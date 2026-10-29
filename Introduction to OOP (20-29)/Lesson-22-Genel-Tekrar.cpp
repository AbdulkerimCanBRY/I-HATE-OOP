#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
// 1. PRIVATE: Sadece kulüp içi sırlar. Dışarıdan ulaşılamaz.
private:
    double maas;
    
    // İç İçe Sınıf (Nested Class): Sadece futbolcuya özel fiziksel rapor.
    class FizikselDurum {
    public:
        int kondisyon;
        bool sakatMi;
        // İç sınıfın kendi kurucusu
        FizikselDurum(int k) : kondisyon(k), sakatMi(false) {} 
    };
    
    // İç sınıftan bir nesne yaratıyoruz.
    FizikselDurum durum;

// 2. PUBLIC: Herkese açık özellikler ve yetenekler.
public:
    // Const (Sabit) Özellik: İsim bir kere verilir, bir daha değiştirilemez.
    const string isim; 
    string mevki;

    // Statik Özellik: Tüm takımı bağlayan, sınıfın geneline ait değer.
    static int takimMevcudu; 
    static double toplamMaasButcesi;

    // 3. KURUCU METOT (Constructor) & İLK DEĞER ATAMA LİSTESİ (Initializer List)
    // Const olan 'isim' ve iç sınıf olan 'durum' ancak burada başlatılabilir.
    Futbolcu(string k_isim, string k_mevki, double k_maas) : isim(k_isim), durum(100) 
    {
        mevki = k_mevki;
        maas = k_maas;
        
        // Statik değerleri güncelliyoruz (Takıma biri katıldı, bütçe etkilendi)
        takimMevcudu++;
        toplamMaasButcesi += maas;
        
        cout << "[KAP BILDIRIMI] " << isim << " Galatasaray'a transfer oldu!" << endl;
    }

    // 4. YIKICI METOT (Destructor)
    // Nesne bellekten silindiğinde otomatik çalışır.
    ~Futbolcu() {
        takimMevcudu--;
        toplamMaasButcesi -= maas;
        cout << "[AYRILIK] " << isim << " ile yollarimiz ayrildi. Emekleri icin tesekkurler." << endl;
    }

    // 5. GETTER (Kapsülleme) ve SABİT (Const) METOT
    // Metot const olduğu için sınıfın hiçbir özelliğini değiştiremez, sadece okuyup döndürür.
    double maasGoster() const {
        return maas;
    }

    // 6. NORMAL METOT: Oyun mekaniği
    void gegenpressYap() {
        if(durum.kondisyon >= 25 && !durum.sakatMi) {
            cout << "-> " << isim << " on alanda amansiz bir Gegenpress uyguluyor!" << endl;
            durum.kondisyon -= 25; // Yorulur
        } else {
            cout << "-> [UYARI] " << isim << " yorgunluktan pres yapamiyor, degisiklik lazim!" << endl;
        }
    }
    
    // Statik Metot: Sadece statik değişkenleri okuyabilen kulüp geneli raporu.
    static void yonetimRaporu() {
        cout << "\n--- YONETIM KURULU RAPORU ---" << endl;
        cout << "Kadro Genisligi: " << takimMevcudu << endl;
        cout << "Toplam Maas Yuku: " << toplamMaasButcesi << " Euro\n" << endl;
    }
};

// Statik değişkenlerin can suyu sınıfın dışında verilir.
int Futbolcu::takimMevcudu = 0;
double Futbolcu::toplamMaasButcesi = 0.0;

int main() {
    cout << "--- Lesson 22: Genel Tekrar ---\n\n";

    Futbolcu::yonetimRaporu(); // Henüz kimse yokken rapor alıyoruz.

    { // 1. Yarı: Kapsam (Scope) açıyoruz
        cout << "--- 1. YARI BASLADI ---\n";
        
        Futbolcu forvet("Victor Osimhen", "Santrafor", 6000000);
        Futbolcu sagAcik("Baris Alper Yilmaz", "Sag Kanat", 2000000);

        Futbolcu::yonetimRaporu(); // Transferlerden sonraki kulüp durumu

        // HATA VERİR: forvet.isim = "Baska Biri"; (Const çünkü)
        // HATA VERİR: forvet.maas = 999999; (Private çünkü)
        
        cout << forvet.isim << " maasi: " << forvet.maasGoster() << " Euro\n" << endl;

        forvet.gegenpressYap();
        sagAcik.gegenpressYap();
        sagAcik.gegenpressYap();
        sagAcik.gegenpressYap();
        sagAcik.gegenpressYap(); // 4. preste pili bitecek

        cout << "\n--- DEVRE ARASI (Oyuncu Degisikligi) ---\n";
        // Kapsam kapanırken buradaki nesneler RAM'den silinecek ve Destructor çalışacak!
    } 

    cout << "\n--- 2. YARI BASLADI ---\n";
    // Osimhen ve Barış bellekten temizlendi. Statik değişkenler otomatik düştü.
    Futbolcu::yonetimRaporu(); 

    return 0;
}
