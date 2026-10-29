#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
public:
    string isim;
    int toplamGol;

    Futbolcu(string k_isim, int k_toplamGol) {
        isim = k_isim;
        toplamGol = k_toplamGol;
    }

    // 1. NORMAL METOT (Sabit değil)
    // Bu metot nesnenin içindeki bir değeri (toplamGol) değiştiriyor.
    void golAt() {
        toplamGol++;
        cout << isim << " muhtesem bir gol atti! Toplam: " << toplamGol << endl;
    }

    // 2. SABİT (CONST) METOT
    // Parantezden hemen sonra 'const' yazarak sisteme şu sözü veriyoruz: 
    // "Bu fonksiyon çalışırken hiçbir değişkeni değiştirmeyecek, sadece ekrana basacak."
    void efsaneYazdir() const {
        cout << "Efsane Oyuncu: " << isim << " | Kariyer Golleri: " << toplamGol << endl;
        
        // HATA VERİR: (Eğer alttaki yorumu kaldırırsan)
        // toplamGol = 999; 
        // Çünkü bu metot 'const' sözü verdi, ihanet edemez!
    }
};

int main() {
    cout << "--- Lesson 14: Sabit Nesneler ve Sabit Methodlar ---\n\n";

    // Aktif bir oyuncu (Normal Nesne)
    Futbolcu aktifOyuncu("Victor Osimhen", 99);
    aktifOyuncu.golAt();          // Sıkıntı yok, gol atabilir.
    aktifOyuncu.efsaneYazdir();   // Sıkıntı yok, const metotları herkes okuyabilir.

    cout << "-----------------------\n";

    // 3. SABİT NESNE (Emekli Efsane)
    // Bu nesnenin hiçbir özelliği bir daha dışarıdan DEĞİŞTİRİLEMEZ.
    const Futbolcu emekliEfsane("Metin Oktay", 217);

    // Sıkıntı yok, çünkü efsaneYazdir() metodu 'const'. Yani nesneyi değiştirmeyecek.
    emekliEfsane.efsaneYazdir(); 

    // HATA VERİR! (Eğer alttaki yorumu kaldırırsan kod çöker)
    // emekliEfsane.golAt(); 
    // Sebep: emekliEfsane 'const' kilitli bir nesnedir. golAt() metodu ise 'const' değildir. 
    // C++ "Bu metot efsanenin gol sayısını değiştirebilir, buna izin veremem!" der ve engeller.

    return 0;
}
