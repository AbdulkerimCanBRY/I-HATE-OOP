#include <iostream>
#include <string>

using namespace std;

class Futbolcu {
// 1. PUBLIC: Stadyumdaki herkesin görebildiği bilgiler.
public: 
    string isim = "Victor Osimhen";
    
    // Public bir metot, sınıfın içindeki gizli (private) bilgilere kendi içerisinden ulaşabilir!
    void maasZammıYap() {
        cout << isim << " icin yeni sozlesme gorusmeleri basladi..." << endl;
        maas += 500000; // Kendi içimizde olduğumuz için maaşı değiştirebiliyoruz.
        cout << "Yeni Maas: " << maas << " Euro\n" << endl;
    }

// 2. PRIVATE: Sadece kulüp yönetiminin bildiği gizli bilgiler.
private:
    double maas = 3000000; // Dışarıdan kimse bunu okuyamaz veya kafasına göre değiştiremez.

// 3. PROTECTED: Soyunma odası sırları. Dışarıya kapalıdır ama "altyapı" oyuncularına açıktır.
protected:
    string taktikSirri = "Hizli hucum ve Gegenpress"; 
};

int main() {
    cout << "--- Lesson 6: Erisim Belirtecleri (Public, Private, Protected) ---\n\n";

    Futbolcu oyuncu1;

    // PUBLIC: Hiçbir sorun yok, doğrudan okuyup değiştirebiliriz.
    cout << "Oyuncu Ismi: " << oyuncu1.isim << "\n" << endl;

    // HATA VERİR! (Eğer alt satırdaki yorumu kaldırırsan kod çalışmaz)
    // oyuncu1.maas = 9999999; 
    // Çünkü 'maas' PRIVATE. Dışarıdan müdahale edilemez, hile yapılamaz!

    // HATA VERİR!
    // cout << oyuncu1.taktikSirri; 
    // Çünkü 'taktikSirri' PROTECTED. Dışarıdan okunamaz.

    // Ancak public olan bir metot üzerinden, içerideki private/protected işlemleri güvenle tetikleyebiliriz:
    oyuncu1.maasZammıYap();

    return 0;
}
