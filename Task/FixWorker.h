#pragma once
#include "worker.h"
class FixWorker : public Worker
{
protected:
	double fix_zp;
public:
	FixWorker();
	FixWorker(const FixWorker&); //конструктор копирования
	FixWorker(int,string, double); //конструктор с параметрами
	virtual ~FixWorker();
	void CalcZp(void){zp=fix_zp;} //Расчет ЗП
	friend ostream& operator<<(ostream&,const FixWorker&); //перегрузка << для вывода в консоль
	friend ofstream& operator<<(ofstream&, FixWorker* );//перегрузка << для вывода в файл
	friend ifstream& operator>>(ifstream&, FixWorker*); //перегрузка >> для ввода из файла
};

