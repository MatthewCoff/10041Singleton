#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;
/// <summary>
/// Паттерн проектирования Singleton
/// </summary>
class FileWorker
{


private:
	FileWorker() {}

	FileWorker(const FileWorker&) = delete;
	FileWorker& operator=(const FileWorker&) = delete;

	~FileWorker() {}


	static FileWorker* instance;
public:


	void SozdFile(const string& crfile)
	{
		ofstream file(crfile);
		if (file)
		{
			cout << "\tСоздание файла : " << endl;
			cout << crfile << endl;
			file.close();

		}
		else
		{
			cout << "Ошибка создания " << endl;

		}
	}

	void EditFile(const string& objfile, const string& objfilenov)
	{
		if (rename(objfile.c_str(), objfilenov.c_str()) == 0)
		{
			cout << "\tМеняем название " << objfile << " на " << objfilenov << endl;
		}
		else
		{
			cout << "Ошибка " << endl;
		}
	}

	void deleteFile(const string& crfile)
	{
		if (remove(crfile.c_str()) == 0)
		{
			cout << "\tУдаление: " << crfile << endl;
		}
		else
		{
			cout << "Ошибка" << endl;
		}
	}

	bool fileExists(const string& crfile)
	{
		ifstream file(crfile);
		if (file)
		{
			cout << "\tвЫход" << endl;
			file.close();
			return true;
		}
		else
		{
			cout << "Ошибка" << endl;
			return false;
		}
	}
	static FileWorker& getInstance()
	{
		static FileWorker instance;
		return instance;
	}

};

int main()
{
	setlocale(LC_ALL, "Russian");

	FileWorker& fileWorker = FileWorker::getInstance();


	fileWorker.SozdFile("\tТекст.txt"); cout  << endl;
	fileWorker.EditFile("\tТексте.txt", "\tдругойтеексте.txt"); cout << endl;
	fileWorker.deleteFile("\tдругойтеексте.txt"); cout << endl;
	cout << boolalpha << fileWorker.fileExists("\tдругойтеексте.txt");



	return 0;
}