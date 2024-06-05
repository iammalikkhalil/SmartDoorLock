void espReset() {
  espSerial.println("AT+RST"); // Send AT command for resetting
  delay(1000); // Wait for reset to complete
}