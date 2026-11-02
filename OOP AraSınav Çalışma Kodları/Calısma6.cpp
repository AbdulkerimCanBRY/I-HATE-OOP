#include <iostream>
#include <string>

class SkorTablosu {
public:
    SkorTablosu(std::string oyuncu, std::size_t kapasite) 
        : m_oyuncu{std::move(oyuncu)}, m_kapasite{kapasite} 
    {
        m_skorlar = new int[m_kapasite]{};
        std::cout << "[Kurucu] " << m_oyuncu << " icin " 
                  << m_kapasite << " kapasiteli skor tablosu acildi.\n";
    }

    ~SkorTablosu() {
        delete[] m_skorlar; 
        std::cout << "[Yikici] " << m_oyuncu << " tablosunun bellegi silindi.\n";
    }

    SkorTablosu(const SkorTablosu& diger) 
        : m_oyuncu{diger.m_oyuncu + "_kopya"}, 
          m_kapasite{diger.m_kapasite}, 
          m_adet{diger.m_adet} 
    {
        m_skorlar = new int[m_kapasite]{};
        for (std::size_t i = 0; i < m_adet; ++i) {
            m_skorlar[i] = diger.m_skorlar[i]; 
        }
        std::cout << "[Kopya Kurucu] " << m_oyuncu << " olusturuldu.\n";
    }

    void skorEkle(int skor) {
        if (m_adet < m_kapasite) {
            m_skorlar[m_adet++] = skor;
            std::cout << m_oyuncu << " icin " << skor << " skoru eklendi.\n";
        } else {
            std::cout << m_oyuncu << " icin tablo dolu, skor eklenemedi!\n";
        }
    }

    void skorGuncelle(std::size_t index, int yeniSkor) {
        if (index < m_adet) {
            m_skorlar[index] = yeniSkor;
            std::cout << m_oyuncu << " nesnesinin " << index << ". indeksteki skoru guncellendi.\n";
        } else {
            std::cout << m_oyuncu << " icin gecersiz indeks!\n";
        }
    }

    void yazdir() const {
        std::cout << "  " << m_oyuncu << " [" << m_adet << "/" << m_kapasite << "]:";
        for (std::size_t i = 0; i < m_adet; ++i) {
            std::cout << ' ' << m_skorlar[i];
        }
        std::cout << '\n';
    }

private:
    std::string m_oyuncu;
    std::size_t m_kapasite{0};
    std::size_t m_adet{0};
    int* m_skorlar{nullptr};
}; 


int main() {
    std::cout << "1) Nesne olusturuluyor\n";
    SkorTablosu t1{"Ahmet", 3};
    t1.skorEkle(100);
    t1.skorEkle(200);
    t1.skorEkle(300);
    t1.yazdir();

    std::cout << "\n2) Kopya kurucu ile yeni nesne\n";
    SkorTablosu t2 = t1; 
    t2.yazdir();

    std::cout << "\n3) Bagimsizlik Testi (Derin Kopya Dogrulamasi)\n";
    t2.skorGuncelle(0, 999);

    std::cout << "Asil nesne : "; 
    t1.yazdir(); 
    std::cout << "Kopya nesne: "; 
    t2.yazdir(); 

    std::cout << "\n4) Program bitiyor (Yikicilar ters sirayla calisacak)\n";
    return 0;
}
