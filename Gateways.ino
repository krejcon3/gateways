int timeInMilis = 0;
boolean isRunning = false;
int timeStep = 10;

void setup() {
  Serial.begin(9600);
}

void loop() {
  delay(timeStep);
  if (isRunning) {
    timeInMilis += timeStep;
  }
}

void serialEvent() {
  while (Serial.available()) {
    char inChar = (char)Serial.read();
    if (inChar == '\n' || inChar == '\r') {
      if (isRunning) {
        printMilis();        
        timeInMilis = 0;
        isRunning = false;    
      } else {
        Serial.println(">>>>>> START <<<<<<");
        isRunning = true;            
      }
    }
  }
}

void printMilis() {
  int seconds = timeInMilis / 1000;
  int milis = timeInMilis % 1000;
  Serial.print("----- ");
  Serial.print(seconds);
  Serial.print(".");
  Serial.print(milis);
  Serial.print("s -----");
  Serial.println();
  Serial.println(">>>>>> STOP <<<<<<");
  Serial.println();
  Serial.println();
  Serial.println();
}


