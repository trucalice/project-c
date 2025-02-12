#include <stdio.h>
#include <string.h>
#include "function.h"

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
    printf("Nhap ID sach: ");
    scanf("%s", arr[*count].id);
    printf("Nhap ten sach: ");
    scanf(" %[^\n]", arr[*count].title);
    printf("Nhap ngay phat hanh: ");
    scanf("%s", arr[*count].releaseDate);
    printf("Nhap ten tac gia: ");
    scanf(" %[^\n]", arr[*count].author);
    printf("Nhap gia tien: ");
    scanf("%f", &arr[*count].price);
    (*count)++;
    printf("Them sach thanh cong!\n");
}

void displayBooks(book arr[], int count) {
    printf("\n| %-10s | %-15s | %-15s | %-20s | %-11s|\n", "ID", "Ten", "Ngay PH", "Tac Gia", "Gia");
    printf("--------------------------------------------------------------------------\n");
    int i = 0;
    for (;i < count; i++) {
        printf("| %-10s | %-15s | %-15s | %-20s | %-10.2f |\n", arr[i].id, arr[i].title, arr[i].releaseDate, arr[i].author, arr[i].price);
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
    printf("\n%| -10s | %-30s | %-15s | %-20s | %-10s|\n", "ID", "Ten", "Ngay PH", "Tac Gia", "Gia");
    printf("--------------------------------------------------------------------------\n");
    int found = 0;
    int i = 0;
    for (; i < count; i++) {
        if (strstr(arr[i].title, title) != NULL) {
            printf("%-10s %-30s %-15s %-20s %-10.2f\n", arr[i].id, arr[i].title, arr[i].releaseDate, arr[i].author, arr[i].price);
            found = 1;
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
            if ((order == 1 && arr[i].price > arr[j].price) || (order == 2 && arr[i].price < arr[j].price)) {
                book temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Sap xep sach theo gia tien thanh cong!\n");
}

