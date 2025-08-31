#include <iostream>
using namespace std;

double HottestDay(double * arr,int n)
{
    double Hottestday = 0.0;
    int index =0;
    for(int y =0; y< n; y++)
    {
           if(Hottestday < arr[y])
           {
               Hottestday = arr[y];
               index = y;
           }
    }
    
    cout << " Day : " << index +1 << " Hottest Temperature is " << Hottestday << endl;
    
    return Hottestday;
}

double ColdestDay(double * arr,int n)
{
    double coldestday = arr[0];
    int index =0;
      for(int y =1; y< n; y++)
    {
           if(coldestday > arr[y])
           {
               coldestday = arr[y];
               index = y;
           }
    }
    cout << " Day : " << index +1 << " Coldest Temperature is " << coldestday << endl;
    return coldestday;
}

double AverageTemperature(double * arr,int n,int m)
{
    double Total=0.0;
    for(int y =0; y< n; y++)
    {
        
          Total = Total + arr[y];

    }
    return (Total/n);
}

int main() 
{
    int n;
    cout << " Enter N(Days)  " << endl;
    cin >> n;
    
    int m;
    cout << " Enter M(times)  " << endl;
    cin >> m;
    
    double ** Temperature;
    Temperature = new double*[n];
    
    for(int y =0; y< n; y++)
    {
        Temperature[y] = new double[m];
    }
    
    for(int y =0; y< n; y++)
    {
        
        for(int i =0; i < m ; i++)
        {
           
           double Time;
           cout << " Enter Temperature  " << endl;
           cin >> Time;
           Temperature[y][i] = Time;
        }
    }
    
    double *DayAverage = new double[n];
    int Total =0;
    for(int y=0;y<n;y++)
    {
        double Total=0;
        for(int i=0;i<m;i++)
        {
            Total = Total + Temperature[y][i];
           
        }
        DayAverage[y]= (Total / m);
    }
    
    double avg = AverageTemperature(DayAverage,n,m);
    cout << " Avg Temperature is " << avg << endl;
    double hottest = HottestDay(DayAverage,n);
    cout << " Hottest Day is " << hottest << endl;
    double coldest = ColdestDay(DayAverage,n);
    cout << " Coldest  is " << coldest << endl;
    
    for(int y =0; y<n;y++)
    {
        delete [] Temperature[y];
    }
    delete [] Temperature;
    delete []DayAverage;
    
    return 0;
}
