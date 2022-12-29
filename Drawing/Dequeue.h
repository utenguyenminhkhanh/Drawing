#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

struct NodeDequeue {
    char so[3];
    int x1, y1, stt;
};

int nQ = 0, nFront = 0, nDequeue;
int x1KhungQ = 650; int x2KhungQ;
int y1KhungQ = 500; int y2KhungQ = 650;
NodeDequeue* mang_Dequeue = new NodeDequeue[10];
int danhDau[10] = { 0 };

void NhapSoDequeue() {
    char temp[3];
    while (nQ < 10) {
        system("cls");
        char s1[] = "Moi nhap phan tu (Nhap xong nhap 0 de tiep tuc nhe!): ";
        outtextxy(100, 50, s1);
        cin >> temp;
        if (strcmp(temp, "0") == 0)
            break;
        strcpy_s(mang_Dequeue[nQ].so, temp);
        mang_Dequeue[nQ].x1 = 620 + 110 * nQ;
        mang_Dequeue[nQ].y1 = 275;
        mang_Dequeue[nQ].stt = nQ;
        nQ++;
    }
    system("cls");
}

void CapNhatManHinhDequeue() {
    system("cls");
    char s2[] = "Cac phan tu da nhap: ";
    outtextxy(600, 175, s2);
    char s31[] = "1. Them phan tu vao Dequeue (tu Front).";
    char s32[] = "2. Them phan tu vao Dequeue (tu Rear).";
    char s41[] = "3. Xoa phan tu khoi Dequeue (tu Front).";
    char s42[] = "4. Xoa phan tu khoi Dequeue (tu Rear).";
    char s51[] = "5. Thoat chuong trinh. ";
    char s52[] = "Moi nhap lua chon de thuc hien (1 hoac 2 hoac 3 hoac 4 hoac 5): ";
    char sfront[] = "Front";
    char srear[] = "Rear";
    outtextxy(600, 25, s31);
    outtextxy(600, 50, s32);
    outtextxy(600, 75, s41);
    outtextxy(600, 100, s42);
    outtextxy(600, 125, s51);
    outtextxy(600, 150, s52);
    drawText(x1KhungQ - 5, y1KhungQ - 30, sfront);
    drawText(x2KhungQ - 40, y1KhungQ - 30, srear);
    for (int i = 0; i < nQ; i++) {
        if (danhDau[i] != 2) {
            rectangle(mang_Dequeue[i].x1 - 10, mang_Dequeue[i].y1 - 10, mang_Dequeue[i].x1 + 80, mang_Dequeue[i].y1 + 80);
            drawText(mang_Dequeue[i].x1 + 22, mang_Dequeue[i].y1 + 22, mang_Dequeue[i].so);
        }
    }
    line(x1KhungQ, y1KhungQ, x2KhungQ, y1KhungQ);
    line(x1KhungQ, y2KhungQ, x2KhungQ, y2KhungQ);
    Sleep(10);
}

void DiChuyenVaoDequeueTheoRear(int k) {
    if (k < 0) {
        char temp[] = "Khong con phan tu nao de Them vao Queue. Bam Enter de tiep tuc nhe!";
        drawText(400, 300, temp);
        _getch();
        return;
    }
    danhDau[k] = 1;
    int i, j = 0;
    for (i = mang_Dequeue[k].x1; i <= x2KhungQ + 100; i = i + 20)
    {
        mang_Dequeue[k].x1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].x1 = x2KhungQ + 100;
    for (i = mang_Dequeue[k].y1; i <= y1KhungQ + 40; i = i + 20)
    {
        mang_Dequeue[k].y1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].y1 = y1KhungQ + 40;
    for (i = mang_Dequeue[k].x1; i >= x1KhungQ + 20 + 120 * (nFront); i = i - 20)
    {
        mang_Dequeue[k].x1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].x1 = x1KhungQ + 20 + 120 * (nFront);
    CapNhatManHinhDequeue();
}

void DiChuyenVaoDequeueTheoFront(int k) {
    if (k < 0) {
        char temp[] = "Khong con phan tu nao de Them vao Queue. Bam Enter de tiep tuc nhe!";
        drawText(400, 300, temp);
        _getch();
        return;
    }
    danhDau[k] = 5;
    int i, j = 0;
    for (i = mang_Dequeue[k].x1; i >= x1KhungQ - 200; i = i - 20)
    {
        mang_Dequeue[k].x1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].x1 = x1KhungQ - 200;
    for (i = mang_Dequeue[k].y1; i <= y1KhungQ + 40; i = i + 20)
    {
        mang_Dequeue[k].y1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].y1 = y1KhungQ + 40;
    for (i = mang_Dequeue[k].x1; i <= x1KhungQ + 20; i = i + 20)
    {
        mang_Dequeue[k].x1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].x1 = x1KhungQ + 20;
    CapNhatManHinhDequeue();
}

int SoORear() {
    for (int i = 0; i <= nQ - 1; i++) {
        if (danhDau[i] == 1)
            return i;
    }
    for (int i = nQ - 1; i >= 0; i--) {
        if (danhDau[i] == 5)
            return i;
    }
    return -1;
}

