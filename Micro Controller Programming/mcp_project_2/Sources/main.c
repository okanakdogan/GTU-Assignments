#include <hidef.h>      /* common defines and macros */
#include "derivative.h"      /* derivative-specific definitions */
#include <string.h>

/*Okan Akdogan*/


#define enable() __asm(cli)
#define disable() __asm(sei)

void buzzer(void);
void MSDelay(unsigned int itime);


#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80
 
#define KEYA 10
#define KEYB 11
#define KEYC 12
#define KEYD 13
#define KEYASTERISK 14
#define KEYSHARP 15


/* Dragon12 Development Board LCD */
#define LCD_DAT PORTK /* Port K drives LCD data pins, E, and RS */
#define LCD_DIR DDRK /* Direction of LCD port */
#define LCD_E 0x02 /* LCD E signal */
#define LCD_RS 0x01 /* LCD Register Select signal */
#define CMD 0 /* Command type for put2lcd */
#define DATA 1 /* Data type for put2lcd */

/* Prototypes for functions in lcd.c */
void openlcd(void); /* Initialize LCD display */
void put2lcd(char c, char type); /* Write command or data to LCD controller */
void puts2lcd (char *ptr); /* Write a string to the LCD display */
void delay_50us(int n); /* Delay n 50 microsecond intervals */
void delay_1ms(int n); /* Delay n 1 millisecond intervals */
void clearDisplay(void);
void moveCursorToSecondLine(void);

void convertScoreToStr(int score,char *scoreStr);
void gamePrint(char * mask, int wpredict,char * scoreStr);
void maskInit(char * wrd,char * mask);

/*Keypad function*/
int ReadKey(void);

char readAsciiLetter(void);

/*Word Store*/

