![Flite](https://github.com/DJMarlow/Flite/blob/master/logo_raw.png)


**Flite Controller**
----
This is a fork of DJMarlow's original flite controller code, with the (as yet unrealized) intent of providing support several alternative temperature sensors.  
The recommended HSCMAND150PA4A3 temp/pressure sensor is quite expensive, and pressure sensing and has limited utility for many users, so this fork will attempt to add support for the following i2c temperature sensors using the same wiring configuration:
- HTU21D Temperature and Humidity Sensor (Humidity not used)
- LM75 Temperature Sensor
- MLX90614 Infrared Sensor (using through-hole for pressure sensor)
- MLX90615 Infrared Sensor (using through-hole for pressure sensor)  

At the time of writing, there appear to be no widely available pressure-sensing alternative to DJMarlow's recommended sensor.

Most changes will be to the flite sensor library itself - the controller code will add changes to support saving of sensor configuration in CMOS

https://www.flitesense.com/

[Flite Controller DIY Documentation](https://gist.github.com/DJMarlow/6e379bbdc4a7a989cb9a6dd93ef59eaf)
