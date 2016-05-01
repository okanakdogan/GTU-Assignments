/*
    created by Okan Akodgan
    121044017

    Numerical Analysis Hw 06
    y'=y*x^2 - y
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
    analytic solution of y'=y*x^2 - y
    is e^( x^3/3 - x ) for x=0 & y=1
*/
double analyticSolution(double x);
double derfunc(double y,double x);
double eulerMethod(double yi, double x,double h);
double heunMethod(double yi,double x,double h);
double rungeKutta2(double yi, double x, double h);
double rungeKutta4(double yi, double x, double h);
double errorCalc(double analytic,double calc);
int main()
{

    double x,h[3]={ 1, 0.5, 0.1};
    double yRes[255];
    int i=2,index=0;
    double y_old=1;
    FILE * out;

    out=fopen("hw6_result.txt","w");

    /*h steps */
    for(i=0;i<3;i++){
        /*analytic sol.*/

        printf("analytic solution for h=%f\n",h[i]);
        fprintf(out,"analytic solution for h=%f\n",h[i]);
        for(x=0,index=0;x<=10;x+=h[i],index++){
            yRes[index]=analyticSolution(x);
            printf("h=%.2f x=%.1f y=%f \n",h[i],x,yRes[index]);
            fprintf(out,"h=%.2f x=%.1f y=%f \n",h[i],x,yRes[index]);
        }
        /*euler solution*/
        printf("\neuler solution for h=%f\n",h[i]);
        fprintf(out,"\neuler solution for h=%f\n",h[i]);
        for(x=h[i],index=0,y_old=1 ;x<=9;x+=h[i],index++){
            y_old=eulerMethod(y_old,x,h[i]);
            printf("h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            printf("error=%f \n",errorCalc(yRes[index+1],y_old));

            fprintf(out,"h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            fprintf(out,"error=%f \n",errorCalc(yRes[index+1],y_old));
        }
        /*heun solution*/
        printf("\nheun solution for h=%f\n",h[i]);
        fprintf(out,"\nheun solution for h=%f\n",h[i]);
        for(x=0,index=0,y_old=1 ;x<=9;x+=h[i],index++){
            y_old=heunMethod(y_old,x,h[i]);
            printf("h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            printf("error=%f \n",errorCalc(yRes[index+1],y_old));

            fprintf(out,"h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            fprintf(out,"error=%f \n",errorCalc(yRes[index+1],y_old));
        }

        /*runge-kutta 2 solution*/
        printf("\nrunge-kutta 2 solution for h=%f\n",h[i]);
        fprintf(out,"\nrunge-kutta 2 solution for h=%f\n",h[i]);
        for(x=0,index=0,y_old=1 ;x<=9;x+=h[i],index++){
            y_old=rungeKutta2(y_old,x,h[i]);
            printf("h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            printf("error=%f \n",errorCalc(yRes[index+1],y_old));

            fprintf(out,"h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            fprintf(out,"error=%f \n",errorCalc(yRes[index+1],y_old));
        }
        /*runge-kutta 4 solution*/
        printf("\nrunge-kutta 4 solution for h=%f\n",h[i]);
        fprintf(out,"\nrunge-kutta 4 solution for h=%f\n",h[i]);
        for(x=0,index=0,y_old=1 ;x<=9;x+=h[i],index++){
            y_old=rungeKutta4(y_old,x,h[i]);
            printf("h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            printf("error=%f \n",errorCalc(yRes[index+1],y_old));

            fprintf(out,"h=%.2f x=%.1f y=%f  ",h[i],x+1,y_old);
            fprintf(out,"error=%f \n",errorCalc(yRes[index+1],y_old));
        }
        printf("\n\n");
        fprintf(out,"\n\n");
    }
    fclose(out);
    return 0;
}

double analyticSolution(double x){
    return pow(M_E,((pow(x,3)/3) - x));
}
double derfunc(double y,double x) {
    return y*pow(x,2)-y;
}
double eulerMethod(double yi, double x,double h){
    return yi + derfunc(yi,x)*h;
}

double heunMethod(double yi,double x,double h){
    double y0=eulerMethod(yi,x,h);
    return yi + ((derfunc(yi,x)+ derfunc(x+h,y0))/2)*h;
}
double rungeKutta2(double yi, double x, double h){
    double k1,k2;
    k1=derfunc(yi,x);
    k2=derfunc(yi+k1*h,x+h);
    return yi +(k1/2+k2/2)*h;
}
double rungeKutta4(double yi, double x, double h){
    double k1,k2,k3,k4;
    k1=derfunc(yi,x);
    k2=derfunc(yi+0.5*k1*h,x+0.5*h);
    k3=derfunc(yi+0.5*k2*h,x+0.5*h);
    k4=derfunc(yi+k3*h,x+h);
    return yi+(1.0/6)*(k1+2*k2+2*k3+k4)*h;
}
double errorCalc(double analytic,double calc){
    return (1-(calc/analytic))*100;
}
