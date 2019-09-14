
/* Created by tamarapple on 9/14/19.*/


#include "count_generic_vector.h"

size_t countVectorInt(const GenericVector *genericVector, void **value) {
    size_t i,counter=0;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
       if((int)(*value)== *(int *)(genericVector->m_items[i])){
           ++counter;
       }
    }
    return counter;
}

size_t countVectorChar(const GenericVector *genericVector, void **value){
    size_t i,counter=0;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        if((int)(*value)== *(char *)(genericVector->m_items[i])){
            ++counter;
        }
    }
    return counter;
}

size_t countVectorDouble(const GenericVector *genericVector, void **value){
    size_t i,counter=0;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        if((int)(*value)== *(double *)(genericVector->m_items[i])){
            ++counter;
        }
    }
    return counter;
}

size_t printVectorFloat(const GenericVector *genericVector, void **value){
    size_t i,counter=0;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        if((int)(*value)== *(float *)(genericVector->m_items[i])){
            ++counter;
        }
    }
    return counter;
}