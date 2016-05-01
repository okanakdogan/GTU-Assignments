/*
    Okan Akdogan
    121044017

    HW03 Regression Homework
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double leastSquaresM(double xSet[],double ySet[],int sizeOfSets);
double leastSquaresC(double M,double meanX,double meanY);
double meanOfSet(double set[],int sizeOfSet);

double standartDeviationRegSums(double xSet[],double ySet[],int sizeOfSets,double M,double C);
double standartDeviationTSums(double ySet[],int sizeOfSets);

double errorResultSquare(double sTSum,double sRegSum);

double sumXpower(double xSet[],int sizeOfSet,int p);
double sumXpowerY(double xSet[],double ySet[], int sizeOfSets,int p);
void gaussElemination(double polyMatrix[][7],double polyResult[],int row,int col);


int main()
{
    double x[10]={2.5 , 3.5 , 5 , 6 , 7.5 , 10 , 12.5 , 15 , 17.5 , 20 };
    double y[10]={5 , 3.4 , 2 , 1.6 , 1.2 , 0.8 , 0.6 , 0.4 , 0.3 , 0.3 };

    double xModified[10];
    double yModified[10];

    double polyMatrix[6][7];
    double polyResult[6];
    double temp=0.0;
    int sizeOFSets=10;

    double M=0,C=0; /*slope and constant*/
    double standartDevRegSum=0;
    double standartDevTSum=0;
    int Quality=0,i,j;
    double r2Value=0;


    /*Function 1 y= a0 + a1*x */

    M=leastSquaresM(x,y,sizeOFSets);
    C=leastSquaresC(M,meanOfSet(x,sizeOFSets),meanOfSet(y,sizeOFSets));
    standartDevRegSum=standartDeviationRegSums(x,y,sizeOFSets,M,C);
    standartDevTSum=standartDeviationTSums(y,sizeOFSets);
    printf("st=%f,sreg=%f\n M=%f C=%f\n",standartDevTSum,standartDevRegSum,M,C);


    r2Value=errorResultSquare(standartDevTSum,standartDevRegSum);
    Quality=r2Value*100;

    printf("r= %f\nQuality Of first representation is %%%d\n\n",sqrt(fabs(r2Value)),Quality);

    /*Function 2 y= A*x^B   */
    /*linear Rep. logy= logA + B* logx  */
    /* logA=C , B=M */

    for(i=0;i<sizeOFSets;++i){
        xModified[i]=log(x[i]);
        yModified[i]=log(y[i]);
    }
    M=leastSquaresM(xModified,yModified,sizeOFSets);
    C=leastSquaresC(M,meanOfSet(xModified,sizeOFSets),meanOfSet(yModified,sizeOFSets));

    standartDevRegSum=standartDeviationRegSums(xModified,yModified,sizeOFSets,M,C);
    standartDevTSum=standartDeviationTSums(yModified,sizeOFSets);
    printf("st=%f,sreg=%f\n M=%f C=%f\n",standartDevTSum,standartDevRegSum,M,C);

    r2Value=errorResultSquare(standartDevTSum,standartDevRegSum);
    Quality=r2Value*100;

    printf("r= %f\nQuality Of first representation is %%%d\n\n",sqrt(fabs(r2Value)),Quality);

    /*Function 3 y= A*e^(B*x)   */
    /*linear Rep. logy= logA + B*x  */
    /* logA=C , B=M */
    for(i=0;i<sizeOFSets;++i){
        xModified[i]=x[i];
        yModified[i]=log(y[i]);
    }
    M=leastSquaresM(xModified,yModified,sizeOFSets);
    C=leastSquaresC(M,meanOfSet(xModified,sizeOFSets),meanOfSet(yModified,sizeOFSets));

    standartDevRegSum=standartDeviationRegSums(xModified,yModified,sizeOFSets,M,C);
    standartDevTSum=standartDeviationTSums(yModified,sizeOFSets);
    printf("st=%f,sreg=%f\n M=%f C=%f\n",standartDevTSum,standartDevRegSum,M,C);

    r2Value=errorResultSquare(standartDevTSum,standartDevRegSum);
    Quality=r2Value*100;

    printf("r= %f\nQuality Of first representation is %%%d\n\n",sqrt(fabs(r2Value)),Quality);

    /*Function 4 y= A/(B*x + D)   */
    /*linear Rep. 1/y= (B/A)*x + D/A  */
    /* D/A=C , B/A=M */

     for(i=0;i<sizeOFSets;++i){
        xModified[i]=x[i];
        yModified[i]=1.0/y[i];
    }
    M=leastSquaresM(xModified,yModified,sizeOFSets);
    C=leastSquaresC(M,meanOfSet(xModified,sizeOFSets),meanOfSet(yModified,sizeOFSets));

    standartDevRegSum=standartDeviationRegSums(xModified,yModified,sizeOFSets,M,C);
    standartDevTSum=standartDeviationTSums(yModified,sizeOFSets);
    printf("st=%f,sreg=%f\n M=%f C=%f\n",standartDevTSum,standartDevRegSum,M,C);

    r2Value=errorResultSquare(standartDevTSum,standartDevRegSum);

    Quality=r2Value*100;

    printf("r= %f\nQuality Of fourth representation is %%%d\n\n",sqrt(fabs(r2Value)),Quality);


    /*Function 5 */

    /*fill matrix*/
    for(i=0;i<6;++i)
        for(j=0;j<6;++j){

            if(0!=i+j)
                polyMatrix[i][j]=sumXpower(x,sizeOFSets,j+i);
            else
                polyMatrix[i][j]=sumXpower(x,sizeOFSets,j+i);
        }

    /*fill result column*/
    for(i=0;i<6;++i)
        polyMatrix[i][6]=sumXpowerY(x,y,sizeOFSets,i);

     for(i=0;i<6;++i){
        for(j=0;j<6;++j)
            printf("%.2f ",polyMatrix[i][j]);
        printf("\n");}

        printf("solve\n");

    for(i=0;i<6;++i)
       printf("%f\n",polyMatrix[i][6]);

    /*solve Equation*/
    gaussElemination(polyMatrix,polyResult,6,7);

    standartDevRegSum=0;
    standartDevTSum=0;

    /*Sr Calculate*/
    for(i=0;i<sizeOFSets;++i){
        temp=polyResult[0];
        for(j=1;j<6;++j)
            temp+= polyResult[j]*pow(x[i],j);
        standartDevRegSum+=pow(y[i]-temp,2);
    }

    standartDevTSum=standartDeviationTSums(y,sizeOFSets);

    printf("\n st=%f,sreg=%f\n",standartDevTSum,standartDevRegSum);
    printf("Equation: \n");
    for(i=0;i<6;++i)
        if(i!=0)
            printf("+ %fx^%d",polyResult[i],i);
        else
            printf("%f ",polyResult[i]);
    printf("\n");

    r2Value=errorResultSquare(standartDevTSum,standartDevRegSum);

    Quality=r2Value*100;

    printf("r= %f\nQuality Of fifth representation is %%%d\n\n",sqrt(fabs(r2Value)),Quality);

    return 0;
}

