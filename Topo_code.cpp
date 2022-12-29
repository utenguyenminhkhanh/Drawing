#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


struct TOPO
{
	int SUC;
	TOPO* next;
};

struct NODE
{
	int COUNT;
	TOPO* TOP;
};
int main() {
	TOPO* P;
	int QLINK[20] = { 0 };
	NODE A[20];
	int n;

	cout << "Nhap so luong Node:\n";
	cin >> n; 
	int N = n;
	for (int i = 1; i <= n; i++)
	{
		A[i].COUNT = 0;
		A[i].TOP = NULL;
	}

	cout << "Nhap cac Huong (1 2):\n";
	for (int i = 0; i < n; i++)
	{
		int j, k;
		cin >> j >> k;
		A[k].COUNT++;
		P = (TOPO*)malloc(sizeof(TOPO));
		P->SUC = k;
		P->next = A[j].TOP;
		A[j].TOP = P;
	}


	int R = 0;
	QLINK[0] = 0;
	for (int k = 1; k <= n; k++)
	{
		if (A[k].COUNT == 0)
		{
			QLINK[R] = k;
			R = k;
		}
	}

	cout << "Sap xep theo topological sort: ";
	int F = QLINK[0];
	while (F != 0) {
		cout << F << " ";
		N--;
		P = A[F].TOP;
		while (P != NULL) {
			A[P->SUC].COUNT--;
			if (A[P->SUC].COUNT == 0)
			{
				QLINK[R] = P->SUC;
				R = P->SUC;
			}
			P = P->next;
		}
		F = QLINK[F];
	}
	return 0;
}