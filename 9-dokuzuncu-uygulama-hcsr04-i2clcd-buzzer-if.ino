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

---------------------------------------------------------------------------------------------
Kodun açıklaması: 

HCSR04 sensöründen gelen mesafe bilgisine dayanarak, belirlenen güvenli mesafe değeri 
ve altında bir mesafe degerinde ölcüm alındığı durumda buzzer'dan uyarı sesleri çıkmaktadır.

*/

#include <Wire.h> 
#include <LiquidCrystal_I2C_Hangul.h>
#include <HCSR04.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

UltraSonicDistanceSensor distanceSensor(9, 10);  

const int guvenli_mesafe = 14; // Minimum güvenli mesafe (cm)

int mesafe = 0;

int buzzer_pin = 7; 
int uyari_sayisi = 2;
int uyari_sesleri[] = {270, 370};

void setup() 
{
  lcd.init();                    // LCD ekranını başlat
  lcd.clear();                   // LCD ekranını temizle
  lcd.backlight();               // Arka ışığı aç
  lcd.setCursor(0, 0);           // İlk satırın başına git
  lcd.print("Hello Robotik!!!"); // "Hello World!" yazısını ekrana yaz
  delay(2000);                   // 2 saniye bekle.
  Serial.begin(9600);            // Seri portu başlat
  pinMode(buzzer_pin, OUTPUT);
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

  if (mesafe <= guvenli_mesafe) 
  {
    for (int i = 0; i < uyari_sayisi; i++)
    {
    tone(buzzer_pin, uyari_sesleri[i]);
    delay(1000);
    noTone(buzzer_pin);
    delay(20);
    }
  } 
  else if (mesafe > guvenli_mesafe) 
  {
    noTone(buzzer_pin); // Buzzer'ı kapat
  }

  delay(100); // Ölçümleri 0.1 saniyede bir yap
}
