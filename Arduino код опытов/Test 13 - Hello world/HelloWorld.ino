#include <Wire.h> // библиотека для управления устройствами по I2C 
#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.begin(16, 2); // Инициируем экран
  lcd.setBacklight(255);//Включаем подсветку
  lcd.home();//Переводим курсор на первй симвом
  lcd.clear();//Очищаем экран
  lcd.print("HELLO");
  lcd.setCursor(0,1);//Переводим курсор на первый символ второй строки
  lcd.print("WORLD");
} 

void loop()
{
}
