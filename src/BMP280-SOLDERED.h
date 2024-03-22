/**
 **************************************************
 *
 * @file        BMP280-SOLDERED.h
 * @brief       Soruce file for the BMP280 library wrapper.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Borna Biro for soldered.com
 ***************************************************/

#ifndef __BMP280_SENSOR_SOLDERED__
#define __BMP280_SENSOR_SOLDERED__

// Include Arduino main header file.
#include "Arduino.h"

// Include library for BMP280.
#include "libs/BMP280_DEV.h"

class Soldered_BMP280 : public BMP280_DEV
{
  public:
    Soldered_BMP280(TwoWire &twoWire = Wire) : BMP280_DEV(twoWire)
    {
    }
#ifdef ARDUINO_ESP8266_GENERIC
    Soldered_BMP280(uint8_t sda, uint8_t scl, TwoWire &twoWire = Wire) : BMP280_DEV(sda, scl, twoWire)
    {
    }
#endif
#ifdef ARDUINO_ESP32_DEV
    Soldered_BMP280(uint8_t sda, uint8_t scl, TwoWire &twoWire = Wire) : BMP280_DEV(sda, scl, twoWire)
    {
    }
#endif
    uint8_t begin();

  protected:
  private:
};

#endif
