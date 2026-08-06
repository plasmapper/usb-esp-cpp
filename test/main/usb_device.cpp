#include "usb_device.h"
#include "unity.h"

//==============================================================================

void TestUsbDevice() {
  PL::UsbDevice usbDevice(TINYUSB_USBDEV_0);

  TEST_ASSERT(usbDevice.Initialize() == ESP_OK);
}
