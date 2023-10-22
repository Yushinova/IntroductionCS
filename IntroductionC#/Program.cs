#define CONSOLE_PARAMETERS
#define STRING_OPERATIONS

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Introduction
{
    class Program
    {
        static void Main(string[] args)
        {
#if CONSOLE_PARAMETERS
			Console.Title = "Introduction to .NET";
			Console.Write("\t\t\t\tHello .NET\n");
			Console.Write("Сам привет!\n");

			Console.SetCursorPosition(25, 15);
			Console.ForegroundColor = ConsoleColor.Green;
			Console.BackgroundColor = ConsoleColor.Blue;
			Console.WriteLine("SetConsoleCursorPosition");
			Console.ResetColor();
			Console.Beep(37, 1000);
			Console.CursorTop = 7;
			Console.CursorLeft = 25;
			Console.WriteLine("От и сказочке конец");
			Console.CursorSize = 100;
			Console.CursorVisible = true; 
#endif

#if STRING_OPERATIONS
			Console.Write("Введите Ваше имя: ");
			string first_name = Console.ReadLine();

			Console.Write("Введите Вашу фамилию: ");
			string last_name = Console.ReadLine();

			Console.Write("Введите Ваш возраст: ");
			int age = Convert.ToInt32(Console.ReadLine());

			Console.WriteLine("Ваше имя: " + first_name + ", Ваша фамилия: " + last_name + ", Ваш возраст: " + age + " лет.");  //Конкатенация строк
			Console.WriteLine(string.Format("Ваше имя: {0}, Ваша фамилия: {1}, Ваш возраст: {2} лет.", first_name, last_name, age));    //Форматирование строк
			Console.WriteLine($"Ваше имя: {first_name}, Ваша фамилия: {last_name}, Ваш возраст: {age} лет.");   //Интерполяция строк  
#endif

        }
    }
}