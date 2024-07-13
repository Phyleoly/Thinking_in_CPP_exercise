#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Plant {
public:
    virtual void water() const {
        cout << "Watering the plant" << endl;
    }
    
    virtual void fertilize() const {
        cout << "Fertilizing the plant" << endl;
    }
    
    virtual void prune() const {
        cout << "Pruning the plant" << endl;
    }
    
    virtual ~Plant() {}
};

class Flower : public Plant {
public:
    void water() const override {
        cout << "Watering the flower" << endl;
    }
    
    void fertilize() const override {
        cout << "Fertilizing the flower with flower fertilizer" << endl;
    }
    
    void prune() const override {
        cout << "Pruning the flower" << endl;
    }
};

class Vegetable : public Plant {
public:
    void water() const override {
        cout << "Watering the vegetable" << endl;
    }
    
    void fertilize() const override {
        cout << "Fertilizing the vegetable with vegetable fertilizer" << endl;
    }
    
    void prune() const override {
        cout << "Pruning the vegetable" << endl;
    }
};

class Tree : public Plant {
public:
    void water() const override {
        cout << "Watering the tree" << endl;
    }
    
    void fertilize() const override {
        cout << "Fertilizing the tree with tree fertilizer" << endl;
    }
    
    void prune() const override {
        cout << "Pruning the tree" << endl;
    }
};

class Greenhouse {
private:
    vector<Plant*> plants;
    
public:
    ~Greenhouse() {
        for (Plant* plant : plants) {
            delete plant;
        }
    }
    
    void addPlant(Plant* plant) {
        plants.push_back(plant);
    }
    
    void careForPlants() const {
        for (Plant* plant : plants) {
            plant->water();
            plant->fertilize();
            plant->prune();
            cout << endl;
        }
    }
};

int main() {
    Greenhouse greenhouse;
    
    greenhouse.addPlant(new Flower);
    greenhouse.addPlant(new Vegetable);
    greenhouse.addPlant(new Tree);
    
    greenhouse.careForPlants();
    
    return 0;
}