#include <iostream>
#include <string>
using namespace std;
bool IsDig(char ch)
{
      
  if ((ch>'9') || (ch<'0') )
  { 
   return   false; 
  } 
    
 return   true; 
}
int main(int argv,char *argc[])
{

	string str,PiStr;
	cin>>PiStr;
	int i,flag=1,k=0;
	int len=PiStr.length();

	for (int j = 1; j < len-1; j++)
	{
		if(PiStr[j]==' '&&flag)
		{
			cout<<"NO"<<endl;
			flag=0;
			break;
		}
	}


	for (i = 0; i < len; i++)
	{
			if(flag&&(!(PiStr[i]>='0'&&PiStr[i]<='9'))&&PiStr[i]!='.'&&PiStr[i]!='e'&&PiStr[i]!='E'&&PiStr[i]!='+'&&PiStr[i]!='-')
		{
				cout<<"NO"<<endl;
				flag=0;
				break;
		}

	
		else if(flag&&(PiStr[i]=='e'||PiStr[i]=='E'))
		{
			for (int j = i; j < len; j++)
			{
				if(PiStr[j]=='.'&&flag)
				{
					cout<<"NO"<<endl;
					flag=0;
					break;
				}
				
			}
			if(i==len-1)
			{
				cout<<"NO"<<endl;flag=0;break;
			}
			if(!IsDig(PiStr[i-1])&&flag)
			{
			    cout<<"NO"<<endl;flag=0;break;}
		}
			else if(flag&&(PiStr[i]=='.'))
		{
			if(i==0)
			{
				cout<<"NO"<<endl;flag=0;break;
			}
			if(i==len-1)
			{
				cout<<"NO"<<endl;flag=0;break;
			}
            else if(!IsDig(PiStr[i-1])&&!IsDig(PiStr[i+1])&&flag)
            {
                cout<<"NO"<<endl;flag=0;break;
            }
			else{
			for(int j=i+1;j<len;j++)
			{
				if(PiStr[j]=='.'&&flag)
				{
					cout<<"NO"<<endl;flag=0;break;
				}
			}
			}
		}
			else
				k++;
		if(flag&&(PiStr[i]=='+'||PiStr[i]=='-'))
         {
             for(int j=i+1;j<len;j++)
              if((PiStr[j]=='+'||PiStr[j]=='-')&&flag)
              {
				  if(PiStr[j-1]=='E'||PiStr[j-1]=='e')
				  {
					  break;
				  }
				  else
				  {
					cout<<"NO"<<endl;
					flag=0;
					break;
				  }
              }
			  if(i==len-1)
			{
				cout<<"NO"<<endl;flag=0;break;
			}
         }
	
	}
	if(flag&&k<len)
		cout<<"YES"<<endl;
	else if(flag)
		cout<<"NO"<<endl;
	return 0;
}