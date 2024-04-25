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

Kodun açıklması: Arduino ile gerçek zamanlı gaz seviyesi okuma uygulamaları Kullanılacak sensörler;

MQ-2: LPG, İzobütan, Propan, Metan, Alkol, Hidrojen
MQ-3: Alkol buharı
MQ-4: Metan, doğal gaz
MQ-5: LPG, propan, metan, hidrojen
MQ-6: LPG, propan, İzobütan, metan, alkol, hidrojen
MQ-7: Karbon monoksit (CO)
MQ-8: Hidrojen, LPG, propan, metan, alkol, hidrojen
MQ-9: Karbon monoksit (CO), metan, LPG
MQ-135: Amonya, sülfür dioksit (SO2), bükülme, alkol, benzen, tiner, sigara dumanı, CO2

Bu deneyimiz üzerinde arduino nano üzerinden i2c lcd, buzzer, role ve mq3 alkol sensörlerinin 
bütünleştiği bir otomasyon tasarımıdır. MQ3 üzerinden gelen alkol seviye bilgisi tehlikeli olarak belirlenen
seviyeye eriştiğinde buzzer ötmesi ile uyarı vermektedir. Role çalışarak sisteme hava girişi yapacak
donanım kurgusu aktif edilerek sisteme hava girişi yapılmaktadır. Yeniden ölçümler sonrası tehlikeli gaz 
seviye ölçümü devam ediyorsa yukarıdaki döngünün tekrarı seviye ölcümü normal ise buzzer susup, 
role kapanmaktadır.

*/

#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

const int mq3_pini = A0;    // MQ3 gaz sensörü pin bağlantısı
const int buzzer_pini = 7;  // Buzzer pin bağlantısı
const int role_pini = 8;    // Röle modülü pin bağlantısı

void setup() 
{
  pinMode(buzzer_pini, OUTPUT);   // Buzzer pinini çıkış olarak ayarla
  pinMode(role_pini, OUTPUT);     // Role pinini çıkış olarak ayarla
  digitalWrite(role_pini, HIGH);  // Röleyi devre dışı bırak
  lcd.init();      // LCD ekranını başlat
  lcd.backlight(); // Arka ışığı aç
  lcd.clear();     // LCD ekranını temizledik
  lcd.setCursor(0, 0);
  lcd.print("Alkol Tespit");
  lcd.setCursor(0, 1);
  lcd.print("Sistemi -->");
  delay(5000);
}

void loop() 
{

  int okunan_alkol_bilgisi = analogRead(mq3_pini);   // MQ3 Gaz sensöründen okuma yap
 
  int tehlike_durumu = 250; //  // Alkol seviyesinin tehlikeli noktaya geldiği anı belirledik.
  
  if (okunan_alkol_bilgisi >= tehlike_durumu) 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alkol Durumu");
    lcd.setCursor(13, 0);
    lcd.print(okunan_alkol_bilgisi);
    lcd.setCursor(0, 1);
    lcd.print("icmeyi Birak!!!");
    buzz(1500, 200);
    digitalWrite(role_pini, LOW);    // Röleyi aktif et (örneğin, bir fanı çalıştırmak için)
    delay(500);                      // Buzzer ve röle 10 saniye boyunca aktif kalacak
  } 
  else 
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Alkollu Degilsin");
    lcd.setCursor(0, 1);
    lcd.print(okunan_alkol_bilgisi);
    digitalWrite(buzzer_pini, LOW); // Buzzer'ı kapat
    digitalWrite(role_pini, HIGH);  // Röleyi devre dışı bırak
  }
  
  delay(1000); // 1 saniye bekle
}

void buzz(unsigned int frekans, unsigned long sure) 
{
  tone(buzzer_pini, frekans, sure);        // Buzzerı belirtilen frekansta belirtilen süre boyunca çal
  delay(sure);                            // Belirtilen süre boyunca bekleyin
  noTone(buzzer_pini);                     // Buzzerı durdur
}