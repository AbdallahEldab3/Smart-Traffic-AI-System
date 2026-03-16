#define GREEN1_PIN 5
#define RED1_PIN 4
#define GREEN2_PIN 15
#define RED2_PIN 19
#define Yellow1_pin 23
#define Yellow2_pin 21

char currentCommand = '\0'; 
char nextCommand = '\0';    
unsigned long phaseStart = 0;
uint8_t currentPhase = 0;
bool isTransitioning = false;

void allOff() {
  digitalWrite(GREEN1_PIN, LOW);
  digitalWrite(RED1_PIN, LOW);
  digitalWrite(GREEN2_PIN, LOW);
  digitalWrite(RED2_PIN, LOW);
  digitalWrite(Yellow1_pin, LOW);
  digitalWrite(Yellow2_pin, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(GREEN1_PIN, OUTPUT);
  pinMode(RED1_PIN, OUTPUT);
  pinMode(GREEN2_PIN, OUTPUT);
  pinMode(RED2_PIN, OUTPUT);
  pinMode(Yellow1_pin, OUTPUT);
  pinMode(Yellow2_pin, OUTPUT);
  allOff();
}

void handleCommand(char cmd) {
  if (currentCommand == '\0') {
    currentCommand = cmd;
    phaseStart = millis();
    allOff();
  } else {
    nextCommand = cmd;
    isTransitioning = true;
    phaseStart = millis();
    allOff();
    digitalWrite(Yellow1_pin, HIGH);
    digitalWrite(Yellow2_pin, HIGH);
  }
}

void processPhase() {
  if (currentCommand == '\0') return;

  unsigned long now = millis();
  unsigned long phaseDuration = 0;

  if (isTransitioning) {
    phaseDuration = 5000;
    if (now - phaseStart >= phaseDuration) {
      isTransitioning = false;
      currentCommand = nextCommand;
      nextCommand = '\0';
      currentPhase = 0;
      phaseStart = millis();
      allOff();
    }
    return; 
  }

  switch(currentCommand) {
    case 'z': 
      if (currentPhase == 0) {
        phaseDuration = 20000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 1) {

        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        
        phaseDuration = 10000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 3) {

        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'x':
      if (currentPhase == 0) {
        phaseDuration = 25000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 5000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'c':
      if (currentPhase == 0) {
        phaseDuration = 15000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 15000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'v':
      if (currentPhase == 0) {
        phaseDuration = 20000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 10000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'b':
      if (currentPhase == 0) {
        phaseDuration = 20000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 10000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'n':
      if (currentPhase == 0) {
        phaseDuration = 15000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 15000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'm':
      if (currentPhase == 0) {
        phaseDuration = 25000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 5000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 'a':
      if (currentPhase == 0) {
        phaseDuration = 20000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 10000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    case 's':
      if (currentPhase == 0) {
        phaseDuration = 15000; 
        digitalWrite(GREEN1_PIN, HIGH);
        digitalWrite(RED2_PIN, HIGH);
      } else if (currentPhase == 1) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      } else if (currentPhase == 2) {
        phaseDuration = 15000; 
        digitalWrite(GREEN2_PIN, HIGH);
        digitalWrite(RED1_PIN, HIGH);
      } else if (currentPhase == 3) {
        phaseDuration = 5000; 
        digitalWrite(Yellow1_pin, HIGH);
        digitalWrite(Yellow2_pin, HIGH);
      }
      break;

    default: return;
  }

  if (now - phaseStart >= phaseDuration) {
    currentPhase = (currentPhase + 1) % 4; /
    phaseStart = millis();
    allOff();
  }
}

void loop() {
  if (Serial.available() > 0) {
    char newCmd = Serial.read();
    if (newCmd != '\n') {
      handleCommand(newCmd);
    }
  }

  processPhase();
}
