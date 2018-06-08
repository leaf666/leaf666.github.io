#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<iomanip>
#include<cstdlib> 
using namespace std;
int yy,mm,dd;
char name[16]="../00-0000.html";
char s[35]="006.vbs ../00-0000.html\r\n";
void getSystemTime()
{ 
 time_t timer; 
 time(&timer); 
 tm* t_tm = localtime(&timer);
 yy=(t_tm->tm_year+1900)%100;
 mm=(t_tm->tm_mon+1);
 dd=(t_tm->tm_mday);
}
void html(int a,int b,int c)
{
	name[3]='0'+a;
	name[4]='0'+b;
	name[6]='0'+c/1000;
	name[7]='0'+(c%1000)/100;
	name[8]='0'+(c%100)/10;
	name[9]='0'+c%10;
	s[11]='0'+a;
	s[12]='0'+b;
	s[14]='0'+c/1000;
	s[15]='0'+(c%1000)/100;
	s[16]='0'+(c%100)/10;
	s[17]='0'+c%10;
}
int main()
{
	cout << "初始化...";
	int cl,incl,id,le;
	string ti,temp;
	int x[8][8]={0};
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
	fout2 << "\t" << "<page>" << "\n";
	fout2 << "\t\t" << "<class>" << cl << "</class>" << "\n";
	fout2 << "\t\t" << "<inclass>" << incl << "</inclass>" << "\n";
	fout2 << "\t\t" << "<level>" << le << "</level>" << "\n";
	fout2 << "\t\t" << "<id>" << setfill('0') << setw(4) << id << "</id>" << "\n";
	getSystemTime();
	fout2 << "\t\t" << "<date>" << yy << setfill('0') << setw(2) << mm << setfill('0') << setw(2) << dd << "</date>" << "\n";
	fout2 << "\t\t" << "<title>" << ti << "</title>" << "\n";
	fout2 << "\t" << "</page>" << "\n";
	cout << "ok" << endl;
	cout << "001.dll to 002.dll...";
	ifstream fin1("001.dll",ios::in);
	while(getline(fin1,temp))
	{
		fout2 << temp << "\n";
	}
	fout2.close();
	fin1.close();
	cout << "ok" << endl;
	cout << "002.dll to 001.dll...";
	ofstream fout1("001.dll",ios::out);
	ifstream fin2("002.dll",ios::in);
	while(getline(fin2,temp))
	{
		fout1 << temp << "\n";
	}
	fout1.close();
	fin2.close();
	cout << "ok" << endl;
	cout << "001.dll to topic.xml...";
	ofstream oxml("../xml/topic.xml",ios::out);
	ifstream ixml("001.dll",ios::in);
	oxml << "<\?xml version=\"1.0\" encoding=\"utf-8\"\?>\n<tree>\n";
	while(getline(ixml,temp))
	{
		oxml << temp << "\n";
	}
	cout << "ok" << endl;
	cout << "write html...";
	html(cl,incl,id);
	ofstream oht(name,ios::out);
	ifstream iht("004.dll",ios::in);
	//update below with 004.dll
	for(int i=1;i<=27;++i)
	{
		getline(iht,temp);
		if(i == 15)
		{
			oht << "\t\t\t\t\t\t<h2>" << ti << "<br>\n";
		}
		else if(i == 16)
		{
			oht << "\t\t\t\t\t\t\t<small><span class=\"glyphicon glyphicon-tag\"></span> ";
			if(cl==1) oht << "公告";
			if(cl==2) oht << "文章";
			if(cl==3) oht << "技术";
			if(cl==4) oht << "分享";
			if(cl==5) oht << "杂文";
			if(cl==6) oht << "资源";
			oht << "</small> <small><span class=\"glyphicon glyphicon-pencil\"></span> ---</small> <small><span class=\"glyphicon glyphicon-lock\"></span><span id=\"level\">";
			oht << le;
			oht << "</span></small> </h2>\n";
		}
		else
		{
			oht << temp << "\n";
		}
	}
	oht.close();
	iht.close();
	cout << "ok" << endl;
	cout << "to utf8...";
	ofstream bat("005.bat",ios::out);
	bat << "006.vbs ../xml/topic.xml\r\n";
	bat << s;
	bat.close();
	cout << "ok";
	return 0;
}
//<?xml version="1.0" encoding="utf-8"?><tree> 
