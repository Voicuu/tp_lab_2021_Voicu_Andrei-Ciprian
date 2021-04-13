#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void push(int *m, char *st,char a)
{
	(*m)++;
	st[*m] = a;
}

int pop(int *m,char *st)
{
	return st[(*m)--];
}

int operatie(char a)
{
	switch (a)
	{
	case'(':
	case')': return 0;
	case '/':
	case '*': return 2;
	case '+':
	case '-':return 1;
		return 10;
	}
}

int main()
{
	int i, n = -1, m = -1, a, b, c, d, e, f,y, z;
	char s[250], fp[250], st[20], x;
	printf("Dati expresia:\n");
	scanf("%s", s);
	printf("a= ");
	scanf("%d", &a);
	printf("b= ");
	scanf("%d", &b);
	printf("c= ");
	scanf("%d", &c);
	printf("d= ");
	scanf("%d", &d);
	printf("e= ");
	scanf("%d", &e);
	printf("f= ");
	scanf("%d", &f);
	for (i = 0; i < strlen(s); i++)
	{
		if (s[i] >= 'a'&&s[i] <= 'z')
			fp[++n] = s[i];
		else
		{
			if (m == -1)
				push(&m, st, s[i]);
			else if(s[i]=='(')
				push(&m, st, s[i]);
			else if (s[i] == ')')
			{
				while (1)
				{
					x = pop(&m, st);
					if (x == '(')
					{
						break;
					}
					else 
					{
						fp[++n] = x;
					}
				}
			}
			else if (operatie(s[i]) <= operatie(st[m]))
			{
				while (operatie(s[i]) <= operatie(st[m]))
				{
					fp[++n] = pop(&m, st);
				}
				push(&m, st, s[i]);
			}
			else
			{
				push(&m, st, s[i]);
			}
		}
	}
	while (m >= 0)
		fp[++n] = pop(&m,st);
	fp[++n] = '\0';
	printf("\nForma Poloneza postfixata este:\n%s", fp);
	for (i = 0; i <n; i++)
	{
		if (fp[i] >= 'a'&&fp[i] <= 'z')
		{
			push(&m, st, fp[i]);
		}
		else
		{
			x = pop(&m, st);
			if (x >= 'a'&&x <= 'z')
			{
				if (x == 'a')
					y = a;
				if (x == 'b')
					y = b;
				if (x == 'c')
					y = c;
				if (x == 'd')
					y = d;
				if (x == 'e')
					y = e;
				if (x == 'f')
					y = f;
			}
			else
				y = x;

			x = pop(&m, st);
			if (x >= 'a'&&x <= 'z')
			{
				if (x == 'a')
					z = a;
				if (x == 'b')
					z = b;
				if (x == 'c')
					z = c;
				if (x == 'd')
					z = d;
				if (x == 'e')
					z = e;
				if (x == 'f')
					z = f;
			}
			else
				z = x;
			if (fp[i] == '/')
			{
				x = z / y;
				push(&m, st, x);
			}
			if (fp[i] == '-')
			{
				x = z - y;
				push(&m, st, x);
			}
			if (fp[i] == '+')
			{
				x = y + z;
				push(&m, st, x);
			}
			if (fp[i] == '*')
			{
				x = y * z;
				push(&m, st, x);
			}
		}
	}
	printf("\n\nRezultatul expresiei este: %d", x);
}