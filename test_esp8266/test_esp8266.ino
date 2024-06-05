#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Function prototypes
void receiveAndParseJson();
void sendMessageToArduino(const char* message);
void connectToWiFi();
void connectToMQTT();
void callback(char* topic, byte* payload, unsigned int length);


// WiFi credentials
const char* ssid = "OPPO A16e";
const char* password = "2486579083";
bool wifiConnected = false;

// MQTT broker details
const char* mqttServer = "192.168.46.30";
const int mqttPort = 1883;
const char* mqttUsername = "iammalikkhalil";
const char* mqttPassword = "Kh@leel01";

bool errorFlag = false;
String payloadString = "";

WiFiClient espClient;
PubSubClient client(espClient);

// SoftwareSerial RX and TX pins
#define RX_PIN 13
#define TX_PIN 15

const int LOCK1 = D0;
const int LOCK = D5;
const int AVAILABLE_LED = D1;
const int WAITING_LED = D2;
const int ACCEPTED_LED = D3;
const int REJECTED_LED = D4;


SoftwareSerial espSerial(RX_PIN, TX_PIN);  // Create a software serial object

void setup() {
  // Initialize SoftwareSerial communication with ESP8266
  espSerial.begin(9600);
  pinMode(AVAILABLE_LED, OUTPUT);
  pinMode(WAITING_LED, OUTPUT);
  pinMode(ACCEPTED_LED, OUTPUT);
  pinMode(REJECTED_LED, OUTPUT);
  pinMode(LOCK, OUTPUT);  
  pinMode(LOCK1, OUTPUT);  
  
  delay(1000);
  
  digitalWrite(AVAILABLE_LED, HIGH);
  digitalWrite(WAITING_LED, LOW);
  digitalWrite(ACCEPTED_LED, LOW);
  digitalWrite(REJECTED_LED, LOW);
  digitalWrite(LOCK, LOW);
  digitalWrite(LOCK1, HIGH);
  // Initialize Serial port for debugging
  Serial.begin(9600);

  connectToWiFi();
  delay(1000);

  if (wifiConnected) {
    client.setServer(mqttServer, mqttPort);
    client.setCallback(callback);
    connectToMQTT();
  }
    delay(1000);
}
