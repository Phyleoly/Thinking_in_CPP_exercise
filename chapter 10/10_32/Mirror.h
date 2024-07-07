#ifndef MIRROR_H
#define MIRROR_H

class Mirror{
private:
    Mirror* ptr;
    bool flag;
public:
    Mirror() : ptr(nullptr), flag(true) {}
    Mirror(Mirror* point) : ptr(point), flag(false) {}
    bool _test() {
        if(ptr != nullptr)
            return ptr->_test();
        else
            return flag;
    } 
};

#endif