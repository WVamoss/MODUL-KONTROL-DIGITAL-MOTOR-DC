#include <LiquidCrystal.h>

// Pin definitions
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);
#define dirMotor 2
#define pwmMotor 3

// Button definitions
#define btnRIGHT 0
#define btnUP 1
#define btnDOWN 2
#define btnLEFT 3
#define btnSELECT 4
#define btnNONE 5

// Variables
int lcd_key = 0;
int adc_key_in = 0;

// Function to read LCD buttons
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
    // Initialize LCD
    lcd.begin(16, 2);
    lcd.setCursor(0, 0);
    lcd.print("MOTOR TEST");
    
    // Initialize pins
    pinMode(10, OUTPUT);
    analogWrite(10, 50);
    pinMode(dirMotor, OUTPUT);
    pinMode(pwmMotor, OUTPUT);
}

void loop() {
    // CCW Rotation
    lcd.setCursor(0, 1);
    lcd.print("dirLOW CCW   ");
    digitalWrite(dirMotor, LOW);
    digitalWrite(pwmMotor, HIGH);
    delay(1000);
    
    // CW Rotation  
    lcd.setCursor(0, 1);
    lcd.print("dirHIGH CW   ");
    digitalWrite(dirMotor, HIGH);
    digitalWrite(pwmMotor, LOW);
    delay(1000);
}
