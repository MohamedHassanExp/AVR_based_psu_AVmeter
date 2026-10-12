#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int voltageAnalogInput = A0;
int currentAnalogInput = A1;

int currentADC = 0;
int voltageADC = 0;

int gain = 1;
float minimumShuntVoltage = 0.1;

int maximumCurrent = 5;
float shuntVoltage = 0.0;
float voltage = 0.0;
float current = 0.0;
float power = 0.0;

float R1 = 1000;  // divide the voltage down to 5v so that it can be used as an input to the adc  
float R2 = 330;
 
void setup(){
   pinMode(voltageAnalogInput, INPUT);
   pinMode(currentAnalogInput, INPUT);
   lcd.init();
   lcd.backlight();
}

float fmap(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

void loop() {
   currentADC = analogRead(currentAnalogInput);
   voltageADC = analogRead(voltageAnalogInput);
   
   shuntVoltage = fabs(fmap(currentADC, 0.0, 1024.0, 0.00, 5.0));    
   current = shuntVoltage * (maximumCurrent / (minimumShuntVoltage * gain));
   voltage = voltageADC * (5.0 / 1024.0) * ((R1 + R2) / R2);
   power = voltage * current;
   
   lcd.setCursor(0,0);
   lcd.print(voltage, 3);
   lcd.print("V");
   
   lcd.setCursor(7,0);
   lcd.print(current, 3);      
   lcd.print("A"); 
   
   lcd.setCursor(0,1); 
   lcd.print(power, 3);
   lcd.print("W");
   
   delay(500);   
}
