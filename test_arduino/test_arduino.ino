#include <SoftwareSerial.h>
#include <ArduinoJson.h>
#include <Adafruit_Fingerprint.h>

// Function prototypes
void espReset();
void receiveMessageFromNodeMCU();
void sendMessageToNodeMCU(const char* message);
void btn();
int getFingerprintIDez();
uint8_t getFingerprintID();

// SoftwareSerial RX and TX pins
const int RX_PIN = 4;
const int TX_PIN = 5;

SoftwareSerial espSerial(RX_PIN, TX_PIN);  // Create a software serial object
SoftwareSerial mySerial(2, 3);

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

void setup() {
  // Initialize Serial communication for debugging
  Serial.begin(9600);

  // Initialize SoftwareSerial communication with ESP8266
  espSerial.begin(9600);

  // Wait for the ESP8266 module to initialize
  delay(1000);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  delay(5);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  Serial.println(F("Reading sensor parameters"));
  finger.getParameters();
  Serial.print(F("Status: 0x")); Serial.println(finger.status_reg, HEX);
  Serial.print(F("Sys ID: 0x")); Serial.println(finger.system_id, HEX);
  Serial.print(F("Capacity: ")); Serial.println(finger.capacity);
  Serial.print(F("Security level: ")); Serial.println(finger.security_level);
  Serial.print(F("Device address: ")); Serial.println(finger.device_addr, HEX);
  Serial.print(F("Packet len: ")); Serial.println(finger.packet_len);
  Serial.print(F("Baud rate: ")); Serial.println(finger.baud_rate);

  finger.getTemplateCount();

  if (finger.templateCount == 0) {
    Serial.print("Sensor doesn't contain any fingerprint data. Please run the 'enroll' example.");
  }
  else {
    Serial.println("Waiting for valid finger...");
      Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  }

  // Reset the ESP8266 module to ensure it's in a known state
  espReset();
}