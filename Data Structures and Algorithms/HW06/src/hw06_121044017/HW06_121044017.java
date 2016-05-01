/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package hw06_121044017;

import java.util.Comparator;

/**
 *
 * @author Okan
 */
public class HW06_121044017 {

    /**
     * @param args the command line arguments
     */
        
    public static void main(String[] args) {
        // TODO code application logic here
        
        driver3();
        
    }
    private static void driver1(){
        GITPriorityQueue<Integer> pq=new GITPriorityQueue<Integer>();
        int data;
        pq.offer(10);
        pq.offer(7);
        pq.offer(11);
        pq.offer(12);
        pq.offer(20);
        pq.offer(30);
        pq.offer(40);
        pq.offer(50);
        System.out.println("Current Tree Status");
        System.out.print(pq.ToString());
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
    }
     private static void driver2(){
        GITPriorityQueue<String> pq=new GITPriorityQueue<String>();
        String data;
        pq.offer("Ali");
        pq.offer("size");
        pq.offer("okan");
        pq.offer("kitap");
        pq.offer("ses");
        pq.offer("klavye");
        pq.offer("not");
        pq.offer("ekran");
        System.out.println("Current Tree Status");
        System.out.print(pq.ToString());
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
    }
     private static void driver3(){
        GITPriorityQueue<Integer> pq=new GITPriorityQueue<Integer>(new comparatorInt());
        int data;
        pq.offer(10);
        pq.offer(7);
        pq.offer(11);
        pq.offer(12);
        pq.offer(20);
        pq.offer(30);
        pq.offer(40);
        pq.offer(50);
        System.out.println("Current Tree Status");
        System.out.print(pq.ToString());
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
        data=pq.poll();
        System.out.print(pq.ToString());
        System.out.println("polled data= "+data);
    }
     private static class comparatorInt implements Comparator<Integer>{
        
        @Override
        public int compare(Integer o1, Integer o2) {
            if(o1==o2)
                return 0;
            else if(o1>o2)
                return -1;
            else 
                return 1;        
        }
     }
}
