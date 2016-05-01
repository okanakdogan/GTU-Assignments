import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by Okan on 7.03.2016.
 */
public class DataSet {

    private ArrayList<Tuple> tuples;
    private double entropy;
    private int positiveNum;
    private int negativeNum;
    private boolean[] attrUsed;
    private HashSet<String> classes;

    public boolean[] getAttrUsed() {
        return attrUsed;
    }



    public DataSet(){
        positiveNum=-1;
        negativeNum=-1;
        tuples=null;
        attrUsed =null;

    }
    public DataSet(ArrayList<Tuple> t){
        positiveNum=-1;
        negativeNum=-1;
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


    public int getPositiveNum() {
        return positiveNum;
    }


    public int getNegativeNum() {
        return negativeNum;
    }

    public double getEntropy() {
        return entropy;
    }

    public void setEntropy(double entropy) {
        this.entropy = entropy;
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
