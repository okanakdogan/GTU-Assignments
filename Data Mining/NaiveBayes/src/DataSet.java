import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by Okan on 7.03.2016.
 */
public class DataSet {

    private ArrayList<Tuple> tuples;
    private boolean[] attrUsed;
    private HashSet<String> classes;

    public boolean[] getAttrUsed() {
        return attrUsed;
    }


    public DataSet(){

        tuples=null;
        attrUsed =null;

    }
    public DataSet(ArrayList<Tuple> t){

        tuples=t;
        attrUsed =new boolean[t.size()];
        classes=new HashSet<String>();
        findClasses();

    }

    public ArrayList<Tuple> getTuples() {
        return tuples;
    }

    public void setTuples(ArrayList<Tuple> tuples) {
        this.tuples = tuples;
    }


    public HashSet<String> getClasses() {
        return classes;
    }

    private void findClasses(){

        for(Tuple t: tuples){
            classes.add(t.getTupleClass());
        }

    }
}
