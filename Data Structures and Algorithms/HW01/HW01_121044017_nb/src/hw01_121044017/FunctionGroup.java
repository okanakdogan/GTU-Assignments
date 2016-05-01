package hw01_121044017;



/**
 * @author Okan
 * @version 1.0
 * @created 22-�ub-2014 18:57:21
 */
public class FunctionGroup {

	private Function[] functions;
	private int size;



	public void finalize() throws Throwable {

	}
        /**
         * Class Constructor sets function array and size=0
         */
	public FunctionGroup(){
            this.functions=new Function[1];
            size=0;
	}

	/**
	 * Function add to Function array
	 * @param func Function object
	 */
	public void addFunc(Function func){
            if(size==0){
                functions[0]=func;
                ++size;
            }
            else{
                Function[] tmp=new Function[size+1];
                int i;
                for(i=0;i<size;++i)
                    tmp[i]=functions[i];
                
                tmp[size]=func;
                ++size;
                functions=tmp;
            }
	}

	/**
	 * gives function given index
	 * @param index of function
         * @return Function given index
	 */
	public Function at(int index){
		return functions[index];
	}
        /**
	 * 
	 *         
         * @return  size of function array in class
	 */
        public int arraySize(){
            return size;    
        }
        

	/**
	 * 
	 * Deletes function that given name
         * @param name of function that will be delete.
         * @return  
	 */
	public boolean deleteFunc(String name){
                int i;
                for(i=0;i<size;++i)
                    if(functions[i].getName().equals(name)){
                        functions[i]=functions[size-1];
                        functions[size-1]=null;
                        --size;
                        return true;
                    }
                
		return false;
	}

}