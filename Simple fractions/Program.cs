using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Simple_fractions
{
    internal class Program
    {
        static void Main(string[] args)
        {
            ConsoleKey key;
            do
            {
                Console.SetCursorPosition(5, 5);
                Console.WriteLine("Int:");
                Console.SetCursorPosition(15, 5);
                Console.WriteLine("----");
                Console.SetCursorPosition(22, 5);
                Console.BackgroundColor = ConsoleColor.DarkGray;
                Console.WriteLine("+");
                Console.ResetColor();
                Console.SetCursorPosition(11, 4);
                Console.WriteLine("Num:");
                Console.SetCursorPosition(11, 6);
                Console.WriteLine("Den:");
                Console.SetCursorPosition(26, 5);
                Console.WriteLine("Int:");
                Console.SetCursorPosition(36, 5);
                Console.WriteLine("----");
                Console.SetCursorPosition(32, 4);
                Console.WriteLine("Num:");
                Console.SetCursorPosition(32, 6);
                Console.WriteLine("Den:");
                Console.SetCursorPosition(9, 5);
                string integerA = Console.ReadLine();
                if (integerA.Length == 0) integerA = "0";
                Console.SetCursorPosition(16, 4);
                string numeratorA = Console.ReadLine();
                Console.SetCursorPosition(16, 6);
                string denomeratorA = Console.ReadLine();
                Console.SetCursorPosition(30, 5);
                string integerB = Console.ReadLine();
                if (integerB.Length == 0) integerB = "0";
                Console.SetCursorPosition(37, 4);
                string numeratorB = Console.ReadLine();
                Console.SetCursorPosition(37, 6);
                string denomeratorB = Console.ReadLine();
                Console.SetCursorPosition(22, 5);
                Console.BackgroundColor = ConsoleColor.DarkGray;
                Console.WriteLine(" ");
                Console.SetCursorPosition(22, 5);
                string sign = Console.ReadLine();
                Console.ResetColor();
                Console.WriteLine();
                Console.WriteLine();
                Simple_fractions A = new Simple_fractions(Convert.ToInt32(numeratorA), Convert.ToInt32(denomeratorA), Convert.ToInt32(integerA));
                Simple_fractions B = new Simple_fractions(Convert.ToInt32(numeratorB), Convert.ToInt32(denomeratorB), Convert.ToInt32(integerB));
                Simple_fractions D = new Simple_fractions();
                switch (Convert.ToChar(sign))
                {
                    case '*':
                        Console.SetCursorPosition(5, 10);
                        A.Show();
                        Console.Write(sign);
                        B.Show();
                        Console.Write("=");
                        D = D.Multi(A, B);
                        D.Show();
                        Console.WriteLine();
                        Console.WriteLine();
                        break;
                    case '/':
                        Console.SetCursorPosition(5, 10);
                        A.Show();
                        Console.Write(sign);
                        B.Show();
                        Console.Write("=");
                        D = D.Div(A, B);
                        D.Show();
                        Console.WriteLine();
                        Console.WriteLine();
                        break;
                    case '+':
                        Console.SetCursorPosition(5, 10);
                        A.Show();
                        Console.Write(sign);
                        B.Show();
                        Console.Write("=");
                        D = D.Sum(A, B);
                        D.Show();
                        Console.WriteLine();
                        Console.WriteLine();
                        break;
                    case '-':
                        Console.SetCursorPosition(5, 10);
                        A.Show();
                        Console.Write(sign);
                        B.Show();
                        Console.Write("=");
                        D = D.Diff(A, B);
                        D.Show();
                        Console.WriteLine();
                        Console.WriteLine();
                        break;
                }
                Console.WriteLine("Для продолжения нажмите любую клавишу/выход Esc");
                Thread.Sleep(200);
                key = Console.ReadKey(true).Key;
                Console.Clear();
            } while (key != ConsoleKey.Escape);
        }
    }
}
