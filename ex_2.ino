/*
São 4 chaves e 4 leds
Pressionando o btn1 o led1 pisca com frequência de 1s
Pressionando o btn2 o led1 pisca com frequência de 2s
Pressionando o btn3 o led1 pisca com frequência de 3s
Pressionando o btn4 o led1 pisca com frequência de 4s
*/

// -> Setar os pinos dos Botoes e dos Leds.
int btn1 = 2;
int btn2 = 3;
int btn3 = 4;
int btn4 = 5;

int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
// -> final da configuração dos pinos (Botões e Leds).


// -> Definir as variáveis que vão captar os estados dos botões.
//    Estado atual e estado anterior para verificar se houve mudança de estado.
//    Por exemplo de HIGH para LOW.
int btn1Atual;
int btn1Anterior;

int btn2Atual;
int btn2Anterior;

int btn3Atual;
int btn3Anterior;

int btn4Atual;
int btn4Anterior;
// -> final da configuração das variáveis que captam os estados dos botões.


// -> Variáveis para cada botão que irá definir se o botão está ATIVO (foi clicado a primeira vez) 
//	  E quando clicado a segunda vez. Clicou a primeira vez (1) clicou a segunda (-1).
int btn1Ativo = -1;
int btn2Ativo = -1;
int btn3Ativo = -1;
int btn4Ativo = -1;
// -> Final.


// -> Configuração das variáveis que irão contar o tempo decorrente de cada botão.
unsigned long tempoInicial1 = 0;
unsigned long tempoInicial2 = 0;
unsigned long tempoInicial3 = 0;
unsigned long tempoInicial4 = 0;
// -> Final.


// -> Definição das variáveis que marcarão o tempo do blink dos LEDs
const long intervalo1 = 1000;
const long intervalo2 = 2000;
const long intervalo3 = 3000;
const long intervalo4 = 4000;
// -> Final.

// -> Uma variável que criei para um possível delay() do equipamento...
unsigned long erro = 50;
// -> Final.


void setup() {
	Serial.begin(4800);

	// -> Setar saída para os LEDs.
	pinMode(led1, OUTPUT);
	pinMode(led2, OUTPUT);
	pinMode(led3, OUTPUT);
	pinMode(led4, OUTPUT);

	// -> Setar INPUT para os botões.
	pinMode(btn1, INPUT);
	pinMode(btn2, INPUT);
	pinMode(btn3, INPUT);
	pinMode(btn4, INPUT);

	// -> Iniciar com todos os LEDs desligados.
	digitalWrite(led1, LOW);
	digitalWrite(led2, LOW);
	digitalWrite(led3, LOW);
	digitalWrite(led4, LOW);
}

