#include <HX711.h>

const int load1 = 1;
const int load2 = ;
const int load3 = 3;
const int load4 = 4;
const int load_clck = 5;
const int out_pin = 6;
const int led_pin = 2;
const int button = 12;

HX711 cell1(load1, load_clck);
HX711 cell2(load2, load_clck);
HX711 cell3(load3, load_clck);
HX711 cell4(load4, load_clck);

void sendLongData(long data, int outPin) {
  for (int i = 31; i >= 0; i--) {
    bool bit = (data >> i) & 1;

    digitalWrite(outPin, bit);

    delayMicroseconds(1000);
  }
}

void setup() {
  cell1.tare();
  cell2.tare();
  cell3.tare();
  cell4.tare();

  pinMode(out_pin, OUTPUT);
  pinMode(led_pin, OUTPUT);
}

void loop() {

  long reading1 = cell1.read();
  sendLongData(reading1, out_pin);
  long reading2 = cell2.read();
  sendLongData(reading1, out_pin);
  long reading3 = cell3.read();
  sendLongData(reading1, out_pin);
  long reading4 = cell4.read();
  sendLongData(reading1, out_pin);
  digitalWrite(led_pin, HIGH);
  delay(250);
  digitalWrite(led_pin, LOW);
  delay(250);
}
