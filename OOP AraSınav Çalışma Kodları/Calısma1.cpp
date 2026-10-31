/*


#include <iostream>
using namespace std;

class BankaHesabi {
    private:
        double bakiye= 0.0;
    public:
        void paraYatir(double x){
            if (x>0)
            {
                bakiye = bakiye + x;
            }
            else
            {
                cout << "Para yatırma işlemi gerçekleştirilemedi"<< endl;
            }
        }
    public:
        void bakiyeGöseter(){
            cout << "Güncel Bakiye: " << bakiye << endl;
        }
};

int main(){
    BankaHesabi benimHesabim;
    benimHesabim.paraYatir(500);
    benimHesabim.paraYatir(-100);
    benimHesabim.bakiyeGöseter();
    return 0;
}


*/



/*


#include <iostream>
using namespace std;

class kahveMakinesi {
    private:
    int suMiktari = 0;
    int kahveMiktari = 0;

    public:
    void malzemeEkle(int su, int kahve){

        if (su > 0)
        {
            suMiktari = suMiktari + su;
        }
        else
        {
            cout << "Geçersiz miktar";
        }
        
        if (kahve > 0)
        {
            kahveMiktari = kahveMiktari + kahve;
        }
        else
        {
            cout << "Geçersiz miktar";
        }
    }
    void kahveYap(){

        if (suMiktari >= 200 && kahveMiktari >= 15)
        {
            suMiktari = suMiktari - 200 ;
            kahveMiktari = kahveMiktari - 15;

            cout << "Kahve Hazır." << endl;
        }
        else
        {
            cout << "Malzeme Eksikliği var." << endl;
        }
    }
    void stokGöstergesi (){
        cout << "Güncel su miktarı: " << suMiktari << endl;
        cout << "Güncel kahve miktarı: " << kahveMiktari << endl;
    }
        
};

int main(){
    kahveMakinesi makine;

    makine.kahveYap();

    makine.malzemeEkle(300,20);

    makine.kahveYap();
    makine.kahveYap();

    makine.stokGöstergesi();


}


*/
