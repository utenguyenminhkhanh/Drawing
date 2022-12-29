#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct NodeCircle {
    char so[3];
    NodeCircle* next;
    int x1, y1, stt;

};
int nC = 0, nnode = 0, nCircle;
int xnull = 1100; int ynull = 400;

NodeCircle* mang_Circle = new NodeCircle[10];
int danhDau_C[10] = { 0 };
void NhapSoCircle() {
    char temp[5];
    while (nC < 10) {
        system("cls");
        char s1[] = "Nhap so (Nhap 0 de thoat): ";
        outtextxy(100, 50, s1);
        cin >> temp;
        if (strcmp(temp, "0") == 0)
            break;
        strcpy_s(mang_Circle[nC].so, temp);
        mang_Circle[nC].x1 = 70 + 100 * nC;
        mang_Circle[nC].y1 = 275;
        mang_Circle[nC].stt = nC - 1;
        nC++;
    }
    system("cls");
}
void CapNhatManHinhCircle() {
    system("cls");
    char s2[] = "Cac Node da nhap: ";
    outtextxy(100, 175, s2);
    char s3[] = "1. Cho vao Circle List.";
    char s4[] = "2. Xoa khoi Circle List.";
    char s1[] = "3. Dung chuong trinh.";
    char s5[] = "Nhap lua chon: ";
    outtextxy(100, 50, s3);
    outtextxy(100, 75, s4);
    outtextxy(100, 100, s1);
    outtextxy(100, 125, s5);
    line(xnull - 15, ynull, xnull - 15, ynull + 50);
    line(xnull - 15, ynull + 50, xnull - nnode * 120, ynull + 50);
    line(xnull - nnode * 120, ynull + 50, xnull - nnode * 120, ynull - 16);

    for (int i = 0; i < nC; i++) {
        if (danhDau_C[i] != 2) {
            line(mang_Circle[i].x1 - 80, mang_Circle[i].y1, mang_Circle[i].x1 - 40, mang_Circle[i].y1);
            line(mang_Circle[i].x1 - 40 - 5, mang_Circle[i].y1 - 5, mang_Circle[i].x1 - 40, mang_Circle[i].y1);
            line(mang_Circle[i].x1 - 40 - 5, mang_Circle[i].y1 + 5, mang_Circle[i].x1 - 40, mang_Circle[i].y1);
            rectangle(mang_Circle[i].x1 - 40, mang_Circle[i].y1 - 20, mang_Circle[i].x1 + 40, mang_Circle[i].y1 + 20);
            lineMau(mang_Circle[i].x1 + 5, mang_Circle[i].y1 - 20, mang_Circle[i].x1 + 5, mang_Circle[i].y1 + 19);
            drawText(mang_Circle[i].x1 - 27, mang_Circle[i].y1 - 9, mang_Circle[i].so);
            drawText(mang_Circle[i].x1, mang_Circle[i].y1 - 9, "Next");


        }
    }

    //Sleep(10);
}

void DiChuyenVaoCircle(int k) {
    if (k < 0) {
        char temp[] = "Khong con so nao de dua vao. Bam Enter de tiep tuc";
        drawText(500, 200, temp);
        _getch();
        return;
    }
    //----------------------------------//
    // ?ánh d?u s? th? k trong m?ng ?ã vào queue

    //----------------------------------//


    char s3[] = "1. Insert vao phia truoc.";
    char s4[] = "2. Insert vao sau mot Node da cho.";
    char s1[] = "3. Insert vao nut cuoi.";
    char s5[] = "Nhap lua chon: ";
    outtextxy(300, 50, s3);
    outtextxy(300, 75, s4);
    outtextxy(300, 100, s1);
    outtextxy(300, 125, s5);
    char choice[3];
    int i, j = 0;
    cin >> choice;
    if (strcmp(choice, "1") == 0) {

        for (i = mang_Circle[k].y1; i <= ynull - 20; i = i + 10)
        {
            mang_Circle[k].y1 = i;
            CapNhatManHinhCircle();
            system("cls");
        }
        mang_Circle[k].y1 = i;
        for (i = mang_Circle[k].x1; i <= xnull - 50 - (nnode * 120); i = i + 10)
        {
            mang_Circle[k].x1 = i;
            CapNhatManHinhCircle();
            system("cls");
        }
        mang_Circle[k].x1 = i;
        CapNhatManHinhCircle();
        danhDau_C[k] = 1;
        nnode++;
        nCircle--;
        return;

    }

    if (strcmp(choice, "2") == 0) {
        char s6[] = "Nhap vi tri Node can them Node vao sau: ";
        outtextxy(500, 125, s6);
        int VTnode; cin >> VTnode;
        if (danhDau_C[VTnode] == 1) {
            for (i = 0; i <= 110; i = i + 10) {
                for (j = 0; j <= nC - 1; j++) {
                    if (mang_Circle[j].x1 <= mang_Circle[VTnode].x1 && danhDau_C[j] == 1)
                    {
                        mang_Circle[j].x1 = mang_Circle[j].x1 - 10;
                        CapNhatManHinhCircle();
                        system("cls");
                    }
                }
            }
            for (i = mang_Circle[k].x1; i <= mang_Circle[VTnode].x1 + 120; i = i + 10)
            {
                mang_Circle[k].x1 = i;
                CapNhatManHinhCircle();
                system("cls");
            }
            for (i = mang_Circle[k].y1; i <= ynull - 10; i = i + 10)
            {
                mang_Circle[k].y1 = i;
                CapNhatManHinhCircle();
                system("cls");
            }
            danhDau_C[k] = 1;
            nnode++;
            nCircle--;
        }
        else {
            char s7[] = "Khong Insert Node duoc: ";
            drawText(400, 200, s7);
        }


        return;
    }

    if (strcmp(choice, "3") == 0) {

        for (i = 0; i <= 110; i = i + 10) {
            for (j = 0; j <= nC - 1; j++) {
                if (danhDau_C[j] == 1)
                {
                    mang_Circle[j].x1 = mang_Circle[j].x1 - 10;
                    CapNhatManHinhCircle();
                    system("cls");
                }

            }
        }
        for (i = mang_Circle[k].x1; i <= xnull - 40; i = i + 10)
        {
            mang_Circle[k].x1 = i;
            CapNhatManHinhCircle();
            system("cls");
        }
        for (i = mang_Circle[k].y1; i <= ynull - 10; i = i + 10)
        {
            mang_Circle[k].y1 = i;
            CapNhatManHinhCircle();
            system("cls");
        }
        danhDau_C[k] = 1;
        nnode++;
        nCircle--;
        return;
    }

}

