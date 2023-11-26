#include <iostream>

// Laskutoimitus on abstrakti yliluokka
class Laskutoimitus {
public:
    // Puhtaan virtuaalinen jäsenfunktio laske
    virtual double laske(double x, double y) = 0;
};

class Yhteenlasku : public Laskutoimitus {
public:
    double laske(double x, double y) override {
        return x + y;
    }
};

class Kertolasku : public Laskutoimitus {
public:
    double laske(double x, double y) override {
        return x * y;
    }
};

int main() {
    Laskutoimitus* laskuOsoitin;

    Yhteenlasku yhteenlasku;
    laskuOsoitin = &yhteenlasku;

    double tulosYhteenlasku = laskuOsoitin->laske(7.0, 7.0);
    std::cout << "Yhteenlasku: " << tulosYhteenlasku << std::endl;

    Kertolasku kertolasku;
    laskuOsoitin = &kertolasku;

    double tulosKertolasku = laskuOsoitin->laske(7.0, 3.0);
    std::cout << "Kertolasku: " << tulosKertolasku << std::endl;

    return 0;
}