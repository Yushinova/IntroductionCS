//#define CHAR
//#define BUTTONS
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
public class Shoot
{
    int size = 1;
    int X, Y;
    public Shoot(int x = 0, int y = 0)
    {
        X = x; Y = y;
    }
    public void Print(int X, int Y)
    {
        Console.SetCursorPosition(X, Y);
        Console.WriteLine("*");
    }
    public void Dell(int X, int Y)
    {
        Console.SetCursorPosition(X, Y);
        Console.Write(" ");
    }
}
public class Babay
{
    int size;
    int X, Y;
    Shoot obj;
    public Babay(int size, int x, int y)
    {
        this.size = size;
        X = x;
        Y = y;
        obj = new Shoot();
    }
    public void Print()
    {
        Console.BackgroundColor = ConsoleColor.Yellow;
        Console.ForegroundColor = ConsoleColor.Yellow;
        for (int i = 0; i < size; i++)
        {
            Console.SetCursorPosition(X, Y + i);
            for (global::System.Int32 j = 0; j < size; j++)
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    Console.BackgroundColor = ConsoleColor.Black;
                    Console.ForegroundColor = ConsoleColor.Black;
                }
                //else if (i== size/2 && j== size/2)
                //{
                //    Console.BackgroundColor = ConsoleColor.Red;
                //    Console.ForegroundColor = ConsoleColor.Red;
                //}
                else
                {
                    Console.BackgroundColor = ConsoleColor.Yellow;
                    Console.ForegroundColor = ConsoleColor.Yellow;
                }
                Console.Write("*");
            }
            Console.WriteLine();
        }
        Console.ResetColor();
    }
    public void Dell()
    {
        Console.BackgroundColor = ConsoleColor.Black;
        Console.ForegroundColor = ConsoleColor.Black;
        for (int i = 0; i < size; i++)
        {
            Console.SetCursorPosition(X, Y + i);
            for (global::System.Int32 j = 0; j < size; j++)
            {
                Console.Write("*");
            }
            Console.WriteLine();
        }
        Console.ResetColor();
    }
    public void Move()
    {
        ConsoleKey key;
        int tempY = Y, tempX = X;
        do
        {
            Print();
            key = Console.ReadKey(true).Key;
            Dell();
            switch (key)
            {
                case ConsoleKey.UpArrow:
                    if (Y > 1) Y--;
                    if (Y == 1) Console.Beep(37, 800);//работае
                    break;
                case ConsoleKey.DownArrow:
                    if (Y < 19) Y++;
                    if (Y == 19) Console.Beep(37, 800);
                    break;
                case ConsoleKey.LeftArrow:
                    if (X > 1) X--;
                    if (X == 1) Console.Beep(37, 800);
                    break;
                case ConsoleKey.RightArrow:
                    if (X < 39) X++;
                    if (X == 39) Console.Beep(37, 800);
                    break;
                case ConsoleKey.W://нужно вынести в отдльную функцию и сделать через потоки
                    tempY = Y;
                    tempX = X + 1;
                    while (tempY != 1)
                    {
                        tempY--;
                        obj.Print(tempX, tempY);
                        Print();
                        Thread.Sleep(30);
                        obj.Dell(tempX, tempY);
                    }
                    break;
                case ConsoleKey.S:
                    tempY = Y;
                    tempX = X + 1;
                    while (tempY != 20)
                    {
                        tempY++;
                        obj.Print(tempX, tempY);
                        Print();
                        Thread.Sleep(30);
                        obj.Dell(tempX, tempY);
                    }
                    break;
                case ConsoleKey.A:
                    tempY = Y+1;
                    tempX = X;
                    while (tempX != 1)
                    {
                        tempX--;
                        obj.Print(tempX, tempY);
                        Print();
                        Thread.Sleep(30);
                        obj.Dell(tempX, tempY);
                    }
                    break;
                case ConsoleKey.D:
                    tempY = Y + 1;
                    tempX = X;
                    while (tempX != 40)
                    {
                        tempX++;
                        obj.Print(tempX, tempY);
                        Print();
                        Thread.Sleep(30);
                        obj.Dell(tempX, tempY);
                    }
                    break;
                default: Console.WriteLine("Error"); break;
            }
        } while (key != ConsoleKey.Escape);
    }
    public void PrintFrame(int h, int w)
    {
       int x = 0, y = 0;
        for (int i = 0; i < h; i++)
        {
            Console.SetCursorPosition(x, y + i);
            for (int j = 0; j < w; j++)
            {
                if (i == 0 || j == 0 || i == h - 1 || j == w - 1)
                {
                    Console.ForegroundColor = ConsoleColor.Blue;
                   
                }
                else Console.ForegroundColor = ConsoleColor.Black;
                Console.Write("*");
            }
            Console.WriteLine();
        }
    }
}

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
            int num;
            string a, b, symbol;
            ConsoleKey key;
            do
            {
                Console.WriteLine("Ваше числовое выражение:");
                string res = Console.ReadLine();
                //while (res.Length!=0)
                //{
                res = res.Replace(" ", "");//можно удалить все пробелы это максимум что я смогла придумать
                num = res.IndexOfAny(new char[] { '*', '-', '/', '+', '%' });
                a = res.Substring(0, num);
                if (num != -1) res = res.Remove(0, num);
                num = res.IndexOfAny(new char[] { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' });
                symbol = res.Substring(0, num);
                if (num != -1) res = res.Remove(0, num);
                b = res;
                //Console.WriteLine(a);
                //Console.WriteLine(b);
                //Console.WriteLine(symbol);
                Console.Clear();
                switch (Convert.ToChar(symbol))
                {
                    case '*': Console.WriteLine(a + symbol + b + "=" + (Convert.ToDouble(a) * Convert.ToDouble(b))); break;
                    case '/':
                        if (Convert.ToDouble(b) != 0) Console.WriteLine(a + symbol + b + "=" + (Convert.ToDouble(a) / Convert.ToDouble(b)));
                        else Console.WriteLine("На 0 делить нельзя!");
                        break;
                    case '+': Console.WriteLine(a + symbol + b + "=" + (Convert.ToDouble(a) + Convert.ToDouble(b))); break;
                    case '%': Console.WriteLine(a + symbol + b + "=" + (Convert.ToDouble(a) % Convert.ToDouble(b))); break;
                    case '-': Console.WriteLine(a + symbol + b + "=" + (Convert.ToDouble(a) - Convert.ToDouble(b))); break;
                }
                //}
                Console.WriteLine("Для продолжения нажмите любую клавишу/выход Esc");
                Thread.Sleep(200);
                key = Console.ReadKey(true).Key;
                Console.Clear();
            } while (key != ConsoleKey.Escape);
            Console.Clear();

            //ДВИЖЕНИЕ КУРСОРА
            Babay obj = new Babay(3,1,1);
            obj.PrintFrame(23, 43);
            obj.Move();
        }
    }
}
