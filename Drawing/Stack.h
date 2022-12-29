#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

struct NodeStack {
    char so[3];
    int x1, y1, stt;
};

int nS = 0, nTop = 0, nStack;
int x1Khung_Stack = 1100; int x2Khung_Stack = 1100; int x3Khung_Stack = 1220; int x4Khung_Stack = 1220;
int y1Khung_Stack = 450; int y2Khung_Stack = 1000; int y3Khung_Stack = 1000; int y4Khung_Stack = 450;
NodeStack* mang_Stack = new NodeStack[10];
int danhDau[10] = { 0 };

void NhapSoStack() {
    char temp[5];
    while (nS < 10) // nS nhu i trong for
    {
        system("cls");
        char s1[] = "Moi nhap phan tu (Nhap xong nhap 0 de tiep tuc nhe!): ";
        outtextxy(100, 50, s1);
        cin >> temp; // nhap gia tri
        if (strcmp(temp, "0") == 0)
            break;
        strcpy_s(mang_Stack[nS].so, temp); // copy temp vao mang_Stack[nS].so
        mang_Stack[nS].x1 = 125 + 130 * nS;
        mang_Stack[nS].y1 = 260;
        mang_Stack[nS].stt = nS;
        nS++;
    }
    system("cls");
}

void CapNhatManHinhStack() {
    system("cls");
    char s2[] = "Cac phan tu da nhap: ";
    outtextxy(100, 160, s2);
    char s3[] = "1. Them phan tu vao Stack.";
    char s4[] = "2. Xoa phan tu khoi Stack.";
    char s1[] = "3. Dung chuong trinh.";
    char s5[] = "Moi nhap lua chon de thuc hien (1 hoac 2 hoac 3): ";
    char stop[] = "Top";
    outtextxy(100, 50, s3);
    outtextxy(100, 75, s4);
    outtextxy(100, 100, s1);
    outtextxy(100, 125, s5);
    drawText(x4Khung_Stack + 10, y4Khung_Stack + 10, stop); // ve chu "Top" theo cot

    for (int i = 0; i < nS; i++) {
        if (danhDau[i] != 2) {
            rectangle(mang_Stack[i].x1 - 10, mang_Stack[i].y1 - 10, mang_Stack[i].x1 + 80, mang_Stack[i].y1 + 80);
            drawText(mang_Stack[i].x1 + 22, mang_Stack[i].y1 + 22, mang_Stack[i].so);
        }
    }
    line(x1Khung_Stack, y1Khung_Stack, x2Khung_Stack, y2Khung_Stack);
    line(x2Khung_Stack, y2Khung_Stack, x3Khung_Stack, y3Khung_Stack);
    line(x4Khung_Stack, y4Khung_Stack, x3Khung_Stack, y3Khung_Stack);
    Sleep(1);
}

void DiChuyenVaoStack(int k) {
    if (k < 0) {
        char temp[] = "Khong con so nao de dua vao. Bam Enter de tiep tuc";
        drawText(500, 300, temp);
        _getch();
        return;
    }

    if (y2Khung_Stack - 30 - (nTop * 30) < y1Khung_Stack)
    {
        char temp[] = "Mang da day, khong them Node vao duoc. Bam Enter de tiep tuc";
        drawText(500, 300, temp);
        _getch();
        return;
    }
    danhDau[k] = 1;
    int i, j = 0;
    for (i = mang_Stack[k].x1; i <= x1Khung_Stack + 25; i = i + 10)
    {
        mang_Stack[k].x1 = i;
        CapNhatManHinhStack();
        system("cls");
    }
    mang_Stack[k].x1 = x1Khung_Stack + 25;
    for (i = mang_Stack[k].y1; i <= y2Khung_Stack - 100 - (nTop * 100); i = i + 10)
    {
        mang_Stack[k].y1 = i;
        CapNhatManHinhStack();
        system("cls");
    }
    mang_Stack[k].y1 = i;
    CapNhatManHinhStack();
}

void DiChuyenRaStack(int k) {
    int i;
    for (i = mang_Stack[k].y1; i >= 280; i = i - 10) {
        mang_Stack[k].y1 = i;
        CapNhatManHinhStack();
        system("cls");
    }
    mang_Stack[k].y1 = 280;
    for (i = mang_Stack[k].x1; i <= x1Khung_Stack + 625; i = i + 10) {
        mang_Stack[k].x1 = i;
        CapNhatManHinhStack();
        system("cls");
    }
    mang_Stack[k].x1 = i;
    nTop--;

    danhDau[k] = 2;
}

int SoOTop() {
    for (int i = 0; i <= nS - 1; i++) {
        if (danhDau[i] == 1)
            return i;
    }
    return -1;
}
void MoPhongStack() {
    char choice[3]; // lua chon
    initgraph();
    NhapSoStack(); // nhap gia tri

    CapNhatManHinhStack(); // hien gia tri vua nhap

    nStack = nS;
    do {
        CapNhatManHinhStack();
        cin >> choice;
        if (strcmp(choice, "1") == 0) {
            DiChuyenVaoStack(nStack - 1);
            nTop++;
            nStack--;
        }

        if (strcmp(choice, "2") == 0) {
            int temp = SoOTop();
            if (temp != -1) {
                DiChuyenRaStack(temp);
            }
            else {
                char s7[] = "Khong co phan tu trong Stack. Bam Enter de tiep tuc";
                drawText(500, 300, s7);
                _getch();
            }
        }
        CapNhatManHinhStack();
        system("cls");
    } while (strcmp(choice, "3") != 0);

    system("cls");
    char s6[] = "Da thoat chuong trinh. Bam Enter de thoat khoi chuong trinh";
    drawText(500, 300, s6);
    _getch();

}