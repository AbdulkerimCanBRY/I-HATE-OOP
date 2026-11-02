#include <iostream>

class Karakter{
    public:
    Karakter(std::string isim, int seviye) : m_isim{isim}, m_seviye{seviye}, m_id{s_siradakiId++} {
        s_aktifSayi++;
        std::cout << m_isim << " oyuna katıldı." << std::endl;
    }

    explicit Karakter(std::string isim) : Karakter(isim, 1) {}

    ~Karakter() {
        --s_aktifSayi;
        std::cout << m_isim << " oyundan ayrıldı." << std::endl;
    }

    void yazdir() const {
        std::cout << "Karakter: " << m_isim << ", Seviye: " << m_seviye << ", ID: " << m_id << std::endl;
    }

    static int getAktifSayi() {
        return s_aktifSayi;
    }



    private:
    const std::string m_isim;
    int m_seviye;
    int m_id;
    inline static int s_aktifSayi{0};
    inline static int s_siradakiId{1001};

};

int main() {
    Karakter::getAktifSayi();
    Karakter k1{"Savasci", 15};

    k1.yazdir();

    Karakter k2{"Buyucu"};
    k2.yazdir();

    std::cout << "\nSu an aktif: " << Karakter::getAktifSayi() << "\n\n";

    // --- GECICI IC BLOK BASLANGICI ---
    {
        Karakter k3{"Gecici Karakter"};
        k3.yazdir();
        std::cout << "Blok icinde aktif sayi: " << Karakter::getAktifSayi() << '\n';
    } 
    // --- GECICI IC BLOK BITTI ---
    // Bu suslu parantez kapandigi an k3 yok olur ve ~Karakter() calisir!

    std::cout << "\nBlok kapandiktan sonra aktif sayi: " << Karakter::getAktifSayi() << "\n\n";

    return 0;
}