void loop() {

	// -> Pega o tempo total desde q o Arduino foi ligado.
	unsigned long tempoTotal = millis();

	// Registra nas variáveis o estado de todos os botões, que estará LOW. Não estarão pressionados (5V) 
	//      neste exemplo em que foram montados em pull-down (5V pressionado e 0V sem estar pressionao).
	//      no pull-up fica invertido (ao pressionar = 0V, solto = 5V).
	btn1Atual = digitalRead(btn1);
	btn2Atual = digitalRead(btn2);
	btn3Atual = digitalRead(btn3);
	btn4Atual = digitalRead(btn4);

  // switch para o botao 1 ------------------------------------------------------

	// -> Condição executada caso o estado do botão mude. Estava LOW e foi clicado, ou seja virou HIGH.
	//		No momento que clicou, o btnAtual passou a ser HIGH e o anterior ficou LOW. Ai entra nesse IF.
	if (btn1Atual != btn1Anterior){

		// Se a condição mudou e o botão está pressionado (HIGH), ele simplismente troca o valor da variável btnAtivo
		//	multiplicando ela por -1. Estava -1 originalmente e passou a ser 1, ou seja CLICOU. Quando for clicado novamente
		//	será multiplicado por -1 e então voltará a ser -1 e assim por diante. Vai alternar entre -1 (não clicado) e 
		//	1 (clicado).
		if (digitalRead(btn1) == HIGH){

			btn1Ativo *= -1;

      // --> esse ELSE é para alguma ação quando soltar o botão (RELEASE). Não fiz nada para isso.
		} else {}

	// -> Esse ELSE entra para quando as condições dos botões forem iguais. Por exemplo. Ao iniciar tava LOW para btnAtual e btnAnterior. 
	//	Quado clicamos ficou HIGH para a atual e LOW para a anterior e executou a rotina acima, mas logo que soltamos o botão após o clique
	//	Ficou HIGH para as duas e então não executa a de cima mas executa a que vem a seguir!	
	} else {

		// -> Se a condição dos botões for igual (HIGH e HIGH) ou (LOW e LOW). Vai verificar o estado do botão: Se foi clicado a 
		//	primeira vez (1) ou clicado pela segunda vez (-1).
		if (btn1Ativo == 1){

			// -> Se clicou pela primeira vez, irá pegar o tempo total que o Arduino tá ligado e subtrair do tempo que decorreu quando
			//	clicamos (que começa com 0). Se o resultado for igual ou maior que o nosso intervalo, ele troca o estado do LED. De
			//	aceso para apagado ou de apagado para aceso.
			if (tempoTotal - tempoInicial1 >= intervalo1 + erro){

				// Logo que verifica que o tempo total - tempo decorrido já deu o intervalo,
				//	ele atualiza a variável tempoInicial. Para começar a contar novamente.
				tempoInicial1 = tempoTotal;

				// troca o estado do LED. De aceso para apagado ou de apagado para aceso.
				digitalWrite(led1, !digitalRead(led1));
			// -> Esse else é apenas para o intervalo que ainda não deu o 1 segundo (neste caso). Até chegar ao intervalo ele não
			//	executa nada.
			} else {}

		// -> Esse ELSE é se a condição do botão não for 1, ou seja, foi clicado pela segunda vez (-1), que entáo terá que desligar o LED. 
		} else {
			digitalWrite(led1, LOW);
		}
	} // final do ELSE para quando os estados dos botões forem iguais (HIGH com HIGH) ou (LOW com LOW).

	// -> Atualiza o estado do botão. O estado anterior passa a ser o atual. Por isso que ao inciar, os dois estão LOW,
	//	Mas quando clicamos a primeira vez, o atual fica HIGH, ele faz toda a rotina para quando o estaado é diferente (btn1Atual != btn1Anterior)
	//	E ao chegar aqui, já soltamos o botão depois do clique (RELEASE) e os estados são atualizados, os dois ficam HIGH e é executada a outra rotina
	// Que é ligar ou apagar os LEDS.
	btn1Anterior = btn1Atual;

    // switch para o botao 2 ------------------------------------------------------
	if (btn2Atual != btn2Anterior){

		if (digitalRead(btn2) == HIGH){

			btn2Ativo *= -1;

      // alguma açao para o release do btn2 
		} else {}
	} else {

		if (btn2Ativo == 1){


			if (tempoTotal - tempoInicial2 >= intervalo2 + erro){
				tempoInicial2 = tempoTotal;
				digitalWrite(led2, !digitalRead(led2));
			} else {}

		} else {
			digitalWrite(led2, LOW);
		}
	}
	btn2Anterior = btn2Atual;

    // switch para o botao 3 ------------------------------------------------------
	if (btn3Atual != btn3Anterior){

		if (digitalRead(btn3) == HIGH){

			btn3Ativo *= -1;

      // alguma açao para o release do btn3 
		} else {}
	} else {

		if (btn3Ativo == 1){


			if (tempoTotal - tempoInicial3 >= intervalo3 + erro){
				tempoInicial3 = tempoTotal;
				digitalWrite(led3, !digitalRead(led3));
			} else {}

		} else {
			digitalWrite(led3, LOW);
		}
	}
	btn3Anterior = btn3Atual;

    // switch para o botao 4
	if (btn4Atual != btn4Anterior){

		if (digitalRead(btn4) == HIGH){

			btn4Ativo *= -1;

      // alguma açao para o release do btn4 ------------------------------------------------------
		} else {}
	} else {

		if (btn4Ativo == 1){


			if (tempoTotal - tempoInicial4 >= intervalo4 + erro){
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