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
public class GITArrayListTest {
    
    public GITArrayListTest() {
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
     * Test of add method, of class GITArrayList.
     */
    @Test
    public void testAdd() {
        System.out.println("add");
        int index = 0;
        int size=0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        ListIterator itr=instance.listIterator();
        while(itr.hasNext()){
            itr.next();
            ++size;
        }
        System.out.printf("size "+size);
        if(size!=3)
            fail("add test Fails");
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of addAll method, of class GITArrayList.
     */
    @Test
    public void  testAddAll() {
        System.out.println("addAll");
        int index = 0;
        int size=0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();
        GITArrayList<Integer> instance2 = new GITArrayList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        instance2.add(0, 40);
        instance2.add(0, 50);
        instance2.add(0, 60);
        
        instance.addAll(instance2);
        ListIterator itr=instance.listIterator();
         while(itr.hasNext()){
            itr.next();
            ++size;
        }
        if(size!=6)
            fail("addAll test Fails");
        // TODO review the generated test code and remove the default call to fail.
        
    }

    /**
     * Test of addFirst method, of class GITArrayList.
     */
    @Test
    public void  testAddFirst() {
        System.out.println("addFirst");
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addFirst(10);
        if(instance.getFirst()!=10)
           fail("The test case is a prototype.");
        // TODO review the generated test code and remove the default call to fail.
       
    }

    /**
     * Test of addLast method, of class GITArrayList.
     */
    @Test
    public void  testAddLast() {
        System.out.println("addLast");
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addLast(10);
        if(instance.getLast()!=10)
           fail("The test case is a prototype.");
        // TODO review the generated test code and remove the default call to fail.
       
    }

    /**
     * Test of containsAll method, of class GITArrayList.
     */
    @Test
    public void  testContainsAll() {
        System.out.println("containsAll");
        int index = 0;
        int size=0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();
        GITArrayList<Integer> instance2 = new GITArrayList<Integer>();
        GITArrayList<Integer> instance3 = new GITArrayList<Integer>();
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        instance2.add(0, 10);
        instance2.add(0, 20);
        instance2.add(0, 30);
        
        instance3.add(0, 40);
        instance3.add(0, 50);
        instance3.add(0, 60);
        
        instance.containsAll(instance2);
        
       
        boolean expResult = true;
        boolean result = instance.containsAll(instance2);
        
        assertEquals(expResult, result);
        
        result = instance.containsAll(instance3);
        expResult = false;
        
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of get method, of class GITArrayList.
     */
    @Test
    public void  testGet() {
        System.out.println("get");
        int index = 0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addFirst(10);
        int expResult = 10;
        int result = instance.get(index);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getFirst method, of class GITArrayList.
     */
    @Test
    public void  testGetFirst() {
        System.out.println("getFirst");
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addFirst(10);
        int expResult = 10;
        int result = instance.getFirst();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getLast method, of class GITArrayList.
     */
    @Test
    public void  testGetLast() {
        System.out.println("getLast");
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addLast(10);
        int expResult = 10;
        int result = instance.getLast();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of iterator method, of class GITArrayList.
     */
    @Test
    public void  testIterator() {
        System.out.println("iterator");
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addFirst(10);
       
        Iterator expResult = null;
        Iterator result = instance.iterator();
       // assertNull(result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of listIterator method, of class GITArrayList.
     */
    @Test
    public void  testListIterator_0args() {
        System.out.println("listIterator");
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addFirst(10);
        
        ListIterator result = instance.listIterator();
        //assertNull( result);
        // TODO review the generated test code and remove the default call to fail.
       // fail("The test case is a prototype.");
    }

    /**
     * Test of listIterator method, of class GITArrayList.
     */
    @Test
    public void  testListIterator_int() {
        System.out.println("listIterator");
        int index = 0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();

        instance.addFirst(10);
        
        ListIterator result = instance.listIterator(index);
        //assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of removeAll method, of class GITArrayList.
     */
    @Test
    public void  testRemoveAll() {
        System.out.println("removeAll");
        int index=0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();
        GITArrayList<Integer> instance2 = new GITArrayList<Integer>();
    
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        instance2.add(0, 10);
        instance2.add(0, 20);
        
        instance.removeAll(instance2);
        int size=0;
         ListIterator itr=instance.listIterator();
         while(itr.hasNext()){
            itr.next();
            ++size;
        }
        if(size!=1)
            fail("removeAll test Fails");
        
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of retainAll method, of class GITArrayList.
     */
    @Test
    public void  testRetainAll() {
        System.out.println("retainAll");
        int index=0;
        GITArrayList<Integer> instance = new GITArrayList<Integer>();
        GITArrayList<Integer> instance2 = new GITArrayList<Integer>();
    
        instance.add(0, 10);
        instance.add(0, 20);
        instance.add(0, 30);
        
        instance2.add(0, 10);
        instance2.add(0, 20);
        
        instance.retainAll(instance2);
        int size=0;
         ListIterator itr=instance.listIterator();
         while(itr.hasNext()){
            itr.next();
            ++size;
        }
        if(size!=2)
            fail("retainAll test Fails");
        
       
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
