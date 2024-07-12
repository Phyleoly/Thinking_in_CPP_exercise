#include <iostream>
#include <string>

using namespace std;

class Travel;

class Pager {
private:
    string message;

public:
    Pager(const string& msg) : message(msg) {
        cout << "Pager: Constructed with message '" << message << "'\n";
    }

    Pager(const Pager& other) : message(other.message) {
        cout << "Pager: Copy Constructed with message '" << message << "'\n";
    }

    Pager& operator=(const Pager& other) {
        if (this != &other) {
            message = other.message;
            cout << "Pager: Assigned with message '" << message << "'\n";
        }
        return *this;
    }

    const string& getMessage() const { return message; }
};

class Traveler {
private:
    string name;

public:
    Traveler(const string& n) : name(n) {
        cout << "Traveler: Constructed with name '" << name << "'\n";
    }

    Traveler(const Traveler& other) : name(other.name) {
        cout << "Traveler: Copy Constructed with name '" << name << "'\n";
    }

    Traveler& operator=(const Traveler& other) {
        if (this != &other) {
            name = other.name;
            cout << "Traveler: Assigned with name '" << name << "'\n";
        }
        return *this;
    }

    const string& getName() const { return name; }
};

class BusinessTraveler : public Traveler {
private:
    Pager pager;

public:
    BusinessTraveler() : Traveler(""), pager("") {
        cout << "BusinessTraveler: Default Constructed\n";
    }

    BusinessTraveler(const string& n, const string& msg) : Traveler(n), pager(msg) {
        cout << "BusinessTraveler: Constructed with name '" << n << "' and Pager message '" << msg << "'\n";
    }

    BusinessTraveler(const BusinessTraveler& other)
        : Traveler(other), pager(other.pager) {
        cout << "BusinessTraveler: Copy Constructed with name '" << other.getName() << "' and Pager message '" << other.pager.getMessage() << "'\n";
    }

    BusinessTraveler& operator=(const BusinessTraveler& other) {
        if (this != &other) {
            Traveler::operator=(other);
            pager = other.pager;
            cout << "BusinessTraveler: Assigned with name '" << other.getName() << "' and Pager message '" << other.pager.getMessage() << "'\n";
        }
        return *this;
    }
};

int main() {
    BusinessTraveler bt1("John Doe", "Urgent: Call back ASAP");
    BusinessTraveler bt2 = bt1; 
    BusinessTraveler bt3("Jane Smith", "Reminder: Meeting at 10AM");
    bt3 = bt1; 

    return 0;
}