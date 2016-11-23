#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;
#include <stdio.h>
typedef struct BasicAyyay
{
	int line_num;
	string key_word;
	string sentence;
}TinyBasic_list;
typedef struct LNode
{
	char iden;
	int data;
	struct LNode *next;
}*Iden_list;


typedef::vector<TinyBasic_list*> TiB_list;
int line_num;
void Let(Iden_list &iden_list,string sentence)
{
	string temp;LNode *s,*p=NULL;
	p=iden_list->next;
	s=(LNode *)malloc(sizeof(LNode));
	int flag=1;
	while(p&&flag)
	{
		if(p->iden==sentence.at(0))
		{
			s=p;flag=0;
		}
		p=p->next;

	}
	if(flag)
		s->iden=sentence.at(0);
	char* end;
	if(sentence.at(2)<='9'&&sentence.at(2)>='0')
	{
		for (int i = 2; i < sentence.length(); i++)
		{
			temp+=sentence.at(i);
		}
		s->data=static_cast<int>(strtol(temp.c_str(),&end,10));
		if(flag)
		{
			s->next=iden_list->next;
			iden_list->next=s;
		}
	}
	else
	{
		LNode *p=NULL,*vri1=NULL,*vri2=NULL;
		p=iden_list->next;
		while (p)
		{
			if(p->iden==sentence.at(2))
				vri1=p;
			if(p->iden==sentence.at(4))
				vri2=p;
			p=p->next;
		}
		if(!vri1)
			s->data=vri2->data;
		else if(!vri2)
			s->data=vri1->data;
		else
			s->data=vri1->data+vri2->data;
		if(flag)
		{
			s->next=iden_list->next;
			iden_list->next=s;
		}
	}
}
void Print(Iden_list &iden_list,string sentence)
{
	char temp=sentence.at(0);
	LNode *p=NULL;
	p=iden_list->next;
	int flag=0;
	while (p)
	{
		if(p->iden==temp)
		{
			cout<<p->iden<<"="<<p->data<<endl;
			flag=1;
			break;
		}
		p=p->next;
	}
	if(!flag)
		cout<<temp<<"=0"<<endl;
}
bool If(Iden_list &iden_list,string sentence)
{
	LNode *p=NULL,*vri1=NULL,*vri2=NULL;

	p=iden_list->next;
	int flag=0;
	if(sentence.length()>=3)
	{
		while (p)
		{
			if(p->iden==sentence.at(0))
				vri1=p;
			if(p->iden==sentence.at(2))
				vri2=p;


			p=p->next;
		}
	}
	if(vri1==NULL||vri2==NULL)
	{
		char* end;
		int data=static_cast<int>(strtol(sentence.c_str(),&end,10));
		if(data)
			return true;
		else
			return false;
	}
	else
	{
		if(sentence.at(1)=='>'&&(vri1->data>vri2->data))
			return true;
		else if(sentence.at(1)=='+'&&(vri1->data+vri2->data)!=0)
			return true;
		else
			return false;
	}
}
int GOTO(Iden_list &iden_list,string sentence)
{
	LNode *p=NULL,*vri1=NULL,*vri2=NULL;

	p=iden_list->next;
	int flag=0;
	if(sentence.length()>=3)
	{
		while (p)
		{
			if(p->iden==sentence.at(0))
				vri1=p;
			if(p->iden==sentence.at(2))
				vri2=p;


			p=p->next;
		}
	}
	if(vri1==NULL||vri2==NULL)
	{
		char* end;
		int tnum=static_cast<int>(strtol(sentence.c_str(),&end,10));
		return tnum-2;
	}
	else
	{
		if(sentence.at(1)=='>'&&(vri1->data>vri2->data))
			return 1;
		else if(sentence.at(1)=='+')
		{

			return vri1->data+vri2->data-2;
		}
		else
			return 0;
	}
}



TiB_list tin_Basic(TiB_list TiB)
{



	string key_word,sentence;
	while (cin>>line_num>>key_word)
	{
		if(key_word=="STOP")
		{
			TinyBasic_list* temp_list=new TinyBasic_list;
			temp_list->line_num=line_num;
			temp_list->key_word=key_word;
			TiB.push_back(temp_list);
			//break;
		}
		else
		{
			cin>>sentence;
			TinyBasic_list* temp_list=new TinyBasic_list;
			temp_list->line_num=line_num;
			temp_list->key_word=key_word;
			temp_list->sentence=sentence;
			TiB.push_back(temp_list);
		}
	}
	return TiB;
}
int main(int argv,char *argc[])
{
	Iden_list identifier_list;
	identifier_list=(Iden_list)malloc(sizeof(LNode));
	identifier_list->next=NULL;
	TiB_list TiB;
	int beginline=0;
	TiB=tin_Basic(TiB);
	//	while ((TiB=tin_Basic(TiB)),EOF)
	//{

	for(int i=beginline;i<line_num;i++)
	{
		if(TiB[i]->key_word=="LET")
		{
			Let(identifier_list,TiB[i]->sentence);
		}
		else if(TiB[i]->key_word=="PRINT")
		{
			Print(identifier_list,TiB[i]->sentence);
		}
		else if(TiB[i]->key_word=="IF")
		{
			bool flag=If(identifier_list,TiB[i]->sentence);
			if(flag&&TiB[i+1]!=NULL)
				continue;
			else if(!flag&&TiB[i+2]!=NULL)
				i++;
		}
		else if(TiB[i]->key_word=="GOTO")
		{
			i=GOTO(identifier_list,TiB[i]->sentence);
		}
		else if(TiB[i]->key_word=="STOP")
		{
			break;
		}
	}
	//}


	return 0;
}