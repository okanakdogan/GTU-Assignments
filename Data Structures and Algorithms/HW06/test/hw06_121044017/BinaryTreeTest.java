/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw06_121044017;

import java.io.BufferedReader;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author Okan
 */
public class BinaryTreeTest {
    
    public BinaryTreeTest() {
    }
    
    @BeforeClass
    public static void setUpClass() {
    }
    
    @Before
    public void setUp() {
    }

    /**
     * Test of getData method, of class BinaryTree.
     */
    @Test
    public void testGetData() {
        System.out.println("getData");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        int expResult = 10;
        int result = instance.getData();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getLeftSubtree method, of class BinaryTree.
     */
    @Test
    public void testGetLeftSubtree() {
        System.out.println("getLeftSubtree");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        BinaryTree<Integer> left = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        left.root=new BinaryTree.Node<Integer>(20);     
        instance.root.left=left.root;

        BinaryTree<Integer> expResult = left;
        BinaryTree<Integer> result = instance.getLeftSubtree();
        assertEquals(expResult.root, result.root);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of getRightSubtree method, of class BinaryTree.
     */
    @Test
    public void testGetRightSubtree() {
        System.out.println("getRightSubtree");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        BinaryTree<Integer> right = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        right.root=new BinaryTree.Node<Integer>(20);     
        instance.root.right=right.root;

        BinaryTree<Integer> expResult = right;
        BinaryTree<Integer> result = instance.getRightSubtree();
        assertEquals(expResult.root, result.root);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of setLeftSubtree method, of class BinaryTree.
     */
    @Test
    public void testSetLeftSubtree() {
        System.out.println("setLeftSubtree");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        BinaryTree<Integer> left = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        left.root=new BinaryTree.Node<Integer>(20); 
        boolean expResult = true;
        boolean result = instance.setLeftSubtree(left);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of setRightSubtree method, of class BinaryTree.
     */
    @Test
    public void testSetRightSubtree() {
        System.out.println("setRightSubtree");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        BinaryTree<Integer> right = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        right.root=new BinaryTree.Node<Integer>(20);  
        boolean expResult = true;
        boolean result = instance.setRightSubtree(right);
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of isLeaf method, of class BinaryTree.
     */
    @Test
    public void testIsLeaf() {
        System.out.println("isLeaf");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        boolean expResult = true;
        boolean result = instance.isLeaf();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of readBinaryTree method, of class BinaryTree.
     */
    @Test
    public void testReadBinaryTree() throws Exception {
        /*
        System.out.println("readBinaryTree");
        BufferedReader bR =new BufferedReader(null);
        
        //bR.read("10\n  null\n  null\n");
        BinaryTree<Integer> expResult = null;
        BinaryTree<Integer> result = BinaryTree.readBinaryTree(bR);
        assertEquals(expResult, result);
        */
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }

    /**
     * Test of ToString method, of class BinaryTree.
     */
    @Test
    public void testToString() {
        System.out.println("ToString");
        BinaryTree<Integer> instance = new BinaryTree<Integer>();
        instance.root=new BinaryTree.Node<Integer>(10);
        String expResult = "10\n  null\n  null\n";
        String result = instance.ToString();
        assertEquals(expResult, result);
        // TODO review the generated test code and remove the default call to fail.
        //fail("The test case is a prototype.");
    }
    
}
