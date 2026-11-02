#include <iostream>
#include <string>

class Savasci {
    private:
        std::string isim;
        int m_can;
        int m_guc;
    
    public:
        Savasci(std::string isim, int can, int guc) : isim{std::move(isim)}, m_can{can}, m_guc{guc}{}

        Savasci& hasarAl(int miktar) {
            m_can -= miktar;
            if (m_can < 0) m_can = 0;
            return *this;
        }

        Savasci& iksiric(int miktar) {
            m_can += miktar;
            return *this;
        }

        void durumYazdir() const {
            std::cout << isim << " - Can: " << m_can << ", Güç: " << m_guc << std::endl;
        }

        const Savasci& dahaGuclu(const Savasci& diger) const {
            if (m_guc > diger.m_guc) {
                return *this;
            } else {
                return diger;
            }
        }

};

int main() {
    Savasci s1{"Thor", 100, 85};
    Savasci s2{"Loki", 80, 90};

    s1.hasarAl(30).iksiric(10).durumYazdir();
    s1.dahaGuclu(s2).durumYazdir();

}