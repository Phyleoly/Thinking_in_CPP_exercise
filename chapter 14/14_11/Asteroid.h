// Asteroid.h
#ifndef ASTEROID_H
#define ASTEROID_H

class Asteroid {
    int id;
    double mass;
public:
    Asteroid(int id, double mass) : id(id), mass(mass) {}
    int getId() const { return id; }
    double getMass() const { return mass; }
};

#endif // ASTEROID_H
