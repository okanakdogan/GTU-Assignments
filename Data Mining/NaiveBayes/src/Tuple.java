import java.util.ArrayList;

/**
 * Created by Okan on 7.03.2016.
 */
public class Tuple {

    private ArrayList<String> attributes;

    public ArrayList<String> getAttributes() {
        return attributes;
    }

    public void setAttributes(ArrayList<String> attributes) {
        this.attributes = attributes;
    }



    public String getTupleClass() {
        return tupleClass;
    }

    public void setTupleClass(String tupleClass) {
        this.tupleClass = tupleClass;
    }

    private String tupleClass;

    public String toString(){

        String tuple="";
        for(int i=0; i< attributes.size();++i){

            tuple= tuple + attributes.get(i);
            if(i!=attributes.size()-1){
                tuple+=",";
            }
        }
        return tuple;
    }



}
