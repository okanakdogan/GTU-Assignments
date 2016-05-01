/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw5;

import java.util.LinkedList;
import java.util.Stack;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class PostfixEvaluatorTest {
    
    public PostfixEvaluatorTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @Before
    public void setUp() {
    }

    /**
     * Test of eval method, of class PostfixEvaluator.
     */
    @Test
    public void testEval() throws Exception {
        System.out.println("eval");
        String expression = "10 sin 50 cos + 10 tan + 10 log * 10 exp / 20 abs - 10 minus + 4 sqrt -";
        Stack<Integer> stackInt=new Stack<Integer>();
        LinkedList<LinkedList<Variable>> vars =new LinkedList<LinkedList<Variable>>();
        
        vars.add(new LinkedList<Variable>());
        vars.peek().add(new Variable("x",10.0));
        stackInt.push(0);
        
        PostfixEvaluator instance = new PostfixEvaluator();
        double expResult = -31.99989621935848;
        double result = instance.eval(expression, vars,stackInt);
        assertEquals(expResult, result, 0.0);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
