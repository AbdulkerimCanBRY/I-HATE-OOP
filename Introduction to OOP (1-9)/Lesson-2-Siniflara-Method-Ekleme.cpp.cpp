#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public: 
    string isim;
    int kondisyon;

    // 1. METOT EKLEME (Parametresiz)
    // Sınıfın içine normal bir fonksiyon yazar gibi yazıyoruz.
    // Bu metot, oyuncunun kendi kondisyonunu değiştiriyor.
    void antrenmanYap() {
        kondisyon += 10; // Kondisyonu 10 artır
        cout << isim << " antrenman yapti. Yeni kondisyon: " << kondisyon << endl;
    }

    // 2. METOT EKLEME (Parametreli)
    // Dışarıdan bir bilgi (kime pas atılacağı) alarak işlem yapan metot.
    void pasVer(string kime) {
        cout << isim << ", " << kime << " isimli oyuncuya kilit bir pas atti!" << endl;
    }
};

int main() {
    cout << "--- Lesson 2: Siniflara Method Ekleme ve Kullanma ---\n\n";

    Futbolcu oyuncu1;
    oyuncu1.isim = "Batrakov";
    oyuncu1.kondisyon = 75;

    cout << "Baslangic Kondisyonu: " << oyuncu1.kondisyon << "\n" << endl;

    // 3. METOT KULLANMA
    // Nesnenin adını yazıp nokta (.) koyduktan sonra eylemi (metodu) çağırıyoruz.
    oyuncu1.antrenmanYap(); 
    
    // Parametre isteyen metoda parantez içinde değer gönderiyoruz.
    oyuncu1.pasVer("Osimhen"); 

    return 0;
}
