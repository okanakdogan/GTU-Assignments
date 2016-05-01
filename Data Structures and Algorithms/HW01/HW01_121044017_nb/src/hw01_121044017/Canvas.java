package hw01_121044017;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Polygon;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JPanel;



/**
 * @author Okan Akdogan
 * @version 1.0
 * @created 22-�ub-2014 19:04:30
 */
public class Canvas extends JPanel implements GraphicMakerIntFace {

	private FunctionGroup FuncGroup;
	



	public void finalize() throws Throwable {
            super.finalize();

	}
        /**
         * Class constructor
         */
	public Canvas(){
            super();
            setLayout(null);
            FuncGroup=new FunctionGroup();
                    
	}
        /**
         * Recreates FunctionGruop object and clears panel 
         * 
         */
        @Override
	public void ClearVisualization(){
             FuncGroup=new FunctionGroup();
             removeAll();
	}
        /**
         *  gets color object of given color name
         * 
         * @param colorName for search color object
         * @return color if found else color black
         */
        private Color getColor(String colorName){
        try {
                 try {
                     return (Color)Color.class.getField(colorName.trim()).get(null);
                 } catch (    IllegalArgumentException | IllegalAccessException ex) {
                     Logger.getLogger(Canvas.class.getName()).log(Level.SEVERE, null, ex);
                     return Color.black;
                 }
            } catch (    NoSuchFieldException | SecurityException ex) {
                Logger.getLogger(Canvas.class.getName()).log(Level.SEVERE, null, ex);
                return Color.black;
            }
           
        }
        

	/**
	 * Draws cosinus function plot
	 * @param func for information color and range
	 */
	private void DrawCos(Function func,Graphics g){
           Polygon p = new Polygon();
       

             for (double x = (func.getRange()[0]*100); x <= (func.getRange()[1]*100); x++) {
                 p.addPoint((int)x+ 320 , 240- (int) (50 * Math.cos((x / 100.0) * 2
                    * Math.PI)));
             
             }
            g.setColor(getColor(func.getColor()));
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
	}

	/**
	 * Draws logarithm function plot
	 * @param func for information color and range
	 */
	private void DrawLog(Function func,Graphics g){
            Polygon p = new Polygon();
            double x;
            
            if(func.getRange()[0]<=0)
                x=1;
            else
                x=func.getRange()[0];

             for (; x <= (func.getRange()[1]*100); x++) {
                 p.addPoint((int)x+ 320 , 240- (int) ( Math.log(x / 100.0)*100));
             
             }
             
            g.setColor(getColor(func.getColor()));
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
         
	}

	/**
	 * Draws sinus function plot
	 * @param func for information color and range
	 */
	private void DrawSin(Function func,Graphics g) {
             Polygon p = new Polygon();
       

             for (double x = (func.getRange()[0]*100); x <= (func.getRange()[1]*100); x++) {
                 p.addPoint((int)x+ 320 , 240- (int) (50 * Math.sin((x / 100.0) * 2
                    * Math.PI)));
             
             }
            g.setColor(getColor(func.getColor()));
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);

	}

	/**
	 * Draws x function plot
	 * @param func for information color and range
	 */
	private void DrawX(Function func,Graphics g){
            Polygon p = new Polygon();
       

             for (double x = (func.getRange()[0]*100); x <= (func.getRange()[1]*100); x++) {
                 p.addPoint((int)x+ 320 , 240- (int)x);
             
             }
            g.setColor(getColor(func.getColor()));
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
	}
        /**
	 * Draws x^2 function plot
	 * @param func for information color and range
	 */
	private void DrawX2(Function func,Graphics g){
            Polygon p = new Polygon();
       

             for (double x = (func.getRange()[0]*100); x <= (func.getRange()[1]*100); x++) {
                 p.addPoint((int)x+ 320 , 240- (int)(x*x)/100);
             
             }
            g.setColor(getColor(func.getColor()));
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
	}
        
        /**
	 * Draws tangent function plot
	 * @param func for information color and range
	 */
	private void DrawTan(Function func,Graphics g){
            Polygon p = new Polygon();
       

             for (double x = (func.getRange()[0]*100); x <= (func.getRange()[1]*100); x++) {
                 p.addPoint((int)x+ 320 , 240- (int) (50 * Math.tan((x / 100.0) * 2
                    * Math.PI)));
             
             }
            g.setColor(getColor(func.getColor()));
            g.drawPolyline(p.xpoints, p.ypoints, p.npoints);
	}



	/**
	 *  paints to panel
	 * @param g graphic object
	 */
        
        @Override
	public void paintComponent(Graphics g){
            super.paintComponent(g);
            
            //Create Graphics object
            Graphics2D g2d = (Graphics2D) g;
            int i;
            g2d.setColor(Color.black);
            
            //draw x-y axis
            
            g2d.drawLine(0, 240, 640, 240);
            g2d.drawLine(320, 0, 320, 480); 
            
            //write label on axis
            for(i=0;i<640;i+=80){
              g2d.drawString(String.valueOf(i-320), i, 255);
            }
      
            for(i=0;i<480;i+=80){
              g2d.drawString(String.valueOf(240-i), 325, i);
            }
            
            
            if(FuncGroup.at(0)!=null){
              for(i=0;i<FuncGroup.arraySize();++i){
                 switch (FuncGroup.at(i).getName()){
                     case "sin(x)": DrawSin(FuncGroup.at(i),g); break;
                     case "x":DrawX(FuncGroup.at(i),g); break;
                     case "cos(x)":DrawCos(FuncGroup.at(i),g); break;
                     case "log(x)":DrawLog(FuncGroup.at(i),g); break;
                     case "x^2":DrawX2(FuncGroup.at(i),g); break;
                     case "tan(x)":DrawTan(FuncGroup.at(i), g);break;
                 }
                 
                 
                 
              }
            } 
            
            
	}

	/**
	 * Reads file given path
	 * @param fileName
         * @return if file found true else false
	 */
	public boolean ReadFile(String fileName){
            
            //auto try catch?
            String funcName,color;
            double minRange,maxRange;
            
            try {        
                //open file
                Scanner reader=new Scanner(new FileInputStream(fileName));
                
                reader.useDelimiter(",|\n");
                while(reader.hasNext()){
                    //read a lines
                    funcName=reader.next();
                   // System.out.printf("\nfName: %s\n ",funcName);
                    minRange=Double.valueOf(reader.next());
                   // System.out.printf("\n%f\n ",minRange);
                    maxRange=Double.valueOf(reader.next());
                    //System.out.printf("\n%f\n ",maxRange);
                    
                    color=reader.next();
                    //System.out.printf("\n%s\n ",color);
                    //add func to array
                    FuncGroup.addFunc(new Function(funcName,minRange,maxRange,color));                    
                }
                reader.close();
                
                return true;
            } catch (FileNotFoundException ex) {
                //Logger.getLogger(Canvas.class.getName()).log(Level.SEVERE, null, ex);
                return false;
            }
            catch(NumberFormatException ex){
                return false;
            }
            
		
	}
        /**
         * FunctionGroup getter
         * @return FunctionGruop objects that includes functions
         */
        public FunctionGroup getFuncs(){
            return FuncGroup;
        }

}