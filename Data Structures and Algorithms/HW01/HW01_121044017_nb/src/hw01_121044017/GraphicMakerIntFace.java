package hw01_121044017;



/**
 * @author Okan
 * @version 1.0
 * @created 22-�ub-2014 18:57:20
 */
public interface GraphicMakerIntFace {

	public void ClearVisualization();


	/**
	 * 
	 * @param fileName path for read file
        * @return true if file found else false
	 */
	public boolean ReadFile(String fileName);

}