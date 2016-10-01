#include <iostream>
#include <string>
using namespace std;
#define isDigital(x) (((x)>='0')&&((x)<='9'))
bool isOpera(string pro,int i)
{
	if (pro[i]=='='||pro[i]=='+'||pro[i]=='-'||pro[i]=='*'||pro[i]=='/'||pro[i]=='<'||pro[i]=='>'||pro[i]=='!')
	{
		return true;
	}
	else
		return false;
}
bool IsDigit(string str) 
{ 
 for(int i=0;i<str.size();i++) 
 {   
  if ((str.at(i)>'9') || (str.at(i)<'0') )
  { 
   return   false; 
  } 
    } 
 return   true; 
} 
int main(int argv,char *argc[])
{

	string pro;
	while(cin>>pro)
	{
		int len=pro.length();
		string KeyTemp,OpTemp;
		int i;
		bool DigFlag=true;
		for (int i = 0; i <= len; i++)
		{
			
			
			if(pro[i]>='a'&&pro[i]<='z'||pro[i]>='A'&&pro[i]<='Z')
				KeyTemp+=pro[i];
			else if(pro[i]>='0'&&pro[i]<='9')
				KeyTemp+=pro[i]; 
			else
			{
				if(isOpera(pro,i))
					OpTemp+=pro[i];
				/*for (string::iterator itr=KeyTemp.begin();itr!=KeyTemp.end();itr++)
				{
					DigFlag&=isDigital(*itr);
				}*/
				if(KeyTemp.length()>0)
				if(IsDigit(KeyTemp))
				{
					cout<<"(integer,"<<KeyTemp<<")"<<endl;
				
				}
				else if(KeyTemp=="main"||KeyTemp=="if"||KeyTemp=="else"||KeyTemp=="for"||KeyTemp=="while"||KeyTemp=="int")
				{
					cout<<"(keyword,"<<KeyTemp<<")"<<endl;
				
				}
				else
					cout<<"(identifier,"<<KeyTemp<<")"<<endl;
				if((OpTemp.length()>0)&&(!(isOpera(pro,i+1))))
				{
					cout<<"(operator,"<<OpTemp<<")"<<endl;
					OpTemp="";
				}
				if(pro[i]=='{'||pro[i]=='}'||pro[i]=='('||pro[i]==')'||pro[i]==','||pro[i]==';')
					cout<<"(boundary,"<<pro[i]<<")"<<endl;
				KeyTemp="";
				
					
			}
				
		}
			
	
	}
	return 0;
}
