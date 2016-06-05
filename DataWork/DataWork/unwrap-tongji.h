#include"Configure.h"
#include<iostream>
#include<fstream>
#include<ostream>
#include<sstream>
#include<string>
#define ls 10000
using namespace std;
vector<string> temp;
//Configure configure[3000000];
vector<Configure> configure;
//Configure configure[2000000];
int line = 0;
void initspread() {
	line = 0;
	configure.clear();
}
void Apart(string str) {
	int start = 0; int len = 0; int pos = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '/') {
			string s(str, start, len);
			temp.push_back(s);
			pos++;  start = pos; len = 0;
		}
		else {
			len++; pos++;
		}
	}
}
int ReadStar(string str) {
	int num = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '/')
			num++;
	}
	return num;
}

void Spread(int i) {
	vector<string>::iterator it;
	it = configure[i].featureArr.begin();
	string str = *it;
	int pos = 0; int tempos = 1;
	while (it != configure[i].featureArr.end()) {
		if (ReadStar(*it) == 0) {
			it++;
			pos++;
		}
		else {
			int m = 0;
			m = ReadStar(*it);
			Apart(*it);
			configure[i].featureArr[pos] = temp[0];
			for (int j = 0; j < m - 1; j++) {
				Configure con(configure[i]);
				//configure[line - 1] = con;
				configure.push_back(con);
				//configure[line - 1].GetPosValue(pos)->value = temp.GetPosValue(tempos)->value;

				configure[line - 1].featureArr[pos] = temp[tempos];
				it = configure[i].featureArr.begin() + pos;
				line++; tempos++;
			}
			pos++; it++;
			tempos = 1;
			temp.clear();
		}
	}
}
/*
void ReadFile(){
for (int f = 48; f < 49; f++){
initspread();
string s1 = "output_ex_";
string s5 = "spread";
string s2, s3, s4; char a[20];
itoa(f, a, 10); s2 = a;
s3 = s1 + s2 + ".csv";
s4 = s5 + s2 + ".txt";

ofstream fout(s4);
streambuf* coutbackup;
coutbackup = cout.rdbuf(fout.rdbuf());

std::string file_name = s3;
std::ifstream fin(file_name.c_str());
if (!fin){
cerr << " a open error" << endl;
}
std::string textline[ls];
for (int i = 0; i < 2000; ++i)
{
//cout << "****" << i << endl;
if (fin.eof()) break;
getline(fin, textline[i], '\n');
std::stringstream word(textline[i]);
Configure ncon;
while (true){
string tempp;
getline(word, tempp, ',');
if (tempp != ""){
//OriArray[i].Add(tempp);
//configure[i].featureArr.push_back(tempp);
ncon.featureArr.push_back(tempp);
}
else break;
}
configure.push_back(ncon);
//word.clear();
line++;
}
configure.pop_back();
int total = 0;
memset(textline, 0, ls);
fprintf(stderr, "ø™ º’πø™\n");
for (int i = 1; i <line-1; i++){
Spread(i);
fprintf(stderr, "%d\n", i);
}

fprintf(stderr, "ø™ º≈≈–Ú\n");
for (int i = 1; i < line - 1; i++){
configure[i].featureCodeSort();
fprintf(stderr, "%d\n", i);
}


sort(configure.begin(), configure.end());
for (int i = 0; i < line - 1; i++){
vector<string>::iterator it;
for (it = configure[i].featureArr.begin(); it != configure[i].featureArr.end(); ++it)
{
cout << *it;
}
printf("\n");
cout << endl;
}

cout.rdbuf(coutbackup);
}
}
*/

vector<Configure> unwrap_tongji(int file_index) {
	//for (int f = 48; f < 49; f++){
	initspread();
	string s1 = "output_ex_";
	string s5 = "output_tongji_";
	string s2, s3, s4; char a[20];
	itoa(file_index, a, 10); s2 = a;
	s3 = s1 + s2 + ".csv";
	s4 = s5 + s2 + ".txt";

	//ofstream fout(s4);
	//streambuf* coutbackup;
	//coutbackup = cout.rdbuf(fout.rdbuf());

	std::string file_name = s3;
	std::ifstream fin(file_name.c_str());
	if (!fin) {
		cerr << " file open error" << endl;
	}
	std::string textline[ls];
	for (int i = 0; i < 10000; ++i)
	{
		//cout << "****" << i << endl;
		if (fin.eof()) break;
		getline(fin, textline[i], '\n');
		std::stringstream word(textline[i]);
		Configure ncon;
		while (true) {
			string tempp;
			getline(word, tempp, ',');
			if (tempp != "") {
				//OriArray[i].Add(tempp);
				//configure[i].featureArr.push_back(tempp);
				ncon.featureArr.push_back(tempp);
			}
			else break;
		}
		configure.push_back(ncon);
		//word.clear();
		line++;
	}
	configure.pop_back();
	int total = 0;
	memset(textline, 0, ls);
	//	fprintf(stderr, "ø™ º’πø™\n");
	for (int i = 1; i <line - 1; i++) {
		Spread(i);
		//		fprintf(stderr, "%d\n", i);
	}

	//	fprintf(stderr, "ø™ º≈≈–Ú\n");
	for (int i = 1; i < line - 1; i++) {
		configure[i].featureCodeSort();
		//		fprintf(stderr, "%d\n", i);
	}


	sort(configure.begin(), configure.end());
	configure.pop_back();

	char filename[20];
	sprintf(filename, "output_tongji_%d.txt", file_index);
	freopen(filename, "w", stdout);
	for (int i = 0; i < line - 2; i++) {
		vector<string>::iterator it;
		for (it = configure[i].featureArr.begin(); it != configure[i].featureArr.end(); ++it)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	//cout.rdbuf(coutbackup);
	return configure;
	//}
}