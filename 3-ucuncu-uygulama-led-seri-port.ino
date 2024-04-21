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

// LED pinini belirle
const int ledPin = 13;

void setup() {
  // Seri haberleşmeyi başlat (baud rate: 9600)
  Serial.begin(9600);

  // LED pinini çıkış olarak ayarla
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Seri porttan veri al
  if (Serial.available() > 0) {
    char receivedChar = Serial.read();
    
    // Alınan karakter 'H' ise LED'i yak
    if (receivedChar == 'H') {
      digitalWrite(ledPin, HIGH);
      Serial.println("LED açık");
    }
    // Alınan karakter 'L' ise LED'i söndür
    else if (receivedChar == 'L') {
      digitalWrite(ledPin, LOW);
      Serial.println("LED kapalı");
    }
  }
}