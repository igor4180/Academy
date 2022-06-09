﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define HUMAN_TAKE_PARAMETERS const std::string last_name, const std::string& first_name, unsigned int age
#define HUMAN_GIVE_PARAMETERS last_name, first_name, age


class Human
{
protected:
	std::string last_name;
	std::string first_name;
	unsigned int age;
public:
	const std::string& get_last_name()const
	{
		return last_name;
	}
	const std::string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
	{
		return age;
	}
	void set_last_name(const std::string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}

	//					Constructors:
	Human(HUMAN_TAKE_PARAMETERS)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//					Methods:
	virtual void print()const
	{
		cout << last_name << " " << first_name << " " << age << " years.\n";
	}
};

#define STUDENT_TAKE_PARAMETERS const std::string& speciality, const std::string& group, unsigned int year, double rating, double attendance
#define STUDENT_GIVE_PARAMETERS speciality, group, year, rating, attendance

class Student :public Human
{
	std::string speciality;
	std::string group;
	unsigned int year;
	double rating;
	double attendance;
public:
	const std::string& get_speciality()const
	{
		return this->speciality;
	}
	const std::string& get_group()const
	{
		return this->group;
	}
	unsigned int get_year()const
	{
		return year;
	}
	double get_rating()const
	{
		return rating;
	}
	double get_attendance()const
	{
		return attendance;
	}
	void set_speciality(const std::string& speciality)
	{
		this->speciality = speciality;
	}
	void set_group(const std::string& group)
	{
		this->group = group;
	}
	void set_year(unsigned int year)
	{
		this->year = year;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}
	void set_attendance(double attendance)
	{
		this->attendance = attendance;
	}

	//				Constructors:
	Student(HUMAN_TAKE_PARAMETERS, STUDENT_TAKE_PARAMETERS) :Human(HUMAN_GIVE_PARAMETERS)
	{
		set_speciality(speciality);
		set_group(group);
		set_year(year);
		set_rating(rating);
		set_attendance(attendance);
		cout << "SCostructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality + " " + "Группа: " + group << " " << "Курс: " << year << " " << "Рейтинг: " << rating << " " << "Посещаемость: " << attendance << endl;
	}
};

class Teacher :public Human
{
	string speciality;
	unsigned int experience;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_speciality(const string& speciality)
	{
		this->speciality = speciality;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//					Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		set_speciality(speciality);
		set_experience(experience);
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		cout << "TDestructor:\t" << this << endl;
	}
	//					Methods:
	/*void print()const
	{
		Human::print();
		cout << "Специальность: " << speciality + " " << "Опыт: " << experience << endl;
	}*/

	ostream& print(ostream& os)const
	{
		Human::print();
		return os << "специальность: " << speciality << ", опыт преподавания: "  << experience << " лет.";
		//os << speciality;
		//os << right;
		//os << experience << "y";
		return os;
	}
	
};

class Graduate :public Student
{
	std::string diplom;
public:
	const std::string& get_diplom()const
	{
		return diplom;
	}
	void set_diplom(const std::string& diplom)
	{
		this->diplom = diplom;
	}

	//			Constructors:
	Graduate
	(
		const std::string& last_name, const std::string& first_name, unsigned int age,
		const std::string& speciality, const std::string& group, unsigned int year, double rating, double attendance,
		const std::string& diplom
	) :Student
	(
		last_name, first_name, age,
		speciality, group, year, rating, attendance
	)
	{
		set_diplom(diplom);
		cout << "GConstructor:\t" << this << endl;
	}
	~Graduate()
	{
		cout << "GDestructor:\t" << this << endl;
	}
	//					Methods:
	void print()const
	{
		Student::print();
		cout << "Тема диплома: " << diplom << endl;
	}
};

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