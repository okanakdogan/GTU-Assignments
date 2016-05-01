/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw8;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Okan
 */
public class Cse222_hw8 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        int startIndex=0,finishIndex=0;
        int[] values={1,2,3,8,0,4,7,6,5};
        int[] valuesSort={0,1,2,3,4,5,6,7,8};
        
        
        //array doldur doldur
    
        ArrayList<ArrayList<Integer>> allLists=new ArrayList<ArrayList<Integer>>();
        //goal 
        ArrayList<Integer> goalPuzzle=new ArrayList<Integer>();
        for(int v:values)
            goalPuzzle.add(v);
        
        Scanner sc=new Scanner(System.in);
        System.out.println("Please enter the initial node in row-wise (use – for space)");
        String initialPuzzle=sc.nextLine();
                
        ArrayList<Integer> puzzle=new ArrayList<Integer>();
        
        String num;
        for(int i=0;i<initialPuzzle.length();++i){
            num=initialPuzzle.substring(i, i+1);
            if(!num.equals("-"))
                puzzle.add(Integer.parseInt(num)); 
            else
                puzzle.add(0);
        }
       
        System.out.println("Please enter the search type (1 for BFS, 2 for DFS)");
        int way=Integer.parseInt(sc.nextLine());
        if(way>2 ||way<1){
            System.out.println(way+" there is no coded way");
            return;
        }
        
