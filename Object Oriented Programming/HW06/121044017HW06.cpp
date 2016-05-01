/*
    121044017HW06.cpp
    Created by Okan Akdogan
    121044017

    Inheritance Classes' Tests

*/
#include <iostream>
#include "121044017HW06P03.h"
#include "121044017HW06P04.h"
#include "121044017HW06P06.h"
#include "121044017HW06P07.h"
#include "121044017HW06P08.h"

using namespace std;
using namespace ns_AppSoftware;
using namespace ns_AppSoftware::ns_VectorGraphicEditor;
using namespace ns_AppSoftware::ns_VectorGraphicEditor::ns_AdobePhotoshop;
using namespace ns_AppSoftware::ns_VectorGraphicEditor::ns_AdobeFlash;
using namespace ns_AppSoftware::ns_MusicSoftware;
using namespace ns_AppSoftware::ns_MusicSoftware::ns_ComputerMS;
using namespace ns_AppSoftware::ns_MusicSoftware::ns_ElectronicMS;
using namespace ns_AppSoftware::ns_MusicSoftware::ns_MediaPlayer;

namespace{
    void appSoftwareTest(AppSoftware & app){

        app.setName("appWindows");
        app.setSystem("Windows");

        cout<<"AppSoftware Class Test"<<endl<<endl;
        cout<<app.getName()<<endl;
        cout<<app.getSystem()<<endl;
        cout<<"alive AppSoftware object: "<<app.getAppSoftAliveObject()<<endl;
        cout<<endl;
    }

    void vectorGraphicEditorTest(VectorGraphicEditor & vecEdi){

        vecEdi.setName("linuxApp");
        vecEdi.setSystem("Linux");
        vecEdi.setCompany("UbuntuApps");
        vecEdi.setYear(2013);

        cout<<"VectorGraphicEditor Class Test"<<endl<<endl;
        cout<<vecEdi.getName()<<endl;
        cout<<vecEdi.getSystem()<<endl;
        cout<<vecEdi.getCompany()<<endl;
        cout<<"Year: "<<vecEdi.getYear()<<endl;
        cout<<"alive AppSoftware object: "<<vecEdi.getAppSoftAliveObject()<<endl;
        cout<<"alive VectorGraphicEditor object: "<<vecEdi.getVGEAliveObject()<<endl;
        cout<<endl;

    }

    void adobePhotoshopTest(AdobePhotoshop & adobe){

        adobe.setName("linuxApp");
        adobe.setSystem("Linux");
        adobe.setCompany("UbuntuApps");
        adobe.setYear(2013);

        cout<<"AdobePhotoshop Class Test"<<endl<<endl;
        cout<<adobe.getName()<<endl;
        cout<<adobe.getSystem()<<endl;
        cout<<adobe.getCompany()<<endl;
        cout<<"Year: "<<adobe.getYear()<<endl;
        cout<<adobe.getPrice()<<endl;
        cout<<adobe.getVersion()<<endl;
        cout<<"alive AppSoftware object: "<<adobe.getAppSoftAliveObject()<<endl;
        cout<<"alive VectorGraphicEditor object: "<<adobe.getVGEAliveObject()<<endl;
        cout<<"alive AdobePhotoshop object: "<<adobe.getAdobePSAliveObject()<<endl;
        cout<<endl;
    }
    void adobeFlashTest(AdobeFlash & adobeF){
         adobeF.setName("WinApp");
        adobeF.setSystem("Windows");
        adobeF.setCompany("WindowsStore");
        adobeF.setYear(2012);

        cout<<"AdobeFlash Class Test"<<endl<<endl;
        cout<<adobeF.getName()<<endl;
        cout<<adobeF.getSystem()<<endl;
        cout<<adobeF.getCompany()<<endl;
        cout<<"Year: "<<adobeF.getYear()<<endl;
        cout<<adobeF.getPrice()<<endl;
        cout<<adobeF.getVersion()<<endl;
        cout<<"alive AppSoftware object: "<<adobeF.getAppSoftAliveObject()<<endl;
        cout<<"alive VectorGraphicEditor object: "<<adobeF.getVGEAliveObject()<<endl;
        cout<<"alive AdobeFlash object: "<<adobeF.getAdobeFlashAliveObj()<<endl;
        cout<<endl;
    }

