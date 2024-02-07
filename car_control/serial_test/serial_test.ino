void setup() {
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(9600);   // Serial monitor for debugging
}

void loop() {
  if (Serial.available() > 0) {
    int receivedData = Serial.parseInt();  // Parse the received integer
    if (receivedData==1){
      digitalWrite(LED_BUILTIN, HIGH);
      delay(1000);
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
      delay(1000);
    }
    delay(1000);
  }
}
