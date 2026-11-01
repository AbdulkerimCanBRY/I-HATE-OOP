#include <iostream>
#include "lamba.h"

int main() {
    Lamba salonLambasi;

    salonLambasi.ac();
    salonLambasi.setParlaklik(85);

    std::cout << "Durum: " << salonLambasi.isAcik() << std::endl;
    std::cout << "Parlaklik: " << salonLambasi.getParlaklik() << std::endl;

    salonLambasi.kapat();
    std::cout << "Parlaklik (Kapali): " << salonLambasi.getParlaklik() << std::endl;

    return 0;
}
