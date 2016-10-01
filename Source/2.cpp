#include <iostream>
#include <string>
using namespace std;

int main(int argv,char *argc[])
{

	string str,PiStr;
	int i;
	for (i = str.length()-1; i >= 0; i--)
	{
		if(str[i]!=' ')
			break;
	}
	int tlen=str.length();
	for (i = 0; i < tlen; i++)
	{
		if(str[i]!=' ')
			break;
	}
	for (int j = 0; j < tlen; j++)
	{
		if(str[j]==' ')
		{
			cout<<"No"<<endl;
			break;
		}
	}
	int k=0;
	for (i = 0; i < tlen; i++)
	{
		if(str[i]!=' ')
			PiStr[k++]=str[i];
	}
	int len=PiStr.length();
	for (i = 0; i < len; i++)
	{
		if((!(PiStr[i]>='0'&&PiStr[i]<='9'))&&PiStr[i]!='.'&&PiStr[i]!='e'&&PiStr[i]!='E'&&PiStr[i]!='+'&&PiStr[i]!='-')
			{
				cout<<"No"<<endl;
				break;
		}
	}
	for (i = 0; i < len; i++)
	{
		if(PiStr[i]=='e'||PiStr[i]=='E')
		{
			for (int j = i; j < len; j++)
			{
				if(PiStr[j]=='.')
				{
					cout<<"No"<<endl;
					break;
				}
			}
		}
	}
	if()
	return 0;
}
