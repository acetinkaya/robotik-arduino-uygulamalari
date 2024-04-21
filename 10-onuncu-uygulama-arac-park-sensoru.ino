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

HCSR04 sensöründen gelen mesafe bilgisine dayanarak, belirlenen güvenli mesafe değeri ve altında bir mesafe degerinde ölcüm durumunda buzzer çalışıyor.

*/


#include <Wire.h> 
#include <LiquidCrystal_I2C_Hangul.h>
#include <HCSR04.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

UltraSonicDistanceSensor distanceSensor(9, 10);

const int buzzerPin = 6; // Buzzer pini

int mesafe = 0; // hcsr04 degerinin tutulacağı değişkendir.

const int minimum_uzaklik = 0;    // Minimum güvenli mesafe (cm)
const int maksimum_uzaklik = 200; // Maksimum algılama mesafesi (cm)
const int buzzer_ton_degeri = 10; // Ses tonu değiştirme aralığı (cm)

void setup() 
{

  lcd.init();                    // LCD ekranını başlat
  lcd.clear();                   // LCD ekranını temizle
  lcd.backlight();               // Arka ışığı aç
  lcd.setCursor(0, 0);           // İlk satırın başına git
  lcd.print("Hello Robotik!!!"); // "Hello World!" yazısını ekrana yaz
  delay(2000);                   // 2 saniye bekle.
  Serial.begin(9600);            // Seri portu başlat
  pinMode(buzzerPin, OUTPUT);
  delay(200);                    // 0.2 saniye bekle.
  
}

void loop() 
{
  lcd.clear();                   
  lcd.setCursor(0,0);
  lcd.print("Olcum Mesafesi:"); 

  mesafe = distanceSensor.measureDistanceCm(); // uzaklık hesabının fonksiyonu
  
  lcd.setCursor(0,1);
  lcd.print(mesafe);
  lcd.setCursor(5,1);
  lcd.print("Cm");

  if (mesafe <= minimum_uzaklik) 
  {
    digitalWrite(buzzerPin, HIGH); // Buzzer'ı çal
  } 
  else if (mesafe >= maksimum_uzaklik) 
  {
    digitalWrite(buzzerPin, HIGH); // Buzzer'ı çal
  } 
  else 
  {
    int toneFrequency = map(mesafe, 0, maksimum_uzaklik, 200, 1000); // Mesafeye göre ton frekansını belirle
    tone(buzzerPin, toneFrequency); // Ton frekansını ayarla
  }

  if (mesafe % buzzer_ton_degeri == 0)    // Mesafe değişim aralığında ise buzzer'ı çal
  {
    tone(buzzerPin, random(200, 1000)); // Rastgele bir ton frekansı seç
  } 
  else 
  {
    noTone(buzzerPin); // Buzzer'ı kapat
  }

  delay(100); // Ölçümleri 0.1 saniyede bir yap
}