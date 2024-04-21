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

i2c lcd kullanımı için kütüphaneli yüklenmesi gerekmektedir.

Bu işlem için Tools->Library Manager->LiquidCrystal_I2C ara-> "LiquidCrystal_I2C_Hangul by Junwha Hong, Dohun Kim, HyungHo Kim" bilgisini içeren 
kütüphaneyi install ile kurulumunu yaparız. Kurulum yapıldıktan sonra File-> Examples -> LiquidCrystal_I2C_Hangul -> printenglish
çalıştırılarak aşağıdaki kodlar gelmektedir. Aşağıdaki kodlarda;

i2c lcd üzerinde 0. ve 1. satırlarda metin yazdırma işlemleri gerçekleştirilmektedir. 

*/

#include <Wire.h> 
#include<LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

void setup() 
{

  lcd.init();                    // LCD ekranını başlat
  lcd.backlight();               // Arka ışığı aç
  lcd.setCursor(0, 0);           // İlk satırın başına git
  lcd.print("Hello World!");     // "Hello World!" yazısını ekrana yaz
  delay(2000); 

  lcd.clear(); 
  lcd.setCursor(0, 1);             // İkinci satırın başına git
  lcd.print("Merhaba Sinif");      // "Merhaba Sinif" yazısını ekrana yaz      
  delay(5000); 
}

void loop() 
{
  
  lcd.clear();                    // Ekranı temizle
  lcd.setCursor(0, 0);            // İlk satırın başına git
  lcd.print("Merhaba");           // "Merhaba" yazısını ekrana yaz
  delay(2000);                    // 2 saniye bekle
  
  lcd.clear();                    // Ekranı temizle
  lcd.setCursor(0, 1);            // İkinci satırın başına git
  lcd.print("Nasilsin?");         // "Nasılsın?" yazısını ekrana yaz
  delay(2000);                    // 2 saniye bekle

}