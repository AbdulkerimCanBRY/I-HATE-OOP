#include <iostream>
#include <string>

class HasarHesaplayici {
    private:
        double m_carpan{1.0};
        mutable int m_hesaplamaSayisi{0};

    public:
        explicit HasarHesaplayici(double carpan) : m_carpan(carpan) {}

        double operator()(int tabanHasar) const {
            ++m_hesaplamaSayisi;
            return tabanHasar * m_carpan;
        }

        double operator()(int tabanHasar, int kritikEk) const {
            ++m_hesaplamaSayisi;
            return (tabanHasar + kritikEk) * m_carpan;
        }

        int getHesaplamaSayisi() const {
            return m_hesaplamaSayisi;
        }
};

int main() {
    HasarHesaplayici normalVurus{1.0};
    HasarHesaplayici atesTopu{1.5};

    normalVurus(100);
    std::cout << "Normal vurus hasari: " << normalVurus(100) << std::endl;

    atesTopu(100);
    std::cout << "Ates topu hasari: " << atesTopu(100) << std::endl;

    atesTopu(100, 50);
    std::cout << "Ates topu kritik hasari: " << atesTopu(100, 50) << std::endl;

    atesTopu.getHesaplamaSayisi();
}