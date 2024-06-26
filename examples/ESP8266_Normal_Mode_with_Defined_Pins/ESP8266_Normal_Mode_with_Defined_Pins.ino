/**
 **************************************************
 *
 * @file        ESP8266_Normal_Mode_with_Defined_Pins.ino
 * @brief       This example shows how to use ESP8266 (Soldered DasduinoCONNECT) with this sensor.
 *              Since ESP8266 has SW driven I2C, it can have I2C on almost any GPIO.
 *              This could be useful if there are device with the same I2C address as this sensor on
 *              default I2C pins.
 *
 *              Using jumper wires, connect:
 *                 BMP280                   DasduinoCONNECT
 *                    GND <---------------> GND
 *                    VCC <---------------> VCC
 *                    SDA <---------------> GPIO14
 *                    SCL <---------------> GPIO13
 *
 *              You will need:
 *              - BMP280 sensor breakout: https://solde.red/333315
 *              - Jumper cables: https://solde.red/100862
 *              - Breadboard: https://solde.red/100871
 *
 * @authors     Borna Biro for soldered.com
 ***************************************************/
// Include Soldered BMP280 library.
#include <BMP280-SOLDERED.h>

// Board select - This example is only compatible with ESP8266 Boards (DasduinoCONNECT)
#ifdef ARDUINO_ESP8266_GENERIC
// Create BMP280 sensor object. Use GPIO14 as SDA and GPIO13 as I2C SCL.
Soldered_BMP280 bmp280(14, 13, Wire);
#else
// If ESP32 is not use, use  default I2C.
Soldered_BMP280 bmp280;
#endif

void setup()
{
    // Initialize serial communication at 115200 bauds.
    Serial.begin(115200);

    // Initialize sensor (check for sensor). Notify if init failed.
    // Also, this will set BMP280 sensor into sleep mode.
    if (!bmp280.begin())
    {
        // Print error message.
        Serial.println("Sensor not found! Check your wiring!");

        // Stop the code!
        while (1)
        {
            // Delay for ESP8266.
            delay(10);
        }
    }

    // Set current pressure at sea level to get accurate altitude readings.
    bmp280.setSeaLevelPressure(1020.6);

    // Set the standby time to 2 seconds.
    bmp280.setTimeStandby(TIME_STANDBY_2000MS);

    // Start BMP280 continuous conversion in normal mode.
    bmp280.startNormalConversion();
}

void loop()
{
    // Variables for storing measurement data.
    float temperature, pressure, altitude;

    // Check if the data is ready.
    if (bmp280.getMeasurements(temperature, pressure, altitude))
    {
        // Print the results.
        Serial.print(temperature);
        Serial.print(F("*C   "));
        Serial.print(pressure);
        Serial.print(F("hPa   "));
        Serial.print(altitude);
        Serial.println(F("m"));
    }
}
