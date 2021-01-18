//
// Created by devilish on 10/20/20.
//


#include "math.h"

int demonic::true_rand() {
    srand(time(0) + rand());
    return rand();
}