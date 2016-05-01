/*
    Sayýsal analiz hw 7
    Okan Akdogan
    121044017
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*analtiik çözüm*/
double analyticSolution(double x);
/*y1' fonksiyonu*/
double derfunc(double y);
/*y2' fonksiyonu*/
double derfunc2(double y1,double y2);

double eulerMethod1(double yi,double h);
double eulerMethod2(double yi,double y1, double y2,double h);

double rungeKutta4_1(double yi, double h);
double rungeKutta4_2(double yi,double y1,double y2, double h);

double errorCalc(double analytic,double calc);

int main()
{

    double x,h[3]={ 1, 0.5, 0.1};
    double yRes[255];
    int i=2,index=0;
    double y_old=1,tmp1;
    double y_old2=1,tmp2;
    FILE * out;

    out=fopen("hw7_result.txt","w");

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
        for(x=0,index=0,y_old=5,y_old2=5;x<=9;x+=h[i],index++){

            tmp1=eulerMethod1(y_old2,h[i]);
            tmp2=eulerMethod2(y_old,y_old2,y_old,h[i]);

            y_old2=tmp1;
            y_old=tmp2;

            printf("h=%.2f x=%.1f y1=%f  ",h[i],x+1,y_old);
            printf("y2=%f  ",y_old2);
            printf("error1=%f ",errorCalc(yRes[index+1],y_old));
            printf("error2=%f \n",errorCalc(yRes[index+1],y_old2));

            fprintf(out,"h=%.2f x=%.1f y1=%f  ",h[i],x+1,y_old);
            fprintf(out,"y2=%f  ",y_old2);
            fprintf(out,"error1=%f ",errorCalc(yRes[index+1],y_old));
            fprintf(out,"error2=%f \n",errorCalc(yRes[index+1],y_old2));

        }
        /*runge-kutta 4 solution*/

        printf("\nrunge-kutta 4 solution for h=%f\n",h[i]);
        fprintf(out,"\nrunge-kutta 4 solution for h=%f\n",h[i]);
        for(x=0,index=0,y_old=5 ,y_old2=2 ;x<=9;x+=h[i],index++){
            y_old=rungeKutta4_1(y_old,h[i]);
            y_old2=rungeKutta4_2(y_old2,y_old,y_old2,h[i]);

            printf("h=%.2f x=%.1f y1=%f  ",h[i],x+1,y_old);
            printf("h=%.2f x=%.1f y2=%f  ",h[i],x+1,y_old2);
            printf("error1=%f ",errorCalc(yRes[index+1],y_old));
            printf("error2=%f \n",errorCalc(yRes[index+1],y_old2));

            fprintf(out,"h=%.2f x=%.1f y1=%f  ",h[i],x+1,y_old);
            fprintf(out,"h=%.2f x=%.1f y2=%f  ",h[i],x+1,y_old2);
            fprintf(out,"error1=%f ",errorCalc(yRes[index+1],y_old));
            fprintf(out,"error2=%f \n",errorCalc(yRes[index+1],y_old2));
        }

        printf("\n\n");
        fprintf(out,"\n\n");

    }
    fclose(out);
    return 0;
}
double analyticSolution(double x){
    return  ( pow(M_E, (-x) ) * ( (10 * cos(sqrt(6) * x/ 2.0)) + ( 2.95*pow(10,(-18)) * sin(sqrt(6)* x / 2.0) ) ) - 5 );
}

double derfunc(double y) {
    return y;
}
double derfunc2(double y1,double y2) {
    return (20+4*y1-16*y2)/8;
}
double eulerMethod1(double yi,double h){
    return yi + derfunc(yi)*h;
}
double eulerMethod2(double yi,double y1, double y2,double h){
    return yi + derfunc2(y1,y2)*h;
}

double rungeKutta4_1(double yi, double h){
    double k1,k2,k3,k4;
    k1=derfunc(yi);
    k2=derfunc(yi+0.5*k1*h);
    k3=derfunc(yi+0.5*k2*h);
    k4=derfunc(yi+k3*h);
    return yi+(1.0/6)*(k1+2*k2+2*k3+k4)*h;
}

double rungeKutta4_2(double yi,double y1,double y2, double h){
    double k1,k2,k3,k4;
    k1=derfunc2(y1,y2);
    k2=derfunc2(yi+0.5*k1*h,y2);
    k3=derfunc2(yi+0.5*k2*h,y2);
    k4=derfunc2(yi+k3*h,y2);
    return yi+(1.0/6)*(k1+2*k2+2*k3+k4)*h;
}

double errorCalc(double analytic,double calc){
    return (1-(calc/analytic))*100;
}
