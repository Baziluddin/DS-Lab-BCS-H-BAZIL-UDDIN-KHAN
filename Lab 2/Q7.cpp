#include <iostream>
using namespace std;

void Avgsalary(double ** Salaries,int TotalDepartments,int Departments[])
{
    for(int y =0; y< TotalDepartments;y++)
    {
        for(int u =0; u< Departments[y];u++)
        {
            double Salary;
            cout << " Enter Salary "  << endl;
            cin >> Salary;
            Salaries[y][u] = Salary;
        }
    }
    
    double * AverageSalary = new double[TotalDepartments];
    
    for(int y =0; y< TotalDepartments;y++)
    {
        double Total =0.0;
        for(int u =0; u< Departments[y];u++)
        {
          Total = Total + Salaries[y][u];
        }
        AverageSalary[y] =(Total/Departments[y]);
    }
    
    cout << " Average Max Salary " << endl;
    double max =0.0;
    for(int y =0; y<TotalDepartments;y++)
    {
        if(max < AverageSalary[y])
        {
            max = AverageSalary[y];
        }
    }
    
    cout << " Max Avg Salary Of Department is " << max << endl;
    
    delete [] AverageSalary;
}


void HighestSalary(double ** Salaries,int TotalDepartments,int Departments[])
{
    int MaxSalary[TotalDepartments];
    for(int y =0; y< TotalDepartments;y++)
    {
        double salary =0.0;
        for(int u =0; u< Departments[y] ; u++)
        {
            if(salary < Salaries[y][u])
            {
                salary = Salaries[y][u];
            }
        }
        MaxSalary[y] = salary;
    }
    
    cout << " Max Salaries Of Department is " << endl;
    
    for(int y =0; y< TotalDepartments;y++)
    {
        cout << " Department " << y+1<<" Max Salary is " << MaxSalary[y] << endl;
    }
    
}


int main()
{
    int TotalDepartments;
    cout << " Enter Total Departments " << endl;
    cin >> TotalDepartments;
    
    int Departments[TotalDepartments];
    for(int y =0; y<TotalDepartments;y++)
    {
        int Totalemployee;
        cout << " Enter enployee  For  Registered Department : "  << endl;
        cin >> Totalemployee;
        Departments[y] = Totalemployee;
    }
    
    double ** Salaries;
    Salaries  = new double*[TotalDepartments];
    
    for(int y =0; y<TotalDepartments;y++)
    {
       Salaries[y] = new double[Departments[y]];
    }
    
    Avgsalary(Salaries, TotalDepartments,Departments);
    
    HighestSalary(Salaries,TotalDepartments,Departments);
    
    for(int y =0; y<TotalDepartments;y++)
    {
        delete[] Salaries[y];
    }
    
    delete [] Salaries;
    return 0;
}
