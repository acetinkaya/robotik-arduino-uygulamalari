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
ve altında bir mesafe degerinde ölcüm durumunda buzzer çalışıyor.

Kodun açıklaması: 
HC-SR04 ultrasonik mesafe sensörünün kütüphaneli okuma işlemidir.

Bu işlem için Tools->Library Manager->HCSR04 ara-> "HCSR04 by Martin Sosic" bilgisini içeren 
kütüphaneyi install ile kurulumunu yaparız. Kurulum yapıldıktan sonra File-> Examples -> HCSR04-> simple
çalıştırılarak aşağıdaki kodlar gelmektedir. Aşağıdaki kodlarda;

Arduino Nano üzerinde dijital pin bölümünde 9. ve 10. pinlere bağlı 
ultrasonik mesafe sensörü ile ölçüm alıp, seri port üzerinden mesafenin basılmasıdır.

Arduino park sensörü sistemidir. Ultrasonik sensörden gelen mesafeye göre buzzerin çalıştırılma durumudur.

*/

#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(9, 10);  // Trig, Echo

const int buzzer_pin = 8;

void setup() {
  pinMode(buzzer_pin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  float mesafe = distanceSensor.measureDistanceCm();

  Serial.print("Mesafe: ");
  Serial.println(mesafe);

  if (mesafe > 2 && mesafe <= 100) {
    // Mesafeyi 10cm-100cm arası 200Hz-2000Hz'e dönüştürelim (ters orantılı)
    int frekans = map((int)mesafe, 2, 100, 200, 2000);
    tone(buzzer_pin, frekans);
    delay(50); // bip süresi
    noTone(buzzer_pin);
    delay(50); // bipler arası boşluk
  }
  else if (mesafe <= 2) {
    // Çok yakınsa kesintisiz alarm
    tone(buzzer_pin, 4000);
  }
  else {
    // 100 cm'den uzaktaysa sessiz
    noTone(buzzer_pin);
  }

  delay(100);
}