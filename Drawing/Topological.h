#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <conio.h>

struct NodeTopo {
    char so[3], huong[5];
    NodeTopo* next;
    int x1, y1;
    int cung_vao = 0, cung_ra = 0;
    int nodera1 = 0, nodera2 = 0;
};

int nT = 0, nOut = 0, nHuong;


NodeTopo* mang_Topo = new NodeTopo[10];
int danhDau_T[10] = { 0 };
void NhapSoTopo() {
    char temp1[5], temp2[5], temp[5];
    char s1[] = "Nhap so Node (Nhap 0 de thoat): ";
    char s2[] = "Nhap so huong: ";
    char s3[] = "Nhap huong: ";
    outtextxy(100, 50, s1);
    cin >> nT;
    outtextxy(100, 70, s2);
    cin >> nHuong;
    outtextxy(100, 100, s3);
    int stt = 0;
    int x = 0, y = 0;
    int danhdau1, danhdau2;
    for (int i = 0; i < nHuong; i++)
    {
        int dem1 = 0, dem2 = 0;
        cin >> temp1; cin >> temp2;
        for (int j = 0; j < nT; j++) {
            if (strcmp(mang_Topo[j].so, temp1) == 0) {
                danhdau1 = j;
                break;
            }
            else
                dem1++;
        }
        for (int j = 0; j < nT; j++) {
            if (strcmp(mang_Topo[j].so, temp2) == 0) {
                danhdau2 = j;
                break;
            }
            else
                dem2++;
        }
        if (dem1 == nT && dem2 == nT) {
            strcpy_s(mang_Topo[stt].so, temp1);

            mang_Topo[stt].x1 = 100;
            mang_Topo[stt].y1 = 100;
            mang_Topo[stt].cung_ra++;

            stt++;

            strcpy_s(mang_Topo[stt].so, temp2);

            mang_Topo[stt].x1 = mang_Topo[stt - 1].x1 + 100;
            mang_Topo[stt].y1 = mang_Topo[stt - 1].y1;
            mang_Topo[stt].cung_vao++;
            mang_Topo[stt - 1].nodera1 = stt;


            stt++;
        }
        if (dem1 == nT && dem2 != nT) {
            strcpy_s(mang_Topo[stt].so, temp1);

            mang_Topo[stt].x1 = mang_Topo[danhdau2].x1 - 100;
            mang_Topo[stt].y1 = mang_Topo[danhdau2].y1 + mang_Topo[danhdau2].cung_vao * 100;
            mang_Topo[stt].cung_ra++;
            mang_Topo[danhdau2].cung_vao++;
            mang_Topo[stt].nodera1 = danhdau2;

            stt++;
        }
        if (dem1 != nT && dem2 == nT) {
            strcpy_s(mang_Topo[stt].so, temp2);

            mang_Topo[stt].x1 = mang_Topo[danhdau1].x1 + 100;
            mang_Topo[stt].y1 = mang_Topo[danhdau1].y1 + mang_Topo[danhdau1].cung_ra * 100;
            mang_Topo[danhdau1].cung_ra++;
            mang_Topo[stt].cung_vao++;
            if (mang_Topo[danhdau1].nodera1 == 0) {
                mang_Topo[danhdau1].nodera1 = stt;
            }
            else {
                mang_Topo[danhdau1].nodera2 = stt;
            }

            stt++;
        }
        if (dem1 != nT && dem2 != nT) {
            mang_Topo[danhdau1].cung_ra++;
            mang_Topo[danhdau2].cung_vao++;
            if (mang_Topo[danhdau1].nodera1 == 0) {
                mang_Topo[danhdau1].nodera1 = danhdau2;
            }
            else {
                mang_Topo[danhdau1].nodera2 = danhdau2;
            }
        }
    }
    system("cls");

}

void CapNhatManHinhTopo() {
    system("cls");
    for (int i = 0; i <= nT - 1; i++) {
        if (danhDau_T[i] != 2) {
            circle(mang_Topo[i].x1, mang_Topo[i].y1, 40);
            drawText(mang_Topo[i].x1 - 11, mang_Topo[i].y1 - 10, mang_Topo[i].so);
            drawText(700, 200, "List Queue: ");
            drawText(700, 250, "Topological: ");
            if (mang_Topo[i].nodera2 == 0) {
                huongTopo(mang_Topo[i].x1, mang_Topo[i].y1, mang_Topo[mang_Topo[i].nodera1].x1, mang_Topo[mang_Topo[i].nodera1].y1);
            }
            else
            {
                huongTopo(mang_Topo[i].x1, mang_Topo[i].y1, mang_Topo[mang_Topo[i].nodera1].x1, mang_Topo[mang_Topo[i].nodera1].y1);
                huongTopo(mang_Topo[i].x1, mang_Topo[i].y1, mang_Topo[mang_Topo[i].nodera2].x1, mang_Topo[mang_Topo[i].nodera2].y1);
            }

        }

    }

    Sleep(10);
}

void MoPhongTopo() {
    char choice[3];
    initgraph();
    NhapSoTopo();

    int Link_Queue[10] = { 0 };
    int M_Topo[10] = { 0 };
    int So_link_Queue = 0;
    int So_Topo = 0;
    CapNhatManHinhTopo();
    _getch();
    int nTopo = nT;
    while (nTopo > 0) {
        for (int i = 0; i <= nT - 1; i++) {
            if (mang_Topo[i].cung_vao == 0) {
                Link_Queue[So_link_Queue] = i;
                circleMau(mang_Topo[i].x1, mang_Topo[i].y1, 40);
                drawTextMau(mang_Topo[i].x1 - 11, mang_Topo[i].y1 - 10, mang_Topo[i].so);

                Sleep(2000);
                mang_Topo[i].cung_vao = -1;
                So_link_Queue++;
            }
        }
        for (int i = 0; i < So_link_Queue; i++) {
            drawText(800 + i * 40, 200, mang_Topo[Link_Queue[i]].so);
            Sleep(2000);
        }
        if (So_link_Queue > 0) {
            M_Topo[So_Topo] = Link_Queue[0];
            mang_Topo[mang_Topo[M_Topo[So_Topo]].nodera1].cung_vao--;
            mang_Topo[mang_Topo[M_Topo[So_Topo]].nodera2].cung_vao--;

            int dich_len = So_link_Queue;
            for (int i = 0; i < dich_len - 1; i++) {
                Link_Queue[i] = Link_Queue[i + 1];
            }
            So_link_Queue--;
            So_Topo++;
            nTopo--;
        }
        system("cls");
        CapNhatManHinhTopo();


        for (int i = 0; i <= nT - 1; i++) {
            if (mang_Topo[i].cung_vao <= 0) {
                circleMau(mang_Topo[i].x1, mang_Topo[i].y1, 40);
                drawTextMau(mang_Topo[i].x1 - 11, mang_Topo[i].y1 - 10, mang_Topo[i].so);

            }
        }
        for (int i = 0; i < So_Topo; i++) {
            drawText(800 + i * 40, 250, mang_Topo[M_Topo[i]].so);
            Sleep(2000);
        }
        for (int i = 0; i < So_link_Queue; i++) {
            drawText(800 + i * 40, 200, mang_Topo[Link_Queue[i]].so);
            Sleep(2000);
        }

    }
}
