#pragma once
#include"Support_Classes.cpp"
class Worker;

class Human
{
protected:
	Fio human;
	string profession;
	int ID = 0;
	Date start_working;

	Human()
	{
		human;
		profession;
	}

public:

	virtual int get_num()
	{
		return 0;
	}

	virtual void set_info()
	{
		cout << "Fio: " << endl;
		human.set_Fio();
		cout << "Profession: ";
		cin >> profession;
		cout << "Start working: " << endl;
		start_working.set_Date();
	}

	virtual void get_info()
	{
		cout << "Fio: " << human.get_Fio() << endl;
		cout << "Profession: " << profession << endl;
	}

	virtual int get_department()
	{
		return 0;
	}

	virtual double get_salary()
	{
		return 0;
	}

	virtual void salary_sort(int* ID) {}

	string get_surname() const
	{
		return human.get_surname();
	}

	virtual void table_out() {}

	virtual void get_info_for_db(std::ofstream* file_txt) {}

	virtual void set_info_from_db(std::ifstream* file_txt) {}

	int get_year()
	{
		return start_working.year;
	}
};