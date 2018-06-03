#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	cout << "初始化...";
	int cl,incl,lastid,id,le;
	string ti;
	cout << "ok" << endl;
	cout << "选择类型(无验证)" << endl;
	cout << "1公告2文章3技术4分享5杂文6资源"
	cin >> cl;
	if(cl == 6)
	{
		cout << "选择次类型";
		cin >> incl;
	}
	else
	{
		incl = 0;
	}
	
	return 0;
}
