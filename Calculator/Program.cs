//#define CALCULATOR_SIMPLE
#define CALCULATOR_HALABUDA
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;

namespace Calculator
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //КАЛЬКУЛЯТОР
            int num = 0, k=0;
            double var1;
            string a, b, symbol;
            ConsoleKey key;

#if CALCULATOR_SIMPLE
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
                //}
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
                Console.WriteLine("Для продолжения нажмите любую клавишу/выход Esc");
                Thread.Sleep(200);
                key = Console.ReadKey(true).Key;
                Console.Clear();
            } while (key != ConsoleKey.Escape);
#endif
#if CALCULATOR_HALABUDA
            //СЧИТАЕТ ДАЖЕ САМУЮ ДИКУЮ ДИЧЬ 2,3+5*-2-4/2*-3=-1,7
            do
            {
                Console.WriteLine("Ваше числовое выражение:");
                string res = Console.ReadLine();
                res = res.Replace("--", "-m");//заменяю все отрицательные числа на m
                res = res.Replace("*-", "*m");
                res = res.Replace("/-", "/m");
                res = res.Replace("+-", "+m");
                if (res[0] == '-')//если первое отрицательное тоже заменяю знак
                {
                    res = res.Substring(1);
                    res = res.Insert(0, "m");
                } 
                //Console.WriteLine("RES:" + res);
                string[] values = res.Split('+', '-', '/', '*');//массив чисел, но все отрицательные с буквой впереди
                string[] operations = res.Split('0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ',', 'm', ' ');//массив знаков
                string oper = String.Join("", operations);//сделали одну строку из знаков математических операций
                oper = oper.Replace(" ", "");//удалили все пробелы
                Console.WriteLine(oper);
                foreach (string i in values) Console.Write(i + "\t");
                Console.WriteLine();
                double[] numbers = new double[values.Length];
                for (int i = 0; i < values.Length; i++)//перевожу числа с m в массив double с нужным знаком//переделать в лист сразу нужно
                {
                    if (values[i].StartsWith("m"))
                    {
                        values[i] = values[i].Replace("m", "");
                        numbers[k] = Convert.ToDouble(values[i]) * (-1);
                    }
                    else numbers[k] = Convert.ToDouble(values[i]);
                    k++;
                }
                List<object> list = numbers.Cast<object>().ToList();//перевожу массив чисел в лист, думала так будет короче, но нет))
                //foreach (double i in list) Console.Write(i + "\t");
                do
                {
                    num = oper.IndexOfAny(new char[] { '*', '/' });//ищем первое вхождение знаков высшего приоритета
                    if(num!=-1)//без этой проверки вылетаем
                    {
                        if (oper[num] == '*')
                        {
                            var1 = Convert.ToDouble(list[num]) * Convert.ToDouble(list[num + 1]);//считаем соседние числа из листа
                            list.RemoveAt(num);//удаляем посчитанные
                            list.RemoveAt(num);
                            list.Insert(num, var1);//вставляем вместо них результать математической операции
                            oper = oper.Remove(num, 1);//удаляем знак из строки
                        }
                        else if (oper[num] == '/')
                        {
                            var1 = Convert.ToDouble(list[num]) / Convert.ToDouble(list[num + 1]);
                            list.RemoveAt(num);
                            list.RemoveAt(num);
                            list.Insert(num, var1);
                            oper = oper.Remove(num, 1);
                        }
                    }
                    foreach (double i in list) Console.Write(i + "\t");
                    Console.WriteLine();
                } while (num != -1);//пока находим один из знаков цикл продолжается
                do
                {
                    num = oper.IndexOfAny(new char[] { '+', '-' });
                    if(num!=-1)
                    {
                        if (oper[num] == '+')
                        {
                            var1 = Convert.ToDouble(list[num]) + Convert.ToDouble(list[num + 1]);
                            list.RemoveAt(num);
                            list.RemoveAt(num);
                            list.Insert(num, var1);
                            oper = oper.Remove(num, 1);
                        }
                        else if (oper[num] == '-')
                        {
                            var1 = Convert.ToDouble(list[num]) - Convert.ToDouble(list[num + 1]);
                            list.RemoveAt(num);
                            list.RemoveAt(num);
                            list.Insert(num, var1);
                            oper = oper.Remove(num, 1);
                        }
                    }
                    foreach (double i in list) Console.Write(i + "\t");
                    Console.WriteLine();
                } while (list.Count()!= 1);//пока не остался последний элемент в листе это и есть ответ
                Console.WriteLine(list[0]);
                Console.WriteLine("Для продолжения нажмите любую клавишу/выход Esc");
                Thread.Sleep(200);
                key = Console.ReadKey(true).Key;
                Console.Clear();
            } while (key != ConsoleKey.Escape);
#endif
        }
    }
}
