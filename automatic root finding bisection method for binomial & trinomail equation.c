//*BISECTION METHOD*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node
{
	int info;
	int exponent;
	struct node *link;
}NODE;
NODE *start = NULL, *ptr;

void display(NODE *ptr)
{
	printf("Your equation is:- ");
	while (ptr)
	{
		if (ptr->exponent == 0)
		{
			printf("%d", ptr->info);
		}
		else
		{
			printf("%dx^%d", ptr->info, ptr->exponent);
		}
		ptr = ptr->link;
		if (ptr == NULL)
		{
			break;
		}
		if (ptr->info >= 0)
			printf("+");
	}
}

void sort_node()
{
	NODE *ptr, *ptr2;
	ptr = start;

	for (; ptr->link != 0; ptr = ptr->link)
	{
		for (ptr2 = ptr->link; ptr2 != '\0'; ptr2 = ptr2->link)
		{
			if (ptr->exponent<ptr2->exponent)
			{
				int ex = ptr->exponent;
				ptr->exponent = ptr2->exponent;
				ptr2->exponent = ex;
				int in = ptr->info;
				ptr->info = ptr2->info;
				ptr2->info = in;
			}
		}
	}
	display(start);
}

void add_node(int value, int value2)
{
	NODE *newptr = NULL;
	newptr = (NODE*)malloc(sizeof(NODE));
	newptr->info = value;
	newptr->exponent = value2;
	newptr->link = NULL;
	if (start == NULL)
	{
		start = newptr;
		ptr = start;
	}
	else
	{
		ptr->link = newptr;
		ptr = newptr;

	}
	sort_node();
}



float maxroot()
{
	NODE *ptr = start;
	float an1 = 0, an2 = 0, an = 0;
	if (ptr != '\0')
		an = ptr->info;
	ptr = ptr->link;
	if (ptr != '\0')
		an1 = ptr->info;
	ptr = ptr->link;
	if (ptr != '\0')
		an2 = ptr->info;
	return(sqrt((pow((an1 / an), 2)) - (2 * (an2 / an))));
}

float interval(NODE *ptr, float a)
{
	float sum = 0;
	while (ptr)
	{
		sum = sum + (ptr->info)*(pow(a, ptr->exponent));
		ptr = ptr->link;
	}
	return(sum);
}
void bisection(float a, float b)
{
	float c, fxa, fxb, fxc;
	c = (a + b) / 2;
	fxa = interval(start, a);
	fxb = interval(start, b);
	fxc = interval(start, c);
	printf("       %f               %f               %f               %f               %f               %f        \n", a, fxa, b, fxb, c, fxc);
	if (fxa*fxc<0 && fabs(fxa - fxc)>0.00001)
	{
		bisection(a, c);
	}
	else if ((fxc*fxb)<0 && fabs(fxb - fxc)>0.00001)
	{
		bisection(c, b);
	}
	else if ((fabs(fxa - fxc)<0.00001) || fabs(fxb - fxc)<0.00001)
	{
		printf("Root found at point: %f", c);
	}
}
void find_interval()
{
	float rmax = maxroot(), fx1, fx2;
	float lmax = -rmax;
	float lmax2 = lmax + 1;
	printf("All the root of the eqn lies b/w:- %f & %f\n", lmax, rmax);
	while (1)
	{
		fx1 = interval(start, lmax);
		fx2 = interval(start, lmax2);
		if ((fx1*fx2)<0 && lmax <= rmax)
		{
			printf("Atleast 1 root is found inside the interval: %f & %f\n", lmax, lmax2);
			printf(" ______________________________________________________________________________________________________________________________________________\n");
			printf("|           a          |           f(a)         |           b         |           f(b)          |           c         |           f(c)         |\n");
			printf(" ______________________________________________________________________________________________________________________________________________\n");
			bisection(lmax, lmax2);
			lmax = lmax2;
			lmax2 += 1;
		}

		else if (lmax <= rmax)
		{
			lmax = lmax2;
			lmax2 += 1;
		}
		else
			exit(1);
	}
}

int main()
{
	int value, value2, n = 1;


	printf("\nPress 0 to exit.Press any no. to write or extented your expression.");
	for (int i = 0; i<3; i++)
	{
		printf("\n\nDo you want enter expression ");
		scanf("%d", &n);
		system("cls");
		display(start);
		printf("\nEnter value for exponent of x ");
		scanf("%d", &value2);
		printf("\nEnter value for coefficient of x^%d: ", value2);
		scanf("%d", &value);
		fflush(stdin);
		add_node(value, value2);
		fflush(stdin);
	}
	printf("\n\n\n");
	display(start);
	printf("\n\n\n");
	find_interval();
	printf("\n\n\t^_^\n\tS.B.\n\n");
	return 0;
}
