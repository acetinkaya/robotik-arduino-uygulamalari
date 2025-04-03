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

Arduino üzerine bağlanan buzzerın çalıştırılması.

*/

const int buzzer_pini = 9;  // Buzzer pin bağlantısı

void setup() 
{
  pinMode(buzzer_pini, OUTPUT);   // Buzzer pinini çıkış olarak ayarla

  delay(500);
}

void loop() 
{ 
  
buzz(1500, 200);

delay(1000); // 1 saniye bekle

buzz(0, 200);

delay(1000); // 1 saniye bekle


}

void buzz(unsigned int frekans, unsigned long sure) 
{
  tone(buzzer_pini, frekans, sure);        // Buzzerı belirtilen frekansta belirtilen süre boyunca çal
  delay(sure);                            // Belirtilen süre boyunca bekleyin
  noTone(buzzer_pini);                     // Buzzerı durdur
}