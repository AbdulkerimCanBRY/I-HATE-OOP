/*


#include <iostream>

void puanGuncelle(int& x, int y = 10){
    x = x + y;
}

void puanGuncelle(int& x, double carpan){
    x = carpan * x;
}

int main(){
    int x ={50};

    puanGuncelle(x);

    std::cout << "değer: " << x << std::endl;

    puanGuncelle(x , 20);

    std::cout << "değer: " << x << std::endl;

    puanGuncelle(x, 1.5);

    std::cout << "değer: " << x << std::endl;

}


*/




/*


#include <iostream>

namespace kargo{

    struct Paket
    {
        std::string alici;
        int desi;
        bool TeslimEdildi = false;
    };

    int teslimEt(Paket& p){

        static int teslimatSayaci{0};

        p.TeslimEdildi = true;

        teslimatSayaci = teslimatSayaci + 1;

        return teslimatSayaci;
    };

    void durumYazdir(const Paket& p){
        std::cout << "Alici Adı: " << p.alici << std::endl;
        std::cout << "Desi: " << p.desi << std::endl;
        std::cout << "Durum: " << p.TeslimEdildi << std::endl;
    };
}
    int main() {
        kargo::Paket ahmet{"Ahmet Yilmaz", 3, false};
        kargo::Paket mehmet{"Mehmet Demir", 5, false};


        kargo::durumYazdir(ahmet);
        kargo::durumYazdir(mehmet);

        std::cout << "Güncel Teslimat: " << kargo::teslimEt(ahmet) << std::endl;
        std::cout << "Güncel Teslimat: " << kargo::teslimEt(mehmet) << std::endl;
        
        kargo::durumYazdir(ahmet);
        kargo::durumYazdir(mehmet);
    }


*/
    
