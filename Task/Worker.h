#pragma once
#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <iterator>
#include <string>
#include <typeinfo>
#include <fstream>
#include <iostream>
#include <memory>
using namespace std;
class Worker //Абстрактный базовый класс
{
protected:
	string name;
	int ident;
	double zp;
public:
	Worker();
	Worker(Worker &&);
	virtual ~Worker();
	virtual void CalcZp()=0; //чистая виртуальная функция расчета ЗП (должна быть реализована в каждом классе наследнике)
	virtual void Show(); //функция выводит информацию о работнике
	bool operator<(Worker&);
	Worker & operator=(Worker &&);
	string Getname();
	int GetIndent();
};

