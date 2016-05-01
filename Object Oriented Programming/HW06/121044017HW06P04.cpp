/*
    121044017HW06P04.cpp
    Created by Okan Akdogan
    121044017

    AdobeFlash Class Imp. File
*/
 #include <iostream>
 #include "121044017HW06P04.h"
using namespace std;
using namespace ns_AppSoftware::ns_VectorGraphicEditor;

namespace ns_AppSoftware{
    namespace ns_VectorGraphicEditor{
        namespace ns_AdobeFlash{

            unsigned AdobeFlash::_AFaliveObj=0;

            AdobeFlash::AdobeFlash():VectorGraphicEditor(){
                _price=0;
                _version=0;
                ++_AFaliveObj;
            }
            AdobeFlash::AdobeFlash(unsigned price,unsigned version)
            :VectorGraphicEditor(),_price(price),_version(version){
                ++_AFaliveObj;
            }

            void AdobeFlash::setPrice(unsigned price){
                _price=price;
            }
            void AdobeFlash::setVersion(unsigned version){
                _version=version;
            }

            AdobeFlash::~AdobeFlash(){
                --_AFaliveObj;
            }
        }//ns_AdobeFlash
    }//ns_VectorGraphicEditor
}//ns_AppSoftware

