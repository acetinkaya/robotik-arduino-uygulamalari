%EEM108 Ders içi uygulamasıdır. Matlab programı üzerinde arduino nano üzerinde 
% yerleşik olan iki sensörlerinden (dth11 ve mq2) gelen verileri
% matlab ortamında görselleştirilmesinin sağlayabilmek bu kodun ana görevidir. 
% İlgili matlab kodu ve arduino üzerinde çalıştırılan kodlar;
% https://github.com/acetinkaya/robotik-arduino-uygulamalari/ github
% alanında 60. örnek olarak Öğr. Gör. Ali ÇETİNKAYA tarafından eklenmiştir.
% Açık kaynak bilgi paylaşımını destekleyin arkadaşlar. Bilgi paylaşıldıkça
% artan bir kavramdır. İyi çalışmalar dilerim.

comport = serialport("COM11", 115200); % Seri bağlantı portunu tanımla
fopen(comport); % Seri portu aç

zamanaraligi = 100; % çalışma saniye aralığı

% Seri Porttan Gelen verilerin tutulacağı dizilerini tanımlanma işlemi
y = zeros(1, zamanaraligi); % Sıcaklık Verisi
z = zeros(1, zamanaraligi); % Nem Verisi
k = zeros(1, zamanaraligi); % Gaz Verisi
 
% Sıcaklık ve Nem verileri için Şekil 1 oluşturuluyor
figure;
subplot(2, 1, 1);

% Gaz verisi için Şekil 2 oluşturuluyor
subplot(2, 1, 2);
% Arduino seri porttan sürekli olarak veri al ve görselleştir
for i = 1:zamanaraligi
    % Arduino'dan veri oku
    y(i) = fscanf(comport, '%d');
    z(i) = fscanf(comport, '%d');
    k(i) = fscanf(comport, '%d');
    
    % Alınan veriyi ekrana yazdır
    fprintf('Sıcaklık: %d\n', y(i));
    fprintf('Nem: %d\n', z(i));
    fprintf('Gaz: %d\n', k(i));
    
    % Şekil 1 için grafiği çiz
    subplot(2, 1, 1);
    plot(1:i, y(1:i), 'r', 'LineWidth', 2); % Sıcaklık
    hold on;
    plot(1:i, z(1:i), 'y', 'LineWidth', 2); % Nem
    hold off;
    xlabel('Çalışma Zaman Aralığı (100 Saniye)');
    ylabel('DTH11 - Isı ve Nem Sensörü');
    title('Isı ve Nem Verileri');
    legend('Sıcaklık', 'Nem');
    
    % Şekil 2 için grafiği çiz
    subplot(2, 1, 2);
    plot(1:i, k(1:i), 'g', 'LineWidth', 2); % Gaz
    xlabel('Çalışma Zaman Aralığı (100 Saniye)');
    ylabel('MQ2 - Gaz Sensörü Verisi');
    title('LPG Gaz Verisi');
    legend('Gaz');
    
    % Çizim işlemleri için 100 milisaniye beklet
    pause(0.1);
end

% Seri portu kapat
fclose(comport);
% Seri port nesnesini siliyoruz.
delete(comport);