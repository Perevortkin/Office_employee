#pragma once
#include "worker.h"
class TimeWorker : public Worker
{
protected:
	double hour_rate;
public:
	TimeWorker();
	TimeWorker(int,string, double); //конструктор с параметрами
	TimeWorker(const TimeWorker&); //конструктор копирования
	virtual ~TimeWorker();
	void CalcZp(void){zp=20.8*8*hour_rate;} //расчет ЗП
	friend ostream& operator<<(ostream&,const TimeWorker&); //перегрузка << для вывода в консоль
	friend ofstream& operator<<(ofstream&, TimeWorker* ); //перегрузка << для вывода в файл
	friend ifstream& operator>>(ifstream&, TimeWorker* ); //перегрузка >> для ввода из файла
};

