#include <LiquidCrystal.h>
LiquidCrystal lcd (12, 11, 5, 4, 3, 2);

String msg = "ola, meu nome eh  ## YURI ##";

int posX = 0;
int posY = 0;
int xMax = 16;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
}

void loop() {
  lcd.setCursor(0,0);
  delay(3000);

  //lcd.clear();
  posX = 0;
  posY = 0;

  for (int i = 0; i < msg.length(); i++) {
    lcd.setCursor(posX, posY);
    lcd.print(msg[i]);
    posX ++;
    delay(100);
    if ( posX == xMax) {
      posX = 0;
      posY = 1;
    }
  }

}
