/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw4;

import java.util.EmptyStackException;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * Translates an infix expression to a postfix expression
 * @author Okan
 */
public class InfixToPostFix {
    /** Insert nested class SyntaxErrorException here*/
    
    //Data Fields
    /**The operator stack*/
    private Stack<String>operatorStack;
    /** The Opertors*/
    //private static final String OPERATORS="+-*/()";
    private static final String[] OPERATORS=
        {"=","input","print","var","plus","minus","sin","cos","tan","sqrt","log","abs","exp","+","-","*","/","(",")"};
    /** The precedence of the operators,matches order in OPERATORS*/
    private static final int[] PRECEDENCE={1,3,3,3,3,3,3,3,3,3,3,3,3,2,2,2,2,-1,-1};
    /**Post fix string*/
    private StringBuilder postfix;
    
    /**
     * Convert a string from infox to post fix
     * @param infix The infıx expression
     * @return postfix expression
     * @throws SyntaxErrorException 
     */
    public String convert(String infix)throws SyntaxErrorException{
        operatorStack=new Stack<String>();
        postfix=new StringBuilder();
        StringTokenizer infixTokens=new StringTokenizer(infix);
        try{
            //Process each token in the infix string
            while(infixTokens.hasMoreTokens()){
                String nextToken=infixTokens.nextToken();
                char firstChar=nextToken.charAt(0);
                //Is it an operand?
                if(isOperator(nextToken)){
                   // System.out.printf("-op: %s-\n", nextToken);
                    processOperator(nextToken);
                }
                else if(Character.isJavaIdentifierStart(firstChar)
                        ||Character.isDigit(firstChar)){
                    
                    postfix.append(nextToken);
                    postfix.append(' ');
                                      
                }// Is it an operator
                
                else{
                    throw new SyntaxErrorException
                            ("Unexpected Character Encountered: "+ firstChar);
                    
                }
                                 
                //System.out.printf("%s\n",postfix.toString());    
            }//End While
            //Pop any remaining operators and
            //append them to postfix
            
            while(!operatorStack.empty()){
                String op=operatorStack.pop();
                //Any '(' on the stack is not matched
                if(op.equals(")"))
                    throw new SyntaxErrorException("Unmatched openning parenthesis");
                postfix.append(op);
                postfix.append(' ');
            }
            //assert: Stact is empty, return result
            
            return postfix.toString();
        }
        catch(EmptyStackException ex){
            throw new SyntaxErrorException
                ("Syntax Error: The stack is empty.");
        }
        
            
    }
    /** Method to process operators
     * 
     * @param op The operator
     * @throws EmptyStackException
     */
    private void processOperator(String op){
        if(operatorStack.empty() || op.equals("(")){
            operatorStack.push(op);
        }
        else{
            //peek opertor stack and
            //let topOp be top operator
            String topOp=operatorStack.peek();
            
            if(precedence(op)>precedence(topOp))
                operatorStack.push(op);
            else{
                // Pop all stacked operators with equal
                // or higher precedence than op
                while(!operatorStack.empty() 
                        && precedence(op) <=precedence(topOp)){
                    operatorStack.pop();
                    if(topOp.equals("(")){
                        //Matching '(' pooped -exit loop
                        break;
                    }
                    postfix.append(topOp);
                    postfix.append(' ');
                    if(!operatorStack.empty()){
                        //Reset topOp
                        topOp=operatorStack.peek();
                    }
                }//End while
                //assert: operator stack is empty or 
                //       current operator precedence >
                //       top of stack operator precedence
                if(!op.equals(")"))
                    operatorStack.push(op);
            }
        }
    
    }
    /**
     *  Determine whether a string is an operator
     * @param ch the string to be tested
     * @return true if ch is an operator
     */
    private boolean isOperator(String ch){
        int i;
        for (i=0;i<OPERATORS.length;++i)
            if(OPERATORS[i].equals(ch))
                return true;    
        return false;
    }
    /**
     * gives precedence degree of operator
     * @param op operator
     * @return precedence of operator
     */
    private int precedence(String op){
        int i;
        for(i=0;i<OPERATORS.length;++i){
            if(OPERATORS[i].equals(op))
                return PRECEDENCE[i];
        }
        return -1;
    }
    
    public class SyntaxErrorException extends Throwable{
        String error;
        SyntaxErrorException(String errmsg){
            error=errmsg;
        }
        public String getmsg(){
            return error;
        } 
    }
    
}
