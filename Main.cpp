/*
Name: Pedro Vargas
Instructor: Professor Quach
Date: 9/17/2025
Description:

Demonstrates Chapter 4, with Complex, rational, and polynomial functions. 
*/



#include <iostream>
#include <iomanip>
#include "Complex.h"
#include "input.h"
using namespace std;



const char* INDENT = "\t";

char mainMenu();

//Complex function lists
void complexProgram();
char complexMenu();
void singleComplexOperations();
void multiComplexOperations();

//Rational function lists
void rationalProgram();
//polynomial function lists
void polynomialProgram();




//main program for all function calls (menu calls)
int main() {
	bool running = true;
	do {
		char functionType = mainMenu();

		switch (functionType) {
		case '1': complexProgram(); break;
		case '2': rationalProgram(); break;
		case '3': polynomialProgram();break;
		default:
			running = false;
		}
	} while (running);
	cout << INDENT << "Program exitted successfully. " << endl;
	return EXIT_SUCCESS;
}



/*
@return char - choice made after main option prompt.
precondition: program begins
postcondition: decision tree to handle return choice. */
char mainMenu() {
	bool invalidChoice = true;

	//rh reference to avoid instancing a char

	char&& tempChoice = 'A';
	do {
		system("cls");
		cout << "\n";
		cout << INDENT <<" CMPR131 Chapter 4: Complex Numbers, Rational Numbers, Polynomials by Pedro Vargas(9 / 17 / 2025)\n";
		cout << INDENT << string(95, (char)205) << endl;
		cout << INDENT<< "1 > Complex Numbers\n";
		cout << INDENT << "2 > Rational Numbers\n";
		cout << INDENT << "3  > Polynomials\n";
		cout << INDENT << string(95, (char)196) << endl;
		cout << INDENT << "0 > exit\n";
		cout << INDENT << string(95, (char)205) << endl;
		tempChoice = inputChar("\tEnter choice:", false);
		if (tempChoice > '3') {
			cerr << INDENT << "INVALID CHOICE ENTERED.TRY AGAIN. \n\t";
			system("pause");
			continue;
		}
		else invalidChoice = false;
	} while (invalidChoice);
	return tempChoice;
}






/**********************************************************************/
/*Complex Section */
/**********************************************************************/

void complexProgram() {
	bool continueRunning = true;
	do {
		char menuChoice = complexMenu();

		switch (menuChoice) {
		case 'A':
			singleComplexOperations();
			break;
		case 'B':
			multiComplexOperations();
			break;
		case '0':
			continueRunning = false;
			break;
		default:break;
		}

	} while (continueRunning);
	cout << "Sending you back to main menu..." << endl;
	system("pause");
	return;
}
char complexMenu() {
	char tempChoice = 'A';
	bool invalidChoice = true;

	do {
		system("cls");
		cout << R"zzz(
          A complex number is a number that can be expressed in the form a + b i, where a and b are real
          numbers, and i represents the "imaginary uni", satisfying the equation i^2 = -1. Because no
          real number satisfies this equation, i is called an imaginary number. For the complex number
          a + b i, a is called the real part and b is called the imaginary part.

                1> Complex Numbers
)zzz";
		cout << INDENT << string(90, (char)205) << endl;
		cout << INDENT << "A> A Complex Number\n";
		cout << INDENT << "B> Multiple Complex Numbers\n";
		cout << INDENT << string(90, (char)196) << endl;
		cout << INDENT << "0> return\n";
		cout << INDENT << string(90, (char)205) << endl;
		tempChoice = inputChar("\tEnter choice:");
		if ( tempChoice != '0'&&(tempChoice != 'A' && tempChoice != 'B')) {
			cerr << INDENT << "INVALID CHOICE ENTERED.TRY AGAIN. \n\t";
			system("pause");
			continue;
		}
		else invalidChoice = false;
	} while (invalidChoice);
	return tempChoice;
}




