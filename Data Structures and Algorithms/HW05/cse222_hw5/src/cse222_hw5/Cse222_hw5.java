/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw5;
import cse222_hw5.InfixToPostFix;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;
import java.util.Scanner;
import java.util.Stack;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Okan Akdogan
 */
public class Cse222_hw5 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String infix;
        String postfix;
        Stack<Integer> listNumStack= new Stack<Integer>();
        LinkedList<LinkedList<Variable>> varList=new LinkedList<LinkedList<Variable>>();
        LinkedList<Variable> vars=new LinkedList<Variable>();
        List<String> Lines;
        double result = 0;
        String path;
        
        Scanner KeyboardInp=new Scanner(System.in);
        InfixToPostFix converter =new InfixToPostFix();
        PostfixEvaluator ev = new PostfixEvaluator();
       
        varList.add(vars);
        listNumStack.push(0);
        
        System.out.println("Enter a file path");
        path=KeyboardInp.next();
        //path="C:\\file.git";
        Path filePath= Paths.get(path);
        
        try{
            Lines=Files.readAllLines(filePath, Charset.defaultCharset());
            
            for(int i=0;i<Lines.size();++i){
                postfix=converter.convert( Lines.get(i).trim()).trim();
                //System.out.println(postfix);
                /**/
                result=ev.eval(postfix, varList,listNumStack);
                //System.out.println(postfix);
                if(postfix.trim().endsWith("loop")){
                  //  System.out.println(postfix);
                    postfix=postfix.substring(0, postfix.length()-5).trim();
                    Variable loopVar=getVar(postfix,varList);                 
                    varList.add(new LinkedList<Variable>());
                    listNumStack.push(listNumStack.peek()+1);                
                    varList.peekLast().add(loopVar);
                }
                if(postfix.equals("begin")){
                    //System.out.println("begin");
                    varList.get(listNumStack.peek()).add(new Variable("line",i));
                }
                if(postfix.equals("end")){
                    
                    Variable loopVar=varList.get(listNumStack.peek()).get(0);
                    
                    if(loopVar.getValue()==0){                       
                        listNumStack.pop(); 
                        varList.removeLast();                      
                    }
                    else if(loopVar.getValue()>0){
                        i=(int)getVar("line", varList).getValue();
                        while(varList.peekLast().size()>2)
                            varList.peekLast().removeLast();
                    }
                    
                }               
            }
                   
            
        } catch (IOException ex) {
            Logger.getLogger(Cse222_hw5.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InfixToPostFix.SyntaxErrorException ex) {
            //System.out.print(ex.getMessage());
            System.out.print(ex.error);
        } catch (PostfixEvaluator.SyntaxErrorException ex) {
            Logger.getLogger(Cse222_hw5.class.getName()).log(Level.SEVERE, null, ex);
            result=0.0;
        }

        
    }

    
    private static Variable getVar(String varName,LinkedList<LinkedList<Variable>> Variables){
      ListIterator itrOut = Variables.listIterator();
      ListIterator itrInner=null;
      Variable var=null;
      Variable result=null;
      while(itrOut.hasNext()){
          itrInner=((LinkedList<Variable>)itrOut.next()).listIterator();
        while(itrInner.hasNext()){
            if((var=(Variable)itrInner.next()).getName().equals(varName))
                 result=var;
        }
      }
      return result;
  }
    
}
