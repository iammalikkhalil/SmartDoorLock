void loop() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi connection lost. Reconnecting...");
    connectToWiFi();
  }

  if (!client.connected() && wifiConnected) {
    Serial.println("MQTT connection lost. Reconnecting...");
    connectToMQTT();
  }

  client.loop();
  delay(1000);

  // Receive and parse JSON data from Arduino
  receiveAndParseJson();
  delay(1000);
}