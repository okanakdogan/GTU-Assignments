
/*
    121044017HW06P06.h
    Created by Okan Akdogan
    121044017

    ComputerMusicSoftware Class Header File
*/

#ifndef COMPUTER_MUSIC_SOFTWARE_H
#define COMPUTER_MUSIC_SOFTWARE_H

#include "121044017HW06P05.h"

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{
        namespace ns_ComputerMS{

            class ComputerMusicSoftware:public MusicSoftware{
            public:
                ComputerMusicSoftware();
                //Calls MusicSoftware constructor
                //sets members to 0 and increases alive object count
                ComputerMusicSoftware(unsigned price,unsigned version);
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
                static unsigned getCompMSAliveObj(){ return _CMSaliveObj;};
                //gets alive ComputerMusicSoftware alive object count
                ~ComputerMusicSoftware();
                //decreases alive object count
            private:
                unsigned _price;
                unsigned _version;
                static unsigned _CMSaliveObj;
            };

        }//ns_ComputerMS
    }//ns_MusicSoftware
}//ns_AppSoftware

#endif // COMPUTER_MUSIC_SOFTWARE_H
