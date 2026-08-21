#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Ultrasonic Sensor Pins
const int trigPin = 5;    // GPIO 5 (D5)
const int echoPin = 18;   // GPIO 18 (D18)

// LED and Buzzer Pins
const int ledPin = 2;     // GPIO 2 (D2)
const int buzzerPin = 4;  // GPIO 4 (D4)

// Object Alert Threshold (in centimeters)
const int alertDistance = 20; 

long duration;
float distanceCm;

void setup() {
  // Pin modes setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Default state: OFF
  digitalWrite(ledPin, LOW);
  digitalWrite(buzzerPin, LOW);

  // ESP32 I2C Pins (SDA = GPIO 21, SCL = GPIO 22)
  Wire.begin(21, 22);

  // Initialize OLED Display (I2C address 0x3C)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); // Stop execution if OLED fails
  }
  
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  // Trigger Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read Echo Pulse Duration
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate Distance in cm
  distanceCm = duration * 0.034 / 2;

  // Alert Logic (Triggered if object <= 20 cm)
  if (distanceCm > 0 && distanceCm <= alertDistance) {
    digitalWrite(ledPin, HIGH);     // LED ON
    digitalWrite(buzzerPin, HIGH);  // Buzzer ON
  } else {
    digitalWrite(ledPin, LOW);      // LED OFF
    digitalWrite(buzzerPin, LOW);   // Buzzer OFF
  }

  // Update OLED Display
  display.clearDisplay();
  
  // Header Text
  display.setTextSize(1);
  display.setCursor(15, 5);
  display.print("Distance Meter");

  // Distance Output
  display.setTextSize(2);
  display.setCursor(10, 25);
  display.print(distanceCm, 1);
  display.print(" cm");

  // Status Output
  display.setTextSize(1);
  display.setCursor(10, 50);
  if (distanceCm > 0 && distanceCm <= alertDistance) {
    display.print("STATUS: ALERT!");
  } else {
    display.print("STATUS: NORMAL");
  }
  
  display.display();

  delay(150); // Refresh delay
}
