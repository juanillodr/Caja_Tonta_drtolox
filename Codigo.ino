//Autor: Juan Dominguez Rodriguez

//Inspirado en https://github.com/vagelis-chantzis/UselessBox/blob/master/UselessBox.ino y en https://www.thingiverse.com/thing:4212064
//Y modificado para la posición y tipo de los motores que uso.


#include <Servo.h> //Incluimos la librera servo.h


//Definimos variables.

#define swPin 2 //Definimos en pin 2 como swPin

#define MAX_brazo  0      //Defino una variable y le asigno el valor 0 grados que es la maxima apertura del brazo

#define MAX_tapadera  75  //Defino una segunda variable y le asigno un valor 75 grados que es la maxima apertura de la tapa



//Definimos los nombres de los servos para identificarlos en el programa.

Servo tapadera;  // Definimos el nombre el servo que movera la tapa
Servo brazo;  // Definimos el nombre del servo que movera el brazo


//Defino la constante posicin y count, la cual ir acumulando la suma de las iteraciones.

int pos = 0;    // variable que guardara la posicion del motor.
int count = 0;



//Comienzo el programa

void setup() {

  Serial.begin(9600);

  pinMode(swPin, INPUT);

  brazo.attach(9);  // Defino la salida digital para el servo 9 que sera el del brazo

  tapadera.attach(10);  // Defino la salida digital para el servo 10 que sera el de la tapadera. 




//Posicionamos los brazos en el numero de grados que corresponda segun la forma de la caja y la disposicin del servo con respecto a esta. 

  brazo.write(150);
  delay(200);
  tapadera.write(135);
  delay(200);
  
  //brazo.write(150);
  //tapadera.write(135);

}



//Comenzamos a escribir el programa que iterara en el tiempo de forma continua.

void loop() {

  delay(100);

  if (digitalRead(swPin) == HIGH)  //Con este if, conseguimos que si el pin 2 esta el valor alto, el algoritmo itere entrando por aqui.

  {

    count++;

    delay(500);

    if (count > 5)

      count = 1;

    switch (count) {

      case 1:

        simpleclose();

        break;

      case 2:

        simpleclose();

        break;

      case 3:

        simpleclose2();

        break;

      case 4:

        crazydoor();

        break;

      case 5:

        slow();

        break;

    }



    delay(2000);

  }

}


//Creamos las distintas posibles soluciones de entretenimiento y juego entra levantar la tapa, y sacar el brazo para apagar el interruptor. 

void simpleclose() {

  //POSICIONES INICIALES
  //brazo.write(150);
  //tapadera.write(135);
  
  //POSICIONES MAXIMAS
  //MAX_brazo  0
  //MAX_tapadera  90


  for (pos = 135; pos >= 75; pos -= 3)   { //abre le tapadera

    tapadera.write(pos);

    delay(15);

  }

  for (pos = 150; pos >= 0+20 ; pos -= 4) { // recoje le brazo

    brazo.write(pos);

    delay(15);

  }



  brazo.write(0); // Pulsa el boton

  delay(200);



  for (pos = 0; pos <= 150; pos += 3) {  //recoje le brazo

    brazo.write(pos);

    delay(5);

  }



  for (pos = 75; pos >= 135; pos -= 3)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  tapadera.write(135);

}


//***********************************************************************************
//Otra posibles y segunda solucion que iterara a la segunda vez que pulsemos el boton

void simpleclose2() {

  
  
  //POSICIONES INICIALES
  //brazo.write(150);
  //tapadera.write(135);
  
  //POSICIONES MAXIMAS
  //MAX_brazo  0
  //MAX_tapadera  75


  for (pos = 135; pos >= 75; pos -= 3)   { //abre le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(800);

  for (pos = 150; pos >= 0 + 20; pos -= 4) { // recoje le brazo

    brazo.write(pos);

    delay(15);

  }

  delay(1000);

  brazo.write(MAX_brazo); // Pulsa el boton

  delay(2000);



  for (pos = MAX_brazo; pos <= 150; pos += 5) {  //recoje le brazo

    brazo.write(pos);

    delay(15);

  }



  for (pos = 75; pos <= 135; pos += 3)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  tapadera.write(135);

}





//*********************************************************************************************************************
//Otra posibles y segunda solucion que iterara a la segunda vez que pulsemos el boton

void crazydoor() {

  //POSICIONES INICIALES
  //brazo.write(150);
  //tapadera.write(135);
  
  //POSICIONES MAXIMAS
  //MAX_brazo  0
  //MAX_tapadera  75

  for (pos = 135; pos >= 75 ; pos -= 2)   { //abre le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(200);

  for (pos = 75 ; pos <= 125 ; pos += 2)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(200);

  for (pos = 125; pos >= 75 ; pos -= 3)   { //abre le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(200);

  for (pos = 75 ; pos <= 135; pos += 3)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(700);

  for (pos = 135; pos >= 75; pos -= 4)   { //abre le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(700);

  for (pos = 75; pos <= 125 ; pos += 4)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(200);

  for (pos = 125; pos >= 75; pos -= 5)   { //abre le tapadera

    tapadera.write(pos);

    delay(15);

  }

  delay(200);

  for (pos = 150; pos >= MAX_brazo + 20; pos -= 3) { // recoje le brazo

    brazo.write(pos);

    delay(15);

  }

  delay(1000);

  brazo.write(MAX_brazo); // Pulsa el boton

  delay(200);

  for (pos = MAX_brazo; pos <= 150; pos += 3) {  //recoje le brazo

    brazo.write(pos);

    delay(5);

  }

  for (pos = 75; pos <= 135; pos += 3)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  tapadera.write(135);

}



//************************************************************************************************

//Otra posibles y segunda solucion que iterara a la segunda vez que pulsemos el boton

void slow()

//POSICIONES INICIALES
  //brazo.write(150);
  //tapadera.write(135);
  
  //POSICIONES MAXIMAS
  //MAX_brazo  0
  //MAX_tapadera  75

{

  for (pos = 135; pos >= 75; pos -= 1)   { //abre le tapadera

    tapadera.write(pos);

    delay(40);

  }

  for (pos = 150; pos >= 0 + 5; pos -= 1) { // recoje le brazo

    brazo.write(pos);

    delay(40);

  }



  for (pos = MAX_brazo; pos >= MAX_brazo + 50; pos += 1) {  //recoje le brazo

    brazo.write(pos);

    delay(40);

  }

  brazo.write(MAX_brazo); // Pulsa el boton

  delay(1000);

  for (pos = MAX_brazo; pos <= 150; pos += 1) {  //recoje le brazo

    brazo.write(pos);

    delay(40);

  }



  for (pos = 75; pos <= 135; pos += 1)  { // cierra le tapadera

    tapadera.write(pos);

    delay(40);

  }

  for (pos = 135; pos >= 85 + 10; pos -= 2)   { //abre le tapadera

    tapadera.write(pos);

    delay(40);

  }

  delay(2000);

  for (pos = MAX_tapadera; pos <= 135; pos += 2)  { // cierra le tapadera

    tapadera.write(pos);

    delay(15);

  }

  tapadera.write(135);

}
