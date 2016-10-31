#include <iostream>
#include <string>
using namespace std;

typedef struct 
{
	char data[6];
	int top;
}Stack;
Stack analysis_Stack;
int line_num;
string forcast_table(char non_terminal,char terminal)
{
	switch (terminal)
	{
	case 'i':switch (non_terminal)
			 {
	case 'E':return "TG";break;
	case 'T':return "FS";break;
	case 'F':return "i";break;
	default:return "";break;
			 }
	case '+':switch (non_terminal)
			 {
	case 'G':return "+TG";break;
	case 'S':return "&";break;
	default:return "";break;
			 }
	case '*':switch (non_terminal)
			 {
	case 'S':return "*FS";break;

	default:return "";break;
			 }
	case '(':switch (non_terminal)
			 {
	case 'E':return "TG";break;
	case 'T':return "FS";break;
	case 'F':return "(E)";break;
	default:return "";break;
			 }
	case ')':switch (non_terminal)
			 {
	case 'G':return "&";break;
	case 'S':return "&";break;
	default:return "";break;
			 }
	case '#':switch (non_terminal)
			 {
	case 'G':return "&";break;
	case 'S':return "&";break;
	default:return "";break;
			 }
	default:return "";break;
	}
}
bool InputStr(char ch)
{
	char analy_top=analysis_Stack.data[analysis_Stack.top];
	while ((analy_top!=ch)&&(analysis_Stack.top!=0)&&(analy_top=='E'||analy_top=='T'||analy_top=='F'||analy_top=='S'||analy_top=='G'))
	{
		string result=forcast_table(analy_top,ch);
		if(result!=""||(!result.empty()))
		{
			cout<<line_num++<<" "<<analy_top<<"-->"<<result<<endl;
			analysis_Stack.data[analysis_Stack.top]=NULL;
			analysis_Stack.top--;
			if(result!="&")
				for (int i = result.length()-1; i >= 0; i--)
				{
					analysis_Stack.data[++analysis_Stack.top]=result.at(i);
				}
		}
		else
		{
			cout<<line_num++<<" "<<analy_top<<"-->&"<<endl;
			analysis_Stack.data[analysis_Stack.top--]=NULL;
		}
		analy_top=analysis_Stack.data[analysis_Stack.top];
	}
	if(analysis_Stack.data[analysis_Stack.top]==ch) 
	{
		analysis_Stack.data[analysis_Stack.top]=NULL;
		analysis_Stack.top--;
		return true;
	}
	else
		return false;
}
int main(int argv,char *argc[])
{
	string str;
	cin>>str;
	line_num=0;

	analysis_Stack.top=-1;
	analysis_Stack.data[++analysis_Stack.top]='#';
	analysis_Stack.data[++analysis_Stack.top]='E';
	int i=0;
	bool flag;
	while (i<str.length())

	{

		flag=InputStr(str.at(i));
		if(flag)
			i++;
		else
			break;
	}
	if(analysis_Stack.top==-1)
		cout<<"accept"<<endl;
	else
		cout<<"error"<<endl;
	return 0;
}