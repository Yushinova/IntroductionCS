//#define TR
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Methods
{
    internal class Program
    {
        static void Main(string[] args)
        {
#if TR
            int a, b;
            Console.Write("Input 2 num: ");
            Init(out a, out b);
            Console.WriteLine($"{a}\t{b}");
            Exchange(ref a, ref b);
            Console.WriteLine($"{a}\t{b}");
#endif
            Console.WriteLine(Sum(3, 5, 13, 21));
        }
        static void Init(out int a, out int b)
        {
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());
        }
        static void Exchange(ref int a, ref int b)
        {
            int buffer = a;
            a = b;
            b = buffer;
        }
        static int Sum(params int[] values)
        {
            int sum = 0;
            foreach (int i in values) sum += i;
            return sum;
        }
    }
}
