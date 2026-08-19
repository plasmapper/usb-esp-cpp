#include "usb_device_cdc.h"
#include "unity.h"

//==============================================================================

const TickType_t readTimeout = 500 / portTICK_PERIOD_MS;
const TickType_t writeTimeout = 600 / portTICK_PERIOD_MS;
const uint8_t dataToSend[] = {1, 2, 3, 4, 5};

//==============================================================================

void TestUsbDeviceCdc() {
  auto usbDevice = std::make_shared<PL::UsbDevice>();
  PL::UsbDeviceCdc usbDeviceCdc(usbDevice, TINYUSB_CDC_ACM_0);
  TEST_ASSERT(usbDeviceCdc.GetName() == PL::UsbDeviceCdc::defaultName);
  TEST_ASSERT_EQUAL(PL::UsbDeviceCdc::defaultReadTimeout, usbDeviceCdc.GetReadTimeout());
  TEST_ASSERT_EQUAL(PL::UsbDeviceCdc::defaultWriteTimeout, usbDeviceCdc.GetWriteTimeout());

  uint8_t receivedData[sizeof(dataToSend)];

  // Enable should fail before initialization, Read/Write should fail while disabled
  TEST_ASSERT(usbDeviceCdc.Enable() == ESP_ERR_INVALID_STATE);
  TEST_ASSERT(usbDeviceCdc.Disable() == ESP_ERR_INVALID_STATE);
  TEST_ASSERT(usbDeviceCdc.Read(receivedData, sizeof(receivedData)) == ESP_ERR_INVALID_STATE);
  TEST_ASSERT(usbDeviceCdc.Write(dataToSend, sizeof(dataToSend)) == ESP_ERR_INVALID_STATE);
  TEST_ASSERT_EQUAL(0, usbDeviceCdc.GetReadableSize());

  TEST_ASSERT(usbDeviceCdc.Initialize() == ESP_OK);

  TEST_ASSERT(usbDeviceCdc.SetReadTimeout(readTimeout) == ESP_OK);
  TEST_ASSERT_EQUAL(readTimeout, usbDeviceCdc.GetReadTimeout());

  TEST_ASSERT(usbDeviceCdc.SetWriteTimeout(writeTimeout) == ESP_OK);
  TEST_ASSERT_EQUAL(writeTimeout, usbDeviceCdc.GetWriteTimeout());

  TEST_ASSERT(usbDeviceCdc.Enable() == ESP_OK);
  TEST_ASSERT(usbDeviceCdc.IsEnabled());

  // No actual hardware tests since a USB host is required for this
  TEST_ASSERT_EQUAL(0, usbDeviceCdc.GetReadableSize());
  TEST_ASSERT(usbDeviceCdc.Read(receivedData, sizeof(receivedData)) == ESP_ERR_TIMEOUT);
  TEST_ASSERT(usbDeviceCdc.Write(dataToSend, sizeof(dataToSend)) == ESP_OK);

  TEST_ASSERT(usbDeviceCdc.Disable() == ESP_OK);
  TEST_ASSERT(!usbDeviceCdc.IsEnabled());
}
