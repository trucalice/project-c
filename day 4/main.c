#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"  
#include "function.h"


int main() {
    book arr[MAX];
    int count = 0;
    int mainChoice, choice;

    loadFromFile(arr, &count); // Tai du lieu tu file khi chuong trinh khoi dong

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
                            inputBook(arr, &count);
                            saveToFile(arr, count); // Luu du lieu vao file sau khi them sach
                            break;
                        case 2:
                            displayBooks(arr, count);
                            break;
                        case 3:
                            editBook(arr, count);
                            saveToFile(arr, count); // Luu sau khi chinh sua
                            break;
                        case 4:
                            deleteBook(arr, &count);
                            saveToFile(arr, count); // Luu sau khi xoa sach
                            break;
                        case 5:
                            searchBook(arr, count);
                            break;
                        case 6:
                            sortBooks(arr, count);
                            saveToFile(arr, count); // Luu sau khi sap xep
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

