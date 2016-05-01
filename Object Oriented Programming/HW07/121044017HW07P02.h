/*
    121044017HW07P02.h

    Created by Okan Akdogan

    SortedList class
*/

#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include "121044017HW07P01.h"

using namespace ns_myList;


namespace ns_myList{

    template <class T>
    class SortedList:public myList<T>{
    public:
        SortedList();
        //constructor
        SortedList(const SortedList<T>& other);
        //copy constructor
        virtual void addElement(T data);
        //adds element and sorts list
       // virtual SortedList<T> & operator+=(const myList<T> & other);
        //adds list to this list. Uses addElement func.
        virtual SortedList<T>* operator+(const myList<T> & other);
        //union function. gives NEW memory with NEW operator.
        virtual SortedList<T>* operator%(const myList<T> & other);
        //intersection function. gives NEW memory with NEW operator.

        ~SortedList();
    private:
        void sortList();
        void swapValues(int index1,int index2);
    };

    template<class T>
    SortedList<T>::SortedList():myList<T>(){/*empty*/}

    template<class T>
    SortedList<T>::SortedList(const SortedList<T> & other ):myList<T>(){
        unsigned i;
        for(i=0;i<other.getNumOfElements();++i)
            this->addElement(other.index(i));

    }

    template<class T>
    void SortedList<T>::addElement(T data ){
        myList<T>::addElement(data);
        sortList();

    }
/*
    template<class T>
    SortedList<T>& SortedList<T>::operator+=(const myList<T> & other){
        unsigned i;

        for(i=0;i<other.getNumOfElements();++i){
            addElement(other.index(i));
        }

        return *this;
    }
*/
    template<class T>
    SortedList<T>* SortedList<T>::operator+(const myList<T> & other) {
        SortedList<T>* tmpList=new SortedList<T>(*this);

        *tmpList+=other;

        return tmpList;
    }

    template<class T>
    SortedList<T>* SortedList<T>::operator%(const myList<T> & other){
        SortedList<T>* tmpList=new SortedList<T>;
        unsigned i,j;

        for(i=0;i<this->getNumOfElements();++i)
            for(j=0;j<other.getNumOfElements();++j)
                if(this->index(i)==other.index(j))
                    tmpList->addElement(other.index(j));

        return tmpList;
    }

    template<class T>
    SortedList<T>::~SortedList(){
        /*Empty*/
    }


    template<class T>
    void SortedList<T>::sortList(){
        int minValueIndex;
        unsigned i,j;
        for(j=0;j<this->getNumOfElements();++j){
            minValueIndex=j;
            for(i=j;i<this->getNumOfElements();++i)
                if(this->index(i)<this->index(minValueIndex))
                    minValueIndex=i;
            swapValues(minValueIndex,j);
        }
    }


    template <class T>
    void SortedList<T>::swapValues(int index1,int index2){
        T tmp=this->index(index1);
        this->index(index1)=this->index(index2);
        this->index(index2)=tmp;
    }
}
#endif // SORTED_LIST_H
