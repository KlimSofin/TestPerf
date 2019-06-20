#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>

using std::ifstream;
using std::cout;
using std::endl;
using std::vector;

void swap(int& a, int& b);
void check_swap(int& a, int& b);
void insertion_sort(vector<int>& t, int begin, int end);
double mediana(vector<int>&t);

int main()
{
	//Чтение файла
	ifstream fin("Input.txt");
	vector<int> numbers;
	int input;
	while (fin >> input)
		numbers.push_back(input);

	//Сортировка считанных данных
	insertion_sort(numbers, 0, numbers.size()-1);

	cout << "min<" << numbers[0]<<">" << endl;
	cout << "max<" << numbers[numbers.size()-1] << ">" << endl;
	cout << "median<" << mediana(numbers) << ">" << endl;
	double sum = 0;
	for (auto j : numbers)
		sum += j;
	cout << "average<" <<sum / numbers.size()<<">" << endl;
	cout << "90 percentil<" << numbers[ceil(0.9*numbers.size())-1]<<">" << endl;
	std::cin.get();
	return 0;
}

double mediana(vector<int>&t)
{
	double sz = t.size();
	if (t.size() % 2 == 0)
		return (double(t[(sz / 2)] + t[(sz / 2) - 1]) / 2);
	else
		return (t[t.size() / 2]);
}
void swap(int& a, int& b)
{
		a = b + a;
		b = a - b;
		a = a - b;
}

void check_swap(int& a, int& b)
{
	if (b < a)
		swap(a, b);
	return;
}

void insertion_sort(vector<int>& t, int begin, int end)
{
	for (int i = end; i > begin; i--) check_swap(t[i-1], t[i]);
	for (int i = begin + 2; i <= end; i++)
	{
		int j = i;
		int it = t[j];
		while (it < t[j - 1])
		{
			t[j] = t[j - 1];
			j--;
		}
		t[j] = it;
	}
	return;
}