int SoOFront() {
    for (int i = 0; i <= nQ - 1; i++) {
        if (danhDau[i] == 5)
            return i;
    }
    for (int i = nQ - 1; i >= 0; i--) {
        if (danhDau[i] == 1)
            return i;
    }
    return -1;
}

void DonLenFront() {
    int i;
    int temp = 0;
    while (temp <= nQ - 1) {
        if (danhDau[temp] == 5) {
            int k = temp;
            int x1 = mang_Dequeue[k].x1;
            for (i = mang_Dequeue[k].x1; i >= x1 - 120; i = i - 10)
            {
                mang_Dequeue[k].x1 = i;
                system("cls");
                CapNhatManHinhDequeue();
            }
            mang_Dequeue[k].x1 = x1 - 120;
        }
        temp++;
    }
    temp = nQ - 1;
    while (temp >= 0) {
        if (danhDau[temp] == 1) {
            int k = temp;
            int x1 = mang_Dequeue[k].x1;
            for (i = mang_Dequeue[k].x1; i >= x1 - 120; i = i - 10)
            {
                mang_Dequeue[k].x1 = i;
                system("cls");
                CapNhatManHinhDequeue();
            }
            mang_Dequeue[k].x1 = x1 - 120;
        }
        temp--;
    }
}

void DonXuongRear() {
    int i;
    int temp1 = 0;
    while (temp1 <= nQ - 1) {
        if (danhDau[temp1] == 1) {
            int k = temp1;
            int x1 = mang_Dequeue[k].x1;
            for (i = mang_Dequeue[k].x1; i <= x1 + 120; i = i + 10)
            {
                mang_Dequeue[k].x1 = i;
                system("cls");
                CapNhatManHinhDequeue();
            }
            mang_Dequeue[k].x1 = x1 + 120;
        }
        temp1++;
    }
    temp1 = nQ - 1;
    while (temp1 >= 0) {
        if (danhDau[temp1] == 5) {
            int k = temp1;
            int x1 = mang_Dequeue[k].x1;
            for (i = mang_Dequeue[k].x1; i <= x1 + 120; i = i + 10)
            {
                mang_Dequeue[k].x1 = i;
                system("cls");
                CapNhatManHinhDequeue();
            }
            mang_Dequeue[k].x1 = x1 + 120;
        }
        temp1--;
    }
}

void DiChuyenRaDequeueTheoFront(int k) {
    int i;
    for (i = mang_Dequeue[k].x1; i >= 200; i = i - 20) {
        mang_Dequeue[k].x1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].x1 = 200;
    for (i = mang_Dequeue[k].y1; i <= 350; i = i + 20) {
        mang_Dequeue[k].y1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].y1 = 350;
    nFront--;
    danhDau[k] = 2;
}

void DiChuyenRaDequeueTheoRear(int k) {
    int i;
    for (i = mang_Dequeue[k].x1; i <= 1700; i = i + 20) {
        mang_Dequeue[k].x1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].x1 = 1700;
    for (i = mang_Dequeue[k].y1; i <= 350; i = i + 20) {
        mang_Dequeue[k].y1 = i;
        CapNhatManHinhDequeue();
        system("cls");
    }
    mang_Dequeue[k].y1 = 350;
    nFront--;
    danhDau[k] = 2;
}

void MoPhongDequeue() {
    char choice[3];
    initgraph();
    x2KhungQ = x1KhungQ + 110;
    NhapSoDequeue();
    if (nQ > 1)
        x2KhungQ = x1KhungQ + nQ * 115 + (nQ - 2) * 5;
    else
        x2KhungQ = x1KhungQ + 110;
    CapNhatManHinhDequeue();
    nDequeue = nQ;
    do {
        CapNhatManHinhDequeue();
        cin >> choice;
        if (strcmp(choice, "1") == 0) {
            if (nDequeue - 1 >= 0)
                DonXuongRear();
            DiChuyenVaoDequeueTheoFront(nDequeue - 1);
            nFront++;
            nDequeue--;
        }
        if (strcmp(choice, "2") == 0) {     
            DiChuyenVaoDequeueTheoRear(nDequeue - 1);
            nFront++;
            nDequeue--;
        }
        if (strcmp(choice, "3") == 0) {
            int temp = SoOFront();
            if (temp != -1) {
                DiChuyenRaDequeueTheoFront(temp);
                DonLenFront();
            }
            else {
                char s7[] = "Khong con phan tu nao de Xoa khoi Queue. Bam Enter de tiep tuc nhe!";
                drawText(400, 300, s7);
                _getch();
            }
        }
        if (strcmp(choice, "4") == 0) {
            int temp = SoORear();
            if (temp != -1) {
                DiChuyenRaDequeueTheoRear(temp);
            }
            else {
                char s7[] = "Khong con phan tu nao de Xoa khoi Queue. Bam Enter de tiep tuc nhe!";
                drawText(400, 300, s7);
                _getch();
            }
        }
    } while (strcmp(choice, "5") != 0);
    system("cls");
    char s6[] = "Da thoat khoi chuong trinh. Bam Enter de thoat nhe!";
    drawText(400, 300, s6);
    _getch();
}