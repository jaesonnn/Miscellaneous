#include <iostream>
#include <cstdlib>
using namespace std;

#include "miscellaneous.h"

void showMenu();
int getResponse();

int main()
{
    int response;
    int base, exponent;
    int number;

    Miscellaneous demo;

    while((response = getResponse()) != 8)
    {
        switch(response)
        {
            case 1:
                demo.printDiamond();
                cout << "\n\n";
                break;
            case 2:
                demo.multiplication();
                cout << "\n\n";
                break;
            case 3:
                demo.numberGuess();
                cout << "\n\n";
                break;
            case 4:
                demo.printSquare();
                cout << "\n\n";
                break;
            case 5:
                demo.calculatePayroll();
                cout << "\n";
                break;
            case 6:
                cout << "Enter the number to be reversed: ";
                cin >> number;
                cout << demo.reverse(number) << "\n\n";
                break;
            case 7:
                cout << "Enter the base: ";
                cin >> base;
                cout << "Enter the exponent: ";
                cin >> exponent;
                cout << demo.power(base,exponent) << "\n\n";
                break;
        }
        system("pause");
    }
    cout << "\nThank you and have a nice day!\n\n";

    return 0;
}

void showMenu()
{
    system("cls");
    cout << "***********************************\n";
    cout << "* Press 1 to print a diamond      *\n";
    cout << "* Press 2 to do multiplication    *\n";
    cout << "* Press 3 to play number guessing *\n";
    cout << "* Press 4 to print a square       *\n";
    cout << "* Press 5 to calculate payroll    *\n";
    cout << "* Press 6 to reverse a number     *\n";
    cout << "* Press 7 to use power function   *\n";
    cout << "* Press 8 to Quit                 *\n";
    cout << "***********************************\n";
    cout << "=====> ";
}

int getResponse()
{
    int response;
    showMenu();             // outputs the menu to the screen
    cin >> response;

    while(response < 1 || response > 8)
    {
        showMenu();
        cin >> response;
    }
    return response;
}
