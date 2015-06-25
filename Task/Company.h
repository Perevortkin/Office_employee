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
	void Show();        //������� ������ ������ �� �����
	void SortMinZp();   //������� ���������� ������ �� �������� �������������� ��, ���� �� ���������� �� �� �������� �� �����
	void ReadFile(string&); //������� ������ ������ �� ����� � ������ �����������
	void WriteFile(string&);//������� ������ ������ �� ������ ����������� � ����
	void First5name();  //������� ������ ������ ���� ���� ���������� �� ������
	void End3ident();   //������� ������ ��������� ���� ��������������� ���������� �� ������
};

