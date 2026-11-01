/*


#include <iostream>

class SmartBattery {
public:
    // --- Mutator (Değiştirici/Setter Metot) ---
    // Gelen miktarı şarj seviyesine ekler; kapsülleme kuralı gereği 
    // sınıf kendi sınırını korur ve değerin 100'ü aşmasına izin vermez.
    void charge(int amount) {
        if (amount <= 0) return; // Hatalı/negatif giriş kontrolü
        m_chargeLevel += amount;
        if (m_chargeLevel > 100) {
            m_chargeLevel = 100; // Üst sınır koruması
        }
    }

    // --- Durum Değiştiren İşlem Metodu ---
    // Yeterli şarj varsa harcamayı yapar ve true döner;
    // yetersiz şarj durumunda işlemi iptal edip false döner.
    bool discharge(int amount) {
        if (amount > 0 && m_chargeLevel >= amount) {
            m_chargeLevel -= amount;
            return true;
        }
        return false;
    }

    // --- Accessor (Erişici/Getter Metot) ---
    // Sonda yer alan 'const' kelimesi, bu fonksiyonun nesnenin asıl
    // durumunu (m_chargeLevel) değiştirmeyeceğini garanti eder.
    // 'm_checkCount' değişkeni 'mutable' tanımlandığı için bu const 
    // fonksiyon içinde bile değeri 1 artırılabilir.
    int getChargeLevel() const {
        ++m_checkCount; // mutable üye güncelleniyor
        return m_chargeLevel;
    }

    // Sayaç okuma metodu: Nesneyi değiştirmediği için const işaretlenir.
    int getCheckCount() const {
        return m_checkCount;
    }

private:
    // Sınıfın iç verileri dışarıdan doğrudan müdahaleye kapalıdır (private).
    // Üye değişkenler 'm_' ön ekiyle belirtilir ve süslü parantezle ilklenir.
    int m_chargeLevel{50};       // Başlangıç şarjı: %50
    mutable int m_checkCount{0}; // const metotlarda da değişebilen sayaç
};

int main() {
    // 1. Normal (durumu değişebilen) nesne:
    SmartBattery phoneBattery;

    // 70 birim şarj ekleniyor: 50 + 70 = 120 olurdu ancak sınır 100'e sabitlenir
    phoneBattery.charge(70);

    // 30 birim harcanıyor: 100 - 30 = 70 kalır
    phoneBattery.discharge(30);
    std::cout << "Telefon Bataryasi: %" << phoneBattery.getChargeLevel() << std::endl;

    std::cout << "------------------------------------" << std::endl;

    // 2. Sabit (const) nesne:
    // Bu nesnenin hiçbir durumu dışarıdan değiştirilemez (charge veya discharge çağrılamaz).
    const SmartBattery backupBattery;

    // getChargeLevel() bir 'const' metot olduğu için const nesne üzerinden çağrılabilir:
    std::cout << "Yedek Batarya (1. Okuma): %" << backupBattery.getChargeLevel() << std::endl;
    std::cout << "Yedek Batarya (2. Okuma): %" << backupBattery.getChargeLevel() << std::endl;

    // mutable anahtar kelimesi sayesinde sayaç const nesnede bile çalıştı ve 2 oldu:
    std::cout << "Yedek Batarya Kontrol Sayisi: " << backupBattery.getCheckCount() << std::endl;

    return 0;
}


*/




/*


#include <iostream>

class WaterTank {

    private:

    const int MAX_CAPACITY{100};
    int m_currentLevel{0};
    mutable int m_readCount{0};


    public: 

    void addWater(int amount){
        if (amount > 0)
        {
            m_currentLevel += amount;

            if (m_currentLevel > MAX_CAPACITY)
            {
                m_currentLevel = MAX_CAPACITY;
            }
        }
    }
    bool useWater(int amount){
        if (amount <= m_currentLevel)
        {
            m_currentLevel -= amount; return true;
        }
        else  return false;
    }

    int getWaterLevel() const{
        ++m_readCount;
        return m_currentLevel;
    }

    int getReadCount() const{
        return m_readCount;
    }
};

int main() {
    
    WaterTank evDeposu;
    evDeposu.addWater(120);
    evDeposu.useWater(40);
    std::cout << "Ev Deposu Su Seviyesi: " << evDeposu.getWaterLevel() << std::endl;

    const WaterTank yedekDepo;
    std::cout << "Yedek Depo (1. Okuma): " << yedekDepo.getWaterLevel() << std::endl;
    std::cout << "Yedek Depo (2. Okuma): " << yedekDepo.getWaterLevel() << std::endl;

    std::cout << "Yedek Depo Kontrol Sayisi: " << yedekDepo.getReadCount() << std::endl;
}


*/