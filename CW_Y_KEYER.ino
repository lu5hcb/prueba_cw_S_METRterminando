void cww(){
  if (fw == 0 && cw == LOW){
   GoIF = 0;
   iffreq=1999398;
   lcd.setCursor(0, 3);
   lcd.print("RCW");
   fw=1;}
           lcd.setCursor(12, 0);
           lcd.print(" CW ");  

  
  
  speedw = analogRead(P_SPEED)/2;            // Read the keying speed from potmeter
 
  if(!digitalRead(P_DOT))                    // If the dot lever is presssed..
  {
    digitalWrite(RELAY, HIGH);
       lcd.setCursor(0, 3);  
       lcd.print("TCW"); 
            GoIF = 0;
            iffreq=iffreqtx;
    keyAndBeep(speedw);                      // ... send a dot at the given speed
    delay(speedw); 
       power_meter();   
        inicio = millis();
        final = inicio + 800;                //     and wait before sending next
  }
  if(!digitalRead(P_DASH))                   // If the dash lever is pressed...
  {   
    digitalWrite(RELAY, HIGH); 
      lcd.setCursor(0, 3);  
      lcd.print("TCW"); 
           GoIF = 0;
           iffreq=iffreqtx;
    keyAndBeep(speedw*3);                    // ... send a dash at the given speed
    delay(speedw);   
                                          //     and wait before sending next
       power_meter();
        inicio = millis();                   // marca activado=1 y guarda el tiempo de inicio.
      
        final = inicio + 800; 
  }
                                            
        activado = 1; 
        actual = millis();  
          
if ( activado == 1 && (actual >final) ) {   // Si fue activado=1 y el tiempo actual es mayor que el final....
    
     digitalWrite(RELAY, LOW);  
    lcd.setCursor(0, 3);
    lcd.print("RCW");
          GoIF = 0;                         // 0 resta 1 suma
          iffreq=iffreqrx_cw;                  // frecuencia de if rx 
  s_meter();
       activado = 0; 
}                            


  
}
