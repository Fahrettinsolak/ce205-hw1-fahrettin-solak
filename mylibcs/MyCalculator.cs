using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;


/**
 * @file MyCalculator.cs
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
    public class MyCalculator
    {

        /// <summary>
        /// Calculate the results for statement such as “(1+5)*(5%(10*10))
        /// </summary>
        /// 
        /// <param name="expression"></param>
        /// 
        /// <returns>int</returns>
        public static int evaluateInfix(string expression)
        {
            char[] tokens = expression.ToCharArray();

            Stack<int> values = new Stack<int>();

            Stack<char> ops = new Stack<char>();

            for (int i = 0; i < tokens.Length; i++)
            {

                if (tokens[i] == ' ')
                {
                    continue;
                }

                if (tokens[i] >= '0' && tokens[i] <= '9')
                {
                    StringBuilder sbuf = new StringBuilder();

                    while (i < tokens.Length &&
                            tokens[i] >= '0' &&
                                tokens[i] <= '9')
                    {
                        sbuf.Append(tokens[i++]);
                    }
                    values.Push(int.Parse(sbuf.ToString()));
                    i--;
                }

                else if (tokens[i] == '(')
                {
                    ops.Push(tokens[i]);
                }

                else if (tokens[i] == ')')
                {
                    while (ops.Peek() != '(')
                    {
                        values.Push(MyData.applyOp(ops.Pop(),
                                         values.Pop(),
                                        values.Pop()));
                    }
                    ops.Pop();
                }

                else if (tokens[i] == '+' ||
                         tokens[i] == '-' ||
                         tokens[i] == '*' ||
                         tokens[i] == '/')
                {

                    while (ops.Count > 0 &&
                             MyData.hasPrecedence(tokens[i],
                                         ops.Peek()))
                    {
                        values.Push(MyData.applyOp(ops.Pop(),
                                         values.Pop(),
                                       values.Pop()));
                    }

                    ops.Push(tokens[i]);
                }
            }

            while (ops.Count > 0)
            {
                values.Push(MyData.applyOp(ops.Pop(),
                                 values.Pop(),
                                values.Pop()));
            }

            return values.Pop();

        }


        /// <summary>
        /// This function will determine missing parenthesis in the statement
        /// (Evaluate Infix will use this function inside
        /// </summary>
        /// 
        /// <param name="expression"></param>
        /// 
        /// <returns></returns>
        public static bool validateInfix(string expression)
        {
            int previous = 0;
            int previous1 = 0;
            string expEvaluated = string.Empty;
            int operatorOperand = 1;

            for (int i = 0; i < expression.Length; i++)
            {
                char c = expression[i];
                if (c == ')')  
                {
                }
                else
                if (c == '(') 
                {
                    int j = expression.IndexOf(')', i);
                    if (j == -1)
                        return false;

                    string substring = expression.Substring(i + 1, j - i - 1);

                    while (MyData.getcharactercount(substring, '(') != MyData.getcharactercount(substring, ')'))
                    {
                        if (j < expression.Length - 1)
                            j = expression.IndexOf(')', j + 1);
                        else
                            break;

                        substring = expression.Substring(i + 1, j - i - 1);
                    }

                    i = j - 1; 

                    if (validateInfix(substring) == true)
                    {
                        if (previous != 0 && previous1 != 0 && previous > previous1)
                        {
                            previous1 = operatorOperand;
                            operatorOperand++;
                            previous = 0;
                        }
                        else if (previous != 0 && previous1 != 0 && previous <= previous1)
                        {
                            return false;
                        }
                        else if (previous1 != 0)
                        {
                            return false;
                        }
                        else
                        {
                            previous1 = operatorOperand;
                            operatorOperand++;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                    if (c == '+'                     
                   || c == '-'
                   || c == '*'
                   || c == '/')
                {
                    if (previous != 0)
                    {
                        return false;
                    }
                    previous = operatorOperand;
                    operatorOperand++;
                }
                else
                {
                    if (previous != 0 && previous1 != 0 && previous > previous1)
                    {
                        previous1 = operatorOperand;
                        operatorOperand++;
                        previous = 0;
                    }
                    else if (previous != 0 && previous1 != 0 && previous <= previous1)
                    {
                        return false;
                    }
                    else if (previous1 != 0)
                    {
                        return false;
                    }
                    else
                    {
                        previous1 = operatorOperand;
                        operatorOperand++;
                    }
                }
            }
            if (previous != 0)
                return false;
            return true;
        }

        /// <summary>
        /// This function will convert infix to postfix,
        /// and EvaluateInfix will process postfix evaluation.
        /// This function will be used in EvaluateInfix
        /// </summary>
        /// 
        /// <param name="expression"></param>
        /// 
        /// <returns>string</returns>
        public static string InfixToPostfixConversion(string expression)
        {

            string result = "";

            Stack<char> stack = new Stack<char>();

            for (int i = 0; i < expression.Length; ++i)
            {
                char c = expression[i];

                if (char.IsLetterOrDigit(c))
                {
                    result += c;
                }

                else if (c == '(')
                {
                    stack.Push(c);
                }

                else if (c == ')')
                {
                    while (stack.Count > 0
                           && stack.Peek() != '(')
                    {
                        result += stack.Pop();
                    }

                    if (stack.Count > 0
                        && stack.Peek() != '(')
                    {
                        return "Invalid Expression"; 
                                                    
                    }
                    else
                    {
                        stack.Pop();
                    }
                }
                else 
                {
                    while (stack.Count > 0
                           && MyData.Prec(c) <= MyData.Prec(stack.Peek()))
                    {
                        result += stack.Pop();
                    }
                    stack.Push(c);
                }
            }

            while (stack.Count > 0)
            {
                result += stack.Pop();
            }

            return result;
        }
    }
}