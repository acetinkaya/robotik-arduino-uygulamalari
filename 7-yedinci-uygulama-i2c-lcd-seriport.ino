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
Seri porttan gelen bilgilerin lcd ekran üzerinde yazılması ve seri porttan bilgi yok iken ekranda veri yok yazmaktadır.

*/

#include <Wire.h> 
#include<LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

void setup() 
{
  lcd.init();                    // LCD ekranını başlat
  lcd.clear();                   // LCD ekranını temizle
  lcd.backlight();               // Arka ışığı aç
  lcd.setCursor(0, 0);           // İlk satırın başına git
  lcd.print("Hello World!");     // "Hello World!" yazısını ekrana yaz
  delay(2000);                   // 2 saniye bekle.
  Serial.begin(9600);            // Seri portu başlat
  delay(200);                    // 0.2 saniye bekle.
}

void loop() 
{
  if (Serial.available() > 0) // Seri porttan veri alındığında
  { 
    String receivedData = Serial.readString();    // Veriyi oku
    lcd.clear();                                  // Ekranı temizle
    lcd.setCursor(0, 0);                          // İlk satırın başına git
    lcd.print(receivedData);                      // Alınan veriyi ekrana yaz
  }
}