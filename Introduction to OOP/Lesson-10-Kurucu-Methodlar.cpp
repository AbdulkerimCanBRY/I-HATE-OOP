#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
private:
    string isim;
    int formaNo;
    int kondisyon;

public:
    // 1. VARSAYILAN KURUCU (Default Constructor)
    // Eğer nesne üretirken parantez içine hiçbir şey yazmazsak bu metot çalışır.
    Futbolcu() {
        isim = "Altyapi Oyuncusu";
        formaNo = 99;
        kondisyon = 50;
        cout << "-- Sistem: Isimsiz bir oyuncu kampa katildi." << endl;
    }

    // 2. PARAMETRELİ KURUCU (Parameterized Constructor)
    // Nesne üretilirken dışarıdan özellikleri anında gönderdiğimiz metot.
    // Geçen derste öğrendiğimiz 'this' işaretçisini burada isim çakışmasını önlemek için kullanıyoruz.
    Futbolcu(string isim, int formaNo, int kondisyon) {
        this->isim = isim;
        this->formaNo = formaNo;
        this->kondisyon = kondisyon;
        cout << "-- Transfer Haberi: " << this->isim << " resmen kadroda!" << endl;
    }

    void bilgileriGoster() {
        cout << "Oyuncu: " << isim << " | Forma No: " << formaNo << " | Kondisyon: " << kondisyon << "\n" << endl;
    }
};

int main() {
    cout << "--- Lesson 10: Kurucu (Constructor) Methodlar ---\n\n";

    // 1. Varsayılan (Parametresiz) kullanım: 
    // Parantez açıp değer göndermediğimiz için ilk kurucu metot çalışır.
    Futbolcu gencOyuncu; 
    gencOyuncu.bilgileriGoster();

    // 2. Parametreli kullanım: 
    // Nesne doğduğu an bütün özellikleri tek satırda doldurulur. İkinci kurucu metot çalışır.
    Futbolcu yildizOyuncu("Victor Osimhen", 9, 95);
    yildizOyuncu.bilgileriGoster();

    return 0;
}
