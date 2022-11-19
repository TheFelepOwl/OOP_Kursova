
#include <iostream>
#include <fstream>

using namespace std;

const int Size = 10;

class Person
{
private:
	string name;
	string telefon;
	int date[3];

public:

	Person()
	{
		this->name = "";
		this->telefon = "";
		for (int i = 0; i < 3; i++)
		{
			this->date[i] = 0;
		}

	}

	Person(string name, string telefon, int d, int m, int y)
	{
		this->name = name;
		this->telefon = telefon;
		date[0] = d;
		date[1] = m;
		date[2] = y;

	}

	~Person()
	{
		this->name = "";
		this->telefon = "";
		for (int i = 0; i < 3; i++)
		{
			this->date[i] = 0;
		}

	}

	void Print_date()
	{
		cout << "Date: ";
		for (int i = 0; i < 3; i++)
		{
			cout << date[i] << ".";
		}

		cout << "\n";
	}


	void Print()
	{
		cout << "\nName: " << name << "\nTelefon" << telefon << endl;
		cout << "Date: ";
		for (int j = 0; j < 3; j++)
		{
			cout << date[j] << ".";
		}

		cout << "\n";

	}

	void Write(string path)
	{	
		
		ofstream fout;

		fout.open(path,ofstream::app);

		if (!fout.is_open())
		{
			cout << "Erorr open file!!!!" << endl;
		}

		else
		{
			fout << "\nName: " << name << "\nTelefon" << telefon;
			fout << "\nDate: ";
			for (int j = 0; j < 3; j++)
			{
				fout << date[j] << ".";
			}

			fout << "\n";
		}
	}


	friend Person Sort(Person* p);
	friend void Print_arr(Person* p, int months);
	friend void Write_arr(Person* p, int months);

};



Person Input(Person* p)
{
	p[0] = Person("Denys", "+380 500846146", 10, 4, 2004);

	p[1] = Person("Oleg", "+49 857433456", 2, 10, 2003);

	p[2] = Person("Yura", "+380 969133468", 13, 9, 2004);

	p[3] = Person("Yaroslav", "+380 974905396", 24, 7, 2004);

	p[4] = Person("Sergay", "+380 974103396", 7, 7, 2004);

	p[5] = Person("Ruslan", "+380 944567775", 12, 7, 2003);

	p[6] = Person("Max", "+380 92267345", 12, 10, 2003);

	p[7] = Person("Tocha", "+49 4455234223", 38, 10, 2003);

	p[8] = Person("Andrey", "+47 234324534", 1, 7, 2003);

	p[9] = Person("Bogdan", "+380 0506768674", 11, 7, 2004);

	cout << "List of DATE:\n";
	for (int i = 0; i < Size; i++)
	{
		p[i].Print_date();
	}



	return *p;
}

Person Sort(Person* p)
{
	Person temp;

	for (int i = 0; i < Size - 1; i++) {
		for (int j = 0; j < Size - i - 1; j++)
		{
			if (p[j].name[0] > p[j + 1].name[0])
			{
				// меняем элементы местами
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}


	return *p;
}

void Print_arr(Person* p, int months)
{
	bool counter = 0;

	for (int i = 0; i < Size; i++)
		if (months == 0 || months == p[i].date[1])
		{
			p[i].Print();
			counter = 1;
		}

	if (counter == 0)
		cout << "EMPTY!!!!!!!";

	cout << "\n\n";
	counter = 0;
}

void Write_arr(Person* p, int months)
{	
	string path;
	cout << "Input name of File(with out .txt): ";
	cin >> path;

	path += ".txt";

	for (int i = 0; i < Size; i++)
		if (months == p[i].date[1])
		{
			p[i].Write(path);	
		}
	
}

int main()
{

	int months = 0;
	char agree = 'n';

	Person p[Size];

	Input(p);

	cout << "Do u want watt FULL data??? y/n: ";
	cin >> agree;


	if (agree == 'y')
		Print_arr(p, months);

	agree = 'n';
	Sort(p);

	cout << "Input Months: ";
	cin >> months;

	Print_arr(p, months);

	cout << "Do u want write this information in FILE? y/n: ";
	cin >> agree;

	if (agree == 'y')
		Write_arr(p, months);


	return 0;


}


