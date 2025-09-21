
// Anthony Herrera
// 9/18/2025
// CMPR 131
// Prof. Quach
// Assignment 04

#include <iostream>
#include <string>
#include <iomanip>
#include "input.h"
//#include "Quadratic.h"
//#include "PseudoRandom.h"
#include "Rational.h"

using namespace std;

void RationalMenu();
void OneRational(Rational& r);
void MultRational(Rational& r3);

void EnterR1(Rational& r1);
void EnterR2(Rational& r2);
char menuOption();



int main()
{
    do
    {
        switch (menuOption())
        {
        case 'X': exit(0); break;
        //case '1': quadraticMenu(); break;
        //case '2': pseudoRandomMenu(); break;
        case '2': RationalMenu(); break;

        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return EXIT_SUCCESS;

}

char menuOption()
{
    system("cls");
    cout << "\n\tCMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Anthony Herrera (9/18/25)";
    cout << "\n\t" << string(105, char(205));
    cout << "\n\t1> Complex Numbers";
    cout << "\n\t2> Rational Numbers";
    cout << "\n\t3> Polynomials";
    cout << "\n\t" << string(105, char(196));
    cout << "\n\tX.Exit";
    cout << "\n\t" << string(105, char(205));

    return toupper(inputChar("\n\tOption: "));

}

void EnterR1(Rational& r1)
{
    r1.setNumerator(inputInteger("\n\tEnter numerator for r1: "));

    while (true)
    {
        try
        {
            r1.setDenominator(inputInteger("\n\tEnter Denominator for r1: "));
            break;
        }
        catch (const Rational::divisionByZero& e)
        {
            cerr << e.what();
        }
    }

    r1.normalize();

}

void EnterR2(Rational& r2)
{
    r2.setNumerator(inputInteger("\n\tEnter numerator for r2: "));
    while (true)
    {
        try
        {
            r2.setDenominator(inputInteger("\n\tEnter Denominator for r2: "));
            break;
        }
        catch (const Rational::divisionByZero& e)
        {
            cerr << e.what();
        }
    }

    r2.normalize();

}




void RationalMenu()
{
    Rational r3;
    Rational r;

    while (true)
    {
        system("cls");
        cout << "\n\tA rational number is a number that can be written as a fraction, a/b, where a is numerator and"
             << "\n\tb is denominator.Rational numbers are all real numbers, and can be positive or negative.A"
             << "\n\tnumber that is not rational is called irrational.Most of the numbers that people use in everyday"
             <<"\n\tlife are rational.These include fractions, integers and numbers with finite decimal digits."
             <<"\n\tIn general, a number that can be written as a fraction while it is in its own form is rational.";

        cout << "\n\n\t2> Rational Numbers";
        cout << "\n\t" << string(105, char(205));
        cout << "\n\tA> Rational Number"
             << "\n\tB> Multiple Rational Numbers";
        cout << "\n\t" << string(105, char(196));
        cout << "\n\t0. Return";
        cout << "\n\t" << string(105, char(205));

        char optionR = toupper(inputChar("\n\tOption: "));

        switch (optionR)
        {
        case '0':
            cout << "\n\tReturn to main menu\n";
            return;
        case 'A': OneRational(r); break;

        case 'B': MultRational(r3); break;
        
        default:
            cout << "\n\tInvalid choice.\n";

        }

        cout << "\n\n";
        system("pause");
    }

}

void OneRational(Rational& r)
{

    while (true)
    {
        system("cls");
        cout << "\n\n\tA Rational Number";
        cout << "\n\t" << string(105, char(205));
        cout << "\n\t1. Enter the numerator"
            << "\n\t2. Enter the denominator"
            << "\n\t3. Display the rational number"
            << "\n\t4. Normalize the rational number"
            << "\n\t5. Negate the rational number"
            << "\n\t6. Add (+) the rational number with a constant"
            << "\n\t7. Subtract (-) the rational number with a constant"
            << "\n\t8. Multiply(*) the rational number with a constant"
            << "\n\t9. Divide(/) the rational number with a constant";
        cout << "\n\t" << string(105, char(196));
        cout << "\n\t0. Return";
        cout << "\n\t" << string(105, char(205));

        int optionR = toupper(inputInteger("\n\tOption: "));

        switch (optionR)
        {
        case 0:
            cout << "\n\tReturn to main menu\n";
            return;
        case 1:
        {
            r.setNumerator(inputInteger("\n\tEnter an integer for the numerator: "));
        } break;

        case 2:
        {
            while (true)
            {
                try
                {
                    r.setDenominator(inputInteger("\n\tEnter an integer for the denominator: "));
                    break;
                }
                catch (const Rational::divisionByZero& e)
                {
                    cerr << e.what();
                }
            }
        } break;
        case 3:
        {
          cout << "\n\tRational number R1 = " << r;
        } break;

        case 4:
        {
            Rational copy4 = r;
            copy4.normalize();
            cout << "\n\tNormalized rational number R2 (a copy of R1)" << "\n\t" << copy4;
        }break;

        case 5:
        {
            Rational copy = r;
            Rational negated = -copy;
            cout << "\n\tNegated rational number R2 (a copy of R1)";
            cout << "\n\t-(" << copy << ")" << " = " <<  -copy;
        } break;

        case 6:
        {
            Rational copy = r;
            int addConst = inputInteger("\n\tEnter an integer value: ");
            cout << "\n\n\tR2 + value"
                << "\n\t(" << copy << ") + " << addConst << " = " << (copy + addConst);

            cout << "\n\n\tvalue + R2"
                << "\n\t" << addConst << " + (" << copy << ")" << " = " << (addConst + copy);
        } break;

        case 7: 
        {
            Rational copy = r;
            int subConst = inputInteger("\n\tEnter an integer value: ");
            cout << "\n\n\tR2 - value"
                << "\n\t(" << copy << ") - " << subConst << " = " << (copy - subConst);

            cout << "\n\n\tvalue - R2"
                << "\n\t" << subConst << " - (" << copy << ")" << " = " << (subConst - copy);
        } break; 

        case 8:
        {
            Rational copy = r;
            int multConst = inputInteger("\n\tEnter an integer value: ");
            cout << "\n\n\tR2 * value"
                << "\n\t(" << copy << ") * " << multConst << " = " << (copy * multConst);

            cout << "\n\n\tvalue * R2"
                << "\n\t" << multConst << " * (" << copy << ")" << " = " << (multConst * copy);
        } break;

        case 9: 
        {
            Rational copy = r;
            int divConst = inputInteger("\n\tEnter an integer value: ");
            cout << "\n\n\tR2 / value";
            try
            {
                cout << "\n\t(" << copy << ") / " << divConst << " = " << (copy / divConst);
            }
            catch (const std::exception&)
            {
                cout << "\n\t(" << copy << ") / " << divConst << " = " << "undefined";
            }

            cout << "\n\n\tvalue / R2";
            try
            {
               cout << "\n\t" << divConst << " / (" << copy << ")" << " = " << (divConst / copy);
            }
            catch (const std::exception&)
            {
                cout << "\n\t" << divConst << " / (" << copy << ")" << " = " << "undefined";
            }

        } break;

        default:
            cout << "\n\tInvalid choice.\n";
        }

        cout << "\n\n";
        system("pause");
    }
}

void MultRational(Rational& r3)
{
    Rational r1, r2;

    r3.setNumerator(621);
    r3.setDenominator(889);



    while (true)
    {
        system("cls");
        cout << "\n\n\tB> Multiple Rational Numbers";
        cout << "\n\t" << string(105, char(205));
        cout << "\n\t1. Enter rational number R1"
            << "\n\t2. Enter rational number R2"
            << "\n\t3. Verify condition operators (==, !=, >=, >, <= and <) of R1 and R2"
            << "\n\t4. Evaluate arithmatic operators (+, - , * and /) of R1 and R2"
            << "\n\t5. Evaluate (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >= 621/889";
        cout << "\n\t" << string(105, char(196));
        cout << "\n\t0. Return";
        cout << "\n\t" << string(105, char(205));

        int optionR = toupper(inputInteger("\n\tOption: "));

        switch (optionR)
        {
        case 0:
            cout << "\n\tReturn to main menu\n";
            return;
        case 1: 
        {
            EnterR1(r1); 
            cout << "\n\tR1 = " << r1;
        } break;

        case 2:
        {
            EnterR2(r2);
            cout << "\n\tR2 = " << r2;
        } break;
        case 3: 
        {
            cout << boolalpha;
            cout << "\n\tR1 == R2 -> ("<< r1 << ") == ("<< r2 <<") ? " << (r1 == r2);
            cout << "\n\tR1 != R2 -> (" << r1 << ") != (" << r2 << ") ? " << (r1 != r2);
            cout << "\n\tR1 >= R2 -> (" << r1 << ") >= (" << r2 << ") ? " << (r1 >= r2);
            cout << "\n\tR1  > R2 -> (" << r1 << ")  > (" << r2 << ") ? " << (r1 > r2);
            cout << "\n\tR1 <= R2 -> (" << r1 << ") <= (" << r2 << ") ? " << (r1 <= r2);
            cout << "\n\tR1  < R2 -> (" << r1 << ")  < (" << r2 << ") ? " << (r1 < r2);
        } break;

        case 4:
        {
            cout << "\n\tAddition      :R1 + R2 -> (" << r1 << ") + (" << r2 << ") = " << (r1 + r2);
            cout << "\n\tSubtraction   :R1 - R2 -> (" << r1 << ") - (" << r2 << ") = " << (r1 - r2);
            cout << "\n\tMultiplication:R1 * R2 -> (" << r1 << ") * (" << r2 << ") = " << (r1 * r2);
            try 
            {
                cout << "\n\tDivision      :R1 / R2 -> (" << r1 << ") / (" << r2 << ") = " << (r1 / r2);
            }
            catch (const Rational::divisionByZero& e) 
            {
                cout << "\n\tDivision      :R1 / R2 -> (" << r1 << ") / (" << r2 << ") = 0/0";
            }
        }break;


        case 5:
        {

            cout << "\n\tR1 = " << r1;
            cout << "\n\tR2 = " << r2;
            cout << "\n\tR3 = " << r3;

            cout << "\n\n\tEvaluating Expression...";
            cout << "\n\t\t (3 * (R1 + R2) / 7) / (R2 - R1 / 9) >=" << r3 << " ?";
            cout << "\n\tstep #1: (3 * (" << r1 + r2 << ") / 7) / (R2 - "<< r1 / 9 << ") >= " << r3 << " ? ";
            cout << "\n\tstep #2: (" << 3 *  (r1 + r2) << ") / 7) / (" << r2 - r1 / 9 << ") >= " << r3 << " ? ";
            cout << "\n\tstep #3: (" << (3 * (r1 + r2) / 7) << ") / (" << r2 - r1 / 9 << ") >= " << r3 << " ? ";
            
            cout << boolalpha;
            try
            {
                cout << "\n\tstep #4: (" << (3 * (r1 + r2) / 7) / (r2 - r1 / 9) << ") >= " << r3 << " ? ";
                cout << "\n\tstep #5: " << ((3 * (r1 + r2) / 7) / (r2 - r1 / 9) >= r3);
            }
            catch (const Rational::divisionByZero& e)
            {
                cout << "\n\tstep #4: (0/0) >= " << r3 << " ? ";
                cout << "\n\tstep #5: " << (0 >= r3);
            }


        } break;

        default:
            cout << "\n\tInvalid choice.\n";
        }

        cout << "\n\n";
        system("pause");
    }
}
