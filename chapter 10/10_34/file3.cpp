#include "Mirror.h"

extern Mirror& mirror2();

Mirror& mirror3() {
    static Mirror mirror3(&mirror2());
    return mirror3; 
}