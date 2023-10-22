using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace For
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //Используя вложенные циклы вывести в консоль фигуры, представленные ниже. Пока не сделаете первую, не переходите ко второй, и т.д. Фигуры предлагается вывести в порядке возрастания сложности.
            //0
            int size = 5;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    Console.Write("*");
                }
                Console.Write("\n");
            }
            Console.Write('\n');
            //1
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if(j<=i) Console.Write("*");
                }
                Console.Write("\n");
            }
            Console.Write('\n');
            //2
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (j >= i) Console.Write("*");
                }
                Console.Write("\n");
            }
            Console.Write('\n');
            //3
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (j < i) Console.Write(" ");
                    else Console.Write("*");
                }
                Console.Write("\n");
            }
            Console.Write('\n');
            //4
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (j < size-i-1) Console.Write(" ");
                    else Console.Write("*");
                }
                Console.Write("\n");
            }
            Console.Write('\n');
            //5
            size = 10;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (j == i+size/2||j == i-size/2) Console.Write("\\");
                    else if(i == size / 2 - j-1 || i == size / 2 + size - j-1) Console.Write("/");
                    else Console.Write(" ");
                }
                Console.Write("\n");
            }
            Console.Write('\n');
            //6
            size = 5;
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                   if(i%2==0)
                    {
                        if (j % 2 != 0) Console.Write("-");
                        else Console.Write("+");

                    }
                   else
                    {
                        if (j % 2 != 0) Console.Write("+");
                        else Console.Write("-");
                    }
                }
                Console.Write("\n");
            }
            Console.Write('\n');
        }
    }
}
