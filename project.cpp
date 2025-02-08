#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

template <class A, int Max>
class Stack
{
private:
    int top;
    A items[Max];

public:
    Stack()
    {
        top = -1;
    }

    bool empty()
    {
        if (top == -1)
            return true;
        return false;
    }

    bool full()
    {
        if (top == Max - 1)
            return true;
        return false;
    }

    bool push(A c)
    {
        if (!full())
        {
            items[++top] = c;
            return true;
        }
        else
            return false;
    }

    A pop()
    {
        if (!empty())
            return items[top--];
        else
        {
            cout << "Stack is empty! " << endl;
            exit(1);
        }
    }

    A stackTop()
    {
        if (!empty())
            return items[top];
        else
        {
            cout << " stack is empty. " << endl;
            exit(1);
        }
    }
};


bool prcd(char top, char current)
{
    if (top == '_' && (current == '+' || current == '-' || current == '*' || current == '/' || current == '^'))
        return false;

    else if ((top == '+' || top == '-') && (current == '+' || current == '-'))
        return false;

    else if ((top == '*' || top == '/') && (current == '*' || current == '/'))
        return false;

    else if ((top == '*' || top == '/') && (current == '-' || current == '+'))
        return false;

    else if (top == '^' && current == '^')
        return true;

    else if ((top == '^') && (current == '+' || current == '-' || current == '*' || current == '/'))
        return false;

    else if (top == '!' && (current == '+' || current == '-' || current == '*' || current == '/' || current == '^'))
        return false;

    else if ((top == '^' || top == '*' || top == '/' || top == '+' || top == '-') && (current == '!'))
        return true;

    else if (top == '!' && current == '!')
        return false;

    else if(top == '_' && current == '!')
        return false;

    return true;
}


bool isNegativeSign(string infix, int index)
{
    if (infix[index] != '-')
    {
        return false;
    }

    else if (index == 0 || infix[index - 1] == '(' ||
             infix[index - 1] == '+' || infix[index - 1] == '-' ||
             infix[index - 1] == '*' || infix[index - 1] == '/' ||
             infix[index - 1] == '^')
    {
        return true;
    }

    else
    {
        return false;
    }
}


string preprocessExpression(string infix)
{
    string processed;
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix.substr(i, 3) == "sin")
        {
            processed += '$';
            i += 2; // Skip the next two characters
        }
        else if (infix.substr(i, 3) == "cos")
        {
            processed += '#';
            i += 2; // Skip the next two characters
        }
        else if (infix[i] == '-')
        {
            // Use isNegativeSign to determine whether to replace '-' with '_'
            if (isNegativeSign(infix, i))
            {
                processed += '_';
            }
            else
            {
                processed += '-';
            }
        }

        else
        {
            processed += infix[i];
        }
    }
    return processed;
}


string infixToPostfix(string infix)
{
    char postfix[100];
    Stack<char, 100> s;
    int i = 0, j = 0;

    while (infix[i] != '\0')
    {
        if (isalpha(infix[i]) || isdigit(infix[i])) // Operand, append to postfix
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            s.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (!s.empty() && s.stackTop() != '(')
            {
                postfix[j++] = s.pop();
            }
            s.pop(); // Pop the '('

            // Check if a function (like # or $) is at the "stack top"
            if (!s.empty() && (s.stackTop() == '#' || s.stackTop() == '$'))
            {
                postfix[j++] = s.pop(); // Add the function to the postfix as a $ or #
            }
        }
        else
        {
            // Handle operators
            while (!s.empty() && !prcd(s.stackTop(), infix[i]))
            {
                postfix[j++] = s.pop();
            }
            s.push(infix[i]);
        }
        i++;
    }

    // Pop remaining elements from the stack
    while (!s.empty())
    {
        postfix[j++] = s.pop();
    }

    postfix[j] = '\0'; // Null-terminate the postfix string
    return postfix;
}


int charToInt(char ch)
{
    return ch - '0';
}


void getValue(string pfix, char variables[], int values[], int &count)
{
    count = 0;

    for (int i = 0; i < pfix.length(); i++)
    {
        if (isdigit(pfix[i]))
        {
            // Convert the digit character to an integer and store it
            int numValue = charToInt(pfix[i]); 
            variables[count] = pfix[i];      
            values[count] = numValue;        
            count++;
        }

        if (isalpha(pfix[i]))
        {
            // Check if the variable is already assigned a value
            bool alreadyAssigned = false;
            for (int j = 0; j < count; j++)
            {
                if (variables[j] == pfix[i])
                {
                    alreadyAssigned = true;
                    break;
                }
            }

            // If not already assigned, prompt for input and store the value
            if (!alreadyAssigned)
            {
                variables[count] = pfix[i]; // Store the variable
                cout << pfix[i] << " = ";   // Prompt for input
                cin >> values[count];       // Store the value
                count++;                    // Increment variable count
            }
        }
    }
}


int factorial(int n)
{
    
    if (n < 0)
    {
        cout << "Factorial is not defined for negative numbers." << endl;
        exit(1);
    }

    int f = 1;
    for (int i = 1; i <= n; i++)
    {
        f *= i;
    }
    
    return f;
}


float evaluatePostfix(string pfix, char variables[], int values[], int count)
{
    Stack<float, 100> s;

    for (int i = 0; i < pfix.length(); i++)
    {
        if (isalpha(pfix[i]) || isdigit(pfix[i])) // Operand
        {
            // Find the variable in the variables array and push its value onto the stack
            for (int j = 0; j < count; j++)
            {
                if (variables[j] == pfix[i])
                {
                    s.push(values[j]);
                    break;
                }
            }
        }
        else // Operator
        {
            float val, val1, val2;

            switch (pfix[i])
            {
            case '!': // Factorial operator
                val = s.pop();
                s.push(factorial(val));
                break;

            case '$': // sin operator
                val = s.pop();
                s.push(sin(val * M_PI / 180.0)); // Ensure radians by converting to float
                break;

            case '#': // cos operator
                val = s.pop();
                s.push(cos(val * M_PI / 180.0)); // Ensure radians by converting to float
                break;

            case '_': // negative operator
                val = s.pop();
                s.push((-1) * val);
                break;

            case '+': // Addition
                val2 = s.pop();
                val1 = s.pop();
                s.push(val1 + val2);
                break;

            case '-': // Subtraction
                val2 = s.pop();
                val1 = s.pop();
                s.push(val1 - val2);
                break;

            case '*': // Multiplication
                val2 = s.pop();
                val1 = s.pop();
                s.push(val1 * val2);
                break;

            case '/': // Division
                val2 = s.pop();
                val1 = s.pop();
                s.push(val1 / val2);
                break;

            case '^': // Exponentiation
                val2 = s.pop();
                val1 = s.pop();
                s.push(pow(val1, val2));
                break;

            default: // Unknown operator
                cout << "Unknown operator encountered: " << pfix[i] << endl;
                exit(1);
            }
        }
    }

    // Final result is the only value left in the stack
    return s.pop();
}


int main()
{
    char infix[100];
    cout << "Enter infix expression: ";
    cin >> infix;

    string processedInfix = preprocessExpression(infix);

    string postfix = infixToPostfix(processedInfix);
    cout << "Postfix expression: " << postfix << endl;

    char variables[100];
    int values[100];
    int count = 0;

    getValue(postfix, variables, values, count);

    float result = evaluatePostfix(postfix, variables, values, count);
    cout << "Answer of the expression: " << result << endl;
}