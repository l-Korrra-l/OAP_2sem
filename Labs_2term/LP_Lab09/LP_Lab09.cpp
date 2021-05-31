/////*4	Задан прямоугольник со сторонами а и b(a, b − натуральные числа).Разбить его на части с помощью квадратов и определить, сколько квадратов получится,
////если каждый раз выбирается самый большой квадрат.*/
//////#include <stdio.h>
//////#include <iostream>
//////#include <cmath>
////// int c = 0;
////// int sec(void);
//////int numcq(unsigned a, unsigned b)
//////{
//////   
//////    if (b != 0)
//////    {
//////          c = floor(a / b) + numcq(b,a % b);
//////    }
//////
//////  return c;
//////}
//////int main(void)
//////{
//////    int a,b;
//////        printf("First task:\nBiggest side: ");
//////        scanf_s("%d", &a);
//////        printf("\nTHe other side: ");
//////        scanf_s("%d", &b);
//////        std::cout << numcq(a, b) << std::endl;
//////        putchar('\n');
//////
//////    return 0;
//////}
////
////
///////*6	Разработать программу, реализующую рекурсивный алгоритм вычисления A(m, n) для любых целых не отрицательных m и n.*/
//#pragma comment(linker, "/STACK:16777216")
//#include <iostream>
//using namespace std;
//
//double qwerty(int m, int n)
//{
//	int f;
//	if (n == 0) return 1;
//	else if (n < m) return -1;
//	else return (2 * qwerty(m, n - 1));
//
//}
//
//int main()
//{
//	int m, n;
//	cout << "m = ";
//	cin >> m;
//	cout << "n = ";
//	cin >> n;
//	cout << "answer: " << qwerty(m, n) << endl;
//	system("pause");
//}
////
//////
//////6. Дополнительные задания.
//////1. Ввести цифру А, записать в файл все возможные числа, состоящие из цифр, не превышающих или равных A.Количество цифр в числах должно быть равно А.
//////Примечание: использовать дополнительный массив.
