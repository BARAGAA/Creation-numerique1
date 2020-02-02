/***    Tp1 noté                            ***/
/*     auteur  BARAGAA Mohammed           */
/*     version du 15 janvier 2020        */
/*                                        */
/******************************************/
#include <iostream> // cin , cout ,endl
#include <cassert> //assert function
#include <cmath> // sin ,e
#include <limits>
#define PI 3.14159265


using namespace std;
/*--------------------------------Algorithmes de sommation------------------*/

double sommationCroissantDouble( int i){
    double somme=0.0;
    for (int j=1; j<=i; j++)
        somme = somme + (1.0/j);
    
    return somme;
}

float sommationCroissantFloat( int i){
    float somme=0.0;
    for (int j=1; j<=i; j++)
        somme = somme + (1.0/j);
    
    return somme;
}

double sommationDecroissantDouble( int i){
    double somme=0.0;
    for (int j=i; j>=1; j--)
        somme = somme + (1.0/j);
    
    return somme;
}

float sommationDecroissantFloat( int i){
    float somme=0.0;
    for (float j=i; j>=1; j--)
        somme = somme + (1.0/j);
    
    return somme;
}
/*double sommation3Double(int i){
int y,x ,total,somme;    
int err = 0 ;// c représente l’erreur à chaque addition
    for(int j=2 ; j<= i; j++ ) {


        y = x_i - c // on additionne l’erreur de l’addition précédente au
        // terme courant
        total=somme+y
        c = (t - s) - y
        s=t

    }
}*/

/*------------------------------Fonctions------------------------------------*/
double f1(double x){
    return x*x + x - 6 ;
}

double f2(double x){
    return x*x*x - 2*x - 5 ;
}

double f3(double x){
    return (exp(x) -1) ;
}

double f4(double x){
    return (x * sin(x*PI/180)) ;
}

double f5(double x){
    return x*x*x - 3*x*x + 3*x - 1 ;
}

/*------------------------------------Bissection-------------------------------------------*/

double bissection(double a , double b ,double e, double (*f)(double)){
    assert(f(a)*f(b) < 0); // the sign must change somewhere in the function
    assert (a<b); // b has to be bigger than a
    if((b-a)<=e||f((b+a)/2) == 0){
        return (b+a)/2;
    }else if(f(a) * f((a+b)/2) < 0) {
        return bissection(a, (a+b)/2,e,f);
    }else{
        return bissection((a+b)/2,b,e,f);
    }
}

/*---------------------------------------Newton-------------------------------*/

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


/*-----------------------------Programme Principal---------------------*/

int main() {
    cout.precision(20);

    /*BISSECTION MÉTHOD */
    /*cout <<"enter the born a"<<endl;
    double a;
    cin >> a;
    cout <<"enter the born b"<<endl;
    double b;
    cin >> b;
    cout <<"enter the precision epsilon"<<endl;
    double e0;
    cin >> e0;
    cout <<"valid input"<<endl;
    cout << "a = "<< a <<endl <<endl;
    cout << "b = "<< b <<endl <<endl;
    cout << "e = "<< e <<endl <<endl;
    cout <<"the found zero is "<< bissection(a,b,e0,f1)<<endl;*/

    /*---------------------------------------------------------------------- */

    /*NEWTON MÉTHOD */
    double x1;
    cout <<"x1 = ";
    cin >> x1;
    cout <<"x2 = ";
    double x2;
    cin >> x2;
    cout <<"enter the precision epsilon"<<endl;
    double e1;
    cin >> e1; 
    cout <<"*------------------------------------------------------------------------------*"<<endl;
    cout <<endl << "x_0 = "<< x1 <<"     ";
    cout << "x_1 = "<< x2 <<"     ";
    cout << "e = "<< e1 <<endl <<endl;
    cout <<"racine = "<<newtonIter(x1,x2,e1,f2)<< endl;


    /*--------------SOMME-------------------  */
    /*int i;
    cin >> i;
    cout << sommationDecroissantDouble(i) << endl; 
    cout << sommationCroissantDouble(i) << endl;
    */ 


}
