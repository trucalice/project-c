#include <stdio.h>
#include "function.h"

int main() {
    book arr[MAX];
    int count = 0;
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                inputBook(arr, &count);
                break;
            case 2:
                displayBooks(arr, count);
                break;
            case 3:
                editBook(arr, count);
                break;
            case 4:
                deleteBook(arr, &count);
                break;
            case 5:
                searchBook(arr, count);
                break;
            case 6:
                sortBooks(arr, count);
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (choice != 0);

    return 0;
}

