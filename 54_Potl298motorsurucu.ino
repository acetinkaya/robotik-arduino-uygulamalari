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

Kodun açıklaması: potansiyo metreden gelen adc sinyal değerlerinin
l298 motor sürücü üzerinde pwm hızının ayarlanarak dc motor sürme uygulaması

*/

int DC_Motor_PWM = 3; // Motor hız kontrol pini (PWM)
int DC_Motor_A = 11;  // Motor yön kontrol pini 11
int DC_Motor_B = 12;  // Motor yön kontrol pini 12

#define pot_pin A1   // Potansiyometre pinini tanımla

void setup()
 {
  // Pinlerin çıkış olarak ayarlanması
  pinMode(DC_Motor_PWM, OUTPUT);
  pinMode(DC_Motor_A, OUTPUT);
  pinMode(DC_Motor_B, OUTPUT);

  delay(100);

  digitalWrite(DC_Motor_A, LOW);
  digitalWrite(DC_Motor_B, LOW);
  delay(100);
}

void loop() 
{

  int pot_degeri = analogRead(pot_pin);  // Potansiyometre değerini oku
  int pwm_hizi = map(pot_degeri, 0, 1023, 0, 255);  //ADC 0 - 1023 to 0-255 pwm 

  // Motorun ileri yönde hareket etmesi
  digitalWrite(DC_Motor_A, HIGH);
  digitalWrite(DC_Motor_B, LOW);
  analogWrite(DC_Motor_PWM, pwm_hizi); // PWM sinyali ile hız kontrolü (255 maksimum hız)

  delay(100);  // 100 milisaniye bekleme

}