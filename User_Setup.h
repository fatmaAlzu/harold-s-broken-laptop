#ifndef USER_SETUP_H
#define USER_SETUP_H

// ========== Display Driver ==========
#define ST7735_DRIVER

// ========== Display Dimensions ==========
#define TFT_WIDTH  480
#define TFT_HEIGHT 320

// ========== SPI Pins (Arduino UNO R4 WiFi) ==========
// Hardware SPI (FIXED)
#define TFT_MISO 12  // MISO (hardware, pin 12)
#define TFT_MOSI 11  // MOSI (hardware, pin 11)
#define TFT_SCLK 13  // SCK  (hardware, pin 13)

// Control Pins (CONFIGURABLE)
#define TFT_CS   10  // LCD_CS (Chip Select)
#define TFT_DC   9   // LCD_RS (Register Select / Data-Command)
#define TFT_RST  8   // LCD_RST (Reset)
#define TFT_BL   7   // LED (Backlight)

// ========== SPI Speed (LOWERED for troubleshooting) ==========
#define SPI_FREQUENCY  10000000
#define SPI_READ_FREQUENCY 5000000

// ========== Rotation ==========
#define TFT_ROTATION 1

// ========== Font Support ==========
#define LOAD_GLCD
#define LOAD_FONT2
#define LOAD_FONT4
#define LOAD_FONT6
#define LOAD_FONT7
#define LOAD_FONT8

// ========== Color Depth ==========
#define TFT_BL_ON HIGH

#endif
