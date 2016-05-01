package hw01_121044017;

import javax.swing.JOptionPane;

/**
 * @author Okan
 * @version 1.0
 * @created 25-�ub-2014 21:30:31
 */
public class GMgui implements GMUserInterface {

	
        PlotFrame frame;
         /**
         * Class constructor
         * 
         */
	public GMgui(){
            
	}

        @Override
	public void finalize() throws Throwable {
            super.finalize();

	}
         /**
         * Clears plane
         */
        @Override
	public void doClearVisualization(){
                frame.canvasUnit.ClearVisualization();
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
		String fileName;
                
                
                
                fileName=JOptionPane.showInputDialog("Enter file path");
                
                if(frame.canvasUnit.ReadFile(fileName)){
                
                    JOptionPane.showMessageDialog(null, "File found");
                    return true;
                }
                else
                    JOptionPane.showMessageDialog(null, "File NOT found");
                
		return false;
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
                choice=JOptionPane.showOptionDialog(
                        null,
                        "Select a Command",
                        "Plot Visualization",
                        JOptionPane.YES_NO_CANCEL_OPTION,
                        JOptionPane.QUESTION_MESSAGE,
                        null,
                        commands,
                        commands[commands.length-1]);
                switch (choice){
                    case 0: doReadFile(); break;
                    case 1: doGraphIt();  break;
                    case 2: doClearVisualization();doGraphIt(); break;
                    default:    //Do nothing
                
                }
                
            }while(choice!=commands.length-1);
	}

}