
/* Created by tamarapple on 9/13/19 */

#include <stdio.h>
#include "tests.h"
#include "generic_vector.h"
#include "print_generic_vector.h"

void genericVectorCreate_test() {

    /* creates vector with capacity 1000 */
    GenericVector *genericVector = genericVectorCreate(1000);
    genericVectorDestroy(&genericVector);

    /* tries to create vector with capacity 0 */
    /* GenericVector *genericVector = genericVectorCreate(0);
    genericVectorDestroy(&genericVector); */

    /* tries to create vector with negative capacity :  program falls (vectorCreate gets size_t) */
    /* GenericVector *genericVector = genericVectorCreate(-2);
    genericVectorDestroy(&genericVector); */
}

void genericVectorPush_test() {
    GenericVector *genericVector = genericVectorCreate(3);
    GenericVector *genericVector2 = genericVectorCreate(5);
    GenericVector *genericVector5 = genericVectorCreate(5);
    int i1 = 0;
    int i2 = 1;
    int i3 = 2;
    void *a = &i1;
    void *b = &i2;
    void *c = &i3;
    double f1 = 0.6;
    double f2 = 1.4;
    double f3 = 2.23;
    void *fa = &f1;
    void *fb = &f2;
    void *fc = &f3;
    char c1 = 'w';
    char c2 = 's';
    char c3 = 'n';

    genericVectorPush(genericVector, a);
    genericVectorPush(genericVector, b);
    genericVectorPush(genericVector, c);
    genericVectorPush(genericVector2, fa);
    genericVectorPush(genericVector2, fb);
    genericVectorPush(genericVector2, fc);
    genericVectorPush(genericVector5, &c1);
    genericVectorPush(genericVector5, &c2);
    genericVectorPush(genericVector5, &c3);

    /*for (; i < 3; ++i) {
        genericVectorPush(genericVector, &i);
    }*/
    printVectorInt(genericVector);
    printVectorDouble(genericVector2);
    printVectorChar(genericVector5);
    /*printVector(vector);*/
    genericVectorDestroy(&genericVector);
    genericVectorDestroy(&genericVector2);
    genericVectorDestroy(&genericVector5);
}

void genericVectorInsert_test() {
    GenericVector *genericVector = genericVectorCreate(3);
    GenericVector *genericVector2 = genericVectorCreate(5);
    GenericVector *genericVector5 = genericVectorCreate(3);
    int i1 = 0;
    int i2 = 1;
    int i3 = 2;
    void *a = &i1;
    void *b = &i2;
    void *c = &i3;
    double f1 = 0.6;
    double f2 = 1.4;
    double f3 = 2.23;
    void *fa = &f1;
    void *fb = &f2;
    void *fc = &f3;
    char c1 = 'w';
    char c2 = 's';
    char c3 = 'n';
    char c4 = 'l';
    char c5 = 'a';
    char c6 = 'b';
    genericVectorPush(genericVector, a);
    genericVectorPush(genericVector, b);
    genericVectorPush(genericVector, c);
    genericVectorPush(genericVector2, fa);
    genericVectorPush(genericVector2, fb);
    genericVectorPush(genericVector2, fc);
    genericVectorPush(genericVector5, &c1);
    genericVectorPush(genericVector5, &c2);
    genericVectorPush(genericVector5, &c3);

    /*for (; i < 3; ++i) {
        genericVectorPush(genericVector, &i);
    }*/
    printVectorInt(genericVector);
    printVectorDouble(genericVector2);
    printVectorChar(genericVector5);

    genericVectorInsert(genericVector5, &c4, 1);
    printVectorChar(genericVector5);
    genericVectorInsert(genericVector5, &c5, 2);
    printVectorChar(genericVector5);
    genericVectorInsert(genericVector5, &c6, 4);
    printVectorChar(genericVector5);
    /*printVector(vector);*/
    genericVectorDestroy(&genericVector);
    genericVectorDestroy(&genericVector2);
    genericVectorDestroy(&genericVector5);
}

void genericVectorPop_test() {
    void *res;
    GenericVector *genericVector5 = genericVectorCreate(3);
    char c1 = 'w';
    char c2 = 's';
    char c3 = 'n';
    char c4 = 'l';
    char c5 = 'a';
    char c6 = 'b';
    genericVectorPush(genericVector5, &c1);
    genericVectorPush(genericVector5, &c2);
    genericVectorPush(genericVector5, &c3);
    genericVectorPush(genericVector5, &c4);
    genericVectorPush(genericVector5, &c5);
    genericVectorPush(genericVector5, &c6);

    printVectorChar(genericVector5);
    genericVectorPop(genericVector5, &res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);
    genericVectorPop(genericVector5, &res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);
    genericVectorPop(genericVector5, &res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);
    /*printf("%c\n",*(char*)res);*/

    genericVectorDestroy(&genericVector5);
}

void genericVectorRemove_test() {
    void *res;
    GenericVector *genericVector5 = genericVectorCreate(3);
    char c1 = 'w';
    char c2 = 's';
    char c3 = 'n';
    char c4 = 'l';
    char c5 = 'a';
    char c6 = 'b';
    genericVectorPush(genericVector5, &c1);
    genericVectorPush(genericVector5, &c2);
    genericVectorPush(genericVector5, &c3);
    genericVectorPush(genericVector5, &c4);
    genericVectorPush(genericVector5, &c5);
    genericVectorPush(genericVector5, &c6);
    printVectorChar(genericVector5);

    genericVectorRemove(genericVector5,0,&res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);

    genericVectorRemove(genericVector5,4,&res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);

    genericVectorRemove(genericVector5,2,&res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);

    genericVectorDestroy(&genericVector5);

}

void genericVectorGetAndVectorSetElement_test(){
    void *res;
    GenericVector *genericVector5 = genericVectorCreate(3);
    char c1 = 'w';
    char c2 = 's';
    char c3 = 'n';
    char c4 = 'l';
    char c5 = 'a';
    char c6 = 'b';
    char c7 = 'u';
    char c8 = 'p';
    genericVectorPush(genericVector5, &c1);
    genericVectorPush(genericVector5, &c2);
    genericVectorPush(genericVector5, &c3);
    genericVectorPush(genericVector5, &c4);
    genericVectorPush(genericVector5, &c5);
    genericVectorPush(genericVector5, &c6);
    printVectorChar(genericVector5);

    /* gets first element */
    genericVectorGetElement(genericVector5, 0, &res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);


    /* sets middle element */
    genericVectorSetElement(genericVector5, 3, &c8);

    genericVectorGetElement(genericVector5, 3, &res);
    printf("res: %c\n", *(char*)res);  /* 11 */
    printVectorChar(genericVector5);
    printGenericVector(&genericVector5,printVectorChar);
    genericVectorDestroy(&genericVector5);



}