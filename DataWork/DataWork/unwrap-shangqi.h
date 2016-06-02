#pragma once
//unwrap shangqi
//try to sort all the features in each configuration
//author:Dongxiang Mao
#include <iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<Windows.h>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include "Configure.h"
using namespace std;
 

vector<Configure> unwrap_shangqi(int file_index)
{
	stringstream ss0;
	ss0 << file_index;
	  string s1 = ss0.str();
	string input_file_name = s1+".csv";

	string output_file_name= "shangqi_unwarped_sorted_"+s1 + ".txt";

	int num = 0;//check the # of column
	vector<string> one_feature_o;
	vector<vector<string>> all_feature_o;//
	vector<string> temp_a;
	vector<string> temp_b;
	vector<string> temp_c;
	vector<string> feature_combinations;//string for all combinations of feature_o
	vector<string> feature_s;//string for feature_s
	vector<string> configs;//results
	vector<vector<string>> sliced_configs;
	vector<Configure> sorted_sliced;
	Configure temp_config;
	vector<int> index;

	string temp, temp2, temp3, feature_o;
	ifstream fin(input_file_name);
	if (!fin)
	{
		cout << "can not open the input file";
	}

	getline(fin, temp);//drop schema
	getline(fin, temp);//operate on second line seperately
	stringstream ss(temp);
	while (getline(ss, temp, ','))
	{
		if (num == 1)
		{
			feature_o = temp;
		}
		else if (num == 2)
		{
			feature_s.push_back(temp);
		}
		++num;
	}

	while (getline(fin, temp))
	{
		stringstream ss(temp);

		while (getline(ss, temp, ','))
		{
			if (num % 3 == 2)
			{
				feature_s.push_back(temp);
			}
			++num;
		}

	}

	string temp4 = feature_o.substr(1, feature_o.size());
	//ss.str(temp4);//reset stringstream ss by feature_o

	stringstream ss2(temp4);

	while (getline(ss2, temp, ';'))//cut feature_o by family
	{
		temp = temp.substr(1, temp.size());
		stringstream temp2(temp);
		while (getline(temp2, temp, ' '))//cut feature_o in the same family by attributes
		{
			one_feature_o.push_back(temp);
		}
		all_feature_o.push_back(one_feature_o);
		one_feature_o.clear();
	}
	/*
	for (unsigned i = 0; i < all_feature_o.size(); i++)//output all attributes group by family
	{
	for (unsigned j = 0; j < all_feature_o[i].size(); j++)
	{
	cout << all_feature_o[i][j] << " ";
	}
	cout << endl;
	}
	*/


	//	cout << all_feature_o.size() << endl;

	if (all_feature_o.size() > 1)
	{
		temp_a = all_feature_o[0];
		for (unsigned i = 1; i < all_feature_o.size(); i++)
		{
			if (i % 2 == 1)
			{
				temp_b.clear();
				for (unsigned j = 0; j < all_feature_o[i].size(); j++)
				{
					for (unsigned k = 0; k < temp_a.size(); k++)
					{
						temp_b.push_back(temp_a[k] + " " + all_feature_o[i][j]);
					}
				}
			}
			else
			{
				temp_a.clear();
				for (unsigned j = 0; j < all_feature_o[i].size(); j++)
				{
					for (unsigned k = 0; k < temp_b.size(); k++)
					{
						temp_a.push_back(temp_b[k] + " " + all_feature_o[i][j]);
					}
				}
			}
		}

		if (all_feature_o.size() % 2 == 0)
		{
			feature_combinations = temp_b;
		}
		else
		{
			feature_combinations = temp_a;
		}
	}
	else
	{
		feature_combinations = all_feature_o[0];
	}


	for (unsigned i = 0; i < feature_combinations.size(); i++)//combine feature o with feature s
	{
		for (unsigned j = 0; j < feature_s.size(); j++)
		{
			configs.push_back(feature_combinations[i] + " " + feature_s[j]);
		}
	}

	for (unsigned i = 0; i < configs.size(); i++)//slice and sort each configuration
	{
		stringstream ss3(configs[i]);
		//temp_c.clear();
		temp_config.featureArr.clear();
		while (getline(ss3, temp, ' '))
		{			
			temp_config.featureArr.push_back("_"+temp);			
		}
		temp_config.featureCodeSort();
		sorted_sliced.push_back(temp_config);
		//Configure config;
		//config.featureArr = temp_c;
		
		//config.featureCodeSort();
		//sliced_configs.push_back(config.featureArr);

	}

	
	sort(sorted_sliced.begin(), sorted_sliced.end());

	/*
	ofstream outfile(output_file_name);//output all results to txt
	if (outfile.is_open())
	{
		for (unsigned i = 0; i < sliced_configs.size(); i++)
		{
			for (unsigned j = 0; j < sliced_configs[i].size(); j++)
			{
				outfile << sliced_configs[i][j]<<" " ;
			}
			outfile << endl;
		}
	}
	else
	{
		cout << "Fail to open the output file!" << endl;
	}


	return sliced_configs;
	*/
	
	ofstream outfile(output_file_name);//output all results to txt
	if (outfile.is_open())
	{
		for (unsigned i = 0; i < sorted_sliced.size(); i++)
		{
			for (unsigned j = 0; j < sorted_sliced[i].featureArr.size(); j++)
			{
				outfile << sorted_sliced[i].featureArr[j] << " ";
			}
			outfile << endl;
		}
	}
	else
	{
		cout << "Fail to open the output file!" << endl;
	}


	return sorted_sliced;



	
}