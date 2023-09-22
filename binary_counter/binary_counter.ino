int leds[] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int num = 1; num <= 256; num++) {
    displayBinaryNumber(num);
    delay(1000);
    clearLeds();
  }
}

void displayBinaryNumber(int num) {
  for (int i = 0; i < 8; i++) {
    int bitValue = (num >> i) & 1;
    digitalWrite(leds[i], bitValue);
  }
}

void clearLeds() {
  for (int i = 0; i < 8; i++) {
    digitalWrite(leds[i], LOW);
  }
}
