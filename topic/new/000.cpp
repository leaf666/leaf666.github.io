#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
int yy,mm,dd;
void getSystemTime()
{ 
 time_t timer; 
 time(&timer); 
 tm* t_tm = localtime(&timer);
 yy=(t_tm->tm_year+1900)%100;
 mm=(t_tm->tm_mon+1);
 dd=(t_tm->tm_mday);
} 
int main()
{
	cout << "初始化...";
	int cl,incl,id,le;
	string ti;
	int x[8][8]={0};
	ifstream fin1("001.dll",ios::in);
//	ofstream fout1("001.dll",ios::out);
//	ifstream fin2("002.dll",ios::in);
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
	cout << "选择类型" << endl;
	cout << "1公告2文章3技术4分享5杂文6资源" << endl;
	cin >> cl;
	if(cl<1 || cl>6)return 0;
	if(cl == 6)
	{
		cout << "选择次类型";
		cout << "1视频" << endl;
		cin >> incl;
		if(incl<0 || incl >5)return 0;
	}
	else
	{
		incl = 0;
	}
	cout << "输入等级" << endl;
	cin >> le; 
	cout << "输入标题" << endl;
	cin >> ti;
	cout << "wirte 003.dll...";
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
	cout << "ok" << endl;
	cout << "wirte 002.dll...";
	ofstream fout2("002.dll",ios::out);
	fout2 << "\t" << "<page>" << endl;
	fout2 << "\t\t" << "<class>" << cl << "</class>" << endl;
	fout2 << "\t\t" << "<inclass>" << incl << "</inclass>" << endl;
	fout2 << "\t\t" << "<level>" << le << "</level>" << endl;
	fout2 << "\t\t" << "<id>" << setfill('0') << setw(4) << id << "</id>" << endl;
	getSystemTime();
	fout2 << "\t\t" << "<date>" << yy << setfill('0') << setw(2) << mm << setfill('0') << setw(2) << dd << "</date>" << endl;
	fout2 << "\t\t" << "<title>" << ti << "</title>" << endl;
	fout2 << "\t" << "</page>" << endl;
	fout2.close();
	cout << "ok" << endl;
	
	return 0;
}
//<?xml version="1.0" encoding="utf-8"?><tree> 
