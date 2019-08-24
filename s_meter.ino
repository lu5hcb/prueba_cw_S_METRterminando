void s_meter(void){
  unsigned int SMeter = analogRead(SMETER);

  meter_counter = meter_counter * 100;
  if(meter_counter >= 1000) meter_counter = 0;
  lcd.setCursor(meter_counter/100+3,1);
  if(SMeter > meter_counter+350) lcd.print((char)255);
  else {
    lcd.print(" ");
  }
  meter_counter = meter_counter/100 + 1;
  
  lcd.setCursor(13,2);
     if(SMeter >= 0 && SMeter <=400) lcd.print("S-1");
     if(SMeter >= 401 && SMeter <= 500) lcd.print("S-2 ");
     if(SMeter >= 501 && SMeter <= 600) lcd.print("S-4 ");
     if(SMeter >= 601 && SMeter <= 700) lcd.print("S-6 ");
     if(SMeter >= 701 && SMeter <= 900) lcd.print("S-9 ");
     if(SMeter >= 901 && SMeter <= 1023) lcd.print("S9+   ");

  }
