Exercício 4:


int pressionado = 0;
int contador = 0;

int ledPin = 13;
int botaoPin = 2;

// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(botaoPin, INPUT); 
  Serial.begin(9600);
  digitalWrite(ledPin,LOW);
  
}

void loop() {

  while (digitalRead(botaoPin) ==  HIGH){
    pressionado = 1;
    delay (100);
  }

    if (pressionado == 1 ){
      contador ++;
      pressionado = 0;
    }

    if (contador == 3 && digitalRead(ledPin) == HIGH){
      digitalWrite(ledPin,LOW);
      contador = 0;
    }

    if (contador == 5){
      digitalWrite(ledPin,HIGH);
      contador = 0;
    }
}
 

    