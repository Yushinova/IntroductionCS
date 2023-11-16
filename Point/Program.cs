using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Point
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Point A = new Point();
            A.X = 2;
            A.Y = 3;
            A.Z = 4;
            A.Info();
            Point B = new Point(20, 30);
            Console.WriteLine("Koll point: " + Point.Count);
            A.Show();
            B.Show();
        }
    }
}
