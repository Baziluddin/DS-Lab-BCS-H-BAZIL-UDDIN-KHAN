#include <iostream>
using namespace std;

int SearchBookid(int ** Books,int TotalCategories,string Category[],int CategoryBooks[])
{
    int Found = -1;
    int SearchId;
     cout << " Enter Book id For Search " << endl;
    cin >> SearchId;
    string category ;
    for(int y =0; y<TotalCategories;y++)
    {
      
       for(int u =0; u< CategoryBooks[y];u++)
       {
            if(SearchId == Books[y][u]){
                     category = Category[y];
                      Found = 1;
                      break;

             }
       }
    }
    if (Found == 1) 
    {
    cout << " Search Book Id Found In Category :: " << category << endl;
     }
    
    return Found;
}
    



int main()
{
    int TotalCategories;
    cout << " Enter Total Category " << endl;
    cin >> TotalCategories;;
    
    string *Category = new string[TotalCategories];
    int *CategoryBooks = new int[TotalCategories];
    for(int y =0; y<TotalCategories;y++)
    {
        string category;
        cout << " Enter Category Name : "  << endl;
        cin >> category;
        
        int TotalBooks;
        cout << " Enter Total Books For Category =  " << category  << endl;
        
        cin >> TotalBooks;
        
        
        CategoryBooks[y] = TotalBooks;
        Category[y] = category;
        
    }
    
    int ** Books;
    Books  = new int*[TotalCategories];
    
    for(int y =0; y<TotalCategories;y++)
    {
       Books[y] = new int[CategoryBooks[y]];
    }

    for(int y =0; y<TotalCategories;y++)
    {
      
       for(int u =0; u< CategoryBooks[y];u++)
       {
                int books;
               cout << " Enter Book ids for " << Category[y] << endl;
              cin >> books;
              Books[y][u]  = books;

        }
    }

    int Found = SearchBookid(Books,TotalCategories,Category,CategoryBooks);
    
    if(Found == -1)
     {
     cout << " Book Id Not Found " << endl;
     }

    for(int y =0; y<TotalCategories;y++)
    {
        delete[] Books[y];
    }
    
    delete [] Books;
    delete[] Category;
    delete[] CategoryBooks;
    return 0;
} 
