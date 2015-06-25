
#include "FixWorker.h"


FixWorker::FixWorker():Worker(),fix_zp(0){}

FixWorker::FixWorker(int id, string nam, double pay)
{
  ident = id;
  name=nam;
  fix_zp=pay;
  CalcZp();
}

FixWorker::FixWorker(const FixWorker& FW) //Конструктор копирования
{
	this->fix_zp =FW.fix_zp;
	this->ident=FW.ident;
	this->name = FW.name;
	this->CalcZp();
}

FixWorker::~FixWorker()
{
}

ostream& operator<<(ostream& obj,const FixWorker& FW) //перегрузка << для вывода в консоль
{
	 	  cout<<FW.ident<<"  "<<FW.name<<"  "<<FW.fix_zp<<"  "<<FW.zp;
return obj;
}

ofstream& operator<<(ofstream& obj, FixWorker* FW ) //перегрузка << для вывода данных в файл
{
	 	obj<<FW->ident<<" "<<FW->name<<" "<<FW->fix_zp<<"\n";
return obj;
}

ifstream& operator>>(ifstream& obj, FixWorker* FW )  //перегрузка >> для ввода данных из файла 
{
	 	obj>>FW->ident>>FW->name>>FW->fix_zp;
		FW->CalcZp();
return obj;
}



