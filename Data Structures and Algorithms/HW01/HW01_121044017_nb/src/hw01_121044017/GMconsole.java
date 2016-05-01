package hw01_121044017;

import java.util.Scanner;

/**
 * @author Okan
 * @version 1.0
 * @created 25-�ub-2014 21:30:31
 */
public class GMconsole implements GMUserInterface{

	
        Scanner scLine;
        PlotFrame frame;
        
        /**
         * Class constructor
         * 
         */
	public GMconsole(){
            scLine=new Scanner(System.in);
	}

	public void finalize() throws Throwable {

	}

	/**
	 * Starts Program menu
	 * @param frame for draw plane
	 */
        @Override
	public void proccessCommands(PlotFrame frame){
            
            
            this.frame=frame;
            String[] commands={"Read File","Graph Functions","Clear Visualization","Exit"};
            int i,choice;
            do{
            for(i=0;i<commands.length;++i)
                System.out.printf("%d - %s \n",i,commands[i]);
            System.out.println("Enter a choice:");
            
            choice=scLine.nextInt();
            switch (choice){
                case 0: doReadFile(); break;
                case 1: doGraphIt(); break;
                case 2: doClearVisualization(); break;
        
                default: //empty3
                    
            }
            
            }while(choice!=commands.length-1);     
            
	}

        
        /**
         * Clears plane
         */
        @Override
	public void doClearVisualization(){
                frame.canvasUnit.ClearVisualization();
                System.out.println("Cleared \n");
	}
         /**
         * Draws functions' plots to plane
         */
        @Override
	public void doGraphIt(){
                frame.setVisible(true);
                frame.repaint();
	}
         /**
         * Reads functions from file that given path
         * @return true if found else false
         */
        @Override
	public boolean doReadFile(){
                System.out.print("Enter a file path: \n");
                String fileName;
                fileName=scLine.next();
                
                if(frame.canvasUnit.ReadFile(fileName)){
                
                    System.out.println("File Readed \n");
                    return true;
                }
                else
                    System.out.println("File Read error \n");
                
		return false;
	}


}