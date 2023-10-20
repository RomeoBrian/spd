// C++ code
//
/*
   	Diseñar un contador de 0 a 99 utilizando 
   	dos displays de 7 segmentos y tres botones para
	controlar la cuenta.
	Debes implementar la técnica de multiplexación 
	para mostrar los dígitos
	en los displays. 
	El contador debe comenzar en 0 
	y debe ser capaz de aumentar o disminuir
	su valor en una unidad con los botones.
*/

//Definicion de pines para tomar los display y los pulsadores
#define A 7
#define B 8
#define C 9
#define D 10
#define E 11
#define F 12
#define G 13
#define switchPrimos 5
#define pulsadorAumenta 4
#define pulsadorDisminuye 3
#define pulsadorReset 2


void setup()
{
  pinMode(7, OUTPUT);          // segmento A
  pinMode(8, OUTPUT);          // segmento B
  pinMode(9, OUTPUT);          // segmento C
  pinMode(10, OUTPUT);          // segmento D
  pinMode(11, OUTPUT);          // segmento E
  pinMode(12, OUTPUT);          // segmento G
  pinMode(13, OUTPUT);          // segmento F
  pinMode(4, INPUT_PULLUP);		//pulsador sumar
  pinMode(3, INPUT_PULLUP);		//pulsador restar
  pinMode(2, INPUT_PULLUP);		//pulsador reiniciar
  pinMode(A4, OUTPUT);			//primer display
  pinMode(A5, OUTPUT);			//segundo display
  Serial.begin(9600);
  
}

//inicializacion de variables a utilizar dentro del codigo
int contadorNumeros = 0;


//inicializamos los lectores de pulsadores 
//para poder lograr el antirrebote
int leerReiniciar = 0;
int leerSumar = 0;
int leerRestar = 0;
int restarAnterior = 1;
int sumarAnterior = 1;
int reiniciarAnterior = 1;
int swPrimosContador = 1;
int numeroPrimo = 0;
int i = 0;
int ultimoNumeroPrimo = 0;
int estadoSw = 1;

  
void loop() {      
  
  //ejecutamos el antirrebote para 
  //poder lograr un uso propio de los pulsadores
  
  swPrimosContador = digitalRead(switchPrimos);
  
  int presionoTecla = teclaPrecionada();
  
	if(swPrimosContador == 1)
    {
      if(estadoSw == 0)
      {
        contadorNumeros =0;
        estadoSw = 1;
      }
      contadorNumeros = manejoPulsadores(presionoTecla);
      numeroPrimo = esPrimo(contadorNumeros);
      //llamamos la funcion para el manejo de los display
      manejarDisplay(numeroPrimo);
    }
  else
  {
    if(estadoSw == 1 )
      {
        contadorNumeros =0;
        estadoSw = 0;
      }
    contadorNumeros = manejoPulsadores(presionoTecla);
  	//llamamos la funcion para el manejo de los display
  	manejarDisplay(contadorNumeros);  
  }
  
  
  
}


int manejoPulsadores(int presionoTecla)
{
  if(presionoTecla == pulsadorAumenta)
    {
       contadorNumeros++;

        if(contadorNumeros > 99)
      {
        contadorNumeros = 0;
      }
    }
    else if(presionoTecla == pulsadorDisminuye)
    {
      contadorNumeros--;
      if(contadorNumeros < 0)
      {
        contadorNumeros = 99;
      }
    }
    else if(presionoTecla == pulsadorReset)
    {
       contadorNumeros = 0;
    }
  return contadorNumeros;
}


void manejarDisplay(int contadorNumeros)
{
  //con esta funcion queremos lograr el funcionamiento del multiplexado
  //al estar los display en un sistema de multiplexado
  //controlamos con esta funcion cual display se enciende en que momento
  //de esta menera con el uso de delay logramos el efecto de que estan 
  //encendidos ambos displays cuando en realidad se encienden y se apagan
  
  
  //Funcion para manejar los numeros y el prendido y apagado de 
  //displays, tomando el contador
  //aca le dividimos 10 al contador para poder sacar los digitos
  numerosDisplay(contadorNumeros/10); 
  prenderDisplay(1,0);
  delay(20);
  //sacamos las decenas para mostrar en el primer display
  numerosDisplay(contadorNumeros - 10*((int)contadorNumeros/10)); 
  prenderDisplay(0,1);
  delay(20);
  
}



