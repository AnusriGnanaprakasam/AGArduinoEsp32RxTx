#include <Arduino.h>

#include <SoftwareSerial.h>

// Create a software serial port on pins 10 (RX) and 11 (TX)
// This will connect to the ESP32’s UART2 pins.
SoftwareSerial arduinoSerial(10, 11); // RX, TX

void setup() {
  Serial.begin(9600);       // Start serial communication with PC (Serial Monitor at 115200 baud)
  arduinoSerial.begin(9600);  // Start software serial communication with ESP32 (9600 baud)
  
  delay(2000);                // Wait for ESP32 to be ready after reset/power up

  // Send first message to ESP32
  arduinoSerial.println("Hey ESP32, wanna hear a joke?");
}

void loop() {
  if (arduinoSerial.available()) {  // If data is available from ESP32
    String received = arduinoSerial.readStringUntil('\n'); 
    received.trim(); // Remove any trailing whitespace or newline
    
    // Print to PC Serial Monitor so we can see the response
    Serial.println("Received from ESP32: " + received);

    // Respond if ESP32 says "Yeah what"
    if (received == "Yeah what") {
      arduinoSerial.println("Why did the ESP32 go to the beach?");
    }
  }
}

/*
🔹 Wiring (Arduino Uno ↔ ESP32):
- Uno Pin 10 (RX) ← ESP32 Pin 26 (TX2)
- Uno Pin 11 (TX) → ESP32 Pin 27 (RX2)
- Uno GND ↔ ESP32 GND
⚠ */