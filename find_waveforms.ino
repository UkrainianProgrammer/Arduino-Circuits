

float sinWave, squareWave, triangleWave;
float samples[300];

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  
}

// the loop routine runs over and over again forever:
void loop() {
  
  float sum = 0;
  float rms = 0;
  // read the input on analog pin 0:
  for(int i = 0; i <= 299; i++){
    int sensorValue = analogRead(A0);
    float voltage = sensorValue * (5.0 / 1023.0);
    samples[i] = voltage;
    //Serial.println(voltage);
    //calculate the sum of squares
    sum = sum + pow(samples[i], 2);

    //Serial.print("Sum equals: ");
    //Serial.println(sum);
  }

  //float temp = 0;
  float amplitude = 0;
  for(int i = 0; i <= 299; i++){
    if(samples[i] > amplitude){
      amplitude = samples[i];
    }  
  }
  
  Serial.print("Amplitude is: ");
  Serial.println(amplitude);
  
  rms = sqrt((1.0/300) * 2.0 * sum);
  Serial.print("RMS is: ");
  Serial.println(rms);
  //Serial.print("RMS is: ");
  //Serial.println(rms);
  sinWave = amplitude/sqrt(2);
  squareWave = amplitude;
  triangleWave = amplitude/sqrt(3);

  float sinDiff = abs(rms - sinWave);
  //Serial.print("sinDiff is: ");
  Serial.println(sinDiff);
  float squareDiff = abs(rms - squareWave);
  //Serial.print("squareDiff is: ");
  Serial.println(squareDiff);
  float triangleDiff = abs(rms - triangleWave);
  //Serial.print("triangleDiff is: ");
  Serial.println(triangleDiff);

  if((sinDiff < squareDiff) and (sinDiff < triangleDiff)){
    Serial.println("Sin Wave");
  }
  if((squareDiff < sinDiff) and (squareDiff < triangleDiff)){
    Serial.println("Square Wave");
  }
  if((triangleDiff < sinDiff) and (triangleDiff < squareDiff)){
    Serial.println("Triangle Wave");
  }
  delay(1000);
}
