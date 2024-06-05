void loop() {

//for fingerprint
  getFingerprintID();
  delay(50);  //don't ned to run this at full speed.

  // // Send message from Arduino to NodeMCU
  // sendMessageToNodeMCU("hii nodemcu");
  // delay(1000);

  // Receive message from NodeMCU
  receiveMessageFromNodeMCU();
  delay(1000);


  // digitalWrite(AVAILABLE_LED, HIGH);
  // digitalWrite(WAITING_LED, HIGH);
  // digitalWrite(ACCEPTED_LED, LOW);
  // digitalWrite(REJECTED_LED, LOW);
  // digitalWrite(LOCK, LOW);

  // delay(500);

  // digitalWrite(AVAILABLE_LED, LOW);
  // digitalWrite(WAITING_LED, LOW);
  // digitalWrite(ACCEPTED_LED, HIGH);
  // digitalWrite(REJECTED_LED, HIGH);
  // digitalWrite(LOCK, LOW);

  // delay(500);


  // digitalWrite(AVAILABLE_LED, LOW);
  // digitalWrite(WAITING_LED, LOW);
  // digitalWrite(ACCEPTED_LED, LOW);
  // digitalWrite(REJECTED_LED, LOW);
  // digitalWrite(LOCK, HIGH);

  // delay(500);
}
