
#include "Company.h"


Company::Company()
{
}


Company::~Company()
{
}



void Company::Show() //������� �������� ��� �������� �������
{
	iter=sp.begin(); //������������� �������� �� ������ ������� sp
	while(iter!=sp.end()) //���� �� ����� sp
	{
		(*iter)->Show(); //����� ������������� �������� *iter ���������� �� �������� ������, � ��������� ��� ���������,  �� ����� ���� � ������� Show 
		                 //������������� � ������ ������ TimeWorker � FixWorker � ����������� � Woker ��� ������ ����������� 
		cout<<"\n";      
		iter++;         //����������� ��������
	}
}

void Company::SortMinZp() //������� ���������� ������� sp �� �������� ��������������� ���������
{
	for(int i=0;i<sp.size();i++)
	{
		for(int j=i+1;j<sp.size();j++) 
			if(*(sp[i])<*(sp[j])) 
				                 
				swap(sp[j],sp[i]); 
	}

}

void Company::ReadFile(string& nfile) //������� ������ ������� � ������ (��������� ������� �����������)
{
	sp.clear(); //������� ������
	string strf;
	ifstream fin(nfile,ios::in); ///������������� ���� nfile � ����� ������
	if(!fin) //������� ������� ���� ��� ������
	{
		cout<<"cannot open file for read";
	}
	while(!fin.eof()) //���� �� ����� �����
	{
		strf="";
		fin>>strf; //������ � ���������� ������ (��� ������ � ����� ��������� ���������)

		if(strf=="TimeWorker") //���� ��������� TimeWorker, ������ �� ��� ���� ������ ����� ������
		{
			TimeWorker tw; //������� ������ ���� TimeWorker
			fin>>&tw; //��������� �������� >> ifstream ���������� � ������ TimeWorker ��� ��������� ��������� �������� ������ ������ & ��� ������� tw
			shared_ptr<TimeWorker>ptr(new TimeWorker(tw)); 
			sp.push_back(ptr);      //��������� ��������� � ������ sp (���������� �������� ������ Worker)
		}
		if(strf=="FixWorker")
		{
			FixWorker fw;
			fin>>&fw; //��������� �������� >> ifstream ���������� � ������ FixWorker ��� ��������� ��������� �������� ������ ������ & ��� ������� fw
			shared_ptr<FixWorker>ptr(new FixWorker(fw));	                        
			sp.push_back(ptr);      //��������� ��������� � ������ sp (���������� �������� ������ Worker)
		}
       
	}
		fin.close(); //��������� ����
}

void Company::WriteFile(string& nfile) //������� ������ �������� ����� ������� �� ������ � ����
{
	iter=sp.begin();//������������� �������� �� ������ �������

	ofstream fout(nfile,ios::out); //������������� ���� nfile � ����� ������
	if(!fout) //������� ������� ���� ��� ������
	{
		cout<<"cannot open file for write";
	}
	int i=0;
	while(iter!=sp.end()) //���� �� ����� �������
	{   
		if (typeid(*iter).name() == "TimeWorker")
		{		
		   fout<<typeid(*iter).name()<<" "; //�������� ��� ������ � ����
		   fout<<(*iter); //���������� �������� ����� ������ TimeWorker � ���� ����� ������������� � ������ TimeWorker << ��� ofstream (��� ���������)
		}
		if (typeid(*iter).name() == "FixWorker")
		{
		   fout<<typeid(*iter).name()<<" "; //�������� ��� ������ � ����
		   fout<<(*iter); //���������� �������� ����� ������ FixWorker � ���� ����� ������������� � ������ FixWorker << ��� ofstream (��� ���������)
		}
		iter++;
	}
		fout.close(); //��������� ���� 
		cout<<"Write file "<<nfile<<"\n";
}

void Company::First5name() //������� ������ ������ ���� ��������� ������
{
	iter=sp.begin();//������������� �������� �� ������ �������
	int cnt=0; //�������� ������� ������� ��� ������
	while(iter!=sp.end() && cnt<5) //��������� � ����� ������� � ����������� 5 �������
	{
		cout<<cnt+1<<".name=> "<<(*iter)->Getname()<<"\n";//������� ������
		iter++;
		cnt++;
	}
}

void Company::End3ident() //������� ������ ��������� ���� ��������� ������
{
	iter=sp.end()-1; //������������� �������� �� ��������� ������� (�������� 1 ��������� sp.end() ��������� �� ������� �������)
	int cnt=0; //�������� ������� ������� ��� ������
	while(iter!=sp.begin() && cnt<3) //��������� � ������ ������� � ����������� 3 ������ � �����
	{
		cout<<cnt+1<<". identifier=> "<<(*iter)->GetIndent()<<"\n"; //������� ������
		iter--;//��������� �� 1 � ������ �������
		cnt++; //����������� �� 1 ������� �������
	}
}