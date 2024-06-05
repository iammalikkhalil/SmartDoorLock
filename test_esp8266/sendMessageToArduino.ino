void sendMessageToArduino(const char* message) {
  // Create a JSON object
  StaticJsonDocument<200> jsonDoc;
  // Add data to the JSON object
  jsonDoc["message"] = message;
  // Serialize the JSON object to a string
  String jsonString;
  serializeJson(jsonDoc, jsonString);
  // Send the JSON string via SoftwareSerial
  espSerial.println(jsonString);
}