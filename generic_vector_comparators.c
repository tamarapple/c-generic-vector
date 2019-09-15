
/* Created by tamarapple on 9/15/19 */


#include "generic_vector_comparators.h"

bool intCompare(const void *value_1, const void *value_2) {
    return (*(int*)(value_1)==*(int*)(value_2));
}

bool charCompare(const void *value_1, const void *value_2){
    return (*(char*)(value_1)==*(char*)(value_2));
}

bool floatCompare(const void *value_1, const void *value_2){
    return (*(float*)(value_1)==*(float*)(value_2));
}

