#include <iostream>
#include <string>

// using namespace std; // Bunu bilerek yoruma aldık, alt tarafta std:: nasıl kullanılır görmek için.

// 1. BİRİNCİ İSİM UZAYI (Kulüp / Klasör gibi düşün)
namespace Galatasaray {
    class Futbolcu {
    public:
        std::string isim = "Mauro Icardi";
        void golSevinci() {
            std::cout << isim << ": Askin Olayim!" << std::endl;
        }
    };
}

// 2. İKİNCİ İSİM UZAYI
// Aynı "Futbolcu" isminde yepyeni bir sınıf açıyoruz ama sistem hata vermiyor. 
// Çünkü bu Futbolcu sınıfı "RealMadrid" isim uzayının içinde yaşıyor.
namespace RealMadrid {
    class Futbolcu {
    public:
        std::string isim = "Arda Guler";
        void golSevinci() {
            std::cout << isim << ": Hala Madrid!" << std::endl;
        }
    };
}

int main() {
    std::cout << "--- Lesson 4: Isim Uzaylari (Namespaces) ---\n\n";

    // 3. İSİM UZAYINDAN NESNE ÜRETME
    // Hangi Futbolcu sınıfını kullanacağımızı :: (Çözünürlük Operatörü) ile belirtiyoruz.
    // Okunuşu: Galatasaray'ın içindeki Futbolcu sınıfı.
    Galatasaray::Futbolcu gsOyuncusu;
    RealMadrid::Futbolcu rmOyuncusu;

    gsOyuncusu.golSevinci();
    rmOyuncusu.golSevinci();

    // NOT: cout, endl ve string aslında C++'ın 'std' (Standart) isim uzayının içindedir.
    // Her defasında başlarına std:: yazmamak için kodun en başına "using namespace std;" yazarız
    // ve "bütün kod boyunca standart isim uzayını kullan" diyerek kendimizi amelelikten kurtarırız.

    return 0;
}