double leastSquaresM(double xSet[],double ySet[],int sizeOfSets){

    double sumXY=0,sumX=0,sumY=0,sumX2=0,result=0;
    int i;

    /*sum of XY*/
    for(i=0;i<sizeOfSets;++i){
        sumXY+=xSet[i]*ySet[i];
    }
    /*sum of X*/
    for(i=0;i<sizeOfSets;++i){
        sumX+=xSet[i];
    }
     /*sum of Y*/
    for(i=0;i<sizeOfSets;++i){
        sumY+=ySet[i];
    }
    /*sum of X^2*/
    for(i=0;i<sizeOfSets;++i){
        sumX2+=xSet[i]*xSet[i];
    }

    result=(sizeOfSets*sumXY - sumX*sumY)/(sizeOfSets*sumX2 - pow(sumX,2));
    return result;
}
double leastSquaresC(double M,double meanX,double meanY){
    return meanY-meanX*M;
}

double meanOfSet(double set[],int sizeOfSet){
    int i;
    double sum=0;
    /*sum of values*/
    for(i=0;i<sizeOfSet;++i)
        sum+=set[i];

    /*mean*/
    return sum/sizeOfSet;
}


double standartDeviationRegSums(double xSet[],double ySet[],int sizeOfSets,double M,double C){
    double sumOfError=0;
    int i;

    for(i=0;i<sizeOfSets;++i)
        sumOfError+= pow( ySet[i]-C-M*xSet[i],2);

    return sumOfError;

}

double standartDeviationTSums(double ySet[],int sizeOfSet){
    double sumOfError=0;
    int i;
    double meanOfY=meanOfSet(ySet,sizeOfSet);

    for(i=0;i<sizeOfSet;++i)
        sumOfError+= pow( ySet[i]-meanOfY,2);

    return sumOfError;

}



double errorResultSquare(double sTSum,double sRegSum){
    return 1.0-sRegSum/sTSum;
}

double sumXpower(double xSet[],int sizeOfSet,int p){
    int i;
    double sum=0;
    for(i=0;i<sizeOfSet;++i){

        sum+=pow(xSet[i],p);
    }
    return sum;
}
double sumXpowerY(double xSet[],double ySet[], int sizeOfSets,int p){
    int i;
    double sum=0;

    for(i=0;i<sizeOfSets;++i){

        sum+=pow(xSet[i],p)*ySet[i];
    }

    return sum;
}

void gaussElemination(double polyMatrix[][7],double polyResult[],int row,int col){

    int i,j,k;
    double temp;
    for(k=0;k<row;k++)
        for(i=0;i<row;i++){
            if(i==k)
                continue;
            temp=polyMatrix[i][k]/polyMatrix[k][k];

            for(j=k;j<row;j++)
                polyMatrix[i][j]=polyMatrix[i][j]-temp*polyMatrix[k][j];
            polyMatrix[i][col-1]=polyMatrix[i][col-1]-temp*polyMatrix[k][col-1];
        }
    for(i=0;i<row;i++){
        polyResult[i]=polyMatrix[i][col-1]/polyMatrix[i][i];
    }
 return;

}
