#pragma once 
// #pragma once: Bu dosyanın projede sadece bir kere kopyalanmasını sağlar. Hataları önler.

#include <string>

// Kural: Başlık (.h) dosyalarında ASLA "using namespace std;" yazılmaz. 
// Bu yüzden string'in başına std:: ekliyoruz.

class Futbolcu {
public:
    std::string isim;
    int kondisyon;

    // Metotların sadece ismini yazıp bırakıyoruz (Deklarasyon)
    Futbolcu(std::string k_isim, int k_kondisyon); 
    void antrenmanYap();
};
