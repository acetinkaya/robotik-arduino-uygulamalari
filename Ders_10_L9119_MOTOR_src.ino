const int analogPin = A0;
const int motorPin = 12;        // L9110 A-IA (PWM çıkışı)
const int motorDirPin = 13;     // L9110 A-IB (motor yönü için sabit LOW verilecek)
const int rolePin = 7;          // Röle çıkışı
const int ledPin = 5;           // PWM çıkışı (LED)

int okunanDeger = 0;
int pwmDegeri = 0;
int parlaklik = 0;

void setup() {
  pinMode(rolePin, OUTPUT);
  pinMode(motorPin, OUTPUT);
  pinMode(motorDirPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(motorDirPin, LOW);  // Tek yönlü sürüş
  Serial.begin(9600);
}

void loop() 
{
  okunanDeger = analogRead(analogPin);
  pwmDegeri = map(okunanDeger, 0, 1023, 0, 255);
  parlaklik = pwmDegeri;  // LED parlaklığını ayarla

  if (okunanDeger >= 0 && okunanDeger <= 500) 
  {
    digitalWrite(rolePin, LOW);
    analogWrite(ledPin, parlaklik);
    digitalWrite(motorPin, HIGH); // Motor hızı
    digitalWrite(motorDirPin, LOW); // Motor hızı
    delay(100);
  } 
  else if (okunanDeger >= 501 && okunanDeger <= 1023) 

  {
    analogWrite(ledPin, parlaklik);
    digitalWrite(motorPin, LOW); // Motor hızı
    digitalWrite(motorDirPin, HIGH); // Motor hızı
    digitalWrite(rolePin, HIGH);
    delay(100);
  }
  else
  {
    analogWrite(ledPin, LOW);
    digitalWrite(motorPin, LOW); // Motor hızı
    digitalWrite(motorDirPin, LOW); // Motor hızı
    digitalWrite(rolePin, LOW);
    delay(100);
  }

  Serial.print("Potansiyometre: ");
  Serial.print(okunanDeger);
  Serial.print(" | PWM: ");
  Serial.println(pwmDegeri);

  delay(100);
}