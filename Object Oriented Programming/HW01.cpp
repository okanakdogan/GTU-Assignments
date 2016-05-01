/*
 * 121044017HW01.cpp
 *
 *  Created on: 25 Eyl 2013
 *      Author: Okan Akdogan
 */

#include <iostream>
#include <string>

#define DEBUG

using namespace std;

int getLineAndSearch(string data,string searchValue,bool ignoreCase );
//search for word in one line and if found returns 1, else returns 0
int upLowSwitch(int ch);
//changes character lowercase-uppercase
//ch character parameter
int compareString(string word,string searchValue,bool ignoreCase);
//compare two words have same size.
//word, searchValue words to compare.
//ignoreCase boolean variable true ignores case-sensitive
//false not ignorse case-sensitive
//if words are same returns 1 o/w 0
void takeLinesAndSearch(string searchValue,bool ignoreCase,bool countLine);
//takes lines one by one and search for seachValue string
//if countline true prints match line's number
//else prints match lines
// ignoreCase changes case-sensitive
//if true ignores elsenot ignores

int main (int argc, char* argv[])
{

    bool ignoreCase=false,countLine=false;
    int i;
    string searchValue="";


#ifdef DEBUG
    cout<< "Number of main arguments: " << argc<<endl;
#endif

    //arguments filter
    if(argc == 1)
        cout << "Missing arguments"<<endl;

    else if(argc==2 && argv[1][0]!='-')
    {

        takeLinesAndSearch(argv[1],ignoreCase,countLine);

    }
    else
    {

        for (i=1; i<argc; ++i)
            if(argv[i][0]=='-')
            {
                if(argv[i][1]=='i' && argv[i][2]=='\0')
                    ignoreCase=true;
                else if(argv[i][1]=='n' && argv[i][2]=='\0')
                    countLine=true;
                else
                    cout<<"wrong option"<<endl;
            }
            else
            {
                if(searchValue=="")
                    searchValue=argv[i];
                else
                    cout<<"wrong arguments"<<endl;
            }
        takeLinesAndSearch(searchValue,ignoreCase,countLine);

    }

    return 0;
}

int getLineAndSearch(string data,string searchValue,bool ignoreCase )
{
    unsigned i=0;
    int result=0;
    int startPos=0;
    int wordlen=0;
    string word="";

    //seperate line to words
    for(i=0; i<data.length(); ++i)
    {
        if(data[i]==' ' )
        {
            word=data.substr(startPos,i-startPos);
            wordlen=word.length();

            //check for non-letters.
            if(word[wordlen-1]=='.' || word[wordlen-1]==',' || word[wordlen-1]=='!' || word[wordlen-1]=='?' )
                word=word.substr(0,wordlen-1);
            startPos=i+1;
            #ifdef DEBUG
                cout<< "Current Word: " << word<<endl;
            #endif

            if(compareString(word,searchValue,ignoreCase))
                result=1;
        }
    }

    // Last word won't seperate in loop. Taking it manually.
    if(data[i-1]==' ' || data[i-1]=='.' || data[i-1]==',' || data[i-1]=='!' || data[i-1]=='?')
        {
            word=data.substr(startPos,i-1-startPos);

        }
    else
        word=data.substr(startPos,i-startPos);

    #ifdef DEBUG
                cout<< "Current Word: " << word<<endl;
    #endif

    if(compareString(word,searchValue,ignoreCase))
        result=1;

    return result;
}

int upLowSwitch(int ch)
{

     if (ch>='a' && ch<='z')
        ch=ch-('a'-'A');
    else if(ch>='A' && ch<='Z')
        ch=ch+('a'-'A');


    return ch;

}
int compareString(string word,string searchValue,bool ignoreCase)
{

    unsigned i;
    int result=1;


    for(i=0; i<=word.size(); ++i)
    {
        if(searchValue[i]=='?')
            continue;
        if(searchValue[i]!=word[i])
        {
            result=0;
            if(ignoreCase==true && upLowSwitch(searchValue[i])==word[i])
                result=1;
        }
    }
    return result;

}

void takeLinesAndSearch(string searchValue,bool ignoreCase,bool countLine)
{

    string data="";
    int lineNumber=0;
    while (getline(cin,data).eof()!=true)
    {
        ++lineNumber;
        #ifdef DEBUG
            cout<< "reading Line: "<<lineNumber<<endl;
        #endif
        if (getLineAndSearch(data,searchValue,ignoreCase))
        {

            if(countLine==false)
                cout<<data<<endl;
            else
                cout<< lineNumber<<endl;
        }
    };

}
