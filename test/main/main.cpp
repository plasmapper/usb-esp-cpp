#include "unity.h"
#include "usb_device.h"
#include "usb_device_cdc.h"

//==============================================================================

extern "C" void app_main(void) {
  UNITY_BEGIN();
  RUN_TEST(TestUsbDevice);
  RUN_TEST(TestUsbDeviceCdc);
  UNITY_END();
}
