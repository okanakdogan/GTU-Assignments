/*
    121044017HW04.cpp
    Okan Akdogan
    121044017

    chess game with classes

*/
#include <iostream>
#include <vector>   //vector<>
#include <cstdlib> //srand rand
#include <ctime>    //time()
using namespace std;

class BoardPosition{

public:
    BoardPosition();
    BoardPosition(char column,int row);
    bool setPosition(char sColumn,int sRow);
    char getColumn() const;
    int getColumnInt() const;
    int getRow() const;
    void reverseRow();

    static int getNumberOfObjects() ;
    bool isWhite() const;
    void inputPosition();
    void outputPosition() const;
    bool operator==(const BoardPosition other);
private:
    char _column;
    int _row;
    static int _numberOfObjects;
};

class ChessPiece{
public:
    ChessPiece();
    ChessPiece(string name,bool isWhitePiece=true);
    bool canMove(BoardPosition bPos);
    string getPieceName();
    bool isWhitePiece();
    BoardPosition & getBoardPosition();
    bool setPosition(char column,int row);
private:
    bool pawnCanMove(BoardPosition bPos);
    bool rookCanMove(BoardPosition bPos);
    bool bishopCanMove(BoardPosition bPos);
    bool knightCanMove(BoardPosition bPos);
    bool queenCanMove(BoardPosition bPos);
    bool kingCanMove(BoardPosition bPos);
    int abs(int number) const;
    string _name;
    bool _isWhitePiece;
    BoardPosition _boardPosition;
};

class ChessBoard{
public:
    ChessBoard();
    void printBoard();
    bool moveBlack(const BoardPosition source,const BoardPosition target);
    bool moveWhite(const BoardPosition source,const BoardPosition target);
    bool isGameFinished();
    bool isWhitesTurn();
    void switchTurn();
    unsigned getMoveCount();
    void addMoveCount();
    BoardPosition randomSource();
    BoardPosition randomTarget(BoardPosition source);

private:
    void setBlackPieces();
    void setWhitePieces();
    char charUpper(const char ch);
    int indexOfPiece(const BoardPosition bPos,bool isWhite);
    bool checkMove(const int index,const BoardPosition source,const BoardPosition target,const bool isWhite) ;
    bool checkMovePawn(const BoardPosition source,const BoardPosition target,const bool isWhite);
    bool checkMoveRook(const BoardPosition source,const BoardPosition target,const bool isWhite);
    bool scanRange(const BoardPosition source,const BoardPosition target,bool inRow);
    bool checkMoveKnight(const BoardPosition source,const BoardPosition target,const bool isWhite);
    bool checkMoveBishop(const BoardPosition source,const BoardPosition target,const bool isWhite);
    bool scanRangeDiagonal(const BoardPosition source,const BoardPosition target);
    bool checkMoveQueen(const BoardPosition source,const BoardPosition target,const bool isWhite);
    bool checkMoveKing(const BoardPosition target,const bool isWhite);

    vector<ChessPiece> _whitePiecesVector;
    vector<ChessPiece> _blackPiecesVector;
    unsigned _moveCount;
    bool _isWhitesTurn;
};

ChessBoard::ChessBoard(){
    setBlackPieces();
    setWhitePieces();
    _isWhitesTurn=true;
    _moveCount=0;
}
void ChessBoard::printBoard(){
    int i,j,index;
    string columns="0ABCDEFGH";
    BoardPosition bPos;

    for(i=1;i<=8;++i){
        for(j=1;j<=8;++j){
            bPos.setPosition(columns[j],i);
            if((index=indexOfPiece(bPos,true))!=-1)
                cout<<charUpper(_whitePiecesVector[index].getPieceName()[0]);
            else if((index=indexOfPiece(bPos,false))!=-1)
                cout<<_blackPiecesVector[index].getPieceName()[0];
            else
                cout<<'.';
        }
        cout<<endl;
    }

}

