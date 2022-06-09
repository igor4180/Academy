#include<iostream>
#include"Human.h"
#include"Student.h"
#include"Teacher.h"
#include"Graduate.h"

using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define INHERITANCE_CHECK

void main()
{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE_CHECK


	Human human("Montana", "Antonio", 25);
	human.print();

	Student pinkman("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 85);
	pinkman.print();

	Teacher t("White", "Walter", 50, "Chemistry", 25);
	t.print(cout);

#endif // INHERITANCE_CHECK

	Human* group[] =
	{
		new Student("Pinkman", "Jessie", 23, "Chemistry", "WW_220", 1, 90, 95),
		new Teacher("White", "Walter", 50, "Chemistry", 25),
		new Graduate("Schreder", "Hank", 40, "Criminalistics", "WW_220", 5, 95, 80, "How to catch Heisenberg"),
		new Student("Vercetti", "Tomas", 30, "Theft", "Vice", 3, 90, 85),
		new Teacher("Diaz", "Ricardo", 50, "Weapons disribution", 20),
		new Teacher("Einstein", "Albert", 143, "Astronomy", 100),
	};
	cout << "-------------------------------------------------\n";

	for (int i = 0; i < sizeof(group) / sizeof(group[0]); i++)
	{
		group[i]->print();
		cout << "-------------------------------------------------\n";
	}
}
