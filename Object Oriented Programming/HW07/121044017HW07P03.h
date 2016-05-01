
/*
    121044017HW07P02.h

    Created by Okan Akdogan

    UniqeList class
*/


#ifndef UNIQE_LIST_H
#define UNIQE_LIST_H

#include "121044017HW07P01.h"

namespace ns_myList{

    template <class T>
    class UniqeList:public myList<T>{
    public:
        UniqeList();
        //constructor
        UniqeList(const UniqeList<T>& other);
        //copy constructor
        virtual void addElement(T data);
        //adds element if data not in list.
     //   virtual UniqeList<T> & operator+=(const myList<T> & other);
        //adds list to this list. Uses addElement func.
        virtual UniqeList<T>* operator+(const myList<T> & other);
        //union function. gives NEW memory with NEW operator.
        virtual UniqeList<T>* operator%(const myList<T> & other);
        //intersection function. gives NEW memory with NEW operator.

        ~UniqeList();
    private:

        void sortList();
        void swapValues(int index1,int index2);
    };

    template<class T>
    UniqeList<T>::UniqeList():myList<T>(){/*empty*/}

    template<class T>
    UniqeList<T>::UniqeList(const UniqeList<T> & other ):myList<T>(){
        unsigned i;
        for(i=0;i<other.getNumOfElements();++i)
            this->addElement(other.index(i));

    }

    template<class T>
    void UniqeList<T>::addElement(T data ){
        if(this->searchElement(data)==-1){
            myList<T>::addElement(data);
            sortList();
        }
    }
/*
    template<class T>
    UniqeList<T>& UniqeList<T>::operator+=(const myList<T> & other){
        unsigned i;

        for(i=0;i<other.getNumOfElements();++i){
            addElement(other.index(i));
        }

        return *this;
    }
*/
    template<class T>
    UniqeList<T>* UniqeList<T>::operator+(const myList<T> & other) {
        UniqeList<T>* tmpList=new UniqeList<T>(*this);

        *tmpList+=other;


        return tmpList;
    }

    template<class T>
    UniqeList<T>* UniqeList<T>::operator%(const myList<T> & other){
        UniqeList<T>* tmpList=new UniqeList<T>;
        unsigned i,j;

        for(i=0;i<this->getNumOfElements();++i)
            for(j=0;j<other.getNumOfElements();++j)
                if(this->index(i)==other.index(j))
                    tmpList->addElement(other.index(j));

        return tmpList;
    }

    template<class T>
    UniqeList<T>::~UniqeList(){
        /*Empty*/
    }


    template<class T>
    void UniqeList<T>::sortList(){
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
    void UniqeList<T>::swapValues(int index1,int index2){
        T tmp=this->index(index1);
        this->index(index1)=this->index(index2);
        this->index(index2)=tmp;
    }

}

#endif // UNIQE_LIST_H
