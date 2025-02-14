#include <stdio.h>
#include <string.h>
#include "function.h"

void mainMenu() {
    printf("=== MENU CHINH ===\n");
    printf("[1] Quan ly sach\n");
    printf("[0] Thoat\n");
    printf("Nhap lua chon: ");
}

void menu() {
    printf("*** Quan Ly Sach ***\n");
    printf("[1] Them sach moi\n");
    printf("[2] Hien thi danh sach sach\n");
    printf("[3] Chinh sua thong tin sach\n");
    printf("[4] Xoa sach\n");
    printf("[5] Tim kiem sach\n");
    printf("[6] Sap xep sach theo gia tien\n");
    printf("[0] Thoat chuong trinh\n");
    printf("==============================\n");
    printf("Nhap lua chon cua ban: ");
}

void inputBook(book arr[], int *count) {
    book newBook;
    int i, isDuplicate;

    // Ki?m tra trùng ID
    do {
        isDuplicate = 0;
        printf("Nhap ID sach (toi da 10 ky tu): ");
        scanf("%9s", newBook.id);

        if (strlen(newBook.id) > 9) {
            printf("Loi: ID qua dai. Vui long nhap lai!\n");
            isDuplicate = 1;
            continue;
        }

        for (i = 0; i < *count; i++) {
            if (strcmp(arr[i].id, newBook.id) == 0) {
                printf("Loi: ID sach da ton tai. Vui long nhap lai!\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);

    // Ki?m tra trùng tên sách
    do {
        isDuplicate = 0;
        printf("Nhap ten sach (toi da 50 ky tu): ");
        scanf(" %[^\n]s", newBook.title);

        if (strlen(newBook.title) >= 50) {
            printf("Loi: Ten sach qua dai! Vui long nhap lai.\n");
            isDuplicate = 1;
            continue;
        }

        for (i = 0; i < *count; i++) {
            if (strcmp(arr[i].title, newBook.title) == 0) {
                printf("Loi: Ten sach da ton tai. Vui long nhap lai!\n");
                isDuplicate = 1;
                break;
            }
        }
    } while (isDuplicate);

    // Nh?p ngày phát hành
    do {
        printf("Nhap ngay phat hanh (toi da 15 ky tu): ");
        scanf("%14s", newBook.releaseDate);
        if (strlen(newBook.releaseDate) >= 15) {
            printf("Loi: Ngay phat hanh qua dai! Vui long nhap lai.\n");
        }
    } while (strlen(newBook.releaseDate) >= 15);

    // Nh?p tên tác gi?
    do {
        printf("Nhap ten tac gia (toi da 30 ky tu): ");
        scanf(" %[^\n]s", newBook.author);
        if (strlen(newBook.author) >= 30) {
            printf("Loi: Ten tac gia qua dai! Vui long nhap lai.\n");
        }
    } while (strlen(newBook.author) >= 30);

    // Nh?p giá sách
    printf("Nhap gia tien: ");
    while (scanf("%f", &newBook.price) != 1 || newBook.price < 0) {
        printf("Loi: Gia tien khong hop le! Vui long nhap lai: ");
        while (getchar() != '\n'); // Xóa b? d?m
    }

    // Thêm sách vào m?ng
    arr[*count] = newBook;
    (*count)++;
    printf("Them sach thanh cong!\n");
}


void displayBooks(book arr[], int count) {
	printf("|============|=================|=================|======================|============|");
    printf("\n| %-10s | %-15s | %-15s | %-20s | %-11s|\n", "ID", "Ten", "Ngay PH", "Tac Gia", "Gia");
    printf("|============|=================|=================|======================|============|\n");
    int i = 0;
    for (;i < count; i++) {
    printf("| %-10s | %-15s | %-15s | %-20s | %-10.2f |\n", arr[i].id, arr[i].title, arr[i].releaseDate, arr[i].author, arr[i].price);
    printf("|------------|-----------------|-----------------|----------------------|------------|\n");
    }
}

void editBook(book arr[], int count) {
    char id[10];
    printf("Nhap ID sach can chinh sua: ");
    scanf("%s", id);
    int i = 0;
    for (;i < count; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            printf("Chinh sua thong tin sach %s\n", arr[i].title);
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", arr[i].title);
            printf("Nhap ngay phat hanh moi: ");
            scanf("%s", arr[i].releaseDate);
            printf("Nhap ten tac gia moi: ");
            scanf(" %[^\n]", arr[i].author);
            printf("Nhap gia tien moi: ");
            scanf("%f", &arr[i].price);
            printf("Chinh sua thong tin thanh cong!\n");
            return;
        }
    }
    printf("Khong tim thay sach voi ID %s!\n", id);
}

void deleteBook(book arr[], int *count) {
    char id[10];
    printf("Nhap ID sach can xoa: ");
    scanf("%s", id);
    int i = 0;
    for (; i < *count; i++) {
        if (strcmp(arr[i].id, id) == 0) {
            char confirm;
            printf("Ban co chac chan muon xoa sach voi ID %s? (y/n): ", id);
            scanf(" %c", &confirm);
            int j = i;
            if (confirm == 'y' || confirm == 'Y') {
                for (; j < *count - 1; j++) {
                    arr[j] = arr[j + 1];
                }
                (*count)--;
                printf("Xoa sach thanh cong!\n");
            } else {
                printf("Huy thao tac xoa sach.\n");
            }
            return;
        }
    }
    printf("Khong tim thay sach voi ID %s!\n", id);
}

void searchBook(book arr[], int count) {
    char title[50];
    printf("Nhap ten sach can tim: ");
    scanf(" %[^\n]", title);
    printf("|============|=================|=================|======================|============|\n");
    printf("| %-10s | %-15s | %-15s | %-20s | %-11s|\n", "ID", "Ten", "Ngay PH", "Tac Gia", "Gia");
    printf("|============|=================|=================|======================|============|\n");
    int found = 0;
    int i = 0;
    for (; i < count; i++) {
        if (strstr(arr[i].title, title) != NULL) {
            printf("| %-10s | %-15s | %-15s | %-20s | %-10.2f |\n", arr[i].id, arr[i].title, arr[i].releaseDate, arr[i].author, arr[i].price);
            found = 1;
            printf("|------------|-----------------|-----------------|----------------------|------------|\n");
        }
    }
    if (!found) {
        printf("Khong tim thay sach nao voi ten %s!\n", title);
    }
}

void sortBooks(book arr[], int count) {
    int order;
    printf("Chon thu tu sap xep: 1. Tang dan 2. Giam dan: ");
    scanf("%d", &order);
    int i = 0;
    int j = i + 1;
    for (; i < count - 1; i++) {
        for (; j < count; j++) {
            if ((order == 1 && arr[i].price > arr[j].price) ||
                (order == 2 && arr[i].price < arr[j].price)) {
                book temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep sach theo gia tien thanh cong!\n");
}


void saveToFile(book arr[], int count) {
    FILE *fptr = fopen("books.dat", "wb"); // Mo file nhi phan
    if (fptr == NULL) {
        printf("Loi! Khong the mo file de ghi.\n");
        return;
    }
    fwrite(arr, sizeof(book), count, fptr); // Ghi toan bo mang trong file
    fclose(fptr);
    printf("Du lieu da duoc luu vao file 'books.dat' thanh cong!\n");
}


void loadFromFile(book arr[], int *count) {
    FILE *fptr = fopen("books.dat", "rb"); // Mo file de doc
    if (fptr == NULL) {
        printf("Khong tim thay file 'books.dat'. He thong se tao file moi khi luu du lieu.\n");
        return;
    }
    int tempCount = fread(arr, sizeof(book), MAX, fptr);
    fclose(fptr);
    
    int i = 0;
    for (; i < tempCount; i++) {
        if (strlen(arr[i].id) > 9 || strlen(arr[i].title) >= 50 || 
            strlen(arr[i].releaseDate) >= 15 || strlen(arr[i].author) >= 30 || arr[i].price < 0) {
            printf("Loi: Du lieu khong hop le trong file! Bo qua muc nay.\n");
            continue;
        }
        arr[*count] = arr[i];
        (*count)++;
    }
    printf("Du lieu da duoc tai tu file 'books.dat'.\n");
}


