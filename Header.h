#pragma once
#include <iostream>
#include "Header.h"
#include <time.h>
#include <vector>
#include <chrono>
#include <fstream>
using namespace std;
using namespace std::chrono;

struct stats {
	size_t comparison_count = 0;
	size_t copy_count = 0;
	double time = 0;
	void print()
	{
		cout << "���������� ���������" << comparison_count << "\n";
		cout << "���������� �����������" << copy_count << "\n";
		cout << "�����" << time << "\n";
	}
	stats operator+(const stats &right)
	{	
		comparison_count += right.comparison_count;
		copy_count += right.copy_count;
		time += right.time;
		return *this;
	}
	stats operator/(const int divisor)
	{
		comparison_count /= divisor;
		copy_count /= divisor;
		time /= divisor;
		return *this;
	}
};
size_t lcg() {
	static size_t x = 0;
	x = (1021 * x + 24631) % 116640;
	return x;
}
void print_vector(vector<int> arr)
{
	for (size_t i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << " ";
	}
}

stats insertion_sort(vector<int>& arr)
{
	auto start = high_resolution_clock::now();
	stats results;
	int temp;
	for (int i = 1; i < arr.size(); i++)
	{
		for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--)
		{
			temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			results.copy_count += 3;
		}
		results.comparison_count++;
	}
	auto stop = high_resolution_clock::now();
	duration<double> duration = stop - start;
	results.time = (double)duration.count();
	//print_vector(arr);
	return results;
}
vector<int> create_vector(int size, int type) {
	std::vector<int> temp;
	if (type == 1) // ������ ������ � ���������� ����������
	{
		for (int i = 0; i < size; i++)
		{
			temp.push_back(lcg());
		}
	}
	else if (type == 2)// ��������������� ������
	{
		for (int i = 0; i < size; i++)
		{
			temp.push_back(i);
		}
	}
	else // ��������������� � �������� �������
	{
		for (int i = size; i > 0; i--)
		{
			temp.push_back(i);
		}
	}
	return temp;
}
stats shell_petrol_station(vector<int>& arr)
{
	auto start = high_resolution_clock::now();
	stats results;
	int temp;
	int step = arr.size() ; // 2
	while (step > 0)
	{
		for (int i = step; i < arr.size(); i++)
		{
			int gap = i - step;
			while (gap >= 0 && arr[gap] > arr[gap + step])
			{
				temp = arr[gap];
				arr[gap] = arr[gap + step];
				arr[gap + step] = temp;
				gap -= step;
				results.copy_count += 3;
				
			}
			results.comparison_count++;
		}
		step /= 2;
	}
	auto stop = high_resolution_clock::now();
	duration<double> duration = stop - start;
	results.time = (double)duration.count();
	//print_vector(arr);
	return results;
}



stats heapify(vector<int>& arr, int n, int i)
{
	stats results;
	int largest = i;
	// �������������� ���������� ������� ��� ������
	int l = 2 * i + 1; // ����� = 2*i + 1
	int r = 2 * i + 2; // ������ = 2*i + 2

	// ���� ����� �������� ������� ������ �����
	if (l < n && arr[l] > arr[largest])
		largest = l;
		
	// ���� ������ �������� ������� ������, ��� ����� ������� ������� �� ������ ������
	if (r < n && arr[r] > arr[largest])
		largest = r;
	results.comparison_count += 2;
	// ���� ����� ������� ������� �� ������
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		results.copy_count += 3;
		// ���������� ����������� � �������� ���� ���������� ���������
		results = results+ heapify(arr, n, largest);
	}
	return results;
}

// �������� �������, ����������� ������������� ����������
stats heapSort(vector<int> &arr)
{
	auto start = high_resolution_clock::now();
	stats results;
	int n = arr.size();
	// ���������� ���� (�������������� ������)
	for (int i = n / 2 - 1; i >= 0; i--)
		results = results+heapify(arr, n, i);

	// ���� �� ������ ��������� �������� �� ����
	for (int i = n - 1; i >= 0; i--)
	{
		// ���������� ������� ������ � �����
		swap(arr[0], arr[i]);
		results.copy_count += 3;
		// �������� ��������� heapify �� ����������� ����
		results= results+ heapify(arr, i, 0);
	}
	auto stop = high_resolution_clock::now();
	duration<double> duration = stop - start;
	results.time = (double)duration.count();
	return results;
}