/**
 **************************************************
 *
 * @file        BMP280-SOLDERED.cpp
 * @brief       Soruce file for the BMP280 library wrapper.
 *
 *
 * @copyright   GNU General Public License v3.0
 * @authors     Borna Biro for soldered.com
 ***************************************************/


#include "BMP280-SOLDERED.h"

/**
 * @brief                   BMP280 library initializer function.
 *
 * @return                  uint8_t - Success initializaton of the sensor.
 *                          1 - Sensor successfully initialized.
 *                          0 - Sensor initialization falied.
 */
uint8_t Soldered_BMP280::begin()
{
    // Call library specific init. function with 0x76 I2C address.
    return BMP280_DEV::begin(BMP280_I2C_ALT_ADDR);
}