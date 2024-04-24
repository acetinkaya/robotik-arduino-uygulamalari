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

i2c lcd üzerinde rölenin açık veya kapalı olma durumunun yazılmasıdır.

*/


#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

int role_pin = 8; // Röle pini

void setup() 
{
  Serial.begin(9600);
  lcd.init();      // LCD ekranını başlat
  lcd.backlight(); // Arka ışığı aç

  pinMode(role_pin, OUTPUT);
  digitalWrite(role_pin, LOW);   

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Role: Kontrol");
  lcd.setCursor(0, 1);
  lcd.print("Uygulamasi");

  delay(5000);
}

void loop() 
{

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Role: Acik");
  digitalWrite(role_pin, LOW);   // Röle modül devre bağlantısında LOW -> Roleyi Aktif etmektedir.
  delay(5000); // 5 saniye bekle
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Role: Kapali");
  digitalWrite(role_pin, HIGH);   // Röle modül devre bağlantısında HIGH -> Roleyi Pasif etmektedir.
  delay(5000); // 5 saniye bekle

}
