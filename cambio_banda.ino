// rutina cambio de banda
void cambiobanda () {
  if (banda == 40) {
    iffreq = 1999959;          //<<<<<<<<<<<<<<<<<<<<<<<<<<<<< colocar valor de fi de la banda
    GoIF = 0;                  // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<1suma 0 resta
    banda = 20;
    bandax = "20m";
        lcd.setCursor(13, 0);
        lcd.print("USB");
  
    rx = 14150000;
  }
 
  else if (banda == 20) {
    banda = 60;
    iffreq = 2000040;           
    GoIF = 1;                    
    bandax = "60m";
       lcd.setCursor(13, 0);
       lcd.print("USB");
  
    rx = 5500000;
  }
  else {
    banda = 40;
    iffreq = 1999980; 
    GoIF = 0; 
    bandax = "40m";
      lcd.setCursor(13, 0);
      lcd.print("LSB");
  
    rx = 7030000;
  };
  fw=0;
  lcd.setCursor(6, 1);
  lcd.print(bandax);
  delay (500);
   lcd.setCursor(6, 1);
  lcd.print("       ");
};
/* else if (banda == 20) {
    banda = 15;
   iffreq = 2000000; //<<<<<<<<<<<<<<<<<<<<<<<<<<<<<colocar valor de fi de la banda
    GoIF = 0; // <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<1suma 0 resta
    bandax = "15m";
    rx = 21200000;
  }
 /* else if (banda == 15) {
    banda = 10;
    bandax = "10m";
    rx = 28500000;
  }*/
