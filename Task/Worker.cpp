
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


bool Worker::operator<(Worker& W) //Перегружаем оператор < (с определенными условиями)
{
	if(this->zp<W.zp) //Если zp левого объекта меньше zp правого
		return true;  //возвращаем истину
	else //если больше либо рано
	{
		if(this->zp==W.zp) //Проверка на равенство zp 
			if(this->name[0] > W.name[0]) //Если zp равны, то проверяем имена сравниваем строки типа string
			  return true; 
			else return false;
		else return false;
	}	
	return false;
}
void Worker::Show() //Функция вывода информации об объекте
{
	cout<<ident<<" "<<name<<" "<<zp;
}
string Worker::Getname() //Функция получения имени работника
{
	string n;
	return n=name;
}

int Worker::GetIndent() //Функция получения идентификатора работника
{
	return ident;
}