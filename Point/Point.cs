using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Point
{
    internal class Point
    {
        const double MAX_X = 95;
        const double MAX_Y = 22;
        double x;
        double y;
        static int count;
        static ConsoleColor color;
        public static int Count { get { return count; } }
        public double X
        {
            get { return x; }
            set
            {
                if (value > MAX_X) value = MAX_X;
                if (value < 0) value = 0;
                x = value;
            }
        }
        public double Z//автосвойства для переменной Z если не нужна фильтрация
        {
            get;
            set;
        }
        public double Y
        {
            get { return y; }
            set
            {
                if (value > MAX_Y) value = MAX_Y;
                if (value < 0) value = 0;
                y = value;
            }
        }
        public Point(double x = 0, double y = 0)
        {
            X = x;
            Y = y;
            count++;
            Console.WriteLine("Ctor: "+ this.GetHashCode());
        }
        static Point()
        {
            color = ConsoleColor.Blue;
        }
        //methods
        public void Info()
        {
            Console.WriteLine($"X={x},\tY={y}");
        }
        public void Show()
        {
            Console.BackgroundColor = color;
            Console.ForegroundColor = color;
            int x = Console.CursorLeft;
            int y = Console.CursorTop;
            Console.SetCursorPosition((int)X, (int)Y);
            Console.WriteLine(" ");
            Console.SetCursorPosition(x, y);
            Console.ResetColor();
        }
    }
}
