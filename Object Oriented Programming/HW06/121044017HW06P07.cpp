/*
    121044017HW06P07.cpp
    Created by Okan Akdogan
    121044017

    ElectronicMusicSoftware Class Imp. File
*/

#include "121044017HW06P07.h"

using namespace std;
using namespace ns_AppSoftware::ns_MusicSoftware::ns_ElectronicMS;

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{
        namespace ns_ElectronicMS{

            unsigned ElectronicMusicSoftware::_EMSaliveObj=0;

            ElectronicMusicSoftware::ElectronicMusicSoftware():MusicSoftware(){
                _price=0;
                _version=0;
                ++_EMSaliveObj;
            }

            ElectronicMusicSoftware::ElectronicMusicSoftware(unsigned price,unsigned version)
            :MusicSoftware(),_price(price),_version(version){
                ++_EMSaliveObj;
            }

            void ElectronicMusicSoftware::setPrice(unsigned price){
                _price=price;
            }
            void ElectronicMusicSoftware::setVersion(unsigned version){
                _version=version;
            }

           ElectronicMusicSoftware::~ElectronicMusicSoftware(){
                --_EMSaliveObj;
            }

        }//ns_ElectronicMS
    }//ns_MusicSoftware
}//ns_AppSoftware

