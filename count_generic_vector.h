
/* Created by tamarapple on 9/14/19.*/


#ifndef GENERICVECTOR_COUNT_GENERIC_VECTOR_H
#define GENERICVECTOR_COUNT_GENERIC_VECTOR_H

#include "generic_vector.h"

size_t countVectorInt(const GenericVector *genericVector, void **value);

size_t countVectorChar(const GenericVector *genericVector, void **value);

size_t countVectorDouble(const GenericVector *genericVector, void **value);

size_t printVectorFloat(const GenericVector *genericVector, void **value);

#endif /*GENERICVECTOR_COUNT_GENERIC_VECTOR_H*/
