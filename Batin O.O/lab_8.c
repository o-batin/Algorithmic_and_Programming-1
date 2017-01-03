/* Батін Олексій Олександрович. ТМ-62. Варінат №3. Лабораторна робота №8.
 Проектування алгоритмів і програм з вкладеними циклами*/ 
#include <stdio.h>  // робота зі стандартними функціями введення-виведення
#include <stdlib.h> // звернення до функції system
#include <string.h> // присвоєння значення рядковій змінній - функція strcpy
#include <math.h>   // робота з математичними функціями
#include <Windows.h>// робота з кирилицею
int main()
{
	double x1, x2, h,  // границі проміжка і крок
		a, b, x,         // параметри a i b і змінна x
		y,               // значення функції
	    s,an,n;
	double eps = 1e-14;
	char r1[75] = "-------------------------------------------------------------------------",
		 r2[25] = "|     x    |     f(x)   "; // заголовки колонок 
	int ind,          // правильність задання вхідних даних
		i,               // номер обчисленого значення
		k = 3;           // кількість пар колонок              
	SetConsoleOutputCP(1251);
	system("cls");     // очистка екрану 
	printf("Табулювання функцiї:\n");
	printf("\t      x+1        5  3^n+x\n");
	printf("\tf(x)=(----)^1/2 *S  ----- + In(x+4)\n");
	printf("\t      x-3        n=2  n-1\n");
	/* Ввведення вхідних даних */
	do {
		ind = 0;
		fflush(stdin); // очистка буферу вводу
		printf("Вкажiть\n\tпромiжок x1, x2: ");
		scanf("%lf%lf", &x1, &x2);
		if (x1 >= x2) {
			printf("\n***Помилка***: x1 >= x2\n\n");
			ind = 1;
		}
		else {
			printf("\tкрок h: ");
			scanf("%lf", &h);
			if (h > x2 - x1 || h <= eps) {
				printf("\n***Помилка***: h > x2 - x1 або h <= 0\n\n");
				ind = 1;
			}
		}
	} while (ind);
	printf("\tзначення параметрiв a i b: ");
	scanf("%lf%lf", &a, &b);
	/* Проведення обчислень і формування таблиці */
	printf("%s\n", r1);
	printf("%s%s%s|\n", r2, r2, r2);
	printf("%s\n", r1);
	x = x1;
	i = 0;
	while (x <= x2 + eps) {
		printf("| %8.2f ", x);
		i++;
		if (fabs(x - 3) < eps || ((x + 1) / (x - 3)) < 0 || (x+4)< eps) //перевірка ОДЗ
			printf("| не визнач  ");
		else {
			s = 0;
			an = 3;
			for (n = 2; n <= 5; n++) {
				an *= 3;
				s += (an + x) / (n - 1);
			}
			y = sqrt((x + 1) / (x-3)) * s + log(x+4);
			if (fabs(y) > 1000)
				printf("|   переповн ");
			else
				printf("| %10.2lf ", y);
		}
		if (i%k == 0) printf("|\n"); //перехід на новий рядок
		x += h;
	}
	if (i%k) { // створення пустих клітинок для х і f(x)
		while (i%k) {
			i++;
			printf("|          |            ");
		}
		printf("|\n");
	}
	printf("%s\n", r1); //нижня лінія
	system("pause");
	return 0;
}
