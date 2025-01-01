#include <Wire.h>

// Setup Variables
const int sensorPin = A0; // Defines the pin that the anemometer output is connected to
int sensorValue = 0; // Variable stores the value direct from the analog pin
float sensorVoltage = 0; // Variable that stores the voltage (in Volts) from the anemometer
float windSpeed = 0; // Wind speed in meters per second (m/s)
float voltageConversionConstant = 0.004882814; // Maps the value from analog read (0-1023) to voltage (0-5V)
int sensorDelay = 1000; // Delay between sensor readings, in milliseconds

// Anemometer Technical Variables
float voltageMin = 0.4; // Minimum output voltage from anemometer in V
float windSpeedMin = 0; // Wind speed in m/s corresponding to minimum voltage
float voltageMax = 2.0; // Maximum output voltage from anemometer in V
float windSpeedMax = 32; // Wind speed in m/s corresponding to maximum voltage

void setup() {
  Serial.begin(9600); // Start the serial connection
  pinMode(sensorPin, INPUT);
}

void loop() {
  sensorValue = analogRead(sensorPin); // Get a value between 0 and 1023 from the analog pin
  sensorVoltage = sensorValue * voltageConversionConstant; // Convert sensor value to actual voltage

  // Convert voltage value to wind speed using linear relationship
  if (sensorVoltage <= voltageMin) {
    windSpeed = 0; // If voltage is below minimum, set wind speed to zero
  } else {
    windSpeed = (sensorVoltage - voltageMin) * windSpeedMax / (voltageMax - voltageMin);
  }

  // Check if wind speed exceeds the threshold and send data
  if (windSpeed >= 30) {
    Serial.print("1");
  } else {
    Serial.print("2");
  }

  delay(sensorDelay);
}
