#pragma once
class Lamba{
    private:

    bool m_acikMi{false};
    int m_parlaklik{0};

    public:
    void ac();
    void kapat();
    void setParlaklik(int seviye);
    bool isAcik() const;
    int getParlaklik() const;
};