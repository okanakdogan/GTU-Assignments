/*
    Okan Akdogan
    121044017

    Numerical Analysis Homework 01

*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    Question Function
*/
 double function( double n);
 /*
    rearranged functions for fixed point(one point) iteration
 */
 double funcForFixedIte(double n);

 /*
    Question's derivative
 */
 double functionDerivative( double n);

/*
    Bisection method function
    inputs:
        function: function pointer of question's function
        leftValue: one of start point on left side of root
        rightValue: other start point on right side of root
        error: approximation value
    output:
        root - if approximate enough
        0 - if something wrong, can be root too.

*/
 double bisectionMethod( double (*function)( double), double leftValue, double rightValue, double error);

 /*
    falsePositionMethod
    inputs:
        func: function pointer of question's function
        leftValue: one of start point on left side of root
        rightValue: other start point on right side of root
        error: approximation value
        maxIt: maximum loop count.
    output:
        root - if approximate enough
        0 - if something wrong, can be root too.

 */
 double falsePositionMethod(double (*func)(double),double leftValue,double rightValue,double error,int maxIt);

 /*
    fixedPointIterationMethod
    inputs:

        func: function pointer of rearranged question's function( x=f(x) )
        startPoint: start point for search root
        error: approximation value
        maxIt: maximum loop count.
    output:
        root - if approximate enough
        0 - if something wrong, can be root too.

 */
 double fixedPointIterationMethod(double (*func)(double),double startPoint,double error,int maxIt);
 /*
    newtonRaphionMethod
    inputs:
        func: function pointer of question's function
        fDeriv: function pointer of question's derivative function
        startPoint: start point for search root
        error: approximation value
        maxIt: maximum loop count.
    output:
        root - if approximate enough
        0 - if something wrong, can be root too.

 */
 double newtonRaphionMethod(double (*f)(double),double (*fDeriv)(double),double startPoint,double error,int maxIt);

 /*
    falsePositionMethod
    inputs:
        func: function pointer of question's function
        leftValue: one of start point on left side of root
        rightValue: other start point on right side of root
        error: approximation value
        maxIt: maximum loop count.
    output:
        root - if approximate enough
        0 - if something wrong, can be root too.

 */
 double secantMethod(double (*func)(double),double leftValue,double rightValue,double error,double maxIt);
int main()
{
     double result;

    printf("Bisecion method\n");
    result=bisectionMethod(&function,1.0,15.0,0.001);
    printf("Bisecion method result=%lf \n",result);

    printf("False Position method\n");
    result=falsePositionMethod(&function,3.0,10.0,0.00001,500);
    printf("False Position method result=%lf \n",result);

    printf("Fixed Point iteration method\n");
    result=fixedPointIterationMethod(&funcForFixedIte,10.0,0.001,50);
    printf("Fixed Point iteration result=%lf \n",result);

    printf("Newton Raphion iteration method\n");
    result=newtonRaphionMethod(&function,&functionDerivative,2.0,0.001,50);
    printf("Newton Raphion iteration result=%lf \n",result);

    printf("Secant method\n");
    result=secantMethod(&function,3.0,5.0,0.001,50);
    printf("Secant result=%lf \n",result);


    return 0;
}

 double function( double n){

    return ((-3000*pow(1.2,n))/(pow(1.2,n)-1) + (175*n)/(pow(1.2,n)-1)+5000);
}
double funcForFixedIte(double n){
    /*
    return (2000*pow(1.2,n)-5000)/-175;
    */
    return log((5000-175*n)/2000)/log(1.2);
}

double functionDerivative( double n){

    return (-3000*(pow(1.2,n)*log(1.2)*(pow(1.2,n)-1) - pow(1.2,2*n)*log(1.2)))/pow((pow(1.2,n)-1),2)
    + 175*((pow(1.2,n)-1)-(n*pow(1.2,n)*log(1.2)))/pow((pow(1.2,n)-1),2) ;
}
/*
    Bisection Method
*/
 double bisectionMethod( double (*function)( double), double leftValue, double rightValue, double error){
     double midValue=0;
     double valueMultiply=0;

    valueMultiply=(*function)(leftValue)*(*function)(rightValue);

    if(valueMultiply==0){
        if((*function)(leftValue)==0)
            return leftValue;
        else
            return rightValue;
    }

    else if(valueMultiply<0){

        midValue=(leftValue+rightValue)/2;

        if(fabs((*function)(midValue))<error)
                    return midValue;
        else{
            if((valueMultiply=(*function)(leftValue)*(*function)(midValue))<0){

                return bisectionMethod(function,leftValue,midValue,error);

            }
            else if ((valueMultiply=(*function)(midValue)*(*function)(rightValue))<0)

                return bisectionMethod(function,midValue,rightValue,error);
            }
    }
    return 0;
}
/*

    False Position Method
*/
double falsePositionMethod(double (*func)(double),double leftValue,double rightValue,double error,int maxIt){
    double midValue,midResult;
    double leftR,rightR;    /*left and right value result from function*/
    int c=0;    /*iteration count*/
    leftR=(*func)(leftValue);
    rightR=(*func)(rightValue);

    if(leftR*rightR<0){
        do{
            leftR=(*func)(leftValue);
            rightR=(*func)(rightValue);

            midValue= (leftValue*rightR-rightValue*leftR)/(rightR-leftR);
            midResult=(*func)(midValue);

            if(leftValue*midResult<0)
                rightValue=midValue;
            else if (leftValue*midResult>0)
                leftValue=midValue;
            else
                return midValue;

            ++c;

        }while(c<maxIt && fabs(midResult)>error);
        return midValue;
    }
    else
        return 0;



}

double fixedPointIterationMethod(double (*func)(double),double startPoint,double error,int maxIt){
    int c=0;
    double nextValue=startPoint,oldValue;

    do{
        oldValue=nextValue;
        nextValue= (*func)(oldValue);

        ++c;
    }while(c<maxIt && fabs(nextValue-oldValue)>error);
    return nextValue;
}

double newtonRaphionMethod(double (*f)(double),double (*fDeriv)(double),double startPoint,double error,int maxIt){
    double nextValue=startPoint;
    double oldValue;
    int c=0;
    do{
        oldValue=nextValue;
        nextValue= oldValue-(*f)(oldValue)/(*fDeriv)(oldValue);

        ++c;
    }while(c<maxIt && fabs(nextValue-oldValue)>error);
    return nextValue;
}

double secantMethod(double (*func)(double),double leftValue,double rightValue,double error,double maxIt){
    double midValue,midResult;
    int c=0;
    do{
        midValue=rightValue-func(rightValue)*(rightValue-leftValue)/(func(rightValue)-function(leftValue));
        midResult=function(midValue);
        leftValue=rightValue;
        rightValue=midValue;

        ++c;
    }while(c<maxIt && fabs(midResult)>error);
    return midValue;

}
