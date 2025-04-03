/*
Bu kodlar açık kaynak paylaşım olarak github "acetinkaya" alanında paylaşımı yapılmıştır. 

BTP222 Robotik dersi içerisinde anlatımı yapılan bu kodlar ve içerikler Öğr. Gör. Ali ÇETİNKAYA tarafından oluşturulmuştur. 

Github alanından; 
watch - ilgili projenin proje takibi bildirimi, 
star - yıldız ile beğenme bildirimi ve 
fork - kendi hesabınıza kopyalama işlemleriyle paylaşımlarıma destek verebilirsiniz. 

Bilgi paylaşıldıkça çoğalır ve gelişir. İyi çalışmalar dilerim.

Öğr. Gör. Ali ÇETİNKAYA İstanbul, 2025

Dersin Kaynak Adresleri:
https://github.com/acetinkaya/robotik-arduino-uygulamalari
https://alicetinkaya.site/ders-robotik
https://avesis.gelisim.edu.tr/alcetinkaya 
https://scholar.google.com.tr/citations?hl=tr&user=XSEW-NcAAAAJ

---------------------------------------------------------------------------------------------
Kodun açıklaması: 

HCSR04 sensöründen gelen mesafe bilgisine dayanarak, belirlenen güvenli mesafe değeri 
ve altında bir mesafe degerinde ölcüm durumunda buzzer çalışıyor.

Kodun açıklaması: 
HC-SR04 ultrasonik mesafe sensörünün kütüphaneli okuma işlemidir.

Bu işlem için Tools->Library Manager->HCSR04 ara-> "HCSR04 by Martin Sosic" bilgisini içeren 
kütüphaneyi install ile kurulumunu yaparız. Kurulum yapıldıktan sonra File-> Examples -> HCSR04-> simple
çalıştırılarak aşağıdaki kodlar gelmektedir. Aşağıdaki kodlarda;

Arduino Nano üzerinde dijital pin bölümünde 9. ve 10. pinlere bağlı 
ultrasonik mesafe sensörü ile ölçüm alıp, seri port üzerinden mesafenin basılmasıdır.

*/

#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(9, 10);  // Trig=9, Echo=10

const int guvenli_mesafe = 14; // cm

int buzzer_pin = 8;
int uyari_sayisi = 2;
int uyari_sesleri[] = {270, 370};

void setup() {
  pinMode(buzzer_pin, OUTPUT);
  Serial.begin(9600); // Seri monitörde mesafe görmek isterseniz
  delay(200); 
}

void loop() {
  float mesafe = distanceSensor.measureDistanceCm();

  Serial.print("Mesafe: ");
  Serial.println(mesafe);

  if (mesafe > 0 && mesafe <= guvenli_mesafe) {
    for (int i = 0; i < uyari_sayisi; i++) {
      tone(buzzer_pin, uyari_sesleri[i]); 
      delay(200); // 0.2 sn çalsın
      noTone(buzzer_pin); 
      delay(100); // iki ses arasında bekleme
    }
  } else {
    noTone(buzzer_pin); 
  }

  delay(200); // Ölçüm aralığı
}