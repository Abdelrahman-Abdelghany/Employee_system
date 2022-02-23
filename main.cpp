#include <bits/stdc++.h>

using namespace std;

const int MAX=1000;//no of employees in the company
string names[MAX];
int ages[MAX];
float salaries[MAX];
char gender[MAX];
int index=0;
//above operations simulate like a database of the company

void read_em()
{
    cout<<"Enter employee name : ";
    cin>>names[index];
    cout<<"Enter employee age : ";
    cin>>ages[index];
    cout<<"Enter employee salary : ";
    cin>>salaries[index];
    cout<<"Enter employee gender (M/F) : ";
    cin>>gender[index];
    ++index;
}

int menu()
{
    int choice=0;
    while(choice==0){
        cout<<"Enter your choice -> \n";
        cout<<"(1)Add new employee : \n";
        cout<<"(2)Print all employee : \n";
        cout<<"(3)Delete by age : \n";
        cout<<"(4)Update salary by employee name : \n";
        cout<<"(5)Exit menu : \n";
        cin>>choice;
        if(!(choice>=1&&choice<=5)){
            cout<<"Invalid Option, Please try again\n";
            choice=0;
        }
    }
    //pass value of choice to employee system function
    return choice;
}
//---------------------------------------------------------------

void print_em()
{
    cout<<"=======================================\n";
    for(int i=0;i<index;i++)
    {
        if(ages[i]!=-1)//make sure not to print deleted elements
            cout<<names[i]<<"  "<<ages[i]<<"  "<<salaries[i]<<"  "<<gender[i]<<endl;
    }
    cout<<"=======================================\n";
}

//---------------------------------------------------------------

void del_by_age_em()
{
    cout<<"Enter the range of ages that you want to delete : ";
    int start,en;
    cin>>start>>en;
    for(int i=start;i<en;i++)
    {
        if(start<=ages[i]&&ages[i]<=en)
        {
            ages[i]=-1;//reprsents deleted element
        }
    }
}

//---------------------------------------------------------------

void update_sal_by_name_em()
{
    cout<<"Enter name and salary : ";
    string name;
    float sal;
    bool found=false;
    cin>>name>>sal;
    for(int i=0;i<index;i++)
    {
        if(ages[i] != -1 && names[i] == name)
        {
            found=true;
            salaries[i]=sal;
            break;
        }
        else if(found==false)
        {
            cout<<"No employees with this name\a\n";
        }
    }
}

//---------------------------------------------------------------
void employee_sys()
{
    //this function to order the system
    while(true){
        int choice=menu();
        if(choice==1)
        {
            read_em();
        }
        else if(choice==2)
        {
            print_em();
        }
        else if(choice==3)
        {
            del_by_age_em();
        }

        else if(choice==4)
        {
            update_sal_by_name_em();
        }
        else
        {
            break;
        }
    }
}

int main()
{
    employee_sys();
}
