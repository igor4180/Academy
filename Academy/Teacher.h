#pragma once
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
		return os << "специальность: " << speciality << ", опыт преподавания: " << experience << " лет.";
		//os << speciality;
		//os << right;
		//os << experience << "y";
		return os;
	}

};
