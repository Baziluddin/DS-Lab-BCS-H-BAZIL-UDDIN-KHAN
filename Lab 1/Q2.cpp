#include<iostream>
using namespace std;

class Exam
{
private:
    string* studentname;
    string* examdate;
    int* score;

public:
    Exam(string n, string e, int s)
    {
        studentname = new string(n);
        examdate = new string(e);
        score = new int(s);
    }

    void setAtt(string n,string e,int s)
    {
        *studentname = n;
        *examdate = e;
        *score = s;
    }
    
    ~Exam() //Due To destructor and due to shallow copy we will get issue like Segmentation fault in output.
    {
    delete studentname;
    delete examdate;
    delete score;
        
    }

    void display()
    {
        cout << "name:"<< *studentname << " exam:"<< *examdate << " score:"<< *score << endl;
    }
};

int main()
{
    string e;
    cout << " enter name" << endl;
    cin >> e;

    string ex;
    cout << " enter exam" << endl;
    cin >> ex;

    int f;
    cout << " enter score" << endl;
    cin >> f;

    Exam E(e,ex,f);
     E.display();
      
    Exam E1 = E;
    E1.display();
    
}
