/*
    121044017HW07P01.h

    Created by Okan Akdogan

    myList class
*/

#ifndef MY_LIST_H
#define MY_LIST_H

#include <iostream>
using namespace std;

namespace ns_myList{

    template <class T>
    class myList{
    public:
        myList();
        virtual void addElement(T data);
        //adds new element
        bool removeElement(T data);
        //finds and removes element
        //if there are two of this data removes lower indexed
        int searchElement(T data) const;
        //finds data in list if not exist returns -1
        unsigned getNumOfElements()const;
        // gets number of elements(list size)
        T& index(int i) const;
        //gets element given index

        myList<T> & operator+=(const myList<T> & other);
        //add lists to this list
        virtual myList<T>* operator+(const myList<T> & other)=0;
        //union function for two lists
        virtual myList<T>* operator%(const myList<T> & other)=0;
        //intersection function for two lists
        template <class T2>friend ostream & operator<<(ostream& out,myList<T2> & l);
        //stream insertion overload

        virtual ~myList();
    private:
        T* _tPtr;
        unsigned _numOfElements;
    };


    template <class T>
    myList<T>::myList(){
        _tPtr=new T(2);
        _numOfElements=0;
    }

    template<class T>
    void myList<T>::addElement(T data){

        if(getNumOfElements()==0){
            _tPtr[0]=data;
            ++_numOfElements;
        }
        else{
            T* tmpTPtr=new T[getNumOfElements()+1];
            unsigned i;

            for(i=0;i<getNumOfElements();++i)
                tmpTPtr[i]=_tPtr[i];
            tmpTPtr[getNumOfElements()]=data;

            delete [] _tPtr;
            _tPtr=tmpTPtr;
            ++_numOfElements;
        }
    }


    template<class T>
    bool myList<T>::removeElement(T data){
        int index=searchElement(data);
        if(index!=-1){
            T* tmpTPtr=new T(getNumOfElements()-1);
            int i,j;

            for(i=0,j=0;i<getNumOfElements();++i){
                if(i!=index){
                    tmpTPtr[j]=_tPtr[i];
                    ++j;
                }
            }
            delete [] _tPtr;
            _tPtr=tmpTPtr;
            --_numOfElements;

            return true;
        }
        else
            return false;
    }

    template<class T>
    int myList<T>::searchElement(T data)const{
        unsigned i;
        for(i=0;i<getNumOfElements();++i){
            if(_tPtr[i]==data){
                return i;
            }
        }
        return -1;
    }

    template<class T>
    myList<T> & myList<T>::operator+=(const myList<T>& other){
         unsigned i;

        for(i=0;i<other.getNumOfElements();++i){
            addElement(other.index(i));
        }

        return *this;

    }

    template <class T>
    unsigned myList<T>::getNumOfElements()const{
        return _numOfElements;
    }

    template <class T>
    T& myList<T>::index(int i)const{
        return _tPtr[i];
    }

    template<class T2>
    ostream& operator<<(ostream& out,myList<T2>& nList){

        unsigned i;
        for(i=0;i<nList.getNumOfElements();++i){
            out<<nList.index(i);
            out<<endl;
        }
        return out;
    }

    template <class T>
    myList<T>::~myList(){
        delete [] _tPtr;
    }


}//ns_myList

#endif // myList_H
