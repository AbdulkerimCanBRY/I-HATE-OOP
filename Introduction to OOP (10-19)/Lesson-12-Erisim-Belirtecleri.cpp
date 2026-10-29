#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;

    // 1. KURUCU (CONSTRUCTOR) - Nesne doğarken çalışır
    Futbolcu(string k_isim) {
        isim = k_isim;
        cout << "[+] " << isim << " sahaya ayak basti!" << endl;
    }

    // 2. YIKICI (DESTRUCTOR) - Nesne ölürken / silinirken çalışır
    // Görevi genelde çöp toplamaktır (Pointer kullandıysak 'delete' işlemleri burada yapılır)
    ~Futbolcu() {
        cout << "[-] " << isim << " dusunu aldi ve stadyumdan ayrildi." << endl;
    }
};

int main() {
    cout << "--- Lesson 12: Yikici (Destructor) Methodlar ---\n\n";

    cout << "--- 1. YARI BASLADI ---\n";
    Futbolcu kaleci("Uğurcan"); 

    // Süslü parantezlerle yeni bir 'Kapsam' (Scope) açıyoruz.
    // Bu parantezlerin içinde yaratılan nesneler, parantez kapandığı an ölür.
    {
        cout << "\n--- 60. DAKIKA: OYUNCU DEGISIKLIGI ---\n";
        Futbolcu yedekOyuncu("Victor Osimhen");
        cout << "Osimhen kafa vurusunu yapti ama top direkten dondu...\n";
        
    } // DİKKAT: Süslü parantez bitti. Yedek oyuncunun ömrü doldu! 
      // (Osimhen için Yıkıcı Metot tam bu satırda otomatik çalışır)

    cout << "\n--- 90. DAKIKA: MAC BITTI ---\n";

    // Program 'return 0' ile tamamen kapanırken, bellekte kalan son nesne olan 
    // Uğurcan da RAM'den silinir ve onun da Yıkıcı Metodu otomatik olarak ateşlenir.
    return 0;
}
