package cse222_hw02;

import java.util.Iterator;
import java.util.ListIterator;

/**
 * @author Okan
 * @version 1.0
 * @created 22-Mar-2014 12:43:51
 */
public class GITLinkedList<E> implements GITList<E> {

        private KWLinkedList<E> lList;
	public GITLinkedList(){
            lList=new KWLinkedList<E>();
	}

	public void finalize() throws Throwable {

	}

	/**
	 *adds given object to given index
	 * 
	 * @param index for insert location
	 * @param obj to add
	 */
	public void add(int index, E obj){
            lList.add(index, obj);
            
	}

	/**
	 * adds all elements in given other list
	 * @param l other list
	 */
	public boolean addAll(GITList<E> l){
                ListIterator<E> i=l.listIterator();
                /*add all elements in other list*/
                while(i.hasNext()){
                    lList.addLast(i.next());
                }
		return true;
	}

	/**
	 * adds to arraylist first location given item 
	 * @param item to add
	 */
	public void addFirst(E item){
            lList.addFirst(item);
            
	}

	/**
	 * adds to array's last location given item 
	 * @param item to add
	 */
	public void addLast(E item){
            lList.addLast(item);
            
	}

	/**
	 * checks for all elements of our list  for contain elemnts in other list
	 * @param l other list
	 */
	public boolean containsAll(GITList<E> l){
                ListIterator itr=l.listIterator(0);
                ListIterator itr2;
                int i;
                E value;
                boolean contains=false;
                /*for all elements in other list*/
                while(itr.hasNext()){
                    
                    value=(E)itr.next();
                    contains=false;
                    itr2=listIterator();
                    
                    /*for all elements in our list*/
                    while(itr2.hasNext()){
                        if(itr2.next().equals(value))
                            contains=true;
                    }
                    if(contains==false)
                        break;
                }
                
		return contains;
		
	}

	/**
	 * gets element given index
	 * @param index
	 */
	public E get(int index){
		return lList.get(index);
	}
         /**
	 * gets element first
	 * 
         * @return element at first
	 */
	public E getFirst(){
		return lList.getFirst();
	}
         /**
	 * gets element last
	 * 
         * @return element at last
	 */   
	public E getLast(){
		return lList.getLast();
	}
        /**
	 * gives iterator for LinkedList
	 * 
         * @return iterator
	 */
	public Iterator iterator(){
		return lList.iterator();
	}
        /**
	 * gives ListIterator for LinkedList
	 * 
         * @return listIterator
	 */
	public ListIterator listIterator(){
		return lList.listIterator();
	}

	/**
	 *  gives ListIterator for LinkedList that starts from given index 
	 * @param index start location of iterator
         * @return ListIterator
	 */
	public ListIterator listIterator(int index){
		return lList.listIterator(index);
	}

	/**
	 * removes from linkedList, elements that same with elements in other list 
	 * @param l other list
	 */
	public boolean removeAll(GITList<E> l){
            
		ListIterator itr=l.listIterator(0);
                ListIterator itr2;
                int i;
                E value,myValue;
                
                if (itr==null)
                    return false;
                /*for all elements in othet list*/
                while(itr.hasNext()){
                    value=(E)itr.next();
                    itr2=listIterator();
                    /*for all elements in our list*/
                    while(itr2.hasNext()){
                        
                        if(itr2.next().equals(value)){                           
                           itr2.remove();
                           
                        }                      
                    }  
                }
               
               
		return true;
	}

	/**
	 * removes from LinkedList, elements that diffrent with elements in other list 
	 * @param l other list
	 */
	public boolean retainAll(GITList<E> l){
		ListIterator itr=l.listIterator(0);
                ListIterator itr2=listIterator();
                int i;
                boolean contains=false;
                E value,myValue;
                if (itr==null)
                    return false;
                /*for all elements in our list*/
               while(itr2.hasNext()){
                   myValue=(E)itr2.next();
                   itr=l.listIterator(0);
                   contains=false;
                   
                   /*for all elements in othet list*/
                   while(itr.hasNext()){
                       value=(E)itr.next();
                       if(myValue.equals(value)){
                           contains=true;
                           break;
                       }
                   }
                   if(contains==false)
                       itr2.remove();
               }
		return true;
	}

}