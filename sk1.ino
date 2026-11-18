#include <KiwisIoT.h>
#include <DHT.h>
#include <math.h>

// Wi-Fi credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* pass = "YOUR_WIFI_PASSWORD";

// KiwisIoT dashboard Topic ID
const char* topic = "YOUR_TOPIC_ID";

// Sensor pins
#define LDR_PIN D5
#define DHT_PIN D2
#define ACS_PIN A0
#define DHTTYPE DHT11

DHT dht(DHT_PIN, DHTTYPE);
KiwisIoT kiwisiot(ssid, pass, topic);

// Adjust according to the LDR module
const int DARK_LEVEL = LOW;

// Nominal ACS712 5A sensitivity
const float ACS_SENSITIVITY = 0.185;

// Example external voltage divider: 10k and 2.7k
const float DIVIDER_RATIO = 2.7 / 12.7;

// Set according to the actual A0 input range
const float ADC_FULL_SCALE = 3.30;

// Set to the actual DC load supply voltage
const float LOAD_VOLTAGE = 12.0;

float zeroSensorVoltage = 0.0;
float energyWh = 0.0;

unsigned long lastSend = 0;
unsigned long lastEnergyTime = 0;