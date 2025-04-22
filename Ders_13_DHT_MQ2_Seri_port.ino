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
Örneğin açıklaması: 

---

DHT Kütüphanesini Arduino menülerinden "Tools" -> "Manage Libraries..." -> arama menüsünden -> "DHT sensor library by Adafruit" bularak "INSTALL" ile kurulum sağlayın, Kurulum tamamlanmdıktan sonra...

---

DHT (Digital Humidity and Temperature) serisi sensörler, dijital çıkışlı sıcaklık ve nem ölçüm sensörleridir. 
Hava koşullarını izlemek, akıllı ev sistemleri, tarım uygulamaları ve IoT projelerinde kullanılır.

------

MQ Serisi Sensörlerin Kullanım ve Uygulanma Alanları:

Sensör	Algıladığı Gazlar	                Uygulama Alanı
MQ-2	  LPG, Propan, Metan, Alkol, Duman	Duman ve gaz alarm sistemleri
MQ-3	  Alkol, Benzen, CH₄, duman	        Alkol ölçerler, araba içi sistemler
MQ-4	  Metan (CH₄), Doğal gaz	          Doğalgaz kaçağı tespiti
MQ-5	  LPG, Doğal gaz, Kömür gazı	      Gaz sızıntısı alarmı
MQ-6	  LPG, İzobütan, Propan	            Endüstriyel gaz algılama
MQ-7	  Karbon monoksit (CO)	            CO dedektörleri
MQ-8	  Hidrojen (H₂)	                    Hidrojen kaçağı kontrolü
MQ-9	  Karbon monoksit (CO), Metan, LPG	Çoklu gaz algılayıcı sistemler
MQ-135	Amonyak, Benzen, CO₂, Duman	      Hava kalitesi ölçümü

*/

#include <DHT.h>

#define DHTPIN 2       
#define DHTTYPE DHT11  

DHT dht(DHTPIN, DHTTYPE);
int mq2Pin = A0;        

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();  
  float humidity = dht.readHumidity();        
  int gasValue = analogRead(mq2Pin);          

  Serial.print("Sıcaklık: ");
  Serial.print(temperature);
  Serial.print("°C\tNem: ");
  Serial.print(humidity);
  Serial.print("%\tGaz Değeri: ");
  Serial.println(gasValue);

  delay(2000);
}