char words[][16]={"AAH","AAL","AAS","ABA","ABB","ABO","ABS",
"ABY","ACE","ACH","ACT","ADD","ADO","ADS",
"ADZ","AFF","AFT","AGA","AGE","AGO","AGS",
"ASH","ASK","ASP","ASS","ATE","ATS","ATT",
"AUA","AUE","AUF","AUK","AVA","AVE","AVO",
"AWA","AWE","AWK","AWL","AWN","AXE","AYE",
"AYS","AYU","AZO","BAA","BAC","BAD","BAG",
"BUM","BUN","BUR","BUS","BUT","BUY","BYE",
"BYS","CAA","CAB","CAD","CAG","CAM","CAN",
"CAP","CAR","CAT","CAW","CAY","CAZ","CEE",
"CEL","CEP","CHA","CHE","CHI","CID","CIG",
"CUE","CUM","CUP","CUR","CUT","CUZ","CWM",
"DAB","DAD","DAE","DAG","DAH","DAK","DAL",
"DAM","DAN","DAP","DAS","DAW","DAY","DEB",
"DOL","DOM","DON","DOO","DOP","DOR","DOS",
"EAU","EBB","ECH","ECO","ECU","EDH","EDS",
"EEK","EEL","EEN","EFF","EFS","EFT","EGG",
"ERE","ERF","ERG","ERK","ERM","ERN","ERR",
"FON","FOP","FOR","FOU","FOX","FOY","FRA",
"FRO","FRY","FUB","FUD","FUG","FUM","FUN",
"FUR","GAB","GAD","GAE","GAG","GAK","GAL",
"HAO","HAP","HAS","HAT","HAW","HAY","HEH",
"HEM","HEN","HEP","HER","HES","HET","HEW",
"HEX","HEY","HIC","HID","HIE","HIM","HIN",
"ICY","IDE","IDS","IFF","IFS","IGG","ILK",
"ILL","IMP","ING","INK","INN","INS","ION",
"JOE","JOG","JOL","JOR","JOT","JOW","JOY",
"JUD","JUG","JUN","JUS","JUT","KAB","KAE",
"KAF","KAI","KAK","KAM","KAS","KAT","KAW",
"LIN","LIP","LIS","LIT","LOB","LOD","LOG",
"LOO","LOP","LOR","LOS","LOT","LOU","LOW",
"MEE","MEG","MEH","MEL","MEM","MEN","MES",
"NAS","NAT","NAW","NAY","NEB","NED","NEE",
"OBI","OBO","OBS","OCA","OCH","ODA","ODD",
"PEN","PEP","PER","PES","PET","PEW","PHI",
"PUT","PUY","PYA","PYE","PYX","QAT","QIN",
"QIS","QUA","RAD","RAG","RAH","RAI","RAJ",
"RAM","RAN","RAP","RAS","RAT","RAV","RAW",
"RAX","RAY","REB","REC","RED","REE","REF",
"ROE","ROK","ROM","ROO","ROT","ROW","RUB",
"SKA","SKI","SKY","SLY","SMA","SNY","SOB",
"TAU","TAV","TAW","TAX","TAY","TEA","TEC",
"TOY","TRY","TSK","TUB","TUG","TUI","TUM",
"TYE","TYG","UDO","UDS","UEY","UFO","UGH",
"UGS","UKE","ULE","ULU","UMM","UMP","UMS",
"VOX","VUG","VUM","WAB","WAD","WAE","WAG",
"WOK","WON","WOO","WOP","WOS","WOT","WOW",
"WOX","WRY","WUD","WUS","WYE","WYN","XIS",
"YAD","YAE","YAG","YAH","YAK","YAM","YAP",
"YAR","YAW","YAY","YEA","YEH","YEN","YEP",
"YES","YET","YEW","YEX","YGO","YID","YIN",
"ZAP","ZAS","ZAX","ZEA","ZED","ZEE","ZEK",
"ZEL","ZEP","ZEX","ZHO","ZIG","ZIN","ZIP",
"ZIT","ZIZ","ZOA","ZOL","ZOO","ZOS","ZUZ",
"ZZZ","AAHS","AALS","ABAC","ABAS","ABBA",
"ABBE","ABBS","ABED","ABET","ABID","ABLE",
"ABLY","ABOS","ABRI","ABUT","ABYE","ABYS",
"ACAI","ACCA","ACED","ACER","ACES","ACHE",
"ACHY","ACID","ACME","ACNE","ACRE","ACTA",
"ACTS","ACYL","ADAW","ADDS","ADDY","ADIT",
"BAAL","BAAS","BABA","BABE","BABU","BABY",
"BACH","BACK","BACS","BADE","BADS","BAEL",
"BAFF","BAFT","BAGH","BAGS","BAHT","BAHU",
"BAIL","BAIT","BAJU","BAKE","BALD","BALE",
"BALK","BALL","BALM","BALS","BALU","BAMS",
"BANC","BAND","BANE","BANG","BANI","BANK",
"BANS","BANT","BAPS","BAPU","BARB","BARD",
"BARE","BARF","BARK","BARM","BARN","BARP",
"BARS","BASE","BASH","BASK","BASS","BAST",
"CAAS","CABA","CABS","CACA","CACK","CADE",
"CADI","CADS","CAFE","CAFF","CAGE","CAGS",
"CAGY","CAID","CAIN","CAKE","CAKY","CALF",
"CALK","CALL","CALM","CALO","CALP","CALX",
"CAMA","CAME","CAMO","CAMP","CAMS","CANE",
"CANG","CANN","CANS","CANT","CANY","CAPA",
"CAPE","CAPH","CAPI","CAPO","CAPS","CARB",
"ANTRE", "CRATE", "EATER", "ENTER", "GRAIN",
"HATER", "HARES", "HIRES", "INTER", "IRATE",
"MATER", "MATES", "MITRE", "NEARS", "NEATS",
"PASTE", "PATER", "RAINS", "RATES", "RENTS",
"STAIN", "STAIR", "TABER", "TINES", "TRAIN",
"TRIPE",""};


/*Wrong Buzzer*/
char wrBuzzerFlag=0;
int buzCounter=0;

interrupt (((0x10000 - Vtimch0)/2)-1) void intrTimCh0(void);

