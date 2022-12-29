#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

struct NodeQueue {
    char so[3];
    int x1, y1, stt;
};

int nQ = 0, nFront = 0, nQueue;
int x1KhungQ = 300; int x2KhungQ;
int y1KhungQ = 500; int y2KhungQ = 650;
NodeQueue* mangQ = new NodeQueue[10];
int danhDau[10] = { 0 };

void NhapSoQueue() {
    char temp[5];
    while (nQ < 10) {
        system("cls");
        char s1[] = "Moi nhap phan tu (Nhap xong nhap 0 de tiep tuc nhe!): ";
        outtextxy(100, 50, s1);
        cin >> temp;
        if (strcmp(temp, "0") == 0)
            break;
        strcpy_s(mangQ[nQ].so, temp);
        mangQ[nQ].x1 = 120 + 110 * nQ;
        mangQ[nQ].y1 = 275;
        mangQ[nQ].stt = nQ;
        nQ++;
    }
    system("cls");

}

void CapNhatManHinhQueue() {
    system("cls");
    char s2[] = "Cac phan tu da nhap: ";
    outtextxy(100, 175, s2);
    char s3[] = "1. Them phan tu vao Queue (tu Rear).";
    char s4[] = "2. Xoa phan tu khoi Queue (tu Front).";
    char s1[] = "3. Thoat chuong trinh.";
    char s5[] = "Moi nhap lua chon de thuc hien (1 hoac 2 hoac 3): ";
    char sfront[] = "Front";
    char srear[] = "Rear";
    outtextxy(100, 50, s3);
    outtextxy(100, 75, s4);
    outtextxy(100, 100, s1);
    outtextxy(100, 125, s5);
    drawText(x1KhungQ - 5, y1KhungQ - 30, sfront);
    drawText(x2KhungQ - 40, y1KhungQ - 30, srear);
    for (int i = 0; i < nQ; i++) {
        if (danhDau[i] != 2) {
            rectangle(mangQ[i].x1 - 10, mangQ[i].y1 - 10, mangQ[i].x1 + 80, mangQ[i].y1 + 80);
            drawText(mangQ[i].x1 + 22, mangQ[i].y1 + 22, mangQ[i].so);
        }
    }
    line(x1KhungQ, y1KhungQ, x2KhungQ, y1KhungQ);
    line(x1KhungQ, y2KhungQ, x2KhungQ, y2KhungQ);
    Sleep(10);
}

void DiChuyenVaoQueue(int k) {
    if (k < 0) {
        char temp[] = "Khong con phan tu nao de Them vao Queue. Bam Enter de tiep tuc nhe!";
        drawText(400, 300, temp);
        _getch();
        return;
    }
    danhDau[k] = 1;

    int i, j = 0;
    for (i = mangQ[k].x1; i <= x2KhungQ + 200; i = i + 20)
    {
        mangQ[k].x1 = i;
        CapNhatManHinhQueue();
        system("cls");
    }
    mangQ[k].x1 = x2KhungQ + 100;
    for (i = mangQ[k].y1; i <= y1KhungQ + 40; i = i + 20)
    {
        mangQ[k].y1 = i;
        CapNhatManHinhQueue();
        system("cls");
    }
    mangQ[k].y1 = y1KhungQ + 40;
    for (i = mangQ[k].x1; i >= x1KhungQ + 20 + 120 * (nFront); i = i - 20)
    {
        mangQ[k].x1 = i;
        CapNhatManHinhQueue();
        system("cls");
    }
    mangQ[k].x1 = x1KhungQ + 20 + 120 * (nFront);
    CapNhatManHinhQueue();
}

void DiChuyenRaQueue(int k) {
    int i;

    for (i = mangQ[k].x1; i >= 25; i = i - 20) {
        mangQ[k].x1 = i;
        CapNhatManHinhQueue();
        system("cls");
    }

    mangQ[k].x1 = 25;
    for (i = mangQ[k].y1; i <= 350; i = i + 20) {
        mangQ[k].y1 = i;
        CapNhatManHinhQueue();
        system("cls");
    }
    mangQ[k].y1 = 350;
    nFront--;
    danhDau[k] = 2;
}

int SoOFront() {
    for (int i = nQ - 1; i >= 0; i--) {
        if (danhDau[i] == 1)
            return i;
    }
    return -1;
}

void DonLenFront() {
    int i;
    int temp = SoOFront();
    while (temp >= 0 && danhDau[temp] == 1) {
        int k = temp;
        int x1 = mangQ[k].x1;
        for (i = mangQ[k].x1; i >= x1 - 110; i = i - 10)
        {
            mangQ[k].x1 = i;
            system("cls");
            CapNhatManHinhQueue();
        }
        mangQ[k].x1 = i;
        temp--;
    }
}


void MoPhongQueue() {
    char choice[3];
    initgraph();
    NhapSoQueue();

    if (nQ > 1)
        x2KhungQ = x1KhungQ + nQ * 115 + (nQ - 2) * 5;
    else
        x2KhungQ = x1KhungQ + 110;
    CapNhatManHinhQueue();
    nQueue = nQ;
    do {
        CapNhatManHinhQueue();
        cin >> choice;
        if (strcmp(choice, "1") == 0) {
            DiChuyenVaoQueue(nQueue - 1);
            nFront++;
            nQueue--;
        }
        if (strcmp(choice, "2") == 0) {
            int temp = SoOFront();
            if (temp != -1) {
                DiChuyenRaQueue(temp);
                DonLenFront();
            }
            else {
                char s7[] = "Khong con phan tu nao de Xoa khoi Queue. Bam Enter de tiep tuc nhe!";
                drawText(400, 300, s7);
                _getch();
            }
        }
        CapNhatManHinhQueue();
        system("cls");
    } while (strcmp(choice, "3") != 0);
    system("cls");
    char s6[] = "Da thoat khoi chuong trinh. Bam Enter de thoat nhe!";
    drawText(400, 300, s6);
    _getch();
}