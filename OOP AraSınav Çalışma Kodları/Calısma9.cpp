#include <iostream>
#include <string>

class DinamikDizi{
    private:
    std::size_t m_boyut{0};
    int* m_veri{nullptr};

    public:

    explicit DinamikDizi(std::size_t boyut) : m_boyut{boyut} {
        m_veri = new int[m_boyut]{};
    }
    DinamikDizi(const DinamikDizi& diger){
        m_boyut = diger.m_boyut;
        m_veri = new int[m_boyut];
        for(std::size_t i = 0; i < m_boyut; ++i){
            m_veri[i] = diger.m_veri[i];
        }
    }
    ~DinamikDizi(){
        delete[] m_veri;
    }

    DinamikDizi& operator=(const DinamikDizi& diger){
        if(this == &diger){
            return *this;
        }
        delete[] m_veri;
        m_boyut = diger.m_boyut;
        m_veri = new int[m_boyut];
        for(std::size_t i = 0; i < m_boyut; ++i){
            m_veri[i] = diger.m_veri[i];
        }
        return *this;
    }
    int& operator[](std::size_t indeks){
        return m_veri[indeks];
    }

    const int& operator[](std::size_t indeks) const{
        return m_veri[indeks];
    }

    std::size_t boyut() const { return m_boyut; }
    void yazdir() const{
        for(std::size_t i = 0; i < m_boyut; ++i){
            std::cout << m_veri[i] << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    DinamikDizi d1{3};
    d1[0] = 10;
    d1[1] = 20; 
    d1[2] = 30;
    d1.yazdir();

    DinamikDizi d2{1};
    DinamikDizi d3{1};
    d3 = d2 = d1;

    d2[0] = 999;

    d1.yazdir();
    d2.yazdir();

    d1 = d1;
    d1.yazdir();
    
}