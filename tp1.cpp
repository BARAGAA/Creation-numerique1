/***    Tp1 noté                            ***/
/*     auteur  BARAGAA Mohammed           */
/*     version du 15 janvier 2020        */
/*                                        */
/******************************************/
#include <iostream> // cin , cout ,endl
#include <cassert> //assert function
#include <cmath> // sin ,e
#define PI 3.14159265

using namespace std;

double sommation1( double i){
    double somme=0.0;
    for (double j=1; j<=i; j++)
        somme = somme + (1/j);
    
    return somme;
}

float sommation2( int i){
    float somme=0.0;
    for (float j=1; j<=i; j++)
        somme = somme + (1/j);
    
    return somme;
}



double f1(double x){
    return x*x + x - 6 ;
}
double f2(double x){
    return x*x*x - 2*x - 5 ;
}
double f3(double x){
    return (exp (x) -1 ) ;
}
double f4(double x){
    return (x * sin(x*PI/180)) ;
}
double f5(double x){
    return x*x*x - 3*x*x + 3*x - 1 ;
}


double bissection(double a , double b ,double e, double (*f)(double)){
    if((b-a)<=e||f((b+a)/2) == 0){
        return (b+a)/2;
    }else if(f(a) * f((a+b)/2) < 0) {
        return bissection(a, (a+b)/2,e,f);
    }else{
        return bissection((a+b)/2,b,e,f);
    }
}

double newtonIter(double x1,double x2 ,double e, double (*f)(double)){
    double tmp;
    double xn;
    xn = x2 - (f(x1)/((f(x2)-f(x1))/(x2-x1)));
     while((abs(f(x1)-f(x2)) > e)){
         x1=x2;
         x2=xn;
        xn= x1 - (f(x1)/((f(x2)-f(x1))/(x2-x1)));
    }

    return xn;


}

int main() {
    /*BISSECTION MÉTHOD */
   /*  cout <<"enter the born a"<<endl;
    double a;
    cin >> a;
    cout <<"enter the born b"<<endl;
    double b;
    cin >> b;
    cout <<"enter the precision epsilon"<<endl;
    double e;
    cin >> e;
    assert(f(a)*f(b) < 0); // the sign must change somewhere in the function
    assert (a<b); // b has to be bigger than a
    cout <<"valid input"<<endl;
    cout << "a = "<< a <<endl <<endl;
    cout << "b = "<< b <<endl <<endl;
    cout << "e = "<< e <<endl <<endl;
    
    double zero = bissection(a,b,e);
    cout <<"the found zero is "<< zero <<endl;*/

    /*---------------------------------------------------------------------- */

    /*NEWTON MÉTHOD */
   /* double x1;
    cout <<"x1"<<endl;
    cin >> x1;
    cout <<"x2"<<endl;
    double x2;
    cin >> x2;
    cout <<"enter the precision epsilon"<<endl;
    double e;
    cin >> e; 
    cout <<newtonIter(x1,x2,e,f2)<< endl;*/

    /*--------------SOMME-------------------  */
    int i;
    cin >> i;
    cout << sommation2(i) << endl;


}
