#include<iostream>
#include<fstream>
#include<vector>
#include<utility>
#include<string>
#include<sstream>

using std::ifstream;
using std::cout;
using std::endl;
using std::pair;
using std::vector;
using std::cin;
using std::string;

int check(int x, int y, int x1, int y1, int x2, int y2);
void read_file(vector<string>&str_r, vector<pair<int, int>>&cor_r);

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream fin("Input.txt");
	int x, y,val;
	vector<pair<int, int>>cor;
	vector<string>str;
	string read;
	while (fin >> read)
		str.push_back(read);

	read_file(str, cor);

	cout << "Write x: ";
	cin >> x;
	cout << "Write y: ";
	cin >> y;
	for (int i = 0; i < 4; i++)
	{
		if (x == cor[i].first&& y == cor[i].second)
		{
			cout << "Точка - вершина четырехугольника ";
			system("pause");
			return 0;
		}
		if (i < 3)
		{
			val = check(x, y, cor[i].first, cor[i].second, cor[i + 1].first, cor[i + 1].second);
			
		}
		else
		{
			val = check(x, y, cor[i].first, cor[i].second, cor[0].first, cor[0].second);
			
		}
		
		if (val > 0)
		{
			cout << "Точка снаружи четырехугольника ";
			system("pause");
			return 0;
		}	
	}
	cout << "Точка внутри четырехугольника ";
	system("pause");
	return 0;
}

void read_file(vector<string>&str_r, vector<pair<int, int>>&cor_r)
{
	string number;
	for (int i = 0; i < str_r.size(); i++) //Обработка каждой строки считанной из файла
	{
		int cor_x = 0, cor_y = 0, k = 0;
			if (str_r[i][k++] == '<') //начало считывания кординаты x
			{
				number = "";
				while (str_r[i][k] != '>')
				{
					number = number + str_r[i][k];
					k++; 
				}
				cor_x = atoi(number.c_str());
			}
			k++;
			if (str_r[i][k++] == '<')//начало считывания кординаты y
			{
				number = "";
				while (str_r[i][k] != '>')
				{
					number = number + str_r[i][k];
					k++;
				}
				cor_y = atoi(number.c_str());

			}
			cor_r.push_back({ cor_x, cor_y });
	}
}

int check(int x,int y,int x1,int y1,int x2,int y2)
{
	return ((y - y1)*(x2 - x1) - (x - x1)*(y2 - y1));
}