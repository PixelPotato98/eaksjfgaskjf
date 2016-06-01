// Oppgave 3 - Lyskryss - Tverrfaglig Eksamen - [31.05.16 - 01.06.16] - Philip Tønnessen

// CONSTANTS:

const int MainRed = 2;      // main road Red LED
const int MainOrange = 3;   // main road Orange LED
const int MainGreen = 4;    // main road Green LED
const int SideRed = 5;      // side-road Red LED
const int SideOrange = 6;   // side-road Orange LED
const int SideGreen = 7;    // side-road Green LED

const int button = A5;      // the pushbutton is attatched to pin A5

// constants                      


// VARIABLES:

int buttonState = 0;        // a variable used to store state of our button
int waitDelay = 15000;      // the opened road should stay open for at least 15 seconds
int greenRedDelay = 3000;   // in the transition from green to red, the orange led should light for 3 seconds (3000ms)
int redGreenDelay = 1000;   // in the transition from red to green, the orange led should light for 3 seconds (1000ms)
int safetyDelay = 4000;     // a safety delay used for startup (both the system and the time it takes for the lights to switch)
                            // - and clearing the junction before the lights turn green.
int lightLoop = 1;         
// variables

// SETUP:
void setup() {
  
  pinMode(SideRed, OUTPUT);
  pinMode(SideOrange, OUTPUT);
  pinMode(SideGreen, OUTPUT);
  pinMode(MainRed, OUTPUT);
  pinMode(MainOrange, OUTPUT);
  pinMode(MainGreen, OUTPUT);
  
  pinMode(button, INPUT);      
                                          
} // setup

// FUNCTIONS

// MAIN PROGRAM:
void loop() {                               
                                             
  if (lightLoop == 1) {                      // when the system starts up, or if the system resets, the light in the main road will be red,
                                             // - until it transitions to orange,then green (default position).
                                            
    digitalWrite(SideRed, HIGH);
    digitalWrite(MainRed, HIGH);
    delay(safetyDelay);                      // to make sure that all of the cars are clear from the junction, we wait 4 seconds until the lights turn green in the main road.
    digitalWrite(MainOrange, HIGH);
    delay(redGreenDelay);                    // when lights go from red to green, the orange light should stay on for 1 second (1000ms).
    digitalWrite(MainRed, LOW);
    digitalWrite(MainOrange, LOW);       
    digitalWrite(MainGreen, HIGH);
    delay(waitDelay);                        // the main road should stay open in the junction for at least 15 seconds, so we use a delay of 15000ms.
    lightLoop = 0;   
  }

  buttonState = digitalRead(button);         // checking the state of the button using digitalRead
  
  if (buttonState == HIGH) {                 // if the button is pressed (HIGH), do the following
    delay(safetyDelay);                      // a delay of 3 seconds (3000ms) to not make the lights switch instantly
    digitalWrite(MainGreen, LOW);            // turning off the green LED at the main road (which is turned on by default)
    digitalWrite(MainOrange, HIGH);          
    delay(greenRedDelay);                    // when lights go from green to red, the orange light should stay on for 3 seconds (3000ms)
    digitalWrite(MainOrange, LOW);           
    digitalWrite(MainRed, HIGH);
    delay(safetyDelay);                      // to make sure that all of the cars are clear from the junction, we wait 4 seconds until the lights turn green in the side-road
    digitalWrite(SideOrange, HIGH);
    delay(redGreenDelay);                    // when lights go from red to green, the orange light should stay on for 1 second (1000ms)
    digitalWrite(SideRed, LOW);
    digitalWrite(SideOrange, LOW);
    digitalWrite(SideGreen, HIGH);
    delay(waitDelay);                        // the side-road should stay open in the junction for at least 15 seconds, so we use a delay of 15000ms.
    digitalWrite(SideGreen, LOW);
    digitalWrite(SideOrange, HIGH);
    delay(greenRedDelay);                    // when lights go from green to red, the orange light should stay on for 3 seconds (3000ms)
    digitalWrite(SideOrange, LOW);
    digitalWrite(SideRed, HIGH);
    delay(safetyDelay);                      // to make sure that all of the cars are clear from the junction, we wait 4 seconds until the lights turn green in the main road
    digitalWrite(MainOrange, HIGH);
    delay(redGreenDelay);                    // when lights go from red to green, the orange light should stay on for 1 second (1000ms)
    digitalWrite(MainRed, LOW);
    digitalWrite(MainOrange, LOW);       
    digitalWrite(MainGreen, HIGH);       
    delay(waitDelay);                        // the main road should stay open in the junction for at least 15 seconds, so we use a delay of 15000ms.
  }
  else {
      digitalWrite(MainGreen, HIGH);         // if no traffic is waiting at the side road, the main road will be open (green lights)
      digitalWrite(SideRed, HIGH);           // the sideroad will be closed (red light)
  }
} // main program
