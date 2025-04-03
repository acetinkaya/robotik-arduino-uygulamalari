/*
  İGÜ MYO Robotik 1. Led Yak ve Söndür uygulaması
  Ekip İsmi:
  ...

  https://github.com/acetinkaya/robotik-arduino-uygulamalari
*/
int led_pin = 13;

void setup() 
{
  pinMode(led_pin, OUTPUT);
}

void loop() 
{
  digitalWrite(led_pin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(100);                      // wait for a second
  digitalWrite(led_pin, LOW);   // turn the LED off by making the voltage LOW
  delay(500);                      // wait for a second
}