void ChessBoard::setBlackPieces(){
    int i;
    string columns="ABCDEFGH";
    for(i=0;i<8;++i){
        _blackPiecesVector.push_back(ChessPiece("piyon",false));
        _blackPiecesVector[i].setPosition(columns[i],2);
    }
    // black rooks set
    _blackPiecesVector.push_back(ChessPiece("kale",false));
    _blackPiecesVector[8].setPosition('A',1);

    _blackPiecesVector.push_back(ChessPiece("kale",false));
    _blackPiecesVector[9].setPosition('H',1);

    //black knights set
    _blackPiecesVector.push_back(ChessPiece("at",false));
    _blackPiecesVector[10].setPosition('B',1);

    _blackPiecesVector.push_back(ChessPiece("at",false));
    _blackPiecesVector[11].setPosition('G',1);


    //black bishops set
    _blackPiecesVector.push_back(ChessPiece("fil",false));
    _blackPiecesVector[12].setPosition('C',1);

    _blackPiecesVector.push_back(ChessPiece("fil",false));
    _blackPiecesVector[13].setPosition('F',1);

    // queen and king
    _blackPiecesVector.push_back(ChessPiece("vezir",false));
    _blackPiecesVector[14].setPosition('D',1);

    _blackPiecesVector.push_back(ChessPiece("sah",false));
    _blackPiecesVector[15].setPosition('E',1);
}

void ChessBoard::setWhitePieces(){
    int i;
    string columns="ABCDEFGH";
    for(i=0;i<8;++i){
        _whitePiecesVector.push_back(ChessPiece("piyon",true));
        _whitePiecesVector[i].setPosition(columns[i],7);
    }
    // white rooks set
    _whitePiecesVector.push_back(ChessPiece("kale",true));
    _whitePiecesVector[8].setPosition('A',8);

    _whitePiecesVector.push_back(ChessPiece("kale",true));
    _whitePiecesVector[9].setPosition('H',8);

    //white knights set
    _whitePiecesVector.push_back(ChessPiece("at",true));
    _whitePiecesVector[10].setPosition('B',8);

    _whitePiecesVector.push_back(ChessPiece("at",true));
    _whitePiecesVector[11].setPosition('G',8);


    //white bishops set
    _whitePiecesVector.push_back(ChessPiece("fil",true));
    _whitePiecesVector[12].setPosition('C',8);

    _whitePiecesVector.push_back(ChessPiece("fil",true));
    _whitePiecesVector[13].setPosition('F',8);

    // queen and king
    _whitePiecesVector.push_back(ChessPiece("vezir",true));
    _whitePiecesVector[14].setPosition('E',8);

    _whitePiecesVector.push_back(ChessPiece("sah",true));
    _whitePiecesVector[15].setPosition('D',8);
}

char ChessBoard::charUpper(const char ch){
    return (ch+('A'-'a'));
}
bool ChessBoard::isGameFinished(){
    int i;
    bool blackKing=false,whiteKing=false;
    for(i=0;i<_blackPiecesVector.size();++i)
        if(_blackPiecesVector.at(i).getPieceName()=="king")
            blackKing=true;

    for(i=0;i<_whitePiecesVector.size();++i)
        if(_whitePiecesVector.at(i).getPieceName()=="king")
            whiteKing=true;

    return !(blackKing&&whiteKing);
}

bool ChessBoard::isWhitesTurn(){
    return _isWhitesTurn;
}

void ChessBoard::switchTurn(){
    if (_isWhitesTurn)
        _isWhitesTurn=false;
    else
        _isWhitesTurn=true;
}

unsigned ChessBoard::getMoveCount(){
    return _moveCount;
}
void ChessBoard::addMoveCount(){
    ++_moveCount;
}

BoardPosition ChessBoard::randomSource(){
    int index;
    srand(time(NULL));

    index=rand()%static_cast<int>(_blackPiecesVector.size());
    return (_blackPiecesVector.at(index).getBoardPosition());
}

BoardPosition ChessBoard::randomTarget(BoardPosition source){
    int row,columnInt,i,index;
    string columns="0ABCDEFGH";
    BoardPosition bPos;
    srand(time(NULL));
    index=indexOfPiece(source,false);

    for(i=0;i<20;++i){
        row=(rand()%8)+1;
        columnInt=(rand()%8)+1;
        bPos.setPosition(columns[columnInt],row);
        if(_blackPiecesVector.at(index).canMove(bPos))
            break;
    }
    return bPos;
}

