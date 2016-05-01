
/*
    121044017HW06P02.cpp
    Created by Okan Akdogan
    121044017

    VectorGraphicEditor Class Imp. File
*/

#include "121044017HW06P02.h"
#include <iostream>

using namespace std;

namespace ns_AppSoftware{
    namespace ns_VectorGraphicEditor{
        unsigned VectorGraphicEditor::_VGEaliveObj=0;

        void VectorGraphicEditor::setYear(unsigned year){
            if(year>1900)
                _year=year;
        }
        void VectorGraphicEditor::setCompany(string company){
            if (!company.empty())
                _company=company;
        }
        VectorGraphicEditor::~VectorGraphicEditor(){
            --_VGEaliveObj;
        }

    }//ns_VectorGraphicSoftware
}//ns_AppSoftware
