/*


#include <iostream>

class Device{
    public:
    void setInfo(std::string name, int level){
        m_deviceName = name;
        m_securityLevel = level;
    }

    friend void inspectDevice(const Device& dev);


    private:
    std::string m_deviceName{"Bilinmiyor"};
    int m_securityLevel{1};

    
};

void inspectDevice(const Device& dev){
    std::cout << "isim: " << dev.m_deviceName << std::endl;
    std::cout << "level: " << dev.m_securityLevel << std::endl;
}

int main(){

    Device* devPtr = new Device;
    devPtr -> setInfo("Iphone", 3);
    
    inspectDevice(*devPtr);

    delete devPtr;
    devPtr = nullptr;
}


*/