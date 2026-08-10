cmake_minimum_required(VERSION 3.22)

idf_component_register(SRCS "main.cpp" "usb_device.cpp" "usb_device_cdc.cpp" INCLUDE_DIRS ".")
