/*
	121044017HW02.cpp
	created by Okan Akdogan on 21/10/2013
	
	HW02 Chess Game

*/


#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

//#define DEBUG

typedef enum {pawn,rook,bishop,knight,queen,king,notPiece} piece_t;

using namespace std;

void resetBoard(char board[][8]);
/*
    resetBoard:
	precondition: char array sized 8x8
	sets pieces to start positions for chess
*/
void printBoard(const char board[][8]);
/*
    printBoard:
	prints all elements in 8x8 array.
*/
char reverseRow(char row);
/*
	precondition: row char must be in range 1-8
	index of rows on chessboard starts from bottom. but in array starts from top.
	this function reverse rows from up to down.
*/
int columnCharToInt(char ch);
/*
	precondition: ch must be in range A-H
	takes char variable and cast to integer.
*/
int rowCharToInt(char ch);
/*
	precondition: ch must be in range 1-8
	takes char variable and cast to integer
*/

string readMove();
/*
	reads move command of user from console and returns in string.
*/
int checkMove(const string gameMove);
/*
	checks move command in gameMove string. Legal form is XY-XY
	X: A to H ; Y: 1 to 8
	returns 1 if legal o/w 0
*/
int checkLocation(const char ch);
/*
	checks character if in range A-H or 1-8
*/
piece_t findPiece(char board[][8],char column,char row);
/*
	finds piece letter in chess board array and returns type enum pieces_t

*/
piece_t pieceFromBoard(const char ch);
/*
	compare character from board with piece list and returns piece_t type
*/

bool isBlackPiece(char board[][8],int row,int column);
/*
	looks location in array and if there is black piece returns true o/w false
*/
bool isWhitePiece(char board[][8],int row,int column);
/*
	looks location in array and if there is white piece returns true o/w false
*/
int abs(const int value);
/*
    takes absolute value of variable
*/

//..Check functions check move for pieces
bool pieceCheck(char board[][8],string gameMove,piece_t piece,bool isWhite=false);
bool pawnCheck(char board[][8],string gameMove,bool isWhite);
bool rookCheck( char board[][8],string gameMove, bool isWhite);
bool knightCheck(char board[][8],string gameMove, bool isWhite);
bool bishopCheck(char board[][8],string gameMove, bool isWhite);
bool queenCheck(char board[][8],string gameMove, bool isWhite);
bool kingCheck(char board[][8],string gameMove, bool isWhite);
void makeMove(char board[][8],string gameMove);

bool areKingsOK(char board[][8]);
/*
    checks if checkMate
*/
string makeBlackMove(char board[][8]);
/*
    creates random black move
*/
char indexLetterConverter(int col);
/*
    converts column index to letter like 0 To A
*/
void makePieceList(char board[][8],int pList[][2],int &lSize);
/*
    array index like 00-01 converting like A1-A2 form.
*/
int main(){

	char board[8][8];

	bool white_turn=true;

    string gameMove="";
    piece_t piece=notPiece;

    resetBoard(board);
    printBoard(board);

	while(areKingsOK(board)){

		//white turn true ise beyaz tas oynar
		if(white_turn==true){

            gameMove=readMove();
            //oyun oku
            if(!gameMove.empty()){
                gameMove[1]=reverseRow(gameMove[1]);
                gameMove[4]=reverseRow(gameMove[4]);
                piece=findPiece(board,gameMove[1],gameMove[0]);
            }
		}
		else{

            //siyah oyunu uydur.
            gameMove=makeBlackMove(board);
            gameMove[1]=reverseRow(gameMove[1]);
            gameMove[4]=reverseRow(gameMove[4]);
            piece=findPiece(board,gameMove[1],gameMove[0]);
		}

        if(piece!=notPiece && pieceCheck(board,gameMove,piece,white_turn)){
            makeMove(board,gameMove);

            printBoard(board);
            if(!white_turn){
                cout<<endl;
                cout<<"Computer Plays "<<gameMove<<endl;
                cout<<endl;
            }
            cout<<endl;
            if(white_turn)
                white_turn=false;
            else
                white_turn=true;
        }
	}
	return 0;
}

