package hw06_121044017;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Serializable;

/**
 * @author Okan
 * @version 1.0
 * @created 03-May-2014 13:10:24
 */
public class BinaryTree<E> implements Serializable{

	protected Node<E> root;

        protected static class Node<E>{
            protected E data;
            protected Node<E> left;
            protected Node<E> right;
            /**
             * Constructor
             * @param data
             */
            public Node(E data){
                this.data=data;
                this.left=null;
                this.right=null;
            }
            // Methods
            /** Return a string representation of the node.
                @return A string representation of the data fields
             */
            @Override
            public String toString() {
              return data.toString();
            }
        }
        /**
         * Constructor
         */
        public BinaryTree(){
            root=null;
	}

	/**
	 * Constructor
	 * @param root
	 */
	protected BinaryTree(Node<E> root){
            this.root=root;
	}

	/**
	 * Constructor
	 * @param data
	 * @param leftTree
	 * @param rightTree
	 */
	public BinaryTree(E data, BinaryTree<E> leftTree, BinaryTree<E> rightTree){
            root = new Node<E>(data);
            if (leftTree != null) {
              root.left = leftTree.root;
            }
            else {
              root.left = null;
            }
            if (rightTree != null) {
              root.right = rightTree.root;
            }
            else {
              root.right = null;
            }
	}
        /**
         * gets data in root
         * @return the data
         */
	public E getData(){
		return root.data;
	}
        /** Return the left subtree.
          @return The left subtree or null if either the root or
          the left subtree is null
        */   
	public BinaryTree getLeftSubtree(){
            if (root != null && root.left != null) {
                return new BinaryTree<E>(root.left);
            }
            else {
                return null;
            }
	}
         
        /** Return the right sub-tree
            @return the right sub-tree or
            null if either the root or the
            right subtree is null.
        */  
	public BinaryTree getRightSubtree(){
            if (root != null && root.right != null) {
                return new BinaryTree<E>(root.right);
            } else {
                return null;
            }
	}
        public boolean setLeftSubtree(BinaryTree<E> tree){
            if (root != null ) {
                if(tree!=null)
                    root.left=tree.root;
                else
                    root.left=null;
                return true;
            } else {
                return false;
            }
	}
        public boolean setRightSubtree(BinaryTree<E> tree){
            if (root != null ) {
                if(tree!=null)
                    root.right=tree.root;
                else
                    root.right=null;
                return true;
            } else {
                return false;
            }
	}
        
	public boolean isLeaf(){
            
            return (root.left==null && root.right==null);          
	}

	 /** Perform a preorder traversal.
            @param node The local root
            @param depth The depth
            @param sb The string buffer to save the output
         */
	private void preOrderTraverse(Node<E> node, int depth, StringBuilder sb){
              for (int i = 1; i < depth; i++) {
                sb.append("  ");
              }
              if (node == null) {
                sb.append("null\n");
              }
              else {
                sb.append(node.toString());
                sb.append("\n");
                preOrderTraverse(node.left, depth + 1, sb);
                preOrderTraverse(node.right, depth + 1, sb);
              }
	}

	/** Method to read a binary tree.
            pre: The input consists of a preorder traversal
                 of the binary tree. The line "null" indicates a null tree.
            @param bR The input file
            @return The binary tree
            @throws IOException If there is an input error
         */
	public static BinaryTree readBinaryTree(BufferedReader bR) throws IOException{
            // Read a line and trim leading and trailing spaces.
            String data = bR.readLine().trim();
            if (data.equals("null")) {
              return null;
            }
            else {
              BinaryTree < String > leftTree = readBinaryTree(bR);
              BinaryTree < String > rightTree = readBinaryTree(bR);
              return new BinaryTree <String>(data, leftTree, rightTree);
            }
	}

	public String ToString(){
            StringBuilder sb = new StringBuilder();
            preOrderTraverse(root, 1, sb);
            return sb.toString();
	}

}