void main(void) {

   unsigned int wordIndex=0,resetVars=0,gameOverFlag=0;
   char mask[17]={0};
   int key=-1,key1=-1,key2=-1,key3=-1,score=0,wrongPredict=0,foundFlag=0,maskFlag=0;
   
   char LCDText[34]={0};
   char scoreStr[5]="   ";
   unsigned char initword=1,i=0,j=0;
   int time=0;
  /*Initalize*/
  
  disable();
  
  /* Enabling keypad */
	DDRA = 0x0F;                     /* PORTA[0-3] is out, PORTA[4-7] input */
	DDRT = DDRT | BIT5;              /* PORTT as output for PT5 buzzer */
	DDRB = 0xFF;                     /* Set PortB as out */
	DDRP = 0x00;                     /* Disabling 7segment */
	PTP  = 0x00;
	
	/* Enabling serial communication with putty */
	SCI0BDL = 156;
	SCI0BDH = 0;
	SCI0CR1 = 0x00;
	SCI0CR2 = 0x0C;
 
  /* Setup for OC5 to buzzer signal*/
 	TSCR1 = BIT7; 
  /* Set prescaler to 32 (87.38 ms), enable TOF interrupt */ 
	TSCR2 = 0x05;
 
	TIOS |= BIT0;                    /* Configure PT4 as OC */
	TCTL2 = (TCTL2 | BIT0) & ~BIT1;  /* Toggle */
	TIE |= BIT0;                     /* Enable OC4 Interrupt */ 
	TFLG1 = BIT0;                    /* Clear OC4 Flag */

	//TFLG2 = BIT7;                    /* Clearing overflow flag */
	
  PORTB = 0x00;
  openlcd();

	enable();
	
	
	/*Program start*/
	
	/*Loop*/
	while(1){
	  
  	/*SelectWord*/   
  	if(initword==1){
  	  maskInit(words[wordIndex],mask);
  	  initword=0;
  	}
  	
  	/*LCD print*/
    convertScoreToStr(score,scoreStr);
  
  	gamePrint(mask,wrongPredict,scoreStr);
  	   	  
  	
  	/*Keypad input wait*/
  	 
    //key=readAsciiLetter();
    
    /*Input from putty*/
    
    while((SCI0SR1 & 0x20) == 0);
    key = SCI0DRL;
    SCI0DRL = key;
    
    
    time=TCNT;
                     
    /*letter compare*/
    i=0;
    while(words[wordIndex][i]!='\0'){
      if(words[wordIndex][i]==key){
        
        mask[i]=words[wordIndex][i];
        foundFlag=1;
      }
      ++i;
    }
    /*check predict*/
    if(foundFlag==0){    
      buzCounter=200;
      MSDelay(1000);
      wrongPredict++;
      //buzCounter=100;           
    }else {
      buzCounter=100;
      MSDelay(600);
    
    }
    foundFlag=0;
      
     clearDisplay();
        
    /*game end check*/
    if(wrongPredict==6){
       
       puts2lcd("yandin");
       MSDelay(1000);
       
       /*clear vars*/
        resetVars=1;
      
      /*next word*/ 
      ++wordIndex;
      if(words[wordIndex][0]=='\0'){
          gameOverFlag=1;   
      } 
      
    
    } else{
      
      i=0;
      maskFlag=0;
      while(mask[i]!='\0'){
        if(mask[i]!=words[wordIndex][i]){
          
          maskFlag=1;
          break; 
        }
        ++i;
      } 
      if(maskFlag==0){
        //bildi
        
        puts2lcd("bildin");
        MSDelay(1000);
        score+=10;
        
        /*clear vars*/
        resetVars=1;
        
        /*next word*/
        
        ++wordIndex; 
        if(words[wordIndex][0]=='\0'){
          gameOverFlag=1;
  
        }  
        
      }
    
    }
    /*Turn End*/
      if(resetVars==1){
        resetVars=0;
        wrongPredict=0;
        for(i=0;i<16;++i)
          mask[i]=' ';
         mask[i]='\0';
         initword=1;
      }
      
      /*Game End*/
      if(gameOverFlag==1){
        
         clearDisplay();
        	puts2lcd("oyun bitti");
          MSDelay(1000);
          moveCursorToSecondLine();
          	  
          puts2lcd("Score=");
          convertScoreToStr(score,scoreStr);
          puts2lcd(scoreStr);
          __asm(swi);  
      }
    
     clearDisplay();
	}
  
}

void maskInit(char * wrd,char * mask){
    int i=0;
	  while(wrd[i]!='\0'){
	    
	    mask[i]='_';
	    ++i;
	  }
	  mask[i]='\0';

}


void gamePrint(char * mask, int wpredict,char * scoreStr){
       puts2lcd(mask);
  	   moveCursorToSecondLine();
  	   puts2lcd("Life=");
  	   put2lcd((char)wpredict+48,DATA);
  	   puts2lcd("Score=");
  	   puts2lcd(scoreStr);
}

void convertScoreToStr(int score,char *scoreStr){
  scoreStr[4]='\0';
  scoreStr[3]=score%10+48;
  scoreStr[2]=(score>9)?(score/10)%10+48:'0';
  scoreStr[1]=(score>99)?(score/100)%10+48:'0';
  scoreStr[0]=(score>999)?(score/1000)%10+48:'0';
}



