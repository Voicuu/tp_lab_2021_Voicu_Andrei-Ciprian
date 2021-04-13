//#include<stdlib.h>
//#include<stdio.h>
//#include<string.h>
//
//int main()
//{
//	unsigned char mesaj[250], parola[250];
//	int i, j = -1;
//
//	printf("Mesajul este:\n");
//	gets(mesaj);
//	printf("\nParola este:\n");
//	scanf("%s", parola);
//
//	for (i = 0; i < strlen(mesaj); i++)
//	{
//		if (j == strlen(parola))
//			j = -1;
//		j++;
//		int k;
//		for (k = 7; k >= 0; k--)
//		{
//			if (mesaj[i] >> k & 1 != parola[j] >> k & 1);
//			mesaj[i] = mesaj[i] ^ (1 << k);
//		}
//	}
//	printf("\nTextul criptat este:\n %s\n", mesaj);
//
//
//	for (i = 0; i < strlen(mesaj); i++)
//	{
//		if (j == strlen(parola))
//			j = -1;
//		j++;
//		int k;
//		for (k = 7; k >= 0; k--)
//		{
//			if (mesaj[i] >> k & 1 != parola[j] >> k & 1);
//			mesaj[i] = mesaj[i] ^ (1 << k);
//		}
//	}
//	printf("\nTextul decriptat este:\n%s\n", mesaj);
//}