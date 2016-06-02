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
	//配置类中排序
	void featureCodeSort();
	//重载小于符号
	friend bool operator<(const Configure& con1, const Configure& con2);
};
