#define CONSOLE_PAR
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace IntroductionC_
{
    internal class Program
    {
        static void Main(string[] args)
        {
#if CONSOLE_PAR
            Console.SetCursorPosition(10, 10);
            Console.Write("Hello!!!!");
#endif

        }
    }
}
