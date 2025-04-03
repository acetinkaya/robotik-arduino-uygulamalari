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

Arduino Nano üzerinde bağlı seri port üzerinden HCSR04 mesafe sensürüün sürülmesi işlemini gerçekleştiriyoruz. 

*/

const int trigPin = 9; // HC-SR04 sensörünün trig ve echo pinlerini tanımla
const int echoPin = 10;

void setup() 
{
  Serial.begin(9600); // Seri haberleşme başlatılıyor
  pinMode(trigPin, OUTPUT); // trig pinini çıkış olarak ayarla
  pinMode(echoPin, INPUT);  // echo pinini giriş olarak ayarla
}

void loop() 
{
  int mesafe = okuMesafe();  // HC-SR04 sensöründen mesafe okuma fonksiyonunu çağır
  
  Serial.print("Mesafe: ");  // Mesafeyi seri porta yazdır
  Serial.print(mesafe);
  Serial.println(" cm");
  
  delay(1000);   // 1 saniye bekle
}


int okuMesafe() // HC-SR04 sensöründen mesafe okuma fonksiyonu
{ 
  digitalWrite(trigPin, HIGH); // Trig pini 10 mikrosaniye boyunca yüksek olacak şekilde ayarla
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  long sure = pulseIn(echoPin, HIGH); // Echo pini yüksek olana kadar bekle
  
  int mesafe = sure / 58;
  // Süreyi mesafeye dönüştür (süre / 2) * (sesin hızı) formülü kullanılır (sesin hızı saniyede 343m/sn'dir.)

  return mesafe; // Mesafeyi döndür
}