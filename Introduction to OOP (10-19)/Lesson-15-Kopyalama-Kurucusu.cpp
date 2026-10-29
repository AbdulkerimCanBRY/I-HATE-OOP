#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    int yetenek;

    // 1. NORMAL KURUCU (Constructor)
    Futbolcu(string k_isim, int k_yetenek) {
        isim = k_isim;
        yetenek = k_yetenek;
        cout << "[+] Orijinal oyuncu Vadi'ye... pardon sahaya indi: " << isim << endl;
    }

    // 2. KOPYALAMA KURUCUSU (Copy Constructor)
    // Kural: SinifAdi(const SinifAdi& orjinalNesne)
    // Neden referans (&) işareti var? Çünkü referans kullanmazsak, kopyalamak için 
    // bir kopyalama daha yapmaya çalışır ve sonsuz bir döngüye girip sistemi çökertir.
    // Neden 'const'? Kopyalarken yanlışlıkla orijinal oyuncunun verilerini bozmayalım diye.
    Futbolcu(const Futbolcu& orjinal) {
        
        // Orijinal nesnenin verilerini alıp, yeni ürettiğimiz nesneye atıyoruz ama biraz değiştiriyoruz.
        isim = orjinal.isim + " (Regen)"; 
        yetenek = orjinal.yetenek - 15; // Klonlar aslından biraz daha tecrübesiz başlar
        
        cout << "[C] Klonlama basarili! Yeni uretilen: " << isim << endl;
    }
};

int main() {
    cout << "--- Lesson 15: Kopyalama Kurucusu (Copy Constructor) ---\n\n";

    // Orijinal nesnemizi normal kurucu ile yaratıyoruz.
    Futbolcu asOyuncu("Dries Mertens", 85);
    
    cout << "\n--- Klonlama Islemi Basliyor ---\n";

    // 3. KOPYALAMA ANLARI
    // Bir nesneyi yaratırken ona başka bir nesneyi eşitlersen Copy Constructor tetiklenir.
    Futbolcu yedekOyuncu = asOyuncu; 
    
    // Veya parantez içinde doğrudan orijinali gönderirsen yine Copy Constructor çalışır.
    Futbolcu gencYetenek(asOyuncu);

    cout << "\n--- Son Durum ---\n";
    cout << "1. Oyuncu: " << asOyuncu.isim << " | Yetenek: " << asOyuncu.yetenek << endl;
    cout << "2. Oyuncu: " << yedekOyuncu.isim << " | Yetenek: " << yedekOyuncu.yetenek << endl;
    cout << "3. Oyuncu: " << gencYetenek.isim << " | Yetenek: " << gencYetenek.yetenek << endl;

    return 0;
}
