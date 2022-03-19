#pragma once
#include "Human.cpp"

class Worker :public Human
{
protected:
	int department = 0;
	double salary;
	int ID = 0;
	static int count;
public:
	Worker()
	{
		count++;
		department = 0;
		salary = 0;
		ID = count;
	}

	virtual int get_num() override
	{
		return 1;
	}

	virtual void set_info() override
	{
		cout << "ID #" << ID << endl;
		Human::set_info();
	P:
		cout << "Department: ";
		string departmentInput = "";
		cin >> departmentInput;
		{
			try
			{
				department = stoi(departmentInput);
			}
			/*catch (invalid_argument)
			{
				cout << "Only numbers are allowed! \n";
				goto P;
			}
			catch (out_of_range)
			{
				cout << "Try again \n";
				goto P;
			}*/
			catch (...)
			{
				cout << "Try again \n";
				goto P;
			}
			if (department < 0)
			{
				cout << "Try again \n";
				goto P;
			}
		}
	D:
		string salaryInput;
		cout << "Salary: ";
		cin >> salaryInput;
		{
			try
			{
				salary = stoi(salaryInput);
				if (salary < 0)
				{
					cout << "Try again \n";
					goto D;
				}
			}
			catch (invalid_argument)
			{
				cout << "Only numbers are allowed! \n";
				goto D;
			}
			catch (out_of_range)
			{
				cout << "Try again \n";
				goto D;
			}
			catch (...)
			{
				cout << "Unknown error! \n";
				goto D;
			}
		}
	}

	virtual void get_info() override
	{
		cout << "ID #" << ID << endl;
		Human::get_info();
		cout << "Department: " << department << endl;
		cout << "Salary: " << salary << endl;
	}

	int get_department() override
	{
		return department;
	}

	double get_salary() override
	{
		return salary;
	}

	void salary_sort(int* ID) override
	{
		this->ID = *ID + 1;
	}

	void table_out() override
	{
		human.table_out();
		cout << setw(6) << ID << "|";
		cout << setw(20) << profession << "|";
		cout << setw(20) << department << "|";
		cout << setw(20) << salary << "|";
		cout << endl;
	}

	virtual void get_info_for_db(std::ofstream* file_txt) override
	{
		*file_txt << ID << endl;
		*file_txt << human.get_surname() << endl;
		*file_txt << human.get_name() << endl;
		*file_txt << human.get_middlename() << endl;
		*file_txt << profession << endl;
		*file_txt << department << endl;
		*file_txt << salary << endl;
	}

	virtual void set_info_from_db(std::ifstream* file_txt) override
	{
		*file_txt >> ID;
		string surname;
		*file_txt >> surname;
		human.set_surname(surname);
		string name;
		*file_txt >> name;
		human.set_name(name);
		string middlename;
		*file_txt >> middlename;
		human.set_middlename(middlename);
		*file_txt >> profession;
		*file_txt >> department;
		*file_txt >> salary;
	}

};