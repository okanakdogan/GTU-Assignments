/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw02;

import java.util.Iterator;
import java.util.ListIterator;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class GITLinkedListTest {
    
    public GITLinkedListTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @AfterClass
    public static void tearDownClass() {
    }
    
    @Before
    public void setUp() {
    }

    

    /**
     * Test of add method, of class GITLinkedList.
     */
    @Test
     public void testAdd() {
        System.out.println("add");
        int index = 0;
        
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(index, 10);
        instance.add(index, 20);
        instance.add(index, 30);
        
        ListIterator itr=instance.listIterator();
        while(itr.hasNext()){
            itr.next();
            ++index;
        }
        if(index!=3)
          fail("The test case is a prototype.");  
        // TODO review the generated test code and remove the default call to fail.
        
    }

    /**
     * Test of addAll method, of class GITLinkedList.
     */
    @Test
     public void testAddAll() {
        System.out.println("addAll");
        int index=0;
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        GITLinkedList<Integer> instance2 = new GITLinkedList<Integer>();
        instance2.add(0, 60);
        instance2.add(0, 50);
        instance2.add(0, 40);
        
        
        boolean result = instance.addAll(instance2);
        
        ListIterator itr=instance.listIterator();
        while(itr.hasNext()){
            itr.next();
            ++index;
        }
        if(index!=6)
          fail("The test case is a prototype.");
        
    }

    /**
     * Test of addFirst method, of class GITLinkedList.
     */
    @Test
     public void testAddFirst() {
        System.out.println("addFirst");
        
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();       
        instance.addFirst(10);
        
        if(instance.get(0)!=10)
            fail("The test case is a prototype.");
        // TODO review the generated test code and remove the default call to fail.
        
    }

    /**
     * Test of addLast method, of class GITLinkedList.
     */
    @Test
     public void testAddLast() {
        System.out.println("addLast");
       
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();       
        instance.addLast(10);
        
        if(instance.getLast()!=10)
            fail("The test case is a prototype.");
    }

    /**
     * Test of containsAll method, of class GITLinkedList.
     */
    @Test
    public void testContainsAll() {
        System.out.println("containsAll");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        GITLinkedList<Integer> instance2 = new GITLinkedList<Integer>();
        instance2.add(0, 10);
        instance2.add(0, 20);
        instance2.add(0, 30);
        
        boolean expResult = true;
        boolean result = instance.containsAll(instance2);
        assertEquals(expResult, result);
        
        instance2.add(0, 40);
        
        expResult = false;
        result = instance.containsAll(instance2);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of get method, of class GITLinkedList.
     */
    @Test
    public void testGet() {
        System.out.println("get");
        int index = 0;
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();       
        instance.addLast(10);
        int result = instance.get(index);
        assertEquals(10, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getFirst method, of class GITLinkedList.
     */
    @Test
    public void testGetFirst() {
        System.out.println("getFirst");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        int expResult = 30;
        int result = instance.getFirst();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getLast method, of class GITLinkedList.
     */
    @Test
    public void testGetLast() {
        System.out.println("getLast");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        int expResult = 10;
        int result = instance.getLast();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of iterator method, of class GITLinkedList.
     */
    @Test
    public void testIterator() {
        System.out.println("iterator");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        //Iterator expResult = null;
        Iterator result = instance.iterator();
        //if no exception it is ok
        
        //assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of listIterator method, of class GITLinkedList.
     */
    @Test
    public void testListIterator_0args() {
        System.out.println("listIterator");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        //ListIterator expResult = null;
        ListIterator result = instance.listIterator();
        //if no exception it is ok
        
        //assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
       // fail("The test case is a prototype.");
    }

    /**
     * Test of listIterator method, of class GITLinkedList.
     */
    @Test
    public void testListIterator_int() {
        System.out.println("listIterator");
        int index = 0;
        GITLinkedList instance = new GITLinkedList();
        //ListIterator expResult = null;
        ListIterator result = instance.listIterator(index);
        //if no exception it is ok
        
        //assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of removeAll method, of class GITLinkedList.
     */
    @Test
    public void testRemoveAll() {
        System.out.println("removeAll");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        GITLinkedList<Integer> instance2 = new GITLinkedList<Integer>();
        instance2.add(0, 10);
        instance2.add(0, 20);
        
        
        
        boolean expResult = true;
        boolean result = instance.removeAll(instance2);
        
        
        assertEquals(expResult, result);
        
        if(instance.getLast()!=30)
           fail("The test case is a prototype."); 
        // TODO review the generated test code and remove the default call to fail.
        
    }

    /**
     * Test of retainAll method, of class GITLinkedList.
     */
    @Test
    public void testRetainAll() {
        System.out.println("retainAll");
        GITLinkedList<Integer> instance = new GITLinkedList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        GITLinkedList<Integer> instance2 = new GITLinkedList<Integer>();
        instance2.add(0, 10);
        instance2.add(0, 20);
        
        boolean expResult = true;
        boolean result = instance.retainAll(instance2);
        assertEquals(expResult, result);
        
        if(instance.getFirst()!=20 || instance.getLast()!=10)
           fail("Retain error"); 
        // TODO review the generated test code and remove the default call to fail.
        
    }
    
}
