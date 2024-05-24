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
RTClib.h -> RTClib by Adafruit
LiquidCrystal_I2C_Hangul.h> -> i2c lcd by Junwha 

Bu işlem için Tools->Library Manager->LiquidCrystal_I2C ara-> "LiquidCrystal_I2C_Hangul by Junwha Hong, Dohun Kim, HyungHo Kim" bilgisini içeren 
kütüphaneyi install ile kurulumunu yaparız. Kurulum yapıldıktan sonra File-> Examples -> LiquidCrystal_I2C_Hangul -> printenglish
çalıştırılarak aşağıdaki kodlar gelmektedir. Aşağıdaki kodlarda;

i2c lcd üzerinde 0. ve 1. satırlarda metin yazdırma işlemleri gerçekleştirilmektedir.
i2c saat modülünden gelen saat ve saniye bilgisini i2c lcd üzerine yazdırılması işlemidir.  

*/

#include <Wire.h> 
#include<LiquidCrystal_I2C_Hangul.h>
#include <RTClib.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

RTC_DS3231 rtc; // RTC tanımlaması

void setup() 
{

  lcd.init();                    // LCD ekranını başlat
  lcd.backlight();               // Arka ışığı aç
  lcd.setCursor(0, 0);           // İlk satırın başına git
  lcd.print("Hello World!");     // "Hello World!" yazısını ekrana yaz
  delay(1000); 

  lcd.clear(); 
  lcd.setCursor(0, 1);             // İkinci satırın başına git
  lcd.print("Merhaba Sinif");      // "Merhaba Sinif" yazısını ekrana yaz      
  delay(2000); 

  if (!rtc.begin())  // RTC başlat ve zamanın ayarlı olup olmadığını kontrol et
  {
    lcd.clear(); 
    lcd.print("RTC bulunamadi");
    while (1); delay(10);
  }

  rtc.adjust(DateTime(2024, 5, 24, 10, 45, 0)); // RTC zaman ayarı (Yıl, Ay, Gün, Saat, Dakika, Saniye)

  lcd.print("RTC zamanı ayarlandi!");   //Serial.println("RTC zamanı ayarlandı!");

}

void loop() // Ana Döngü
{
  
  DateTime now = rtc.now();  // Şu anki zamanı oku
  
  lcd.clear();   // LCD ekranını temizle
  
  lcd.setCursor(0, 0);   // Saat ve dakikayı LCD'nin birinci satırına yaz
  lcd.print(now.hour(), DEC);
  lcd.print(':');
  lcd.print(now.minute(), DEC);
  lcd.print(':');
  lcd.print(now.second(), DEC);
  
  lcd.setCursor(0, 1);   // Tarihi LCD'nin ikinci satırına yaz
  lcd.print(now.day(), DEC);
  lcd.print('/');
  lcd.print(now.month(), DEC);
  lcd.print('/');
  lcd.print(now.year(), DEC);
  
  delay(1000);  // Bir saniye bekle
}