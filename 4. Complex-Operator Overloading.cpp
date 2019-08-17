//Program for operator overloading using friend function for all the operators
#include <iostream>
using namespace std;

class complex
{
    int real,img;
public:
//friend function is used for all the operators('>>' , '<<' , '+' , '*')
//functions are defined inside the class and declared outside the class
    friend istream& operator>>(istream&, complex &c);
    friend ostream& operator<<(ostream&, complex c);
    friend complex operator+(complex,complex);
    friend complex operator*(complex,complex);
};
//function declaration outside the class
istream& operator>>(istream& din,complex &c)
{
    cout<<"\nPlease enter Real Part : ";
    din>>c.real;
    cout<<"\nPlease enter Imaginary Part : ";
    din>>c.img;
    return din;
}
//function declaration outside the class
ostream& operator<<(ostream& dout, complex c)
{
    dout<<"\n Number is = "<<c.real<<"+"<<c.img<<"i";
    return dout;
}
//friend keyword is not used while declaring  
complex operator+(complex c1,complex c2)
{
    complex a;
    a.real=c1.real+ c2.real;
    a.img=c1.img + c2.img;
    return a;
}
//friend keyword is not used while declaring
complex operator*(complex c1,complex c2 )
{
    complex a1;
    a1.real= ((c1.real*c2.real)-(c1.img*c2.img));
    a1.img= ((c1.real*c2.img)+ (c1.img * c2.real));
    return a1;
}

int main() {
    complex c1,c2,c3,c4;
    cin>>c1>>c2;
    c3=c1+c2;
    cout<<c3;
    c4=c1*c2;
    cout<<c4;
    return 0;
}
