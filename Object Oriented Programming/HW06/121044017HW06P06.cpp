/*
    121044017HW06P06.cpp
    Created by Okan Akdogan
    121044017

    ComputerMusicSoftware Class Imp. File
*/

#include "121044017HW06P06.h"

using namespace std;
using namespace ns_AppSoftware::ns_MusicSoftware::ns_ComputerMS;

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{
        namespace ns_ComputerMS{

            unsigned ComputerMusicSoftware::_CMSaliveObj=0;

            ComputerMusicSoftware::ComputerMusicSoftware():MusicSoftware(){
                _price=0;
                _version=0;
                ++_CMSaliveObj;
            }

            ComputerMusicSoftware::ComputerMusicSoftware(unsigned price,unsigned version)
            :MusicSoftware(),_price(price),_version(version){
                ++_CMSaliveObj;
            }

            void ComputerMusicSoftware::setPrice(unsigned price){
                _price=price;
            }
            void ComputerMusicSoftware::setVersion(unsigned version){
                _version=version;
            }

            ComputerMusicSoftware::~ComputerMusicSoftware(){
                --_CMSaliveObj;
            }

        }//ns_ComputerMS
    }//ns_MusicSoftware
}//ns_AppSoftware
