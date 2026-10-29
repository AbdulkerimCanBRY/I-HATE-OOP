#include <iostream>
// Sadece başlık dosyasını çağırıyoruz, C++ arka planda Futbolcu.cpp'yi de bulup birleştirecek.
#include "Futbolcu.h" 

using namespace std;

int main() {
    cout << "--- Lesson 16: Sinif (Class) Kutuphanesi Nasil Olusturulur? ---\n\n";

    // Artık Futbolcu sınıfımız sanki C++'ın kendi özelliğiymiş gibi tertemiz çalışır.
    Futbolcu oyuncu1("Baris Alper Yilmaz", 85);
    
    oyuncu1.antrenmanYap();

    return 0;
}
