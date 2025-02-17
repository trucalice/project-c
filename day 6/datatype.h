#ifndef DATATYPE_H
#define DATATYPE_H

#define MAX 100

typedef struct {
    char id[10];
    char title[50];
    char releaseDate[15];
    char author[30];
    float price;
     int quantity;
} book;

typedef struct {
    char id[10];
    char name[50];
    char phone[15];
} customer;
#endif
