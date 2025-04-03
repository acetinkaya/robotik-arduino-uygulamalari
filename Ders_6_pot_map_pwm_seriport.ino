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

---------------------------------------------------------------------------------------------------------
Kodun açıklaması: 

Arduino üzerinde var olan seri porttan potansiyometre değerini okuma.

*/


const int analogPin = A0;   // Potansiyometre veya sensör girişi
const int ledPin = 6;       // PWM destekli bir pin (LED bağlanacak)

int okunanDeger = 0;        // A0'dan okunan değer
int parlaklik = 0;          // LED için PWM değeri (0-255)

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);       // Seri monitörde değerleri görmek için
}

void loop() {
  okunanDeger = analogRead(analogPin);        // 0 - 1023 arası değer
  parlaklik = map(okunanDeger, 0, 1023, 0, 255); // 0 - 255'e ölçekle
  
  analogWrite(ledPin, parlaklik);             // PWM ile LED parlaklığı ayarla

  Serial.print("Analog Değer: ");
  Serial.print(okunanDeger);
  Serial.print(" | PWM: ");
  Serial.println(parlaklik);

  delay(100); // Okuma frekansı
}