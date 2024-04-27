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

#define joyX A2   // Potansiyometre pinini tanımla
#define joyY A3

#define servo_pin_x 5  // Servo motor pinini tanımla
#define servo_pin_y 6  

Servo servo_motor_x;  // Servo motor nesnesini oluştur
Servo servo_motor_y;

void setup() // Kurulum ayarları
{
  lcd.init();      // LCD ekranını başlat
  lcd.backlight(); // Arka ışığı aç

  servo_motor_x.attach(servo_pin_x);  // Servo motoru belirtilen pine bağla
  servo_motor_y.attach(servo_pin_y);   

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("X ve Y eksen");
  lcd.setCursor(0, 1);
  lcd.print("Joyistick Uyg.");

  delay(5000);
}

void loop() // Ana döngü başlangıcı
{
  lcd.clear(); // Lcd ekranı temizliyoruz.

  lcd.setCursor(0, 0);
  lcd.print("X:");
  lcd.setCursor(0, 1);
  lcd.print("Y:");

  int xValue = analogRead(joyX); // X eksenindeki değeri oku
  int yValue = analogRead(joyY); // Y eksenindeki değeri oku

  int xAngle = map(xValue, 0, 1023, 0, 180); // X eksenindeki değeri 0-180 aralığına dönüştür
  int yAngle = map(yValue, 0, 1023, 0, 180); // Y eksenindeki değeri 0-180 aralığına dönüştür

  servo_motor_x.write(xAngle); // X eksenindeki değeri servo motorun açısına dönüştür
  servo_motor_y.write(yAngle); // Y eksenindeki değeri servo motorun açısına dönüştür

  lcd.setCursor(3, 0);
  lcd.print(xValue);
  lcd.setCursor(3, 1);
  lcd.print(yValue);

  delay(100); // Güncelleme aralığını ayarla (msec)
}