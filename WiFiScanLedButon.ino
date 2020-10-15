#include "ESP8266WiFi.h"

void setup() {

 
  
  pinMode(D2, INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(2000000);

 

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  Serial.println("Setup done");
  Serial.println("aperte o botão para buscar -> o <-");
}

void loop() {
  int buton = digitalRead(D2);

  if (buton == LOW)  {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("(☞ﾟヮﾟ)☞ scan start ☜(ﾟヮﾟ☜)");


    // WiFi.scanNetworks will return the number of networks found
    int n = WiFi.scanNetworks();
    Serial.println("scan done");
    if (n == 0) {
      Serial.println("no networks found");
      digitalWrite(LED_BUILTIN, HIGH);
    } else {
      digitalWrite(LED_BUILTIN, HIGH);
      Serial.print(n);
      Serial.println("📶networks found📶");
      for (int i = 0; i < n; ++i) {

        Serial.print(i + 1);
        Serial.print(": ");
        Serial.print(WiFi.SSID(i));
        Serial.print(" (");
        Serial.print(WiFi.RSSI(i));
        Serial.print(")");
        Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? "🔓" : "🔒");
        delay(10);
      }
    }
    Serial.println("");


    delay(5000);

  } 
  
}
