#pragma once

class Sayac {
public:
    // Yalnızca fonksiyon imzaları (bildirimler / declarations) yer alır.
    // Gövdeler (.cpp dosyasına bırakılır) buraya yazılmaz.
    void artir();
    void azalt();
    int getDeger() const;

private:
    int m_deger{0}; // Başlangıç değeri 0 olan üye değişken
};
