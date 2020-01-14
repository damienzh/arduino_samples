/* How to use a Force sensitive resistor to fade an LED with Arduino
   More info: http://www.ardumotive.com/how-to-use-a-force-sensitive-resistor-en.html
   Dev: Michalis Vasilakis // Date: 22/9/2015 // www.ardumotive.com  */

//Constants:
// const int ledPin = 3;     //pin 3 has PWM funtion
#include <Grove_LED_Bar.h>

const int sensorPin = 14; //pin A0 to read analog input
Grove_LED_Bar bar(9, 8, 0, LED_BAR_10);

//Variables:
int value; //save analog value

void setup(){

  // pinMode(ledPin, OUTPUT);  //Set pin 3 as 'output'
  bar.begin();
  Serial.begin(9600);       //Begin serial communication

}

void loop(){

  value = analogRead(sensorPin);       //Read and save analog value from potentiometer
  Serial.println(value);               //Print value
  value = map(value, 0, 1023, 0, 10); //Map value 0-1023 to 0-255 (PWM)
  //analogWrite(ledPin,255-value);          //Send PWM value to led
  bar.setLevel(value);
  delay(100);                          //Small delay

}
