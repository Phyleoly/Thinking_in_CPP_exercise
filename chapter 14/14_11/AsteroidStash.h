// AsteroidStash.h
#ifndef ASTEROIDSTASH_H
#define ASTEROIDSTASH_H

#include "PStash.h"
#include "Asteroid.h"

class AsteroidStash : public PStash {
public:
    int add(Asteroid* element) {
        return PStash::add(static_cast<void*>(element));
    }

    Asteroid* operator[](int index) const {
        return static_cast<Asteroid*>(PStash::operator[](index));
    }

    Asteroid* remove(int index) {
        return static_cast<Asteroid*>(PStash::remove(index));
    }
};

#endif // ASTEROIDSTASH_H