void multiComplexOperations() {
	Complex complexNum1;
	Complex complexNum2;
	Complex complexNum3(1.07109, 0.120832);

	Complex tempVar1;
	Complex tempVar2;


	char menuChoice = 'A';
	do{
	system("cls");
	cout << INDENT << "B > Multiple Complex Numbers\n";
	cout << INDENT << string(90, (char)205) << endl;
	cout << INDENT << INDENT << "1. Enter complex number C1\n";
	cout << INDENT << INDENT << "2. Enter complex number C2\n";
	cout << INDENT << INDENT << "3. Verify condition operators(== and != ) of C1 and C2\n";
	cout << INDENT << INDENT << "4. Evaluate arithmatic operators(+, -, *and / ) of C1 and C2\n";
	cout << INDENT << INDENT << "5. Evaluate steps in(3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (1.07109 + 0.120832i) ?\n";
	cout << INDENT << string(90, (char)196) << endl;
	cout << INDENT << "0. return\n";
	cout << INDENT << string(90, (char)205) << endl;
	menuChoice = inputChar("\tOption: ", false);

	switch (menuChoice) {
	case '1':
		complexNum1.setRealFactor(inputDouble("\t\tEnter a number (Double Value) for the real part of C1: "));
		complexNum1.setImaginaryFactor(inputDouble("\t\tEnter a number (double Value) for the imaginary part of C1:"));
		cout << "\n\t\t" << "C1 = " << complexNum1 << endl << endl;
		break;
	case '2':
		complexNum2.setRealFactor(inputDouble("\t\tEnter a number (Double Value) for the real part of C2: "));
		complexNum2.setImaginaryFactor(inputDouble("\t\tEnter a number (double Value) for the imaginary part of C2:"));
		cout << "\n\t\t" << "C2 = " << complexNum2 << endl << endl;
		break;
	case '3':
		cout << "\n\n";
		cout << INDENT << INDENT << "C1 == C2 -> ( " << complexNum1 << ") == ( " << complexNum2 << ") ? " << (complexNum1 == complexNum2 ? "True" : "False") << endl;
		cout << INDENT << INDENT << "C2 != C1 -> ( " << complexNum2 << ") != ( " << complexNum1 << ") ? " << (complexNum2 != complexNum1 ? "True" : "False") << endl << endl;

		break;
	case '4':
		cout << "\n\n";
		cout << INDENT << INDENT << "Addition      : C1 + C2 -> (" << complexNum1 << ") + (" << complexNum2 << ") = " << (complexNum1 + complexNum2) << endl;
		cout << INDENT << INDENT << "Subtraction   : C2 - C1 -> (" << complexNum2 << ") - (" << complexNum1 << ") = " << (complexNum2 - complexNum1) << endl;
		cout << INDENT << INDENT << "Multiplication: C1 * C2 -> (" << complexNum1 << ") * (" << complexNum2 << ") = " << (complexNum1 * complexNum2) << endl;
			try {
				cout << INDENT << INDENT << "Division      : C2 / C1 -> (" << complexNum2 << ") / (" << complexNum1 << ") = " <<setprecision(3) << complexNum2 / complexNum1;
		} catch (const exception& e) {
			cerr <<"\n" <<  INDENT << INDENT << e.what() << endl << endl;
			}
		cout << endl << endl;
		break;
	case '5':
		cout << "\n\n";
		cout << INDENT << INDENT << "C1 = " << complexNum1 << endl;
		cout << INDENT << INDENT << "C2 = " << complexNum2 << endl;
		cout << INDENT << INDENT << "C3 = " << complexNum3 << endl << endl;
		cout << INDENT << INDENT << "Evaluating expression..." << endl << endl;
		
		cout << INDENT << INDENT << "(3 * (C1 + C2) / 7) / (C2 - C1 / 9) != (" << complexNum3 << ")?\n\n";
		tempVar1 = complexNum1 + complexNum2;
		tempVar2 = complexNum2 - complexNum1;

		cout << INDENT << INDENT << "Step #1: (3 * (" << tempVar1 << ") / 7 ) / ( " << tempVar2 << " / 9) != (" << complexNum3 << ")\n";
		tempVar1 = tempVar1 * 3;
		tempVar2 = complexNum2 - complexNum1;

		cout << INDENT << INDENT << "Step #2: ((" << tempVar1 << ") / 7) / (R2 / 9) != (" << complexNum3 << ")\n";
		tempVar1 = tempVar1 / 7.0;
		tempVar2 = tempVar2 / 9.0;
		cout << INDENT << INDENT << "step #3: ((" << tempVar1 << ") / (" << tempVar2 << ") != (" << complexNum3 << ")\n";
		try {
			tempVar1 = tempVar1 / tempVar2;
		}
		catch (const exception& e) {
			tempVar1.setRealFactor(0.0);
			tempVar1.setImaginaryFactor(0.0);
		}
		cout << INDENT << INDENT << "step #4: (" << tempVar1 << ") != (" << complexNum3 << ")\n";
		cout << INDENT << INDENT << "step #5: " << ((tempVar1 != complexNum3) ? "True" : "False") << endl << endl;

		break;
	default:
		cout << INDENT << "Sending you back to main menu. \n\t";
		system("pause");
		return;
	}
	system("pause");
	}while (true);
}



