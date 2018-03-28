const int buttonPin = 2;
int buttonState;
int lastButtonState = LOW;
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 5000;    // the debounce time; increase if the output flickers
int melody[10] = {0};
int conter = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead (buttonPin);
  int sensorValue = analogRead(A2); //spin
  int thisPitch = map(sensorValue, 400, 1000, 120, 1500);
  if (buttonState != lastButtonState) {
    if(buttonState == 0){
        lastDebounceTime = millis();
        if(conter<10){
            
             melody[conter]=analogRead(A2);
             Serial.println(melody[conter]);
             conter++;
      }
  }
    
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    Serial.println("asdas");
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:
   while(1){
     for(int i = 0; i < conter ; i++){
      tone(8, melody[i], 20);
    }
   }

  }
  lastButtonState = buttonState;
  
  delay(100);

}
