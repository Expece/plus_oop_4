#pragma once
#include "Worker.cpp"

class ForeignWorker :public Worker	//типо иностранный работник
{
protected:

	string country_from;	//из какой страны прибыл
	Date end_working;
public:
	ForeignWorker()
	{
		country_from = "";
		end_working;
	}

	int get_num() override
	{
		return 2;
	}

	void set_info() override
	{
		Worker::set_info();
		cout << "Country from: ";
		cin >> country_from;
		cout << "Date of end working: " << endl;
		end_working.set_Date();
	}

	void get_info() override
	{
		Worker::get_info();
		cout << "Country from: " << country_from << endl;
		cout << "Date of end working: " << end_working.get_Date() << endl;
	}

	void table_out() override
	{
		human.table_out();
		cout << setw(6) << ID << "|";
		cout << setw(20) << profession << "|";
		cout << setw(20) << department << "|";
		cout << setw(20) << salary << "|";
		cout << setw(20) << country_from << "|";
		end_working.table_out();
		cout << endl;
	}

	void get_info_for_db(std::ofstream* file_txt) override
	{
		*file_txt << ID << endl;
		*file_txt << human.get_surname() << endl;
		*file_txt << human.get_name() << endl;
		*file_txt << human.get_middlename() << endl;
		*file_txt << profession << endl;
		*file_txt << department << endl;
		*file_txt << salary << endl;
		*file_txt << country_from << endl;
		*file_txt << end_working.day << endl;
		*file_txt << end_working.month << endl;
		*file_txt << end_working.year << endl;
	}

	void set_info_from_db(std::ifstream* file_txt) override
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
		*file_txt >> country_from;
		*file_txt >> end_working.day;
		*file_txt >> end_working.month;
		*file_txt >> end_working.year;
	}
};