/**
 * Created by Okan on 7.03.2016.
 */
public class MainTest {

    public static void main(String[] args){

        DataSet data;
        data = DataReader.readData("data.csv",5);

        System.out.println("Read check");
        for(int i=0 ;i< data.getTuples().size();++i){

            System.out.println("i:"+i + " "+ data.getTuples().get(i).getTupleClass() );
        }


        System.out.println("Tree Build");
        DTree d =new DTree();
        Node root=new Node();
        d.buildTree(data,root);


    }
}
