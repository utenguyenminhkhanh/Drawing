#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct NodeLink {
    char so[3];
    int x1, y1, stt;

};

int nL = 0, nNode = 0, nLink;
int xNull = 1500; int yNull = 600;
char sNull[] = "NULL";
NodeLink* mang_Link = new NodeLink[10];
int danhDau[10] = { 0 };

void NhapSoLink() {
    char temp[3];
    while (nL < 10) {
        system("cls");
        char s1[] = "Moi nhap phan tu (Nhap xong nhap 0 de tiep tuc nhe!): ";
        outtextxy(100, 50, s1);
        cin >> temp;
        if (strcmp(temp, "0") == 0)
            break;
        strcpy_s(mang_Link[nL].so, temp);
        mang_Link[nL].x1 = 150 + 150 * nL;
        mang_Link[nL].y1 = 300;
        mang_Link[nL].stt = nL - 1;
        nL++;
    }
    system("cls");
}

void CapNhatManHinhLink() {
    system("cls");
    char s2[] = "Cac phan tu da nhap: ";
    outtextxy(100, 175, s2);
    char s3[] = "1. Them phan tu vao Linklist.";
    char s4[] = "2. Xoa phan tu khoi Linklist.";
    char s1[] = "3. Dung chuong trinh.";
    char s5[] = "Moi nhap lua chon de thuc hien (1 hoac 2 hoac 3): ";
    outtextxy(100, 50, s3);
    outtextxy(100, 75, s4);
    outtextxy(100, 100, s1);
    outtextxy(100, 125, s5);
    drawText(xNull + 33, yNull, sNull);
    for (int i = 0; i < nL; i++) {
        if (danhDau[i] != 2) {
            line(mang_Link[i].x1 + 35, mang_Link[i].y1, mang_Link[i].x1 + 95, mang_Link[i].y1);
            line(mang_Link[i].x1 + 95 - 5, mang_Link[i].y1 - 5, mang_Link[i].x1 + 95, mang_Link[i].y1);
            line(mang_Link[i].x1 + 95 - 5, mang_Link[i].y1 + 5, mang_Link[i].x1 + 95, mang_Link[i].y1);
            rectangle(mang_Link[i].x1 - 40, mang_Link[i].y1 - 30, mang_Link[i].x1 + 40, mang_Link[i].y1 + 30);
            drawText(mang_Link[i].x1 - 13, mang_Link[i].y1 - 9, mang_Link[i].so);
        }
    }
    Sleep(10);
}

int SoOLink() {
    for (int i = 0; i <= nL - 1; i++) {
        if (danhDau[i] == 1)
            return i;
    }
    return -1;
}

void DiChuyenVaoLink(int k) {
    if (k < 0) {
        char temp[] = "Khong con phan tu nao de Them vao Link List. Bam Enter de tiep tuc!";
        drawText(500, 200, temp);
        _getch();
        return;
    }
    char s3[] = "1. Them vao phia truoc.";
    char s4[] = "2. Them vao sau mot phan tu tuy chon.";
    char s1[] = "3. Them vao nut cuoi.";
    char s5[] = "Moi nhap lua chon de thuc hien (1 hoac 2 hoac 3): ";
    outtextxy(700, 75, s3);
    outtextxy(700, 100, s4);
    outtextxy(700, 125, s1);
    outtextxy(700, 150, s5);
    char choice[3];
    int i, j = 0;
    cin >> choice;
    if (strcmp(choice, "1") == 0) {
        for (i = mang_Link[k].y1; i <= yNull; i = i + 10)
        {
            mang_Link[k].y1 = i;
            CapNhatManHinhLink();
        }
        mang_Link[k].y1 = i;
        for (i = mang_Link[k].x1; i <= xNull - 70 - (nNode * 142); i = i + 10)
        {
            mang_Link[k].x1 = i;
            CapNhatManHinhLink();
        }
        mang_Link[k].x1 = i;
        CapNhatManHinhLink();
        danhDau[k] = 1;
        nNode++;
        nLink--;
        return;
    }
    if (strcmp(choice, "2") == 0) {
        char s6[] = "Nhap vi tri phan tu can Them: ";
        outtextxy(700, 175, s6);
        int VTNode; cin >> VTNode;
        if (danhDau[VTNode] == 1) {
            for (i = 0; i <= 80; i = i + 10) {
                for (j = 0; j <= nL - 1; j++) {
                    if (mang_Link[j].x1 <= mang_Link[VTNode].x1 && danhDau[j] == 1)
                    {
                        mang_Link[j].x1 = mang_Link[j].x1 - 16;
                        CapNhatManHinhLink();
                    }
                }
            }
            for (i = mang_Link[k].x1; i <= mang_Link[VTNode].x1 + 138; i = i + 10)
            {
                mang_Link[k].x1 = i + 7;
                CapNhatManHinhLink();
            }
            for (i = mang_Link[k].y1; i <= yNull + 10; i = i + 10)
            {
                mang_Link[k].y1 = i;
                CapNhatManHinhLink();
            }
            danhDau[k] = 1;
            drawText(xNull + 45, yNull, sNull);
            nNode++;
            nLink--;
        }
        else {
            char s7[] = "Khong the Them phan tu.";
            drawText(700, 500, s7);
        }
        return;
    }
    if (strcmp(choice, "3") == 0) {        
        for (i = 0; i <= 90; i = i + 10) {
            for (j = 0; j <= nL - 1; j++) {
                if (danhDau[j] == 1)
                {
                    mang_Link[j].x1 = mang_Link[j].x1 - 14;
                    CapNhatManHinhLink();
                }

            }
        }
        for (i = mang_Link[k].x1; i <= xNull - 60; i = i + 10)
        {
            mang_Link[k].x1 = i;
            CapNhatManHinhLink();
        }
        for (i = mang_Link[k].y1; i <= yNull + 10; i = i + 10)
        {
            mang_Link[k].y1 = i;
            CapNhatManHinhLink();
        }
        danhDau[k] = 1;
        nNode++;
        nLink--;
        return;
    }
}

