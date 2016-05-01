/*
	121044017HW03.cpp
	created by Okan Akdogan on 29/10/2013

	BoardPosition class

*/
#include <iostream>

using namespace std;

class BoardPosition{

public:
    BoardPosition();
    BoardPosition(char column,int row);
    bool setPosition(char sColumn,int sRow);
    char getColumn() const;
    int getColumnInt() const;
    int getRow() const;

    static int getNumberOfObjects() ;
    bool isWhite() const;
    void inputPosition();
    void outputPosition() const;
private:
    char _column;
    int _row;
    static int _numberOfObjects;
};

int BoardPosition::_numberOfObjects=0;

BoardPosition::BoardPosition(){
    ++_numberOfObjects;
}
BoardPosition::BoardPosition(char column,int row){
    setPosition(column,row);
    ++_numberOfObjects;
}
// Takes legal values for row and column
bool BoardPosition::setPosition(char column,int row){

    if(('A'<=column && 'H'>=column) &&(1<=row&&8>=row)){
        _column=column;
        _row=row;
        return true;
    }
    else
        return false;
}
//returns column
char BoardPosition::getColumn() const{
    return _column;
}
//returns row
int BoardPosition::getRow() const{
    return _row;
}
//returns column integer
int BoardPosition::getColumnInt() const{
    return (_column-'A'+1);
}
//returns created object count
int BoardPosition::getNumberOfObjects(){
    return _numberOfObjects;
}
// returns true if square is white o/w false
bool BoardPosition::isWhite() const{
    int cColumn=getColumnInt();
    return ((_row+cColumn)%2==0)?true:false;
}
//takes position from standart input
void BoardPosition::inputPosition(){
        bool status;
        char column,row;
        cin>>column>>row;
        status=setPosition(column,(row-'0'))?true:false;
        if (!status){
            cout<<"Wrong Position"<<endl;
        }
}
//prints column and row standart output
void BoardPosition::outputPosition() const{
    cout<<_column<<_row;
}
int main()
{
    /*I/O Functions*/
    BoardPosition pos('A',1);
    cout<<"I/O functions"<<endl;
    cout<<"Output function"<<endl;
    pos.outputPosition();
    cout<<endl<<"input function"<<endl;
    pos.inputPosition();
    cout<<"Output function"<<endl;
    pos.outputPosition();

    /*get functions*/
    pos.outputPosition();
    cout<<endl<<"get functions"<<endl;
    cout<<"Column: "<<pos.getColumn()<<endl;
    cout<<"Column: "<<pos.getColumnInt()<<endl;
    cout<<"Row: "<<pos.getRow()<<endl;

    /*is White Functions*/
    pos.outputPosition();
    cout<<endl<<"isWhite"<<endl;
    if (pos.isWhite())
        cout<<"White"<<endl;
    else
        cout<<"Black"<<endl;

    /*numberOfObjects*/
    //second object
    BoardPosition();
    cout<<"numberOfObj: "<<pos.getNumberOfObjects()<<endl;

    return 0;
}
