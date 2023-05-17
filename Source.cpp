#include "Header.h"
using namespace std;

void main()
{
	setlocale(LC_ALL, "Russian");
	stats one;
	stats two;
	stats three;
	//auto Vector = create_vector(1000, 1);
	//print_vector(Vector);
	cout << "100 раз рандомный вектор по 1000\n";
	cout << "\n" << "вставки\n";
	for (int i = 0; i < 10; i++)
	{
		auto Vector = create_vector(100000,3);
		one = one + insertion_sort(Vector);
	}
	one = one / 10;
	one.print();
	cout << "\n" << "шелл-хеликс    :)\n";
	for (int i = 0; i < 100; i++)
	{
		auto Vector = create_vector(100000, 3);
		two = two + shell_petrol_station(Vector);
	}
	two = two / 100;
	two.print();
	cout << "\n" << "Пирамида хиопса\n";
	 for (int i = 0; i < 100; i++)
	{
		auto Vector = create_vector(100000, 3);
		three = three + heapSort(Vector);
	}
	 three = three / 100;
	three.print();
	//print_vector(Vector);
}
