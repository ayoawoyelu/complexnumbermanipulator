//
//  Complex.cpp
//  
//
//  Created by Ayomide Awoyelu on 2015-12-30.
//
//

// A SIMPLE PROGRAM TO AID MY COMPUTATION OF COMPLEX NUMBERS

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
struct rectangular{                                                                 // A structure that defines a complex number in its rectangular form
    float real;                                                                     // The real part of the complex number
    float imaginary;                                                                // The Imaginary part of the complex number.
};

struct polar{                                                                       // A structure that defines a complex number in its polar form
    float magnitude;                                                                // The magnitude of a complex number
    float angle;                                                                    // The angle of a complex number
};



void print_rectangle(float r, float i){                                             // Printing function for Rectangular form
    if (i<0) {
        cout<<r<<i<<"i"<<endl;
    }
    else {
        cout<<r<<"+"<<i<<"i"<<endl;
    }
}

void print_polar(float magnitude, float angle){                                     // Printing Function for Polar form
    cout<<magnitude<<"∠"<<angle<<"°"<<endl;
}

void rect_pol(float real, float imaginary){                                         // Function for converting from rectangular to polar form
    float mag= sqrt((real*real)+(imaginary*imaginary));                             // Magnitude
    float argument = atan2(imaginary,real)*57.29577951;                             // Argument
    print_polar(mag, argument);                                                     // Calling the printing function
    
}

void pol_rect(float magnitude, float argument ){                                    // Function for converting from polar form to rectangular form
    float real = magnitude*cos(argument*0.01745329);                                // real part
    float imaginary = magnitude*sin(argument*0.01745329);                           // Imaginary part
    print_rectangle(real, imaginary);                                               // Calling the printing function
}

void add_rect(float r1, float i1, float r2, float i2){                              // Simple add function for the rectangular form
    r1= r1+r2;
    i1= i1+i2;
    print_rectangle(r1,i1);
}

void sub_rect(float r1, float i1, float r2, float i2){                              // Simple subtract function for the rectangular form.
    r1= r1-r2;
    i1= i1-i2;
    print_rectangle(r1,i1);
}
void mult_rect(float r1, float i1, float r2, float i2){                             // Multiplication function for the rectangular form. For (a+bi)(c+di) = (ac -bd) + (ad + bc)i
    float re= r1*r2-i1*i2;                                                          // This is given by the real part (ac-bd)
    float im= r1*i2+r2*i1;                                                          // This is given by the imaginary part (ad + bc)
    print_rectangle(re,im);
}
void mult_polar( float mag1, float arg1, float mag2, float arg2){                   // Multiplication function for the polar form.
    mag1 = mag1*mag2;
    arg1 = arg1+arg2;
    print_polar(mag1, arg1);
}
void div_rect( float a, float b, float c, float d){

        float re = ((a*c+b*d)/(c*c+d*d));
        float im = ((b*c-a*d)/(c*c+d*d));
        print_rectangle(re, im);
}
void div_polar( float mag1, float arg1, float mag2, float arg2){
    mag1= mag1/mag2;
    arg1 = arg1-arg2;
    print_polar(mag1, mag2);
}

