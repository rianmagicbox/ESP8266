
void setup() {
  Serial.begin(9600);
  
  pinMode(D2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {
  int sensorVal = digitalRead(D2);
  
  if (sensorVal == HIGH) {
    Serial.println(":(");
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    Serial.println(":)");
    digitalWrite(LED_BUILTIN, LOW);
  }
}
