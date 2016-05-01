/*
    121044017HW06P01.cpp
    Created by Okan Akdogan
    121044017

    AppSoftware Class Imp. File
*/


#include "121044017HW06P01.h"
#include <iostream>

using namespace std;

namespace ns_AppSoftware{

    unsigned AppSoftware::_aliveObj=0;

    AppSoftware::AppSoftware(){
        ++_aliveObj;
    }

    void AppSoftware::setName(string name){
        if (!name.empty())
            _name=name;
    }

    void AppSoftware::setSystem(string system){
        if(system=="Windows" || system=="OSX"|| system=="Linux")
            _system=system;
    }

    AppSoftware::~AppSoftware(){
        --_aliveObj;
    }
}
