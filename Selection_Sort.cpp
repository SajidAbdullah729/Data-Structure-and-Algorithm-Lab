
#include<iostream>
#include<string>
using namespace std;
struct student
{
    int place;
    int id;
    string name;
} stud[100];

void swappp( struct student &A, struct student &B){
    student temp = A;
    A = B;
    B = temp;
}

template<typename T>
void swapp(T &a,T &b)
{
    T temp=a;
    a=b;
    b=temp;
}


void insertData()
{
    stud[0].place = 5;
    stud[0].id = 35;
    stud[0].name = "Jolil";

    stud[1].place = 6;
    stud[1].id = 45;
    stud[1].name = "Montu";

    stud[2].place = 1;
    stud[2].id = 63;
    stud[2].name = "Galib";

    stud[3].place = 4;
    stud[3].id = 56;
    stud[3].name = "Niloy";

    stud[4].place = 2;
    stud[4].id = 60;
    stud[4].name = "Adnan";

    stud[5].place = 3;
    stud[5].id = 14;
    stud[5].name = "Rais";
}

void printList()
{
    cout<<"place\tid\tname\n";
    for(int i=0; i<6; i++)
    {
        cout<<stud[i].place<<"\t"<<stud[i].id<<"\t"<<stud[i].name<<endl;
    }
}
void selectionSort()
{
    for(int i=0; i<6; i++)
    {
        int idx=i;
        for(int j=i+1; j<6; j++)
        {
            if(stud[idx].id>stud[j].id)
            {
                idx=j;
            }
        }
      swappp(stud[idx],stud[i]);
    }
}
int binSer(int id)
{
    int left=1;
    int right=6;
    int f=0;
    int place;
    while(left<=right)
    {
        int mid=(left+right)/2;
        if(stud[mid].id==id)
        {
            f=1;
            place=stud[mid].place;
            break;
        }
        else if(stud[mid].id>id)
        {
            right=mid-1;
        }
        else if(stud[mid].id<id)
        {
            left=mid+1;
        }
    }
    if(f) return place;
    else return -1;
}
int main()
{
    insertData();
    cout<<"*************Your unsorted list*************"<<endl;
    printList();
    selectionSort();
    cout<<"*************Your sorted list*************"<<endl;
    printList();
    int x;
    cout<<"Enter your student id: ";
    cin>>x;

    cout<<"Given student place is "<<binSer(x)<<endl;
    return 0;
}
