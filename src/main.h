/*
    Author: DJMarlow - https://github.com/DJMarlow
    Date: 2021-8-4
    Version 1.6.0
        - Added user configurable temperature offset
        - Fixed calibration bug from display when level is "nan"
    
    MIT License
    Copyright (c) 2020 Derrick Marlow
    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:
    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.
    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
void fliteStartup();
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
void saveToBruControl();
bool bruControlPUT(String variable, float value);
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
void getSensorsUpdateInterval();
void getValuesBlack();
/*
void getValuesBlue();
void getValuesRed();
void getValuesGreen();
*/
void getValues(float l, float t, float p);
void getZeroPressureBlack();
/*
void getZeroPressureBlue();
void getZeroPressureRed();
void getZeroPressureGreen();
*/
void getZeroPressure(float p);
void getTempOffsetBlack();
/*
void getTempOffsetBlue();
void getTempOffsetRed();
void getTempOffsetGreen();
*/
void getTempOffset(float t);
void getLevelCalBlack();
/*
void getLevelCalBlue();
void getLevelCalRed();
void getLevelCalGreen();
*/
void getLevelCal(float lowEU, float highEU, float lowDistance, float highDistance);
void handleRoot();
void handleNotFound();
void handleUpdateController();
void handleUpdateWiFiSettings();
void handleTestWiFiSettings();
void handleUpdateUnits();
void handleUpdateInterval();
void handleZeroPressure();
void handleTempOffset();
void handleHighCalibration();
void handleLowCalibration();
void handleUpdateFliteAPIKeys();
void handleUpdateTaplistAPIKeys();
void handleUpdateBruControl();
void setfliteSensorSelection(String selections);
char *getControllerEnabled();
bool controllerEnabled();
char *getFliteAPIEnabled();
bool fliteEnabled();
char *getFliteAppID();
char *getFliteAPIKey();
char *getTaplistAPIEnabled();
bool taplistEnabled();
char *getTaplistAPIKey();
char *getTaplistVenueID();
char *getTaplistTapID();
char *getBruControlEnabled();
bool bruControlEnabled();
char *getBruControlIP();
char *getBruControlPort();
char *getGUID();
char *getMyPassword();
char *getWiFiSSID();
char *getWiFiPassword();
int getUpdateInterval();
char *getMetricUnitsEnabled();
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

//The version of the Flite codebase
#define CODE_VERSION "1.6.0"

//Required length of GUID and AP Password
#define GUID_LENGTH 8
#define AP_PW_LENGTH 32

//Calibrate the display
//Set touchCal to true to calibrate the display, set back to false after finished
bool touchCal = false;
//Set the calibration coefficients based on touch cal performed
#define MINIMUM_X 300
#define MAXIMUM_X 3800
#define MINIMUM_Y 3800
#define MAXIMUM_Y 500

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

//Variables for web server
#define SSID_PREFIX "Flite_"

#endif // _MAIN_H
