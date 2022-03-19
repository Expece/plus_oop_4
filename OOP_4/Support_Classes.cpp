#pragma once
#include "include.h"

class Fio
{
	string surname;
	string name;
	string middlename;

	Fio()
	{
		surname = "";
		name = "";
		middlename = "";
	}

	void set_Fio()
	{
		cout << "Surname: ";
		cin >> surname;
		cout << "Name: ";
		cin >> name;
		cout << "Middlename: ";
		cin >> middlename;
	}

	string get_Fio()
	{
		return surname + ' ' + name + ' ' + middlename;
	}

	string get_surname() const
	{
		return surname;
	}

	friend class Human;
public:

	void table_out()
	{
		int tab = 30;
		if (get_Fio().length() > tab)
			tab = get_Fio().length();

		cout << setw(tab) << get_Fio() << "|";
	}

	string get_surname()
	{
		return surname;
	}

	void set_surname(string surname)
	{
		this->surname = surname;
	}

	string get_name()
	{
		return name;
	}

	void set_name(string name)
	{
		this->name = name;
	}

	string get_middlename()
	{
		return middlename;
	}

	void set_middlename(string middlename)
	{
		this->middlename = middlename;
	}
};

class Date
{
public:
	int day;
	int month;
	int year;
	Date(int day = 0, int month = 0, int year = 0)
		: day(day), month(month), year(year)
	{}

	void set_Date()
	{
		string dayInput;
	C:
		cout << "Day: ";
		cin >> dayInput;
		{
			try
			{
				day = stoi(dayInput);
				if (day < 0 || day>31)
				{
					cout << "Try again \n";
					goto C;
				}
			}
			catch (invalid_argument)
			{
				cout << "Only numbers are allowed! \n";
				goto C;
			}
			catch (out_of_range)
			{
				cout << "Try again \n";
				goto C;
			}
			catch (...)
			{
				cout << "Unknown error! \n";
				goto C;
			}
		}
		string monthInput;
	A:
		cout << "Month: ";
		cin >> monthInput;
		{
			try
			{
				month = stoi(monthInput);
				if (month < 0 || month>12)
				{
					cout << "Try again \n";
					goto A;
				}
			}
			catch (invalid_argument)
			{
				cout << "Only numbers are allowed! \n";
				goto A;
			}
			catch (out_of_range)
			{
				cout << "Try again \n";
				goto A;
			}
			catch (...)
			{
				cout << "Unknown error! \n";
				goto A;
			}
		}
		string yearInput;
	B:
		cout << "Year: ";
		cin >> yearInput;
		{
			try
			{
				year = stoi(yearInput);
				if (year < 0)
				{
					cout << "Try again \n";
					goto B;
				}
			}
			catch (invalid_argument)
			{
				cout << "Only numbers are allowed! \n";
				goto B;
			}
			catch (out_of_range)
			{
				cout << "Try again \n";
				goto B;
			}
			catch (...)
			{
				cout << "Unknown error! \n";
				goto B;
			}
		}
	}

	string get_Date()
	{
		return std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
	}

	void table_out()
	{
		cout << setw(20) << get_Date() << "|";
	}

};