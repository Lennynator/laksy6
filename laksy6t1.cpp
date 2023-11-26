#include <iostream>

class Ajoneuvo {
protected:
    double huippunopeus;
    int kayttoonottovuosi;
    double paino;

public:
    Ajoneuvo(double nopeus, int vuosi, double massa)
        : huippunopeus(nopeus), kayttoonottovuosi(vuosi), paino(massa) {}

    void tulostaTiedot() const {
        std::cout << "Ajoneuvo - Huippunopeus: " << huippunopeus << ", Käyttöönottovuosi: " << kayttoonottovuosi
            << ", Paino: " << paino << std::endl;
    }
};

class Auto : public Ajoneuvo {
protected:
    int ovienLukumaara;
    int renkaidenLukumaara;

public:
    Auto(double nopeus, int vuosi, double massa, int ovet, int renkaat)
        : Ajoneuvo(nopeus, vuosi, massa), ovienLukumaara(ovet), renkaidenLukumaara(renkaat) {}

    void tulostaTiedot() const {
        Ajoneuvo::tulostaTiedot();
        std::cout << "Auto - Ovien lukumäärä: " << ovienLukumaara << ", Renkaiden lukumäärä: " << renkaidenLukumaara
            << std::endl;
    }
};

class Henkiloauto : public Auto {
protected:
    int maksimimatkustajat;

public:
    Henkiloauto(double nopeus, int vuosi, double massa, int ovet, int renkaat, int matkustajat)
        : Auto(nopeus, vuosi, massa, ovet, renkaat), maksimimatkustajat(matkustajat) {}

    void tulostaTiedot() const {
        Auto::tulostaTiedot();
        std::cout << "Henkilöauto - Maksimimatkustajat: " << maksimimatkustajat << std::endl;
    }
};

class Kuormaauto : public Auto {
protected:
    double maksimikuorma;

public:
    Kuormaauto(double nopeus, int vuosi, double massa, int ovet, int renkaat, double kuorma)
        : Auto(nopeus, vuosi, massa, ovet, renkaat), maksimikuorma(kuorma) {}

    void tulostaTiedot() const {
        Auto::tulostaTiedot();
        std::cout << "Kuorma-auto - Maksimikuorma: " << maksimikuorma << std::endl;
    }
};

class Lentokone : public Ajoneuvo {
protected:
    double maksimilentokorkeus;

public:
    Lentokone(double nopeus, int vuosi, double massa, double korkeus)
        : Ajoneuvo(nopeus, vuosi, massa), maksimilentokorkeus(korkeus) {}

    void tulostaTiedot() const {
        Ajoneuvo::tulostaTiedot();
        std::cout << "Lentokone - Maksimilentokorkeus: " << maksimilentokorkeus << std::endl;
    }
};

class Laiva : public Ajoneuvo {
protected:
    double maksimisyvays;

public:
    Laiva(double nopeus, int vuosi, double massa, double syvyys)
        : Ajoneuvo(nopeus, vuosi, massa), maksimisyvays(syvyys) {}

    void tulostaTiedot() const {
        Ajoneuvo::tulostaTiedot();
        std::cout << "Laiva - Maksimisyvyys: " << maksimisyvays << std::endl;
    }
};

int main() {
    Ajoneuvo ajoneuvo(120.0, 2015, 1500.0);
    Auto auto1(180.0, 2018, 1200.0, 4, 4);
    Henkiloauto henkiloauto(200.0, 2020, 1400.0, 4, 4, 5);
    Kuormaauto kuormaauto(150.0, 2010, 2500.0, 2, 6, 5000.0);
    Lentokone lentokone(800.0, 2010, 10000.0, 12000.0);
    Laiva laiva(40.0, 2005, 8000.0, 15.0);

    ajoneuvo.tulostaTiedot();
    std::cout << std::endl;
    auto1.tulostaTiedot();
    std::cout << std::endl;
    henkiloauto.tulostaTiedot();
    std::cout << std::endl;
    kuormaauto.tulostaTiedot();
    std::cout << std::endl;
    lentokone.tulostaTiedot();
    std::cout << std::endl;
    laiva.tulostaTiedot();

    return 0;
}