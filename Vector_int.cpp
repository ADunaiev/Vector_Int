#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
using namespace std;

//������� 2.
//� ���������� ���� vector �������� ����� ����� �����.
//�������� �������� ��� ������� ��������� ����� :
//1. ����� ������������ ��������;
//2. ����� ������������� ��������;
//3. ���������� ������ �� ��������;
//4. ���������� ������ �� �����������;
//5. ���������� �������� � ���������� �� �������� ���������;
//6. ���������� �������� � ���������� �� �������� ���������;
// 
//7. �������� ��������� �� ���������� ������ ��������
//��������.
//�������� ������� �17 �� ��������� ������������ ��������� ���, ��� ���
//����������.

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