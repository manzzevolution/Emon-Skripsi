// --------------------------------------- OLED Init ---------------------------------------------
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for #include "SSD1306Wire.h"
#include "sensyncLogo.h"
#define DISPLAY_HEIGHT 64
#define DISPLAY_WIDTH 128
#define separateStart Serial.println(F("---------- Start ------------"));
#define separateEnd Serial.println(F  ("----------- End -------------"));

//OLED pins to WeMos D1 Mini GPIOs via this connecthin:
//OLED_SDA -- GPIO4 / D2
//OLED_SCL -- GPIO5 / D1

#include "SSD1306.h" // alias for #include "SSD1306Wire.h"
SSD1306  display(0x3c, 4, 5);

// --------------------------------------- End OLED ---------------------------------------------
// ------------------------------------ PZEM-004T Init ------------------------------------------
#include <SoftwareSerial.h> // Arduino IDE <1.6.6
#include <PZEM004T.h>

PZEM004T pzem(D3,D4);  // (RX,TX) connect to TX,RX of PZEM
IPAddress ip(192,168,1,1);

float v,i,p,e;
long numSampling = 1;
long timeSampling = 300; //s
// ------------------------------------ End PZEM-004T -------------------------------------------

// ------------------------------------ LED Sensor Init ------------------------------------------
#define sensorLedPin D7
#define ada "Menyala"
#define mati "Mati"

int statusLED;
String kondisiLED = "";
// ------------------------------------ End LED Sensor ------------------------------------------

// ------------------------------------ Wifi and Thingspeak Init ------------------------------------------

#include "ThingSpeak.h"
#include "WifiParam.h"
#include <ESP8266WiFi.h>
//needed for library
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <WiFiClient.h> 
#include <ESP8266HTTPClient.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 7 * 3600, 60000);
//for LED status
#include <Ticker.h>
Ticker ticker;
#define retry 5

char ssid[] = SECRET_SSID;   // your network SSID (name) 
char pass[] = SECRET_PASS;   // your network password
char ssidAP[] = SECRET_SSID_AP;   // your network SSID (name) 
char passAP[] = SECRET_PASS_AP;   // your network password
char ssid2[] = SECRET_SSID2;   // your network SSID (name) 
char pass2[] = SECRET_PASS2;   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char * myWriteAPIKey = SECRET_WRITE_APIKEY;

String myStatus = "";

//start-block2
IPAddress IP = IPAddress(192, 168, 1, 5);
IPAddress Gateway = IPAddress(192, 168, 1, 1);
IPAddress Subnet = IPAddress(255, 255, 255, 0);
//end-block2

// ------------------------------------ End Wifi and Thingspeak ------------------------------------------

// ------------------------------------ Sensync Dashboard Init ------------------------------------------
#include <ESP8266WiFi.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
#include <ESP8266HTTPClient.h>

String confirmResponse = "eah";

// ------------------------------------ End Sensync Dashboard ------------------------------------------


// ----------------------------------------- SDCard Init -----------------------------------------
// include the SD library:
#include <SPI.h>
#include <SD.h>

// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;

const int chipSelect = D8;

int detik,menit,jam,tanggal,bulan,tahun;
// ---------------------------------------------------------------------------------------------
