void setincrement(void) {
  if (increment == 10) {
    increment = 100;
    hertz = "_";
    hertzPosition = 6;

  }
  else if (increment == 100) {
    increment = 1000;
    hertz = "_";
    hertzPosition = 4;
  }
  else if (increment == 1000) {
    increment = 10000;
    hertz = "_";
    hertzPosition = 3;
  }

   else if (increment == 10000) {
    increment = 1000000;
    hertz = "_";
    hertzPosition = 2;
  }
  else {
    increment = 10;
    hertz = "_";
    hertzPosition = 7;
  };
   lcd.setCursor(1, 0);
 lcd.print(millions);

  lcd.print(hundredthousands);
  lcd.print(tenthousands);
  lcd.print(thousands);
  lcd.print(".");
  lcd.print(hundreds);
  lcd.print(tens);

  lcd.print(" Kz ");

  timepassed = millis();
  lcd.setCursor(hertzPosition, 0);
  lcd.print(hertz);
  delay(500);
}
