/* Author:      Floyd Ack
 * Date:        Thursday, 17 June 2020
 * Github:      https://github.com/jaesonnn
 * Twitter:     https://twitter.com/WellFloyd
 * Facebook:    https://www.facebook.com/jason.ack/
 * Instagram:   https://www.instagram.com/wellfloyd_/
 * Purpose:     Miscellaneous is a program that comprises seven functions, each
 *              of which does a highly specific purpose that is unrelated to the
 *              others, hence the name Miscellaneous.
*/

#include "miscellaneous.h"

#include <QDebug>
#include <iomanip>
#include <cstdlib>
#include <iostream>
using namespace std;

Miscellaneous::Miscellaneous()
{
//    qDebug() << "A Miscellaneous object is created";
}

// function that prints a diamond shape with an x amount of rows
void Miscellaneous::printDiamond()
{
    int base, row, column, star;

    cout << "Please enter any odd number as the base between 1-19: ";
    cin >> base;

    if(base > 1 && base < 19)
    {
        if(base%2 == 0)         // checks if the number inputted is an odd number
        {
            cout << "ERROR: Your base number isn't an odd number.\n";       // error message
            printDiamond();                                                 // recalls itself
        }
        else
        {
            // prints the top part of the diamond
            for(row=0; row <= base/2; row++)
            {
                for(column=0; column <= base/2 - row; column++) {
                    cout << " ";
                }
                for(star=0; star < (2*row+1); star++) {
                    cout << "*";
                }
                cout << "\n";
            }

            // prints the bottom part of the diamond
            for(row=0; row < base/2; row++)
            {
                for(column=1; column < row+3; column++) {
                    cout << " ";
                }
                for(star=1; star < base-(2*row+1); star++) {
                    cout << "*";
                }
                cout << "\n";
            }
        }
    }
    else        // the number entered is not a number between 0 and 19
    {
        cout << "ERROR: The number you entered is not in the range.\n";
        printDiamond();
    }
}

// function that prompts the user to answer 10 multiplication problems
void Miscellaneous::multiplication()
{
    int score = 0;
    int correct = 0;
    int numbering = 1;
    int response;

    cout << "Enter an answer for each multiplication problem.\n";

    for(int count=1; count<=10; count++)
    {
        int num1 = rand() % 9 + 1;      // a random number is chosen as value for the first number
        int num2 = rand() % 9 + 1;      // a random number is chosen as value for the second number
        int answer = num1 * num2;       // the answer is calculated and is available for comparison

        cout << "\n" << numbering << ".) How much is " << num1 << " times " << num2 << "? ";
        cin >> response;

        ++numbering;

        int rightAnsRandNum = rand() % 4 + 1;       // a random number is chosen & is to be used to output any one of the 4 correct statements
        int wrongAnsRandNum = rand() % 4 + 1;       // a random number is chosen & is to be used to output any one of the 4 incorrect statements

        // the user's response matches the value of variable 'answer'
        if(response == answer)
        {
            switch(rightAnsRandNum)        // if it's the correct answer, it prints one of the statements according to the first random number
            {
                case 1: cout << "    Very Good!\n"; break;
                case 2: cout << "    Excellent!\n"; break;
                case 3: cout << "    Nice Work!\n"; break;
                case 4: cout << "    Keep up the good work!\n"; break;
            }
            correct++;
        }
        else                            // the user entered an incorrect answer
        {
            switch(wrongAnsRandNum)     // one of the four statements is printed to inform the user that he/she is wrong
            {
                case 1: cout << "    No. Please try again.\n"; break;
                case 2: cout << "    Wrong. Try once more.\n"; break;
                case 3: cout << "    Don't give up.!\n"; break;
                case 4: cout << "    No. Keep trying.\n"; break;
            }

            // continues the first loop after an incorrect answer was made
            for(int count=correct; count<9; count++)
            {
                cout << "\n" << numbering << ".) How much is " << num1 << " times " << num2 << "? ";
                cin >> response;

                if(response == answer)
                {
                    switch(rightAnsRandNum)        // one of the four statements is printed to inform the user that he/she is right
                    {
                        case 1: cout << "    Very Good!\n"; break;
                        case 2: cout << "    Excellent!\n"; break;
                        case 3: cout << "    Nice Work!\n"; break;
                        case 4: cout << "    Keep up the good work!\n"; break;
                    }
                    correct++;      // the value of correct answers is incremented
                    numbering++;
                    break;          // we break out the if-statement if a right attempt was made
                }
                else                // the user entered an incorrect answer again
                {
                    switch(wrongAnsRandNum)         // one of the four statements is printed to inform the user that he/she is wrong
                    {
                        case 1: cout << "    No. Please try again.\n"; break;
                        case 2: cout << "    Wrong. Try once more.\n"; break;
                        case 3: cout << "    Don't give up.!\n"; break;
                        case 4: cout << "    No. Keep trying.\n"; break;
                    }
                    numbering++;
                }
            }   // end of for-loop
        }   // end of else statement

        // we exit the outer for-loop after 10 questions
        if(numbering == 11)
            break;
    }

    // the user's score is calculated for
    score = (correct * 100)/10;
    cout << "\nYour score is " << score << "%\n";

    if(score < 75)      // the user performed poorly
        cout << "\tPlease ask your instructor for extra help.\n";
    else                // the user performed well
        cout << "\tGreat job!\n";
}

