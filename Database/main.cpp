#include <iostream>
#include <Windows.h>
#include <map>
#include <string>
#include <vector>
#include <time.h>
#include<fstream>
#include <algorithm> 
#include<conio.h>
using namespace std;
enum Direction { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, esc = 27 };
class Receipt
{
	string receipt;//номер квитанции вводим с клавиатуры
	string nameFine;//название штрафа
	double Sum;
public:
	Receipt()
	{
		receipt = "var";
		nameFine = "name";
		Sum = 0;
#ifdef DEBUG
		cout << "RCtor: " << this << endl;
#endif // DEBUG
	}
	Receipt(string var, string name, double sum)
	{
		receipt = var;
		nameFine = name;
		Sum = sum;
#ifdef DEBUG
		cout << "RCtor: " << this << endl;
#endif // DEBUG
	}
	void RandSet(string number_car, vector<string>Fine, vector<double>sum)//передаем номер машины который ввели и 2 вектра с готовыми штрафами и суммами
	{
		time_t rtime;//текущее время в милисекундах
		time(&rtime);//получаем текущее время
		tm mytime;//структура для хранения данных про текущую дату
		localtime_s(&mytime, &rtime);//расчленяем полученную дату на поля структуры
		receipt = number_car + to_string(mytime.tm_mday) + to_string(mytime.tm_mon) + to_string(mytime.tm_year + 1900) + to_string(100 + rand() % 900);
		int var = rand() % Fine.size();
		nameFine = Fine[var];
		Sum = sum[var];
	}
	void PrintReceipt()
	{
		cout << "N: " << receipt << "\t" << ": " << nameFine << "\t" << "sum: " << Sum << endl;
	}
	string getReceipt()const
	{
		return receipt;
	}
	string getnameFine()const
	{
		return nameFine;
	}
	double getSum()
	{
		return Sum;
	}
};
class Car
{
	string Number;
	vector<Receipt>allReceipt;
public:

	void RandNumber()
	{
		string temp;
		temp.push_back('A' + rand() % ('Z' - 'A'));
		temp += to_string(100 + rand() % 900);
		temp.push_back('A' + rand() % ('Z' - 'A'));
		temp.push_back('A' + rand() % ('Z' - 'A'));
		Number = temp;
	}
	void AddReceipt(Receipt var)
	{
		allReceipt.push_back(var);

	}
	void PrintReceipt()
	{
		cout << "Car: " << Number << endl;
		for (Receipt var : allReceipt)
		{
			var.PrintReceipt();
		}
	}
	Car()
	{
		Number = "non";
	}
	Car(string number)
	{
		Number = number;
#ifdef DEBUG
		cout << "CCtor: " << this << endl;
#endif // DEBUG
	}
	string getNumber()const
	{
		return Number;
	}
	vector<Receipt> getVector()
	{
		return allReceipt;
	}
	~Car()
	{
#ifdef DEBUG
		cout << "CDisrt: " << this << endl;
#endif // DEBUG
	}
};
class Database
{
	int Size;
	map<string, vector<Receipt>>database;
public:
	Database(int size)
	{
		Size = size;
	}
	void setDatabase(Car car)
	{
		//pear 
		database.insert(pair<string, vector<Receipt>>(car.getNumber(), car.getVector()));
	}
	void printAllnumbers()
	{
		for (auto it = database.begin(); it != database.end(); ++it)
		{
			cout << it->first << "\t";
		}
		cout << endl;
	}
	void findCar(string var)
	{
		transform(var.begin(), var.end(), var.begin(), ::toupper);//ПЕРЕВОД В ВЕРХНИЙ РЕГИСТР БУКВ
		auto it = database.find(var);
		if (it!=database.end())//метод возвращает итератор на элемент, если он не найден, возвращает итератор на конец карты
		{			
			cout << it->first << endl;
			for (auto var : it->second)
			{
				var.PrintReceipt();
			}
		}
		else throw exception ("Car number not found!");
	}
	void printDatabase()
	{
		for (auto it = database.begin(); it != database.end(); ++it)
		{
			cout << it->first << endl;
			for (auto var : it->second)
			{
				var.PrintReceipt();
			}
			cout << endl;
		}
	}
	map < string, vector<Receipt>> getBase()
	{
		return database;
	}
};
bool isEmpty(ifstream& FILE)//проверка пуст ли файл
{
	int size;
	FILE.seekg(0, ios::end);//смещаемся от начала файла до конца
	size = FILE.tellg();//узнаём на какое количество байт произошло смещение
	return size == 0;
}
void main()
{
	setlocale(LC_ALL, "");
	srand(time(NULL));
	vector<string>fine = { "Превышение_скорости","Обгон","Пересечение_сплошной","Ремень_безопасности","Нет_регистрации","Движение_по_встречному_направлению" };
	vector<double>sum = { 2000,3000,2500,500,1000,5000 };
	int size = 10, size_fine, size_vector;
	string numberCar;
	string numreceipt;//номер квитанции
	string nameFine;//название штрафа
	double Sum;
	Database base(size);
	ifstream readF("base.txt");
	if (readF.is_open())
	{
		while (!readF.eof())
		{
			readF >> numberCar >> size_vector;
			Car car(numberCar);
			int temp = 0;
			while (temp != size_vector)
			{
				readF >> numreceipt >> nameFine >> Sum;
				Receipt receipt(numreceipt, nameFine, Sum);
				car.AddReceipt(receipt);
				temp++;
			}
			base.setDatabase(car);
		}
		base.printDatabase();
	}
	else
	{
		for (size_t i = 0; i < size; i++)//заполнение базы рандом
		{
			Car car;
			car.RandNumber();
			Receipt receipt;
			size_fine = 1 + rand() % 5;
			for (size_t i = 0; i < size_fine; i++)
			{
				receipt.RandSet(car.getNumber(), fine, sum);
				car.AddReceipt(receipt);
			}
			base.setDatabase(car);
		}
		ofstream writeF("base.txt", ios::app);
		for (const auto& entry : base.getBase())
		{
			if (!isEmpty(readF))
			{
				writeF << "\n" << entry.first << " " << entry.second.size();
				for (auto var : entry.second)
				{
					writeF << "\n" << var.getReceipt() << " " << var.getnameFine() << " " << var.getSum();
				}
			}
			else
			{
				writeF << entry.first;
				for (auto var : entry.second)
				{
					writeF << " " << var.getReceipt() << " " << var.getnameFine() << " " << var.getSum();
				}
			}
		}
		writeF.close();
		base.printDatabase();
	}
	//поиск машины по номеру
	int key;
	cout << "Для продолжения нажмите любую клавишу/выход: Esc" << endl;
	key = _getch();
	if (key != esc)
	{
		system("cls");
		base.printAllnumbers();
		do
		{
			cout << "Number car: ";
			getline(cin, numberCar);
			try
			{
				base.findCar(numberCar);
			}
			catch (const exception& ex)
			{
				cout << ex.what() << endl;
			}
			key = _getch();
		} while (key != esc);
	}
}