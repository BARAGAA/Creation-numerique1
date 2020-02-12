/***    Tp1 noté                            ***/
/*     auteur  BARAGAA Mohammed           */
/*     version du 10 fev janvier 2020        */
/*                                        */
/******************************************/
#include <iostream> // cin , cout ,endl
#include <cassert> //assert function
#include <cmath> // sin ,e
#include <limits>
#define PI 3.14159265


using namespace std;
/*--------------------------------Algorithmes de sommation------------------*/

double sommationCroissantDouble( int n){
    double somme=0.0;
    for (int j=1; j<=n; j++)
        somme = somme + (1.0/j);
    
    return somme;
}

float sommationCroissantFloat( int n){
    float somme=0.0;
    for (int j=1; j<=n; j++)
        somme = somme + (1.0/j);
    
    return somme;
}

double sommationDecroissantDouble( int n){
    double somme=0.0;
    for (int j=n; j>=1; j--)
        somme = somme + (1.0/j);
    
    return somme;
}

float sommationDecroissantFloat( int n){
    float somme=0.0;
    for (float j=n; j>=1; j--)
        somme = somme + (1.0/j);
    
    return somme;
}
double meilleurSumDouble(int n){
double y ,total;
double somme=1.0;    
double err = 0 ;// c représente l’erreur à chaque addition
    for(int j=2 ; j<= n; j++ ) {


        y = (1.0/j) - err; // on additionne l’erreur de l’addition précédente au
        // terme courant
        total= somme+y;
        err = (total - somme) - y;
        somme=total;
    }
    return somme;
}

float meilleurSumFloat(int n){
float y ,total;
float somme=1.0;    
float  err = 0 ;// c représente l’erreur à chaque addition
    for(int j=2 ; j<= n; j++ ) {


        y = (1.0/j) - err; // on additionne l’erreur de l’addition précédente au
        // terme courant
        total= somme+y;
        err = (total - somme) - y;
        somme = total;
    }
    return somme;
}

/*------------------------------Fonctions------------------------------------*/
double f1(double x){
    return x*x*x - 2*x - 5 ;
}

double f2(double x){
    return (exp(-x) -x) ;
}

double f3(double x){
    return ((x * sin(x*PI/180)) -1 ) ;
}

double f4(double x){
    return x*x*x - 3*x*x + 3*x - 1 ;
}

/*------------------------------------Bissection-------------------------------------------*/

double bissection(double a , double b ,double e, double (*f)(double)){
    assert(f(a)*f(b) < 0); // the sign must change somewhere in the function
    assert (a<b); // b has to be bigger than a
    if((b-a)<=e||f((b+a)/2) == 0){
        return (b+a)/2;
    }else if(f(a) * f((b+a)/2) < 0) {
        return bissection(a, (b+a)/2,e,f);
    }else{
        return bissection((b+a)/2,b,e,f);
    }
}

/*---------------------------------------Newton-------------------------------*/

double newtonIter(double x1,double x2 ,double e, double (*f)(double)){
    double tmp;
    double xn;
    xn = x2 - (f(x1)/((f(x2)-f(x1))/(x2-x1)));
     while((abs(xn - x2 ) > e)){
         x1=x2;
         x2=xn;
        xn= x1 - (f(x1)/((f(x2)-f(x1))/(x2-x1)));
    }
     return xn;
}


/*-----------------------------Programme Principal---------------------*/

int main() {
    cout.precision(17);

    /*BISSECTION METHOD */
  /*  cout <<"enter the born a"<<endl;
    double a;
    cin >> a;
    cout <<"enter the born b"<<endl;
    double b;
    cin >> b;
    cout <<"enter the precision epsilon"<<endl;
    double e1;
    cin >> e1;
    cout << "a = "<< a <<endl <<endl;
    cout << "b = "<< b <<endl <<endl;
    cout << "e = "<< e1 <<endl <<endl;
    cout <<"the found zero is "<< bissection(a,b,e1,f1)<<endl;
    */

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
   /* int i;
    cin >> i;
    cout << "in double precision"<<endl<<endl;
    cout <<"Croissant = "<<endl;
    cout << sommationCroissantDouble(i) << endl;
    cout <<"Decroissant = "<<endl<<endl;
    cout << sommationDecroissantDouble(i) << endl; 
    cout << "MeilleurSum"<<endl;
    cout <<meilleurSumDouble(i) << endl;
    cout << "en single precision"<<endl; 
    cout <<"Croissant = "<<endl<<endl;
    cout << sommationCroissantFloat(i) << endl;
    cout <<"Decroissant = "<<endl<<endl;
    cout << sommationDecroissantFloat(i) << endl; 
    cout <<"MeilleurSum"<<endl<<endl;
    cout <<meilleurSumFloat(i) << endl;*/



    


}
