/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw4;

/**
 * Variable class to use with List
 * @author Okan
 */
public class Variable{
    
       private String varName;
       private double value;
       
       Variable(){ 
           varName="";
           value=0.0;
       }
       Variable(String name,double val){ 
           varName=name;
           value=val;
       }
       public String getName(){ return varName;}
       public double getValue(){ return value;}
       public void setName(String name){ varName=name; }
       public void setValue(double val){ value=val;}
    }
