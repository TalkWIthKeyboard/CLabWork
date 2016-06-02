#pragma once
#include <cstring>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Configure
{
private:

public:
	Configure();
	Configure(const Configure & con);
	~Configure();
	vector<string> featureArr;
public:
	//������������
	void featureCodeSort();
	//����С�ڷ���
	friend bool operator<(const Configure& con1, const Configure& con2);
};
