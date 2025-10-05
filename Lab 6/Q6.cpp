#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

class Expression 
{
private:
    char* cstack;
    int topC;
    int csize;
    int* istack;
    int topI;
    int isize;

public:
    Expression(int size) 
    {
        cstack = new char[size];
        istack = new int[size];
        csize = isize = size;
        topC = -1;
        topI = -1;
    }

    void pushChar(char ch)
    {
        if(topC < csize - 1)
        {
            cstack[++topC] = ch;
        }
        else 
        {
            cout << " Cant Push " << endl;
        }
        
    }

    char popChar() 
    {
        if(topC >= 0) 
        {
            return cstack[topC--];
        }
        
        return '\0';
    }

    char peekChar() 
    {
        if(topC >= 0)
        {
            return cstack[topC];
        }
        
        return '\0';
    }

    void pushInt(int val) 
    {
        if(topI < isize - 1)
        {
            istack[++topI] = val;
        }
        else
        {
            cout << " Cant Push " << endl;
        }
    }

    int popInt() 
    {
        if(topI >= 0)
        {
            return istack[topI--];
        }
        
        return 0;
    }

    int precedence(char op)
    {
        if(op == '+' || op == '-')
        {
            return 1;
        }
        
        if(op == '*' || op == '/')
        {
            return 2;
        }
        
        if(op == '^') 
        {
            return 3;
        }
        
        return 0;
    }

    bool isOperator(char ch)
    {
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    bool isDigit(char ch)
    {
        if(ch >= '0' && ch <= '9')
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    string reverseString(string s)
    {
        int n = s.length();
        for(int i = 0; i < n / 2; i++) 
        {
            char temp = s[i];
            s[i] = s[n-i-1];
            s[n-i-1] = temp;
        }
        return s;
    }

    string infixToPrefix(string infix)
    {
        infix = reverseString(infix);
        for(int i = 0; i < infix.length(); i++) 
        {
            if(infix[i] == '(') 
            {
                infix[i] = ')';
            }
            
            else if(infix[i] == ')')
            {
                infix[i] = '(';
            }
            
        }

        string prefix = "";
        for(int i = 0; i < infix.length(); i++) 
        {
            char ch = infix[i];
            if(isDigit(ch)) 
            {
                prefix += ch;
            }
            
            else if(ch == '(')
            {
                pushChar(ch);
            }
            
            else if(ch == ')') 
            {
                while(topC != -1 && peekChar() != '(')
                {
                    prefix += popChar();
                }
                
                popChar();
            }
            else if(isOperator(ch)) 
            {
                while(topC != -1 && ((precedence(peekChar()) > precedence(ch)) || 
                      (precedence(peekChar()) == precedence(ch) && ch != '^')))
                {
                    prefix += popChar();
                }
                pushChar(ch);
            }
        }

        while(topC != -1)
        {
            prefix += popChar();
        }
        
        prefix = reverseString(prefix);
        return prefix;
    }

    int evaluatePrefix(string prefix) 
    {
        prefix = reverseString(prefix);
        for(int i = 0; i < prefix.length(); i++) 
        {
            char ch = prefix[i];
            if(isDigit(ch)) 
            {
                pushInt(ch - '0');
            }
            
            else if(isOperator(ch))
            {
                int b = popInt();
                int a = popInt();
                int res = 0;
                
                if(ch == '+')
                {
                    res = a + b;
                }
                
                else if(ch == '-') 
                {
                    res = a - b;
                }
                
                else if(ch == '*') 
                {
                    res = a * b;
                }
                
                else if(ch == '/') 
                {
                    res = a / b;
                }
                
                else if(ch == '^') 
                {
                    res = pow(a, b);
                }
                
                pushInt(res);
            }
        }
        return popInt();
    }
};

int main() 
{
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    Expression Exp(infix.length());
    string prefix = Exp.infixToPrefix(infix);
    int result = Exp.evaluatePrefix(prefix);

    cout << "Prefix: " << prefix << endl;
    cout << "Evaluation: " << result << endl;

    return 0;
}
