#include <iostream>
#include <string>

class Sure {

    private:
        int m_dakika{0};
        int m_saniye{0};
        void düzenle() {
        
            if (m_saniye >= 60) {
                m_dakika += m_saniye / 60;
                m_saniye %= 60;
            }
        }
    public:
        Sure(int dakika = 0, int saniye = 0) : m_dakika(dakika), m_saniye(saniye) {
            düzenle();
        }

        Sure operator+(const Sure& diger) const {
        
            Sure toplam;
            toplam.m_dakika = m_dakika + diger.m_dakika;
            toplam.m_saniye = m_saniye + diger.m_saniye;
            toplam.düzenle();
            return toplam;
        }

        Sure& operator+=(const Sure& diger){
            
            m_dakika += diger.m_dakika;
            m_saniye += diger.m_saniye;
            düzenle();
            return *this;
        }

        bool operator==(const Sure& diger) const {
            return (m_dakika == diger.m_dakika) && (m_saniye == diger.m_saniye);
        }

        Sure& operator++() {
            ++m_saniye;
            düzenle();
            return *this;
        }

        Sure operator++(int) {
            Sure temp = *this;
            ++(*this);
            return temp;
        }

        friend std::ostream& operator<<(std::ostream& os, const Sure& s) {
            os << s.m_dakika << " dakika " << s.m_saniye << " saniye";
            return os;
        }
    
};

int main() {
    Sure s1(2, 45);
    Sure s2(1, 30);
    std::cout << "s1: " << s1 << " | s2: " << s2 << std::endl;

    Sure toplam = s1 + s2;
    std::cout << "Toplam: " << toplam << std::endl;

    s1 += s2;
    std::cout << "s1 += s2: " << s1 << std::endl;

    Sure s3(0, 59);
    s3++;
    std::cout << "s3 after post-increment: " << s3 << std::endl;

    ++s3;
    std::cout << "s3 after pre-increment: " << s3 << std::endl;
    
}