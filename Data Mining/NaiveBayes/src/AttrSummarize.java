import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;


/**
 * Created by Okan on 21.03.2016.
 */
public class AttrSummarize {
    private boolean isDiscrete;
    //discrete values
    private HashSet<String> values;
    private HashSet<String> classes;
    private HashMap<String,HashMap<String,Double>> probs;


    //cont. values
    //hashset class,values
    HashMap<String,GaussInfo> classGaussInfos;

    public AttrSummarize(HashSet<String> classes){
        this.classes=classes;
        this.isDiscrete=false;
        classGaussInfos= new HashMap<String,GaussInfo>();

    }


    public AttrSummarize(HashSet<String> values,HashSet<String> classes ){
        this.values=values;
        this.classes=classes;
        probs = new HashMap<String,HashMap<String,Double>>();

        for(String val:values){
            probs.put(val,new HashMap<String,Double>());
        }
        this.isDiscrete=true;
    }


    public HashSet<String> getValues() {
        return values;
    }

    public HashSet<String> getClasses() {
        return classes;
    }

    public HashMap<String, HashMap<String, Double>> getProbs() {
        return probs;
    }

    public HashMap<String, GaussInfo> getClassGaussInfos() {
        return classGaussInfos;
    }
}
