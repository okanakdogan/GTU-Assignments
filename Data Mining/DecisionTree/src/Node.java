/**
 * Created by Okan on 7.03.2016.
 */
public class Node {
    private Node parent;
    public Node[] children;
    private DataSet data;
    private double entropy;
    private double nodeGain;

    public Node() {
        this.data = new DataSet();
        setEntropy(0.0);
        setParent(null);
        setChildren(null);
    }

    public Node getParent() {
        return parent;
    }

    public void setParent(Node parent) {
        this.parent = parent;
    }

    public DataSet getData() {
        return data;
    }

    public void setData(DataSet data) {
        this.data = data;
    }

    public double getEntropy() {
        return entropy;
    }

    public void setEntropy(double entropy) {
        this.entropy = entropy;
    }

    public Node[] getChildren() {
        return children;
    }

    public void setChildren(Node[] children) {
        this.children = children;
    }

    public double getNodeGain() {
        return nodeGain;
    }

    public void setNodeGain(double nodeGain) {
        this.nodeGain = nodeGain;
    }

}


