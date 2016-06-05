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
#include "Configure.h"
using namespace std;


int sort_compare(vector<Configure>tongji, vector<Configure>shangqi,int num)
{
	vector<int> shangqi_ex, tongji_ex;
	string line;

	//sort(tongji, max_size);
	sort(tongji.begin(), tongji.end());
	sort(shangqi.begin(), shangqi.end());

	vector<Configure>::iterator cmp1 = shangqi.begin();
	vector<Configure>::iterator cmp2 = tongji.begin();
	int tongji_counter = 0, shangqi_counter = 0;
	while ((cmp2 != tongji.end()) && (cmp1 != shangqi.end()))
	{
		if (*cmp1 < *cmp2)
		{
			cmp1++;
			shangqi_counter++;
			shangqi_ex.push_back(shangqi_counter);
		}
		else if (*cmp2 < *cmp1)
		{
			cmp2++;
			tongji_counter++;
			tongji_ex.push_back(tongji_counter);
		}
		else
		{
			cmp2++;
			tongji_counter++;
			cmp1++;
			shangqi_counter++;
		}
	}
	if (cmp1 != shangqi.end())
	{
		while (cmp1 != shangqi.end())
		{
			cmp1++;
			shangqi_counter++;
			shangqi_ex.push_back(shangqi_counter);
		}
	}
	if (cmp2 != tongji.end())
	{
		while (cmp2 != tongji.end())
		{
			cmp2++;
			tongji_counter++;
			tongji_ex.push_back(tongji_counter);
		}
	}

	fprintf(stderr, "上汽多出：%d  同济多出：%d\n\n", shangqi_ex.size(), tongji_ex.size());

	char filename[20];
	sprintf(filename, "tongji_extra_%d.txt", num);
	freopen(filename, "w", stdout);
	for (int i = 0; i < tongji_ex.size(); i++)
	{
		printf("%d\n", tongji_ex[i]);
	}
	fclose(stdout);

	sprintf(filename, "shangqi_extra_%d.txt", num);
	freopen(filename, "w", stdout);
	for (int i = 0; i < shangqi_ex.size(); i++)
	{
		printf("%d\n", shangqi_ex[i]);
	}
	fclose(stdout);

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

