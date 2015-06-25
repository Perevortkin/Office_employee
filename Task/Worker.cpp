
#include "Worker.h"


Worker::Worker():name(""),ident(0),zp(0) {}
Worker::Worker(Worker && emp){
	name = emp.name;
	ident = emp.ident;
	zp = emp.zp;
}
Worker & Worker::operator=(Worker && emp){
	swap(name, emp.name);
	swap(ident, emp.ident);
	swap(zp, emp.zp);
	return *this;
}

Worker::~Worker()
{
}


bool Worker::operator<(Worker& W) //����������� �������� < (� ������������� ���������)
{
	if(this->zp<W.zp) //���� zp ������ ������� ������ zp �������
		return true;  //���������� ������
	else //���� ������ ���� ����
	{
		if(this->zp==W.zp) //�������� �� ��������� zp 
			if(this->name[0] > W.name[0]) //���� zp �����, �� ��������� ����� ���������� ������ ���� string
			  return true; 
			else return false;
		else return false;
	}	
	return false;
}
void Worker::Show() //������� ������ ���������� �� �������
{
	cout<<ident<<" "<<name<<" "<<zp;
}
string Worker::Getname() //������� ��������� ����� ���������
{
	string n;
	return n=name;
}

int Worker::GetIndent() //������� ��������� �������������� ���������
{
	return ident;
}