// function that allows the user to guess a random number in the range 1 to 1000
void Miscellaneous::numberGuess()
{
    int num = rand() % 1000 + 1;
    int count = 1;
    int guess;
    char response;

    cout << "I have a number between 1 and 1000.\n"
            "Can you guess my number?\n"
            "Please enter your first guess: ";
    cin >> guess;

    // enters the loop if the user's guess isn't equal to the random number
    while(guess != num)
    {
        // the user guessed a higher number
        if(guess > num) {
            cout << "\nToo high. Try again.\n";
            count++;
        }
        else {      // the user guessed a lower number
            cout << "\nToo low. Try again.\n";
            count++;
        }

        cout << "Guess again.\n";
        cin >> guess;
    }

    // the right number is guessed
    if(guess == num)
        cout << "Excellent! You guessed the number!\n";

    if(count < 10)          // less than 10 tries
        cout << "Either you know the secret or you got lucky!\n";
    else if(count == 10)    // exactly 10 tries
        cout << "Aha! You know the secret!\n";
    else if(count > 10)     // more than 10 tries
        cout << "You should be able to do better.\n";

    // asks the user if he/she wants to play again
    cout << "Would you like to play again? (y or n) ==> ";
    cin >> response;

    if(response =='y' || response == 'Y') {
        numberGuess();
    }
    else if(response == 'n' || response == 'N') {
        system("break");
    }
}

// function that asks the user for the size of the side of a square and then prints a hollow square
void Miscellaneous::printSquare()
{
    int rows;
    cout << "Enter number of rows: ";
    cin >> rows;

    for(int i=1; i<=rows; i++)
    {
        for(int j=1; j<=rows; j++)
        {
            if((i==1) || (i==rows))
                cout << "*";
            else {
                if((j==1) || (j==rows))
                    cout << "*";
                else
                    cout << " ";
            }
        }
        cout << endl;
    }
}

void Miscellaneous::calculatePayroll()
{
    int code, product, hours;
    double salary, hrlyRate, rate, sale;
    double overtime, overTimePay, gross, wage;

    cout << "To calculate the weekly pay depends on the type of employee.\n"
            "     Each employee has a unique key from 1-4\n"
            "     Managers(1)           Hourly workers(2)\n"
            "     Commission workers(3) Piece Workers(4).\n"
            "     Enter (5) is you wish to quit.\n"
            "Code: ";
    cin >> code;

    // runs continuously unless 5 is entered by the user
    while(code != 5)
    {
        switch(code)
        {
            case 1: cout << "      Managers\n"; break;
            case 2: cout << "      Hourly Workers\n"; break;
            case 3: cout << "      Commission Workers\n"; break;
            case 4: cout << "      Piece Workers\n"; break;
            default: break;
        }

        if(code == 1)   // runs when code (1) is entered
        {
            cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                    "^^^^ Manager PayCode Has been selected ^^^^\n"
                    "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                    "Enter Salary: $";
            cin >> salary;
            cout << "==> Manager's salary is: $" << salary << endl;
        }

        if(code == 2)   // runs when code (2) is entered
        {
            cout << "\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                    "^ Hourly Workers PayCode Has Been Selected ^\n"
                    "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                    "Enter Hour Rate($0.00):$ ";
            cin >> hrlyRate;

            cout << "Enter hours worked: ";
            cin >> hours;

            if(hours > 40)
            {
                gross = hrlyRate * 40;
                overtime = hours - 40;                      // overtime hours is being calculated for
                overTimePay = overtime * hrlyRate * 1.5;    // overtime pay is being calculated for
                salary = gross + overTimePay;
                cout << "==> Hourly worker's salary is: $" << salary << endl;
            }
            else {
                salary = hrlyRate * hours;      // calculates the hourly rate by multiplying it to hours then stores it in salary
                cout << "==> Hourly worker's salary is: $" << salary << endl;
            }
        }

        if(code == 3)   // runs when code (3) is entered
        {
            cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                  "^ Commission Workers PayCode Has Been Selected ^\n"
                  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                  "Enter weekly sale: ";
            cin >> sale;
            cout << "Employee recieves $250 plus 5.7% of their gross weekly sales.\n";
            wage = (sale * 5.7)/100;
            salary = wage + 250;
            cout << "==> Commission worker's salary is: $" << salary << endl;
        }

        if(code == 4)   // runs when code (4) is entered
        {
            cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                  "^^ Piece Worker PayCode Has Been Selected ^^\n"
                  "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n"
                  "Enter the number of products sold: ";
            cin >> product;

            cout << "Enter rate per each pieces sold: $";
            cin >> rate;

            cout << "Employee recieves a fixed amount of money per item they produce.\n";
            salary = product * rate; // salary is being calculated for by multiplying the product and rate
            cout << "==> Piece worker's salary is: $" << salary << endl;
        }

        cout << "\nDo you wish to calculate another employee?\n"
                "Enter (5) is you wish to quit.\n";
        cout << "Code: ";
        cin >> code;
    }
}

// function that takes an integer parameter with an unknown number of digits & returns the number with its digits reversed
int Miscellaneous::reverse(int num)
{
    int reversedNumber = 0;

    while(0 < num)
    {
        // 0 is then multiplied with 10 and is added added to the remainder of the number after being divided by 10
        reversedNumber = (reversedNumber * 10) + (num%10);

        // the value after being multiplied by 0 then added to the modulus is returned to be displayed
        num = num/10;
    }
    return reversedNumber;
}

// function that finds the power of a given base number with a given exponent
long int Miscellaneous::power(int base, int exponent)
{
    if(exponent == 1)       // base case
        return base;
    else
        return (base * power(base,exponent-1));     // recursive call
}
