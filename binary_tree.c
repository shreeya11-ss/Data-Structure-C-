#include<stdio.h>
#include<stdlib.h>
struct tree{
    struct tree *right,*left;
    int data;
}*root ;