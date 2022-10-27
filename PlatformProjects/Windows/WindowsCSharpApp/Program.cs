using System;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;

namespace DesktopProjectsApp
{
    class Program
    {
        //static extern int StartEngine();
        [DllImport(@"E:\Repos\SimpleShooterGame\x64\Debug\Project.dll", CallingConvention = CallingConvention.Cdecl)]
        static extern int StartEngine();

        static void Main(string[] args)
        {
            Console.WriteLine("Input:");

            foreach (string arg in args)
            {
                Console.WriteLine("arg: " + arg);
            }

            Console.WriteLine("Starting ...");

            try
            {
                StartEngine();
            }
            catch (Exception exception)
            {
                Console.WriteLine("Got Exception(C#): '" + exception + "'");
            }

            Console.WriteLine("End.");
        }
    }
}
