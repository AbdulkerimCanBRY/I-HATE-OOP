#include <iostream>
#include "sayac.h" // Sınıfı kullanabilmek için başlık dosyasını ekliyoruz

int main() {
    Sayac s; // Nesne oluşturuldu (m_deger = 0)

    s.artir(); // 1 oldu
    s.artir(); // 2 oldu
    s.azalt(); // 1'e düştü

    std::cout << "Guncel Sayac Degeri: " << s.getDeger() << '\n';

    return 0;
}
