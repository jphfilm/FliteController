#ifndef _MAIN_H
#define _MAIN_H

#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>
#include <Parse.h>
#include <EEPROM.h>
#include <Wire.h>
#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_GFX.h>
#include <gfxfont.h>
#include <Adafruit_ILI9341.h>
#include <FliteSensor.h>
#include <Arduino.h>

void setup();
void loop();
void secondsLoop();
void clickListenerLoop();
void webServerLoop();
void changeSerialtoI2C();
void changeI2CToSerial();
void setI2CBusSensors();
void setupfliteSensors();
void setupfliteSensor(FliteSensor &fliteSensor, String color);
void setupILI9341();
void setupXPT2046();
int getTouchX(int rawX);
int getTouchY(int rawY);
bool isCloudServiceEnabled();
void connectToWiFi();
void beginWiFi();
void disconnectFromWiFi();
void saveToCloud();
void saveToParseServer();
int getmLServedFromGal(float gal);
void saveToTaplist();
void showSplash();
void showMainDisplay();
void updateMainDisplay(int color, float l, float t, float p);
float gallonsToLiters(float liters);
float farenheitToCelsius(float farenheit);
float psiTokPa(float psi);
void updateDisplayedConfig();
void updateDisplayedNetwork();
char *ip2CharArray(IPAddress ip);
void updateDisplayedCalibration();
void updateKegDisplay(float l);
void showHeader(int i);
void showFooter(String s);
void showWiFiIcon();
void enterMaintMode();
void exitMaintMode();
void showWrenchIcon();
void hideStatusIcon();
void onUpArrowTouch();
void onDownArrowTouch();
void onCalibrateZeroPSITouch();
void onCalibrateHighTouch();
void onCalibrateLowTouch();
void updateSensorData();
void enableWebServer();
void getControllerInfo();
void getSensorSelection();
void getValuesBlack();
void getValuesBlue();
void getValuesRed();
void getValuesGreen();
void getValues(float l, float t, float p);
void getZeroPressureBlack();
void getZeroPressureBlue();
void getZeroPressureRed();
void getZeroPressureGreen();
void getZeroPressure(float p);
void getLevelCalBlack();
void getLevelCalBlue();
void getLevelCalRed();
void getLevelCalGreen();
void getLevelCal(float lowEU, float highEU, float lowDistance, float highDistance);
void handleRoot();
void handleNotFound();
void handleUpdateWiFiSettings();
void handleTestWiFiSettings();
void handleUpdateUnits();
void handleZeroPressure();
void handleHighCalibration();
void handleLowCalibration();
void handleUpdateFliteAPIKeys();
void handleUpdateTaplistAPIKeys();
void setfliteSensorSelection(String selections);
char *getFliteAPIEnabled();
bool fliteEnabled();
char *getFliteAppID();
char *getFliteAPIKey();
char *getTaplistAPIEnabled();
bool taplistEnabled();
char *getTaplistAPIKey();
char *getTaplistVenueID();
char *getTaplistTapID();
char *getWiFiSSID();
char *getWiFiPassword();
char * getMetricUnitsEnabled();
bool metricUnitsEnabled();
void getfliteSensorSelection();

typedef struct
{
    uint16_t bitmapOffset;
    uint8_t width, height;
    uint8_t xAdvance;
    int8_t glyph;
} GFXbitmapGlyph;

typedef struct
{
    uint8_t *bitmap;
    GFXbitmapGlyph *glyphs;
    uint8_t glyphCount;
} GFXbitmapFont;

/*--------------------------------------------------*/
//Only modify variables between these lines!
//File: FliteController_V1.3.2_<ControllerID>.ino
//Author: Derrick Marlow
//Date: 2020-11-17

//The GUID of the FliteController class object
#define GUID ""

//The unique password for this controller's WiFi AP
#define SERVER_PASSWORD ""

//The version of the codebase
#define CODE_VERSION "1.3.2"

//Calibrate the display
//Set touchCal to true to calibrate the display, set back to false after finished
bool touchCal = false;
//Set the calibration coefficients based on touch cal performed
#define MINIMUM_X 300
#define MAXIMUM_X 3800
#define MINIMUM_Y 3800
#define MAXIMUM_Y 500

/*--------------------------------------------------*/

//Assign pins for ILI9341 display
#define TFT_DC D2
#define TFT_CS D1
#define TFT_LED D8

//Assign pins for XPT2046 touchscreen
#define TOUCH_CS D3
#define TOUCH_IRQ D4

//There are no additional GPIO pins that can be used for I2C bus using the display and touchscreen
//Repurposing Rx/Tx pins
#define SDA 1
#define SCL 3

//Assign colors
#define FLITE_BLUE 0x659E
#define FLITE_GREY 0x5AEB
#define KEG_FILL 0xD5E4

//Assign display dimensions
#define DISPLAY_WIDTH 240
#define DISPLAY_HEIGHT 320

//Assign button dimensions
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50

//The interval to update parse server, in Minutes
#define CLOUD_UPDATE_INTERVAL 60

//The interval to update the sensor data, in Seconds
#define SENSOR_UPDATE_INTERVAL 30

//Variables for web server
#define SSID_PREFIX "Flite_"

#endif // _MAIN_H
