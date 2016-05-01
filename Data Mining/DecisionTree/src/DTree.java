import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by Okan on 7.03.2016.
 */
public class DTree {

    public Node buildTree(DataSet data,Node root){

        int bestAttribute = -1;
        double bestGain = 0;

        data.setEntropy(EntropyInfoGain.calculateEntropy(data.getTuples(), data.getClasses()));
        root.setEntropy(data.getEntropy());

        if(root.getEntropy()==0){
            return root;
        }



        int colSize= data.getTuples().get(0).getAttributes().size();
        for(int i = 0; i < colSize; i++) {
            if(!data.getAttrUsed()[i]) {

                HashSet<String> attrVals =new HashSet<>();

                //find set of values for current attr
                for(Tuple t: data.getTuples()){
                    attrVals.add(t.getAttributes().get(i));
                }

                double infoAttr=0;
                for(String attrVal:attrVals){

                    //ATTR OUT
                    //System.out.println("for attr: " + attrVal);

                    int countOcc=0;

                    for (Tuple t: data.getTuples()){
                        if(t.getAttributes().get(i).equals(attrVal)){
                            countOcc++;
                        }
                    }

                    double infoClass=0;
                    for(String cls: data.getClasses()){

                        int clsPosnum=0;
                        for (Tuple t: data.getTuples()){
                            if(t.getAttributes().get(i).equals(attrVal)){
                                if(t.getTupleClass().equals(cls))
                                    clsPosnum++;
                            }
                        }
                        infoClass+=(countOcc/(double)data.getTuples().size())*calcI(clsPosnum,data.getTuples().size());
                        //INFOCLASS OUT
                        //System.out.println( countOcc +"/"+data.getTuples().size()+"*"+calcI(clsPosnum,data.getTuples().size() ));

                    }

                    infoAttr += infoClass;
                    //INFOATTR OUT
                    //System.out.println("current infoAttr "+ infoAttr);
                }

                //GAIN OUT
                System.out.println("gain:" + root.getEntropy() +" - "+ infoAttr);
                double gain = root.getEntropy()-infoAttr;

                if(gain > bestGain) {
                    bestAttribute = i;
                    bestGain = gain;
                }
            }
        }
        if(bestAttribute!=-1){

            HashSet<String> attrVals =new HashSet<>();

            //find set of values for best attr
            for(Tuple t: data.getTuples()){
                attrVals.add(t.getAttributes().get(bestAttribute));
            }

            Node[] children=new Node[attrVals.size()];
            data.getAttrUsed()[bestAttribute]=true;
            root.setNodeGain(bestGain);
            System.out.println(bestGain);
            for( String attr: attrVals){

                buildTree(data,root);
            }
        }else{
            return root;
        }
        return root;
    }

    public static double calcI(int count,int tupleSize){

        //System.out.println("calcI: prob =" + count + "/" + tupleSize);
        double probability = count / (double)tupleSize;
        if(count > 0) {
            return -probability * (Math.log(probability) / Math.log(2));
        }
        return 0;
    }

}
