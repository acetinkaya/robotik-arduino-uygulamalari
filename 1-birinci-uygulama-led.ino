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

Arduino Nano üzerinde bağlı olan 13. ledin yarım saniye aralıklar ile yanıp sönmesini hedef ediniyoruz.
Bu kapsamda pinMode fonksiyonu ile arduino pinlerini giriş (INPUT) veya çıkış (OUTPUT) yapmaya yarar. 
digitalWrite kodu ile ilgili pin üzerinde HIGH tanımlaması varsa pin çıkışı aktif-5V, LOW tanımlaması var ise pin çıkışı pasif-0V olarak ayarlanmaktadır. 
Arduino platformunda atmega programlar iken iki önemli fonksiyon bulunmaktadır. setup() fonksiyonu ile denetleyicinin ayarları yapılır. loop() fonksiyonu ile denetleyicinin program döngüsü çalıştırılmaktadır.
delay() fonksiyonu ile;  program döngüsünün belirli bir süre boyunca kod üzerinde çalışmasını sağlamaktadır. 

*/

const int ledPin = 13; // LED pini

void setup() 
{
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarlandı
}

void loop() 
{
  digitalWrite(ledPin, HIGH); // LED'i yak
  delay(500); // 500 milisaniye (0.5 saniye) bekle

  digitalWrite(ledPin, LOW); // LED'i söndür
  delay(500); // 500 milisaniye (0.5 saniye) bekle
}
