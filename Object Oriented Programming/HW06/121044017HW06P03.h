/*
    121044017HW06P03.h
    Created by Okan Akdogan
    121044017

    AdobePhotoshop Class Header File
*/
#ifndef ADOBE_PHOTOSHOP_H
#define ADOBE_PHOTOSHOP_H

#include "121044017HW06P02.h"

namespace ns_AppSoftware{
    namespace ns_VectorGraphicEditor{
        namespace ns_AdobePhotoshop{

            class AdobePhotoshop:public VectorGraphicEditor{
            public:
                AdobePhotoshop();
                //calls VectorGraphicEditor Constructor
                //increases _APaliveObj
                AdobePhotoshop(unsigned price,unsigned version);
                //increases AdobePhotoshop alive object count

                void setPrice(unsigned price);
                //sets price
                void setVersion(unsigned version);
                //sets version
                unsigned getPrice() const{return _price;};
                //gets price
                unsigned getVersion() const{return _version;};
                //gets version
                unsigned getAdobePSAliveObject(){return _APaliveObj;};
                ~AdobePhotoshop();
                //decreases alive object counts
            private:
                unsigned _price;
                unsigned _version;
                static unsigned _APaliveObj;
            };

        }//ns_AdobePhotoshop
    }//ns_VectorGraphicEditor
}//ns_AppSoftWare

#endif // ADOBEPHOTOSHOP_H
