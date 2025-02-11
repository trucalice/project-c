#ifndef DATATYPE_H
#define DATATYPE_H

#define MAX 100

// Struct luu tru thong tin sach
typedef struct {
    char id[10];
    char title[50];
    char releaseDate[15];
    char author[30];
    float price;
} book;

#endif
