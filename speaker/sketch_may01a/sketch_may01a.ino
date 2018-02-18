#include <math.h>

const int historyToKeep = 40;
int historicalInputs [historyToKeep] = {};

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < historyToKeep; i++){
    historicalInputs[i] = 0;
  }
}

void loop() {
  int in = analogRead(A0);
  
  for(int i = historyToKeep-1; i > 0; i--)
  {
    historicalInputs[i] = historicalInputs[i-1];
  }
  
  historicalInputs[0] = in;
  
  int sum = 0;
  for(int i = 0; i < historyToKeep; i++)
  {
    sum += historicalInputs[i];
  }
  
  int average = sum/historyToKeep;
  Serial.println(average);
  
  tone(13, average * 20);
}

