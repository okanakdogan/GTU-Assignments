package hw06_121044017;

/**
 * @author Okan
 * @version 1.0
 * @created 03-May-2014 13:10:21
 */
public interface PriorityQueue<E> {

	public E element();

	/**
	 * 
	 * @param item
	 */
	public boolean offer(E item);

	public E peek();

	public E poll();

	public E remove();

}