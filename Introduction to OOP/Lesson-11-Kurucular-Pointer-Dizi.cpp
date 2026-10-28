#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
private:
    string isim;
    int formaNo;

public:
    // 1. VARSAYILAN KURUCU (Parametresiz)
    Futbolcu() {
        isim = "Altyapi Oyuncusu";
        formaNo = 99;
        cout << "[SISTEM] Varsayilan kurucu calisti: " << isim << " yaratildi." << endl;
    }

    // 2. PARAMETRELİ KURUCU
    Futbolcu(string isim, int formaNo) {
        this->isim = isim;
        this->formaNo = formaNo;
        cout << "[TRANSFER] Parametreli kurucu calisti: " << this->isim << " kadroda." << endl;
    }

    void goster() {
        cout << "Forma: " << formaNo << " - " << isim << endl;
    }
};

int main() {
    cout << "--- Lesson 11: Kurucu Metotlar Pointer ve Dizilerde Nasil Calisir ---\n\n";

    cout << "--- 1. DIZI (ARRAY) ILE KULLANIM ---\n";
    // Sadece 3 kişilik bir takım açtık. Değer vermediğimiz için
    // bilgisayar otomatik olarak 3 KERE varsayılan (parametresiz) kurucuyu çalıştırır!
    Futbolcu yedekKulubesi[3]; 

    cout << "\n--- 2. PARAMETRELI DIZI KULLANIMI ---\n";
    // Eğer diziyi yaratırken ilk 11'i kendimiz belirlemek istiyorsak:
    Futbolcu ilkOnBir[2] = {
        Futbolcu("Muslera", 1),
        Futbolcu("Davinson Sanchez", 6)
    };

    cout << "\n--- 3. POINTER (ISARETCI) ILE KULLANIM ---\n";
    // 'new' kelimesi RAM'de yer açarken, yanındaki parantezler anında kurucuyu tetikler.
    Futbolcu* yildizTransfer = new Futbolcu("Victor Osimhen", 9);
    
    // Pointer olduğu için özelliklere ok (->) ile ulaşıyoruz.
    yildizTransfer->goster();

    // RAM'i temizlemeyi unutmuyoruz.
    delete yildizTransfer; 

    return 0;
}
