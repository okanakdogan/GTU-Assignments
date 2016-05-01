import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Created by Okan on 7.03.2016.
 */
public class DataReader {

    public static DataSet readData( String filePath, int classIndex){
        --classIndex;
        BufferedReader reader = null;
        DataInputStream dis = null;
        ArrayList<Tuple> tuples = new ArrayList<Tuple>();
        try {
            File f = new File(filePath);
            FileInputStream fis =  new FileInputStream(f);
            reader = new BufferedReader(new InputStreamReader(fis));

            String line;
            Tuple t = null;
            ArrayList<String> attr ;

            while ((line=reader.readLine())!=null){
                String[] cols = line.split(",");
                attr = new ArrayList<String>();

                for (int i=0; i<cols.length; i++){
                    if(i!=classIndex)
                        attr.add(cols[i].toString());
                }
                t=new Tuple();
                t.setAttributes(attr);
                t.setTupleClass(cols[classIndex].toString());
                tuples.add(t);
            }

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            System.out.println("Got an IOException error: " + e.getMessage());
        }

        DataSet dataset = new DataSet(tuples);
        return dataset;
    }
}
