//Time 10min 00s
#include "list.h"
#include <math.h>
typedef struct Item Item;
Item* CreaDaInterni(const Item* i, double r) {
    Item* res = ListCreateEmpty();
    while (!ListIsEmpty(i)) {
        //If the point is inside the radius
        if (sqrt((double)(i->value.x * i->value.x) + (double)(i->value.y * i->value.y)) < r) {
            res = ListInsertBack(res, &i->value);
        }
        i = ListGetTail(i);
    }
    return res;
}