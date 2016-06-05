#include "Configure.h"

extern map<string, int> familyCodeNum;
extern map<string, string> featureToFamily;

Configure::Configure()
{
}

Configure::~Configure()
{
}

Configure::Configure(const Configure & con)
{
	featureArr.assign(con.featureArr.begin(), con.featureArr.end());
}

void Configure::featureCodeSort()
{
	string nowSort[1000];

	for (int i = 0; i < featureArr.size(); i++)
	{
		nowSort[familyCodeNum[featureToFamily[featureArr[i]]] - 1] = featureArr[i];
	}

	for (int i = 0; i < featureArr.size(); i++)
	{
		featureArr[i] = nowSort[i];
	}
}

bool operator<(const Configure& con1, const Configure& con2)
{
	for (int i = 0; i < con1.featureArr.size(); i++)
	{
		if (con1.featureArr[i] < con2.featureArr[i])
		{
			return true;
		}
		if (con1.featureArr[i] > con2.featureArr[i])
		{
			return false;
		}
	}
	return false;
}
