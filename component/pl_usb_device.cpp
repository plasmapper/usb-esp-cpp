#include "pl_usb_device.h"
#include "esp_check.h"

#if defined(CONFIG_IDF_TARGET_ESP32P4) || defined(CONFIG_IDF_TARGET_ESP32S2) || defined(CONFIG_IDF_TARGET_ESP32S3)

//==============================================================================

static const char* TAG = "pl_usb_device";

//==============================================================================

namespace PL {

//==============================================================================

UsbDevice::UsbDevice(tinyusb_usbdev_t device, int vBusMonitorPin) : device(device), vBusMonitorPin(vBusMonitorPin) { }

//==============================================================================

UsbDevice::~UsbDevice() {
  if (initialized)
    tinyusb_driver_uninstall();
}

//==============================================================================

esp_err_t UsbDevice::Lock(TickType_t timeout) {
  esp_err_t error = mutex.Lock(timeout);
  if (error == ESP_OK)
    return ESP_OK;
  if (error == ESP_ERR_TIMEOUT && timeout == 0)
    return ESP_ERR_TIMEOUT;
  ESP_RETURN_ON_ERROR(error, TAG, "mutex lock failed");
  return ESP_OK;
}

//==============================================================================

esp_err_t UsbDevice::Unlock() {
  ESP_RETURN_ON_ERROR(mutex.Unlock(), TAG, "mutex unlock failed");
  return ESP_OK;
}

//==============================================================================

esp_err_t UsbDevice::Initialize() {
  LockGuard lg(*this);
  if (initialized)
    return ESP_OK;
  tinyusb_config_t config = {};
  config.self_powered = vBusMonitorPin >= 0;
  config.vbus_monitor_io = vBusMonitorPin;
  ESP_RETURN_ON_ERROR(tinyusb_driver_install(&config), TAG, "driver install failed");
  initialized = true;
  return ESP_OK;
}

//==============================================================================

}

#endif