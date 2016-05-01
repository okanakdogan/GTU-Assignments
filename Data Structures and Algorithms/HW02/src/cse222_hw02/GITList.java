package cse222_hw02;

import java.util.Iterator;
import java.util.ListIterator;

/**
 * @author Okan
 * @version 1.0
 * @created 22-Mar-2014 12:43:51
 */
public interface GITList<E> {

	/**
	 * 
	 * @param index
	 * @param obj
	 */
	public void add(int index, E obj);

	/**
	 * 
	 * @param l
	 */
	public boolean addAll(GITList<E> l);

	/**
	 * 
	 * @param item
	 */
	public void addFirst(E item);

	/**
	 * 
	 * @param item
	 */
	public void addLast(E item);

	/**
	 * 
	 * @param l
	 */
	public boolean containsAll(GITList<E> l);

	/**
	 * 
	 * @param index
	 */
	public E get(int index);

	public E getFirst();

	public E getLast();

	public Iterator iterator();

	public ListIterator listIterator();

	/**
	 * 
	 * @param index
	 */
	public ListIterator listIterator(int index);

	/**
	 * 
	 * @param l
	 */
	public boolean removeAll(GITList<E> l);

	/**
	 * 
	 * @param l
	 */
	public boolean retainAll(GITList<E> l);

}