void buzzer(void){
  
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
  
  
int ReadKey(void) {
	int row,
	    column;
	
	const char row_mask[4] = { 0xFE,0xFD,0xFB,0xF7 };
	const char col_mask[4] = { BIT4,BIT5,BIT6,BIT7 };        
	const unsigned int keys[4][4] = 
	{ 1,2,3,10,
	  4,5,6,11,
	  7,8,9,12,
	  14,0,15,13 };
		
	for(row=0 ; row < 4 ; ++row) {
		PORTA = 0xFF;// Reset PortA
		for(column=0; column < 4 ;++column) {
			PORTA = PORTA & row_mask[row]; // Set specific row to 0
			
			if( (PORTA & col_mask[column]) == 0 ) {
			// Check if any key is pressed
 
				delay_1ms(10);                      
				// Wait 50ms and check again for make sure key is pressed.
				if( (PORTA & col_mask[column]) == 0 ) {
					//refreshLCD = TRUE;
					return keys[row][column]; 
				}
			}
		}
	}
	return -1;
}

char readAsciiLetter(void){

  int key1=-1,key2=-1;
  
  while(key1 == -1)key1=ReadKey();
  while(key2 == -1)key2=ReadKey();
  	 

  return key1*10+key2; //ascii code

}

  
  void openlcd(void) {
	LCD_DIR = 0xFF; /* configure LCD_DAT port for output */
	delay_1ms(50); /* Wait for LCD to be ready */
	put2lcd(0x28,CMD); /* set 4-bit data, 2-line display, 5x7 font */
	put2lcd(0x0F,CMD); /* turn on display, cursor, blinking */
	put2lcd(0x06,CMD); /* move cursor right */
	put2lcd(0x01,CMD); /* clear screen, move cursor to home */
	delay_1ms(1); /* wait until "clear display" command is complete */
}
 
void puts2lcd (char *ptr) {
	while (*ptr) { /* While character to send */
		put2lcd(*ptr,DATA); /* Write data to LCD */
		delay_50us(1); /* Wait for data to be written */
		ptr++; /* Go to next character */
	}
}
 
void put2lcd(char c, char type) {
	char c_lo, c_hi;
	c_hi = (c & 0xF0) >> 2; /* Upper 4 bits of c */
	c_lo = (c & 0x0F) << 2; /* Lower 4 bits of c */
	
	if (type == DATA) LCD_DAT |= LCD_RS; /* select LCD data register */
	else LCD_DAT &= (~LCD_RS); /* select LCD command register */
	
	if (type == DATA)
		LCD_DAT = c_hi|LCD_E|LCD_RS; /* output upper 4 bits, E, RS high */
	else
		LCD_DAT = c_hi|LCD_E; /* output upper 4 bits, E, RS low */
	LCD_DAT |= LCD_E; /* pull E signal to high */
	__asm(nop); /* Lengthen E */
	__asm(nop);
	__asm(nop);
 
	LCD_DAT &= (~LCD_E); /* pull E to low */
	if (type == DATA)
		LCD_DAT = c_lo|LCD_E|LCD_RS; /* output lower 4 bits, E, RS high */
	else
		LCD_DAT = c_lo|LCD_E; /* output lower 4 bits, E, RS low */
	LCD_DAT |= LCD_E; /* pull E to high */
	__asm(nop); /* Lengthen E */
	__asm(nop);
	__asm(nop);
 
	LCD_DAT &= (~LCD_E); /* pull E to low */
	delay_50us(1); /* Wait for command to execute */
}
 
#define D50US 133 /* Inner loop takes 9 cycles; need 50x24 = 1200 cycles */
void delay_50us(int n) {
	volatile int c;
	for (;n>0;n--)
		for (c=D50US;c>0;c--) ;
}
 
#define D10US 26
void delay_10us(int n) {
	volatile int c;
	for (;n>0;n--)
		for (c=D10US;c>0;c--) ;
}
 
void delay_1ms(int n) {
	for (;n>0;n--) delay_50us(200);
}
 
void delay_halfms(int n) {
	for (;n>0;n--) delay_50us(100);
}
 
void clearDisplay(void) {
	put2lcd(0x01,CMD); /* clear screen, move cursor to home */
	delay_50us(40); /* wait until "clear display" command is complete */
}
 
void moveCursorToSecondLine(void) {
	put2lcd(0xC0,CMD);
	delay_50us(40); /* wait until "clear display" command is complete */
}

interrupt (((0x10000 - Vtimch0)/2)-1) void intrTimCh0(void) {
  if(buzCounter>0){
    --buzCounter;
    PTT=PTT^BIT5;
  
  }
  //if(wrBuzzerFlag==1)	
	//PTT = PTT ^ BIT5; 
	// using different frequency for highspeed warning
	TC0 += (wrBuzzerFlag==0) ? 750 : 1250;
	TFLG1 |= BIT0;
}