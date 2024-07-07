#include "Mirror.h"

extern Mirror& mirror3();

Mirror& mirror4() {
    static Mirror mirror4(&mirror3());
    return mirror4; 
}