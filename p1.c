#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int SetFlag(unsigned char a, int k)
{
	return a | (1 << k);
}


int GetFlag(unsigned char a, int k)
{
	return 1 & (a >> k);
}

void initializarea(unsigned char a[126])
{
	int i;
	for (i = 0; i <= 125; i++)
		a[i] = 0;
}

void citirea(unsigned char a[126])
{
	int n;
	printf("Pentru oprire introduceti 1001.\n");
	do
	{
		printf("Introduceti numarul dorit: ");
		scanf("%d", &n);
		a[n / 8] = SetFlag(a[n / 8], n % 8);
	} while (n != 1001);
}

void afisarea(unsigned char a[126])
{
	int i;
	for (i = 0; i <= 1000; i++)
	{
		if (GetFlag(a[i / 8], i % 8))
			printf("%d ", i);
	}
	printf("\n");
}

int main()
{
	unsigned char a[256];
	enum {iesire, initializare, citire ,afisare}opt;
	do {
		printf("0. Iesire\n");
		printf("1. Initializare\n");
		printf("2. Citire\n");
		printf("3. Afisare\n");
		printf("Optiunea dvs. este: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case iesire:exit(0);
			break;
		case initializare: initializarea(a);
			break;
		case citire: citirea(a);
			break;
		case afisare: afisarea(a);
			break;
		default:printf("Optiune invalida\n");
			break;
		}
	} while (1);
	system("pause");
	return 0;
}