int ChessBoard::indexOfPiece(const BoardPosition bPos,bool isWhite){
    int i;
    if (isWhite){
        for(i=0;i<_whitePiecesVector.size();++i){
            if(_whitePiecesVector[i].getBoardPosition()==bPos)
                return i;
        }

    }
    else
         for(i=0;i<_blackPiecesVector.size();++i){
            if(_blackPiecesVector.at(i).getBoardPosition()==bPos)
                return i;
        }
    return -1;
}

bool ChessBoard::moveWhite(const BoardPosition source,const BoardPosition target){
    int index=indexOfPiece(source,true);
    int tIndex;
    if(index!=-1){
        if(_whitePiecesVector.at(index).canMove(target) && checkMove(index,source,target,true)){
           if((tIndex=indexOfPiece(target,false))!=-1)
                _blackPiecesVector.erase(_blackPiecesVector.begin()+(tIndex+1));
           _whitePiecesVector[index].getBoardPosition()=target;
            return true;
        }
    }
    return false;
}

bool ChessBoard::moveBlack(const BoardPosition source,const BoardPosition target){
    int index=indexOfPiece(source,false);
    int tIndex;
    if(index!=-1){
        if(_blackPiecesVector.at(index).canMove(target) && checkMove(index,source,target,false)){
           if((tIndex=indexOfPiece(target,true))!=-1)
                _whitePiecesVector.erase(_whitePiecesVector.begin()+(tIndex+1));
           _blackPiecesVector[index].getBoardPosition()=target;
           return true;
        }
    }
    return false;
}

bool ChessBoard::checkMove(const int index,const BoardPosition source,const BoardPosition target,const bool isWhite){
   string name="";
    if(isWhite){
        name=_whitePiecesVector.at(index).getPieceName();
    }
    else
        name=_blackPiecesVector.at(index).getPieceName();

    if (name=="piyon")
        return checkMovePawn(source,target,isWhite);
    else if(name=="kale")
        return checkMoveRook(source,target,isWhite);
    else if(name=="fil")
        return checkMoveBishop(source,target,isWhite);
    else if(name=="at")
        return checkMoveKnight(source,target,isWhite);
    else if(name=="vezir")
        return checkMoveQueen(source,target,isWhite);
    else if(name=="sah")
        return checkMoveKing(target,isWhite);
    else
        cerr<<"Wrong piece name in ChessBoard::checkMove Func."<<endl;
    return false;
}

bool ChessBoard::checkMovePawn(const BoardPosition source,const BoardPosition target,const bool isWhite){

    if(source.getColumnInt()==target.getColumnInt() &&
        indexOfPiece(target,true)==-1 && indexOfPiece(target,false)==-1)
        return true;
    else{
        if(isWhite){
            return (indexOfPiece(target,false)!=-1);
        }
        else{
            return (indexOfPiece(target,true)!=-1);
        }
    }
}

bool ChessBoard::checkMoveRook(const BoardPosition source,const BoardPosition target,const bool isWhite){
   bool rangeStatus=false;
    int i;
    if(source.getRow()!=target.getRow() && scanRange(source,target,true))
        rangeStatus=true;
    else if(source.getColumnInt()!=target.getColumnInt() && scanRange(source,target,false))
        rangeStatus=true;

    if(isWhite){
        if(indexOfPiece(target,true)==-1)
            return rangeStatus;
        else
            return false;
    }
    else{
        if(indexOfPiece(target,false)==-1)
            return rangeStatus;
        else
            return false;

    }

}

