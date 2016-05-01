/*
    121044017HW06P02.h
    Created by Okan Akdogan
    121044017

    VectorGraphicEditor Class Header File
*/

#ifndef VECTOR_GRAPHIC_EDITOR_H
#define VECTOR_GRAPHIC_EDITOR_H

#include "121044017HW06P01.h"

namespace ns_AppSoftware{
    namespace ns_VectorGraphicEditor{

        class VectorGraphicEditor:public AppSoftware{
        public:
            VectorGraphicEditor():AppSoftware(){++_VGEaliveObj;};
            //increases alive object count
            void setYear(unsigned year);
            //sets year
            unsigned getYear() const{return _year;};
            void setCompany(string company);
            string getCompany() const {return _company;};
            static unsigned getVGEAliveObject(){return _VGEaliveObj;};
            ~VectorGraphicEditor();
            //decreases alive object count
        private:
            unsigned _year;
            string _company;
            static unsigned _VGEaliveObj;
        };


    }//ns_VectorGraphicSoftware

}//ns_AppSoftware


#endif // VECTOR_GRAPHIC_SOFTWARE_H



