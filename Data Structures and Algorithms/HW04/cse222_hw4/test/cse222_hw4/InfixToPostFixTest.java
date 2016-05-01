/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw4;

import java.util.logging.Level;
import java.util.logging.Logger;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class InfixToPostFixTest {
    
    public InfixToPostFixTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @Before
    public void setUp() {
    }

    /**
     * Test of convert method, of class InfixToPostFix.
     * @throws java.lang.Exception
     */
    @Test
    public void testConvert() throws Exception {
        System.out.println("convert");
        String infix = "sin x + cos 50 + tan x * log 10 / exp 10 - abs 20 + minus 10 - sqrt 4";
        InfixToPostFix instance = new InfixToPostFix();
        String expResult ="x sin 50 cos + x tan + 10 log * 10 exp / 20 abs - 10 minus + 4 sqrt - ";
        String result="";
        try {
            result = instance.convert(infix);
        } catch (InfixToPostFix.SyntaxErrorException ex) {
            Logger.getLogger(InfixToPostFixTest.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        System.out.println(result);
        System.out.println(expResult);
        assertEquals(expResult, result);
            
        
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
