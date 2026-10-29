#include <iostream>
#include <string>

using namespace std;

// 1. SINIF (CLASS) TANIMLAMA
// Sınıf bir fabrikadaki "üretim kalıbı" veya bir oyunun "karakter şablonu"dur.
// Tek başına hiçbir şey yapmaz, sadece neleri barındıracağını söyler.
class Futbolcu {
public: // public: Şimdilik herkes bu özelliklere dışarıdan erişebilsin diyoruz.
    
    // Özellikler (Değişkenler)
    string isim;
    string mevki;
    int kondisyon;
};

int main() {
    cout << "--- Lesson 1: Sinif ve Nesne Tanimlama ---\n\n";

    // 2. NESNE (OBJECT) ÜRETME
    // Kalıbı kullanarak bellekte (RAM) gerçekten yer kaplayan nesneler yaratıyoruz.
    Futbolcu oyuncu1;
    Futbolcu oyuncu2;

    // 3. ÖZELLİKLERE DEĞER ATAMA
    // Nokta (.) operatörünü kullanarak nesnenin içindeki boşlukları dolduruyoruz.
    oyuncu1.isim = "Batrakov";
    oyuncu1.mevki = "On Numara";
    oyuncu1.kondisyon = 75;

    oyuncu2.isim = "Baris Alper Yilmaz";
    oyuncu2.mevki = "Sag Acik";
    oyuncu2.kondisyon = 99; // 4-3-3 Gegenpress sistemine uygun yuksek kondisyon!

    // 4. BİLGİLERİ EKRANA YAZDIRMA
    cout << "1. Oyuncu: " << oyuncu1.isim << " | Mevki: " << oyuncu1.mevki << " | Kondisyon: " << oyuncu1.kondisyon << endl;
    cout << "2. Oyuncu: " << oyuncu2.isim << " | Mevki: " << oyuncu2.mevki << " | Kondisyon: " << oyuncu2.kondisyon << endl;

    return 0;
}
