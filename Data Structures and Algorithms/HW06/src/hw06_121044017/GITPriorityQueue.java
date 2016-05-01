package hw06_121044017;

import java.io.BufferedReader;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.Stack;

/**
 * @author Okan
 * @version 1.0
 * @created 03-May-2014 13:10:21
 */
public class GITPriorityQueue<E> extends BinaryTree<E> implements PriorityQueue<E> {
        //Data Fields
        /** An optional reference to a Comparator object. */
	private Comparator<E> comparator=null;
        /** The BinaryTree to hold the data. */
	private BinaryTree<E> theData;
        private int numOfElements;

        //Constructor
	public GITPriorityQueue(){
            theData=new BinaryTree<E>();
            numOfElements=0;
	}

	/** Creates a heap-based priority tree 
         * that orders its elements according to the specified
         *  comparator.
         *  @param comp The comparator used to order this priority queue
         */
	public GITPriorityQueue(Comparator<E> comp){
            theData=new BinaryTree<E>();
            comparator=comp;
	}

	/** Compare two items using either a Comparator object’s compare method
            or their natural ordering using method compareTo.
            pre: If comparator is null, left and right implement Comparable<E>.
            @param left One item
            @param right The other item
            @return Negative int if left less than right,
               0 if left equals right,
               positive int if left > right
            @throws ClassCastException if items are not Comparable
        */
	private int compare(E left, E right){
            if (comparator != null) { // A Comparator is defined.
              return comparator.compare(left, right);
            }
            else { // Use left’s compareTo method.
              return ( (Comparable < E > ) left).compareTo(right);
            }
	}
        /**
         * gets small priority from tree
         * @return priority data 
         * @throws NoSuchElementException if tree empty null
         */
	public E element(){
            E data=peek();
            if(data==null)
                throw new NoSuchElementException();
            else
                return data;
	}

