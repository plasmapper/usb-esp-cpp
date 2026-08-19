#include "usb_device.h"
#include "unity.h"

//==============================================================================

void TestUsbDevice() {
  PL::UsbDevice usbDevice;

  TEST_ASSERT(usbDevice.Initialize() == ESP_OK);
}
