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

Kurulacak Kütüphaneler---->
RTClib.h -> RTClib by Adafruit
LiquidCrystal_I2C_Hangul.h> -> i2c lcd by Junwha 

Servo motor kontrol etmek istiyorsanız --> Servo.h kütüphanesini dahil etmeniz gerekmektedir. 

Bu işlem için Tools->Library Manager->LiquidCrystal_I2C ara-> "LiquidCrystal_I2C_Hangul by Junwha Hong, Dohun Kim, HyungHo Kim" bilgisini içeren 
kütüphaneyi install ile kurulumunu yaparız. Kurulum yapıldıktan sonra File-> Examples -> LiquidCrystal_I2C_Hangul -> printenglish
çalıştırılarak aşağıdaki kodlar gelmektedir. Aşağıdaki kodlarda;

i2c lcd üzerinde 0. ve 1. satırlarda metin yazdırma işlemleri gerçekleştirilmektedir.
i2c saat modülünden gelen saat ve saniye bilgisini i2c lcd üzerine yazdırılması işlemidir.  

*/


#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>
#include <RTClib.h>

LiquidCrystal_I2C_Hangul lcd(0x27, 16, 2); // 0x27 adresli 16x2 karakter LCD
RTC_DS3231 rtc; // RTC tanımlaması

const int buzzerPin = 8; // Buzzer pin
const int startButtonPin = 5; // Başlatma butonu pini

// Değişkenler
bool sistem_dongusu = false;
unsigned long previousMillis = 0;
const long interval = 60000; // 1 dakika

void setup() {
  lcd.init(); // LCD ekranını başlat
  lcd.backlight(); // Arka ışığı aç
  lcd.setCursor(0, 0); // İlk satırın başına git
  lcd.print("Hello World!"); // "Hello World!" yazısını ekrana yaz
  delay(1000);

  lcd.clear();
  lcd.setCursor(0, 1); // İkinci satırın başına git
  lcd.print("Merhaba Sinif"); // "Merhaba Sinif" yazısını ekrana yaz
  delay(2000);

  if (!rtc.begin()) { // RTC başlat ve zamanın ayarlı olup olmadığını kontrol et
    lcd.clear();
    lcd.print("RTC bulunamadi");
    while (1) delay(10);
  }

  rtc.adjust(DateTime(2024, 5, 24, 13, 46, 0)); // RTC zaman ayarı (Yıl, Ay, Gün, Saat, Dakika, Saniye)
  lcd.print("RTC zamanı ayarlandi!"); //Serial.println("RTC zamanı ayarlandı!");

  pinMode(buzzerPin, OUTPUT); // Buzzer pinini çıkış olarak ayarla
  pinMode(startButtonPin, INPUT); // Başlatma butonu pinini giriş olarak ayarla
}

void loop() 
{
  lcd.clear();
  
  bool startButtonPressed = digitalRead(startButtonPin); // Düğmeye basıldığında LOW olacak // Başlatma butonunu kontrol et

  if (startButtonPressed) // Başlatma butonuna basıldığında
  { 
    sistem_dongusu = true;
  }

  if (sistem_dongusu) 
  {
    DateTime now = rtc.now();
    //lcd.clear();
    // LCD ekranında zamanı göster
    lcd.setCursor(0, 1);
    //lcd.print("                 ");
    lcd.setCursor(0, 0);
    lcd.print("Saat: ");
    if (now.hour() < 10) lcd.print('0');
    lcd.print(now.hour());
    lcd.print(':');
    if (now.minute() < 10) lcd.print('0');
    lcd.print(now.minute());
    lcd.print(':');
    if (now.second() < 10) lcd.print('0');
    lcd.print(now.second());
    delay(1000);
    
    unsigned long currentMillis = millis();     // 1 dakika aralıkla buzzer'ı öttür
    if (currentMillis - previousMillis >= interval) 
    {
      previousMillis = currentMillis; // Buzzer'ı 1 saniye boyunca öttür
      
      digitalWrite(buzzerPin, HIGH);
      delay(1000);
      
      lcd.clear(); // LCD ekranını temizle
      lcd.setCursor(0, 0);
      lcd.print("1. Kutudan");
      lcd.setCursor(0, 1);
      lcd.print("ilacini Al!!!");
      delay(5000);
      digitalWrite(buzzerPin, LOW);
    }
  }
  else 
  {
      lcd.clear(); // LCD ekranını temizle
      lcd.setCursor(0, 0);
      lcd.print("Sistemin Baslat!!");
      lcd.setCursor(0, 1);
      lcd.print("Butona Bas");
      delay(100);
  }
}