void DiChuyenRaLink() {
    char s3[] = "1. Xoa o phia truoc.";
    char s4[] = "2. Xoa o vi tri tuy chon.";
    char s1[] = "3. Xoa o nut cuoi.";
    char s5[] = "Moi nhap lua chon de thuc hien (1 hoac 2 hoac 3): ";
    outtextxy(700, 75, s3);
    outtextxy(700, 100, s4);
    outtextxy(700, 125, s1);
    outtextxy(700, 150, s5);
    char choice[3];
    int i, j = 0;
    cin >> choice;
    if (strcmp(choice, "1") == 0) {
        int min = xNull;
        int dau_list;
        for (int i = 0; i < nL; i++) {
            if ((danhDau[i] == 1) && (mang_Link[i].x1 < min)) {
                min = mang_Link[i].x1;
                dau_list = i;
            }
        }
        for (i = mang_Link[dau_list].y1; i <= 800; i = i + 10)
        {
            mang_Link[dau_list].y1 = i;
            CapNhatManHinhLink();
            system("cls");
        }
        mang_Link[dau_list].y1 = i;
        CapNhatManHinhLink();
        danhDau[dau_list] = 2;
        nNode--;
        return;
    }
    if (strcmp(choice, "2") == 0) {
        char s6[] = "Nhap vi tri phan tu can Xoa: ";
        outtextxy(700, 175, s6);
        int VTNode; cin >> VTNode;
        if (danhDau[VTNode] == 1) {
            for (i = mang_Link[VTNode].y1; i <= 850; i = i + 10)
            {
                mang_Link[VTNode].y1 = i;
                CapNhatManHinhLink();
                system("cls");
            }
            mang_Link[VTNode].y1 = i;
            for (i = 0; i <= 90; i = i + 10) {
                for (j = 0; j <= nL - 1; j++) {
                    if (mang_Link[j].x1 < mang_Link[VTNode].x1 && danhDau[j] == 1)
                    {
                        mang_Link[j].x1 = mang_Link[j].x1 + 14;
                        CapNhatManHinhLink();
                        system("cls");
                    }
                }
            }
            nNode--;
            danhDau[VTNode] = 2;
        }
        else {
            char s7[] = "Khong the Xoa phan tu.";
            drawText(700, 500, s7);
        }
        return;
    }
    if (strcmp(choice, "3") == 0) {
        int max = 0;
        int cuoi_list;
        for (int i = 0; i <= nL - 1; i++) {
            if ((danhDau[i] == 1) && (mang_Link[i].x1 > max)) {
                max = mang_Link[i].x1;
                cuoi_list = i;
            }
        }
        for (i = mang_Link[cuoi_list].y1; i <= 800; i = i + 10)
        {
            mang_Link[cuoi_list].y1 = i;
            CapNhatManHinhLink();
            system("cls");
        }
        for (i = 0; i <= 90; i = i + 10) {
            for (j = 0; j <= nL - 1; j++) {
                if ((mang_Link[j].x1 < xNull) && danhDau[j] == 1)
                {
                    mang_Link[j].x1 = mang_Link[j].x1 + 14;
                    CapNhatManHinhLink();
                    system("cls");
                }
            }
        }
        nNode--;
        danhDau[cuoi_list] = 2;
        return;
    }
}

void MoPhongLink() {
    char choice[3];
    initgraph();
    NhapSoLink();
    CapNhatManHinhLink();
    nLink = nL;
    do {
        CapNhatManHinhLink();
        cin >> choice;
        if (strcmp(choice, "1") == 0) {
            DiChuyenVaoLink(nLink - 1);
        }
        int temp = SoOLink();
        if (strcmp(choice, "2") == 0) {
            if (temp != -1) {
                DiChuyenRaLink();
            }
            else {
                char s7[] = "Khong con phan tu nao de Xoa khoi Link List. Bam Enter de tiep tuc!";
                drawText(400, 200, s7);
                _getch();
            }
        }
        CapNhatManHinhLink();
        system("cls");
    } while (strcmp(choice, "3") != 0);
    system("cls");
    char s6[] = "Da thoat chuong trinh. Bam Enter de thoat khoi chuong trinh nhe!";
    drawText(400, 300, s6);
    _getch();
}
