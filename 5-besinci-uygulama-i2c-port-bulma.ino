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

Bu kodun görevi I2C hattında bağlı olan cihazları tarayıp erişim adreslerini kullanıcı için seri porta 
yazdırılmasıdır. Bu Arduino kodu, I2C (Inter-Integrated Circuit) iletişim protokolü kullanarak 
Arduino'nun çevresel cihazları taramasını ve bulmasını sağlar. 

i2c modül --> Arduino
VCC --------> VCC
GND --------> GND
SDA --------> A4
SDL --------> A5

*/

#include <Wire.h> // Bu kütüphane Arduino platformunda I2C (Inter-Integrated Circuit) 
                  // haberleşme protokolünü kullanmak için kullanılan bir kütüphanedir. 

boolean DeviceFound = false; // Cihazın bulunup bulunmadığını belirleyen boolean değişken

byte error, address; // Hata ve adres değişkenleri

void setup() 
{
  
  Wire.begin(); // I2C ve seri haberleşmeyi başlat
  Serial.begin(9600);
  Serial.println("\nI2C Araniyor...");

 
  for (address = 0; address <= 127; address++ )  // I2C adreslerini tara
  {
    
    Wire.beginTransmission(address); // Her bir adrese erişmeye çalış
    error = Wire.endTransmission();
    
    
    if (error == 0) // Eğer bir cihaz bulunursa
    {
      Serial.print("I2C cihaz bulundu. Adresi: 0x"); // Cihazın adresini seri porta yazdır
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);

      DeviceFound = true; // Cihaz bulunduğunu işaretle ve döngüden çık
      break;
    } 
    
    else if (error == 4) // Eğer bir hata oluşursa
    {
      Serial.print("Bilinmeyen hata olustu. Adres: 0x"); // Hata mesajını seri porta yazdır
      if (address < 16) Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  
  
  if (DeviceFound == false) // Herhangi bir cihaz bulunamazsa
    Serial.println("Herhangi bir bagli I2C bulunamadi\n");
  else
    Serial.println("Tamamlandi. Kolay gelsin.\n");
}

void loop() 
{
  // Boş döngü // seri port ekranında i2c modülünün adresini yazdırma işlemidir. 
  // Sistemin resetlenme süreci için arduino üzerindeki buton kullanılabilir. 
}
