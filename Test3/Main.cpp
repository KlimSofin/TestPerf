#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<utility>

using std::cout;
using std::endl;
using std::ifstream;
using std::vector;
using std::pair;

void find_max_length(vector<double>&t, vector<double>&max); //Расчет длинн очередей

int find_max_time(vector<double>&mx);//Определение максимальной длинны очереди

void time_out(double val);

int main()
{
	setlocale(LC_ALL, "rus");
	const int maxVal = 16;
	ifstream fin;
	vector<double>queue_val, max(16);
	double numb;
	std::string names[5] = { "Input1.txt","Input2.txt" ,"Input3.txt" ,"Input4.txt" ,"Input5.txt" };

	for (int i = 0; i < 5; i++)//Считывание всех данных в вектор
	{
		fin.open(names[i]);
		while (fin >> numb)
			queue_val.push_back(numb);
		fin.close();
	}
	
	find_max_length(queue_val, max);

	time_out(find_max_time(max));


}

void find_max_length(vector<double>&t, vector<double>&max)
{
	
	for (int j = 0,k = 0; j<16; j++)
	{
		for (int i = j; i < 80; i += 16)
			max[k] = max[k] + t[i];
		k++;
	}

}

int find_max_time(vector<double>&mx)
{
	double max = mx[0];
	int max_i = 0;
	for (int i = 0; i < 16; i++)
	{
		if (max < mx[i])
		{
			max = mx[i];
			max_i = i;
		}		
	}
	return max_i+1;//Отсчет с 0 идет поэтому +1
}

void time_out(double val)
{
	cout << "Максимальный пик был при " << val << " замере. Спустя " << val * 30 << " минут после начала рабочего дня.";	
}