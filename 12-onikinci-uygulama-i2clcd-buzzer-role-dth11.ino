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

Kodun açıklması: arduino nano üzerinden dth11 üzerinden alınan verilerin işlenerek i2c lcd, buzzer ve role uygulamasıdır.
HC-SR04 ultrasonik mesafe sensörünün kütüphaneli okuma işlemidir.

Bu işlem için Tools->Library Manager->DHT11 ara-> "DHT11 by Dhruba Saha" bilgisini içeren 
kütüphaneyi install ile kurulumunu yaparız. Kurulum yapıldıktan sonra File-> Examples -> HCSR04-> simple
çalıştırılarak aşağıdaki kodlar gelmektedir. Aşağıdaki kodlarda;

*/

#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>
#include <DHT11.h>      // DHT tipine uygun kütüphane seçimi

DHT11 dht11(2);         // DHT11 sensörünün pin numarası  

#define BUZZER_PIN 7      // Buzzer pinini belirt

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

void setup() 
{
  lcd.init();                      // LCD ekranını başlat
  lcd.backlight();                 // Arkadan ışık aç
  pinMode(BUZZER_PIN, OUTPUT);     // Buzzer pinini çıkış olarak ayarla
}

void loop() 
{

  int sicaklik = 0;
  int nem = 0;
  int sonuc = dht11.readTemperatureHumidity(sicaklik, nem); // Sıcaklık ve nem değerlerini oku

  if (sonuc == 0) 
  {
      if (!isnan(nem) && !isnan(sicaklik))  // Değerler doğruysa LCD ekranına yazdır
      {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Sicaklik: ");
        lcd.print(sicaklik);
        lcd.print(" C");

        lcd.setCursor(0, 1);
        lcd.print("Nem: ");
        lcd.print(nem);
        lcd.print("%");
        
        if (sicaklik > 30 || nem > 60)  // Belirli bir sıcaklık veya nem seviyesi aşıldığında uyarı ver
        {
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("Dikkat Uyari!!!");
          lcd.setCursor(0, 1);
          lcd.print("Terk Etmelisin!!");
          buzz(1500, 200);
        }
      }
  } 
  else 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Okuma hatasi");
    lcd.setCursor(0, 1);
    lcd.print(DHT11::getErrorString(sonuc));
    delay(100);
  }
  delay(2000);  // 2 saniye bekleyin
}

void buzz(unsigned int frekans, unsigned long sure) 
{
  tone(BUZZER_PIN, frekans, sure);        // Buzzerı belirtilen frekansta belirtilen süre boyunca çal
  delay(sure);                            // Belirtilen süre boyunca bekleyin
  noTone(BUZZER_PIN);                     // Buzzerı durdur
}