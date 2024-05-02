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

Kodun açıklaması: potansiyo metreden gelen adc sinyal değerlerinin i2clcd üzerine yansıtılarak
l298 motor sürücü üzerinde pwm hızının ayarlanarak dc motor sürme uygulaması

*/

int DC_Motor_PWM = 3; // Motor hız kontrol pini (PWM)
int DC_Motor_A = 11;  // Motor yön kontrol pini 11
int DC_Motor_B = 12;  // Motor yön kontrol pini 12

#define pot_pin A1   // Potansiyometre pinini tanımla

#include <Wire.h> 
#include<LiquidCrystal_I2C_Hangul.h>
#include <HCSR04.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD
UltraSonicDistanceSensor distanceSensor(9, 10);  // hcsr04 pinleri

int mesafe = 0;

int pot_degeri = 0;

int pwm_hizi = 0;

void setup()
 {
  // Pinlerin çıkış olarak ayarlanması
  pinMode(DC_Motor_PWM, OUTPUT);
  pinMode(DC_Motor_A, OUTPUT);
  pinMode(DC_Motor_B, OUTPUT);

  delay(100);

  digitalWrite(DC_Motor_A, LOW);
  digitalWrite(DC_Motor_B, LOW);
  delay(100);

  lcd.init();                    // LCD ekranını başlat
  lcd.backlight();               // Arka ışığı aç
  lcd.setCursor(0, 0);           // İlk satırın başına git
  lcd.print("i2clcd-hcsr-mtr");     // "Hello World!" yazısını ekrana yaz
  lcd.setCursor(0, 1);             // İkinci satırın başına git
  lcd.print("Uygulamasi");      // "Merhaba Sinif" yazısını ekrana yaz      
  delay(5000); 
}

void loop() 
{
  lcd.clear();                   
  lcd.setCursor(0,0);
  lcd.print("Olcum:"); 

  mesafe = distanceSensor.measureDistanceCm(); // uzaklık hesabının fonksiyonu
  
  lcd.setCursor(8,0);
  lcd.print(mesafe);
  lcd.setCursor(11,0);
  lcd.print("Cm");

  pwm_hizi = map(mesafe, 0, 17, 0, 255);  //HCSR04 0 - 17 to 0-255 pwm 

  digitalWrite(DC_Motor_A, HIGH);      // Motorun ileri yönde hareket etmesi
  digitalWrite(DC_Motor_B, LOW);
  analogWrite(DC_Motor_PWM, pwm_hizi); // PWM sinyali ile hız kontrolü (255 maksimum hız)

  lcd.setCursor(0, 1);           // İkinci satırın başına git
  lcd.print("PWM D:");           // "PWM D:" yazısını ekrana yaz
  lcd.setCursor(8, 1);           // ikinci satırın 8. hücresine git
  lcd.print(pwm_hizi);           // pwm degerini ekrana yaz

  delay(300);  // 250 milisaniye bekleme
}