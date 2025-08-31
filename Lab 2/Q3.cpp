#include <iostream>
using namespace std;

void AvgMarks(double ** Marks,int TotalStudents,int RegCourses[])
{
    for(int y =0; y< TotalStudents;y++)
    {
        for(int u =0; u< RegCourses[y];u++)
        {
            double marks;
            cout << " Enter Marks For Student  " << y+1 << endl;
            cin >> marks;
            Marks[y][u] = marks;
        }
    }
    
    double * AverageMarks = new double[TotalStudents];
    
    for(int y =0; y< TotalStudents;y++)
    {
        double Total =0.0;
        for(int u =0; u< RegCourses[y];u++)
        {
          Total = Total + Marks[y][u];
        }
        AverageMarks[y] =(Total/RegCourses[y]);
    }
    
    cout << " Average Marks " << endl;
    for(int y =0; y<TotalStudents;y++)
    {
       cout << " Student " << y+1 << " Average Marks : " << AverageMarks[y] << endl;
    }
    
    delete [] AverageMarks;
}


int main()
{
    int TotalStudents;
    cout << " Enter Total Students " << endl;
    cin >> TotalStudents;
    
    int RegCourses[TotalStudents];
    for(int y =0; y<TotalStudents;y++)
    {
        int Cours;
        cout << " Enter Courses Registered For Students : " << y+1 << endl;
        cin >> Cours;
        RegCourses[y] = Cours;
    }
    
    double ** Marks;
    Marks = new double*[TotalStudents];
    for(int y =0; y<TotalStudents;y++)
    {
       Marks[y] = new double[RegCourses[y]];
    }
    
    AvgMarks(Marks, TotalStudents,RegCourses);
    
    for(int y =0; y<TotalStudents;y++)
    {
        delete[] Marks[y];
    }
    
    delete [] Marks;
    return 0;
}
