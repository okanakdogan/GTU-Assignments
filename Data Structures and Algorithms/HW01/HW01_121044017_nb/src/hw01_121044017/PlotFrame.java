/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw01_121044017;


import javax.swing.JFrame;



/**
 *
 * @author Okan
 */
public class PlotFrame extends JFrame {
    
    public Canvas canvasUnit;
    /**
     * Class Constructor
    */
    public PlotFrame(){
        super("Plot");
        canvasUnit=new Canvas();
        
        setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
        add( canvasUnit );
        setSize(640, 480);
        setResizable(false);
    
    }
    
}
