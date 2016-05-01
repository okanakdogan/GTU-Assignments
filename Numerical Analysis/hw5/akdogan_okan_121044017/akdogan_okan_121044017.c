/*
    Okan Akdogan
    121044017
    Numerical Analysis Homework 5
    integrals of 15.3^(2.5*x) with methods:
        -Numerical
        -Trapezoidal
        -Simpson 1/3
        -Simpson 3/8
        -Multiple Trapezoidal with n=2,4,10,20
        -Multiple Simpson 1/3 with n=2,4,10,20
    and Their Errors

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Function of homework
    input
       x: value for function
    returns 15.3^(2.5*x)
*/
double intgFunc(double x);

/*
    numerical
    integrates function with divide intervals
    and calculates sums areas of rectangles under the function
    inputs
        a: start x value of integral
        b: end x value of integral
        n: count of part for divide
    returns numerical integration method result
*/
double numerical(double a,double b, int n);
/*
    trapezoidal
    integrates function sum of area of Trapezoid under the function
    inputs
        a: start x value of integral
        b: end x value of integral
    returns trapezoidal integration method result
*/
double trapezoidal(double a,double b);
/*
    trapezoidalN
    integrates function with divide intervals
    and sums of areas of Trapezoids under the function
    inputs
        a: start x value of integral
        b: end x value of integral
        n: count of part for divide
    returns multiple trapezoidal integration method result
*/
double trapezoidalN(double a,double b,int n);

/*
    simpson13
    integrates function with Simpson 1/3 method
    inputs
        a: start x value of integral
        b: end x value of integral
    returns Simpson 1/3 integration method result
*/
double simpson13(double a, double b);
/*
    simpson13N
    integrates function with Multiple Application of Simpson 1/3 method
    inputs
        a: start x value of integral
        b: end x value of integral
        n: count of part for divide
    returns multiple Simpson 1/3 integration method result
*/
double simpson13N(double a, double b,int n);
/*
    simpson38
    integrates function with Simpson 3/8 method
    inputs
        a: start x value of integral
        b: end x value of integral
    returns Simpson 3/8 integration method result
*/
double simpson38(double a, double b);
/*
    error
    Calculates and returns error with between values
    inputs
        real: correct value
        result: approx. value
    returns error calculate result
*/
double error(double real,double result);

int main()
{
    /*15.3 ^(2.5*x) func 0 to 1 integral result from WolframAlpha*/
    const double realResult=134.12;
    double result=0.0;

    /*numerical*/
    result=numerical(0,1,10);
    printf("numerical result = %f \n\n",result);

    /*trapezoidal*/
    result=trapezoidal(0,1);
    printf("trapezoidal result = %f \n",result);
    printf("trapezoidal error result = %f \n\n",error(realResult,result));

    /*simpson13*/
    result=simpson13(0,1);
    printf("simpson 1/3 result = %f \n",result);
    printf("simpson 1/3 error result = %f \n\n",error(realResult,result));

    /*simpson38*/
    result=simpson38(0,1);
    printf("simpson 3/8 result = %f \n",result);
    printf("simpson 3/8 error result = %f \n\n",error(realResult,result));

    /*for n=2,4,10,20*/
    /*Trapezoidal*/
    result=trapezoidalN(0,1,2);
    printf("trapezoidal n=2 result = %f  error= %f \n",result,error(realResult,result));
    result=trapezoidalN(0,1,4);
    printf("trapezoidal n=4 result = %f  error= %f \n",result,error(realResult,result));
    result=trapezoidalN(0,1,10);
    printf("trapezoidal n=10 result = %f  error= %f \n",result,error(realResult,result));
    result=trapezoidalN(0,1,20);
    printf("trapezoidal n=20 result = %f  error= %f \n",result,error(realResult,result));
    printf("\n");

    /*Simspon 1/3*/
    result=simpson13N(0,1,2);
    printf("Simpson 1/3 n=2 result = %f  error= %f \n",result,error(realResult,result));
    result=simpson13N(0,1,4);
    printf("Simpson 1/3 n=4 result = %f  error= %f \n",result,error(realResult,result));
    result=simpson13N(0,1,10);
    printf("Simpson 1/3 n=10 result = %f  error= %f \n",result,error(realResult,result));
    result=simpson13N(0,1,20);
    printf("Simpson 1/3 n=20 result = %f  error= %f \n",result,error(realResult,result));

    return 0;
}
double intgFunc(double x){
    return pow(15.3,(2.5*x));
}

double numerical(double a,double b, int n){
    double h,sum=0;

    h=(b-a)/n;  /*interval*/

    for(;(b-a)>0.0001;a+=h){
        sum+=intgFunc(a)*h; /*sum of areas of rectangles*/
    }
    return sum;
}
double trapezoidal(double a,double b){
    /*Trapezoidal method formula*/
    return (b-a)*(intgFunc(a)+intgFunc(b))/2.0;
}
double trapezoidalN ( double a, double b, int n)
{
  double h;
  double y = 0, x, sum = 0, y0, yn;
  int i;

  h = (b - a) / n; /*interval*/

  y0 = intgFunc(a);
  yn = intgFunc(b);

    /*sum of mid intervals*/
  for (i=1,x=a+h ; i<n ; x=x+h,i++)
    sum=sum+intgFunc(x);

  y =(h / 2)*((y0 + yn)+2*sum);

  return y;
}

double simpson13(double a, double b){
    double m=(b-a)/2.0; /*mid value (x1)*/
    /*simpson 1/3 formula*/
    return (b-a)*(intgFunc(a)+ 4*intgFunc(m)+intgFunc(b))/6.0;
}
double simpson13N(double a, double b ,int n){
    int i;
    double h=(b-a)/n;
    double mid1Sum=0.0,mid2Sum=0.0;

    /*sum of odd mid values sum (x1,x3,x5,...)*/
    for(i=1;i<=(n-1);i+=2){
        mid1Sum+=intgFunc(a+i*h);
    }
    /*sum of even mid values sum (x2,x4,x6,...)*/
    for(i=2;i<=(n-2);i+=2){
        mid2Sum+=intgFunc(a+i*h);
    }
    /*Multiple application simpson 1/3 formula*/
    return (b-a)*(intgFunc(a)+ 4*mid1Sum +2*mid2Sum +intgFunc(b))/(3*n);
}

double simpson38(double a, double b){
    double h=(b-a)/3.0;/*interval*/
    double x1=a+h,x2=a+2*h; /*mid values*/
    /*simpson 3/8 method formula*/
    return (b-a)*(intgFunc(a)+3*intgFunc(x1)+3*intgFunc(x2)+intgFunc(b))/8.0;
}

double error(double real,double result){
    return fabs(1-(result/real));
}
