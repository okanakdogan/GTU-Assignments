/*
    121044017HW07P01.cpp

    Created by Okan Akdogan

    myList class
*/
#include "121044017HW07P01.h"

using namespace ns_myList;
using namespace std;

namespace ns_myList{

    template <class T>
    myList<T>::myList(){
        _tPtr=new T(2);
        _numOfElements=0;
    }

    template <class T>
    myList<T>::myList(const myList<T>& other){
        _numOfElements=0;
        *this+=other;
    }
/*
    template<class T>
    void myList<T>::addElement(T data){
        T* tmpTPtr=new T(getNumOfElements()+1);
        int i;
        for(i=0;i<getNumOfElements();++i)
            tmpTPtr[i]=_tPtr[i];
        tmpTPtr[getNumOfElements()]=data;
        delete _tPtr;
        _tPtr=tmpTPtr;

    }
*/

    template<class T>
    bool myList<T>::removeElement(T data){
        int index=searchElement(data);
        if(index!=-1){
            T* tmpTPtr=new T(_numOfElements-1);
            int i,j;

            for(i=0,j=0;i<_numOfElements;++i){
                if(i!=index){
                    tmpTPtr[j]=_tPtr[i];
                    ++j;
                }
            }
            delete [] _tPtr;
            _tPtr=tmpTPtr;

            return true;
        }
        else
            return false;
    }

    template<class T>
    int myList<T>::searchElement(T data)const{
        int i;
        for(i=0;i<_numOfElements;++i){
            if(_tPtr[i]=data){
                return i;
            }
        }
        return -1;
    }

    template <class T>
    unsigned myList<T>::getNumOfElements()const{
        return _numOfElements;
    }

    template <class T>
    T& myList<T>::index(int i)const{
        return _tPtr[i];
    }
/*
    template<class T>
    myList<T>& myList<T>::operator+=(const myList<T> & other){
        T* tmpTPtr=new T(getNumOfElements()+other.getNumOfElements());
        int i,j;

        for(i=0;i<getNumOfElements();++i){
            tmpTPtr[i]=_tPtr[i];
        }
        for(i=0,j=getNumOfElements();i<other.getNumOfElements();++i,++j){
            tmpTPtr[j]=other.index(i);
        }
        _numOfElements+=other.getNumOfElements();
        delete [] _tPtr;
        _tPtr=tmpTPtr;

        return *this;
    }
    template <class T>
    myList<T> myList<T>::operator%(const myList<T> & other){
        myList<T> nList;
        int i,j;

        for(i=0;i<getNumOfElements();++i)
            for(j=0;j<other.getNumOfElements();++j)
                if(_tPtr[i]==other.index(j))
                    nList.addElement(_tPtr[i]);
        return nList;
    }
    */
    template<class T>
    ostream& operator<<(ostream& out,myList<T>& nList){

        int i;
        for(i=0;i<nList.getNumOfElements;++i){
            out<<nList.index(i);
            out<<endl;
            return out;
        }
    }

    template <class T>
    myList<T>::~myList(){
        delete [] _tPtr;
    }

}//ns_myList
