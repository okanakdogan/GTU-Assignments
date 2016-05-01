/*
    121044017HW06P05.h
    Created by Okan Akdogan
    121044017

    MusicSoftware Class Header File
*/

#ifndef MUSIC_SOFTWARE_H
#define MUSIC_SOFTWARE_H

#include "121044017HW06P01.h"

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{

        class MusicSoftware:public AppSoftware{
        public:
            MusicSoftware();
            //Calls AppSoftware constructor
            //increases alive object count
            MusicSoftware(unsigned year,string company);
            //Calls AppSoftware constructor
            //increases alive object count and sets member variable with parameters

            void setCompany(string company);
            //sets company name
            void setYear(unsigned year);
            //sets year
            string getCompany() const{ return _company;};
            //gets company name
            unsigned getYear() const{ return _year;};
            //gets year
            static unsigned getMusicSoftAliveObj(){return _MSaliveObj;};
            //gets alive MusicSoftware alive object count
            ~MusicSoftware();
            //decreases alive object count
        private:
            unsigned _year;
            string _company;
            static unsigned _MSaliveObj;
        };


    }//ns_MusicSoftware
}//ns_AppSoftware

#endif // MUSIC_SOFTWARE_H
