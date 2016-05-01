/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw06_121044017;

import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class GITPriorityQueueTest {
    
    public GITPriorityQueueTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @Before
    public void setUp() {
    }

    /**
     * Test of element method, of class GITPriorityQueue.
     */
    @Test
    public void testElement() {
        System.out.println("element");
        GITPriorityQueue<Integer> instance = new GITPriorityQueue<Integer>();
        instance.offer(10);
        instance.offer(20);
        instance.offer(8);
        int expResult = 8;
        int result = instance.element();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of offer method, of class GITPriorityQueue.
     */
    @Test
    public void testOffer() {
        System.out.println("offer");
        int item = 10;
        GITPriorityQueue<Integer> instance = new GITPriorityQueue();
        boolean expResult = true;
        boolean result = instance.offer(item);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of peek method, of class GITPriorityQueue.
     */
    @Test
    public void testPeek() {
        System.out.println("peek");
        GITPriorityQueue<Integer> instance = new GITPriorityQueue<Integer>();
        instance.offer(10);
        int expResult = 10;
        int result = instance.peek();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of poll method, of class GITPriorityQueue.
     */
    @Test
    public void testPoll() {
        System.out.println("poll");
        GITPriorityQueue<Integer> instance = new GITPriorityQueue<Integer>();
        instance.offer(10);
        instance.offer(20);
        
        int expResult = 10;
        int result = instance.poll();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of remove method, of class GITPriorityQueue.
     */
    @Test
    public void testRemove() {
        System.out.println("remove");
        GITPriorityQueue<Integer> instance = new GITPriorityQueue<Integer>();
        instance.offer(10);
        int expResult = 10;
        int result = instance.remove();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of ToString method, of class GITPriorityQueue.
     */
    @Test
    public void testToString() {
        System.out.println("ToString");
        GITPriorityQueue<Integer> instance = new GITPriorityQueue<Integer>();
        instance.offer(10);
        String expResult = "10\n  null\n  null\n";
        String result = instance.ToString();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
