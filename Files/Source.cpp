#include<iostream>
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

void main()
{
	setlocale(LC_ALL, "");
	std::ofstream fout;     //1) ������� �����
	fout.open("File.txt", std::ios_base::app);  //2) ��������� �����
	fout << "Hello World!\n"; //3) ������� � �����
	fout.close();			//4) ��������� �����
	//������ ����� ���������, ��� ��� �� �����, ��� ������� ������.
	//������� ��� ��� ������ ����� open(), ������� �� ��� ����� ������� ����� close();
	system("notepad File.txt");
}
