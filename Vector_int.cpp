#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

//Задание 2.
//В контейнере типа vector хранится набор целых чисел.
//Создайте функторы для решения следующих задач :
//1. Поиск минимального значения;
//2. Поиск максимального значения;
//3. Сортировка данных по убыванию;
//4. Сортировка данных по возрастанию;
//5. Увеличение значений в контейнере на заданную константу;
//6. Уменьшение значений в контейнере на заданную константу;
// 
//7. Удаление элементов из контейнера равных искомому
//значению.
//Домашнее задание №17 Не забывайте использовать алгоритмы там, где это
//необходимо.

void show(vector<int> v) 
{
	for (auto var : v)
		cout << var << "\t";

	cout << endl;
}
bool comp_min(int left, int right)
{
	return left < right;
}
bool comp_max(int left, int right)
{
	return left > right;
}

vector<int>& operator+=(vector<int>& object, int delta)
{
	for (auto var = begin(object); var != end(object); ++var)
	{
		*var += delta;
	}
	return object;
}
vector<int>& operator-=(vector<int>& object, int delta)
{
	for (auto var = begin(object); var != end(object); ++var)
	{
		*var -= delta;
	}
	return object;
}

int main()
{
	srand(time(NULL));

	const int size = 10;
	vector<int> vi;

	for (size_t i = 0; i < size; i++)
		vi.push_back(rand() % 20 + 1);
	
	cout << "Array generated: \n";
	show(vi);
	
	auto it = min_element(vi.begin(), vi.end(), comp_min);
	cout << "\nMinimum element is " << *it << endl;

	it = min_element(vi.begin(), vi.end(), comp_max);
	cout << "\nMaximum element is " << *it << endl;

	sort(vi.begin(), vi.end(), comp_min);
	cout << "\nArray after sorting increasing: \n";
	show(vi);

	sort(vi.begin(), vi.end(), comp_max);
	cout << "\nArray after sorting decreasing: \n";
	show(vi);

	int temp;
	cout << "\nEnter value to increase all elements: ";
	cin >> temp;
	vi += temp;
	show(vi);

	cout << "\nEnter value to decrease all elements: ";
	cin >> temp;
	vi -= temp;
	show(vi);

	cout << "\nEnter value to delete form vector: ";
	cin >> temp;
	vi.erase(remove(begin(vi), end(vi), temp));
	show(vi);


	return 0;
}