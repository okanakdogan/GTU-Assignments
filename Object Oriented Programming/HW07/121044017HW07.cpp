/*
    121044017HW07.cpp
    Created by Okan Akdogan

    GYTE - Cse241 HW07 List class

*/

#include <iostream>
#include "121044017HW07P02.h"
#include "121044017HW07P03.h"

using namespace std;
using namespace ns_myList;

int main(){

    /*Test Of Lists*/

    UniqeList<int> uList;
    SortedList<int> sList;

    myList<int>* tmpList;

    uList.addElement(1);
    uList.addElement(5);
    uList.addElement(2);
    uList.addElement(20); //
    uList.addElement(30);
    uList.addElement(20); //same element

    sList.addElement(1);
    sList.addElement(3);
    sList.addElement(7);
    sList.addElement(8);
    sList.addElement(5);

    uList+=sList;

    cout<<"union"<<endl;
    tmpList=sList+uList; //+ and % operators gives array memory with new operator
    cout<<*tmpList<<endl;
    delete tmpList;


    cout<<"intersection"<<endl;
    tmpList=uList%sList;
    cout<<*tmpList;
    delete tmpList;

    return 0;
}
