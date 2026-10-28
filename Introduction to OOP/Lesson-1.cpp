#include <iostream>
#include <string>

using namespace std;

// 1. CLASS (SINIF) OLUŞTURMA: Kendi veri tipimizi (şablonumuzu) yaratıyoruz.
// Bunu boş bir "Kek Kalıbı" veya "Karakter Yaratma Ekranı" gibi düşünebilirsin.
class OyunKarakteri {
  public: // public: Bu şablonun içindekilere dışarıdan (main içinden) doğrudan erişilebilir demek.
    
    // Karakterin özellikleri (Değişkenler)
    string isim;
    int seviye;

    // Karakterin yapabileceği bir eylem (Buna OOP'de Metot / Fonksiyon denir)
    void saldir() {
        cout << isim << " baltasini savurdu!" << endl;
    }
};

int main() {
    cout << "--- OOP'ye Basit Bir Giris ---\n\n";

    // 2. OBJECT (NESNE) ÜRETME: Şablondan gerçek ve canlı bir karakter çıkarıyoruz.
    // Kek kalıbından gerçek bir kek yapmak gibi.
    OyunKarakteri karakter1; 
    
    // 3. ÖZELLİKLERİ DOLDURMA: Araya nokta (.) koyarak karakterin özelliklerine ulaşıyoruz.
    karakter1.isim = "Yorick";
    karakter1.seviye = 5;

    // 4. BİLGİLERİ EKRANA YAZDIRMA
    cout << "Secilen Sampiyon: " << karakter1.isim << endl;
    cout << "Seviyesi: " << karakter1.seviye << "\n" << endl;

    // 5. METOT KULLANMA: Karakterin içindeki eylemi tetikliyoruz.
    karakter1.saldir();

    return 0;
}
