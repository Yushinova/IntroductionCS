//#define CHAR
//#define BUTTONS
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Shooter
{
    internal class Program
    {
        static void Main(string[] args)
        {
#if CHAR
            char key;
            do
            {
                key = Console.ReadKey(true).KeyChar;
                //Console.WriteLine((int)key);
                switch(key)
                {
                    case 'w': case 'W': Console.WriteLine("Вперед"); break;
                    case 's': case 'S': Console.WriteLine("Назад"); break;
                    case 'a': case 'A': Console.WriteLine("Влево"); break;
                    case 'd': case 'D': Console.WriteLine("Вправо"); break;
                    case ' ': Console.WriteLine("Прыжок"); break;
                    case (char)13: Console.WriteLine("Огонь"); break;
                    case (char)27: Console.WriteLine("Выход"); break;
                        default: Console.WriteLine("Error"); break;
                }
            }while (key!=27);
#endif
#if BUTTONS
            ConsoleKey key;
            do
            {
                key = Console.ReadKey(true).Key;
                //Console.Beep(37, 1000);//работае
                //Console.WriteLine((int)key);
                switch (key)
                {
                    case ConsoleKey.W: case ConsoleKey.UpArrow: Console.WriteLine("Вперед"); break;
                    case ConsoleKey.S: case ConsoleKey.DownArrow: Console.WriteLine("Назад"); break;
                    case ConsoleKey.A: case ConsoleKey.LeftArrow: Console.WriteLine("Влево"); break;
                    case ConsoleKey.D: case ConsoleKey.RightArrow: Console.WriteLine("Вправо"); break;
                    case ConsoleKey.Spacebar: Console.WriteLine("Прыжок"); break;
                    case ConsoleKey.Enter: Console.WriteLine("Огонь"); break;
                    case ConsoleKey.Escape: Console.WriteLine("Выход"); break;
                    default: Console.WriteLine("Error"); break;
                }
            } while (key != ConsoleKey.Escape);
#endif
            //КАЛЬКУЛЯТОР

            //ДВИЖЕНИЕ КУРСОРА
        }
    }
}
