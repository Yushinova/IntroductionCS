//#define MASS1
//#define MASS2
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace String
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Random rand = new Random(0);
#if MASS1
            Console.WriteLine("size:");
            int sise = Convert.ToInt32(Console.ReadLine());
            int[] arr = new int[sise];
            
            for (int i = 0; i < arr.Length; i++)
            {
                arr[i] = rand.Next(100);
            }
            //for (int i = 0; i < arr.Length; i++)
            //{
            //    Console.WriteLine(arr[i] + "\t");
            //}
            foreach (int i in arr)
            {
                Console.Write(i + "\t");
            }
            Console.WriteLine();
            int summ=0;
            foreach (int i in arr)
            {
                summ += i;
            }
            Console.WriteLine("summ:" + summ);
            Console.WriteLine("Average:" + (double)summ/arr.Length);
            //int min, max;
            //min = max = arr[0];
            //foreach (int i in arr)
            //{
            //    if (i < min) min = i;
            //    if (i > max) max = i;
            //}
            //Console.WriteLine("min:" + min);
            //Console.WriteLine("max:" + max);
            Console.WriteLine("min:" + arr.Min());
            Console.WriteLine("Max:" + arr.Max());
            Console.WriteLine("Sum:"+arr.Sum());
            Console.WriteLine("Average:" + arr.Average());
            Array.Sort(arr);
            foreach (var i in arr) Console.WriteLine(i + "\t");
#endif
#if MASS2
            Console.WriteLine("koll row:");
            int rows = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("koll col:");
            int cols = Convert.ToInt32(Console.ReadLine());
            int[,] arr = new int[rows, cols];
            Console.WriteLine("kol izm:" + arr.Rank);
            Console.WriteLine("kol row:" + arr.GetLength(0));
            Console.WriteLine("kol col:" + arr.GetLength(1));
            Console.WriteLine("kol elementov:" + arr.Length);
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (global::System.Int32 j = 0; j < arr.GetLength(1); j++)
                {
                    arr[i, j] = rand.Next(100);
                }
            }
            for (int i = 0; i < arr.GetLength(0); i++)
            {
                for (global::System.Int32 j = 0; j < arr.GetLength(1); j++)
                {
                    Console.Write(arr[i, j] + "\t");
                }
                Console.WriteLine();
            }
            
            Console.WriteLine("Summ all:" + arr.Cast<int>().Sum());
            Console.WriteLine("Average: " + arr.Cast<int>().Average());
            Console.WriteLine("Min: " + arr.Cast<int>().Min());
            Console.WriteLine("Max: " + arr.Cast<int>().Max());
#endif
            //зубчатые массивы
            int[][] arr =
            {
                new int[]{3,5,8,13,21},
                new int[]{34,55,89},
                new int[]{144,233,377,610}
            };
            for (int i = 0; i < arr.Length; i++)
            {
                for (int j = 0; j < arr[i].Length; j++)
                {
                    Console.Write(arr[i][j] + "\t");
                }
                Console.WriteLine();
            }
        }
    }
}
