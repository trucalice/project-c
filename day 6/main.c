#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"  
#include "function.h"


int main() {
    book arr[MAX];
    customer customers[MAX];
    int bookCount = 0, customerCount = 0;
    int mainChoice, choice;

    loadFromFile(arr, &bookCount);
    loadCustomersFromFile(customers, &customerCount);

    do {
        mainMenu();
        scanf("%d", &mainChoice);
        switch (mainChoice) {
            case 1:
                do {
                    menu();
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            inputBook(arr, &bookCount);
                            saveToFile(arr, bookCount);
                            break;
                        case 2:
                            displayBooks(arr, bookCount);
                            break;
                        case 3:
                            editBook(arr, bookCount);
                            saveToFile(arr, bookCount);
                            break;
                        case 4:
                            deleteBook(arr, &bookCount);
                            saveToFile(arr, bookCount);
                            break;
                        case 5:
                            searchBook(arr, bookCount);
                            break;
                        case 6:
                            sortBooks(arr, bookCount);
                            saveToFile(arr, bookCount);
                            break;
                        case 0:
                            printf("Quay lai menu chinh.\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long chon lai.\n");
                    }
                } while (choice != 0);
                break;
            case 2:
                do {
                    customerMenu();
                    scanf("%d", &choice);
                    switch (choice) {
                        case 1:
                            inputCustomer(customers, &customerCount);
                            saveCustomersToFile(customers, customerCount);
                            break;
                        case 2:
                            displayCustomers(customers, customerCount);
                            break;
                        case 3:
                            editCustomer(customers, customerCount);
                            saveCustomersToFile(customers, customerCount);
                            break;
                        case 4:
                            deleteCustomer(customers, &customerCount);
                            saveCustomersToFile(customers, customerCount);
                            break;
                        case 5:
                            printf("Nhap ten khach hang can tim: ");
                            char searchName[50];
                            scanf(" %[^\n]", searchName);
                            searchCustomerByName(customers, customerCount, searchName);
                            break;
                        case 6:
                            printf("Nhap ID khach hang: ");
                            char customerId[10];
                            scanf("%9s", customerId);
                            printf("Nhap ID sach muon muon: ");
                            char bookId[10];
                            scanf("%9s", bookId);
                            borrowBook(customers, customerCount, arr, bookCount, customerId, bookId);
                            saveToFile(arr, bookCount);
                            break;
                        case 0:
                            printf("Quay lai menu chinh.\n");
                            break;
                        default:
                            printf("Lua chon khong hop le. Vui long chon lai.\n");
                    }
                } while (choice != 0);
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (mainChoice != 0);

    return 0;
}

