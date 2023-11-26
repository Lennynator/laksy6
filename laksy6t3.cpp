#include <iostream>
#include <fstream>
#include <string>

class Writable {
public:
    virtual void writeState(const std::string& filename) const = 0;
};

class Readable {
public:
    virtual void readState(const std::string& filename) = 0;
};

class OmaLuokka : public Writable, public Readable {
private:
    int numero;
    std::string nimi;

public:
    OmaLuokka(int num, const std::string& name) : numero(num), nimi(name) {}

    void writeState(const std::string& filename) const override {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << numero << "\n" << nimi << "\n";
            file.close();
            std::cout << "Tila kirjoitettu tiedostoon: " << filename << std::endl;
        }
        else {
            std::cerr << "Virhe tiedoston kirjoittamisessa: " << filename << std::endl;
        }
    }

    void readState(const std::string& filename) override {
        std::ifstream file(filename);
        if (file.is_open()) {
            file >> numero >> nimi;
            file.close();
            std::cout << "Tila luettu tiedostosta: " << filename << std::endl;
        }
        else {
            std::cerr << "Virhe tiedoston lukemisessa: " << filename << std::endl;
        }
    }

    void tulostaTila() const {
        std::cout << "Numero: " << numero << ", Nimi: " << nimi << std::endl;
    }
};

int main() {
    OmaLuokka omaOlio(42, "Douglas");

    omaOlio.writeState("tila.txt");

    OmaLuokka toinenOlio(0, "");
    toinenOlio.readState("tila.txt");

    toinenOlio.tulostaTila();

    return 0;
}
