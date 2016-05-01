/*
    121044017HW06P05.cpp
    Created by Okan Akdogan
    121044017

    MusicSoftware Class Imp. File
*/

#include "121044017HW06P05.h"
using namespace std;
using namespace ns_AppSoftware::ns_MusicSoftware;
namespace ns_AppSoftware{
    namespace ns_MusicSoftware{

        unsigned MusicSoftware::_MSaliveObj=0;

        MusicSoftware::MusicSoftware():AppSoftware(){
            _year=1900;
            ++_MSaliveObj;
        }
        MusicSoftware::MusicSoftware(unsigned year,string company)
        :AppSoftware(){
            setYear(year),
            setCompany(company);
            ++_MSaliveObj;
        }

        void MusicSoftware::setCompany(string company){
            if (!company.empty())
                _company=company;
        }
        void MusicSoftware::setYear(unsigned year){
            if(year>1900)
                _year=year;
        }

        MusicSoftware::~MusicSoftware(){
            --_MSaliveObj;
        }

    }//ns_MusicSoftware
}//ns_AppSoftware
