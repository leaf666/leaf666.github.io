#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	cout << "初始化...";
	int cl,incl,id,le;
	int yy,mm,dd;
	string ti;
	int x[8][8]={0};
	ifstream fin1("001.dll",ios::in);
//	ofstream fout1("001.dll",ios::out);
//	ifstream fin2("002.dll",ios::in);
	ofstream fout2("002.dll",ios::out);
	ifstream fin3("003.dll",ios::in);
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
		{
			fin3 >> x[i][j];
		}
	}
	fin3.close();
	cout << "ok" << endl;
	cout << "选择类型(无验证)" << endl;
	cout << "1公告2文章3技术4分享5杂文6资源" << endl;
	cin >> cl;
	if(cl == 6)
	{
		cout << "选择次类型";
		cout << "1视频" << endl;
		cin >> incl;
	}
	else
	{
		incl = 0;
	}
	cout << "输入等级" << endl;
	cin >> le; 
	cout << "输入标题" << endl;
	cin >> ti;
	
	x[cl-1][incl] += 1;
	id = x[cl-1][incl];
	ofstream fout3("003.dll",ios::out);
	for(int i=0;i<6;++i)
	{
		for(int j=0;j<6;++j)
		{
			fout3 << x[i][j] << " ";
		}
	}
	fout3.close();
	cout << "wirte 003.dll" << endl;
	
	
	return 0;
}
//<?xml version="1.0" encoding="utf-8"?><tree> 
