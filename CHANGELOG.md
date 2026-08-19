# Changelog
All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.0.0] - 2026-08-19
### Changed
- Upgraded esp_tinyusb dependency to 2.2.1 (breaking change: UsbDevice's constructor no longer takes a tinyusb_usbdev_t device argument, which no longer exists in esp_tinyusb 2.x).

### Fixed
- Write flush error check.
- Discard read performance when discarding data one byte at a time.
- UsbDevice privately inheriting Lockable, inconsistent with the rest of the pack.
- sprintf used instead of snprintf for the MAC-derived serial string.

## [1.2.1] - 2026-08-14
### Fixed
- Read/write timeout corrupted by xTaskCheckForTimeOut writing back into the stored timeout member.

## [1.2.0] - 2026-08-14
### Added
- Write operation timeout to UsbDeviceCdc.

### Fixed
- Ignored esp_read_mac error when generating the USB serial number.

## [1.1.0] - 2026-08-10
### Added
- ESP-IDF v6.0 support.

## [1.0.4] - 2026-08-07
### Added
- Test suite.

### Changed
- Lock timeout handling.
- Static const members to constexpr.
- UsbDeviceCdc::Write buffer-full retry limit into a named constant.

### Fixed
- Missing vTaskDelay in UsbDeviceCdc::Read.
- Self-referencing UsbDevice::vBusMonitorPin default member initializer.
- Missing internal linkage for macString and string_descriptor globals.

## [1.0.3] - 2025-04-29
### Fixed
- Setting serial number to MAC address if not specified in menuconfig.

## [1.0.2] - 2024-09-26
### Fixed
- USB-CDC write flushing.

## [1.0.1] - 2024-09-11
### Fixed
- Compiling USB code only if it is supported.

## [1.0.0] - 2024-09-02
Initial release.