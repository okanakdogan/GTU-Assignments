/*
    121044017HW06P01.h
    Created by Okan Akdogan
    121044017

    AppSoftware Class Header File
*/

#ifndef APPSOFTWARE_H
#define APPSOFTWARE_H
#include <iostream>
using namespace std;

namespace ns_AppSoftware{

    class AppSoftware{
    public:
        AppSoftware();
        //increases alive object count
        void setName(string name);
        // sets _name member with parameter "name" if not empty
        string getName() const{return _name;};
        //returns name
        void setSystem(string system);
        // sets _system member with parameter "system" if not empty
        string getSystem() const{return _system;};
        //returns system
        static unsigned getAppSoftAliveObject(){return _aliveObj;};
        //returns alive object count
        ~AppSoftware();
        //decreases alive object count
    private:
        string _name;
        string _system;
        static unsigned _aliveObj;
    };
}

#endif // APPSOFTWARE_H