bool ChessBoard::scanRange(const BoardPosition source,const BoardPosition target,bool inRow){
    int sPos,ePos;
    BoardPosition bPos;
    string columns="0ABCDEFGH";
    if (inRow){
        sPos=(source.getRow()<target.getRow()?source.getRow():target.getRow())+1;
        ePos=source.getRow()>target.getRow()?source.getRow():target.getRow();
        for(;sPos<ePos;++sPos){
                bPos.setPosition(source.getColumn(),sPos);
            if(indexOfPiece(bPos,true)!=-1)
                return false;
            if(indexOfPiece(bPos,false)!=-1)
                return false;
        }
    }
    else{
        sPos=(source.getColumnInt()<target.getColumnInt()?source.getColumnInt():target.getColumnInt())+1;
        ePos=source.getColumnInt()>target.getColumnInt()?source.getColumnInt():target.getColumnInt();
        for(;sPos<ePos;++sPos){
                bPos.setPosition(columns[sPos],source.getRow());
            if(indexOfPiece(bPos,true)!=-1)
                return false;
            if(indexOfPiece(bPos,false)!=-1)
                return false;
        }
    }
    return true;
}

bool ChessBoard::checkMoveKnight(const BoardPosition source,const BoardPosition target,const bool isWhite){
    return(indexOfPiece(target,isWhite)==-1);
}
ChessPiece::ChessPiece(){
    _name="";
    _isWhitePiece=true;
}
bool ChessBoard::checkMoveBishop(const BoardPosition source,const BoardPosition target,const bool isWhite){
    int scanStatus=false;
    if (scanRangeDiagonal(source,target))
        scanStatus=true;
    if(indexOfPiece(target,isWhite)==-1)
        return scanStatus;
    return false;
}

bool ChessBoard::scanRangeDiagonal(const BoardPosition source,const BoardPosition target){
    int sPos,ePos,columnInt,addValue;
    BoardPosition bPos;
    string columns="0ABCDEFGH";

    sPos=(source.getRow()<target.getRow()?source.getRow():target.getRow())+1;
    ePos=source.getRow()>target.getRow()?source.getRow():target.getRow();

    if(source.getColumnInt()<target.getColumnInt())
        addValue=1;
    else
        addValue=-1;

    columnInt=source.getColumnInt()+addValue;

    for(;sPos<ePos;++sPos,columnInt+=addValue){
        bPos.setPosition(columns[columnInt],sPos);
        if(indexOfPiece(bPos,true)!=-1)
            return false;
        if(indexOfPiece(bPos,false)!=-1)
            return false;
    }
    return true;
}

bool ChessBoard::checkMoveQueen(const BoardPosition source,const BoardPosition target,const bool isWhite){
    if (source.getRow()!=target.getRow() && source.getColumnInt()!=target.getColumnInt())
        return checkMoveBishop(source,target,isWhite);
    else
        return checkMoveRook(source,target,isWhite);
}

bool ChessBoard::checkMoveKing(const BoardPosition target,const bool isWhite){
    return (indexOfPiece(target,isWhite)==-1);
}

ChessPiece::ChessPiece(string name,bool isWhitePiece){
    int i;
    const int pSize=6;
    string pieceNames[]={"piyon","kale","fil","at","vezir","sah"};
    _name="";
    for(i=0;i<pSize;++i){
        if(name==pieceNames[i]){
            _name=name;
            break;
        }
    }
    if(i==pSize)
        cerr<<"Error name assignment in ChessPiece Constructor"<<endl;

    _isWhitePiece=isWhitePiece;

}

bool ChessPiece::pawnCanMove(BoardPosition bPos){

    return (abs(bPos.getRow()-_boardPosition.getRow())==1 && abs(bPos.getColumnInt()-_boardPosition.getColumnInt())<2);
}

bool ChessPiece::rookCanMove(BoardPosition bPos){

    return((bPos.getRow()==_boardPosition.getRow() && bPos.getColumnInt()!=_boardPosition.getColumnInt())
       || (bPos.getRow()!=_boardPosition.getRow() && bPos.getColumnInt()==_boardPosition.getColumnInt()));
}
bool ChessPiece::bishopCanMove(BoardPosition bPos){

    return (abs(bPos.getRow()-_boardPosition.getRow())==abs(bPos.getColumnInt()-_boardPosition.getColumnInt()));
}
bool ChessPiece::knightCanMove(BoardPosition bPos){

    return ((abs(bPos.getRow()-_boardPosition.getRow())==2 && abs(bPos.getColumnInt()-_boardPosition.getColumnInt())==1)
    || (abs(bPos.getRow()-_boardPosition.getRow())==1 && abs(bPos.getColumnInt()-_boardPosition.getColumnInt())==2));
}

