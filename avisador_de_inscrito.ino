#include <SerialDisplay.h>

const int pinOE = D2;
const uint8_t totalModulos = 4;
SerialDisplay displays(D3, D4, totalModulos); // (data, clock, number of modules)
int pwm = 0;

void setup(){
  Serial.begin(115200);
  displays.setBrightnessPin(pinOE);
  displays.Off(0);
  displays.Info(&Serial);
}

void printAndWait(byte modulo, byte segmento, unsigned long tempo) {
  displays.Set(segmento, modulo);
  unsigned long previousMillis = millis();
  unsigned long currentMillis = millis();
  while (currentMillis - previousMillis < tempo) {
    currentMillis = millis();
    delay(10);
  }
}

void clear() {
  for (uint8_t i = 1; i <= totalModulos; i++) {
    displays.Set(0x00, i);
  }  
}

void animacao(unsigned long tempo) {
  // Da esquerda para a direita
  for (uint8_t i = 1; i <= totalModulos; i++) {
    printAndWait(i, SerialDisplay::PIN_A, tempo);
  }
  // Fazendo o contorno no último módulo a direita
  printAndWait(totalModulos, (SerialDisplay::PIN_A | SerialDisplay::PIN_B), tempo);
  printAndWait(totalModulos, (SerialDisplay::PIN_A | SerialDisplay::PIN_B | SerialDisplay::PIN_C), tempo);
  printAndWait(totalModulos, (SerialDisplay::PIN_A | SerialDisplay::PIN_B | SerialDisplay::PIN_C | SerialDisplay::PIN_D), tempo);

  // Da direita para a esquerda
  for (uint8_t i = totalModulos - 1; i >= 1; i--) {
    printAndWait(i, SerialDisplay::PIN_A | SerialDisplay::PIN_D, tempo);
  }

  // Fazendo o contorno no primeiro módulo a esquerda
  printAndWait(1, (SerialDisplay::PIN_A | SerialDisplay::PIN_D | SerialDisplay::PIN_E), tempo);
  printAndWait(1, (SerialDisplay::PIN_A | SerialDisplay::PIN_D | SerialDisplay::PIN_E | SerialDisplay::PIN_F), tempo);  
}

void animacao2(unsigned long tempo) {
  for (uint8_t i = totalModulos; i >= 1; i--) {
    printAndWait (i, SerialDisplay::PIN_A, tempo);
  }
  printAndWait(1, (SerialDisplay::PIN_A | SerialDisplay::PIN_F), tempo);
  printAndWait(1, (SerialDisplay::PIN_A | SerialDisplay::PIN_F | SerialDisplay::PIN_E), tempo);
  printAndWait(1, (SerialDisplay::PIN_A | SerialDisplay::PIN_F | SerialDisplay::PIN_E | SerialDisplay::PIN_D), tempo);

  for (uint8_t i = 2; i <= totalModulos; i++) {
    printAndWait (i, SerialDisplay::PIN_A | SerialDisplay::PIN_D, tempo); 
  }
  printAndWait(totalModulos, (SerialDisplay::PIN_A | SerialDisplay::PIN_C | SerialDisplay::PIN_D), tempo);
  printAndWait(totalModulos, (SerialDisplay::PIN_A | SerialDisplay::PIN_C | SerialDisplay::PIN_D | SerialDisplay::PIN_B), tempo);
}

void loop() {
  animacao(1000);
  clear();
  animacao2(1000);
  clear();
  animacao(500);
  clear();
  animacao2(500);
  clear();
  animacao(250);
  clear();
  animacao2(250);
  clear();
  animacao(125);
  clear();
  animacao2(125);
  clear();
  animacao(64);
  clear();
  animacao2(64);
  clear();
  animacao(32);
  clear();  
  animacao2(32);
  clear();
  animacao(16);
  clear();
  animacao2(16);
  clear();
  for (int i = 0; i < 5; i++) {
    animacao(8);
    clear();
    animacao2(8);
    clear();
  }
}
