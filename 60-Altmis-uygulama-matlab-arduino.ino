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
MQ-135: Hava Kalitesi Sensörü

Bu deneyimiz üzerinde arduino nano üzerinden i2c lcd, buzzer, role ve mq2 lpg gazı sensörlerinin 
bütünleştiği bir otomasyon tasarımıdır. MQ2 üzerinden gelen gaz seviye bilgisi tehlikeli olarak belirlenen
seviyeye eriştiğinde buzzer ötmesi ile uyarı vermektedir. Role çalışarak sisteme hava girişi yapacak
donanım kurgusu aktif edilerek sisteme hava girişi yapılmaktadır. Yeniden ölçümler sonrası tehlikeli gaz 
seviye ölçümü devam ediyorsa yukarıdaki döngünün tekrarı seviye ölcümü normal ise buzzer susup, 
role kapanmaktadır.

*/

#include <Wire.h>
#include <LiquidCrystal_I2C_Hangul.h>
#include <DHT11.h>      

LiquidCrystal_I2C_Hangul lcd(0x27,16,2); // 0x27 adresli 16x2 karakter LCD

DHT11 dht11(2);             // DHT11 sensörünün pin numarası  

const int mq2_pini = A0;    // MQ2 gaz sensörü pin bağlantısı

int sicaklik = 0;
int nem = 0;
int okunan_gaz_bilgisi = 0;
int sonuc = 0;

int led = 13;

void setup() 
{
  Serial.begin(115200); // Seri haberleşme başlatılıyor
}

void loop() 
{
  digitalWrite(led, HIGH);
  okunan_gaz_bilgisi = analogRead(mq2_pini);   // Gaz sensöründen okuma yap
  sonuc = dht11.readTemperatureHumidity(sicaklik, nem); // Sıcaklık ve nem değerlerini oku
  delay(100);
  //if (sonuc == 0) 
  //{
    
  Serial.println(sicaklik);
  delay(100);
  Serial.println(nem);
  delay(100);
  Serial.println(okunan_gaz_bilgisi);
  digitalWrite(led, LOW);
  delay(100);
  //} 
}