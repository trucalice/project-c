#include <stdio.h>
#include "function.h"

void mainMenu() {
    printf("\n*** MENU CHINH ***\n");
    printf("[1] Quan ly sach\n");
    printf("[0] Thoat\n");
    printf("====================\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    book arr[MAX];
    int count = 0;
    int mainChoice, choice;

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

