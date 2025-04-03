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

Arduino Nano üzerinde bağlı seri porttan led sürme işlemini gerçekleştiriyoruz. 

*/

int led_pin = 13;

void setup() 
{
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600); // Seri haberleşmeyi başlat (baud rate: 9600)
}

void loop() 
{
  if (Serial.available() > 0) // Seri porttan veri al
  {
    char receivedChar = Serial.read();

    if (receivedChar == 'H')  // Alınan karakter 'H' ise Seri port ekranına H Bilgisi Geldi yaz
    {
      Serial.println("H Bilgisi Geldi");
      digitalWrite(led_pin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(1000); // 1000 milisaniye (1 saniye) bekle
    }
    else if (receivedChar == 'L') // Alınan karakter 'L' ise Seri port ekranına L Bilgisi Geldi yaz
    {
      Serial.println("L Bilgisi Geldi");
      digitalWrite(led_pin, LOW);   // turn the LED off by making the voltage LOW
      delay(1000); // 1000 milisaniye (1 saniye) bekle
    }
  }
}