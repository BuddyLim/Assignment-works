import java.util.*;
import java.lang.*;
import java.io.*;
/**
 * Write a description of class RR here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class Process implements Comparator<Process>
{  
       String processname;
       int arrivaltime;
       int bursttime;
       int priority;  
       int counter = 0;
       
       public void setprocessname(String processname){
           this.processname = processname;
        }
       public void setTime(int arrivaltime, int bursttime,int priority){
       this.arrivaltime = arrivaltime;
       this.bursttime = bursttime;
       this.priority = priority; 
       }
       public void getTime(){
           System.out.println(processname);
           System.out.println("Arrival time: " + arrivaltime +"\n" + "Burst time: " + bursttime + "\n" + "Priority: " + priority);
       }
       public String getprocessName(){
           return this.processname;
       }
       public int getarrivalTime(){
           return this.arrivaltime;
       }
       public int getPriority(){
           return this.priority;
       }
       public int getburstTime(){
           return this.bursttime;
       }      
       public void setburstTime(){
            --this.bursttime;
       }
       public void setCounter(){
           ++this.counter;
       }
        public int getCounter(){
            return this.counter;
        }
        public void resetCounter(){
            this.counter = 0;
        }
       public int compare(Process a, Process b){
           return a.arrivaltime - b.arrivaltime;
       }

}


