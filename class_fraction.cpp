#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b)
    {
        if (b==0)
            return a;
        else
            return gcd(b,a%b);
    }
class Fraction{
private:
    int Sorat;
    int Makhraj;

public:
    Fraction(int a=0, int b=1){
        this->Sorat=a;
        if (b==0)
        {
            cout<<"Cannot Assainment Zero to Domenator\n";
            this->Makhraj=1;
        }

        else
        {
            this->Makhraj=b;
        }

    }



    friend int gcd(int a, int b);

    void Simplify()
    {
        int com=gcd(Sorat,Makhraj);

        this->Sorat/=com;
        this->Makhraj/=com;
    }
    Fraction operator +(const Fraction & Other)
    {
        Fraction Result;
        Result.Sorat=Sorat*Other.Makhraj+Other.Sorat*Makhraj;
        Result.Makhraj=Makhraj*Other.Makhraj;
        Result.Simplify();

        return Result;
    }
        Fraction operator -(const Fraction & Other)
    {
        Fraction Result;
        Result.Sorat=Sorat*Other.Makhraj-Other.Sorat*Makhraj;
        Result.Makhraj=Makhraj*Other.Makhraj;
        Result.Simplify();

        return Result;
    }

    friend ostream & operator <<(ostream & out,const Fraction & Frac)
    {
        out<<Frac.Sorat<<"/"<<Frac.Makhraj<<endl;
        return out;
    }

};

int main()
{
    Fraction F1(3,7);
    Fraction F2(8,3),F3;
    F1.Simplify();
    cout<<F1;
    F3=F1+F2;
    cout<<F3;
}
