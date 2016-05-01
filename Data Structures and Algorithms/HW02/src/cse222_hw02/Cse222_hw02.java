/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package cse222_hw02;

import java.util.ListIterator;

/**
 *
 * @author Okan
 */
public class Cse222_hw02 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        /*
        GITArrayList<Integer> list =new GITArrayList<Integer>();
         GITArrayList<Integer> list2 =new GITArrayList<Integer>();
        */
        GITLinkedList<Integer> list =new GITLinkedList<Integer>();
         GITLinkedList<Integer> list2 =new GITLinkedList<Integer>();
        GITLinkedList<Integer> list3 =new GITLinkedList<Integer>();
         ListIterator i=list.listIterator();
        list.add(0,10);
        list.add(0,20);
        list.add(1,30);
        
        list2.add(0,10);
        list2.add(0,20);
        list2.add(1,30);
        
        list3.add(0,10);
        
        list.addAll(list2);
        //list2.add(0,40);
        i=list.listIterator();
        /*
        while(i.hasNext())
         System.out.printf("%d\n",i.next());
        */
      
        list.removeAll(list2);
         
        i=list.listIterator();
        while(i.hasNext())
         System.out.printf("%d\n",i.next());
             
               
    }
    
}
