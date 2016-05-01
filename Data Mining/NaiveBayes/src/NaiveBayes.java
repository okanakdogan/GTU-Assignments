import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

/**
 * Created by Okan on 21.03.2016.
 */
public class NaiveBayes {

    private HashSet<String> classes;
    private ArrayList<AttrSummarize> attrSummarizes;
    private HashMap<String,Double> probOfClasses;
    ArrayList<Character> attrType;
    int numOfAttr;

    public NaiveBayes(DataSet data,ArrayList<Character> attrType) throws Exception {

        classes=data.getClasses();
        attrSummarizes= new ArrayList<AttrSummarize>();

        numOfAttr=0;

        if(data.getTuples()!=null){
            numOfAttr=data.getTuples().get(0).getAttributes().size();
        }

        this.attrType= attrType;

        if(numOfAttr != attrType.size()){
            throw new Exception("atrribute type size not equal to column size");
        }

        // count each class occurence
        HashMap<String,Integer> occurClasses = new HashMap<String,Integer>();

        //add maps
        for(String cls: classes){
            occurClasses.put(cls,0);
        }

        //update occurs.
        for(Tuple t: data.getTuples()){
            occurClasses.put(t.getTupleClass(),occurClasses.get(t.getTupleClass())+1);
        }

        //save probabilites of classes occur/tuppleNum
        probOfClasses = new HashMap<String,Double>();
        for(String cls: classes){

            // DEBUG info about p(class)

            System.out.println("p(class) - Class prob: "+ cls +" - "+ occurClasses.get(cls)/(double)data.getTuples().size());
            probOfClasses.put(cls, occurClasses.get(cls)/(double)data.getTuples().size());
        }

        for(int i=0; i< numOfAttr; ++i){

            if(attrType.get(i).equals('d')) {
                //if discrete
                //find value set
                HashSet<String> valueSet = new HashSet<String>();

                for (Tuple t : data.getTuples()) {
                    String val = t.getAttributes().get(i);
                    valueSet.add(val);
                }
                AttrSummarize attrSemm = new AttrSummarize(valueSet, classes);

                //count for all values

                for (String val : valueSet) {
                    int numOfThisValue = 0;
                    for (String clas : classes) {

                        int numForThisClass = 0;
                        for (Tuple t : data.getTuples()) {
                            if (t.getTupleClass().equalsIgnoreCase(clas)
                                    && t.getAttributes().get(i).equalsIgnoreCase(val)) {
                                numForThisClass++;
                                numOfThisValue++;
                            }
                        }
                        //System.out.println("value: "+ val + " class: "+ clas +" numForThisClass: "+numForThisClass );
                        attrSemm.getProbs().get(val).put(clas, numForThisClass / (double) occurClasses.get(clas));
                    }
                }
                attrSummarizes.add(attrSemm);
            }
            else if(attrType.get(i).equals('c')){

                AttrSummarize attrSemm = new AttrSummarize(classes);

                for ( String inner_cls:classes){


                    double sum=0.0;
                    ArrayList<Double> values = new ArrayList<Double>();

                    for (Tuple t : data.getTuples()) {
                        if (t.getTupleClass().equalsIgnoreCase(inner_cls)) {
                            double val = Double.parseDouble(t.getAttributes().get(i));
                            sum += val;
                            values.add(val);
                        }
                    }
                    //find mean

                    double mean = sum/(double)values.size();
                    double std = stdev(values,mean);
                    attrSemm.getClassGaussInfos().put(inner_cls,new GaussInfo(mean,std));

                }
                attrSummarizes.add(attrSemm);

            }
        }
    }

    public boolean predict( Tuple t){
        if(t.getAttributes().size()!=numOfAttr){
            System.err.println("tuple attribute size not equal classifier model");
            return false;
        }

        // hold prob results for classes
        HashMap<String,Double> probClasses = new HashMap<String,Double>();

        //add classes to map
        for(String cls: classes){
            probClasses.put(cls,probOfClasses.get(cls));
        }

        for(int i=0; i< numOfAttr;++i){

            if(attrType.get(i).equals('d')) {
                HashMap<String, Double> probsOfAttr;
                probsOfAttr = attrSummarizes.get(i).getProbs().get(t.getAttributes().get(i));

                for (String cls : classes) {
                    probClasses.put(cls, probClasses.get(cls) * probsOfAttr.get(cls));
                }
            }else if(attrType.get(i).equals('c')){
                HashMap<String,GaussInfo> classGaussInfos= attrSummarizes.get(i).getClassGaussInfos();

                for (String cls : classes) {
                    GaussInfo infos =classGaussInfos.get(cls);
                    double prob = probDist(Double.parseDouble(t.getAttributes().get(i)),infos.getMean(),infos.getStd());
                    probClasses.put(cls,(probClasses.get(cls)*prob));
                }

            }
        }

        String resultClass=findBestFitClass(probClasses);
        t.setTupleClass(resultClass);

        return true;
    }

    private String findBestFitClass(HashMap<String,Double> probs){
        HashMap.Entry<String,Double> maxEntry=null;


        for (HashMap.Entry<String, Double> entry : probs.entrySet())
        {
            if (maxEntry == null || entry.getValue().compareTo(maxEntry.getValue()) > 0)
            {
                maxEntry = entry;
            }
        }

        return maxEntry.getKey();
    }

    public void printValues(){
        //print all probabilities

        for (int i=0;i< attrSummarizes.size();++i){

            if( attrType.get(i).equals('d')) {
                HashMap<String, HashMap<String, Double>> attrProbs = attrSummarizes.get(i).getProbs();

                for (String val : attrProbs.keySet()) {
                    HashMap<String, Double> pvals = attrProbs.get(val);
                    for (String cls : pvals.keySet()) {
                        System.out.println(val + ": " + cls + " - " + pvals.get(cls));
                    }
                }
            }else if(attrType.get(i).equals('c')){

                HashMap<String,GaussInfo> gi = attrSummarizes.get(i).getClassGaussInfos();

                for(String cls: gi.keySet()){

                    GaussInfo g= gi.get(cls);

                    System.out.println("i:"+i + cls +": mean: "+ g.getMean()+" variance: "+Math.pow(g.getStd(), 2));
                }

            }
        }

    }

    private double stdev(ArrayList<Double> values, double mean){

        double sqrSum=0.0;
        for (int i=0; i<values.size(); ++i){

            sqrSum+= Math.pow((values.get(i)-mean),2);
        }
        double std = Math.sqrt(sqrSum / ((double) values.size() - 1));
        return std;
    }

    private double probDist(double val,double mean, double variance){

        return Math.exp( - Math.pow((val - mean),2)/(2*Math.pow(variance,2)))/ Math.sqrt(2*Math.PI*Math.pow(variance,2));
    }

}