	/** Insert an item into the priority queue.
          pre: The Binarytree theData is in heap order.
          post: The item is in the priority queue and
                theData is in heap order.
          @param item The item to be inserted
          @throws NullPointerException if the item to be inserted is null.
       */
	public boolean offer(E item){
           if (item==null)
               throw new NullPointerException();
           Stack<Integer> path;
           path=add(item);
           makeHeap(path, theData);
           return true;
	} 
        /**
         * adds item to correct location for complete tree 
         * @param item to add
         * @return integer stack that show way of last added data 
         */
        private Stack<Integer> add(E item){
             ++numOfElements;
            int temp=numOfElements;
            if(temp==1){
                theData=new BinaryTree<E>(new Node(item));
                return null;
            }
            Stack<Integer>path=new Stack<Integer>();
            Stack<Integer>returnPath=new Stack<Integer>();
            
            BinaryTree<E> root=theData;
            while(temp>1){
                path.push(temp%2);
                returnPath.push(temp%2); 
                temp/=2;               
            }
            
             while(path.size()>1){
                 if(path.pop()==0)
                     root=root.getLeftSubtree();
                 else
                     root=root.getRightSubtree();
             }
            if(path.pop()==0)
               root.setLeftSubtree(new BinaryTree<E>(new Node(item)));
            else
               root.setRightSubtree(new BinaryTree<E>(new Node(item)));
            return returnPath;
        }
        /**
         * moves data given path to correct place for make heap
         * 
         * @param path integer stack that shows way to last added
         * @param root tree root
         */
        private void makeHeap(Stack<Integer>path, BinaryTree<E> root){
            if(path==null)
                return;
            if(path.size()>1){
                if(path.pop()==0)
                    makeHeap(path,root.getLeftSubtree());
                else
                    makeHeap(path, root.getRightSubtree());
            }
            else{
                if(path.pop()==0){
                    if(compare(root.getData(), (E)root.getLeftSubtree().getData())>0){
                        E temp=root.getData();
                        root.root.data=(E)root.getLeftSubtree().getData();
                        root.getLeftSubtree().root.data=temp;
                    }
                       
                }
                else{
                    if(compare(root.getData(), (E)root.getRightSubtree().getData())>0){
                        E temp=root.getData();
                        root.root.data=(E)root.getRightSubtree().getData();
                        root.getRightSubtree().root.data=temp;
                    }
                }
                    
            }
        }
        /**
         * gets small priority from tree
         * @return priority data if tree empty null
         */
	public E peek(){
		return theData.getData();
	}
        /**
         * gets small priority and removes from tree
         * @return priority data if tree empty null
         */
	public E poll(){
            E data=peek();
            if(data==null){
                return data;
            }else{
                if(numOfElements==1){
                    theData=null;
                    return data;
                }
                Stack<Integer>path=new Stack<Integer>();
                int temp=numOfElements;
                BinaryTree<E> root=theData;
                while(temp>1){
                path.push(temp%2); 
                temp/=2;               
                }
                 while(path.size()>1){
                 if(path.pop()==0)
                     root=root.getLeftSubtree();
                 else
                     root=root.getRightSubtree();
                }
                 if(path.pop()==0){
                    theData.root.data=(E)root.getLeftSubtree().getData();
                    root.setLeftSubtree(null);
                    
                 }
                 else{
                    theData.root.data=(E)root.getRightSubtree().getData();
                    root.setRightSubtree(null);
                 }                
                 --numOfElements;
                 //makeheap
                 makeHeapFromRoot(theData);
                 return data;
            }
            
	}
        /**
         * makes given tree heap(priorty)
         * @param root tree
         */
        private void makeHeapFromRoot(BinaryTree<E> root){
            if(!root.isLeaf()){
                //if there is only right child and bigger then child swap
                if(root.getLeftSubtree()==null &&
                   compare(root.getData(),(E)root.getRightSubtree().getData())>0){
                    E temp=root.getData();
                    root.root.data=(E)root.getRightSubtree().getData();
                    root.getRightSubtree().root.data=temp;
                    makeHeapFromRoot(root.getRightSubtree());
                }
                //if there is only left child and bigger then child swap
                else if(root.getRightSubtree()==null &&
                        compare(root.getData(),(E)root.getLeftSubtree().getData())>0){
                    E temp=root.getData();
                    root.root.data=(E)root.getLeftSubtree().getData();
                    root.getLeftSubtree().root.data=temp;
                    makeHeapFromRoot(root.getLeftSubtree());
                }
                //if have two children
                else if(root.getLeftSubtree()!=null && root.getRightSubtree()!=null){
                      //select small child
                      if(compare((E)root.getLeftSubtree().getData(),(E)root.getRightSubtree().getData())<0){
                          //if small child is left and bigger then child swap
                          if(compare(root.getData(),(E)root.getLeftSubtree().getData())>0){
                               E temp=root.getData();
                               root.root.data=(E)root.getLeftSubtree().getData();
                               root.getLeftSubtree().root.data=temp;
                               makeHeapFromRoot(root.getLeftSubtree());
                          }
                      }else{
                          //if small child is left and bigger then child swap
                         if(compare(root.getData(),(E)root.getRightSubtree().getData())>0){
                             E temp=root.getData();
                            root.root.data=(E)root.getRightSubtree().getData();
                            root.getRightSubtree().root.data=temp;
                            makeHeapFromRoot(root.getRightSubtree());
                         }                         
                      }                       
                }
            }
        }
        /**
         * gets small priority and removes from tree
         * @return priority data
         * @throws NoSuchElementException if tree is null
         */
        @Override
	public E remove(){
               E data=poll();
               if(data==null)
                   throw new NoSuchElementException();
               else
                   return data;          
	}

	/**
	 * 
	 * @param i
	 * @param j
	 */
	private void swap(int i, int j){

	}

	public String ToString(){
		return theData.ToString();
	}

}