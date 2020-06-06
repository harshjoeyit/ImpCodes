#include<bits/stdc++.h>
using namespace std;

class bill
{
    public:

    int food;
    float shopping;

    // constructor 
    bill( int f = 0 , float s = 0.0 ): food(f) , shopping(s) { }

    // operations 
    bill operator+( const bill& rhs )       // adds the correspoding fields in the class objects 
    {
        bill b;
        b.food = food + rhs.food;
        b.shopping = shopping + rhs.shopping;
        return b;
    }

    bill operator++()                       // pre increment  
    {
        food = food + 1;
        shopping = shopping + 0.1;
        return *this;
    }

    bill operator++(int)                    // post increment , additional parameter to distinguish the pre increment functionand this function 
    {
        bill b = *this;
        ++*this;                             
        return b;
    }

    int operator[](int i)                       // subscript operator 
    {
        if(i == 1)
            return food;
        else
            return shopping;
    }

    ostream &operator<<( ostream &os )          // <<
    {
        os<<endl<<"food: "<<food<<"\nshopping: "<<shopping<<endl;
        return os;
    }

    istream &operator>>( istream &in )           // >> 
    {
        int f;
        float s;

        cout<<"\nenter food , shopping: \n";
        in>>f>>s;

        if(in)                                    //if input opeartion in previous line is successful
        {
            food = f;
            shopping = s;
        }

        return in;
    }


    void getbill()
    {
        cout<<"food: "<<food<<"\nshopping: "<<shopping<<endl;
    }

    
};

// no member function operation 
// if ssame operation functions are defined then the meber function takes the precedence 
bill operator-( const bill& lhs , const bill& rhs )       // adds the correspoding fields in the class objects 
{
    cout<<"non member - function called: "<<endl;
    bill b;
    b.food = lhs.food - rhs.food;
    b.shopping = lhs.shopping - rhs.shopping;
    return b;
}


bool operator==( const bill& lhs , const bill& rhs )      // checks if the objects fields are wxactly the same or not 
{
        return ( (lhs.food == rhs.food) && (lhs.shopping == rhs.shopping) );
}

bool operator!=( const bill& lhs , const bill& rhs )
{
    return !( lhs == rhs );         // calls the == operator function
}



int main()
{
    bill B1(10,2.3);
    bill B2(20,3.2);

    B1.getbill();
    B2.getbill();
    B1 = B1 + B2;           // member function called 
    
    B1.getbill();

    cout<<"food: "<<B1[1]<<endl;
    cout<<"shopp: "<<B1[2]<<endl;

    ++B1;

    B1.getbill();

    bill B3(1,3.2) , B4(1,3.2) ;
    bool b = B3 != B4;
    cout<<( (b==1) ? "unequal" : "equal" );

 
    B1>>cin;            // way to use the >> ''          ''             ''

    B1<<cout;           // way to call the << operator member function 


    bill Bill_diff = B3 + B4;
    Bill_diff.getbill();


    // testing the increment operators

    bill B11(10,2.3);
    bill B22(20,6.5);

    bill B33 = B11++;
    B11.getbill();
    B33.getbill();
    
    bill B44 = ++B22;
    B22.getbill();
    B44.getbill();
}