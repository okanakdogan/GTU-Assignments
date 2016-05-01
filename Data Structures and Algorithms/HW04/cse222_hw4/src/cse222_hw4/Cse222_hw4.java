/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw4;

import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Okan Akdogan
 */
public class Cse222_hw4 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        String infix;
        String postfix;
        LinkedList<Variable> vars=new LinkedList<Variable>();
        List<String> Lines;
        double result = 0;
        String path;
        
        Scanner KeyboardInp=new Scanner(System.in);
        InfixToPostFix converter =new InfixToPostFix();
        PostfixEvaluator ev = new PostfixEvaluator();
        
       
        System.out.println("Enter a file path");
        path=KeyboardInp.next();
        Path filePath= Paths.get(path);
        
        try{
            Lines=Files.readAllLines(filePath, Charset.defaultCharset());
            for(int i=0;i<Lines.size();++i){
                postfix=converter.convert( Lines.get(i));
                //System.out.println(postfix);
                result=ev.eval(postfix, vars);
            }
            
        } catch (IOException ex) {
            Logger.getLogger(Cse222_hw4.class.getName()).log(Level.SEVERE, null, ex);
        } catch (InfixToPostFix.SyntaxErrorException ex) {
            //System.out.print(ex.getMessage());
            System.out.print(ex.error);
        } catch (PostfixEvaluator.SyntaxErrorException ex) {
            Logger.getLogger(Cse222_hw4.class.getName()).log(Level.SEVERE, null, ex);
            result=0.0;
        }
        try {
            //InfixToPostfixParens converter =new InfixToPostfixParens();
            
            System.out.println(converter.convert("sin x + cos 50 + tan x * log 10 / exp 10 - abs 20 + minus 10 - sqrt 4"));
        } catch (InfixToPostFix.SyntaxErrorException ex) {
            Logger.getLogger(Cse222_hw4.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.printf("\n a=%f\n",vars.get(0).getValue());
        
    }
    
}