int main(){
    cout<< "Welcome to the Complex number maniuplator!"<<endl;
    cout<<" From the list of options, choose what you would like to do:"<<endl;
    cout<<"     1. Add"<<endl;
    cout<<"     2. Subtract"<<endl;
    cout<<"     3. Multiply"<<endl;
    cout<<"     4. Divide"<<endl;
    cout<<"     5. Convert to Polar"<<endl;
    cout<<"     6. Convert to rectangular"<<endl;
    rectangular* first = new rectangular;
    rectangular* second = new rectangular;
    polar* polar1= new polar;
    polar* polar2 = new polar;
    
    int choice;
    cin>>choice;
    if (cin.fail()) {
        cerr<<"Error!"<<endl;
        return -1;
    }
    if (choice<1||choice>6) {
        cerr<< "Invalid Input🚫"<<endl;
        return -2;
    }
/* FOR Choice 1:...........................................................................................................................................................................*/
    if (choice==1) {
        cout<<" Addition of Two complex numbers [Rectangular form]"<<endl;
        cout<<"Input Real part: "<<endl;
        cin>>first->real;
        cout<<"Input Imaginary part: "<<endl;
        cin>> first->imaginary;
        cout<<"Input Real part: "<<endl;
        cin>>second->real;
        cout<<"Input Imaginary part: "<<endl;
        cin>> second->imaginary;
        cout<<"Result:";
        add_rect(first->real,first->imaginary,second->real,second->imaginary);
        
    }
    
    
/* FOR Choice 2:........................................................................................................................................................................... */

    if (choice==2) {
        cout<<" Subtraction of Two complex numbers [Rectangular form]"<<endl;
        cout<<"Input Real part: "<<endl;
        cin>>first->real;
        cout<<"Input Imaginary part: "<<endl;
        cin>> first->imaginary;
        cout<<"Input Real part: "<<endl;
        cin>>second->real;
        cout<<"Input Imaginary part: "<<endl;
        cin>> second->imaginary;
        cout<<"Result:";
        sub_rect(first->real,first->imaginary,second->real,second->imaginary);
        
    }
    
/* FOR Choice 3:........................................................................................................................................................................... */

    if (choice==3) {
        cout<<"Multiplication of Complex numbers."<<endl;
        cout<<" Input form?:"<<endl;
        cout<<"     A-> Rectangular"<<endl;
        cout<<"     B-> Polar"<<endl;
        char select;
        cin>>select;
        if (cin.fail()) {
            cerr<<" Error!"<<endl;
            return -1;
        }
//        if (select<65||select>66) {
//            cerr<<" Invalid Input"<<endl;
//            return -1;
//        }
        
        if (select == 'A'|| select == 'a') {
            cout<<"Multiplication of two complex numbers [Rectangular form]"<<endl;
            cout<<" Input Real part 1: "<<endl;
            cin>>first->real;
            cout<<" Input Imaginary part 1: "<<endl;
            cin>> first->imaginary;
            cout<<" Input Real part 2: "<<endl;
            cin>>second->real;
            cout<<" Input Imaginary part 2: "<<endl;
            cin>> second->imaginary;
            cout<<"Result:";
            mult_rect(first->real,first->imaginary,second->real,second->imaginary);
        }
        
        if (select == 'B'|| select == 'b') {
            cout<<"Multiplication of two complex numbers [Polar form]"<<endl;
            cout<<" Input Magnitude 1: "<<endl;
            cin>>polar1->magnitude;
            cout<<" Input Arg/Angle 1(in degrees): "<<endl;
            cin>> polar1->angle;
            cout<<" Input Magnitude 2: "<<endl;
            cin>>polar2->magnitude;
            cout<<" Input Arg/Angle 2: "<<endl;
            cin>> polar2->angle;
            if (polar1->magnitude<0 ||polar2->magnitude ) {
                cerr<<"Invalid Input"<<endl;
                return -1;
            }
            cout<<"Result:";
            mult_polar(polar1->magnitude,polar1->angle,polar2->magnitude,polar2->angle);
        }

    }
/* FOR Choice 4:...........................................................................................................................................................................*/

    if (choice == 4) {
        cout<<"Division of Complex numbers."<<endl;
        cout<<" Input form?:"<<endl;
        cout<<"     A-> Rectangular"<<endl;
        cout<<"     B-> Polar"<<endl;
        char pick;
        cin>>pick;
        if (cin.fail()) {
            cerr<<"Error!"<<endl;
            return -1;
        }
        if (pick == 'A'|| pick == 'a') {
            cout<<"Division of Complex numbers[Rectangular Form]"<<endl;
            cout<<" Input Real Part 1:"<<endl;
            cin>> first->real;
            cout<<" Input Imaginary part 1: "<<endl;
            cin>> first->imaginary;
            cout<<" Input Real part 2: "<<endl;
            cin>>second->real;
            cout<<" Input Imaginary part 2: "<<endl;
            cin>> second->imaginary;
            cout<<"Result:";
            div_rect(first->real,first->imaginary,second->real,second->imaginary);
        }
        if (pick == 'B'|| pick =='b') {
            cout<<"Division of Complex numbers[Rectangular Form]"<<endl;
            cout<<" Input Magnitude 1: "<<endl;
            cin>>polar1->magnitude;
            cout<<" Input Arg/Angle 1(in degrees): "<<endl;
            cin>> polar1->angle;
            cout<<" Input Magnitude 2: "<<endl;
            cin>>polar2->magnitude;
            cout<<" Input Arg/Angle 2: "<<endl;
            cin>> polar2->angle;
            if (polar1->magnitude<0 ||polar2->magnitude ) {
                cerr<<"Invalid Input"<<endl;
                return -1;
            }
            cout<<"Result:";
            div_polar(polar1->magnitude,polar1->angle,polar2->magnitude,polar2->angle);
            
        }
        
    }
/* FOR Choice 5:........................................................................................................................................................................... */
    if (choice == 5) {
        cout<<"Conversion of Rectangular to polar"<<endl;
        cout<<" Input Real part"<<endl;
        cin>> first->real;
        cout<<" Input Imaginary part"<<endl;
        cin>> first->imaginary;
        cout<<"    Result:";
        rect_pol(first->real,first->imaginary);
    }
    
/* FOR Choice 6:...........................................................................................................................................................................*/
    if (choice == 6) {
        cout<<"Conversion of Polar to Rectangular"<<endl;
        cout<<"Input Magnitude"<<endl;
        cin>> polar1->magnitude;
        cout<<"Input Angle/Argument"<<endl;
        cin>> polar1->angle;
        cout<<"Result:";
        rect_pol(polar1->magnitude,polar1->angle);
    }
    
    
    return 0;
    
}
