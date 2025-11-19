#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
int lcd_key = 0;
int adc_key_in = 0;

#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5
#define dirMotor 2
#define pwmMotor 3

float Voltage = 0;
float Current = 0;
float vRead = 0;
float R1 = 30000;
float R2 = 3300;
float iRead = 0;
int mVperAmp = 185;
int ACSoffset = 1650;

int read_LCD_buttons() {
    adc_key_in = analogRead(0);
    if (adc_key_in > 1022) return btnNONE;
    if (adc_key_in < 50) return btnRIGHT;
    if (adc_key_in < 250) return btnUP;
    if (adc_key_in < 450) return btnDOWN;
    if (adc_key_in < 750) return btnLEFT;
    if (adc_key_in < 1019) return btnSELECT;
    return btnNONE;
}

void setup() {
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("I = ");
    lcd.setCursor(0, 1);
    lcd.print("V = ");
    pinMode(10, OUTPUT);
    analogWrite(10, 50);
    pinMode(dirMotor, OUTPUT);
    pinMode(pwmMotor, OUTPUT);
}

void loop() {
    lcd_key = read_LCD_buttons();
    
    if (lcd_key == btnSELECT) {
        digitalWrite(dirMotor, LOW);
        digitalWrite(pwmMotor, HIGH);
    } else {
        digitalWrite(dirMotor, HIGH);
        digitalWrite(pwmMotor, LOW);
    }
    
    iRead = analogRead(11) * 3300 / 1024;
    Current = ((iRead - ACSoffset) / mVperAmp) * 1000;
    
    vRead = analogRead(10) * 3.3 / 1024;
    Voltage = vRead / (R2 / (R1 + R2));
    
    lcd.setCursor(5, 0);
    lcd.print(Current);
    
    if (Voltage > 10) {
        lcd.setCursor(5, 1);
        lcd.print(Voltage);
    } else {
        lcd.setCursor(5, 1);
        lcd.print("OFF ");
    }
    
    delay(500);
}
