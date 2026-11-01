#include "sayac.h" // Sınıfın taslağını içeri çeker

// Kapsam çözünürlük operatörü (Sayac::) ile bu fonksiyonların 
// Sayac sınıfına ait olduğunu derleyiciye bildiriyoruz.
void Sayac::artir() {
    ++m_deger;
}

void Sayac::azalt() {
    // Sayacın eksiye düşmesini engelleyen sınır kontrolü
    if (m_deger > 0) {
        --m_deger;
    }
}

int Sayac::getDeger() const {
    return m_deger;
}
