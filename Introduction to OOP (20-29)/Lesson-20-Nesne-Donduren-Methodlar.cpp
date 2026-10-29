#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    int kondisyon;

    Futbolcu(string k_isim, int k_kondisyon) {
        isim = k_isim;
        kondisyon = k_kondisyon;
    }

    // 1. NESNE DÖNDÜREN METOT
    // Metodun dönüş tipine dikkat: void, int veya string değil, doğrudan "Futbolcu".
    // Bu demek oluyor ki bu fonksiyon işi bittiğinde bize bir "Futbolcu nesnesi" teslim edecek.
    Futbolcu ozelKampaGir() {
        cout << isim << " 1 aylik ozel antrenman kampina alindi..." << endl;
        
        // Metodun içinde yepyeni bir nesne (eski oyuncunun güncellenmiş klonunu) yaratıyoruz.
        // İsminin sonuna not ekliyor ve kondisyonunu fullüyoruz.
        Futbolcu kampGormusVersiyon(isim + " (Prime)", 100);
        
        // 2. NESNEYİ DIŞARI FIRLATMA
        // Yarattığımız bu yeni nesneyi main fonksiyonuna gönderiyoruz.
        return kampGormusVersiyon; 
    }
};

int main() {
    cout << "--- Lesson 20: Nesne Donduren Methodlar ---\n\n";

    // Orijinal oyuncumuzu yaratıyoruz, kondisyonu düşük.
    Futbolcu yorgunOyuncu("Leroy Sane", 40);
    
    cout << "Kampa Gitmeden Once: " << yorgunOyuncu.isim << " | Kondisyon: " << yorgunOyuncu.kondisyon << "\n" << endl;

    // 3. DÖNEN NESNEYİ YAKALAMA
    // yorgunOyuncu kampa giriyor. Kamp bittiğinde metot bize YENİ bir nesne fırlatıyor.
    // Biz de o fırlatılan nesneyi havada yakalayıp "primeOyuncu" adında yeni bir değişkene atıyoruz.
    Futbolcu primeOyuncu = yorgunOyuncu.ozelKampaGir();

    cout << "\nKampa Gittikten Sonra:" << endl;
    
    // Eski oyuncu hala yorgun (çünkü o kampa girmeden önceki halini temsil ediyor)
    cout << "Eski Kart: " << yorgunOyuncu.isim << " | Kondisyon: " << yorgunOyuncu.kondisyon << endl;
    
    // Yeni oyuncu ise metodun içinden fırlatılan Prime versiyon!
    cout << "Yeni Kart: " << primeOyuncu.isim << " | Kondisyon: " << primeOyuncu.kondisyon << endl;

    return 0;
}
