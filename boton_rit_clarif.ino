void ritcla(void){
     unsigned int prit = analogRead(rit);  
    clarificadori=map(prit,0,1000,-2400,2100); 
 if (clarificadori<1){
    delay(100); 
   lcd.setCursor(9,0);
   lcd.print("  kk   ");
   lcd.setCursor(9,0);
   lcd.print(clarificadori);
 } 

  
 if (clarificadori>1){
   lcd.setCursor(9,0);
   delay(99);
   lcd.print("    ");
   lcd.setCursor(9,0);
   lcd.print(clarificadori*10);
 } 

  }

  
