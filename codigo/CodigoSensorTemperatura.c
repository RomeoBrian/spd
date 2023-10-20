#define sensor A0
#define visualTres A3
#define visualDos A4
#define visualUno A5
#define A 12
#define B 13
#define C 7
#define D 8
#define E 9
#define F 11
#define G 10

int temperaturaTomada;
int centena;
int decena;
int unidad;
int delayTime = 25;

void setup()
{
    pinMode(A, OUTPUT);
    pinMode(B, OUTPUT);
    pinMode(C, OUTPUT);
    pinMode(D, OUTPUT);
    pinMode(E, OUTPUT);
    pinMode(F, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(visualTres, OUTPUT);
    pinMode(visualDos, OUTPUT);
    pinMode(visualUno, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    temperaturaTomada = map(analogRead(sensor), 20, 358, -40, 125);
    centena = temperaturaTomada / 100;
    decena = (temperaturaTomada - (centena * 100)) / 10;
    unidad = temperaturaTomada - (centena * 100 + decena * 10);

    displayApagado();

    if (temperaturaTomada >= 100)
    {
        displayCentenaFunction();
        sevenDisplay(centena);

        displayDecenaFunction();
        sevenDisplay(decena);

        displayUnidadFunction();
        sevenDisplay(unidad);
    }

    if (temperaturaTomada >= 0 && temperaturaTomada <= 100)
    {
        displayApagado();
        displayDecenaFunction();
        sevenDisplay(decena);
        displayUnidadFunction();
        sevenDisplay(unidad);
    }

    if (temperaturaTomada < 0)
    {
        displayCentenaFunction();
        sevenDisplay(-1);

        displayDecenaFunction();
        sevenDisplay(abs(decena));

        displayUnidadFunction();
        sevenDisplay(abs(unidad));
    }
}

void displayCentenaFunction()
{
    displayApagado();
    digitalWrite(visualUno, 0);
    digitalWrite(visualDos, 1);
    digitalWrite(visualTres, 1);
}

void displayDecenaFunction()
{
    displayApagado();
    digitalWrite(visualUno, 1);
    digitalWrite(visualDos, 0);
    digitalWrite(visualTres, 1);
}

void displayUnidadFunction()
{
    displayApagado();
    digitalWrite(visualUno, 1);
    digitalWrite(visualDos, 1);
    digitalWrite(visualTres, 0);
}

void displayApagado()
{
    delay(delayTime);
    digitalWrite(visualUno, 1);
    digitalWrite(visualDos, 1);
    digitalWrite(visualTres, 1);
}

void sevenDisplay(int number)
{
    switch (number)
    {
    case 1:
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    case 2:
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 0);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 0);
        digitalWrite(G, 1);
        break;
    case 3:
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 1);
        break;
    case 4:
        digitalWrite(A, 0);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 5:
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 0);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 6:
        digitalWrite(A, 1);
        digitalWrite(B, 0);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 7:
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
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
        digitalWrite(D, 1);
        digitalWrite(E, 0);
        digitalWrite(F, 1);
        digitalWrite(G, 1);
        break;
    case 0:
        digitalWrite(A, 1);
        digitalWrite(B, 1);
        digitalWrite(C, 1);
        digitalWrite(D, 1);
        digitalWrite(E, 1);
        digitalWrite(F, 1);
        digitalWrite(G, 0);
        break;
    case -1:
        digitalWrite(A, 0);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 1);
        break;
    case 10:
        digitalWrite(A, 0);
        digitalWrite(B, 0);
        digitalWrite(C, 0);
        digitalWrite(D, 0);
        digitalWrite(E, 0);
        digitalWrite(F, 0);
        digitalWrite(G, 0);
        break;
    }
}
