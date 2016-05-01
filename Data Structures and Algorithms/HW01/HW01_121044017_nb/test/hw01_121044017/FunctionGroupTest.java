/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw01_121044017;

import org.junit.After;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class FunctionGroupTest {
    
    public FunctionGroupTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @Before
    public void setUp() {
    }
    
    @After
    public void tearDown() {
    }

    /**
     * Test of finalize method, of class FunctionGroup.
     */
    @Test
    public void testFinalize() throws Exception {
        System.out.println("finalize");
        FunctionGroup instance = new FunctionGroup();
        //instance.finalize();
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of addFunc method, of class FunctionGroup.
     */
    @Test
    public void testAddFunc() {
        System.out.println("addFunc");
        Function func =new Function("sin(x)",-3.0,3.0,"red");
        FunctionGroup instance = new FunctionGroup();
        instance.addFunc(func);
        assertEquals(func,instance.at(0));
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of at method, of class FunctionGroup.
     */
    @Test
    public void testAt() {
        System.out.println("at");
        int index = 0;
        FunctionGroup instance = new FunctionGroup();
        
        instance.addFunc(new Function("sin(x)",-3.0,3.0,"red"));
        Function expResult = new Function("sin(x)",-3.0,3.0,"red");
        
        Function result = instance.at(index);
        assertFalse(expResult.equals(result));
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
        
    }

    /**
     * Test of arraySize method, of class FunctionGroup.
     */
    @Test
    public void testArraySize() {
        System.out.println("arraySize");
        FunctionGroup instance = new FunctionGroup();
        int expResult = 0;
        int result = instance.arraySize();
        assertEquals(expResult, result);
        
        instance.addFunc(new Function("sin(x)",-3.0,3.0,"red"));
        
        expResult=1;
        result=instance.arraySize();
        assertEquals(expResult, result);
        
        
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of deleteFunc method, of class FunctionGroup.
     */
    @Test
    public void testDeleteFunc() {
        System.out.println("deleteFunc");
        String name = "log(x)";
        FunctionGroup instance = new FunctionGroup();
        boolean expResult = false;
        boolean result = instance.deleteFunc(name);
        assertEquals(expResult, result);
        
        
        instance.addFunc(new Function("sin(x)",-3.0,3.0,"red"));
        name="sin(x)";
        expResult=true;
        result=instance.deleteFunc(name);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
