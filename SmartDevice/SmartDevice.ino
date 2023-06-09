// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// Servo
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
// SD Card - Confirm Pin
#define SDpin 10
// Traffic Lights - LED Outputs
#define ledRed A0
#define ledYellow A1
#define ledGreen A2
//dc motor DFRobot
int E1 = 6;
int M1 = 7;
// Servo
#include <Servo.h>
Servo myservo;
//Potentiometer
#define pot A3
// Piezo Buzzer
#define piezoPin 8
// Sonar - HC-SR04
#define echoPin 6 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin A4 //attach pin D3 Arduino to pin Trig of HC-SR04
// Line Sensor
#define lineSensorPin 3
// Crash Sensor / Button
#define crashSensor 7

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }
/*
  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1);
    */
  }

  // Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");
}


void loop() {
  // put your main code here, to run repeatedly:
  temperatureControl();
  delay(250);
  lightControl();
  delay(250);
  doorbell();
  delay(250);
  doorControl();
}
/*
  controls the temperature in the house
  @params none
  @return pirValue
*/
void temperatureControl() { /*air conditioning*/
  int pirValue = digitalRead(pirSensor);
  digitalWrite(pirValue);
  if (pirValue == HIGH)
    int speedValue = 255; // Can be 0-255.
  digitalWrite(M1, HIGH);
  analogWrite(E1, speedValue);   //PWM Speed Control
/*
 read pirValue
 if true
 output to Servo motor(pin 9)
 else
 output notone to pin 9
 */
}
/*
  controls the light in the house
  @params none
  @return lineSensorValue
*/
void lightControl
int lineSensorValue = digitalRead(lineSensorPin);
if (lineSensorValue == HIGH) {
  int potValue = analogRead(pot);// reads the value of the potentiometer (value between 0 and 1023)
}
digitalWrite(ledYellow, HIGH);
} else {
  digitalWrite(ledYellow, LOW);
  /*
   read lineSensorValue
   if true
   output to ledYellow(pin A1)
   else
   output notone to A1
   
   */
}
/*
  doorbell (ringing noise when crash button pressed)
  @params none
  @return crashSensorValue
*/
void doorbell() {
  int crashSensorValue = digitalRead(crashSensor);
  tone(piezoPin, 1000); // Send 1KHz sound signal...
  delay(100);
  noTone(piezoPin);
  /*
   read crash sensor value
   if true
   output to piezo(pin 3)
   else
   output notone to pin 3
   */
}


/*
  locks the door when certain distance reached (unless turned off)
  @params none
  @return none
*/
void doorControl() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  int distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)
  // Servo position values range from 0-180
  int servoPos = 100;
  myservo.write(servoPos);
  /*
   read SonarSensor Value
   if true
   output to DC motor(pin 6)
   else
   output notone to pin 6
   */
}
