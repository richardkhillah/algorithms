//
//  main.cpp
//  Calculator
//  Description: A calculator that allows the user to input data "normally",
//               i.e. instead of pre/postfix expressions, user uses an infix
//               infix expression.
//
//  Created by Richard Khillah on 3/8/16.
//  Copyright © 2016 Richard Khillah. All rights reserved.
//
#include "LinkedStack.h"
#include <string>
#include <iostream>
#include <cassert>
using namespace std;

char Operators[] = {'+', '-', '*', '/'};
char Parens[] = {'(', ')'};
const int NUM_BRACKETS = 2;

bool isOperator(const char s);
bool isParen(const char s);
bool opPrecedence(const char ch, const char nextOpOnStack);

string convertInput(const string infixExpression);
int compute(const string postfixExpression);

int getMenuOption() {
    int option;
    bool inRange = false;
    cout << "Main Menu:\n";
    cout << "1. run Hardcoded Example\n";
    cout << "2. run UserInput Example\n";
    cout << "3. exit\n";
    do {
        cout << "What would you like to do? ";
        cin >> option;
        inRange = (option >= 1 && option <= 3);
        if (!inRange)
            cout << "invalid entry.  Try again.\n";
    }while (!inRange);
    return option;
}
void runHardCoded() {
    string input = "2*(4-2)";
    string converted = convertInput(input);
    cout << input << " was converted = " << converted << endl;
    int result = compute(converted);
    cout << "result = " << result << " should be 4" << endl;

    string input2 = "(2*3)-2";
    string converted2 = convertInput(input2);
    cout << input2 << " was converted2 = " << converted2 << endl;
    int result2 = compute(converted2);
    cout << "result2 = " << result2 << " should be 4" << endl;

    string input3 = "8-((2+2*3)/2)";
    string converted3 = convertInput(input3);
    cout << input3 << " was converted = " << converted3 << endl;
    int result3 = compute(converted3);
    cout << "result = " << result3 << " should be 4" << endl;
}
bool goAgain() {
    cout << "would you like to input another string? (y/n): ";
    char choice;
    cin >> choice;
    while (tolower(choice) != 'y' && tolower(choice) != 'n')
    {
        cout << "Enter either y or n: ";
        cin >> choice;
    }
    return tolower(choice) == 'y';
}
void runUserInput() {
    string infixExpression;
    string postfixExpression;
    int result = 0;
    do
    {
        cout << "Enter a PROPER infix expression: ";
        cin.ignore();
        getline(cin, infixExpression);
        postfixExpression = convertInput(infixExpression);
//        cout << infixExpression << "converted to postfix is " << postfixExpression << endl;
        result = compute(postfixExpression);
        cout << "the result of " << infixExpression << " is " << result << endl;
    }while (goAgain());
}

int main() {
    int choice = 0;
    do
    {
        choice = getMenuOption();
        switch (choice) {
            case 1:
                runHardCoded();
                break;
            case 2:
                runUserInput();
                break;
            case 3:
                exit(0);
                break;
        }
    } while (true);
        return 0;
}

bool isOperator(const char ch) {
    int index = 0;
    while (index < 4) {
        if (Operators[index] == ch)
            return true;
        index++;
    }
    return false;
}

bool isParen(const char ch) {
    bool isBracket = false;
    int index = 0;
    while (!isBracket && index < NUM_BRACKETS) {
        if (Parens[index]==ch)
            isBracket = true;
        index++;
    }
    return isBracket;
}

