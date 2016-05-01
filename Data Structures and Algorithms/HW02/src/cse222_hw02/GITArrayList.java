package cse222_hw02;

import java.util.Iterator;
import java.util.ListIterator;
import java.util.NoSuchElementException;

/**
 * @author Okan
 * @version 1.0
 * @created 22-Mar-2014 12:43:51
 */
public class GITArrayList<E> implements GITList<E> {

        private KWArrayList<E> aList;
       
	public GITArrayList(){
            aList=new KWArrayList<E>();
	}

	public void finalize() throws Throwable {

	}

	/**
         * adds given object to given index
	 * 
	 * @param index for insert location
	 * @param obj to add
	 */
	public void add(int index, E obj){
            
             E valueOld=null,valueNew;
             int i=index;
             /*if list empty just add*/
             if(aList.size()==0)
                  aList.add(obj);
             else{
                 /*insert elemnt given index*/
                valueNew=aList.get(index);
                aList.set(i,obj);
                i++;
                /*shift other elements*/
                while(i<aList.size()){
                    valueOld=aList.get(i);
                    aList.set(i, valueNew);
                    valueNew=valueOld;
                    ++i;
                 }
                /*add last shift element*/
                aList.add(valueNew);
             }
	}

	/**
	 * adds all elements in given other list
	 * @param l other list
	 */
	public boolean addAll(GITList<E> l){
                ListIterator<E> i=l.listIterator();
                /*add with loop*/
                while(i.hasNext()){
                    aList.add(i.next());
                }
		return true;
	}

	/**
	 * adds to arraylist first location given item 
	 * @param item to add
	 */
        @Override
	public void addFirst(E item){
              this.add(0,item);
	}

	/**
	 * adds to array's last location given item 
	 * @param item to add
	 */
	public void addLast(E item){
            aList.add(item);
	}

	/**
	 * checks for all elements of our list  for contain elemnts in other list
	 * @param l other list
	 */
	public boolean containsAll(GITList<E> l){
                ListIterator itr=l.listIterator(0);
                int i;
                E value;
                boolean contains=false;
                /*take one of element form other list*/
                while(itr.hasNext()){
                    value=(E)itr.next();
                    contains=false;
                    /*for all elements in our list*/ 
                    for(i=0;i<aList.size();++i){
                        /*check elements are same*/
                        if(aList.get(i).equals(value))
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
		return aList.get(index);
	}
        /**
	 * gets element first
	 * 
         * @return element at first
	 */
	public E getFirst(){
		return aList.get(0);
	}
         /**
	 * gets element last
	 * 
         * @return element at last
	 */    
	public E getLast(){
		return aList.get(aList.size()-1);
	}
         /**
	 * gives iterator for arraylist
	 * 
         * @return iterator
	 */
	public Iterator iterator(){
		return new Itr();
	}
        /**
	 * gives ListIterator for arraylist
	 * 
         * @return listIterator
	 */
	public ListIterator listIterator(){
		return new listItr(0);
	}

	/**
	 *  gives ListIterator for arraylist that starts from given index 
	 * @param index start location of iterator
         * @return ListIterator
	 */
        @Override
	public ListIterator listIterator(int index){
		return new listItr(index);
	}

	/**
	 * removes from arraylist, elements that same with elements in other list 
	 * @param l other list
	 */
	public boolean removeAll(GITList<E> l){
                ListIterator itr=l.listIterator(0);
                int i;
                E value;
                /*run in all elements in other list*/
                while(itr.hasNext()){
                    value=(E)itr.next();
                    /*run in all elements in our list for each elemt from other list*/
                    for(i=0;i<aList.size();++i){
                        
                        if(aList.get(i).equals(value)){
                            
                           aList.remove(i);
                           
                            --i;
                        }
                    }     
                }      
		return true;
	}

	/**
	 * removes from arraylist, elements that diffrent with elements in other list 
	 * @param l other list
	 */
	public boolean retainAll(GITList<E> l){
		 ListIterator itr=l.listIterator(0);
                int i;
                boolean contains=false;
                E value;
                /*run for all elements in our list*/
               for(i=0;i<aList.size();++i){
                   itr=l.listIterator(0);
                   contains=false;
                   /*check for all elements in other list*/
                   while(itr.hasNext()){
                       value=(E)itr.next();
                       if(aList.get(i).equals(value)){
                           contains=true;
                           break;
                       }
                   }
                   if(contains==false)
                       aList.remove(i);
               }
		return true;
	}
        
        private class Itr implements Iterator<E>{
            int cursor;
            int lastRet=-1;
            
            public boolean hasNext(){
                return cursor!=aList.size();
            }
            
            public E next(){
                
                if(hasNext()){
                  lastRet=cursor;
                  ++cursor;  
                  
                  return  aList.get(lastRet);
                }
                else
                   return null;
            }
            
            public void remove(){
                if(lastRet<0)
                   throw new IllegalStateException();
                else{
                    aList.remove(lastRet);
                }
                
            }
           
        }
        
        public class listItr extends Itr implements ListIterator<E>{
            listItr(int index){
                super();
                cursor=index;
            }
            public boolean hasPrevious(){
                return cursor!=0;
            }
            public int nextIndex(){
                return cursor;
            }
            public int previousIndex(){
                return cursor-1;
            }
            public E previous(){
                if(cursor-1<0)
                    throw new NoSuchElementException();
                else if(cursor-1>aList.size()) {
                    throw new IndexOutOfBoundsException();
                }
                else{
                    --cursor;
                    lastRet=cursor;
                    return aList.get(cursor);
                }       
            }
            public void set(E e){
                if(lastRet<0)
                    throw new IllegalStateException();
                else{
                    aList.set(lastRet, e);
                }
                
            }
            public void add(E e){
                GITArrayList.this.add(cursor, e);
                cursor++;
                lastRet=-1;
 
            }
              
        }

}