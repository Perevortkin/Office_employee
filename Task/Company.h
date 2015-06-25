#pragma once
#include "Worker.h"
#include "FixWorker.h"
#include "TimeWorker.h"
class Company
{
	
protected:
	vector <shared_ptr<Worker>> sp;
	vector <shared_ptr<Worker>>::iterator iter;
public:
	Company();
	virtual ~Company();
	void Show();        //Функция вывода списка на экран
	void SortMinZp();   //Функция сортировки списка по убыванию среднемесячной ЗП, если ЗП одинаковая то по алфавиту по имени
	void ReadFile(string&); //Функция чтения данных из файла в список сотрудников
	void WriteFile(string&);//Функция записи данных из списка сотрудников в файл
	void First5name();  //Функция вывода первых пяти имен работников из списка
	void End3ident();   //Функция вывода последних трех идентификаторов работников из списка
};

