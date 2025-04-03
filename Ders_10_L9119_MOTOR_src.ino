/*
Bu kodlar açık kaynak paylaşım olarak github "acetinkaya" alanında paylaşımı yapılmıştır. 

BTP222 Robotik dersi içerisinde anlatımı yapılan bu kodlar ve içerikler Öğr. Gör. Ali ÇETİNKAYA tarafından oluşturulmuştur. 

Github alanından; 
watch - ilgili projenin proje takibi bildirimi, 
star - yıldız ile beğenme bildirimi ve 
fork - kendi hesabınıza kopyalama işlemleriyle paylaşımlarıma destek verebilirsiniz. 

Bilgi paylaşıldıkça çoğalır ve gelişir. İyi çalışmalar dilerim.

Öğr. Gör. Ali ÇETİNKAYA İstanbul, 2025

Dersin Kaynak Adresleri:
https://github.com/acetinkaya/robotik-arduino-uygulamalari
https://alicetinkaya.site/ders-robotik
https://avesis.gelisim.edu.tr/alcetinkaya 
https://scholar.google.com.tr/citations?hl=tr&user=XSEW-NcAAAAJ

---------------------------------------------------------------------------------------------------------
Kodun açıklaması: 

Arduino üzerinde pottan alınan degere göre L9119 ile DC motor sürme uygulamasıdır. 

*/


const int analogPin = A0;     // Potansiyometre orta bacak
const int motorPin = 5;       // L9110 A-IA (PWM çıkışı)
const int motorDirPin = 6;    // L9110 A-IB (motor yönü için sabit LOW verilecek)

int okunanDeger = 0;          // 0-1023
int pwmDegeri = 0;            // 0-255

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(motorDirPin, OUTPUT);
  digitalWrite(motorDirPin, LOW);  // Tek yönlü sürüş için sabit düşük
  Serial.begin(9600);
}

void loop() {
  okunanDeger = analogRead(analogPin);
  pwmDegeri = map(okunanDeger, 0, 1023, 0, 255); // PWM aralığına ölçekle

  analogWrite(motorPin, pwmDegeri); // Motor hızı ayarlanır

  Serial.print("Potansiyometre: ");
  Serial.print(okunanDeger);
  Serial.print(" | PWM: ");
  Serial.println(pwmDegeri);

  delay(100);
}