string convertInput(const string infixExpression) {
    int length = infixExpression.length();
    string postfixExpression;
    LinkedStack *stack = new LinkedStack();
    int position = 0;
    char ch = infixExpression.at(position);

    // while there is a character in the infix position
    while (position < length)
    {
        if (!isOperator(ch) && !isParen(ch)) // it is an operand
            // so append it to postfixExpression
            postfixExpression+=ch;
        else if (ch == '(')
            // push it onto the stack
            stack->push(ch);
        else if (isOperator(ch) || isParen(ch))
        {
            // if the stack is empty
            if (stack-> isEmpty() && !isParen(ch)){
                // push it onto the stack
                stack-> push(ch);
            }
            //  otherwise, pop operators of greater or equal precedence from
            //  the stack and append them to postfixExp. stop when
            //  you encounter either a "(" or an operator of lower precedence,
            //  or the stack becomes empty. Then, push it onto the stack
            else {
                // enforce precondition
                assert(!(stack->isEmpty()));
                bool again = false;
                do
                {
                    again = false;
                    char nextOpOnStack = stack->peek();
                    if (nextOpOnStack == '(')
                    {
                        // pop the open paren off the stack
                        stack-> pop();
                        // stop popping operators
//                        continue;
                    } else if (opPrecedence(ch, nextOpOnStack)) { //(nextOpOnStack >= ch) {
                        // append operator to postfix expression
                        postfixExpression+=nextOpOnStack;
                        // pop operator off stack
                        stack->pop();
                        // and continue
                        again = true;
                    } else {
                        again = false;
                    }
                } while ( again && !(stack->isEmpty()) );
                if (ch != ')')
                    stack->push(ch);
            }
        }
        //4. if you encounter a ")", pop operators off the stack and
        //   append them to postfixExp until you encounter the "(".
        else if(ch == ')')
        {
            // load the next operator on the stack
            bool again = false;
            do
            {
                again = false;
                char nextOpOnStack = stack->peek();
                if (nextOpOnStack == '(' )
                    // pop it off the stack
                    stack->pop();
                    // then continue past else
                    // note: again is still false;
                else if (stack->isEmpty())
                {
                    // append the next op on stack to the postfix expression
                    postfixExpression+=nextOpOnStack;
                    // pop the next op on stack off the stack
                    stack->pop();
                    // and continue
                    again = true;
                }
            } while (again);
        }
        if (++position < length)
            ch = infixExpression.at(position);
    }
    while (!stack->isEmpty()) {
        char nextOpOnStack = stack->peek();
        if (!isParen(nextOpOnStack))
            postfixExpression+=nextOpOnStack;
        stack->pop();
    }
    return postfixExpression;
}

//int compute(const char *postfixExpression)
int compute(const string postfixExpression) {
    LinkedStack *resultStack = new LinkedStack();
    char temp;

    // cycle through the postfixExpression
    int index = 0;
    while (index < postfixExpression.length())
    {
        // load ith element of postfixExpression (pfe)
        temp = postfixExpression[index];

        // if the ith element of the pfe is not an operator
        if (!(isOperator(temp)))
        {
            // push it onto the results stack
            resultStack->push(temp);
        }
        else // temp is an operator
        {
            char op2 = resultStack->peek();
            resultStack->pop();
            char op1 = resultStack->peek();
            resultStack->pop();
            // perform operation
            int result = 0;
            char r;
            switch (temp) {
                case '+':
                    result = (op1 - '0') + (op2 - '0');
                    resultStack->push(result + '0');
                    break;
                case '-':
                    result = (op1 - '0') - (op2 - '0');
                    resultStack->push(result + '0');
                    break;
                case '*':
                    result = (op1 - '0') * (op2 - '0');
                    resultStack->push(result + '0');
                    break;
                case '/':
                    result = (op1 - '0') / (op2 - '0');
                    resultStack->push(result + '0');
                    break;
            }
        }
        index++;
    }

    // the result has been computed and is the only
    // remaining character on the stack
    return (resultStack->peek()) - '0';
}

bool opPrecedence(const char ch, const char nextOpOnStack) {
    switch (ch) {
        case '*':
            if (nextOpOnStack == '+' || nextOpOnStack == '-')
                return false;
        case '/':
            if (nextOpOnStack == '+' || nextOpOnStack == '-')
                return false;
        case '+':
        case '-':
        default:
            return true;
            break;
    }
    return true;
}

/*
 ===========================
 SAMPLE RUN
 ===========================
 !!COMMENT!!:
 THE PRECIDENCE OF OPERATION IS OFF..  ALSO, OPTION 2
 FOR USER INPUT IS NOT RUNCTIONING PROPERLY.
 ============================
 Script started on Tue Mar 15 23:41:33 2016
 [?1034hbash-3.2$ ./a.out
 Main Menu:
 1. run Hardcoded Example
 2. run UserInput Example
 3. exit
 What would you like to do? 1
 converted = 242-*
 result = 4 should be 4
 converted2 = 23*2-
 result2 = 4 should be 4
 converted = 822+-3*2/
 result = 6 should be 4
 Main Menu:
 1. run Hardcoded Example
 2. run UserInput Example
 3. exit
 What would you like to do? 3
 bash-3.2$ exit
 exit

 Script done on Tue Mar 15 23:41:46 2016


 */
