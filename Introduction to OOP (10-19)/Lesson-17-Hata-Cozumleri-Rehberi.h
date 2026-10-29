// 1. DÜŞMAN: MULTIPLE DEFINITION (Çoklu Tanımlama) HATASI
// Eğer projede birden fazla dosya yanlışlıkla "Futbolcu.h" dosyasını çağırırsa,
// C++ aynı futbolcuyu iki kere yaratmaya çalışır ve çöker.
// Bunu önlemenin modern yolu en üste "#pragma once" yazmaktır.
#pragma once 

// Ancak daha eski ve garantili bir sektör standardı olan "Include Guard" şöyledir:
// Okunuşu: Eğer FUTBOLCU_H tanımlanmadıysa (ifndef), onu tanımla (define).
#ifndef FUTBOLCU_H
#define FUTBOLCU_H

#include <string>

class Futbolcu {
public:
    std::string isim;
    void antrenmanYap();
};

#endif // Kapsama korumasının sonu. Dosya 10 kere bile include edilse, 
       // ilk seferde tanımlandığı için diğerlerini es geçer ve çökmez.



/*

2. DÜŞMAN: UNDEFINED SYMBOLS FOR ARCHITECTURE (Linker Hatası)
Sebebi: VS Code'daki Play tuşunun sadece açık olan 'main.cpp' dosyasını derlemesi,
metotların içinin dolu olduğu 'Futbolcu.cpp' dosyasını unutmasıdır. C++ parçaları birleştiremez.

ÇÖZÜM: VS Code Terminalini Aç ve Manuel Derle
---------------------------------------------------------
Adım 1 (Derleme) : g++ main.cpp Futbolcu.cpp -o oyun
Adım 2 (Çalıştırma): ./oyun
---------------------------------------------------------

3. DÜŞMAN: DOSYA İSİMLERİNDEKİ BOŞLUK VE RAKAMLAR
Sebebi: "1. Futbolcu.h" gibi isimlendirmeler C++ kütüphane çağrılarında (include) 
sistemin dosyayı bulamamasına yol açar.
Çözüm: Sınıf isimleri her zaman büyük harfle başlar ve eklentisiz, tertemiz yazılır 
(Örn: Futbolcu.h ve Futbolcu.cpp).

*/
