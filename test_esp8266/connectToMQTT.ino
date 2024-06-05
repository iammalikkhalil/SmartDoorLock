void connectToMQTT() {
  Serial.print("Connecting to MQTT");
  while (!client.connected()) {
    Serial.print(".");
    if (client.connect("NodeMCU-client", mqttUsername, mqttPassword)) {
      Serial.println();
      Serial.println("Connected to MQTT broker");
      client.subscribe("MQTTUserRequest");
      client.subscribe("MQTTAdminResponse");
      // client.subscribe("DoorLock");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" Retrying in 5 seconds...");
      delay(5000);
    }
  }
}