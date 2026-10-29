#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
private:
    double maas = 3000000;
    string gizliMadde = "Serbest kalma bedeli 200 Milyon Euro";

public:
    string isim = "Victor Osimhen";

    // 1. FRIEND FONKSİYON BİLDİRİMİ
    // Bu fonksiyon sınıfın bir parçası DEĞİLDİR. Sadece dışarıdaki bir fonksiyona 
    // "Benim private kasama bakabilirsin" diye yetki veriyoruz.
    friend void tffDenetcisi(Futbolcu& f);

    // 2. FRIEND SINIF BİLDİRİMİ
    // "Menajer" adındaki başka bir sınıfın, bu sınıfın tüm gizli verilerine tam erişimini sağlıyoruz.
    friend class Menajer;
};

// --- Dışarıdaki Bağımsız Fonksiyon ---
// Dikkat et, Futbolcu:: diye başlamıyor çünkü sınıfın kendi metodu değil!
void tffDenetcisi(Futbolcu& f) {
    cout << "--- TFF Denetim Raporu ---" << endl;
    // Normalde f.maas yazmak HATA verirdi (private olduğu için). 
    // Ama 'friend' ilan edildiği için kapılar ona açık.
    cout << f.isim << " adli oyuncunun maasi: " << f.maas << " Euro\n" << endl;
}

// --- Dışarıdaki Başka Bir Sınıf ---
class Menajer {
public:
    void sozlesmeIncele(Futbolcu& f) {
        cout << "--- Menajer Islemleri ---" << endl;
        // Menajer, Futbolcu'nun 'friend' sınıfı olduğu için private verilere rahatça ulaşır.
        cout << "Gizli Madde: " << f.gizliMadde << endl;
        
        // Sadece okumakla kalmaz, doğrudan değiştirebilir de!
        f.maas += 500000;
        cout << "Menajer maasi artirdi. Yeni maas: " << f.maas << " Euro" << endl;
    }
};

int main() {
    cout << "--- Lesson 8: Friend Fonksiyon ve Friend Siniflar ---\n\n";

    Futbolcu oyuncu1;
    
    // Normal yollardan deneseydik:
    // cout << oyuncu1.maas; // HATA! Private verilere main() içinden ulaşılamaz.

    // 1. FRIEND FONKSİYON KULLANIMI
    tffDenetcisi(oyuncu1);

    // 2. FRIEND SINIF KULLANIMI
    Menajer Drogba;
    Drogba.sozlesmeIncele(oyuncu1);

    return 0;
}
