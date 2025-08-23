#include<iostream>
using namespace std;

class BankAccount
{
    private:
        int balance;

    public:
        BankAccount()
        {balance = 0;}

        BankAccount(int bal)
        {
            balance =0;
            balance  = balance+bal;}

        void Balance()
        {cout<<"balance is "<<balance<<endl;}

        BankAccount(BankAccount & man)
        {
            balance = man.balance;
        }
        
        void deduct(int bal)
        {
            if(bal >=0&& bal<=balance)
            {
                balance = balance - 200;
            }
            else
            {
                cout << " Wrong Entry. "<<endl;
            }
        }
};
int main()
{
    BankAccount account1;
    cout << "Account 1 Balance"<<endl;
    account1.Balance();
    BankAccount account2(1000);
    cout << "Account 2 Balance"<<endl;
    account2.Balance();
    BankAccount account3(account2);
    account3.deduct(200);
    cout << "Account 3 Balance"<<endl;
    account3.Balance();
    cout << "Account 2 Balance"<<endl;
    account2.Balance();
}