void resetBoard(char board[][8]){
    int i,j;

    board[0][0]='k';
    board[0][1]='a';
    board[0][2]='f';
    board[0][3]='s';
    board[0][4]='v';
    board[0][5]='f';
    board[0][6]='a';
    board[0][7]='k';

    for(i=0;i<8;++i)
        board[1][i]='p';

    for(j=2;j<6;++j)
        for(i=0;i<8;++i)
            board[j][i]='.';

    for(i=0;i<8;++i)
        board[6][i]='P';

    board[7][0]='K';
    board[7][1]='A';
    board[7][2]='F';
    board[7][3]='V';
    board[7][4]='S';
    board[7][5]='F';
    board[7][6]='A';
    board[7][7]='K';

}
void printBoard(const char board[][8]){
    int row,column;
    for(row=0;row<8;++row){
        for(column=0;column<8;++column)
            cout<<board[row][column]<<" ";
        cout<<endl;
    }
}
char reverseRow(char row){
    int rowInt=static_cast<int>(row)-48;
    rowInt=9-rowInt;
    return static_cast<char>(rowInt+48);
}
int columnCharToInt(char ch){
   int column=-1;
    switch (ch){
        case 'A': column=0; break;
        case 'B': column=1; break;
        case 'C': column=2; break;
        case 'D': column=3; break;
        case 'E': column=4; break;
        case 'F': column=5; break;
        case 'G': column=6; break;
        case 'H': column=7; break;
        default: column=-1;
    }
    return column;
}
int rowCharToInt(char ch){
    return (static_cast<int>(ch))-49;
}
string readMove(){
    string whiteMove="";

    cout<<"White's Turn Enter Your Move:"<<endl;
    cin>>whiteMove;

    if(whiteMove.length()==5){
        if (checkMove(whiteMove)==1)
            return whiteMove;
        else{
            cout<<"Entered wrong move"<<endl;
            return "";
        }
    }
    else {
        cout<<"Wrong Move length "<<endl;
        return "";
    }

}
int checkMove(const string gameMove){
    int i,strSize=gameMove.length();

    for(i=0;i<strSize;++i){

        if (i==2)
            continue;
        if(checkLocation(gameMove[i])!=1)
            return 0;
    }
    return 1;
}
int checkLocation(const char ch){
    if(('A'<=ch && ch<='H') || ('1'<=ch&&ch<='8')){
        return 1;
    }
    else
        return 0;
}
piece_t findPiece(char board[][8],char row,char column){
    #ifdef DEBUG
        cout<<"row "<<row<<" column "<<column<<endl;
    #endif // DEBUG

    int columnInt=columnCharToInt(column);

    int rowInt=rowCharToInt(row);
    #ifdef DEBUG
        cout<<"rowInt "<<rowInt<<" columnInt "<<columnInt<<endl;
        cout<<"board char "<<board[rowInt][columnInt]<<endl;
    #endif // DEBUG

    if(board[rowInt][columnInt]!='.')
        return pieceFromBoard(board[rowInt][columnInt]) ;
    else
        return notPiece;

}
piece_t pieceFromBoard(const char ch){
    piece_t piece=notPiece;
    #ifdef DEBUG
        cout<<"board char "<<ch<<endl;
    #endif // DEBUG

    switch (ch){
        case 'P':case 'p':piece=pawn; break;
        case 'K': case 'k': piece=rook; break;
        case 'A': case 'a':piece=knight; break;
        case 'F':case 'f': piece=bishop; break;
        case 'V':case 'v': piece=queen;break;
        case 'S': case 's': piece=king; break;
        default: piece=notPiece; break;
    }
    return piece;

}
bool isBlackPiece(char board[][8],int row,int column){
    bool result=false;
    switch (board[row][column]){
        case 'p': result=true;break;
        case 'k': result=true; break;
        case 'a': result=true; break;
        case 'f': result=true; break;
        case 'v': result=true; break;
        case 's': result=true; break;
        default: result=false; break;
    }
    return result;
}
bool isWhitePiece(char board[][8],int row,int column){
    bool result=false;
    switch (board[row][column]){
        case 'P': result=true;break;
        case 'K':result=true; break;
        case 'A': result=true; break;
        case 'F': result=true; break;
        case 'V':result=true;break;
        case 'S':result=true; break;
        default: result=false; break;
    }
    return result;
}
void gameMoveSeparate(string gameMove,int &cRow,int &cColumn,int &tRow,int &tColumn){
        cColumn=columnCharToInt(gameMove[0]);
        cRow=rowCharToInt(gameMove[1]);
        tColumn=columnCharToInt(gameMove[3]);
        tRow=rowCharToInt(gameMove[4]);
}
int abs(const int value){
    if (value<0)
        return -value;
    else
        return value;
}
bool pieceCheck(char board[][8],string gameMove,piece_t piece,bool isWhite){

    switch (piece) {
        case 0: return pawnCheck(board,gameMove,isWhite);
        case 1: return rookCheck(board,gameMove,isWhite);
        case 2: return bishopCheck(board,gameMove,isWhite);
        case 3: return knightCheck(board,gameMove,isWhite);
        case 4: return queenCheck(board,gameMove,isWhite);
        case 5: return kingCheck(board,gameMove,isWhite);
        default: return false;
    }
}
bool pawnCheck(char board[][8],string gameMove, bool isWhite){
    int cColumn,cRow,tColumn,tRow;
    bool legalMove=false;

    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);

    #ifdef DEBUG
        cout<<"current row column"<<cRow<<" "<<cColumn<<endl;
        cout<<"target row column"<<tRow<<" "<<tColumn<<endl;
    #endif // DEBUG

    if(abs(tRow-cRow)==1 && abs(tColumn-cColumn)==0 && board[tRow][tColumn]=='.')
        legalMove=true;
    else if(abs(tRow-cRow)==1 && (abs(tColumn-cColumn)==1) ){
        if(isWhite && isBlackPiece(board,tRow,tColumn))
            legalMove=true;
        else if(!isWhite && isWhitePiece(board,tRow,tColumn))
            legalMove=true;
    }

    #ifdef DEBUG
        if (legalMove)
            cout<<"legal Move"<<endl;
        else
            cout<<"not legal Move"<<endl;
    #endif // DEBUG

    return legalMove;
}
bool rookCheck(char board[][8], string gameMove,bool isWhite){
    int cColumn,cRow,tColumn,tRow;
    bool legalMove=false;

    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);
    if((tRow==cRow && tColumn!=cColumn) || (tRow!=cRow && tColumn==cColumn) ){
         if(isWhite && isBlackPiece(board,tRow,tColumn))
            legalMove=true;
        else if(!isWhite && isWhitePiece(board,tRow,tColumn))
            legalMove=true;
        else if(board[tRow][tColumn]=='.')
            legalMove=true;
    }

    return  legalMove;
}
bool knightCheck(char board[][8],string gameMove, bool isWhite){

    int cColumn,cRow,tColumn,tRow;
    bool legalMove=false;

    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);

    if((abs(tRow-cRow)==2 && abs(tColumn-cColumn)==1) ||(abs(tRow-cRow)==1 && abs(tColumn-cColumn)==2) ){
         if(isWhite && isBlackPiece(board,tRow,tColumn))
            legalMove=true;
        else if(!isWhite && isWhitePiece(board,tRow,tColumn))
            legalMove=true;
        else if(board[tRow][tColumn]=='.')
            legalMove=true;
    }
    return legalMove;
}
bool bishopCheck(char board[][8],string gameMove, bool isWhite){
    int cColumn,cRow,tColumn,tRow;
    bool legalMove=false;

    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);

    if(abs(tRow-cRow)==abs(tColumn-cColumn)){
         if(isWhite && isBlackPiece(board,tRow,tColumn))
            legalMove=true;
        else if(!isWhite && isWhitePiece(board,tRow,tColumn))
            legalMove=true;
        else if(board[tRow][tColumn]=='.')
            legalMove=true;
    }
    return legalMove;
}
bool queenCheck(char board[][8],string gameMove, bool isWhite){
 int cColumn,cRow,tColumn,tRow;
    bool legalMove=false;

    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);

    if (bishopCheck(board,gameMove,isWhite)|| rookCheck(board,gameMove,isWhite)){
        if(isWhite && isBlackPiece(board,tRow,tColumn))
            legalMove=true;
        else if(!isWhite && isWhitePiece(board,tRow,tColumn))
            legalMove=true;
        else if(board[tRow][tColumn]=='.')
            legalMove=true;
    }
    return legalMove;
}
bool kingCheck(char board[][8],string gameMove, bool isWhite){
 int cColumn,cRow,tColumn,tRow;
    bool legalMove=false;

    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);

    if( abs(tRow-cRow)<2 && abs(tColumn-cColumn)<2 && !(tColumn==cColumn && tRow==cRow)){
         if(isWhite && isBlackPiece(board,tRow,tColumn))
            legalMove=true;
        else if(!isWhite && isWhitePiece(board,tRow,tColumn))
            legalMove=true;
        else if(board[tRow][tColumn]=='.')
            legalMove=true;
    }
    return legalMove;
}

