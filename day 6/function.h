#ifndef FUNCTION_H
#define FUNCTION_H

#include "datatype.h"

void mainMenu(); 
void menu();
void customerMenu(); 

void inputBook(book arr[], int *count);
void displayBooks(book arr[], int count);
void editBook(book arr[], int count);
void deleteBook(book arr[], int *count);
void searchBook(book arr[], int count);
void sortBooks(book arr[], int count);
void saveToFile(book arr[], int count);
void loadFromFile(book arr[], int *count);

void inputCustomer(customer arr[], int *count);
void displayCustomers(customer arr[], int count);
void editCustomer(customer arr[], int count);
void deleteCustomer(customer arr[], int *count);
void saveCustomersToFile(customer arr[], int count);
void loadCustomersFromFile(customer arr[], int *count);
void searchCustomerByName(customer arr[], int count, char name[]);
void borrowBook(customer customers[], int customerCount, book books[], int bookCount, char customerId[], char bookId[]);
void nhapSoDienThoai(char phone[]);
#endif

