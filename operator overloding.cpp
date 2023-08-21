#include<iostream>
using namespace std;
class Person
{
    private:
        int age;
        int rank;
    public:
    Person (int x,int y)
    {
        cout<<"parameterized constructor call:"<<endl;
        age=x;
        rank=y;
    }
    Person(const Person &p)
    {
        cout<<"Copy Constructor call:"<<endl;
        age=p.age;
        rank=p.rank;

    }
    void display()

    {

        cout<<"Display fun call:"<<endl<<"Person age is "<<age<<" and rank is "<<rank<<endl;
    }
    Person()
    {
        cout<<"Non-parameterized constructor:"<<endl;

    }
    Person operator++()
    {
        cout<<"pre-increment operator call:"<<endl;
        Person t;
        t.age=++age;
        t.rank=++rank;
        return t;
    }
    Person operator++(int )//this int is dummy to differentiate b/w pre and post increment.
    {
        cout<<"post-increment operator call:"<<endl;
        Person t;
        t.age=age++;
        t.rank=rank++;
        return t;
    }
    Person operator+(const Person X)
    {
        cout<<"+ operator call:"<<endl;
        Person temp;
        temp.age=age+X.age;
        temp.rank=rank+X.rank;
        return temp;

    }
    void setdata()
    {
        cout<<"Set data function call:"<<endl;
        cin>>age>>rank;
    }
    friend ostream& operator<<(ostream &os,Person p);
    friend istream& operator>>(istream &is,Person &X);

};
ostream & operator<<(ostream &os,Person p)
{
    os<<"insertion operator call:" <<endl;
    os<<"Person age is "<< p.age<<" and rank is "<<p.rank<<endl;
    return os;
}
istream& operator>>(istream &is,Person &X)
 {
     cout<<"Extraction operator call:"<<endl;
     is>>X.age;
     is>>X.rank;
     return is;
 }

int main()
{
    Person p1(20,21);
    Person p2=p1;
    Person p3;
    cout<<p1<<p2;
    Person p6=++p2;
    cout<<p6;
    Person p4=p2;
    cin>>p3;
    cout<<p3<<p2;
    Person p5 = p1+p2;
    cout<<p5;
    cout<<++p6<<p6++<<p6;


}
