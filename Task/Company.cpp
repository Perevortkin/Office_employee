
#include "Company.h"


Company::Company()
{
}


Company::~Company()
{
}



void Company::Show() //Функция показать все элементы вектора
{
	iter=sp.begin(); //устанавливаем итератор на начало вектора sp
	while(iter!=sp.end()) //пока не конец sp
	{
		(*iter)->Show(); //через разименованый итератор *iter добираемся до элемента списка, а поскольку это указатель,  то через него к функции Show 
		                 //реализованной в каждом классе TimeWorker и FixWorker и объявленной в Woker как чистая виртуальная 
		cout<<"\n";      
		iter++;         //увеличиваем итератор
	}
}

void Company::SortMinZp() //функция сортировки вектора sp по убыванию среднемесячного заработка
{
	for(int i=0;i<sp.size();i++)
	{
		for(int j=i+1;j<sp.size();j++) 
			if(*(sp[i])<*(sp[j])) 
				                 
				swap(sp[j],sp[i]); 
	}

}

void Company::ReadFile(string& nfile) //Функция чтения обектов в список (структура классов сохраняется)
{
	sp.clear(); //очистка списка
	string strf;
	ifstream fin(nfile,ios::in); ///устанавливаем файл nfile в режим чтения
	if(!fin) //попытка открыть файл для чтения
	{
		cout<<"cannot open file for read";
	}
	while(!fin.eof()) //пока не конец файла
	{
		strf="";
		fin>>strf; //читаем в переменную данные (все данные в файле разделены пробелами)

		if(strf=="TimeWorker") //если встретили TimeWorker, значит за ним идут данные этого класса
		{
			TimeWorker tw; //создаем объект типа TimeWorker
			fin>>&tw; //поскольку оператор >> ifstream перегружен в классе TimeWorker для указателя выполняем операцию взятия адреса & для объекта tw
			shared_ptr<TimeWorker>ptr(new TimeWorker(tw)); 
			sp.push_back(ptr);      //добавляем указатель в вектор sp (указателей базового класса Worker)
		}
		if(strf=="FixWorker")
		{
			FixWorker fw;
			fin>>&fw; //поскольку оператор >> ifstream перегружен в классе FixWorker для указателя выполняем операцию взятия адреса & для объекта fw
			shared_ptr<FixWorker>ptr(new FixWorker(fw));	                        
			sp.push_back(ptr);      //добавляем указатель в вектор sp (указателей базового класса Worker)
		}
       
	}
		fin.close(); //закрываем файл
}

void Company::WriteFile(string& nfile) //Функция записи объектов наших классов из списка в файл
{
	iter=sp.begin();//позиционируем итератор на начало вектора

	ofstream fout(nfile,ios::out); //устанавливаем файл nfile в режим записи
	if(!fout) //попытка открыть файл для записи
	{
		cout<<"cannot open file for write";
	}
	int i=0;
	while(iter!=sp.end()) //пока не конец вектора
	{   
		if (typeid(*iter).name() == "TimeWorker")
		{		
		   fout<<typeid(*iter).name()<<" "; //записать имя класса в файл
		   fout<<(*iter); //записываем значения полей класса TimeWorker в файл через перегруженный в классе TimeWorker << для ofstream (для указателя)
		}
		if (typeid(*iter).name() == "FixWorker")
		{
		   fout<<typeid(*iter).name()<<" "; //записать имя класса в файл
		   fout<<(*iter); //записываем значения полей класса FixWorker в файл через перегруженный в классе FixWorker << для ofstream (для указателя)
		}
		iter++;
	}
		fout.close(); //закрываем файл 
		cout<<"Write file "<<nfile<<"\n";
}

void Company::First5name() //Функция вывода первых пяти элементов списка
{
	iter=sp.begin();//позиционируем итератор на начало вектора
	int cnt=0; //Обнуляем счетчик записей для вывода
	while(iter!=sp.end() && cnt<5) //двигаемся к концу вектора и отсчитываем 5 записей
	{
		cout<<cnt+1<<".name=> "<<(*iter)->Getname()<<"\n";//выводим записи
		iter++;
		cnt++;
	}
}

void Company::End3ident() //Функция вывода последних трех элементов списка
{
	iter=sp.end()-1; //устанавливаем итератор на последний элемент (отнимаем 1 поскольку sp.end() указывает за границу вектора)
	int cnt=0; //Обнуляем счетчик записей для вывода
	while(iter!=sp.begin() && cnt<3) //двигаемся к началу вектора и отсчитываем 3 записи с конца
	{
		cout<<cnt+1<<". identifier=> "<<(*iter)->GetIndent()<<"\n"; //выводим записи
		iter--;//смещаемся на 1 к началу вектора
		cnt++; //увеличиваем на 1 счетчик записей
	}
}