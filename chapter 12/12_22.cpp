#include <string>
#include <iostream>

class Dog {
    std::string nm;
public:
    Dog(const std::string& name) : nm(name) {
        std::cout << "Creating Dog: " << *this << std::endl;
    }

    Dog(const Dog* dp, const std::string& msg)
        : nm(dp->nm + msg) {
        std::cout << "Copied dog" << *this << "from "
                  << *dp << std::endl;
    }

    ~Dog() {
        std::cout << "Deleting Dog: " << *this << std::endl;
    }

    void rename(const std::string& newName) {
        nm = newName;
        std::cout << "Dog renamed to: " << *this << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& os, const Dog& d) {
        return os << "[" << d.nm << "]";
    }
};

class DogHouse {
    Dog* p;
    std::string houseName;
public:
    DogHouse(Dog* dog, const std::string& house)
        : p(dog), houseName(house) {}
    DogHouse(const DogHouse& dh)
        : p(new Dog(dh.p, " copy-constructed")),
          houseName(dh.houseName + " copy-constructor") {}
    // DogHouse& operator=(const DogHouse& dh) {
    //     if(&dh != this) {
    //         p = new Dog(dh.p, " assigned");
    //         houseName = dh.houseName + " assigned";
    //     }
    //     return *this;
    // }
    void renameHouse(const std::string& newName) {
        houseName = newName;
    }
    Dog* getDog() const { return p; }
    ~DogHouse() { delete p; }
    friend std::ostream& operator<<(std::ostream& os, const DogHouse& dh) {
        return os << "[" << dh.houseName
            << "] contains " << *dh.p;
    }
};

int main() {
    DogHouse fidos(new Dog("Fido"), "FidoHOuse");
    std::cout << fidos << std::endl;
    DogHouse fidos2 = fidos;
    std::cout << fidos2 << std::endl;
    fidos2.getDog()->rename("Spot");
    fidos2.renameHouse("SpotHouse");
    std::cout << fidos2 << std::endl;
    fidos = fidos2;
    std::cout << fidos << std::endl;
    fidos.getDog()->rename("Max");  
    fidos2.renameHouse("MaxHouse");

    return 0;
}