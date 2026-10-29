#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    
    // 1. STATİK ÖZELLİK (Sınıfa ait ortak kasa/bilgi)
    // Her nesnenin kendine ait bir kopyası olmaz, tüm nesneler bu tek değişkeni ortak kullanır.
    static int toplamOyuncuSayisi;
    static double transferButcesi;

    Futbolcu(string k_isim) {
        isim = k_isim;
        toplamOyuncuSayisi++; // Her yeni oyuncu yaratıldığında genel sayıyı 1 artırır
    }

    // 2. STATİK METOT
    // Nesne üretmeden doğrudan Sınıfın adıyla çağrılabilen eylemlerdir.
    // DİKKAT: Statik bir metot, SADECE statik değişkenleri okuyabilir/değiştirebilir!
    static void kulupRaporuVer() {
        cout << "--- YONETIM KURULU RAPORU ---" << endl;
        cout << "Kadro Genisligi: " << toplamOyuncuSayisi << " kisi" << endl;
        cout << "Kalan Transfer Butcesi: " << transferButcesi << " Euro\n" << endl;
        
        // HATA VERİR: cout << isim; 
        // C++ sorar: "Hangi futbolcunun ismi? Ben yönetime bakıyorum, kişileri tanımam!"
    }
};

// 3. STATİK DEĞİŞKENLERE İLK DEĞERİ ATAMA
// Statik değişkenlerin can suyu sınıfın dışında, main'den hemen önce verilir.
int Futbolcu::toplamOyuncuSayisi = 0;
double Futbolcu::transferButcesi = 15000000.0; // 15 Milyon Euro bütçe

int main() {
    cout << "--- Lesson 18: Statik Ozellikler ve Methodlar ---\n\n";

    // 4. STATİK METODU NESNESİZ KULLANMA
    // Ortada henüz hiçbir oyuncu yokken bile kulüp raporunu çekebiliriz.
    Futbolcu::kulupRaporuVer(); 

    // Transferleri yapıyoruz (Nesneleri yaratıyoruz)
    Futbolcu transfer1("Sara");
    Futbolcu transfer2("Jakobs");

    Futbolcu::transferButcesi -= 10000000.0; // Bütçeden para harcadık

    // Transferlerden sonra kulübün son durumu:
    Futbolcu::kulupRaporuVer();

    return 0;
}
