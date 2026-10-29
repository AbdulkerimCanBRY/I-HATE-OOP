#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    int kondisyon;
    
    // 1. SABİT (CONST) ÖZELLİKLER
    // Başına const koyduğumuz an bu değerler bir daha asla değiştirilemez.
    const int dogumYili;
    const int lisansNo;

    // 2. İLK DEĞER ATAMA LİSTESİ (Initializer List)
    // Const değişkenlere değer atamanın TEK YOLU budur. 
    // Kurucu metodun parantezi bittikten hemen sonra iki nokta (:) koyarız ve atamaları yaparız.
    Futbolcu(string k_isim, int k_dogumYili, int k_lisansNo) : dogumYili(k_dogumYili), lisansNo(k_lisansNo) 
    {
        // Normal (sabit olmayan) değişkenleri eskisi gibi içeride atayabiliriz.
        isim = k_isim;
        kondisyon = 100;
    }

    void profilGoster() {
        cout << "Oyuncu: " << isim << endl;
        cout << "Dogum Yili: " << dogumYili << " (Degistirilemez)" << endl;
        cout << "Lisans No: " << lisansNo << " (Degistirilemez)" << endl;
        cout << "Kondisyon: " << kondisyon << "\n" << endl;
    }
};

int main() {
    cout << "--- Lesson 13: Siniflarin Sabit (const) Ozellikleri ---\n\n";

    // Nesneyi yaratırken sabit değerleri veriyoruz. (1998 doğum yılı, 1905 lisans no)
    Futbolcu oyuncu1("Victor Osimhen", 1998, 1905);
    
    oyuncu1.profilGoster();

    // 3. DEĞİŞTİRME DENEMELERİ
    
    // Normal değişkenler sorunsuz değişir:
    oyuncu1.kondisyon = 85; 
    
    // HATA VERİR! (Yorumu kaldırırsan kod çalışmaz)
    // oyuncu1.dogumYili = 2000; 
    // HATA VERİR!
    // oyuncu1.lisansNo = 9999;
    
    cout << "Guncel Kondisyon: " << oyuncu1.kondisyon << endl;

    return 0;
}
