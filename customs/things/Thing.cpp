#include <cstdio>
#include "Thing.hpp"

// TODO: calculate ComplexObjectMargin
Thing::Thing () : Object (0, 0, 0, 0, 0, 0) {}

void Thing::add (Object *object) {
    objects.push_back (object);
}

void Thing::render () {
    for (Object *obj : objects)
        obj->render ();
}

void Thing::clean () {
    for (Object *obj : objects)
        obj->clean ();
}

void Thing::transform (mat4 T, int type) {
    printf ("thing transform\n");
    for (Object *obj : objects)
        obj->_transform (T, type);
}

void Thing::measure () {
    using std::min;
    using std::max;
    
    for (Object *obj : objects) {
        for (int i = 0; i < 3; i++) {
            margin[i][0] = min (margin[i][0], obj->margin[i][0]);
            margin[i][1] = max (margin[i][1], obj->margin[i][1]);
        }
    }
}