using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Cryptography;
using System.Security.Cryptography.X509Certificates;
using System.Text;
using System.Threading.Tasks;
public class MySquare//ячейка
{
    private int size;
    public MySquare(int var)//конструктор почему то не могу сделать приватным
    {
        if (var < 1) size = 1;
        if (var > 5) size = 5;
        else size = var;
    }
    public void Print(int X, int Y, ConsoleColor color)
    {
        for (int i = 0; i < size; i++)
        {
            Console.ForegroundColor = color;
            Console.BackgroundColor = color;
            Console.SetCursorPosition(X, Y+i);
            for (global::System.Int32 j = 0; j < size; j++)
            {
                Console.Write("* ");
            }
            Console.WriteLine();
        }
        Console.ResetColor();
    }
    public int getSize()
    {
        return size;
    }
}
public class MyChessBoard//доска
{
    private int size;
    MySquare obj;
    public MyChessBoard(int var, MySquare obj)
    {
        if (var < 3) size = 3;
        if (var > 10) size = 10;
        else size = var;
        this.obj = obj;
    }
    public void Print(int X=0, int Y=0)
    {
        int temp = X;//если здают координаты отличные от 0
        for (int i = 0; i < size; i++)
        {
            for (global::System.Int32 j = 0; j < size; j++)
            {
                if (i % 2 == 0)
                {
                    if(j%2==0) obj.Print(X, Y, ConsoleColor.White);
                    else obj.Print(X, Y, ConsoleColor.Gray);
                } 
                else
                {
                    if (j % 2 == 0) obj.Print(X, Y, ConsoleColor.Gray);
                    else obj.Print(X, Y, ConsoleColor.White);
                }
                X += obj.getSize()*2;
            }
            X = temp;//возвращаем значение которое передали
            Y += obj.getSize();
        }
    }
}
namespace ChessBoard
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.Write("Ведите размер ячейки (от 1 до 5): ");
            int size_square = Convert.ToInt32(Console.ReadLine());
            Console.Write("Введите размер доски: (от 3 до 10)");
            int size_board=Convert.ToInt32(Console.ReadLine());
            MySquare obj = new MySquare(size_square);
            MyChessBoard obj2 = new MyChessBoard(size_board, obj);
            obj2.Print(0,3);
        }
    }
}
