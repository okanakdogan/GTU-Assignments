import javax.management.Attribute;
import java.util.ArrayList;

/**
 * Created by Okan on 7.03.2016.
 */
public class MainTest {

    public static void main(String[] args){

        /** -------- TEST 1 ---------
         *  Only String*/

        System.out.println("-----TEST 1 - ONLY STRING ----");

        DataSet data;
        data = DataReader.readData("data.csv",5);

        System.out.println("Read check");

        for(int i=0 ;i< data.getTuples().size();++i){
            System.out.println("i:"+i + " "+ data.getTuples().get(i).toString() );
        }

        ArrayList<Character> attrType = new ArrayList<Character>();

        attrType.add('d');
        attrType.add('d');
        attrType.add('d');
        attrType.add('d');


        NaiveBayes nb = null;
        try {
            nb = new NaiveBayes(data,attrType);
        } catch (Exception e) {
            e.printStackTrace();
        }
        nb.printValues();
        ArrayList<String> attrs =new ArrayList<String>();

        attrs.add("<=30");
        attrs.add("medium");
        attrs.add("yes");
        attrs.add("fair");


        Tuple testTuple =new Tuple();
        testTuple.setAttributes(attrs);


        nb.predict(testTuple);

        System.out.println("TestTuple: "+ testTuple.toString()+ " class: " + testTuple.getTupleClass());


        /** ---------TEST 2 ---------
         * ONLY NUMBERS  */

        System.out.println("\n-----TEST 2 - ONLY Numbers ----\n");

        data = DataReader.readData("data2.csv",1);

        System.out.println("Read check");

        for(int i=0 ;i< data.getTuples().size();++i){
            System.out.println("i:"+i + " "+ data.getTuples().get(i).toString() );
        }

        attrType.clear();
        attrType.add('c');
        attrType.add('c');
        attrType.add('c');

        attrs.clear();
        attrs.add("6.0");
        attrs.add("130.0");
        attrs.add("8.0");

        nb = null;
        try {
            nb = new NaiveBayes(data,attrType);
        } catch (Exception e) {
            e.printStackTrace();
        }
        nb.printValues();

        testTuple.setAttributes(attrs);

        nb.predict(testTuple);
        System.out.println("TestTuple: "+ testTuple.toString()+ " class: " + testTuple.getTupleClass());

        /** ---------TEST 2 ---------
         * MIXED CONT. DISCRETE  */
        System.out.println("\n-----TEST 3 - ONLY Numbers ----\n");


        data = DataReader.readData("data3.csv",1);

        System.out.println("Read check");

        for(int i=0 ;i< data.getTuples().size();++i){
            System.out.println("i:"+i + " "+ data.getTuples().get(i).toString() );
        }

        attrType.clear();
        attrType.add('c');
        attrType.add('c');
        attrType.add('c');
        attrType.add('d');
        attrType.add('d');
        attrType.add('d');
        attrType.add('d');

        attrs.clear();
        attrs.add("6.0");
        attrs.add("130.0");
        attrs.add("8.0");
        attrs.add("<=30");
        attrs.add("medium");
        attrs.add("yes");
        attrs.add("fair");

        nb = null;
        try {
            nb = new NaiveBayes(data,attrType);
        } catch (Exception e) {
            e.printStackTrace();
        }
        nb.printValues();

        testTuple.setAttributes(attrs);

        nb.predict(testTuple);
        System.out.println("TestTuple: "+ testTuple.toString()+ " class: " + testTuple.getTupleClass());


    }
}
