#include<LiquidCrystal.h>
int count=0;
int TEMP=A0;
String readString;
LiquidCrystal lcd(12,11,5,4,3,2);
void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("FULL DUPLEX");
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Waiting for data");
}
void loop(){
  int T=analogRead(TEMP);
  float v;
  float c;
  float f;
  while(count<01){
    v=(T/965.0)*5;
    c=(v-0.5)*100;
    f=(c-0.5)*(9/5)+32;
    Serial.println(f);
    lcd.setCursor(0,1);
    lcd.print(f);
    count+=1;
    delay(3);
  }
  while(Serial.available()){
    delay(3);
    char d=Serial.read();
    readString+= d;
  }
  if(readString.length()>02){
    Serial.print("CHAR REC :" + readString);
    lcd.setCursor(6,1);
    lcd.print(readString);
  }
  readString=" ";
}
