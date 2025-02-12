#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"


void menu();
void inputBook(book arr[], int *count);
void displayBooks(book arr[], int count);
void editBook(book arr[], int count);
void deleteBook(book arr[], int *count);
void searchBook(book arr[], int count);
void sortBooks(book arr[], int count);

#endif
