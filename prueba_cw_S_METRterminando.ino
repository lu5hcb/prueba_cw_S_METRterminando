

//* VFO PARA CAHUANE FR 300 CON KEYER Y MODO SSB Y CW          
                                    // Inclusion de librerias
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <rotary.h>



/////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                     //DECLARACION DE PINES

#define PMETER       A0              // ENTRADA PARA MEDIR LA POTENCIA DE SALIDA DE 0V 5V
#define SMETER       A1              // conectar potenciometro para velocidad del keyer 0v a 5v
#define tx           13              //ENTRADA DE SEÑAL CUANDO EL EQUIPO ESTA EN TX (BAJA)
#define P_SPEED      A6              //ENTRADA DE SEÑAL DE 0V A 5V PARA MEDIR LAS SEÑALES S
// PIN               A4              //LCD I2C sdl             
// PIN               A5              //LCD I2C   scl           
#define  rit         A2             // boton rit carificador

// PIN                2              // PIN DEL ENCODER             
// PIN                3              // PIN DEL ENCODER
#define RELAY         4              // conectar para desbalancear el modulador balanceado  
#define CAM_MODO      A2              // cambia de modo ssb a cw
#define P_DASH        A3             // conectar a la raya del keyer en low
#define P_DOT         A3              // conectar a punto del keyer en low                                                                    //definicion DE PINES PARA EL DDS
#define W_CLK         8              // Pin 8 - (CLK)AD9850
#define FQ_UD         9              // Pin 9 - (FQ)AD9850
#define DATA         10              // Pin 10 - (DATA)AD9850
#define RESET        11              // Pin 11 -(RESET) AD9850
#define pulseHigh(pin) {digitalWrite(pin, HIGH); digitalWrite(pin, LOW); } // PARA CONTROLARA EL DDS
#define salto        A2              // incremento del encoder
#define P_CW         12              // relay de trasmision.  
#define banda1        A2 

Rotary r = Rotary(2, 3); // pins del rotary encoder
LiquidCrystal_I2C lcd(0x27,20,4);                        


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                    // DECLARACION DE CONSTANTES Y VARIABLES
unsigned int prit_counter=1;
unsigned int meter_counter=1;        // VARIABLE DEL MEDIDOR DE SEÑAL
unsigned int Pmeter_counter=1;       // variable el pwer_meter
int valor2;                          // Esto es una variable entera para el temporizador del delay
int contador=0;                      // Variable contador igual a cero en el inicio.para el temporizador del delay
int activado=0;                      // Al principio no ha sido activado.para el temporizador del delay
long inicio, final, actual;          // Tiempos.para el temporizador del delay
int cw;                              //variables para entrar en cw
int fw;                              //variables para entrar en cw
int speedw;                          // variable de velocidad del keyer
int_fast32_t rx = 7000000;           // Frecuencia de inicio VFO
int_fast32_t rx2 = 1;                // Variable auxiliar para retener la nueva frecuencia
int_fast32_t increment = 10;         // paso de sintonia inicial.
int_fast32_t iffreq = 0;             //FRECUENCIA INTERMEDIA
int_fast32_t iffreqrx_ssb = 1999980;             //FRECUENCIA INTERMEDIA
int_fast32_t iffreqtx= 1999980;             //FRECUENCIA INTERMEDIA
int_fast32_t iffreqrx_cw = 1999308;             //FRECUENCIA INTERMEDIA
int buttonstate = 0  ;               // var boton pasos de sintonia
int buttonband = 0;                  // var boton cambio de banda
int txssb= 0;                        // var boton  equipo en tx
int GoIF = 0;                        //var suma o resta FI
int equip = 0;                       //var numero de equipo
String hertz = " ";
int  hertzPosition = 10;
byte ones, tens, hundreds, thousands, tenthousands, hundredthousands, millions ; //Ubicacion lugares
String freq;                         // string para retener la frecuencia
int_fast32_t timepassed = millis();  //
String bandax = "40m";               // string indicador de banda ,inicia en 40m
int banda = 40;                      //inicia BAND 40m
String equipx = "VFO";               // string indicador de equipo o VFO, inicia en VFO
String BAN1 = "LSB";
int clarificadord=0;
int clarificadori=0;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                      //ASIGNA VALORES LOGICOS A LOS PINES

