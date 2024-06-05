void callback(char* topic, byte* payload, unsigned int length) {
  payloadString = "";
  Serial.print("Message received on topic: ");
  Serial.println(topic);

  for (int i = 0; i < length; i++) {
    payloadString += (char)payload[i];
  }

  Serial.print("Message: ");
  Serial.println(payloadString);

  if (strcmp(topic, "MQTTAdminResponse") == 0) {
    // Check if the payload string is equal to "1"
    if (payloadString == "1") {
      Serial.println("Condition true...");
      // sendMessageToArduino("led1");
      digitalWrite(ACCEPTED_LED, HIGH);
      digitalWrite(LOCK, HIGH);
      digitalWrite(LOCK1, LOW);
      delay(200);
        digitalWrite(ACCEPTED_LED, LOW);
      delay(200);
        digitalWrite(ACCEPTED_LED, HIGH);
      delay(200);
        digitalWrite(ACCEPTED_LED, LOW);

      delay(1000);

        digitalWrite(ACCEPTED_LED, HIGH);
      delay(200);
        digitalWrite(ACCEPTED_LED, LOW);
      delay(200);
        digitalWrite(ACCEPTED_LED, HIGH);
      delay(200);
        digitalWrite(ACCEPTED_LED, LOW);

      delay(3000);
      digitalWrite(LOCK, LOW);
      digitalWrite(LOCK1, HIGH);
      digitalWrite(WAITING_LED, LOW);
      digitalWrite(AVAILABLE_LED, HIGH);

    } else {
      Serial.println("Condition false...");
      sendMessageToArduino("led2");
      digitalWrite(REJECTED_LED, HIGH);
      delay(200);
        digitalWrite(REJECTED_LED, LOW);
      delay(200);
        digitalWrite(REJECTED_LED, HIGH);
      delay(200);
        digitalWrite(REJECTED_LED, LOW);

      delay(1000);

        digitalWrite(REJECTED_LED, HIGH);
      delay(200);
        digitalWrite(REJECTED_LED, LOW);
      delay(200);
        digitalWrite(REJECTED_LED, HIGH);
      delay(200);
        digitalWrite(REJECTED_LED, LOW);

      digitalWrite(WAITING_LED, LOW);
      digitalWrite(AVAILABLE_LED, HIGH);
    }
  }
}