void singleComplexOperations() {
	Complex complexNum;
	char menuChoice = 'A';
	double constant = 0.0;
	Complex C2;
	
	do {
		system("cls");
		cout << INDENT << "A> A Complex Number\n";
		cout << INDENT << string(90, (char)205) << endl;
		cout << INDENT << INDENT << "1. Enter the real number\n";
		cout << INDENT << INDENT << "2. Enter the imaginary number\n";
		cout << INDENT << INDENT << "3. Display the complex number\n";
		cout << INDENT << INDENT << "4. Negate the complex number\n";
		cout << INDENT << INDENT << "5. Add (+) the complex number with a constant\n";
		cout << INDENT << INDENT << "6. Subtract (-_ the complex number with a constant\n";
		cout << INDENT << INDENT << "7. Multiply (*) the complex number with a constant\n";
		cout << INDENT << INDENT << "8. Divide(/) the complex number with a constant\n";
		cout << INDENT << string(90, (char)196) << endl;
		cout << INDENT << INDENT << "0. return\n";
		cout << INDENT << string(90, (char)205) << endl;
		menuChoice = inputChar("\tOption:", false);


		switch (menuChoice) {
		case '1':
			complexNum.setRealFactor(inputDouble("\tEnter a number (double value) for the real part: "));
			break;
		case '2':
			complexNum.setImaginaryFactor(inputDouble("\tEnter a number (double value) for the imaginary part: "));
			break;
		case '3':
			cout << INDENT << INDENT << "Complex number C1 = " << complexNum << "\n\n";
			break;
		case '4':
			cout << INDENT << INDENT << "-(" << complexNum << ") = " << (complexNum * -1) << "\n\n";
			break;
		case '5':
			C2 = complexNum;
			constant = inputDouble("\t\tEnter a value (double):");
			cout << "\n\n";
			//first add
			cout << INDENT << INDENT << "C2 + value\n" << INDENT << INDENT;
			cout << "(" << C2 << ") + " << constant << " = " << (C2 + constant);
			//second add
			C2 = complexNum;
			cout << "\n\n";
			cout << INDENT << INDENT << "value + C2\n" << INDENT << INDENT;
			cout << constant << " + (" << C2 << ") " << " = " << (constant + C2);
			cout << "\n\n";
			break;
		case '6':
			C2 = complexNum;
			constant = inputDouble("\t\tEnter a value (double):");
			cout << "\n\n";
			//first subtract
			cout << INDENT << INDENT << "C2 - value\n" << INDENT << INDENT;
			cout << "(" << C2 << ") - " << constant << " = " << (C2 - constant);
			//second sub
			C2 = complexNum;
			cout << "\n\n";
			cout << INDENT << INDENT << "value - C2\n" << INDENT << INDENT;
			cout << constant << " - (" << C2 << ") " << " = " << (constant - C2);
			cout << "\n\n";
	
			break;
		case '7':
			C2 = complexNum;
			constant = inputDouble("\t\tEnter a value (double):");
			cout << "\n\n";
			//first mult
			cout << INDENT << INDENT << "C2 * value\n" << INDENT << INDENT;
			cout << "(" << C2 << ") * " << constant << " = " << (C2 * constant);
			//second mult
			C2 = complexNum;
			cout << "\n\n";
			cout << INDENT << INDENT << "value * C2\n" << INDENT << INDENT;
			cout << constant << " * (" << C2 << ") " << " = " << (constant * C2);
			cout << "\n\n";
			break;
		case '8':
			C2 = complexNum;
			constant = inputDouble("\t\tEnter a value (double):");
			cout << "\n\n";
			try {
				//first divison
				cout << INDENT << INDENT << "C2 / value\n" << INDENT << INDENT;
				cout << "(" << C2 << ") / " << constant << " = " << (C2 / constant);
				//second division
				C2 = complexNum;
				cout << "\n\n";
				cout << INDENT << INDENT << "value / C2\n" << INDENT << INDENT;
				cout << constant << " / (" << C2 << ") " << " = " << (constant / C2);
				cout << "\n\n";
			}
			catch (const exception& e) {
				cerr << INDENT << e.what() << endl;
			}
			break;
		default:
			cout << INDENT << "Sending you back to main menu. \n\t";
			system("pause");
			return;
		}
		system("pause");
	} while (true);
}
/**********************************************************************/
/*End of Complex section*/
/**********************************************************************/

void rationalProgram() {

}


void polynomialProgram() {

}










