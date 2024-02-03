#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int trigpin = 8;
int echopin = 9;
int led1 = A1;
int led2 = A2;
int led3 = A3;
int led4 = A4;
int buzzer = 11;
float time;
float cm;
float inch;
float ncm;


void setup() {
  lcd.begin(16, 2);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("___WELCOME TO___");
  lcd.setCursor(0, 1);
  lcd.print("___Our Project__");
  delay(800);

  lcd.setCursor(0, 0);
  lcd.print("_____TO FIND____");
  lcd.setCursor(0, 1);
  lcd.print("__The Distance__");
  delay(1000);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("__Team Leader__");
  lcd.setCursor(0, 1);
  lcd.print("Md. Shahin Alam!");
  delay(1500);

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("_Nishat  Sarkar_");
  lcd.setCursor(0, 1);
  lcd.print("___Raju Ahmed___");
  delay(1500);

  lcd.setCursor(0, 0);
  lcd.print("_Rajoni Khatun_");
  lcd.setCursor(0, 1);
  lcd.print("___Thank You___");
  delay(1500);
}

void loop() {
  digitalWrite(trigpin, LOW);
  delay(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin, HIGH);
  cm = (time * 0.0345) / 2;
  inch = (int)(cm / 2.54);
  ncm = (cm - inch * 2.54);

  if (2 <= cm && cm <= 335.28) {
    lcd.setCursor(0, 0);
    lcd.print("Object Detected!");
    lcd.setCursor(0, 1);
    lcd.print(inch);
    lcd.print("inch_");
    lcd.print(ncm);
    lcd.print("cm");

    if (inch >= 0.00 && inch < 2.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 2.00 && inch < 3.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 3.00 && inch < 4.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 4.00 && inch < 5.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 5.00 && inch < 6.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    } else if (inch >= 6.00 && inch < 7.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 7.00 && inch < 8.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 8.00 && inch < 9.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, HIGH);
    } else if (inch >= 9.00 && inch < 10.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 10.00 && inch < 11.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, HIGH);
    }

    else if (inch >= 11.00 && inch < 12.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, LOW);
    } else if (inch >= 12.00 && inch < 13.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, LOW);
    } else if (inch >= 13.00 && inch < 14.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, LOW);
    } else if (inch >= 14.00 && inch < 15.00) {
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, LOW);
    } else if (inch >= 15.00 && inch < 16.00) {
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(buzzer, LOW);
    }

    else {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
      digitalWrite(led4, LOW);
      digitalWrite(buzzer, LOW);
    }
  }

  else {
    lcd.setCursor(0, 0);
    lcd.print("__No object in__");
    lcd.setCursor(0, 1);
    lcd.print("______Range_____");
    digitalWrite(buzzer, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
}