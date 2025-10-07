
#include "HardwareSerial.h"

// Create a HardwareSerial instance using UART2
// ESP32 UART2 is mapped to RX=16, TX=17 in this sketch
HardwareSerial espSerial(2);

void setup() {
  Serial.begin(9600);                           // Start Serial Monitor debug output at 115200 baud
  espSerial.begin(9600, SERIAL_8N1, 16, 17);      // Start UART2 at 9600 baud, RX=27, TX=26
}

void loop() {
  if (espSerial.available()) {  // If data is available from Arduino
    String received = espSerial.readStringUntil('\n');
    received.trim(); // Remove trailing whitespace/newline
    
    // Print message from Arduino to PC Serial Monitor
    Serial.println("Received from Arduino: " + received);

    // Respond to messages from Arduino
    if (received == "Hey ESP32, wanna hear a joke?") {
      espSerial.println("Yeah what");
    } else if (received == "Why did the ESP32 go to the beach?") {
      espSerial.println("Because it wanted more *bandwidth*!");
    }
  }
}

/*
🔹 Wiring (ESP32 ↔ Arduino Uno):
- ESP32 Pin 16 (RX2) ← Uno Pin 11 (TX)
- ESP32 Pin 17 (TX2) → Uno Pin 10 (RX)
- ESP32 GND ↔ Uno GND
⚠ ESP32 uses 3.3V logic. Uno TX (5V) → ESP32 RX (3.3V) should use a voltage divider or level shifter.
*/