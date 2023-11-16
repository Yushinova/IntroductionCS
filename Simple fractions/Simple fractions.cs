using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Simple_fractions
{
    internal class Simple_fractions
    {
        public int numerator;
        public int denominator;
        public int integer_part;
        public Simple_fractions(int num = 0, int den = 0, int integ = 0)
        {
            numerator = num;
            denominator = den;
            integer_part = integ;
           // Console.WriteLine("FCtor\t" + this.GetHashCode());
        }
        public void Show()
        {
            if (integer_part != 0 && numerator != 0) Console.Write(integer_part + "(" + Math.Abs(numerator) + "/" + denominator + ")");
            if (numerator == 0) Console.Write(integer_part);
            if (integer_part == 0) Console.Write(numerator + "/" + denominator);
        }
        public int Delitel(int a, int b)//нашла в с++
        {
            a = Math.Abs(a);
            b=Math.Abs(b);
            if (b == 0) return a;
            else return Delitel(b, a % b);
        }
        public void Reduction()//из неправильной дроби правильную и сокращаем
        {
            int temp_num = 0, temp_int_part = 0, x;
            if (numerator >= denominator)
            {
                while (numerator % denominator != 0)
                {
                    numerator--;
                    temp_num++;
                }
                temp_int_part = numerator / denominator;
                numerator = temp_num;
                if (numerator == 0) denominator = 0;
                integer_part += temp_int_part;
            }
            x=Delitel(numerator, denominator);
            numerator /= x;
            denominator/=x;
        }
        public void Incorrect_fraction()//для деления нужно привести дробь к неправильной
        {
            if(integer_part!=0)
            {
                numerator = integer_part*denominator+numerator;
            }
        }
        public Simple_fractions Sum(Simple_fractions A, Simple_fractions B)
        {
            Simple_fractions D = new Simple_fractions();
                D.numerator = A.numerator * B.denominator + B.numerator * A.denominator;
                D.denominator = A.denominator * B.denominator;
                D.integer_part = A.integer_part + B.integer_part;
                D.Reduction();
            return D;
        }
        public Simple_fractions Diff(Simple_fractions A, Simple_fractions B)
        {
            Simple_fractions D = new Simple_fractions();
                D.numerator = A.numerator * B.denominator - B.numerator * A.denominator;
                D.denominator = A.denominator * B.denominator;
                D.integer_part = A.integer_part - B.integer_part;
                D.Reduction();
            return D;
        }
        public Simple_fractions Multi(Simple_fractions A, Simple_fractions B)
        {
            Simple_fractions D = new Simple_fractions();
            D.numerator = A.numerator * B.numerator;
            D.denominator = A.denominator * B.denominator;
            D.integer_part = A.integer_part * B.integer_part;
            D.Reduction();
            return D;
        }
        public Simple_fractions Div(Simple_fractions A, Simple_fractions B)
        {
            Simple_fractions D = new Simple_fractions();
            A.Incorrect_fraction();
            B.Incorrect_fraction();
            D.numerator = A.numerator * B.denominator;
            D.denominator = A.denominator * B.numerator;
            D.Reduction();
            return D;
        }
    }
}