import java.util.ArrayList;
import java.util.HashSet;

/**
 * Created by Okan on 9.03.2016.
 */
public class EntropyInfoGain {

    public static double calculateEntropy(ArrayList<Tuple> data,HashSet<String> classes) {
        double entropy = 0;

        if(data.size() == 0) {
            // nothing to do
            return 0;
        }


        for(String cls: classes) {
            int count = 0;
            for(int j = 0; j < data.size(); j++) {
                Tuple tuple = data.get(j);

                if(tuple.getTupleClass().equals( cls)) {
                    count++;
                }
            }

            double probability = count / (double)data.size();
            if(count > 0) {
                entropy += -probability * (Math.log(probability) / Math.log(2));
            }
        }

        return entropy;
    }


    public static double calculateGain(double rootEntropy, ArrayList<Double> subEntropies, ArrayList<Integer> setSizes, int data) {
        double gain = rootEntropy;

        for(int i = 0; i < subEntropies.size(); i++) {
            gain += -((setSizes.get(i) / (double)data) * subEntropies.get(i));
        }

        return gain;
    }
}