void numerosDisplay(int numero){
//funcion para mostrar los numeros correspondientes
//llamamos a la funcion borrar display para el apagado de los digitos
  borrar_display();
      
  switch (numero) {
  	case 0:
      digitalWrite(A, 1); 
      digitalWrite(B, 1); 
      digitalWrite(C, 1); 
      digitalWrite(D, 1); 
      digitalWrite(E, 1); 
      digitalWrite(F, 1); 
      break;
  	case 1: 
      	digitalWrite(B, 1); 
      	digitalWrite(C, 1); 
    	break;
    case 2: 
      	digitalWrite(A, 1);
    	digitalWrite(B, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(E, 1); 
    	digitalWrite(D, 1); 
    	break;
    case 3: 
      	digitalWrite(A, 1);
    	digitalWrite(B, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1); 
    	digitalWrite(D, 1); 
    	break;
    case 4: 
      	digitalWrite(F, 1);
    	digitalWrite(B, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1); 
    	break;
    case 5: 
      	digitalWrite(A, 1);
    	digitalWrite(F, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1);
    	digitalWrite(D, 1);
    	break;
    case 6: 
      	digitalWrite(A, 1);
    	digitalWrite(F, 1); 
      	digitalWrite(G, 1); 
    	digitalWrite(C, 1);
    	digitalWrite(E, 1);
    	digitalWrite(D, 1);
    	break;
    case 7: 
      	digitalWrite(A, 1);
    	digitalWrite(B, 1); 
    	digitalWrite(C, 1);
    	break;
    case 8: 
      	digitalWrite(A, 1); 
      	digitalWrite(B, 1); 
      	digitalWrite(C, 1); 
      	digitalWrite(D, 1); 
      	digitalWrite(E, 1); 
      	digitalWrite(F, 1);
    	digitalWrite(G, 1);
    	break;
    case 9: 
      	digitalWrite(A, 1); 
      	digitalWrite(B, 1); 
      	digitalWrite(C, 1);  
      	digitalWrite(F, 1);
    	digitalWrite(G, 1);
    	break;
  	default:
    	break;
}
  	
}


void borrar_display(){
	
  	digitalWrite(A, 0); 
	digitalWrite(B, 0); 
	digitalWrite(C, 0); 
	digitalWrite(D, 0); 
	digitalWrite(E, 0); 
	digitalWrite(F, 0); 
	digitalWrite(G, 0); 

}



void prenderDisplay(int display1, int display2){
  //funcion que controla el encendido de los diaplay
  //de esta menera podemos indicar cual display prender y en que momento
  digitalWrite(A5, display1);
  digitalWrite(A4, display2);
}


int teclaPrecionada(void)
{
  //Funcion para recrear el antirrebote
  //en una primera instancia obtenemos los pulsadores
  leerReiniciar = digitalRead(pulsadorReset);
  leerSumar = digitalRead(pulsadorAumenta);
  leerRestar = digitalRead(pulsadorDisminuye);
  
  
  //al no estar pulsados se inicializan en 1 y tomamos ese estado
  if(leerSumar == 1)
  {
    sumarAnterior = 1;
  }
  if(leerRestar  == 1)
  {
    restarAnterior = 1;
  }
  if(leerReiniciar  == 1)
  {
    reiniciarAnterior = 1;
  }
  
  //preguntamos si el fue pulsado y si el estado anterior es distinto
  //entonces lo modificamos y devolvemos el pulsador
  //de esta manera logramos el efecto antirrebote
   if(leerSumar == 0 && leerSumar != sumarAnterior)
  {
  	sumarAnterior = leerSumar;
    return pulsadorAumenta;
  }
  
  if(leerRestar == 0 && leerRestar != restarAnterior)
  {
  	restarAnterior = leerRestar;
    return pulsadorDisminuye;
  }
  
  if(leerReiniciar == 0 && leerReiniciar != sumarAnterior)
  {
  	reiniciarAnterior = leerReiniciar;
    return pulsadorReset;
  }
  // si no pasa nada de lo anterior se devuelve 0
  return 0;
}

//con esta funcion podemos determinar si el numero es primo o no 

int esPrimo(int numero)
{
  if(numero != 1)
  {
    for(i=2; i<numero ; i++ )
    {
      if(numero%i==0) return ultimoNumeroPrimo; 
    }
    ultimoNumeroPrimo = numero;
  	return numero;
  }return 0;
}
