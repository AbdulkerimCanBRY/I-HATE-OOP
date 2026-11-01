#include "lamba.h"

void Lamba::ac(){
    m_acikMi = true;
    if (m_parlaklik == 0)
    {
        m_parlaklik = 50;
    }
};
void Lamba::kapat(){
    m_acikMi = false;
    m_parlaklik = 0;
};

void Lamba::setParlaklik(int seviye){
    if (m_acikMi == true &&  0<= seviye && 100 >= seviye)
    {
        m_parlaklik = seviye;
    }
    }

bool Lamba::isAcik() const{
    return m_acikMi;
}

int Lamba::getParlaklik() const{
    return m_parlaklik;
}

    




