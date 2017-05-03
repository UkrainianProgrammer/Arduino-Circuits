int buttonPin = 2;
boolean buttonState = LOW;
int motorPin1 = 10;
int motorPin2 = 11;
int motorEnabled = 0;
boolean previousButtonState = LOW;


void setup() {
  pinMode(buttonPin,INPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
   if(previousButtonState != buttonState && buttonState == HIGH){
    motorEnabled = !motorEnabled;
    }
  if(motorEnabled == 1){
    delay(500);
    digitalWrite(motorPin2, LOW);
    delay(500);
    digitalWrite (motorPin1,HIGH);
    }
  else{
    delay(500);
    digitalWrite (motorPin1,LOW);
    delay(500);
    digitalWrite(motorPin2, HIGH);
    }
  previousButtonState = buttonState;
}


