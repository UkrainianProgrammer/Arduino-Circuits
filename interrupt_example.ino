// constants won't change. Used here to set a pin number :
const byte ledPin1 =  12;// the number of the LED pin
const byte ledPin2 = 13;
const byte interruptPin1 = 2;
const byte interruptPin2 = 3;
// Variables will change :
volatile byte ledState1 = LOW;             // ledState used to set the LED
volatile byte ledState2 = LOW;
// The value will quickly become too large for an int to store
unsigned long previousMillis1 = 0;        // will store last time LED was updated
unsigned long previousMillis2 = 0;
bool led1 = false;
bool led2 = false;
bool reached3sec = false;
// constants won't change :
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(interruptPin1, INPUT);
  pinMode(interruptPin2, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin1), ledButton1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), ledButton2, CHANGE);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.
  if(led1 == true){
    blink1();
    digitalWrite(ledPin1, ledState1);
  }
  else{
    digitalWrite(ledPin1, LOW);
  }

  if(led2 == true){
    blink2();
    digitalWrite(ledPin2, ledState2);
  }
  else{
    digitalWrite(ledPin2, LOW);
  }
  

}

void blink1(){
    // check to see if it's time to blink the LED; that is, if the
  // difference between the current time and last time you blinked
  // the LED is bigger than the interval at which you want to
  // blink the LED.
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis1 >= interval) {
    // save the last time you blinked the LED
    previousMillis1 = currentMillis;

    // if the LED is off turn it on and vice-versa:
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
    
    // set the LED with the ledState of the variable:
    //digitalWrite(ledPin, ledState);
  }
}

void blink2(){
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis2 >= interval * 3 && reached3sec == true) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis;
    ledState2 = LOW;
    reached3sec = false;
  }

  if (currentMillis - previousMillis2 >= interval * 2 && reached3sec == false) {
    // save the last time you blinked the LED
    previousMillis2 = currentMillis;
    ledState2 = HIGH;
    reached3sec = true;
  }
  
}

void ledButton1(){
  led1 = !led1;
}

void ledButton2(){
  led2 = !led2;
}

