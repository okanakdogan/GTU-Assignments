/**
 * Created by Okan on 23.03.2016.
 */
public class GaussInfo {
    public GaussInfo (double mean, double std) {
        this.mean = mean;
        this.std = std;
    }

    private double mean;
    private double std;

    public double getMean() {
        return mean;
    }

    public void setMean(double mean) {
        this.mean = mean;
    }

    public double getStd() {
        return std;
    }

    public void setStd(double std) {
        this.std = std;
    }
}
