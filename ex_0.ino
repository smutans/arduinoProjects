
int buttonPin = 2;// switch is connected to pin 2
int ledPin = 13;
int previousState;                        // variable for reading the pin status
int actualState;                // variable to hold the last button state

void setup() {
  pinMode(buttonPin, INPUT);    // Set the switch pin as input
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);           // Set up serial communication at 9600bps
  previousState = digitalRead(buttonPin);   // read the initial state
}


void loop(){
  actualState = digitalRead(buttonPin);      // read input value and store it in veriable

  if (actualState != previousState) {          // the button state has changed!
    if (actualState == HIGH) {                // check if the button is pressed
      Serial.println("Button just pressed");
      
      digitalWrite(ledPin, !digitalRead(ledPin)); // Write the oposite state of LED

     } else {                         // the button is -not- pressed...
      Serial.println("Button just released");
    }
  }

  previousState = actualState;                 // save the new state in our variable
}