 
 void ssb() 
  {
   
      txssb = digitalRead(tx);           //señal de que hay tx en el equipo
 if (txssb == LOW) {
 /*   else{ */       digitalWrite(RELAY, HIGH); 
            lcd.setCursor(0, 1);
            lcd.print("TXs");
    
  power_meter();                          // MUESTRA POWER EN DISPLAY
  }
  
  else
  {
            digitalWrite(RELAY, LOW); 
            lcd.setCursor(0, 1);
            lcd.print("RXs");
            digitalWrite(RELAY, LOW);
            
  s_meter();  
          // MUESTRA SMETER EN DISPLAY
  }
    }
