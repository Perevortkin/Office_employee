
#include "TimeWorker.h"


TimeWorker::TimeWorker():Worker(),hour_rate(0){}

TimeWorker::TimeWorker(int id, string nam, double pay) //конструктор с параметрами
{
  ident = id;
  name=nam;
  hour_rate=pay;
  CalcZp();
}

TimeWorker::TimeWorker(const TimeWorker& TW) // онструктор копировани€
{
	this->hour_rate =TW.hour_rate;
	this->ident=TW.ident;
	this->name = TW.name;
	this->CalcZp();
}

TimeWorker::~TimeWorker()
{
}

ostream& operator<<(ostream& obj,const TimeWorker& TW) //перегрузка << дл€ вывода в консоль
{
	 	  cout<<TW.ident<<"  "<<TW.name<<"  "<<TW.hour_rate<<"  "<<TW.zp;
return obj;
}

ofstream& operator<<(ofstream& obj, TimeWorker* TW ) //перегрузка << дл€ вывода данных в файл
{
	 	obj<<TW->ident<<" "<<TW->name<<" "<<TW->hour_rate<<"\n";
return obj;
}

ifstream& operator>>(ifstream& obj, TimeWorker* TW ) //перегрузка >> дл€ ввода данных из файла
{
	 	obj>>TW->ident>>TW->name>>TW->hour_rate;
		TW->CalcZp();
return obj;
}


