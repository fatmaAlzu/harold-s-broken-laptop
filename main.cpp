#include <Arduino.h>
#include <TFT_eSPI.h>
#include <Wire.h>

TFT_eSPI tft = TFT_eSPI();

// Touch controller FT63360 I2C address
#define FT63360_I2C_ADDR 0x38

// Touch pins
#define CTP_RST  6   // Touch Reset
#define CTP_INT  5   // Touch Interrupt (optional)

void initTouch() {
  // Initialize I2C for touch (pins fixed on UNO R4: SDA=20, SCL=21)
  Wire.begin();
  
  // Reset touch controller
  pinMode(CTP_RST, OUTPUT);
  digitalWrite(CTP_RST, LOW);
  delay(100);
  digitalWrite(CTP_RST, HIGH);
  delay(200);
  
  // Optional: Setup interrupt pin
  pinMode(CTP_INT, INPUT_PULLUP);
  
  Serial.println("Touch (FT63360) initialized");
}

void setup() {
  Serial.begin(9600);
  delay(1000);
  Serial.println("\n=== Minimal TFT Test ===");
  
  // Setup backlight
  pinMode(7, OUTPUT);
  digitalWrite(7, HIGH);
  Serial.println("Backlight ON (pin 7)");
  delay(500);
  
  // Manual reset sequence
  pinMode(8, OUTPUT);
  Serial.println("Resetting display...");
  digitalWrite(8, HIGH);
  delay(100);
  digitalWrite(8, LOW);
  delay(100);
  digitalWrite(8, HIGH);
  delay(200);
  Serial.println("Reset complete");
  
  // Initialize TFT
  Serial.println("Calling tft.init()...");
  tft.init();
  Serial.println("tft.init() complete");
  
  tft.setRotation(1);
  Serial.println("Rotation set");
  
  // Try to fill screen
  Serial.println("Filling screen BLACK...");
  tft.fillScreen(TFT_BLACK);
  delay(1000);
  
  Serial.println("Filling screen RED...");
  tft.fillScreen(TFT_RED);
  delay(1000);
  
  Serial.println("Filling screen GREEN...");
  tft.fillScreen(TFT_GREEN);
  delay(1000);
  
  Serial.println("Filling screen BLUE...");
  tft.fillScreen(TFT_BLUE);
  delay(1000);
  
  Serial.println("Filling screen WHITE...");
  tft.fillScreen(TFT_WHITE);
  
  Serial.println("Test complete!");
}

void loop() {
  // Demo: color cycle
  tft.fillRect(100, 50, 280, 150, TFT_RED);
  delay(500);
  tft.fillRect(100, 50, 280, 150, TFT_GREEN);
  delay(500);
  tft.fillRect(100, 50, 280, 150, TFT_BLUE);
  delay(500);
  
  // Optional: Read touch data
  if (Wire.available()) {
    // Touch data available (if interrupt connected)
    Serial.println("Touch detected!");
  }
}
