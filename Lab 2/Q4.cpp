#include <iostream>
using namespace std;

double TotalExpenses(double arr[],int n)
{
    double Total =0.0;
    for(int y =0; y<n;y++)
    {
        Total = Total + arr[y];
    }
    return Total;
}

double AverageExpenses(double arr[],int n)
{
    double Total =0.0;
    for(int y =0; y<n;y++)
    {
        Total = Total + arr[y];
    }
    return (Total/n);
}


int main()
{
    int n;
    cout << " Enter Size for 1d Array " << endl;
    cin >> n;
    
    double * array;
    array = new double[n];
    
    for(int y =0; y<n;y++)
    {
        double Expenses;
        cout << " Enter Expenses For Month  " << y+1 << endl;
        cin >> Expenses;
        array[y] = Expenses;
    }
    
    string Choice;
    cout << " Do You Want To Resize Array by Adding More Months ?(Yes/No) " << endl;
    cin >> Choice;
    if(Choice == "Yes")
    {
        int ExtraMonths;
        cout << " Tell Extra months To add " << endl;
        cin >> ExtraMonths;
        double * Extraarray = new double [n+ExtraMonths];
        
        for(int y =0;y<n;y++)
        {
            
           Extraarray[y] = array[y];
        }
        delete [] array;
        array = Extraarray;
        
        
        for(int i =n; i< n + ExtraMonths;i++)
        {
           double Expenses;
           cout << " Enter Expenses For Month  " << i+1 << endl;
           cin >> Expenses;
           Extraarray[i] = Expenses;
        }
        n = n + ExtraMonths;
    }
    double Total = TotalExpenses(array,n);
    cout << " Total Expenses For N " << n << " months is " << Total << endl;
    double Average = AverageExpenses(array,n);
    cout << " Average Expenses For N " << n << " months is " << Average << endl;
    
    delete[] array;
    
    return 0;
}
