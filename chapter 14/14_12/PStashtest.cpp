// PStashtest.cpp
#include "AsteroidStash.h"
#include <iostream>
using namespace std;

int main() {
    AsteroidStash stash;

    for(int i = 0; i < 5; i++) {
        stash.add(new Asteroid(i, i * 10.0));
    }

    for(int i = 0; i < stash.count(); i++) {
        cout << "Asteroid " << stash[i]->getId() << ": " << stash[i]->getMass() << " kg" << endl;
    }

    for(int i = 0; i < stash.count(); i++) {
        delete stash.remove(i);
    }

    return 0;
}