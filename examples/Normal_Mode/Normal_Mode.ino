/**
 **************************************************
 *
 * @file        Normal_Mode.ino
 * @brief       This example will show basic usage of the BMP280
 *              sensor. It will periodically read BMP280 for new
 *              measured data.
 *
 *              Connect easyC cable to sensor and Dasduino board, upload
 *              the code and open serial monitor.
 *
 *              You will need:
 *              - BMP280 sensor breakout: https://solde.red/333315
 *              - easyC cable: https://solde.red/333311
 *
 * @authors     Borna Biro for soldered.com
 ***************************************************/

// Include Soldered BMP280 library.
#include <BMP280-SOLDERED.h>

// Create BMP280 sensor object.
Soldered_BMP280 bmp280;

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

    // Set the pressure oversampling to X4
    // bmp280.setPresOversampling(OVERSAMPLING_X4);

    // Set the temperature oversampling to X1
    // bmp280.setTempOversampling(OVERSAMPLING_X1);

    // Set the IIR filter to setting 4
    // bmp280.setIIRFilter(IIR_FILTER_4);

    // Set the standby time to 2 seconds
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
