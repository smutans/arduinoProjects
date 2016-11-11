/*
4 Buttons and 4 LEDs
Pressing BTN1, led 1 blinks with 1s frequency
Pressing BTN2, led 1 blinks with 2s frequency
Pressing BTN3, led 1 blinks with 3s frequency
Pressing BTN4, led 1 blinks with 4s frequency
*/

// -> Setting Leds and buttons pins according to arduino connection
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int btn4 = 5;

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
// 


// -> Variables to catch buttons states. (Atual = current, Anterior = previous)
int btn1Atual;
int btn1Anterior;

int btn2Atual;
int btn2Anterior;

int btn3Atual;
int btn3Anterior;

int btn4Atual;
int btn4Anterior;
//


// -> Variables to use in press event. One press (set 1) another press (set -1). Starts with nothing pressed
int btn1Ativo = -1;
int btn2Ativo = -1;
int btn3Ativo = -1;
int btn4Ativo = -1;
//


// -> Variables to store time after press buton and compare after with global time
unsigned long tempoInicial1 = 0;
unsigned long tempoInicial2 = 0;
unsigned long tempoInicial3 = 0;
unsigned long tempoInicial4 = 0;
//


// -> Settings frequency of led blinks (1000 = 1000ms = 1s)
const long intervalo1 = 1000;
const long intervalo2 = 2000;
const long intervalo3 = 3000;
const long intervalo4 = 4000;
// 

void setup() {

	// -> OUTPUT LEDs.
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);

	// -> INPUT BUTTONS.
	pinMode(btn1, INPUT);
	pinMode(btn2, INPUT);
	pinMode(btn3, INPUT);
	pinMode(btn4, INPUT);

	// -> Start with all LEDs in LOW state
	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
	digitalWrite(led3, LOW);
	digitalWrite(led4, LOW);
}

void loop() {

	// -> Store global time in variable (tempoTotal). Running time after arduino starts.....
	unsigned long tempoTotal = millis();

	// Current State of each button (starts all in LOW state - nothing is pressed)
	btn1Atual = digitalRead(btn1);
	btn2Atual = digitalRead(btn2);
	btn3Atual = digitalRead(btn3);
	btn4Atual = digitalRead(btn4);

  // switch para o botao 1 ------------------------------------------------------

	// -> If actualState is different of previousState of the button, execute! After start all buttons are in
	//	low state... don't execute this step. but after press, actualState is HIGH and previous is LOW and then 
	//	execute this if condition!!
	if (btn1Atual != btn1Anterior){

		// If buttonSate is HIGH, just multiply variable that controls if button was pressed or not. Pressed = 1, not pressed = -1.
		if (digitalRead(btn1) == HIGH){

			btn1Ativo *= -1;

      // --> ELSE to do something on button release if you want.....
		} else {}

	// -> ELSE that execute if states (actual and previous) are the same as in the beggining or after pressed.
	} else {

		// -> If it was the first press (==1), second press (==-1)
		if (btn1Ativo == 1){

			// -> first press, need to calculate time and verify if 1 second passed after press. It's simple... just take tempoTotal (global time running)
			//	minus tempoInicial (time get after press. Start = 0) and verify if it is >= interval (frequency). If it is, change led STATE. If not, don't
			//	execute. go to else that do nothing.
			if (tempoTotal - tempoInicial1 >= intervalo1){

				// Update variable after satisfy condition of 1 second. Partial time = global time and start checking again......
				
				tempoInicial1 = tempoTotal;

				// change led state
				digitalWrite(led1, !digitalRead(led1));

			// -> ELSE do something while is checking 1s... I didn't code anything... you can add a buzzer scale... hehe :)
			} else {}

		// -> ELSE if is the 2nd press... one press turn on blink, 2nd, turn off!!
		} else {
			digitalWrite(led1, LOW);
		}
	} 

	// Update button state (actual and previous)
	btn1Anterior = btn1Atual;

    // same code to button 2..........................................................................
	if (btn2Atual != btn2Anterior){

		if (digitalRead(btn2) == HIGH){

			btn2Ativo *= -1;

      
		} else {}
	} else {

		if (btn2Ativo == 1){


			if (tempoTotal - tempoInicial2 >= intervalo2){
				tempoInicial2 = tempoTotal;
				digitalWrite(led2, !digitalRead(led2));
			} else {}

		} else {
			digitalWrite(led2, LOW);
		}
	}
	btn2Anterior = btn2Atual;

    // same code to button 3..........................................................................

	if (btn3Atual != btn3Anterior){

		if (digitalRead(btn3) == HIGH){

			btn3Ativo *= -1;

		} else {}
	} else {

		if (btn3Ativo == 1){


			if (tempoTotal - tempoInicial3 >= intervalo3){
				tempoInicial3 = tempoTotal;
				digitalWrite(led3, !digitalRead(led3));
			} else {}

		} else {
			digitalWrite(led3, LOW);
		}
	}
	btn3Anterior = btn3Atual;

    // same code to button 4..........................................................................

	if (btn4Atual != btn4Anterior){

		if (digitalRead(btn4) == HIGH){

			btn4Ativo *= -1;

		} else {}
	} else {

		if (btn4Ativo == 1){


			if (tempoTotal - tempoInicial4 >= intervalo4){
				tempoInicial4 = tempoTotal;
				digitalWrite(led4, !digitalRead(led4));
			} else {
			}

		} else {
			digitalWrite(led4, LOW);
		}
	}
	btn4Anterior = btn4Atual;

}