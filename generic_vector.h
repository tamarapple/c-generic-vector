
/* Created by tamarapple on 9/13/19 */


#ifndef GENERICVECTOR_GENERIC_VECTOR_H
#define GENERICVECTOR_GENERIC_VECTOR_H

#include <stddef.h>

typedef enum {
    false, true
} bool;

typedef struct GenericVector GenericVector;

typedef void (*PrintFunc)(const GenericVector *genericVector);

typedef bool (*CompareFunc)(const void *value_1, const void *value_2);



typedef enum {
    E_OK,
    E_NULL_PTR,
    E_UNDERFLOW,
    E_ALLOCATION_ERROR,
    E_BAD_INDEX
} ErrorCode;

typedef enum {
    E_RIGHT, E_LEFT
} Direction;


struct GenericVector {
    void **m_items;
    size_t m_capacity;
    size_t m_size;
};

/* Creates instance of vector and returns it  */
GenericVector *genericVectorCreate(size_t size);

/* Frees vector's allocations */
void genericVectorDestroy(GenericVector **genericVector);

/* Multiplies the vector capacity */
ErrorCode resizeGenericVector(GenericVector *genericVector);

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode genericVectorPush(GenericVector *genericVector, void *value);

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode genericVectorInsert(GenericVector *genericVector, void *value, size_t index);

/* Clears the item at the end */
ErrorCode genericVectorPop(GenericVector *genericVector, void **res);

/* Clears an item at a certain position and shifts */
ErrorCode genericVectorRemove(GenericVector *genericVector, size_t index, void **res);

/* Gets element from vector in specific index */
ErrorCode genericVectorGetElement(const GenericVector *genericVector, size_t index, void **res);

/* sets element in specific index in vector */
ErrorCode genericVectorSetElement(GenericVector *genericVector, size_t index, void *value);

/* Gets vector size */
size_t genericVectorGetSize(const GenericVector *genericVector);

/* Gets vector capacity */
size_t genericVectorGetCapacity(const GenericVector *genericVector);

/* Counts how many instances of a given value there are */
size_t genericVectorCount(const GenericVector *genericVector, void *value, CompareFunc comperator);

/* Checks if vector is full, If the vector is full returns true, else returns false */
bool isFull(const GenericVector *genericVector);

/* Checks if vector is empty, If the vector is empty returns true, else returns false */
bool isEmpty(const GenericVector *genericVector);

/* Shifts all the elements in vector according the specific direction right or left  */
ErrorCode shiftGenericVector(GenericVector *genericVector, size_t index, Direction direction);

/* Shifts right all the elements in vector */
void shiftRightGenericVector(GenericVector *genericVector, size_t index);

/* Shifts left all the elements in vector */
void shiftLeftGenericVector(GenericVector *genericVector, size_t index);

/* Prints vector elements */
void printGenericVector(const GenericVector *genericVector, PrintFunc printFunc);

#endif /* GENERICVECTOR_GENERIC_VECTOR_H */
