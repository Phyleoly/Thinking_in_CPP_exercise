#ifndef MIRROR_H
#define MIRROR_H

class Mirror {
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

Mirror mirror1;
Mirror mirror2;
Mirror mirror3;
Mirror mirror4;
Mirror mirror5;

class MirrorIni {
public:
    MirrorIni() {
        mirror1 = Mirror();
        mirror2 = Mirror(&mirror1);
        mirror3 = Mirror(&mirror2);
        mirror4 = Mirror(&mirror3);
        mirror5 = Mirror(&mirror4);
    }
};

static MirrorIni mirrorIni;

#endif