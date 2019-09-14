
/* Created by tamarapple on 9/13/19 */


#include "generic_vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


/*struct GenericVector {
    void **m_items;
    size_t m_capacity;
    size_t m_size;
};*/

/* Creates instance of vector and returns it  */
GenericVector *genericVectorCreate(size_t size) {
    GenericVector *genericVector;

    /* if size == 0 assert aborts the program */
    assert(size != 0);

    genericVector = malloc(sizeof(GenericVector));

    /* if vector allocation failed assert aborts the program*/
    assert(genericVector);

    if (genericVector) {
        genericVector->m_capacity = size;
        genericVector->m_size = 0;
        genericVector->m_items = malloc(genericVector->m_capacity * sizeof(void *));
        /* if vector->arr allocation failed, frees the vector and puts there NULL */
        if (!genericVector->m_items) {
            free(genericVector);

            /* the function returns NULL  */
            genericVector = NULL;
        }
    }

    return genericVector;
}

/* Frees vector's allocations */
void genericVectorDestroy(GenericVector **genericVector) {


    if (genericVector && *genericVector) {

        free((*genericVector)->m_items);
        free(*genericVector);

        (*genericVector)->m_items = NULL;

        /* needs to do it because we want that the user's vector will point to NULL and not to some address  */
        *genericVector = NULL;
    }
}

/* Multiplies the vector capacity */
ErrorCode resizeGenericVector(GenericVector *genericVector) {
    ErrorCode errorCode;
    void **temp;

    genericVector->m_capacity *= 2;
    temp = realloc(genericVector->m_items, genericVector->m_capacity * sizeof(void *));

    /* if allocation failed, realloc returns NULL, then needs to free vector's allocation */
    if (!temp) {
        genericVectorDestroy(&genericVector);
        errorCode = E_ALLOCATION_ERROR;
    } else {
        genericVector->m_items = temp;
        errorCode = E_OK;
    }

    return errorCode;
}

/* Adds an item at the end. Grows if needed (by * 2) */
ErrorCode genericVectorPush(GenericVector *genericVector, void *value) {
    ErrorCode errorCode = E_OK;

    /* if vector = NULL, can't push and assert abort thr program  */
    assert(genericVector);

    if (isFull(genericVector)) {
        errorCode = resizeGenericVector(genericVector);
    }

    *(genericVector->m_items + genericVector->m_size) = value;
    genericVector->m_size++;

    return errorCode;
}

/* Adds an item at a certain position and shifts. Grows if needed (by * 2) */
ErrorCode genericVectorInsert(GenericVector *genericVector, void *value, size_t index) {
    ErrorCode errorCode = E_OK;

    /* if the index is in the end of the vector, calls vectorPush function */
    if (index == genericVectorGetSize(genericVector)) {
        genericVectorPush(genericVector, value);
        return E_OK;
    } else if (index > genericVectorGetSize(genericVector))
        errorCode = E_BAD_INDEX;
    else {
        shiftGenericVector(genericVector, index, E_RIGHT);
        ++genericVector->m_size;
        *(genericVector->m_items + index) = value;
    }

    return errorCode;
}

/* Clears the item at the end */
ErrorCode genericVectorPop(GenericVector *genericVector, void **res) {
    ErrorCode errorCode = E_OK;
    if (isEmpty(genericVector))
        errorCode = E_UNDERFLOW;
    else {
        *res = *(genericVector->m_items + genericVector->m_size - 1);
        --genericVector->m_size;
    }
    return errorCode;
}

/* Clears an item at a certain position and shifts */
ErrorCode genericVectorRemove(GenericVector *genericVector, size_t index, void **res) {
    ErrorCode errorCode = E_OK;
    /* if vector=NULL, aborts thr program  */
    assert(genericVector);
    if (index == genericVectorGetSize(genericVector) - 1) {
        errorCode = genericVectorPop(genericVector, res);
    }

        /* if the index is bigger than the vector size */
    else if (index > (genericVectorGetSize(genericVector) - 1))
        errorCode = E_BAD_INDEX;
    else {
        *res = *(genericVector->m_items + index);
        shiftGenericVector(genericVector, index, E_LEFT);
        --genericVector->m_size;
    }

    return errorCode;
}

/* Gets element from vector in specific index */
ErrorCode genericVectorGetElement(const GenericVector *genericVector, size_t index, void **res) {
    ErrorCode errorCode = E_OK;

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    /* if the index is bigger than the vector size */
    if (index > genericVector->m_size - 1)
        errorCode = E_BAD_INDEX;
    else {
        *res = *(genericVector->m_items + index);
        errorCode = E_OK;
    }
    return errorCode;
}

/* sets element in specific index in vector */
ErrorCode genericVectorSetElement(GenericVector *genericVector, size_t index, void *value) {
    ErrorCode errorCode = E_OK;

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    /* if the index is bigger than the vector size */
    if (index > genericVector->m_size - 1)
        errorCode = E_BAD_INDEX;
    else {
        *(genericVector->m_items + index) = value;
        errorCode = E_OK;
    }
    return errorCode;
}

/* Gets vector size */
size_t genericVectorGetSize(const GenericVector *genericVector) {

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    return genericVector->m_size;
}

/* Gets vector capacity */
size_t genericVectorGetCapacity(const GenericVector *genericVector) {

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    return genericVector->m_capacity;
}

/* Counts how many instances of a given value there are */
size_t genericVectorCount(const GenericVector *genericVector, void *value) {
    size_t counter = 0;
    return counter;
}

/* Checks if vector is full, If the vector is full returns true, else returns false */
bool isFull(const GenericVector *genericVector) {

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    if (genericVectorGetCapacity(genericVector) <= genericVectorGetSize(genericVector)) {
        return true;
    } else
        return false;
}

/* Checks if vector is empty, If the vector is empty returns true, else returns false */
bool isEmpty(const GenericVector *genericVector) {

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    return !(genericVector->m_size);
}

/* Shifts all the elements in vector according the specific direction right or left  */
ErrorCode shiftGenericVector(GenericVector *genericVector, size_t index, Direction direction) {
    ErrorCode errorCode = E_OK;

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    if (isFull(genericVector))
        errorCode = resizeGenericVector(genericVector);

    if (errorCode == E_OK) {

        if (direction == E_LEFT) {
            shiftLeftGenericVector(genericVector, index);

        } else if (direction == E_RIGHT) {
            shiftRightGenericVector(genericVector, index);
        }
    }
    return errorCode;
}

/* Shifts right all the elements in vector */
void shiftRightGenericVector(GenericVector *genericVector, size_t index) {
    size_t i = genericVectorGetSize(genericVector);

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    /* I added condition i>0 because when index = 0 , in the last loop iteration i will get 0 and then reduced by one
     * and get a big number- because size_t is unsigned, so the loop will be endless
     * */
    while (i >= index && i > 0) {
        *(genericVector->m_items + i) = *(genericVector->m_items + i - 1);
        --i;
    }
}

/* Shifts left all the elements in vector */
void shiftLeftGenericVector(GenericVector *genericVector, size_t index) {
    size_t i = index;

    /* if vector = NULL, aborts thr program  */
    assert(genericVector);

    while (i < genericVectorGetSize(genericVector)) {
        *(genericVector->m_items + i) = *(genericVector->m_items + i + 1);
        i++;

    }
}

/* Prints vector elements */
void printGenericVector(const GenericVector *genericVector,PrintFunc printFunc){
    printFunc(&genericVector);
}
