#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */

/*Okan Akdogan*/


#define enable() __asm(cli)
#define disable() __asm(sei)


void buzer(void);
void MSDelay(unsigned int itime);

interrupt(((0x10000-Vrti)/2)-1) void timerRti(void);


const unsigned char letters[]={ 0x77,0x7c,0x39,0x5e,0x79,0x71,0x76,0x38,0x54,
                       0x3F,0x73,0x50,0x6D,0x3E,0x6E,0x5B};
                       
const unsigned char asciTable[]={65,98,67,100,69,70,72,76,110,79,80,114,83,85,89,90};
/*                                A  b  C  d   E  F  H  L  n   O  P  r   S  U  Y  Z*/
                        
const char digits[] ={0x3F, 0x06,0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07 ,0x7F, 0x6F};


char unsigned words[][5]={"PArA","dEdE","PAPA","AnnE","PALA","SUCU","bOrA","dAnA","SAnA","bAbA","UYUZ","FOrA","HALA"};
char openletter[4]={0,0,0,0};

unsigned int kelime =0;

unsigned char bildiCnt=0;
unsigned char bildiHarfCnt=0;
unsigned char bilemediCnt=0;
unsigned char buzzerFlag=0;
unsigned char showWordFlag=0;
unsigned char showScoreFlag=0;
unsigned char lastInLet=0;
unsigned int score=0;
  
void main(void) {
 
    int i;
    unsigned char prev=0;
    char dogruHarf=0;
    char yanlisCount=0;
    char bitti=0;
    
    disable();
    DDRB = 0xFF;
    DDRP = 0x0F;
    DDRH = 0x00;
    PORTB = 0;
    RTICTL = 0x23;
    CRGINT = 0x80;
    CRGFLG = 0x80;
    enable();
    
    
    for(;;){
    
      if(prev!=lastInLet){
         prev=lastInLet;
        /*harf karsilastir*/
        for(i=0;i<4;++i){
      
          if(words[kelime][i]==lastInLet){
             openletter[i]=1;
             dogruHarf=1;
          }
        }
        /*hatali girdi mi*/
  
        if(dogruHarf==0){
          buzzerFlag=1;
          yanlisCount++;
        }
      
        dogruHarf=0;
        
             
      }
     
     /*oyun bitti mi*/
       
      if(yanlisCount==6){    
        yanlisCount=0;
        bilemediCnt++;
        bildiHarfCnt=0;       
        showWordFlag=1;
        
        bitti=1;       
      }
      
      /*bilinenleri say*/
      bildiHarfCnt=0;
      for(i=0;i<4;++i)
        bildiHarfCnt+=openletter[i];
      
      if(bildiHarfCnt==4){
        bildiCnt++;
        score=bildiCnt*10;
        showWordFlag=1;
        yanlisCount=0;
        bitti=1;
        
      }
       
      /*buzzer sound*/
      if(buzzerFlag==1){
        MSDelay(5000); 
        buzer();
        buzzerFlag=0; 
      }
      
      /*show Word game end*/
      if(showWordFlag==1){
        for(i=0;i<4;++i)
          openletter[i]=1;
        MSDelay(5000);
        showWordFlag=0;
      }
      
      /*round end, clear variables*/
      if(bitti==1){
        /*clear vars*/
        bildiHarfCnt=0;
        bitti=0;
        yanlisCount=0;
        
        /*showScore*/
        showScoreFlag=1;
        MSDelay(3000);
        showScoreFlag=0;
        
        /*clear word visible set*/
        for(i=0;i<4;++i)
          openletter[i]=0;
          
        /*next word*/
        kelime++;
        if(kelime>12){
          __asm(swi);
        }
      
      }
    
      
    }
    
}


interrupt(((0x10000-Vrti)/2)-1) void timerRti(void) 
{ 
  static unsigned char index =0;
  int letterIndex=0;
  int i;
  static int inputSec=0;
  
        
  switch(index){
  
    case 0: PTP = 0x0E;
           
        break;
        
    case 1: PTP = 0x0D;
            
        break;
             
     case 2: PTP = 0x0B;
             
        break;
        
     case 3: PTP = 0x07;
             
        break;
  }
  
  if(showScoreFlag==0){
    
    for(i=0;i<16;++i)
      if(asciTable[i]==words[kelime][index])
        letterIndex=i;
    
    if(openletter[index]==0)
      PORTB=0x08;
    else
      PORTB=letters[letterIndex];
  }
  else{
    /*show score*/
      switch(index){
  
    case 0: PORTB = digits[(score/1000)%10];
           
        break;
        
    case 1: PORTB = digits[(score/100)%10];
            
        break;
             
     case 2: PORTB = digits[(score/10)%10];
             
        break;
        
     case 3: PORTB = digits[(score)%10];
             
        break;
      }
  
  }
  /*input al*/
  ++inputSec;
  if(inputSec>2000){
    lastInLet=PTH;
    inputSec=0;
  
  }
 

  index = (index+1)%4;
  CRGFLG = 0x80;
           
     
}

void buzer(void){
  
     int buzCnt;
     for(buzCnt = 0; buzCnt < 100; buzCnt++) 			
            {
            
               DDRT = DDRT | 0x20;    // PTT5 as output
               PTT = PTT | 0x20;      //make PT5=1
               MSDelay(10);         //change the delay size to see what happens
               PTT = PTT &(~0x20);      //Make PT5=0
               MSDelay(10);         //change delay size....

            } 
}


void MSDelay(unsigned int itime)    //millisec delay
  {
    unsigned int i; unsigned int j;
    for(i=0;i<itime;i++)
      for(j=0;j<4000;j++);
  }
