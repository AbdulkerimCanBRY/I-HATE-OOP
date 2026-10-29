#include <iostream>
#include <string>

using namespace std;

// 1. SINIF TASARIMI (Taktik Tahtası)
// Sınıfın içini temiz tutuyoruz. Sadece oyuncunun neleri var ve neleri yapabilir, onu listeliyoruz.
class Futbolcu {
public:
    string isim;
    int formaNo;

    // Metotların sadece ismini (imzasını) yazıp noktalı virgülle bırakıyoruz. İçini doldurmuyoruz!
    void presYap(); 
    void sutCek(); 
};

// 2. METOTLARI SINIFIN DIŞINDA DOLDURMA (Antrenman Sahası)
// Bilgisayara bu metotların kafamıza göre bir fonksiyon olmadığını, 
// "Futbolcu" sınıfına ait olduğunu :: işareti ile söylüyoruz.

// Kural: DönüşTipi SınıfAdı::MetotAdı() { ... }
void Futbolcu::presYap() {
    cout << formaNo << " numarali " << isim << " rakip savunmaya amansiz bir Gegenpress yapiyor!" << endl;
}

void Futbolcu::sutCek() {
    cout << isim << " ceza sahasina girer girmez topu 90'a asti!" << endl;
}

int main() {
    cout << "--- Lesson 5: Sinif Tasariminda Methodlari Disari Tasima ---\n\n";

    Futbolcu oyuncu1;
    oyuncu1.isim = "Batrakov";
    oyuncu1.formaNo = 83;

    // Kullanımı tamamen aynı, değişen tek şey arka plandaki düzenimiz.
    oyuncu1.presYap();
    oyuncu1.sutCek();

    return 0;
}
