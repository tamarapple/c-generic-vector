#include <stdio.h>

#include "tests.h"

int main() {
    /*genericVectorCreate_test();*/
    /*genericVectorPush_test();*/
    /*genericVectorInsert_test();*/
    genericVectorPop_test();
    genericVectorRemove_test();
    genericVectorGetAndVectorSetElement_test();
    genericVectorCount_test();

    return 0;
}