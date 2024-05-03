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

Kodun açıklaması: Çift DC motorun L298 motor sürücü üzerinde sürülmesi işlemidir. 

*/

int DC_Motor_PWM = 3; // Motor hız kontrol pini (PWM)
int DC_Motor_A = 11;  // Motor yön kontrol pini 11
int DC_Motor_B = 12;  // Motor yön kontrol pini 12

int DC_Motor_C = 4;   // Motor yön kontrol pini 4
int DC_Motor_D = 13;  // Motor yön kontrol pini 13

#define pot_pin A1   // Potansiyometre pinini tanımla

void setup()
 {
  // Pinlerin çıkış olarak ayarlanması
  pinMode(DC_Motor_PWM, OUTPUT);
  pinMode(DC_Motor_A, OUTPUT);
  pinMode(DC_Motor_B, OUTPUT);
  pinMode(DC_Motor_C, OUTPUT);
  pinMode(DC_Motor_D, OUTPUT);

  delay(100);

  digitalWrite(DC_Motor_A, LOW);
  digitalWrite(DC_Motor_B, LOW);
  digitalWrite(DC_Motor_C, LOW);
  digitalWrite(DC_Motor_D, LOW);
  delay(100);
}

void loop() 
{

  // Motorun durması
  digitalWrite(DC_Motor_A, LOW);
  digitalWrite(DC_Motor_B, LOW);
  digitalWrite(DC_Motor_C, LOW);
  digitalWrite(DC_Motor_D, LOW);
  analogWrite(DC_Motor_PWM, 0); // PWM sinyali ile hız kontrolü (255 maksimum hız)

  delay(2000);  // 2 saniye bekleme

  // Motorun İleri hareketi
  digitalWrite(DC_Motor_A, HIGH);
  digitalWrite(DC_Motor_B, LOW);
  digitalWrite(DC_Motor_C, HIGH);
  digitalWrite(DC_Motor_D, LOW);
  analogWrite(DC_Motor_PWM, 255); // PWM sinyali ile hız kontrolü (255 maksimum hız)
  
  delay(2000);  // 2 saniye bekleme

  // Motorun durması
  digitalWrite(DC_Motor_A, LOW);
  digitalWrite(DC_Motor_B, LOW);
  digitalWrite(DC_Motor_C, LOW);
  digitalWrite(DC_Motor_D, LOW);
  analogWrite(DC_Motor_PWM, 0); // PWM sinyali ile hız kontrolü (255 maksimum hız)

  delay(2000);  // 2 saniye bekleme

  // Motorun Geri hareketi
  digitalWrite(DC_Motor_A, LOW);
  digitalWrite(DC_Motor_B, HIGH);
  digitalWrite(DC_Motor_C, LOW);
  digitalWrite(DC_Motor_D, HIGH);
  analogWrite(DC_Motor_PWM, 255); // PWM sinyali ile hız kontrolü (255 maksimum hız)
  
  delay(2000);  // 2 saniye bekleme
}