/*        puzzle.add(2);
        puzzle.add(8);
        puzzle.add(3);
        puzzle.add(1);
        puzzle.add(6);
        puzzle.add(4);
        puzzle.add(7);
        puzzle.add(0);
        puzzle.add(5);*/
               
        //graphı olustur
        ListGraph myGraph=new ListGraph(factorial(9), true);
        initGraph(myGraph,allLists);
        allLists=permuteUnique(valuesSort);
       //System.out.println("all List size=" + allLists.size());
        
        //arama objesi
       // DepthFirstSearch dfs=new DepthFirstSearch(myGraph);
        
        //baslangıc noktası bul
        startIndex=allLists.indexOf(puzzle);
        finishIndex=allLists.indexOf(goalPuzzle);
        
        
        System.err.println("s:"+startIndex +" f:"+finishIndex);
        if(way==1){
            int [] tmpArr=new int[myGraph.getNumV()];
            LinkedList<Integer> path=new LinkedList<Integer>();
            //ara
            tmpArr = BreadthFirstSearch.breadthFirstSearch(myGraph, startIndex);

            //yolu list'e kaydet
            int val=finishIndex;
            while(val!=startIndex){
               val=tmpArr[val];
               path.addFirst(val);
            }
            //cozumu yaz
            int k;
            System.out.println("Your solution takes "+path.size()+" steps");
            for(int i=0; i<puzzle.size();++i){
                if(puzzle.get(i)!=0)
                    System.out.print(puzzle.get(i));
                else
                    System.out.print(" ");
                if((i+1)%3==0)
                    System.out.print("\n");
            }
            for(k=0; k<path.size();++k){
                System.out.println("step "+(k+1));

                for(int j=0; j<allLists.get(path.get(k)).size();++j){
                    int ind=allLists.get(path.get(k)).get(j);
                    if(ind!=0)    
                        System.out.print(allLists.get(path.get(k)).get(j));
                    else
                        System.out.print(" ");
                    if((j+1)%3==0)
                        System.out.print("\n");
                }   
            }
            System.out.println("Step " +(k+1));
            for(int i=0; i<goalPuzzle.size();++i){
                if(goalPuzzle.get(i)!=0)
                    System.out.print(goalPuzzle.get(i));
                else
                    System.out.print(" ");
                if((i+1)%3==0)
                    System.out.print("\n");
            } 
        }
        else{
            System.out.println("DFS can give stackOverFlowError");
            DepthFirstSearch dfs=new DepthFirstSearch(myGraph);
            dfs.depthFirstSearch(startIndex);
            
            int [] tmpArr=new int[myGraph.getNumV()];
            tmpArr=dfs.getParent();
            
            LinkedList<Integer> path=new LinkedList<Integer>();
            
            //yolu list'e kaydet
            int val=finishIndex;
            while(val!=startIndex){
               val=tmpArr[val];
               path.addFirst(val);
            }
            //cozumu yaz
            int k;
            System.out.println("Your solution takes "+path.size()+" steps");
            for(int i=0; i<puzzle.size();++i){
                if(puzzle.get(i)!=0)
                    System.out.print(puzzle.get(i));
                else
                    System.out.print(" ");
                if((i+1)%3==0)
                    System.out.print("\n");
            }
            for(k=0; k<path.size();++k){
                System.out.println("step "+(k+1));

                for(int j=0; j<allLists.get(path.get(k)).size();++j){
                    int ind=allLists.get(path.get(k)).get(j);
                    if(ind!=0)    
                        System.out.print(allLists.get(path.get(k)).get(j));
                    else
                        System.out.print(" ");
                    if((j+1)%3==0)
                        System.out.print("\n");
                }   
            }
            System.out.println("Step " +(k+1));
            for(int i=0; i<goalPuzzle.size();++i){
                if(goalPuzzle.get(i)!=0)
                    System.out.print(goalPuzzle.get(i));
                else
                    System.out.print(" ");
                if((i+1)%3==0)
                    System.out.print("\n");
            } 
        }
            
       
          
    }
    private static int factorial(int n){
        if(n==0)
            return 1;
        else
            return factorial(n-1)*n;
    }
    private static void initGraph(ListGraph g,ArrayList<ArrayList<Integer>> allLists){
       int c1,c2,index=0,tmp,zeroInd,graphInd=-1;
       int[] step={-3,-1,1,3};
       int[] values={0,1,2,3,4,5,6,7,8};
      
       ArrayList<Integer> list=new ArrayList<Integer>();
       ArrayList<Integer> list2=new ArrayList<Integer>();
       for(c1=0;c1<9;++c1){
           list.add(c1);
           list2.add(c1);
       }
      /*
       for(c1=0;c1<8;++c1){
           for(c2=c1+1;c2<9;++c2){
               tmp=list2.get(c1);
               list2.set(c1, list2.get(c2));         
               list2.set(c2,tmp);
               allLists.add(new ArrayList<Integer>(list2));
               System.out.println(list2 +" "+ c1+"<->"+c2);
               list2.clear();
               list2.addAll(list);
           }
       }
       */
       
       allLists=permuteUnique(values);
       System.out.println("all List size=" + allLists.size());
       
       System.out.println("Preparing Graph");
       /*set dests*/
       File f=new File("8puzzleGraph.txt");
       if(f.exists()&& !f.isDirectory()){
                 
           BufferedReader bR;
           try {
               bR = new BufferedReader(new FileReader(f));
               g.loadEdgesFromFile(bR);
           } catch (FileNotFoundException ex) {
               Logger.getLogger(Cse222_hw8.class.getName()).log(Level.SEVERE, null, ex);
           } catch (IOException ex) {
               Logger.getLogger(Cse222_hw8.class.getName()).log(Level.SEVERE, null, ex);
           }
           
           return;
       }
       long nodeCount=0;
       for(c1=0;c1<allLists.size();++c1){
/*           
           if((((double)c1/allLists.size())*100)%10==0)
               System.out.println((((double)c1/allLists.size())*100));
        */
          /* if(c1%100==0)
              System.out.println(c1);*/
           
           list2.clear();
           list2.addAll(allLists.get(c1));
           zeroInd=list2.indexOf(0);
          /* System.out.println(list2);*/
           if(zeroInd%2==1){
               // edge
               for(int i:step){           
                    if(zeroInd+i>-1 && zeroInd+i<9){
                        list.clear();
                        list.addAll(list2);
                        //swap
                        tmp=list.get(zeroInd+i);
                        list.set(zeroInd+i, list.get(zeroInd));
                        list.set(zeroInd, tmp);
                        //find dest
                        for(c2=0;c2<allLists.size();++c2){
                            if(allLists.get(c2).equals(list)){
                                graphInd=c2;
                                break;
                            }
                        }
                        g.insert(new Edge(c1, graphInd));
                        ++nodeCount;
                        /*System.out.println("f1:"+c1+" "+graphInd);*/
                    }
               }  
           }else if(zeroInd%2==0 && zeroInd!=4 ) {
               //corner
                for(int i:step){           
                    if(zeroInd+i>-1 && zeroInd+i<9){
                        list.clear();
                        list.addAll(list2);
                        //swap
                        tmp=list.get(zeroInd+i);
                        list.set(zeroInd+i, list.get(zeroInd));
                        list.set(zeroInd, tmp);
                        //find dest
                        for(c2=0;c2<allLists.size();++c2){
                            if(allLists.get(c2).equals(list)){
                                graphInd=c2;                             
                                break;
                            }
                        }
                        g.insert(new Edge(c1, graphInd));
                        ++nodeCount;
                      /*  System.out.println("f2:"+c1+" "+graphInd);*/
                    }
               } 
           }else{
               //center
                for(int i:step){           
                    if(zeroInd+i>-1 && zeroInd+i<9){
                        list.clear();
                        list.addAll(list2);
                        //swap
                        tmp=list.get(zeroInd+i);
                        list.set(zeroInd+i, list.get(zeroInd));
                        list.set(zeroInd, tmp);
                        //find dest
                        for(c2=0;c2<allLists.size();++c2){
                            if(allLists.get(c2).equals(list)){
                                graphInd=c2;
                                break;
                            }
                        }
                        g.insert(new Edge(c1, graphInd));
                        ++nodeCount;
                       /* System.out.println("f3:"+c1+" "+graphInd);*/
                    }
               } 
           }
       }
       //Graph completed
       try{
        g.saveEdgesToFile("8puzzleGraph.txt");
       }catch(IOException ex){
           System.err.println("File write error");
       }
    }
    public static ArrayList<ArrayList<Integer>> permuteUnique(int[] num) {
            ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
            permuteUnique(num, 0, result);
            return result;
    }

    private static void permuteUnique(int[] num, int start, ArrayList<ArrayList<Integer>> result) {

            if (start >= num.length ) {
                    ArrayList<Integer> item = convertArrayToList(num);
                    result.add(item);
            }

            for (int j = start; j <= num.length-1; j++) {
                    if (containsDuplicate(num, start, j)) {
                            swap(num, start, j);
                            permuteUnique(num, start + 1, result);
                            swap(num, start, j);
                    }
            }
    }

    private static ArrayList<Integer> convertArrayToList(int[] num) {
            ArrayList<Integer> item = new ArrayList<Integer>();
            for (int h = 0; h < num.length; h++) {
                    item.add(num[h]);
            }
            return item;
    }

    private static boolean containsDuplicate(int[] arr, int start, int end) {
            for (int i = start; i <= end-1; i++) {
                    if (arr[i] == arr[end]) {
                            return false;
                    }
            }
            return true;
    }

    private static void swap(int[] a, int i, int j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
    }
    
    
}
