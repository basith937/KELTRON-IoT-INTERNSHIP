#define START_BUTTON 2   
#define STOP_BUTTON 3    
#define RELAY_PIN    8   

bool isSystemRunning = false;

void setup() {
  pinMode(START_BUTTON, INPUT_PULLUP);
  pinMode(STOP_BUTTON, INPUT_PULLUP);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  bool startPressed = (digitalRead(START_BUTTON) == LOW);
  bool stopPressed  = (digitalRead(STOP_BUTTON) == LOW);

  if (startPressed) {
    isSystemRunning = true;
  }

  if (stopPressed) {
    isSystemRunning = false;
  }

  if (isSystemRunning) {
    digitalWrite(RELAY_PIN, HIGH);
  } else {
    digitalWrite(RELAY_PIN, LOW);
  }

  delay(100);
}



