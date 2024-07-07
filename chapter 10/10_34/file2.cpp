#include "Mirror.h"

extern Mirror& mirror1();

Mirror& mirror2() {
    static Mirror mirror2(&mirror1());
    return mirror2; 
}