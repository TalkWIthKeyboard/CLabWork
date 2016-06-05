#include <iostream>
#include "Configure.h"
#include "unwrap-shangqi.h"
#include "unwrap-tongji.h"
#include "compare.h"
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
#pragma warning(disable:4996)
const int maxbound = 228;
char str[100];
int familyNum;
map<string, string> featureToFamily;
vector<string> familyVector;
map<string, int> familyCodeNum;

//����input1�ļ��ַ���
void workStr()
{
	int kg[3];
	char reStr[100];
	string * feature, *family;
	memset(kg, 0, sizeof(kg));
	kg[0] = -1;

	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] == ' ')
		{
			kg[1] = i;
		}
		if (str[i] == ':')
		{
			kg[2] = i;
			break;
		}
	}

	for (int i = 1; i <= 2; i++)
	{
		memset(reStr, '\0', sizeof(reStr));
		for (int j = kg[i - 1] + 1; j < kg[i]; j++)
		{
			reStr[j - kg[i - 1] - 1] = str[j];
		}
		if (i == 1)
		{
			family = new string(reStr);
		}
		else {
			feature = new string(reStr);
		}
	}

	if (familyVector.size() == 0 || familyVector[familyVector.size() - 1] != *family)
	{
		familyVector.push_back(*family);
	}

	featureToFamily[*feature] = *family;
}

//����feature��family��ӳ��
void makeFeatureToFamily()
{
	freopen("input1.txt", "r", stdin);
	while (gets_s(str) != 0)
	{
		workStr();
	}
	
	sort(familyVector.begin(),familyVector.end());
	int num = 0;
	vector<string>::iterator it;
	for (it = familyVector.begin(); it != familyVector.end(); ++it)
	{
		familyCodeNum[*it] = num;
		num++;
	}
}

//��ʼ��
void init()
{
	familyNum = 0;
}

int main() {
	int left_bound,right_bound;
	cout << "������Ҫ���ı������:";
		cin >> left_bound >> right_bound;
		while ((left_bound<0) || (right_bound>maxbound) || (left_bound > right_bound))
		{
			cout << "������Ҫ���ı������:";
			cin >> left_bound >> right_bound;
		}
	init();
	makeFeatureToFamily();

	vector<Configure> shangqi;
	vector<Configure> tongji;
	
	for (int i = left_bound; i <= right_bound; ++i)
	{
		fprintf(stderr, "��ʼ�����%d������\n", i);
		fprintf(stderr, "��ʼչ����������ѹ�������ļ�\n");
		shangqi = unwrap_shangqi(i);
		fprintf(stderr, "��ʼչ��ͬ�÷���ѹ�������ļ�\n");
		tongji = unwrap_tongji(i);
		fprintf(stderr, "��ʼ�Ƚ�˫���Ľ��\n");
		sort_compare(tongji, shangqi,i);
	}
}