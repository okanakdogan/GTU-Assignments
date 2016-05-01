package hw01_121044017;



/**
 * @author Okan
 * @version 1.0
 * @created 22-�ub-2014 18:57:21
 */
public class Function {

	private String color;
	private String name;
	private double[] range;
        
        /**
        * Class constructor 
        *
        */
        
	public Function(){
                this.range= new double[2];
	}

	public void finalize() throws Throwable {

	}

	/**
	 * Class constructor with function informations.
	 * @param name function name
	 * @param min  minimum range 
	 * @param max  maximum range
	 * @param color for plot draw
	 */
	public Function(String name, double min, double max, String color){
            
                this.range= new double[2];
            
                this.name=name;
                this.color=color;
                this.range[0]=min;
                this.range[1]=max;
                
	}
        /**
        * Color getter
        * @return the color for plot draw
        */
	public String getColor(){
		return this.color;
	}
        
        /**
        * name getter
        * @return the name of function
        */
	public String getName(){
		return this.name;
	}
        /**
        * Range getter
        * @return double array of range
        */
	public double[] getRange(){
		return this.range;
	}
        /**
        * Color setter
        * @param color for the plot draw
        */
	public void setColor(String color){
            this.color=color;
	}
         /**
        * name setter
        * @param name name of the function
        */
	public void setName(String name){
            this.name=name;
	}

}