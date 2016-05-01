package cse222_hw02;
import java.util.*;

/** This class implements some of the methods of the Java
*   ArrayList class.
*   @author Koffman & Wolfgang
*/

public class KWArrayList < E > {
  // Data Fields
  /** The default initial capacity */
  private static final int INITIAL_CAPACITY = 10;

  /** The underlying data array */
  private E[] theData;

  /** The current size */
  private int size = 0;

  /** The current capacity */
  private int capacity = 0;

  /** Construct an empty KWArrayList with the default
        initial capacity
   */
  public KWArrayList() {
    capacity = INITIAL_CAPACITY;
    theData = (E[])new Object[capacity];
  }

  /** Add an entry to the data inserting it before the
        item at the specified index.
        @param index - The index of the time that the new
        value it to be inserted in front of.
        @param theValue - The value to be inserted
        @throws ArrayIndexOUtOfBoundsException if index is
        less than zero or greater than size
   */
  public boolean add(E anEntry) {
    if (size == capacity) {
      reallocate();
    }
    theData[size] = anEntry;
    size++;
    return true;
  }

  /** Get a value in the array based on its index.
        @param index - The index of the item desired
        @return The contents of the array at that index
        @throws ArrayIndexOutOfBoundsException - if the index
        is negative or if it is greater than or equal to the
        current size
   */
  public E get(int index) {
    if (index < 0 || index >= size) {
      throw new ArrayIndexOutOfBoundsException(index);
    }
    return theData[index];
  }

  /** Set the value in the array based on its index.
        @param index - The index of the item desired
        @param newValue - The new value to store at this position
        @return The old value at this position
        @throws ArrayIndexOutOfBoundsException - if the index
        is negative or if it is greater than or equal to the
        current size
   */
  public E set(int index, E newValue) {
    if (index < 0 || index >= size) {
      throw new ArrayIndexOutOfBoundsException(index);
    }
    E oldValue = theData[index];
    theData[index] = newValue;
    return oldValue;
  }

  /** Remove an entry based on its index
        @param index - The index of the entry to be removed
        @return The value removed
        @throws ArrayIndexOutOfBoundsException - if the index
        is negative or if it is greater than or equal to the
        current size
   */
  public E remove(int index) {
    if (index < 0 || index >= size) {
      throw new ArrayIndexOutOfBoundsException(index);
    }
    E returnValue = theData[index];
    for (int i = index + 1; i < size; i++) {
      theData[i - 1] = theData[i];
    }
    size--;
    return returnValue;
  }

  /** Allocate a new array to hold the directory
   */
  private void reallocate() {
    capacity = 2 * capacity;
    E[] newData = (E[])new Object[capacity];
    System.arraycopy(theData, 0, newData, 0, size);
    theData = newData;
  }

  /** Get the current size of the array
        @return The current size of the array
   */
  public int size() {
    return size;
  }
}
