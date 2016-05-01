/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw01_121044017;

import java.awt.Graphics;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class CanvasTest {
    
    public CanvasTest() {
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
     * Test of finalize method, of class Canvas.
     */
    @Test
    public void testFinalize() throws Exception {
        System.out.println("finalize");
        Canvas instance = new Canvas();
        //instance.finalize();
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of ClearVisualization method, of class Canvas.
     */
    @Test
    public void testClearVisualization() {
        System.out.println("ClearVisualization");
        Canvas instance = new Canvas();
        instance.ClearVisualization();
        
        assertEquals(0,instance.getFuncs().arraySize());
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of paintComponent method, of class Canvas.
     */
    @Test
    public void testPaintComponent() {
       // System.out.println("paintComponent");
       // Graphics g =null
        //Canvas instance = new Canvas();
        //instance.paintComponent(g);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of ReadFile method, of class Canvas.
     */
    @Test
    public void testReadFile() {
        System.out.println("ReadFile");
        String fileName = "C:\file.txt";
        Canvas instance = new Canvas();
        boolean expResult = false;
        boolean result = instance.ReadFile(fileName);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getFuncs method, of class Canvas.
     */
    @Test
    public void testGetFuncs() {
        System.out.println("getFuncs");
        Canvas instance = new Canvas();
        FunctionGroup expResult = new FunctionGroup();
        FunctionGroup result = instance.getFuncs();
        assertFalse(expResult.equals(result));
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
