#include <dht.h>
#define dht_dpin A0 //Set equal to channel sensor is on
dht DHT;
#define echoPin 7 // Echo Pin
#define trigPin 8 // Trigger Pin
#define LEDPin 13 // Onboard LED
int maximumRange = 200; // Maximum range needed
int minimumRange = 0; // Minimum range needed
long duration, distance; // Duration used to calculate distance

void setup() {
    Serial.begin (9600);
    
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(LEDPin, OUTPUT); // Use LED indicator (if required)
    
    delay(300); //Let system settle
    Serial.println("Humidity and temperature\n\n");
    delay(700); //Wait rest of 1000ms recommended delay before
    //accessing sensor
}
void loop() {
    /* The following trigPin/echoPin cycle is used to determine the
    distance of the nearest object by bouncing soundwaves off of it. */
    float speed;
    speed = 331.3 + 0.606*DHT.temperature;
    Serial.println("spped:");
    Serial.println(speed);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    //Calculate the distance (in cm) based on the speed of sound.
    int x;
    x = 10000 / speed;
    x = x*2;
    distance = duration/x;
    if (distance >= maximumRange || distance <= minimumRange){
        /* Send a negative number to computer and Turn LED ON to indicate "out of range"*/
        Serial.println("-1");
        digitalWrite(LEDPin, HIGH);
    }
    else {
        /* Send the distance to the computer using Serial protocol, and turn LED OFF to indicate successful reading. */
        Serial.println("distance:");
        Serial.println(distance);
        digitalWrite(LEDPin, LOW);
        if(distance>=30 && distance<=100){
            tone(10,300,50);
            delay(500);
            tone(10,300,50);
            delay(500);
        }
        else if(distance<30){
            tone(10,300,50);
            delay(250);
            tone(10,300,50);
            delay(250);
            tone(10,300,50);
            delay(250);
            tone(10,300,50);
            delay(250);
        }
      }
    //Delay 50ms before next reading.
    delay(1);
}


/*void loop(){
    DHT.read11(dht_dpin);
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("% ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("C ");
    delay(1000); //data update period
   
}*/
