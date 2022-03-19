#include"ForeignWorker.cpp"

//------------------------------------------------------------------------
bool operator ==(const Human* worker, string surname)
{
	return (worker->get_surname() == surname);
}
//------------------------------------------------------------------------
//Human& operator=(const Human& human)
//{
//
//}
//------------------------------------------------------------------------
istream& operator>> (istream& in, vector <Human*>& workman)
{
	int flag = 0;
	string flagInput;
L:
	cout << "To add Worker press-0, to ForeignWorker-1" << endl;
	cin >> flagInput;
	{
		try
		{
			flag = stoi(flagInput);
			if (flag < 0)
			{
				cout << "Try again \n";
				goto L;
			}
			if (flag > 1)
			{
				cout << "Try again \n";
				goto L;
			}
		}
		catch (invalid_argument)
		{
			cout << "Only numbers are allowed! \n";
			goto L;
		}
		catch (out_of_range)
		{
			cout << "Try again \n";
			goto L;
		}
		catch (...)
		{
			cout << "Unknown error! \n";
			goto L;
		}
	}
	if (flag)
	{
		workman.push_back(new ForeignWorker);
		workman[workman.size() - 1]->set_info();
	}
	else
	{
		workman.push_back(new Worker);
		workman[workman.size() - 1]->set_info();
	}
	return in;
}
//------------------------------------------------------------------------
int control_value(int& value, string valueInput, int rang)
{
	try
	{
		value = stoi(valueInput);
	}
	catch (invalid_argument)
	{
		cout << "Only numbers are allowed! \n";
		return 1;
	}
	catch (out_of_range)
	{
		cout << "Out of the range \n";
		return 1;
	}
	catch (...)
	{
		cout << "Unknown error! \n";
		return 1;
	}
	if (value < 0)
	{
		cout << "Try again! \n";
		return 1;
	}
	if (rang == 1 && value > 1)
	{
		cout << "Try again \n";
		return 1;
	}
	for (int i = 0; i < valueInput.length(); i++)
	{
		if ((int)valueInput[i] > 57 || (int)valueInput[i] < 48)
		{
			cout << "Try again \n";
			return 1;
		}
	}

	return 0;
}
//------------------------------------------------------------------------
void table_ouput()
{
	cout << "Fio" << setw(27) << " " << "|";
	cout << setw(6) << "ID" << "|";
	cout << setw(20) << "Profession" << "|";
	cout << setw(20) << "Department" << "|";
	cout << setw(20) << "Salary" << "|";
	cout << setw(20) << "Country from" << "|";
	cout << setw(20) << "End working" << "|";
	cout << endl;
}
//------------------------------------------------------------------------
void menu(vector <Human*>& workman)
{
	for (int menu = 0; menu != 8;)
	{
		string menuInput;
		cout << "===========================================" << endl << endl;
		cout << "Вывести данные в табличном виде...........1" << endl;
		cout << "Добавить работника в базу.................2" << endl;
		cout << "Поикс по номеру отдела....................3" << endl;
		cout << "Сортировка по убыванию оклада.............4" << endl;
		cout << "Найти всех работников с заданной фамилией.5" << endl;
		cout << "Добавить несколько новых работников.......6" << endl;
		cout << "Проработавшие более 10 лет................7" << endl;
		cout << "Выйти из программы........................8" << endl;
	D:
		cin >> menuInput;
		if (control_value(menu, menuInput, 0))
			goto D;

		system("cls");

		switch (menu)
		{
		case 1:
		{
			cout << "Print full data base::" << endl;
			table_ouput();
			for (int i = 0; i < workman.size(); i++)
			{
				workman[i]->table_out();
			}
			break;
		}
		case 2:
		{
			int flag = 0;
			string flagInput;
		F:
			cout << "To add Worker press-0, to ForeignWorker-1" << endl;
			cin >> flagInput;
			if (control_value(flag, flagInput, 1))
				goto F;

			if (flag)
			{
				workman.push_back(new ForeignWorker);	//добавляю объект в вектор
				workman[workman.size() - 1]->set_info();

			}
			else
			{
				workman.push_back(new Worker);	//добавляю объект в вектор
				workman[workman.size() - 1]->set_info();
			}
			break;
		}
		case 3:
		{
			int department = 0;
			string departmentInput;
		R:
			cout << "Department number:";
			cin >> departmentInput;
			if (control_value(department, departmentInput, 0))
				goto R;

			bool chek = true;
			for (int i = 0; i < workman.size(); i++)
			{
				if (workman[i]->get_department() == department)
				{
					workman[i]->get_info();
					chek = false;
				}
			}
			if (chek)
				cout << "Workers are not found \n";
			break;
		}
		case 4:
		{
			for (int count = 0; count < workman.size(); count++)
			{
				for (int i = 0; i < workman.size(); i++)
				{
					int SmallestIndex = i;
					for (int j = i + 1; j < workman.size(); j++)
					{
						if (workman[SmallestIndex]->get_salary() < workman[j]->get_salary())
							SmallestIndex = j;
					}

					workman[i]->salary_sort(&SmallestIndex);
					workman[SmallestIndex]->salary_sort(&i);

					swap(workman[i], workman[SmallestIndex]);
				}
			}
			cout << "Отсортировано" << endl;
			break;
		}
		case 5:
		{
			string surname;
			cout << "Введите фамилию:";
			cin >> surname;
			int tmp = 0;
			for (int i = 0; i < workman.size(); i++)
			{
				if (workman[i] == surname)
				{
					workman[i]->get_info();
					cout << "-------------------------------------------" << endl;
					tmp++;
				}
				if (tmp == 0 && (i + 1) == workman.size())
					cout << "-------------------------------------------" << endl << "Такого работника нет" << endl;
			}
			break;
		}
		case 6:
		{
			int value = 0;
			string valueInput;
		K:
			cout << "Workers quantity: ";
			cin >> valueInput;
			if (control_value(value, valueInput, 0))
				goto K;

			for (int i = 0; i < value; i++)
			{
				cin >> workman;
				system("cls");
			}

			break;
		}
		case 7:
		{
			Date now;
			now.set_Date();
			table_ouput();
			for (int i = 0; i < workman.size(); i++)
			{
				if ((now.year - workman[i]->get_year()) > 10)
				{
					workman[i]->table_out();
				}
			}
		}
		}
		if (menu != 8)
			system("pause");
	}
}
//------------------------------------------------------------------------
void data_base(vector <Human*>& workman)
{
	if (workman.size() != 0)	//проверяю на загрузку из файла
		cout << "Data base upload" << endl;
	else
	{
		string numberInput;
		int number = 0;
	C:
		cout << "Workers quantity: ";
		getline(cin, numberInput);
		if (control_value(number, numberInput, 0))
			goto C;

		string flagInput;
		int flag = 0;

		for (int i = 0; i < number; i++)
		{
		B:
			cout << "To add Worker press-0, to ForeignWorker-1" << endl;
			cin >> flagInput;
			if (control_value(flag, flagInput, 1))
				goto B;
			system("cls");
			if (flag == 1)
			{
				workman.push_back(new ForeignWorker);	//добавляю объект в вектор
				workman[i]->set_info();

			}
			else
			{
				workman.push_back(new Worker);	//добавляю объект в вектор
				workman[i]->set_info();
			}
			system("cls");
		}

	}
}
//------------------------------------------------------------------------
void save_data_base(vector <Human*>& workman)
{
	ofstream file_txt;
	file_txt.open("file.txt");

	file_txt << workman.size() << endl;
	for (int i = 0; i < workman.size(); i++)
	{
		file_txt << workman[i]->get_num() << endl;
		workman[i]->get_info_for_db(&file_txt);
	}
	file_txt.close();
}
//------------------------------------------------------------------------
void load_data_base(vector <Human*>& workman)
{
	ifstream file_txt;
	file_txt.open("file.txt");
	if (file_txt.is_open())
	{
		int size = 0;
		file_txt >> size;

		for (int i = 0; i < size; i++)
		{
			int num;
			file_txt >> num;
			if (num == 1)
				workman.push_back(new Worker);
			else
				workman.push_back(new ForeignWorker);

			workman[i]->set_info_from_db(&file_txt);
		}
	}
	file_txt.close();
}
//------------------------------------------------------------------------
int Worker::count = 0;
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);	//для русских

	vector <Human*> workman;	//вектор указателей на базовый(начальный) объект

	load_data_base(workman);	//загрузка дб из файла

	data_base(workman);
	menu(workman);

	save_data_base(workman);	//сохранение дб в файл	

	return 0;
}