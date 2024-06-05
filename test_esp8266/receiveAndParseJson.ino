void receiveAndParseJson() {
  // Check if data is available on SoftwareSerial
  if (espSerial.available()) {
    // Read the incoming data
    String jsonData = espSerial.readStringUntil('\n');
    Serial.println(jsonData);
    // Parse JSON data
    StaticJsonDocument<200> jsonDoc;
    DeserializationError error = deserializeJson(jsonDoc, jsonData);
    // Check if parsing succeeded
    if (!error) {
      // Extract the message from the JSON data
      String message = jsonDoc["message"];
      // Print the received message
      Serial.print("Received message from Arduino: ");
      Serial.println(message);

      digitalWrite(AVAILABLE_LED, LOW);
      digitalWrite(WAITING_LED, HIGH);
      // Convert 'message' to a C-style string
      const char* messageStr = message.c_str();
      // Publish the message to the MQTT topic
      client.publish("MQTTUserRequest", messageStr);
    } else {
      Serial.print("Error during JSON parsing: ");
      Serial.println(error.c_str());
    }
  }
}
