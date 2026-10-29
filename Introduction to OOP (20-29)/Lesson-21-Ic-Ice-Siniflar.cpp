#include <iostream>
#include <string>

using namespace std;

// 1. ANA SINIF (Outer Class)
class Futbolcu {
public:
    string isim;

    // 2. İÇ İÇE SINIF (Inner / Nested Class)
    // Sadece bir futbolcuya ait olabilecek yepyeni bir şablonu ana sınıfın içine kuruyoruz.
    class Sozlesme {
    public:
        int maas;
        int bitisYili;
        bool bonusVarMi;

        void detayYazdir() {
            cout << "Maas: " << maas << " Euro | Bitis: " << bitisYili;
            if(bonusVarMi) cout << " (Gol Bonusu Icerir!)" << endl;
            else cout << endl;
        }
    };

    // Ana sınıfın içinde, az önce yukarıda yarattığımız şablondan bir 'nesne' üretiyoruz.
    Sozlesme menajerlikAnlasmasi;

    // Futbolcunun kurucu metodu
    Futbolcu(string k_isim, int k_maas, int k_bitis) {
        isim = k_isim;
        
        // İç içe sınıfın özelliklerine erişip içini dolduruyoruz
        menajerlikAnlasmasi.maas = k_maas;
        menajerlikAnlasmasi.bitisYili = k_bitis;
        menajerlikAnlasmasi.bonusVarMi = true; 
    }

    void oyuncuTanit() {
        cout << "--- OYUNCU PROFILI ---" << endl;
        cout << "Isim: " << isim << endl;
        
        // İç sınıfın (Sözleşmenin) kendi metodunu çağırıyoruz
        menajerlikAnlasmasi.detayYazdir();
        cout << "\n";
    }
};

int main() {
    cout << "--- Lesson 21: Ic Ice Siniflar (Nested Classes) ---\n\n";

    // Orijinal oyuncumuzu yaratıp bilgilerini veriyoruz. 
    // Biz sadece 3 bilgi veriyoruz, arka planda C++ sözleşmeyi kendi içinde organize ediyor.
    Futbolcu oyuncu1("Victor Osimhen", 6000000, 2028);
    oyuncu1.oyuncuTanit();

    // 3. DIŞARIDAN İÇ SINIF NESNESİ ÜRETME (Opsiyonel)
    // Eğer "Ben sadece boş bir sözleşme kağıdı (nesnesi) yaratmak istiyorum" dersen,
    // Çözünürlük operatörü (::) ile Futbolcu'nun içindeki Sozlesme'ye ulaşırsın.
    Futbolcu::Sozlesme bosKagit;
    bosKagit.maas = 50000;
    bosKagit.bitisYili = 2028;
    bosKagit.bonusVarMi = false;

    cout << "--- BOS SOZLESME TASLAGI ---" << endl;
    bosKagit.detayYazdir();

    return 0;
}
