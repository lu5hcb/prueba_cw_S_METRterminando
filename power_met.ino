void power_meter(void){
  unsigned int PMeter = analogRead(PMETER);

  Pmeter_counter = Pmeter_counter * 100;
  if(Pmeter_counter >= 1100) Pmeter_counter = 0;
  lcd.setCursor(Pmeter_counter/100+4,1);
  if(PMeter > Pmeter_counter+350) lcd.print((char)255);
  else {
  lcd.print(" ");
  }
  Pmeter_counter = Pmeter_counter/100 + 1;
  
  lcd.setCursor(12,1);
     if(PMeter >= 0 && PMeter <=200) lcd.print("  0w   ");
     if(PMeter >= 201 && PMeter <=400) lcd.print("  5w   ");
    if(PMeter >= 401 && PMeter <= 500) lcd.print("10w ");
    if(PMeter >= 501 && PMeter <= 600) lcd.print("25w ");
    if(PMeter >= 601 && PMeter <= 700) lcd.print("50w ");
    if(PMeter >= 701 && PMeter <= 900) lcd.print("75w ");
    if(PMeter >= 901 && PMeter <= 1023) lcd.print("100w ");

  }
