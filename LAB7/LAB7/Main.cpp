#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h>

using namespace std;

template <typename T> int checkSum(T);

int main()
{
	int t1 = time(NULL);
	string in_file = "input.txt";
	string out_file = "output.txt";
	ifstream input;
	ofstream output;
	input.open(in_file);
	output.open(out_file);
	vector<int> array(7);
	if (input.is_open())
	{
		printf("Opened file for input.\n");
		for (int i = 0; i < array.size(); i++)
		{
			input >> array[i];
		}
	}
	else
	{
		throw "Error while opening file for input.";
	}
	if (output.is_open())
	{
		printf("Opened file for output.\n");
	}
	else
	{
		throw "Error while opening file for output.";
	}
	output << " Element\tcheckSum" << endl;
	for (int i = 0; i < array.size(); i++)
	{
		output << array[i] << " \t--- \t" << checkSum(array[i]) << endl;
	}
	input.close();
	output.close();
	printf("\n Time of running program is %d seconds\n", time(NULL) - t1);
	system("pause");
}

template<typename T>
int checkSum(T value)
{
	int rezult = 0;
	int size = sizeof(T);
	char* pointer = (char*)&value;
	for (int i = 0; i < size; i++, pointer++)
	{
		int num = *pointer;
		for (int j = 0; j < 8; j++)
		{
			rezult += num & 1;
			num = num >> 1;
		}

	}
	return rezult;
}
