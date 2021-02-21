#define _LCD_TYPE 1 //Магическая константа. Тип подключения дисплея: 1 - по шине I2C, 2 - десятиконтактное. Обязательно указывать ДО подключения библиотеки
#include <LCD_1602_RUS_ALL.h>

LCD_1602_RUS lcd(0x27, 16, 2);

void setup() {
  
  lcd.init(); //Инициализация LCD (по умолчанию для ESP8266: 4 - SDA, 5 - SCL)
  //lcd.init(0, 2); //ESP8266-01 I2C: 0 - SDA, 2 - SCL

  // Печать сообщения на LCD
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("ПРИВЕТ МИР");
  lcd.setCursor(0, 1);
  lcd.print("ПО-РУССКИ");
}

void loop() {
}
