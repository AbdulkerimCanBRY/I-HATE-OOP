// Taktik tahtamızı bu dosyaya dahil ediyoruz (Kendi dosyamız olduğu için tırnak " " içinde yazılır)
#include "Futbolcu.h" 
#include <iostream>

using namespace std;

// Sınıfın adını (Futbolcu::) kullanarak metotların içini dolduruyoruz (İmplementasyon)
Futbolcu::Futbolcu(string k_isim, int k_kondisyon) {
    isim = k_isim;
    kondisyon = k_kondisyon;
}

void Futbolcu::antrenmanYap() {
    kondisyon += 10;
    cout << isim << " antrenmanini tamamladi. Yeni Kondisyon: " << kondisyon << endl;
}
