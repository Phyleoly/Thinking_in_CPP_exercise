// AsteroidStash.h
#ifndef ASTEROIDSTASH_H
#define ASTEROIDSTASH_H

#include "Asteroid.h"
#include <vector>

class AsteroidStash {
    std::vector<Asteroid*> asteroids;
public:
    void add(Asteroid* asteroid) {
        asteroids.push_back(asteroid);
    }

    Asteroid* operator[](int index) const {
        return asteroids[index];
    }

    Asteroid* remove(int index) {
        Asteroid* asteroid = asteroids[index];
        asteroids.erase(asteroids.begin() + index);
        return asteroid;
    }

    int count() const {
        return asteroids.size();
    }

    ~AsteroidStash() {
        for (Asteroid* asteroid : asteroids) {
            delete asteroid;
        }
    }
};

#endif // ASTEROIDSTASH_H