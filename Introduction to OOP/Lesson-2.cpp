#include <iostream>
#include <string>

using namespace std;

// 1. CLASS (SINIF) Şablonumuz
class OyunKarakteri {
  public: 
    string isim;
    int seviye;

    // 2. YAPICI METOT (CONSTRUCTOR)
    // - Sınıfın adıyla BİREBİR AYNI isme sahip olmak zorundadır.
    // - Başına void, int, string vb. hiçbir şey yazılmaz.
    // - Yeni bir nesne (karakter) yaratıldığı anda OTOMATİK olarak SADECE BİR KERE çalışır.
    OyunKarakteri(string baslangicIsmi, int baslangicSeviyesi) {
        
        // Dışarıdan parantez içiyle gelen değerleri, karakterin kendi özelliklerine eşitliyoruz.
        isim = baslangicIsmi;
        seviye = baslangicSeviyesi;
        
        // Karakter yaratıldığı an ekrana bu yazı çıkacak.
        cout << "-- Sistem Mesaji: " << isim << " Vadi'ye inis yapti!" << endl;
    }

    // Karakterin standart eylemi
    void saldir() {
        cout << isim << " saldirdi!" << endl;
    }
};

int main() {
    cout << "--- OOP'ye Basit Giris 2: Yapici Metotlar ---\n\n";

    // 3. NESNE ÜRETİRKEN DEĞERLERİ VERME
    // Önceki derste boş bir karakter yaratıp, alt satırlarda içini dolduruyorduk.
    // Şimdi "Yapıcı Metot" sayesinde karakteri doğduğu an isimlendirip seviyesini veriyoruz.
    
    OyunKarakteri karakter1("Yorick", 5);
    OyunKarakteri karakter2("Garen", 1); 

    cout << "\n--- Karakter Bilgileri ---\n";
    cout << "1. Karakter: " << karakter1.isim << " | Seviye: " << karakter1.seviye << endl;
    cout << "2. Karakter: " << karakter2.isim << " | Seviye: " << karakter2.seviye << "\n" << endl;

    // Metotları test edelim
    karakter1.saldir();
    karakter2.saldir();

    return 0;
}
