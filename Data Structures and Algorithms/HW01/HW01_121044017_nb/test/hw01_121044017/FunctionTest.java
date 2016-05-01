/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw01_121044017;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class FunctionTest {
    
    public FunctionTest() {
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
    
    @After
    public void tearDown() {
    }

    /**
     * Test of finalize method, of class Function.
     * @throws java.lang.Exception
     */
    @Test
    public void testFinalize() throws Exception {
        System.out.println("finalize");
        Function instance = new Function();
        //instance.finalize();
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getColor method, of class Function.
     */
    @Test
    public void testGetColor() {
        System.out.println("getColor");
        Function instance = new Function("sin(x)",-3.0,3.0,"red");
        String expResult = "red";
        String result = instance.getColor();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getName method, of class Function.
     */
    @Test
    public void testGetName() {
        System.out.println("getName");
        Function instance = new Function("sin(x)",-3.0,3.0,"red");
        String expResult = "sin(x)";
        String result = instance.getName();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getRange method, of class Function.
     */
    @Test
    public void testGetRange() {
        System.out.println("getRange");
        Function instance = new Function("sin(x)",-3.0,3.0,"red");
        double[] expResult = {-3.0,3.0};
        double[] result = instance.getRange();
        assertArrayEquals(expResult, result,0.001);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of setColor method, of class Function.
     */
    @Test
    public void testSetColor() {
        System.out.println("setColor");
        String color = "blue";
        Function instance = new Function("sin(x)",-3.0,3.0,"red");
        instance.setColor(color);
        
        assertEquals(color,instance.getColor());
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of setName method, of class Function.
     */
    @Test
    public void testSetName() {
        System.out.println("setName");
        String name = "";
        Function instance = new Function();
        instance.setName(name);
        assertEquals(name,instance.getName());
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
