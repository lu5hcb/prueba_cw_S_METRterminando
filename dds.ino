
void sendFrequency(double frequency) {  
    if (GoIF == 1) {
    frequency = frequency + iffreq;
  }; //Si el pin esta en alto SUMA la FI
  if (GoIF == 0) {
    frequency = frequency - iffreq  ;
     }; // Si el pin esta en bajo RESTA la FI 
  int32_t freq = frequency * 4294967296./180000000;  // note 180 MHz clock on 9851. also note slight adjustment of this can be made to correct for frequency error of onboard crystal
  for (int b=0; b<4; b++, freq>>=8) {
    tfr_byte(freq & 0xFF);
  }
  tfr_byte(0x001);   // Final control byte, LSB 1 to enable 6 x xtal multiplier on 9851 set to 0x000 for 9850
  pulseHigh(FQ_UD);  // Done!  Should see output
}
// transfers a byte, a bit at a time, LSB first to the 9851 via serial DATA line
void tfr_byte(byte data)
{
  for (int i=0; i<8; i++, data>>=1) {
    digitalWrite(DATA, data & 0x01);
    pulseHigh(W_CLK);   //after each bit sent, CLK is pulsed high
  }
}
