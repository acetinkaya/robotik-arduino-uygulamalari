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
*/
const int ledPin = 13; // LED pini

void setup() 
{
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarlandı
  Serial.begin(9600); // Seri haberleşmeyi başlat (baud rate: 9600)
}

void loop() 
{
  // Seri porttan veri al
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    
    // Alınan karakter 'H' ise LED'i yak
    if (receivedChar == 'H') 
    {
      Serial.println("LED açık");
      digitalWrite(ledPin, HIGH); // LED'i yak
      delay(1000); // 1000 milisaniye (1 saniye) bekle
    }
    // Alınan karakter 'L' ise LED'i söndür
    else if (receivedChar == 'L') 
    {
      Serial.println("LED kapalı");
      digitalWrite(ledPin, LOW); // LED'i söndür
      delay(1000); // 1000 milisaniye (1 saniye) bekle
    }
  }
}