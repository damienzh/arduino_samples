// test code for Grove - Sound Sensor
// loovee @ 2016-8-30
#include <Grove_LED_Bar.h>
const int pinAdc = A0;
Grove_LED_Bar bar(9, 8, 0, LED_BAR_10);
void setup()
{
    Serial.begin(9600);
    //Serial.println("Grove - Sound Sensor Test...");
    bar.begin();
}

void loop()
{
    long sum = 0;
    for(int i=0; i<32; i++)
    {
        sum += analogRead(pinAdc);
    }

    sum >>= 5;

    Serial.println(sum);
    sum = map(sum, 0, 255, 0, 10);
    bar.setLevel(sum);
    delay(10);
}
