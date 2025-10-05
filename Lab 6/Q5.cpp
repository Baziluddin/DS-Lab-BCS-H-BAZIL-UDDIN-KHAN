#include <iostream>
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


    void pushChar(char c) 
    { 
        if(topC < csize-1) 
        {
          cstack[++topC] = c; 
        }
        else
        {
            cout << " Cant Push " << endl;
        }
    }
    
    char popChar()
    { 
        if(topC == -1)
        {
            return ' ';
        }
        else
        {
            return cstack[topC--];
        }
    }
    
    char peekChar() 
    { 
        if(topC == -1)
        {
            return ' ';
        }
        else
        {
            return cstack[topC];
        }
    }
    
    bool isCharEmpty() 
    { 
       return topC == -1;
    }


    void pushInt(int x)
    {
        if(topI < isize-1) 
        {
          istack[++topI] = x; 
        }
        
        else
        {
            cout << " Cant Push " << endl;
        }
        
    }
    
    int popInt() 
    { 
        if(topI == -1)
        {
            return -1;
        }
        else
        {
            return istack[topI--];
        }
        
    }

    int precedence(char op) 
    {
        if(op == '^')
        {
            return 3;
        }
        
        if(op == '*' || op == '/')
        {
            return 2;
        }
        
        if(op == '+' || op == '-')
        {
            return 1;
        }
        
        return 0;
    }

    bool isOperator(char c) 
    {
        if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^')
        {
            return true;
        }
        else
        {
            return false;
        }
        
    }

    int power(int base, int exp) 
    {
        int result = 1;
        for(int i=0;i<exp;i++) 
        {
            result = result * base;
        }
        
        return result;
    }

    void infixToPostfix(char infix[], char postfix[])
    {
        int k = 0;
        for(int i=0; infix[i] != '\0'; i++)
        {
            char c = infix[i];
            if(c >= '0' && c <= '9')
            {
                 postfix[k++] = c;
            }
            
            else if(c == '(')
            {
                pushChar(c);
            }
            
            else if(c == ')') 
            {
                while(!isCharEmpty() && peekChar() != '(')
                {
                    postfix[k++] = popChar();
                }
                popChar();
            } 
            else if(isOperator(c)) 
            {
                while(!isCharEmpty() && precedence(peekChar()) >= precedence(c))
                {
                    postfix[k++] = popChar();
                }
                pushChar(c);
            }
        }
        while(!isCharEmpty())
        {
            postfix[k++] = popChar();
        }
        postfix[k] = '\0';
    }

    int evaluatePostfix(char postfix[]) 
    {
        for(int i=0; postfix[i] != '\0'; i++) 
        {
            char c = postfix[i];
            if(c >= '0' && c <= '9')
            {
                pushInt(c - '0');
            }
            else if(isOperator(c))
            {
                int b = popInt();
                int a = popInt();
                if(c == '+')
                {
                    pushInt(a + b);
                } 
                else if(c == '-')
                { 
                    pushInt(a - b);
                }
                else if(c == '*') 
                {
                    pushInt(a * b);
                }
                
                else if(c == '/')
                {
                    pushInt(a / b);
                }
                
                else if(c == '^')
                {
                    pushInt(power(a,b));
                }
            }
        }
        return popInt();
    }
    
    ~Expression()
    { 
        delete[] cstack;
        delete[] istack;
    }

};

int main()
{
    int Size;
    cout << "Enter Max size for expression: ";
    cin >> Size;
    Size = Size *10;

    Expression expr(Size);
    char* infix = new char[Size];
    char* postfix = new char[Size];

    cout << "Enter Infix Expression: ";
    cin >> infix;

    expr.infixToPostfix(infix, postfix);
    cout << "Postfix Expression: " << postfix << endl;

    int result = expr.evaluatePostfix(postfix);
    cout << "Evaluated Result: " << result << endl;

    delete[] infix;
    delete[] postfix;
    return 0;
}
