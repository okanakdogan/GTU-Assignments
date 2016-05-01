package cse222_hw5;

import java.util.*;

/** Class that can evaluate a postfix expression.
*   @author Koffman & Wolfgang
* */

public class PostfixEvaluator {

  // Nested Class
  /** Class to report a syntax error. */
  public static class SyntaxErrorException
      extends Exception {
    /** Construct a SyntaxErrorException with the specified
        message.
        @param message The message
     */
    SyntaxErrorException(String message) {
      super(message);
    }
  }

  // Constant
  /** A list of operators. */
  private static final String[] OPERATORS=
        {"=","loop","begin","end","input","print","var","plus","minus","sin","cos","tan","sqrt","log","abs","exp","+","-","*","/"};
  private static final int[] OPERATORTYPE={2,1,0,0,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2};  
  // Data Field
  /** The operand stack. */
  private Stack < String > operandStack;
  
  /** Variables*/
  //private LinkedList<Variable> Variables;
  private LinkedList<LinkedList<Variable>>VarList;
  private Stack<Integer> stackInt;
  
  // Methods
  /** Evaluates the current operation.
      This function pops the two operands off the operand
      stack and applies the operator.
      @param op A character representing the operator
      @return The result of applying the operator
      @throws EmptyStackException if pop is attempted on
              an empty stack
   */
  private double evalOp(String op) throws SyntaxErrorException {
    double result = 0;
    // Evaluate the operator.
    int type=operatorType(op);
    double rhs; 
    double lhs;
    
    if(type==1){
        String value=operandStack.pop();
        if(op.equals("loop")||op.equals("begin")||op.equals("end"))
            return 0.0;
        if(op.equals("var")){
            addVariable(new Variable(value,0.0));  
            return 0.0;
        }
        else if(op.equals("input")){
            if(isContainVar(new Variable(value,0.0))==true){
               /*input message*/
               System.out.printf("input for %s=",value);
               
               Scanner inp=new Scanner(System.in);
               result=inp.nextDouble();
               getVar(value).setValue(result);  
               return result;
            }
        }
        if(isContainVar(new Variable(value,0.0))==false)
            rhs = Double.parseDouble(value);
        else       
            rhs = getVar(value).getValue();
            
            
        
        switch(op){
            case "plus":
                result=+rhs;
                break;
            case "minus":
                result=-rhs;
                break;
            case "sin":
                result=Math.sin(rhs*Math.PI/180);
                break;
            case "cos":
                result=Math.cos(rhs*Math.PI/180);
                break;
            case "tan":
                result=Math.tan(rhs*Math.PI/180);
                break;
            case "sqrt":
                result=Math.sqrt(rhs);
                break;
            case "log":
                result=Math.log(rhs);
                break;
            case "abs":
                result=Math.abs(rhs);
                break;
            case "exp":
                result=Math.exp(rhs);
                break;
            case "print":
                System.out.println(rhs);
                result=0.0;
                break;                   
        }
        
    }else if(type==2){
        // Pop the two operands off the stack.
        String value=operandStack.pop();
        if(isContainVar(new Variable(value,0.0))==false)
            rhs = Double.parseDouble(value);
        else       
            rhs = getVar(value).getValue();
            
        value=operandStack.pop();
        if(isContainVar(new Variable(value,0.0))==false)           
            lhs = Double.parseDouble(value);
        else           
            lhs = getVar(value).getValue();
        
        switch (op) {   
            case "+":
              result = lhs + rhs;
              break;
            case "-":
              result = lhs - rhs;
              break;
            case "/":
              result = lhs / rhs;
              break;
            case "*":
              result = lhs * rhs;
              break;
            case "=":
               if(isContainVar(new Variable(value,0.0))){
                   getVar(value).setValue(rhs);
                   result=rhs;
               }else{
                   throw new SyntaxErrorException("No Lvalue");
               }
                   
         }
        
    }else{
        Scanner inp=new Scanner(System.in);       
        if(op.equals("input")){
            result=inp.nextDouble();
        }
    }
   
    return result;
  }

  
  /** Determines whether a character is an operator.
      @param op The character to be tested
      @return true if the character is an operator
   */
  private boolean isOperator(String op) {
    int i;
        for (i=0;i<OPERATORS.length;++i)
            if(OPERATORS[i].equals(op))
                return true;    
        return false;
  }
  private int operatorType(String op){
      int i;
        for(i=0;i<OPERATORS.length;++i){
            if(OPERATORS[i].equals(op))
                return OPERATORTYPE[i];
        }
        return -1;
  }

