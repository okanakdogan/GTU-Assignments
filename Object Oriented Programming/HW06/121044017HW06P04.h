/*
    121044017HW06P04.h
    Created by Okan Akdogan
    121044017

    AdobeFlash Class Header File
*/

#ifndef ADOBE_FLASH_H
#define ADOBE_FLASH_H

#include "121044017HW06P02.h"

namespace ns_AppSoftware{
    namespace ns_VectorGraphicEditor{
        namespace ns_AdobeFlash{

            class AdobeFlash:public VectorGraphicEditor{
                public:
                    AdobeFlash();
                    //calls VectorGraphicEditor constructor
                    //sets member variable to 0 and increases alive object count
                    AdobeFlash(unsigned price,unsigned version);
                    //calls VectorGraphicEditor constructor
                    //sets member variable with parameters

                    void setPrice(unsigned price);
                    //sets Price
                    void setVersion(unsigned version);
                    //sets version
                    unsigned getPrice()const{return _price;};
                    //gets price
                    unsigned getVersion()const{return _version;};
                    //gets version
                    static unsigned getAdobeFlashAliveObj(){return _AFaliveObj;};
                    //gets alive Adobe Flash objects
                    ~AdobeFlash();
                    //decreases alive object count
                private:
                    unsigned _price;
                    unsigned _version;
                    static unsigned _AFaliveObj;
            };

        }//ns_AdobeFlash
    }//ns_VectorGraphicEditor
}//ns_AppSoftware
#endif // ADOBE_FLASH_H
