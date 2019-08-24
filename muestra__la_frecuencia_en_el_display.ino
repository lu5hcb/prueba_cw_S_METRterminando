
// muestra  la frecuencia en el display
void showFreq() {
  millions = int((rx / 1000000));
  hundredthousands = ((rx / 100000) % 10);
  tenthousands = ((rx / 10000) % 10);
  thousands = (((rx / 1000) % 10));
  hundreds = (((rx / 100) % 10));
  tens = ((rx / 10) % 10);
  ones = ((rx / 1) % 10);
  lcd.setCursor(0, 0);
  lcd.print("            ");
  if (millions > 9) {
    lcd.setCursor(1, 0);
  }
  else {
    lcd.setCursor(1, 0);
  }
  
  lcd.print(millions);

  lcd.print(hundredthousands);
  lcd.print(tenthousands);
  lcd.print(thousands);
  lcd.print(".");
  lcd.print(hundreds);
  lcd.print(tens);

 // lcd.print(" Kz ");

  timepassed = millis();

};
