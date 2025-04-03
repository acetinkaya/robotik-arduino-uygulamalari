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

Arduino Buzzer melodi uygulamasıdır. 

*/


int buzzer = 8; //Buzzerin bağlı olduğu arduino pini
int notaSayi = 8;
int Do = 262;
int Re = 294;
int Mi = 330;
int Fa = 349;
int Sol = 392;
int La = 440;
int Si = 494;
int Do_ = 523;
int notalar[] = {Do, Re, Mi, Fa, Sol, La, Si, Do_};
 
void setup()
{
  pinMode(buzzer,OUTPUT);
}
void loop()
{
    for (int i = 0; i < notaSayi; i++)
  {
    tone(buzzer, notalar[i]);
    delay(500);
    noTone(buzzer);
    delay(20);
  }
  noTone(buzzer);
}