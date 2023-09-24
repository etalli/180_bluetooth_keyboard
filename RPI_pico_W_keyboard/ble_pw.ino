#include <KeyboardBT.h>

void ledCB(bool numlock, bool capslock, bool scrolllock, bool compose, bool kana, void *cbData) {
  (void) numlock;
  (void) scrolllock;
  (void) compose;
  (void) kana;
  (void) cbData;
  digitalWrite(LED_BUILTIN, capslock ? HIGH : LOW);
}

void setup() {
  KeyboardBT.begin("pcw_mcr"); // this name will be displayed on your PC
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);

  KeyboardBT.onLED(ledCB);
  KeyboardBT.begin();
  delay(5000);
  
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {
  if (BOOTSEL) {
    KeyboardBT.print("type in your password here"); // your password
    while (BOOTSEL);
  }
}
