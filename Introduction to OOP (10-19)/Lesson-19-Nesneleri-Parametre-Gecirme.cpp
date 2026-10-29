#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    int golSayisi;

    Futbolcu(string k_isim) {
        isim = k_isim;
        golSayisi = 0;
    }

    // 1. NESNEYİ METODA PARAMETRE OLARAK VERME
    // Metodun içine (Futbolcu& takimArkadasasi) yazarak, bu metodun 
    // çalışması için dışarıdan başka bir Futbolcu nesnesine ihtiyacı olduğunu söylüyoruz.
    // & (Referans) işareti: "Oyuncunun klonunu değil, GERÇEK kendisini getir" demektir.
    void asistYap(Futbolcu& takimArkadasasi) {
        cout << isim << " ceza sahasina harika bir orta acti!" << endl;
        
        // Gelen nesnenin (Osimhen'nin) kendi metodunu tetikliyoruz.
        takimArkadasasi.golAt(); 
    }

    void golAt() {
        golSayisi++;
        cout << "[GOL] " << isim << " topu aglara gonderdi! Toplam Gol: " << golSayisi << "\n" << endl;
    }
};

int main() {
    cout << "--- Lesson 19: Methodlara Nesneleri Parametre Gecirme ---\n\n";

    Futbolcu oyuncu1("Batrakov");
    Futbolcu oyuncu2("Osimhen");

    // Batrakov topu alıyor ve metoda Osimhen NESNESİNİ fırlatıyor.
    oyuncu1.asistYap(oyuncu2);

    // Bir asist daha yapsın
    oyuncu1.asistYap(oyuncu2);

    cout << "--- MAC SONU ISTATISTIKLERI ---" << endl;
    cout << oyuncu2.isim << " Toplam Gol: " << oyuncu2.golSayisi << endl;

    return 0;
}
