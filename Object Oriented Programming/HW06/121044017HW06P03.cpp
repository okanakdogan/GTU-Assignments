/*
    121044017HW06P03.cpp
    Created by Okan Akdogan
    121044017

    AdobePhotoshop Class Imp. File
*/
#include "121044017HW06P03.h"
#include <iostream>
using namespace std;

namespace ns_AppSoftware{
    namespace ns_VectorGraphicEditor{
        namespace ns_AdobePhotoshop{

            unsigned AdobePhotoshop::_APaliveObj=0;

            AdobePhotoshop::AdobePhotoshop():VectorGraphicEditor(){
                _price=0;
                _version=0;
                ++_APaliveObj;
            }
            AdobePhotoshop::AdobePhotoshop(unsigned price,unsigned version)
            :VectorGraphicEditor(),_price(price),_version(version){
                ++_APaliveObj;
            }
            void AdobePhotoshop::setPrice(unsigned price){
                _price=price;
            }
            void AdobePhotoshop::setVersion(unsigned version){
                _version=version;
            }
            AdobePhotoshop::~AdobePhotoshop(){
                --_APaliveObj;
            }

        }//ns_AdobePhotoshop
    }//ns_VectorGraphicEditor
}//ns_AppSoftware
