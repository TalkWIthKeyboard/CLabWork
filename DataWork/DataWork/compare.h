// Name:Dongxiang Mao
// sort and compare 
// Date:2016-05-24

#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <fstream>  
#include <string>  
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


int sort_compare(vector<vector<string>>tongji, vector<vector<string>>shangqi)
{
	
	vector<vector<string>> tongji_extra;
	vector<vector<string>> shangqi_extra;
	string line;

	//sort(tongji, max_size);
	sort(tongji.begin(), tongji.end());
	sort(shangqi.begin(), shangqi.end());

	vector<vector<string>>::iterator cmp1 = shangqi.begin();
	vector<vector<string>>::iterator cmp2 = tongji.begin();
	int counter = 0;
	while ((cmp2 != tongji.end()) && (cmp1 != shangqi.end()))
	{
		if (*cmp2 > *cmp1)
		{
			shangqi_extra.push_back(*cmp1);
			cmp1++;
			++counter;
			cout << counter << endl;
		}
		else if (*cmp2 < *cmp1)
		{
			tongji_extra.push_back(*cmp2);
			cmp2++;

		}
		else
		{
			cmp2++;
			cmp1++;
			++counter;
		}
	}
	if (cmp1 != shangqi.end())
	{
		while (cmp1 != shangqi.end())
		{
			shangqi_extra.push_back(*cmp1);
			++cmp1;
			++counter;
			cout << counter << endl;
		}
	}
	if (cmp2 != tongji.end())
	{
		while (cmp2 != tongji.end())
		{
			tongji_extra.push_back(*cmp2);
			++cmp2;

		}
	}


	ofstream outfile("out_tongji31.txt");
	if (outfile.is_open())
	{
		for (unsigned i = 0; i < tongji_extra.size(); i++)
		{
			for (unsigned j = 0; j < tongji_extra[i].size(); j++)
			{
				outfile << tongji_extra[i][j] << " ";
			}
			outfile << endl;
		}
		outfile.close();
	}
	else
	{
		cout << "Fail to open the output file!" << endl;
	}

	ofstream outfile1("out_shangqi31.txt");
	if (outfile1.is_open())
	{
		for (unsigned i = 0; i < shangqi_extra.size(); i++)
		{
			for (unsigned j = 0; j < shangqi_extra[i].size(); j++)
			{
				outfile << shangqi_extra[i][j] << " ";
			}
			outfile << endl;
		}
		outfile1.close();
	}
	else
	{
		cout << "Fail to open the output file!" << endl;
	}

	/*
	ofstream outfile2("sort_tongji31.txt");
	if (outfile2.is_open())
	{
		for (vector<string>::iterator it = tongji.begin(); it != tongji.end(); ++it)
			outfile2 << *it << endl;

		outfile2.close();
	}
	else
	{
		cout << "Fail to open the output file!" << endl;
	}

	ofstream outfile3("sort_shangqi31.txt");
	if (outfile3.is_open())
	{
		for (vector<string>::iterator it = shangqi.begin(); it != shangqi.end(); ++it)
			outfile3 << *it << endl;

		outfile3.close();
	}
	else
	{
		cout << "Fail to open the output file!" << endl;
	}
	*/

	return 0;  // indicates successful termination
}

