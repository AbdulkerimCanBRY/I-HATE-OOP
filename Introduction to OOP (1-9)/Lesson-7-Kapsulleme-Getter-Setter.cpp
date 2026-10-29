#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
private:
    // Dışarıdan doğrudan erişime kapalı, kapsüllenmiş veriler
    double maas;
    int kondisyon; 

public:
    string isim;

    // 1. GETTER METOTLARI (Veriyi Okuma)
    // Sadece içerideki gizli değeri dışarıya "return" (döndürme) ile verir. 
    // Değiştirme yetkisi yoktur, sadece bilgi verir.
    double getMaas() {
        return maas;
    }

    int getKondisyon() {
        return kondisyon;
    }

    // 2. SETTER METOTLARI (Veriyi Kurallı Değiştirme)
    // Dışarıdan gelen yeni değeri alır, bizim IF kurallarımızdan geçirir, uygunsa kaydeder.
    void setMaas(double yeniMaas) {
        if (yeniMaas < 0) {
            cout << "Hata: Futbolcuya eksi maas veremezsiniz! Islem iptal." << endl;
        } else {
            maas = yeniMaas;
            cout << isim << " adli oyuncunun maasi " << maas << " olarak guncellendi." << endl;
        }
    }

    void setKondisyon(int yeniKondisyon) {
        // Kondisyon 0'ın altına düşemez, 100'ün üstüne çıkamaz!
        if (yeniKondisyon > 100) {
            kondisyon = 100;
        } else if (yeniKondisyon < 0) {
            kondisyon = 0;
        } else {
            kondisyon = yeniKondisyon;
        }
    }
};

int main() {
    cout << "--- Lesson 7: Kapsulleme (Getter ve Setter) ---\n\n";

    Futbolcu oyuncu;
    oyuncu.isim = "Lucas Torreira";

    // HATA VERİR: oyuncu.maas = 2500000; (Çünkü private)
    
    // SETTER İLE DEĞER ATAMA (Kurallı Giriş)
    oyuncu.setMaas(2500000);
    oyuncu.setKondisyon(85);

    // GETTER İLE DEĞER OKUMA (Güvenli Çıkış)
    cout << "Guncel Maas: " << oyuncu.getMaas() << " Euro" << endl;
    cout << "Guncel Kondisyon: " << oyuncu.getKondisyon() << "\n" << endl;

    // KURAL İHLALİ DENEMESİ
    cout << "--- Kural Ihlali Denemesi ---\n";
    oyuncu.setMaas(-50000); // Kurala takılacak ve değişmeyecek
    
    // Gegenpress yorgunluğu: Kondisyonu abartılı düşürelim
    oyuncu.setKondisyon(-20); // Kurala takılacak ve 0'a sabitlenecek
    cout << "Zorlu mac sonu kondisyon: " << oyuncu.getKondisyon() << endl;

    return 0;
}