void setup() {
   pinMode(salto, INPUT_PULLUP);       //BOTON DE CAMBIO DE INCREMENTO    
   pinMode(buttonstate, INPUT_PULLUP); // STEP (Boton a GND que cambia los pasos de sintonia)
   pinMode(banda1, INPUT_PULLUP);      // boton a GND que cambia de banda
   pinMode(CAM_MODO, INPUT_PULLUP);    // cambia de modo alto ssb bajo cw
   pinMode(tx, INPUT_PULLUP);          // tx ssb
  // pinMode(P_AUDIO, INPUT_PULLUP);     // salida busser cw
   pinMode(P_CW, OUTPUT);              //salida para cambiar el modulador balanceado DE ESTADO
   pinMode(RELAY, OUTPUT);             // salida para relay de ssb y cw
   pinMode(P_DOT, INPUT_PULLUP);       //entrada punto cw low 
   pinMode(P_DASH, INPUT_PULLUP);      //entrada raya cw low
   digitalWrite(P_CW, LOW);            //inicia balanceado
  // lcd.begin(20, 4);                   //inicia lcd
   PCICR |= (1 << PCIE2);
   PCMSK2 |= (1 << PCINT18) | (1 << PCINT19);
   sei();
   pinMode(FQ_UD, OUTPUT);             //dds pines
   pinMode(W_CLK, OUTPUT);             //dds pines
   pinMode(DATA, OUTPUT);             //dds pines
   pinMode(RESET, OUTPUT);             //dds pines
   pinMode(RELAY, OUTPUT);             //relay de ppt tx
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  
  pulseHigh(RESET);                    // este pulso habilita el modo serie del AD9850
  pulseHigh(W_CLK);                    // este pulso habilita el modo serie del AD9850
  pulseHigh(FQ_UD);                    // este pulso habilita el modo serie del AD9850
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                    //INICIA E LA PRESENTACION DE LA PANTALLA Y DEL SOFT
                                     
  lcd.setCursor(1, 0);
  lcd.backlight();
  lcd.print("LU5HCB DDS VFO");
  delay (500);
   lcd.setCursor(1, 0);
   lcd.print("              "); 
    lcd.setCursor(411, 4);
   lcd.print("    LU5HCB DDS    ");
  lcd.setCursor(hertzPosition, 1);
  lcd.print(hertz);
   
 cambiobanda();
    delay(500);
 cambiobanda();
    delay(500);
 cambiobanda();
   delay(500);
   lcd.setCursor(6, 1);
  lcd.print("        ");
  s_meter();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                         ///COMIENSO DEL PROGRAMA
void loop(){



      cw = digitalRead(CAM_MODO);        //boton cambia de cw a HIGH ssb
  if (cw == HIGH) {
    ssb();
  }

 
  buttonband = digitalRead(banda1);       // Lee boton cambio de banda
  if (buttonband == LOW) {
      cambiobanda();}
 
                                          // Actualiza la frecuencia del display cuando la frecuencia nueva es distinta a al actual
  if (rx != rx2) {
    showFreq();
    sendFrequency(rx);
    rx2 = rx;
  }

                                           // Lee el boton STEP y cambia los pasos de sintonia (10, 100, 1k , 10k)
      buttonstate = digitalRead(salto);
  if (buttonstate == LOW) {
    
  setincrement();                           //FUNCION DE MODO DE INCREMENTO
  }

      cw = digitalRead(CAM_MODO );         //boton cambia de fonia a cw
  if (cw == LOW) {
    
 cww();                                    //FUNCION DE CW
    }
    else
    {
      ritcla();
      GoIF = 0;// 0 resta 1 suma
      iffreq=(iffreqrx_ssb-(clarificadori));                     // frecuencia de if rx SSB
      fw=0;
          lcd.setCursor(13, 0);
          lcd.print("SSB ");
}
  sendFrequency(rx);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

                                           // rutina de interrupcion del rotary encoder
ISR(PCINT2_vect) {
  unsigned char result = r.process();

  if (result) {
    if (result == DIR_CW) {
      rx = rx + increment;
    }
    else {
      rx = rx - increment;
    };
    if (rx >= 30000000) {
      rx = rx2;
    }; // LIMITE SUPERIOR DEL VFO
    if (rx <= 1000000) {
      rx = rx2;
    }; // LIMITE INFERIOR DEL VFO
  }
  }
