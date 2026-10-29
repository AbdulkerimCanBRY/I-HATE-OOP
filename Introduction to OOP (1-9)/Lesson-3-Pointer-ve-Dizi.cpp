#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    int numara;

    void sahayaCik() {
        cout << "Forma No " << numara << ": " << isim << " sahada!" << endl;
    }
};

int main() {
    cout << "--- Lesson 3: Nesneleri Dizi ve Pointer Olarak Tanimlama ---\n\n";

    // 1. NESNELERİ DİZİ (ARRAY) OLARAK TANIMLAMA
    // Tek tek değişken oluşturmak yerine 3 kişilik bir takım listesi (dizi) açıyoruz.
    Futbolcu takim[3]; 

    takim[0].isim = "Ugurcan Cakir";
    takim[0].numara = 1;

    takim[1].isim = "Abdulkerim Bardakci";
    takim[1].numara = 42;

    takim[2].isim = "Torreira";
    takim[2].numara = 34;

    cout << "--- Takim Kadrosu (Dizi Kullanimi) ---\n";
    // Döngü sayesinde tek satır kodla bütün takımı sahaya sürüyoruz
    for(int i = 0; i < 3; i++) {
        takim[i].sahayaCik();
    }

    // 2. NESNELERİ POINTER (İŞARETÇİ) OLARAK TANIMLAMA
    // RAM'de dinamik olarak özel bir yer ayırmak için 'new' kelimesini kullanırız.
    cout << "\n--- Yildiz Transfer (Pointer Kullanimi) ---\n";

    Futbolcu* yildizOyuncu = new Futbolcu();

    // DİKKAT: Nesne pointer ise nokta (.) yerine ok (->) operatörü kullanılır!
    yildizOyuncu->isim = "Leao"; 
    yildizOyuncu->numara = 27;

    yildizOyuncu->sahayaCik();

    // 'new' ile yaratılan nesneler işimiz bitince bellekte çöp yapmasın diye silinmelidir.
    delete yildizOyuncu; 

    return 0;
}
