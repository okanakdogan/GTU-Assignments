/*
    121044017HW06P08.cpp
    Created by Okan Akdogan
    121044017

    MediaPlayer Class Imp. File
*/

#include "121044017HW06P08.h"

using namespace std;
using namespace ns_AppSoftware::ns_MusicSoftware::ns_MediaPlayer;

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{
        namespace ns_MediaPlayer{

            unsigned MediaPlayer::_MPaliveObj=0;

            MediaPlayer::MediaPlayer():MusicSoftware(){
                _price=0;
                _version=0;
                ++_MPaliveObj;
            }

            MediaPlayer::MediaPlayer(unsigned price,unsigned version)
            :MusicSoftware(),_price(price),_version(version){
                ++_MPaliveObj;
            }

            void MediaPlayer::setPrice(unsigned price){
                _price=price;
            }
            void MediaPlayer::setVersion(unsigned version){
                _version=version;
            }

           MediaPlayer::~MediaPlayer(){
                --_MPaliveObj;
            }

        }//ns_MediaPlayer
    }//ns_MusicSoftware
}//ns_AppSoftware


