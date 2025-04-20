/*
Bu kodlar açık kaynak paylaşım olarak github "acetinkaya" alanında paylaşımı yapılmıştır. 

BTP222 Robotik dersi içerisinde anlatımı yapılan bu kodlar ve içerikler Öğr. Gör. Ali ÇETİNKAYA tarafından oluşturulmuştur. 

Github alanından; 
watch - ilgili projenin proje takibi bildirimi, 
star - yıldız ile beğenme bildirimi ve 
fork - kendi hesabınıza kopyalama işlemleriyle paylaşımlarıma destek verebilirsiniz. 

Bilgi paylaşıldıkça çoğalır ve gelişir. İyi çalışmalar dilerim.

Öğr. Gör. Ali ÇETİNKAYA İstanbul, 2024

Dersin Kaynak Adresleri:
https://github.com/acetinkaya/robotik-arduino-uygulamalari
https://alicetinkaya.site/ders-robotik
https://avesis.gelisim.edu.tr/alcetinkaya 
https://scholar.google.com.tr/citations?hl=tr&user=XSEW-NcAAAAJ

---------------------------------------------------------------------------------------------------------
Kodun açıklaması: 

Arduino üzerinde dc motor sürücü çalıştırması 

*/

const int motorPin = 12;        // L9110 A-IA (PWM çıkışı)
const int motorDirPin = 13;     // L9110 A-IB (motor yönü için sabit LOW verilecek)

void setup() 
{
  pinMode(motorPin, OUTPUT);
  pinMode(motorDirPin, OUTPUT);
  digitalWrite(motorDirPin, LOW); // Motor hızı
  digitalWrite(motorPin, LOW); // Motor hızı
  Serial.begin(9600);
  delay(100);
}

void loop() 
{
  digitalWrite(motorPin, HIGH); // Motor hızı
  digitalWrite(motorDirPin, LOW); // Motor hızı
  delay(2000);

  digitalWrite(motorPin, LOW); // Motor hızı
  digitalWrite(motorDirPin, HIGH); // Motor hızı
  delay(2000);
}
