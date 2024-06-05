void sendMessageToNodeMCU(const char* message) {
  // Create a JSON object
  StaticJsonDocument<200> jsonDoc;
  
  // Add data to the JSON object
  jsonDoc["message"] = message;
  
  // Serialize the JSON object to a string
  String jsonString;
  serializeJson(jsonDoc, jsonString);
  
  // Send the JSON string via Serial to NodeMCU
  espSerial.println(jsonString);
}