int SoOCircle() {

    for (int i = 0; i <= nC - 1; i++) {

        if (danhDau_C[i] == 1)
            return i;
    }

    return -1;
}
void DiChuyenRaCircle() {

    char s3[] = "1. Delete o phia truoc.";
    char s4[] = "2. Delete mot Node da cho.";
    char s1[] = "3. Delete o nut cuoi.";
    char s5[] = "Nhap lua chon: ";
    outtextxy(300, 50, s3);
    outtextxy(300, 75, s4);
    outtextxy(300, 100, s1);
    outtextxy(300, 125, s5);
    char choice[3];
    int i, j = 0;
    cin >> choice;
    if (strcmp(choice, "1") == 0) {
        int min = xnull;
        int dau_circle;
        for (int i = 0; i < nC; i++) {
            if ((danhDau_C[i] == 1) && (mang_Circle[i].x1 < min)) {
                min = mang_Circle[i].x1;
                dau_circle = i;
            }
        }
        for (i = mang_Circle[dau_circle].y1; i <= 800; i = i + 10)
        {
            mang_Circle[dau_circle].y1 = i;
            CapNhatManHinhCircle();
            system("cls");
        }
        mang_Circle[dau_circle].y1 = i;
        CapNhatManHinhCircle();
        danhDau_C[dau_circle] = 2;
        nnode--;
        return;

    }
    if (strcmp(choice, "2") == 0) {
        char s6[] = "Nhap vi tri Node can Delete: ";
        outtextxy(500, 125, s6);
        int VTnode; cin >> VTnode;
        if (danhDau_C[VTnode] == 1) {
            for (i = mang_Circle[VTnode].y1; i <= 800; i = i + 10)
            {
                mang_Circle[VTnode].y1 = i;
                CapNhatManHinhCircle();
                system("cls");
            }
            mang_Circle[VTnode].y1 = i;
            for (i = 0; i <= 110; i = i + 10) {
                for (j = 0; j <= nC - 1; j++) {
                    if (mang_Circle[j].x1 < mang_Circle[VTnode].x1 && danhDau_C[j] == 1)
                    {
                        mang_Circle[j].x1 = mang_Circle[j].x1 + 10;
                        CapNhatManHinhCircle();
                        system("cls");
                    }
                }
            }
            nnode--;
            danhDau_C[VTnode] = 2;
        }
        else {
            char s7[] = "Khong Delete Node duoc: ";
            drawText(400, 200, s7);
        }
        return;
    }
    if (strcmp(choice, "3") == 0) {
        int max = 0;
        int cuoi_circle;
        for (int i = 0; i <= nC - 1; i++) {
            if ((danhDau_C[i] == 1) && (mang_Circle[i].x1 > max)) {
                max = mang_Circle[i].x1;
                cuoi_circle = i;
            }
        }
        for (i = mang_Circle[cuoi_circle].y1; i <= 800; i = i + 10)
        {
            mang_Circle[cuoi_circle].y1 = i;
            CapNhatManHinhCircle();
            system("cls");

        }
        for (i = 0; i <= 110; i = i + 10) {
            for (j = 0; j <= nC - 1; j++) {
                if ((mang_Circle[j].x1 < xnull) && danhDau_C[j] == 1)
                {
                    mang_Circle[j].x1 = mang_Circle[j].x1 + 10;
                    CapNhatManHinhCircle();
                    system("cls");
                }
            }
        }
        nnode--;
        danhDau_C[cuoi_circle] = 2;
        return;
        //----------------------------------//
        // ?ánh d?u s? th? k trong m?ng ?ã ra kh?i queue
        //----------------------------------//
    }
}
void MoPhongCircle() {
    char choice[3];
    initgraph();
    NhapSoCircle();

    CapNhatManHinhCircle();

    nCircle = nC;
    do {
        CapNhatManHinhCircle();
        cin >> choice;
        if (strcmp(choice, "1") == 0) {
            DiChuyenVaoCircle(nCircle - 1);
        }
        int temp = SoOCircle();

        if (strcmp(choice, "2") == 0) {
            if (temp != -1) {
                DiChuyenRaCircle();
            }
            else {
                char s7[] = "Khong co phan tu trong Stack. Bam Enter de tiep tuc";
                drawText(400, 200, s7);
                _getch();
            }
        }
        CapNhatManHinhCircle();
        system("cls");

    } while (strcmp(choice, "3") != 0);

    system("cls");
    char s6[] = "Da thoat chuong trinh. Bam Enter de thoat khoi chuong trinh";
    drawText(400, 300, s6);
    _getch();

}

