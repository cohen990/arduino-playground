/*
  AnalogReadSerial
  
  Attach the input of a button to 5V
  Attach the output of that button to A0
  
  Attach the input of an LED to 13
  Attach the output of that LED to GND
 This example code is in the public domain.
 */
int currentOne= 0;
int oneBefore = 0;
int twoBefore = 0;

int sequenceOn[4]= {13, 12, 11, 12};
int sequenceOff[4] = {12, 13, 12, 11};
int currentStep = 0;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  
  twoBefore = oneBefore;
  oneBefore = currentOne;
  currentOne = sensorValue;
  
  int movingAverage = (currentOne + oneBefore + twoBefore)/3;
  
  if(movingAverage >= 1000){
    Serial.print("Executing step: ");
    Serial.println(currentStep);
    // print out the value you read:
    digitalWrite(sequenceOn[currentStep], HIGH);
    digitalWrite(sequenceOff[currentStep], LOW);
    
    currentStep++;
    
    if(currentStep >= sizeof(sequenceOn)){
      currentStep = 0;
    }
    
    delay(50);
  }
  else{
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
  }
  delay(1);        // delay in between reads for stability
}