  /** Evaluates a postfix expression.
      @param expression The expression to be evaluated
      @return The value of the expression
      @throws SyntaxErrorException if a syntax error is detected
   */
  public double eval(String expression,LinkedList<LinkedList<Variable>> vars,Stack<Integer> stackInt) throws SyntaxErrorException {
    // Create an empty stack.
    operandStack = new Stack < String > ();
    VarList= vars;
    this.stackInt=stackInt;
    // Process each token.
    StringTokenizer tokens = new StringTokenizer(expression);
    try {
      while (tokens.hasMoreTokens()) {
        String nextToken = tokens.nextToken();
        // Is it an operator?
        if (isOperator(nextToken)) {
          // Evaluate the operator.
            double result = evalOp(nextToken);
          // Push result onto the operand stack.
          operandStack.push(String.valueOf(result));
        }
        
        // Does it start with a digit?
        else if (Character.isJavaIdentifierStart(nextToken.charAt(0))|| 
                Character.isDigit(nextToken.charAt(0))) {
          // Get the integer value.
          //double value = Integer.parseInt(nextToken);
          // Push value onto operand stack.
          operandStack.push(nextToken);
        } 
        
        else {
          // Invalid character.
          throw new SyntaxErrorException(
              "Invalid character encountered");
        }
      } // End while.

      // No more tokens - pop result from operand stack.
      String answer = operandStack.pop();
      // Operand stack should be empty.
      if (operandStack.empty()) {
        return Double.parseDouble(answer);
      }
      else {
        // Indicate syntax error.
        throw new SyntaxErrorException(
            "Syntax Error: Stack should be empty");
      }
    }
    catch (EmptyStackException ex) {
      // Pop was attempted on an empty stack.
      throw new SyntaxErrorException(
          "Syntax Error: The stack is empty");
    }
  }
  /**
   * adds given variable object to list if not exist
   * @param var variable to add
   */
  private void addVariable(Variable var) throws SyntaxErrorException{
      //if (isContainVar(var)==false)
      boolean isContain=false;
      ListIterator itr = VarList.get(stackInt.peek()).listIterator();
      while(itr.hasNext())
          if (((Variable)itr.next()).getName().equals(var.getName()))
              isContain=true;
      if(!isContain)
        VarList.get(stackInt.peek()).add(var);
      else
          throw new SyntaxErrorException("variable exist");
  }
  /**
   * control to variable if exist in list
   * @param var variable to check
   * @return true if var exist in list o/w false
   */
  private boolean isContainVar(Variable var){
      //ListIterator itr = Variables.listIterator();
      ListIterator itrOut=VarList.listIterator();
      ListIterator itrInner ;
      while(itrOut.hasNext()){
          itrInner= ((LinkedList<Variable>)itrOut.next()).listIterator();
        while(itrInner.hasNext()){
            if(((Variable)itrInner.next()).getName().equals(var.getName()))
            return true;
        }
      }
      return false;
  }
  /**
   * gets variable object from list
   * @param varName name of variable
   * @return Variable if exist o/w null
   */
  private Variable getVar(String varName){
      ListIterator itrOut = VarList.listIterator();
      ListIterator itrInner;
      Variable var=null;
      Variable result=null;
      while(itrOut.hasNext()){
          itrInner= ((LinkedList<Variable>)itrOut.next()).listIterator();
        while(itrInner.hasNext()){
            if((var=(Variable)itrInner.next()).getName().equals(varName))
                result=var;
        }
      }
      return result;
  }
  
}
