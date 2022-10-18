using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
/**
 * @file MyData.cs
 * @author Fahrettin SOLAK
 * @date 18 October 2022
 *
 * @brief <b> HW-1 Functions </b>
 *
 * HW-1 Algo Lib Functions Header
 *
 * @see http://bilgisayar.mmf.erdogan.edu.tr/en/
 *
 */

namespace mylibcs
{
    /// <summary>
    /// Data structure stored on XOR Linked List and Skip List
    /// </summary>
    public class MyData
    {
        public int key;

        public static bool hasPrecedence(char op1,
                                 char op2)
        {
            if (op2 == '(' || op2 == ')')
            {
                return false;
            }
            if ((op1 == '*' || op1 == '/') &&
                   (op2 == '+' || op2 == '-'))
            {
                return false;
            }
            else
            {
                return true;
            }
        }


        public static int applyOp(char op, int b, int a)
        {
            switch (op)
            {
                case '+':
                    return a + b;
                case '-':
                    return a - b;
                case '*':
                    return a * b;
                case '/':
                    if (b == 0)
                    {
                        throw new
                        System.NotSupportedException(
                               "Cannot divide by zero");
                    }
                    return a / b;
            }
            return 0;
        }
        /// <summary>
        /// A utility function to return
        /// precedence of a given operator
        /// Higher returned value means higher precedence
        /// </summary>
        /// <param name="ch"></param>
        /// <returns></returns>
        internal static int Prec(char ch) 
        {
            switch (ch)
            {
                case '+':
                case '-':
                    return 1;

                case '*':
                case '/':
                    return 2;

                case '^':
                    return 3;
            }
            return -1;
        }
        /// <summary>
        /// to get the number of desired operation
        /// </summary>
        /// <param name="exp"></param>
        /// <param name="_c"></param>
        /// <returns></returns>
        public static int getcharactercount(string exp, char _c)
        {
            int count = 0;
            foreach (char c in exp)
            {
                if (c == _c)
                    count++;
            }
            return count;
        }

        public MyData(int key)
        {
            this.key = key;
        }
    }
}