#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize the LCD with I2C address 0x3F and dimensions 16x2
LiquidCrystal_I2C lcd(0x3F, 16, 2);
const int ledPin = 13; // LED pin
char incomingByte;

void setup() {
  lcd.begin();
  Serial.begin(9600); // Start the serial connection
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Display initial message on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Windspeed sensor");
  lcd.setCursor(0, 1);
  lcd.print("Waiting data !!!");
}

void loop() {
  while (Serial.available() > 0) {
    incomingByte = Serial.read(); // Read incoming data
    Serial.println(incomingByte);

    // Clear LCD display
    lcd.clear();

    if (incomingByte == '1') {
      digitalWrite(ledPin, HIGH); // Turn on LED
      lcd.setCursor(0, 0);
      lcd.print("ATTENTION !!!!");
      lcd.setCursor(0, 1);
      lcd.print("Wind High");
    } else {
      digitalWrite(ledPin, LOW); // Turn off LED
      lcd.setCursor(0, 0);
      lcd.print("dry environment");
      lcd.setCursor(0, 1);
      lcd.print("all looks good!");
    }
  }
}
