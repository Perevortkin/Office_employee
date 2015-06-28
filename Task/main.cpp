#include "Company.h"

int main()
{   
	Company comp; //создаем объект типа Firma
	string namef= "company.sps"; //задаем имя файла для выгрузки/загрузки коллекции
	int key;
        int quit=1;
        while (quit)
        {

        cout<<"---------Input operation-----------\n";
	cout<<"1: Load workers with file \n";
	cout<<"2: Wrire workers in file \n";
	cout<<"3: Show worker \n";
	cout<<"4: Sort workers list \n";
        cout<<"5: Show 5 first names  workers \n";
	cout<<"6: Show 3 end identifier  workers \n";
	cout<<"0: Exit \n";
	cout<<"=>";
	cin>>key;
	switch(key)
	{
		case 1:
			comp.ReadFile(namef);
			comp.Show();

		break;
		case 2:
			comp.WriteFile(namef);
		break;
		case 3:
			comp.Show();
		break;
		case 4:
			comp.SortMinZp();
			comp.Show();
		break;
		case 5:
			comp.First5name();
		break;
		case 6:
			comp.End3ident();
		break;
                case 0: quit=0;
                break;

	}

        }
	return 0;
}

