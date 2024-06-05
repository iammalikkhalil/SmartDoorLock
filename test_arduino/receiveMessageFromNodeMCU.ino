void receiveMessageFromNodeMCU() {
  if (espSerial.available()) {
    // Read the incoming data
    String jsonData = espSerial.readStringUntil('\n');
    
    // Parse JSON data
    StaticJsonDocument<200> jsonDoc;
    DeserializationError error = deserializeJson(jsonDoc, jsonData);
    
    // Check if parsing succeeded
    if (!error) {
      // Extract the message from the JSON data
      String message = jsonDoc["message"];
      
      // Print the received message
      Serial.print("Received message from NodeMCU: ");
      Serial.println(message);
    } else {
      Serial.print("Error during JSON parsing: ");
      Serial.println(error.c_str());
    }
  }
}