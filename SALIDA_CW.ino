

                               // ESTA FUNCION ACTIVA LOS RELE DE TX Y DEMODULA EL MODULADOR BALANCEADO
void keyAndBeep(int speedw)
{
  digitalWrite(P_CW , HIGH);                    // TX MODULAdor
   digitalWrite(RELAY , HIGH);                  // TX RELAY
  for (int i=0; i < (speedw/5); i++)    // LOOP DE SONIDO Y TIEMPO
  {
  // digitalWrite(P_AUDIO, HIGH);
    delay(1);
  //digitalWrite(P_AUDIO, LOW);
   delay(1);
  }
  digitalWrite(P_CW , LOW);             //  RX MODULADOR
   digitalWrite(RELAY , LOW);           //  RX RELAY
   
}
