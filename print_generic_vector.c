
/* Created by tamarapple on 9/13/19 */


#include "print_generic_vector.h"
#include <stdio.h>

void printVectorInt(const GenericVector *genericVector) {
    int i;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        printf("%d ", *(int *)(genericVector->m_items[i]));
    }
    printf("\n");
}

void printVectorChar(const GenericVector *genericVector){
    int i;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        printf("%c ", *(char *)(genericVector->m_items[i]));
    }
    printf("\n");
}


void printVectorDouble(const GenericVector *genericVector){
    int i;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        printf("%f ", *(double *)(genericVector->m_items[i]));
    }
    printf("\n");
}

/*void printVectorFloat(const GenericVector *genericVector){
    int i;
    size_t size = genericVectorGetSize(genericVector);
    for (i = 0; i < size; ++i) {
        printf("%f ", *(float *)(genericVector->m_items[i]));
    }
    printf("\n");
}*/

