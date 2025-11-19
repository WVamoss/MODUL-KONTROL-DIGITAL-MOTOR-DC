#include <LiquidCrystal.h>
#include <Encoder.h>
#define ENCODER_OPTIMIZE_INTERRUPTS

Encoder encModule(24, 25);
Encoder encMotor(50, 52);
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

long positionModule = -999;
long positionMotor  = -999;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("ENC = ");
  lcd.setCursor(0, 1);
  lcd.print("Motor = ");
  pinMode(26, INPUT);
}

void loop() {
  long newEncModule, newEncMotor;
  newEncModule = encModule.read();
  newEncMotor  = encMotor.read();

  // tampilkan nilai encoder jika berubah
  if (newEncModule != positionModule || newEncMotor != positionMotor) {
    lcd.setCursor(6, 0);
    lcd.print(newEncModule / 4);  // misal untuk modul dikalibrasi
    lcd.print("     ");           // hapus sisa angka lama

    lcd.setCursor(8, 1);
    lcd.print(newEncMotor);
    lcd.print("     ");           // hapus sisa angka lama

    positionModule = newEncModule;
    positionMotor  = newEncMotor;
  }

  // tombol reset encoder di pin 26
  if (digitalRead(26) == LOW) {
    encModule.write(0);
    encMotor.write(0);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("ENC = ");
    lcd.setCursor(0, 1);
    lcd.print("Motor = ");
    delay(300);  // debounce tombol
  }
}