    void MusicSoftwareTest(MusicSoftware & musicSoft){

        musicSoft.setName("OSXApp");
        musicSoft.setSystem("OSX");
        musicSoft.setCompany("Apple");
        musicSoft.setYear(2013);

        cout<<"MusicSoftware Class Test"<<endl<<endl;
        cout<<musicSoft.getName()<<endl;
        cout<<musicSoft.getSystem()<<endl;
        cout<<musicSoft.getCompany()<<endl;
        cout<<"Year: "<<musicSoft.getYear()<<endl;
        cout<<"alive AppSoftware object: "<<musicSoft.getAppSoftAliveObject()<<endl;
        cout<<"alive MusicSoftware object: "<<musicSoft.getMusicSoftAliveObj()<<endl;
        cout<<endl;

    }
    void computerMusicSoftwareTest(ComputerMusicSoftware & cms){

        cms.setName("XPApp");
        cms.setSystem("Windows");
        cms.setCompany("Microsoft");
        cms.setYear(2012);

        cout<<"ComputerMusicSoftware Class Test"<<endl<<endl;
        cout<<cms.getName()<<endl;
        cout<<cms.getSystem()<<endl;
        cout<<cms.getCompany()<<endl;
        cout<<"Year: "<<cms.getYear()<<endl;
        cout<<"alive AppSoftware object: "<<cms.getAppSoftAliveObject()<<endl;
        cout<<"alive MusicSoftware object: "<<cms.getMusicSoftAliveObj()<<endl;
        cout<<"alive CompterMusicSoftware object: "<<cms.getCompMSAliveObj()<<endl;
        cout<<endl;

    }

    void electronicMusicSoftwareTest(ElectronicMusicSoftware & ems){

        ems.setName("7App");
        ems.setSystem("Windows");
        ems.setCompany("Microsoft");
        ems.setYear(2011);

        cout<<"ElectronicMusicSoftware Class Test"<<endl<<endl;
        cout<<ems.getName()<<endl;
        cout<<ems.getSystem()<<endl;
        cout<<ems.getCompany()<<endl;
        cout<<"Year: "<<ems.getYear()<<endl;
        cout<<"alive AppSoftware object: "<<ems.getAppSoftAliveObject()<<endl;
        cout<<"alive MusicSoftware object: "<<ems.getMusicSoftAliveObj()<<endl;
        cout<<"alive ElectronicMusicSoftware object: "<<ems.getElecMSAliveObj()<<endl;
        cout<<endl;

    }

    void MediaPlayerTest(MediaPlayer & mp){
        mp.setName("UApp");
        mp.setSystem("Linux");
        mp.setCompany("Ubuntu");
        mp.setYear(2012);

        cout<<"MediaPlayer Class Test"<<endl<<endl;
        cout<<mp.getName()<<endl;
        cout<<mp.getSystem()<<endl;
        cout<<mp.getCompany()<<endl;
        cout<<"Year: "<<mp.getYear()<<endl;
        cout<<"alive AppSoftware object: "<<mp.getAppSoftAliveObject()<<endl;
        cout<<"alive MusicSoftware object: "<<mp.getMusicSoftAliveObj()<<endl;
        cout<<"alive MediaPlayer object: "<<mp.getMPAliveObj()<<endl;
        cout<<endl;


    }
}

int main(){

    //AppSoftware Class Tests
    AppSoftware app;
    appSoftwareTest(app);

    //VectorGraphicEditor Class tests
    VectorGraphicEditor vecEdi;
    vectorGraphicEditorTest(vecEdi);


    //AdobePhotoshop Class Tests
    AdobePhotoshop adobe(10,1);
    adobePhotoshopTest(adobe);


    //AdobeFlash Class Tests

    AdobeFlash adobeF(10,1);
    adobeFlashTest(adobeF);

    //MusicSoftware Class Tests
    MusicSoftware musicSoft;
    MusicSoftwareTest(musicSoft);

    //ComputerMusicSoftware Tests
    ComputerMusicSoftware cms(20,2);
    computerMusicSoftwareTest(cms);

    //ElectronicMusicSoftware Tests
    ElectronicMusicSoftware ems(30,3);
    electronicMusicSoftwareTest(ems);

    //MediaPlayer Tests
    MediaPlayer mediaPlayer(10,5);
    MediaPlayerTest(mediaPlayer);

    return 0;
}
