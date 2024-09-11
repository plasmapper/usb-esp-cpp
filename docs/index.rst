USB Component
=============

.. |COMPONENT| replace:: usb

.. |ESP_IDF_VERSION| replace:: 5.3
   
.. |VERSION| replace:: 1.0.1

.. include:: ../../../installation.rst

.. include:: ../../../sdkconfig_usb.rst

Features
--------

1. :cpp:class:`PL::UsbDevice` - a USB device class.
2. :cpp:class:`PL::UsbDeviceCdc` - a :cpp:class:`PL::HardwareInterface` and :cpp:class:`PL::Stream` implementation for the USB device CDC endpoint.
   :cpp:func:`PL::UsbDeviceCdc::Initialize` initializes the USB device and the USB device CDC endpoint.
   A number of Get And Set methods get and set USB device CDC parameters.
   A number of :cpp:func:`PL::UsbDeviceCdc::Read` and :cpp:func:`PL::UsbDeviceCdc::Write` functions read and write from/to the endpoint.
   Reading and writing to/from :cpp:class:`PL::Buffer` object checks the data size and locks the object so these methods can
   be used in multithreaded applications. 
3. :cpp:class:`PL::StreamServer` can be used with :cpp:class:`PL::UsbDeviceCdc` to implement a stream server for the USB device CDC endpoint. The descendant class should override
   :cpp:func:`PL::StreamServer::HandleRequest` to handle the client request. :cpp:func:`PL::StreamServer::HandleRequest` is only called when there is incoming data in the internal buffer.

Thread safety
-------------

Class method thread safety is implemented by having the :cpp:class:`PL::Lockable` as a base class and creating the class object lock guard at the beginning of the methods.

Examples
--------
| `USB device CDC <https://components.espressif.com/components/plasmapper/pl_usb/versions/1.0.1/examples/usb_device_cdc>`_
| `USB device CDC echo server <https://components.espressif.com/components/plasmapper/pl_usb/versions/1.0.1/examples/usb_device_cdc_echo_server>`_

API reference
-------------

.. toctree::
  
  api/usb_device      
  api/usb_device_cdc