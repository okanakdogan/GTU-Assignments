package hw01_121044017;

import javax.swing.JFrame;

/**
 * @author Okan
 * @version 1.0
 * @created 25-�ub-2014 21:30:31
 */
public interface GMUserInterface {
        
        /**
         * Calls clear method in Canvas class
         */
	public void doClearVisualization();
         /**
         * Calls repaint method in JFrame class
         */
	public void doGraphIt();
        
         /**
         * Calls readFile method in Canvas class
         */
	public boolean doReadFile();

	/**
	 * starts program menu
	 * @param funcGroup includes function array
	 */
	public void proccessCommands(PlotFrame frame);

}