int potPin = A0;
int potMax = 1023;

int seg1 = 12;
int seg2 = 11;
int seg3 = 10;
int seg4 = 9;
int seg5 = 8;
int seg6 = 7;
int seg7 = 6;
int seg8 = 5;

int numLetras = 6;

int pinosAon[]={seg1, seg2, seg3, seg5, seg6, seg7};
int pinosAoff[]={seg4, seg8};
int qtdPinosAon = sizeof(pinosAon)/sizeof(int);
int qtdPinosAoff = sizeof(pinosAoff)/sizeof(int);

int pinosEon[]={seg1, seg4, seg5, seg6, seg7};
int pinosEoff[]={seg2, seg3, seg8};
int qtdPinosEon = sizeof(pinosEon)/sizeof(int);
int qtdPinosEoff = sizeof(pinosEoff)/sizeof(int);

int pinosIon[]={seg5, seg6};
int pinosIoff[]={seg1, seg2, seg3, seg4, seg7, seg8};
int qtdPinosIon = sizeof(pinosIon)/sizeof(int);
int qtdPinosIoff = sizeof(pinosIoff)/sizeof(int);

int pinosOon[]={seg1, seg2, seg3, seg4,seg5, seg6};
int pinosOoff[]={seg7, seg8};
int qtdPinosOon = sizeof(pinosOon)/sizeof(int);
int qtdPinosOoff = sizeof(pinosOoff)/sizeof(int);

int pinosUon[]={seg2, seg3, seg4,seg5, seg6};
int pinosUoff[]={seg1, seg7, seg8};
int qtdPinosUon = sizeof(pinosUon)/sizeof(int);
int qtdPinosUoff = sizeof(pinosUoff)/sizeof(int);

int pinosPton[]={seg8};
int pinosPtoff[]={seg1, seg2, seg3, seg4,seg5, seg6, seg7};
int qtdPinosPton = sizeof(pinosPton)/sizeof(int);
int qtdPinosPtoff = sizeof(pinosPtoff)/sizeof(int);

void ligaA(){
  for(int i=0; i<qtdPinosAon; i++){
    digitalWrite(pinosAon[i], HIGH);
  }
  for(int j=0; j<qtdPinosAoff; j++){
    digitalWrite(pinosAoff[j], LOW);
  }
}

void ligaE(){
  for(int i=0; i<qtdPinosEon; i++){
    digitalWrite(pinosEon[i], HIGH);
  }
  for(int j=0; j<qtdPinosEoff; j++){
    digitalWrite(pinosEoff[j], LOW);
  }
}

void ligaI(){
  for(int i=0; i<qtdPinosIon; i++){
    digitalWrite(pinosIon[i], HIGH);
  }
  for(int j=0; j<qtdPinosIoff; j++){
    digitalWrite(pinosIoff[j], LOW);
  }
}

void ligaO(){
  for(int i=0; i<qtdPinosOon; i++){
    digitalWrite(pinosOon[i], HIGH);
  }
  for(int j=0; j<qtdPinosOoff; j++){
    digitalWrite(pinosOoff[j], LOW);
  }
}

void ligaU(){
  for(int i=0; i<qtdPinosUon; i++){
    digitalWrite(pinosUon[i], HIGH);
  }
  for(int j=0; j<qtdPinosUoff; j++){
    digitalWrite(pinosUoff[j], LOW);
  }
}

void ligaPonto(){
  for(int i=0; i<qtdPinosPton; i++){
    digitalWrite(pinosPton[i], HIGH);
  }
  for(int j=0; j<qtdPinosPtoff; j++){
    digitalWrite(pinosPtoff[j], LOW);
  }
}



void setup() {

  Serial.begin(4800);

  pinMode(potPin, INPUT);

  pinMode(seg1, OUTPUT);
  pinMode(seg2, OUTPUT);
  pinMode(seg3, OUTPUT);
  pinMode(seg4, OUTPUT);
  pinMode(seg5, OUTPUT);
  pinMode(seg6, OUTPUT);
  pinMode(seg7, OUTPUT);
}

void loop() {

  int potValue = analogRead(potPin);
  Serial.println(potValue);

  if (potValue > 0 && potValue < (potMax/numLetras)*1){
    ligaA();
  }

  if (potValue > (potMax/numLetras*1) && potValue < (potMax/numLetras)*2){
    ligaE();
  }

  if (potValue > (potMax/numLetras)*2 && potValue < (potMax/numLetras)*3){
    ligaI();
  }

  if (potValue > (potMax/numLetras)*3 && potValue < (potMax/numLetras)*4){
    ligaO();
  }

  if (potValue > (potMax/numLetras)*4 && potValue < (potMax/numLetras)*5){
    ligaU();
  }

  if (potValue > (potMax/numLetras)*5 && potValue < (potMax/numLetras)*6){
    ligaPonto();
  }



  // ligaA();
  // delay(1000);
  // ligaE();
  // delay(1000);
  // ligaI();
  // delay(1000);
  // ligaO();
  // delay(1000);
  // ligaU();
  // delay(1000);
}
