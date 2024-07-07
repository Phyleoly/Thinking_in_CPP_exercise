#include "Mirror.h"

Mirror& mirror1() {
    static Mirror mirror1;
    return mirror1; 
}