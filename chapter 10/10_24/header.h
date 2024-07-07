#ifndef HEADER_H
#define HEADER_H

namespace BobsSuperDuperLibrary {
    class Widget {};
    class Poppit {};
}

namespace Xanthan {
    class Arm {};
    class Leg {};
    class Head {};
    class Robot {
        Arm arm[4];
        Leg leg[16];
        Head head[3];
    };
} 

#endif