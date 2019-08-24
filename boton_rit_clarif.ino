void ritcla(void){
     unsigned int prit = analogRead(rit);

  //prit_counter = prit_counter * 100;
 // if(prit_counter >= 1100) prit_counter = 0
  
    clarificadori=map(prit,0,1000,-2400,2100); 
 if (clarificadori<1){
  delay(100);
 
    lcd.setCursor(9,0);
 lcd.print("     ");
 lcd.setCursor(9,0);
  lcd.print(clarificadori);
 } 

  
 if (clarificadori>1){
   lcd.setCursor(9,0);
   delay(100);
 lcd.print("      ");
  lcd.setCursor(9,0);
  lcd.print(clarificadori*10);
 } 

 // lcd.setCursor(8,1);
 // lcd.print("+");
 
 

/*if(prit<512) {
    int clarificadord=map(prit,512,1024,0,100);
   lcd.setCursor(8,0);  
  lcd.print("-");
  lcd.setCursor(9,0);
   lcd.print(clarificadord);
  }*/
  }