string indexConverter(const int cRow,const int cCol,const int tRow,const int tCol ){
    string blackMove="XY-XY";

    blackMove[0]=indexLetterConverter(cCol);
    blackMove[1]=static_cast<char>(9-cRow)+47;
    blackMove[3]=indexLetterConverter(tCol);
    blackMove[4]=static_cast<char>(9-tRow)+47;
    #ifdef DEBUG
        cout << "Converter Result "<<blackMove<<endl;
    #endif // DEBUG

    return blackMove;
}
char indexLetterConverter(int col){
    char ch=' ';
    switch (col){
        case 0:ch='A';break;
        case 1:ch='B';break;
        case 2:ch='C'; break;
        case 3:ch='D'; break;
        case 4:ch='E'; break;
        case 5: ch='F';break;
        case 6:ch='G'; break;
        case 7:ch='H'; break;
        default: ch=' ';
    }
    return ch;
}
void makeMove(char board[][8],string gameMove){
    int cColumn,cRow,tColumn,tRow;
    char ch;
    gameMoveSeparate(gameMove,cRow,cColumn,tRow,tColumn);
    ch=board[cRow][cColumn];
    board[cRow][cColumn]='.';
    board[tRow][tColumn]=ch;
}
bool areKingsOK(char board[][8]){
    int row,column;
    bool bKing=false,wKing=false;

    for(row=0;row<8;++row){
        for(column=0;column<8;++column){
            if(board[row][column]=='s')
                bKing=true;
            else if(board[row][column]=='S')
                wKing=true;
        }
    }
    return wKing&&bKing;
}
string makeBlackMove(char board[][8]){
    int i=0,listSize=0;
    int cRow,cColumn,tRow,tColumn=-1;
    int pList[16][2]={0};
    bool status=true;
    string gameMove="";

    srand(time(NULL));
    do{

        makePieceList(board,pList,listSize);
        i=rand()%listSize;
        cRow=pList[i][0];
        cColumn=pList[i][1];

        tRow=rand()%8;
        i=0;
        do{
            if(tColumn==7){
                tColumn=0;
                tRow=rand()%8;
            }
            else
                ++tColumn;

            gameMove=indexConverter(cRow,cColumn,tRow,tColumn);
            ++i;
            if (i>60)
                break;
        }while(status=!pieceCheck(board,gameMove,findPiece(board,gameMove[1],gameMove[0])));

    }while(status);
    return gameMove;
}
void makePieceList(char board[][8],int pList[][2],int &lSize){
    int row=-1,col=-1;
    int counter=0;

    for(row=0;row<8;++row){
        for(col=0;col<8;++col){
            if(isBlackPiece(board,row,col)){

                pList[counter][0]=row;
                pList[counter][1]=col;
                ++counter;
            }
        }
    }
      lSize=counter;
}
