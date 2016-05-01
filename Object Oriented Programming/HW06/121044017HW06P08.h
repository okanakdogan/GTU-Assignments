/*
    121044017HW06P08.h
    Created by Okan Akdogan
    121044017

    MediaPlayer Class Header File
*/

#ifndef MEDIA_PLAYER_H
#define MEDIA_PLAYER_H

#include "121044017HW06P05.h"

namespace ns_AppSoftware{
    namespace ns_MusicSoftware{
        namespace ns_MediaPlayer{

            class MediaPlayer:public MusicSoftware{
            public:
                MediaPlayer();
                //Calls MusicSoftware constructor
                //sets members to 0 and increases alive object count
                MediaPlayer(unsigned price,unsigned version);
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
                static unsigned getMPAliveObj(){ return _MPaliveObj;};
                //gets alive MediaPlayer alive object count
                ~MediaPlayer();
                //decreases alive object count
            private:
                unsigned _price;
                unsigned _version;
                static unsigned _MPaliveObj;
            };

        }//ns_MediaPlayer
    }//ns_MusicSoftware
}//ns_AppSoftware

#endif // ELECTRONIC_MUSIC_SOFTWARE_H
