#include <iostream>
#include <vector>
using namespace std;

class Aircraft {
public:
    virtual void takeoff() const {
        cout << "Aircraft is taking off" << endl;
    }

    virtual void land() const {
        cout << "Aircraft is landing" << endl;
    }

    virtual void communicate() const {
        cout << "Aircraft communicating with tower" << endl;
    }

    virtual ~Aircraft() {}
};

class Airplane : public Aircraft {
public:
    void takeoff() const override {
        cout << "Airplane is taking off from runway" << endl;
    }

    void land() const override {
        cout << "Airplane is landing on runway" << endl;
    }

    void communicate() const override {
        cout << "Airplane communicating with tower" << endl;
    }
};

class Helicopter : public Aircraft {
public:
    void takeoff() const override {
        cout << "Helicopter is taking off vertically" << endl;
    }

    void land() const override {
        cout << "Helicopter is landing vertically" << endl;
    }

    void communicate() const override {
        cout << "Helicopter communicating with tower" << endl;
    }
};

class Drone : public Aircraft {
public:
    void takeoff() const override {
        cout << "Drone is taking off remotely" << endl;
    }

    void land() const override {
        cout << "Drone is landing remotely" << endl;
    }

    void communicate() const override {
        cout << "Drone communicating with tower" << endl;
    }
};

class Tower {
private:
    vector<Aircraft*> controlledAircraft;

public:
    void addAircraft(Aircraft* aircraft) {
        controlledAircraft.push_back(aircraft);
    }

    void sendTakeoffInstructions() const {
        for (const auto& aircraft : controlledAircraft) {
            aircraft->takeoff();
        }
    }

    void sendLandingInstructions() const {
        for (const auto& aircraft : controlledAircraft) {
            aircraft->land();
        }
    }

    void communicateWithAll() const {
        for (const auto& aircraft : controlledAircraft) {
            aircraft->communicate();
        }
    }

    ~Tower() {
        for (const auto& aircraft : controlledAircraft) {
            delete aircraft;
        }
    }
};

int main() {
    Tower controlTower;

    controlTower.addAircraft(new Airplane());
    controlTower.addAircraft(new Helicopter());
    controlTower.addAircraft(new Drone());

    cout << "Sending takeoff instructions:" << endl;
    controlTower.sendTakeoffInstructions();
    cout << endl;

    cout << "Sending landing instructions:" << endl;
    controlTower.sendLandingInstructions();
    cout << endl;

    cout << "Communicating with all aircraft:" << endl;
    controlTower.communicateWithAll();

    return 0;
}