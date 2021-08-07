#include <LiquidCrystal.h>
const int  MIN_BUTTON = 6;
const int  SEC_BUTTON = 7;
const int START_BUTTON = 10;
bool WAS_START_BUTTON = true;
bool WAS_MIN_BUTTON = true;
bool WAS_SEC_BUTTON = true;
int mood = 2;
int minutes = 0;
int seconds = 0;
const int buzz = 13;

LiquidCrystal lcd(11,12,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
  
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Set the time:");
  lcd.setCursor(0, 1);
  lcd.print("Min:");
  lcd.setCursor(7, 1);
  lcd.print("Sec:");
} 

void loop(){
  bool IS_MIN_BUTTON = digitalRead(MIN_BUTTON);
  if (WAS_MIN_BUTTON && !IS_MIN_BUTTON){
    delay(10);
    IS_MIN_BUTTON = digitalRead(MIN_BUTTON);
    if (!IS_MIN_BUTTON){
      lcd.setCursor(4,1);
      lcd.print(minutes);
      minutes++;
      if (minutes > 59){
        minutes = 0;
        lcd.setCursor(4,1);
        lcd.print(seconds);
      }
    }
  }
  WAS_MIN_BUTTON = IS_MIN_BUTTON;
  bool IS_SEC_BUTTON = digitalRead(SEC_BUTTON);
  if (WAS_SEC_BUTTON && !IS_SEC_BUTTON){
    delay(10);
    IS_SEC_BUTTON = digitalRead(SEC_BUTTON);
    if (!IS_SEC_BUTTON){
      lcd.setCursor(11,1);
      lcd.print(seconds);
      seconds++;
      if (seconds > 59){
        seconds = 0;
        lcd.setCursor(11,1);
        lcd.print(seconds);
      }
    }
  }
  WAS_SEC_BUTTON = IS_SEC_BUTTON;
  bool IS_START_BUTT = digitalRead(START_BUTTON);
  if (WAS_START_BUTTON && !IS_START_BUTT){
    delay(10);
    IS_START_BUTT = digitalRead(START_BUTTON);
    if (!IS_START_BUTT){
      if (mood == 2){
        mood = 1;
        starting();
      }
      else if (mood == 1){
        mood = 2;
        stoping();
      }
    }
  }
}
void starting(){
  while (minutes > -1 && seconds > -1){
    lcd.setCursor(11,1);
    lcd.print(seconds);
    seconds--;
    if (seconds < 1){
      seconds = 59;
      lcd.setCursor(11,1);
      lcd.print(seconds);
      minutes--;
      lcd.setCursor(4,1);
      lcd.print(minutes);
    }
  }
}
void stoping(){
  
}
