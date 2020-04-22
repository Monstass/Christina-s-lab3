#include <iostream>
#include <ctime>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

class Array
{
private:

	int array_size, def_num;
	
public:

	std::vector<float> Arr1, Arr2, Arr3;

	Array()
	{
		array_size = 15;
		def_num = 0;
	}

	Array(int N, float M)
	{
		array_size = N;
		def_num = M;
	}

	void made_array(std::vector<float> &array)
	{
		for (int i = 0; i < array_size; i++)
		{
			array.push_back(rand() % 201 + (-100));
		}
	}

	void show_array(std::vector<float>& array)
	{
		for (auto i = array.begin(); i != array.end(); i++)
		{
			cout << "\t" << *i;
		}
	}
	
	void trans_array(std::vector<float>& array1, std::vector<float>& array2)
	{
		auto it = array1.begin();
		for (auto i = array2.begin(); i != array2.end(); i++)
		{
			if (*i > def_num && *it > def_num)
			{
				float holder = 0;
				holder = *i + *it;
				Arr3.push_back(holder);
			}
		it++;
		}
	}

	void finding_max_num(std::vector<float> &array)
	{
		float max = -101;
		int num_of_max = 0, s = 0;
		for (auto i = array.begin(); i != array.end(); i++)
		{
			s++;
			if (*i > max)
			{
				max = *i;
				num_of_max = s;
			}
		}
		cout << endl << "Номер максимального элемента: " << num_of_max;
	}

	~Array()
	{
		cout << endl << "---Деструкция выполнена успешно---";
	}
};

int main()
{	
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	int size, num;

	while (1)
	{
		cout << "Введите размер массива: ";
		cin >> size;
		if (size < 16 && size > 0)
		{
			break;
		}
		else
		{
			cout << "Ошибка, за пределами ограничения..";
		}
	}
	system("cls");

	while (1)
	{
		cout << "Введите число: ";
		cin >> num;
		if (num < 100 && num > -100)
		{
			break;
		}
		else
		{
			cout << "Ошибка, за пределами ограничения...";
		}
	}
	system("cls");

	Array A(size, num);
	A.made_array(A.Arr1);
	cout << "1-й массив: ";
	A.show_array(A.Arr1);

	Array B(size, num);
	B.made_array(B.Arr2);
	cout << endl << "2-й массив: ";
	B.show_array(B.Arr2);
	
	Array C(size, num);
	C.trans_array(A.Arr1, B.Arr2);
	cout << endl << "3-й массив: ";
	C.show_array(C.Arr3);
	cout << endl;
	C.finding_max_num(C.Arr3);

	cout << endl;
	return 0;
}