/*
#       _\|/_   A ver..., ¿que tenemos por aqui?
#       (O-O)        
# ---oOO-(_)-OOo---------------------------------
 
 
#################################################
# ********************************************* #
# *  PLAY MUSIC WITH SIMPLE TONES IN ARDUINO  * #
# *      Autor: Eulogio López Cayuela         * #
# *                                           * #
# *    Versión 1.0    Fecha: 26/04/2015       * #
# ********************************************* #
#################################################
*/


#define PIN_SONIDO 7        // Patilla para conectar el 'positivo' del piezoelectrico/altavoz

int PAUSA = 550;

// Definir las frecuencias de las notas mucicales
#define DO 523
#define RE 587
#define MI 659
#define FA 698
#define SOL 783
#define LA 880
#define SI 897

int cancion[] = {
  DO, DO, RE, DO, FA, MI, PAUSA,
  DO, DO, RE, DO, SOL, FA, PAUSA,
  DO, DO, LA,
  FA, FA, MI,RE, PAUSA,
  SI, SI, LA, FA, SOL, LA,PAUSA,
  PAUSA,PAUSA,PAUSA,PAUSA,PAUSA};


//*******************************************************
//         FUNCION DE CONFIGURACION
//*******************************************************
void setup()
{
  pinMode(PIN_SONIDO, OUTPUT);
  digitalWrite (PIN_SONIDO,LOW);    // Ponemos a GND la patilla 'positiva' del piezoelectrico para evitar
                                    // sonidos indeseados hasta el momento de ser activado 
}


//*******************************************************
//        BUCLE PRINCIPAL DEL PROGRAMA
//*******************************************************
void loop()
{
  for (int i=0; i<34; i++){
    if (cancion[i] == PAUSA){
      delay(PAUSA);
    }
    else {
      tone(PIN_SONIDO, cancion[i], 250); //patilla, nota, tiempo
      delay (400);
    }      
  }
}


//*******************************************************
//                    FIN DE PROGRAMA
//*******************************************************

