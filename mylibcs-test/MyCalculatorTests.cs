using Microsoft.VisualStudio.TestTools.UnitTesting;
using mylibcs;
using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


/**
 * @file MyCalculatorTests.cs
 * @author Fahrettin SOLAK
 * @date 18 October 2022
 *
 * @brief <b> HW-1 Tests </b>
 *
 * HW-1 Algo Lib Tests Header
 *
 * @see http://bilgisayar.mmf.erdogan.edu.tr/en/
 */


namespace mylibcs_test
{
    [TestClass]
    public class MyCalculatorTests
    {
        [TestMethod]
        public void TestEvaluateInfix()
        {
            string infixExpression = "2*(5*(3+6))/5-2*456";
            int res = MyCalculator.evaluateInfix(infixExpression);

            Assert.AreEqual(-894, res);
        }

        [TestMethod]
        public void TestValidateInfix()
        {
            LinkedList<string> arr = new LinkedList<string>();
            arr.AddFirst("AB(C/D)+E^F");
            foreach (string s1 in arr)
            {
                string str = s1;
                str = "(" + str + ")";
                str = str.Replace(" ", string.Empty);
                bool result = MyCalculator.validateInfix(str) == true;
                Assert.AreEqual(false, result);
            }
        }

        [TestMethod]
        public void TestInfixToPostfixConversion()
        {
            string exp = "a+b(c^d-e)^(f+gh)-i";
            string res = MyCalculator.InfixToPostfixConversion(exp);
            Assert.AreEqual("abcd^e-fgh+^+i-", res);
        }
    }
}