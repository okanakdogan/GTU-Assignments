
/*
    121044017HW06P07.h
    Created by Okan Akdogan
    121044017

    ElectronicMusicSoftware Class Header File
*/

#ifndef ELECTRONIC_MUSIC_SOFTWARE_H
#define ELECTRONIC_MUSIC_SOFTWARE_H

#include "121044017HW06P05.h"

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{
        namespace ns_ElectronicMS{

            class ElectronicMusicSoftware:public MusicSoftware{
            public:
                ElectronicMusicSoftware();
                //Calls MusicSoftware constructor
                //sets members to 0 and increases alive object count
                ElectronicMusicSoftware(unsigned price,unsigned version);
                //Calls MusicSoftware constructor
                //increases alive object count
                void setPrice(unsigned price);
                //sets price
                void setVersion(unsigned version);
                //sets version
                unsigned getPrice() const{ return _price;};
                //gets price
                unsigned getVersion()const{ return _version;};
                //gets version
                static unsigned getElecMSAliveObj(){ return _EMSaliveObj;};
                //gets alive ElectronicMusicSoftware alive object count
                ~ElectronicMusicSoftware();
                //decreases alive object count
            private:
                unsigned _price;
                unsigned _version;
                static unsigned _EMSaliveObj;
            };

        }//ns_ElectronicMS
    }//ns_MusicSoftware
}//ns_AppSoftware

#endif // ELECTRONIC_MUSIC_SOFTWARE_H

