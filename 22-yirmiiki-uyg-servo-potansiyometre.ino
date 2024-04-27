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

Kodun açıklaması: Potansiyometreden okunan değerin, servo motora aktarımını yapıp 
i2c lcd üzerinde pot ve servo motor değerlerini yazdıran kod parçasıdır. 

*/

#include <Servo.h> // Servo motor kütüphanesi
#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

#define pot_pin A1   // Potansiyometre pinini tanımla
#define servo_pin 5  // Servo motor pinini tanımla

Servo servo_motor;  // Servo motor nesnesini oluştur

const int numOkumalar = 10; // Hareketli ortalama için okuma sayısı
int okumalar[numOkumalar];  // Okuma dizisi
int okumaIndeksi = 0;          // Okuma dizisi indeksi
int toplam = 0;              // Okuma toplamı
int ortalama = 0;            // Hareketli ortalama

void setup() // Kurulum ayarları
{
  
  lcd.init();      // LCD ekranını başlat
  lcd.backlight(); // Arka ışığı aç

  servo_motor.attach(servo_pin);  // Servo motoru belirtilen pine bağla

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Potansiyometre");
  lcd.setCursor(0, 1);
  lcd.print("Servo Uyg.");

  delay(5000);
}

void loop() // Ana döngü başlangıcı
{
  lcd.clear(); // Lcd ekranı temizliyoruz.
  lcd.setCursor(0, 0);
  lcd.print("Pot D: ");
  lcd.setCursor(8, 0);
  int pot_degeri = analogRead(pot_pin);  // Potansiyometre değerini oku
  lcd.print(pot_degeri);

  toplam -= okumalar[okumaIndeksi];             // Okuma dizisinden eski değeri çıkar
  okumalar[okumaIndeksi] = analogRead(pot_pin);  // Yeni okumayı al
  toplam += okumalar[okumaIndeksi];              // Okuma toplamına yeni değeri ekle
  okumaIndeksi = (okumaIndeksi + 1) % numOkumalar; // Okuma dizisi indeksini güncelle
  ortalama = toplam / numOkumalar;              // Hareketli ortalama hesapla

  int servo_acisi = map(ortalama, 0, 1023, 0, 180);  
  // 0 ile 1023 arasında analog olarak okunan potansiyometre değerini 0-180 arasına dönüştürmektedir.
  // 0 ile 180 servo motorun çalışma açılarıdır. 
  lcd.setCursor(0, 1);
  lcd.print("Aci D: ");
  lcd.setCursor(8, 1);
  lcd.print(servo_acisi);

  servo_motor.write(servo_acisi);  // Servo motorun açısını potansiyometre değerine göre ayarla
  
  delay(15);  // Servo motorun tepki süresi
  
}