bool ChessPiece::queenCanMove(BoardPosition bPos){
    return bishopCanMove(bPos)||rookCanMove(bPos);
}

bool ChessPiece::kingCanMove(BoardPosition bPos){

    return (abs(bPos.getRow()-_boardPosition.getRow())<2 && abs(bPos.getColumnInt()-_boardPosition.getColumnInt())<2
            && !(bPos.getRow()==_boardPosition.getRow()) && bPos.getColumnInt()==_boardPosition.getColumnInt());
}

bool ChessPiece::canMove(BoardPosition bPos){

    if (_name=="piyon")
        return pawnCanMove(bPos);
    else if (_name=="kale")
        return rookCanMove(bPos);
    else if (_name=="fil")
        return bishopCanMove(bPos);
    else if (_name=="at")
        return knightCanMove(bPos);
    else if (_name=="vezir")
        return queenCanMove(bPos);
    else if (_name=="sah")
        return kingCanMove(bPos);
    else{
        cerr<<"ChessPiece::canMove _name match not found"<<endl;
        return false;
    }
}

int ChessPiece::abs(int number)const{
    return (number<0)?(-number):(number);
}

string ChessPiece::getPieceName(){
    return _name;
}

bool ChessPiece::isWhitePiece(){
    return _isWhitePiece;
}
BoardPosition& ChessPiece::getBoardPosition(){
    return _boardPosition;
}
bool ChessPiece::setPosition(char column,int row){
    return _boardPosition.setPosition(column,row);
}

int BoardPosition::_numberOfObjects=0;

BoardPosition::BoardPosition(){
    ++_numberOfObjects;
}
BoardPosition::BoardPosition(char column,int row){
    setPosition(column,row);
    ++_numberOfObjects;
}
bool BoardPosition::setPosition(char column,int row){

    if(('A'<=column && 'H'>=column) &&(1<=row&&8>=row)){
        _column=column;
        _row=row;
        return true;
    }
    else
        return false;
}
char BoardPosition::getColumn() const{
    return _column;
}
int BoardPosition::getRow() const{
    return _row;
}
int BoardPosition::getColumnInt() const{
    return (_column-'A'+1);
}
int BoardPosition::getNumberOfObjects(){
    return _numberOfObjects;
}
void BoardPosition::reverseRow(){
    _row=9-_row;
}
bool BoardPosition::isWhite() const{
    int cColumn=getColumnInt();
    return ((_row+cColumn)%2==0)?true:false;
}

void BoardPosition::inputPosition(){
        bool status;
        char column,row;
        cin>>column>>row;
        status=setPosition(column,(row-'0'))?true:false;
        if (!status){
            cout<<"Wrong Position"<<endl;
        }
}
void BoardPosition::outputPosition() const{
    cout<<_column<<_row;
}

bool BoardPosition::operator==(const BoardPosition other){
    if(_row==other.getRow() && _column==other.getColumn())
        return true;
    else
        return false;
}

int main()
{
    BoardPosition source,target;
    ChessBoard board;
    char ch;

    board.printBoard();

/*
    source=board.randomSource();
            source.outputPosition();
            cout<<"**"<<endl;
            target=board.randomTarget(source);
    target.outputPosition();
*/
    while(board.isGameFinished()){
        if(board.isWhitesTurn()){
            cout<<"Enter Move for white:"<<endl;
            source.inputPosition();
            cin>>ch;
            target.inputPosition();
            source.reverseRow();
            target.reverseRow();
            if(board.moveWhite(source,target)){
                board.addMoveCount();
                board.switchTurn();
                board.printBoard();
                cout<<endl;
            }
        }
        else{

            source=board.randomSource();
            target=board.randomTarget(source);
            /*
            cout<<"Enter Move for black:"<<endl;
            source.inputPosition();
            cin>>ch;
            target.inputPosition();
            source.reverseRow();
            target.reverseRow();
*/
            if(board.moveBlack(source,target)){
                board.addMoveCount();
                board.switchTurn();
                board.printBoard();
                cout<<endl;
            }
        }
    }

    return 0;
}
