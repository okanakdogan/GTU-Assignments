/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw01_121044017;

import javax.swing.JFrame;

/**
 *  121044017
 * @author Okan Akdogan
 */
public class HW01_121044017 {

    /**
     * @param args the command line arguments
     */
    
    
    public static void main(String[] args) {
        // TODO code application logic here
        
        GMconsole userInterface=new GMconsole();
        //GMgui userInterface=new GMgui();
        
        PlotFrame frame = new PlotFrame();
        
        userInterface.proccessCommands(frame);
        frame.dispose();
        
                
               
    }
    
}
