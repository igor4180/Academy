#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<fstream>
using std::cin;
using std::cout;
using std::endl;

//#define WRITE_TO_FILE

void main()
{
	setlocale(LC_ALL, "");
#ifdef WRITE_TO_FILE
	const int SIZE = 256;
	char sz_filename[SIZE] = {}; //sz_ - string zero
	std::ofstream fout;     //1) Создаем поток
	cout << "Введите имя файла:";
	cin.getline(sz_filename, SIZE);
	if (strcmp(sz_filename + strlen(sz_filename) - 4, ".txt"))
		//strlen() - возвращает размер строки в символах.
		strcat(sz_filename, ".txt");
	fout.open(sz_filename, std::ios_base::app);  //2) Открываем поток
	char sz_contents[SIZE] = {};
	cout << "Введите содержимое файла:";
	cin.getline(sz_contents, SIZE);
	//fout << "Hello World!\n"; //3) Выводим в поток
	fout << sz_contents;
	fout.close();
	char sz_command[SIZE] = "notepad ";
	strcat(sz_command, sz_filename);
	//strcat (char* str1, char* str2) выполняет конкатенацию (слияние) строк
	//к содержимому первой строки добавляется содержимое второй
	system(sz_command);
	/*fout << "new Student Pinkman, Jessie, 23, Chemistry, WW_220, 1, 90, 95,\n";
	fout << "new Teacher White, Walter, 50, Chemistry, 25,\n";
	fout << "new Graduate Schreder, Hank, 40, Criminalistics, WW_220, 5, 95, 80, How to catch Heisenberg,\n";
	fout << "new Student Vercetti, Tomas, 30, Theft, Vice, 3, 90, 85,\n";
	fout << "new Teacher Diaz, Ricardo, 50, Weapons disribution, 20,\n";
	fout << "new Teacher Einstein, Albert, 143, Astronomy, 100,\n";
	fout.close();*/			//4) Закрываем поток
	//Потоки нужно закрывать, это так же важно, как удалять память.
	//Сколько раз был вызван метод open(), столько же раз нужно вызвать метод close();
	//system("notepad File.txt");
#endif WRITE_TO_FILE

	std::ifstream fin;
	fin.open("File.txt");
	if (fin.is_open())
	{
		//todo: read file
		const int n = 256;
		char buffer[n] = {};
		while (!fin.eof()) //eof - end of file
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		std::cerr << "Eror: file not found" << endl;
	}
	fin.close();
	system("notepad File.txt");

}
