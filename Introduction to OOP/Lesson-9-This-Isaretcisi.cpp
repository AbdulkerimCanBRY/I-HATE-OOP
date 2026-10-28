#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
private:
    string isim;
    int formaNo;

public:
    // SETTER METODU
    // Dikkat: Parametre isimleri (isim, formaNo), sınıfın kendi özellikleriyle birebir aynı!
    void setBilgiler(string isim, int formaNo) {
        
        // isim = isim; // BÖYLE YAZARSAK HATA OLMAZ AMA MANTIK ÇÖKER. C++ parametreyi yine parametreye eşitler.
        
        // DOĞRU KULLANIM:
        // this-> kelimesi "Bu nesnenin kendi özelliği olan" anlamına gelir.
        // Sağ taraftaki yalın 'isim' ise dışarıdan gelen parametredir.
        this->isim = isim; 
        this->formaNo = formaNo;
    }

    void kendiniTanit() {
        // 'this->' kullanmak zorunlu değildir ama okunabilirliği artırır.
        // "Benim ismim, benim forma numaram" demiş oluyoruz.
        cout << "Ben " << this->isim << ", Forma Numaram: " << this->formaNo << endl;
    }
};

int main() {
    cout << "--- Lesson 9: Siniflardaki This Isaretcisi (Pointer) ---\n\n";

    Futbolcu oyuncu1;
    
    // Dışarıdan değerleri gönderiyoruz.
    oyuncu1.setBilgiler("Leroy Sane", 10);
    
    oyuncu1.kendiniTanit();

    return 0;
}
