
import java.util.*;
import java.lang.*;
import java.io.*;

public class Program{  
    static ArrayList<Process> processes= new ArrayList<>();        
    static LinkedList<Process> p1 = new LinkedList<>();
    static LinkedList<Process> p2 = new LinkedList<>();
    static LinkedList<Process> p3 = new LinkedList<>();
    static LinkedList<Process> p4 = new LinkedList<>();
    static LinkedList<Process> p5 = new LinkedList<>();
    static LinkedList<Process> p6 = new LinkedList<>();  
    
    static ArrayList<String> processname = new ArrayList<>(); //store the process name for gantt chart
    static ArrayList<Integer> timing = new ArrayList<>(); //store the serving time for gantt chart
    static int currenttime = 0;
    static int quantum = 0;
    boolean spacing = true;
    
    public static void main(String[] args){           
       new Program().Start();
    }    
    public void Start(){
       Scanner input = new Scanner(System.in);                
       System.out.print("Enter the number of processes: ");
       int num = input.nextInt();         
       for(int x=0;x<num;x++){
           Process p = new Process();
            System.out.format("Process %d%n",x);
            System.out.print("Arrival time: ");          
            int arrival = input.nextInt();
            System.out.print("Burst time: ");
            int burst = input.nextInt();
            System.out.print("Priority: ");
            int prio = input.nextInt();
             
            p.setprocessname("P"+x);
            p.setTime(arrival,burst,prio);  
            processes.add(p);
            System.out.println("------------------------------\n");
       }
       System.out.print("Set quantum: ");
       quantum = input.nextInt();
       System.out.println("------------------------------\n");       
       Collections.sort(processes, new Comparator<Process>(){
           public int compare(Process a, Process b){
               return a.arrivaltime - b.arrivaltime;
            }    
       });
       timing.add(currenttime);
       processfilter();
    }
    public void processfilter(){       
        //System.out.print("| ");      
        while(processes.size()>0 && currenttime>=processes.get(0).getarrivalTime()){
            if (processes.get(0).getPriority()==1){
                p1.addLast(processes.get(0));
            }
            else if(processes.get(0).getPriority()==2){
                p2.addLast(processes.get(0));    
            }
            else if(processes.get(0).getPriority()==3){
                p3.addLast(processes.get(0));    
            }
            else if(processes.get(0).getPriority()==4){
                p4.addLast(processes.get(0));    
            }
            else if(processes.get(0).getPriority()==5){
                p5.addLast(processes.get(0));   
            }
            else if(processes.get(0).getPriority()==6){
                p6.addLast(processes.get(0));   
            }
            Process removed = processes.remove(0);          
        }     
        processcompletion();
    }
    public void processcompletion(){   
        if(!p1.isEmpty()){
            roundrobin(p1.get(0),p1);                
        }
        else if(!p2.isEmpty()){
            roundrobin(p2.get(0),p2);              
        }
        else if(!p3.isEmpty()){
            roundrobin(p3.get(0),p3);        
        }
        else if(!p4.isEmpty()){
            roundrobin(p4.get(0),p4);        
        }
        else if(!p5.isEmpty()){
            roundrobin(p5.get(0),p5);
        }
        else if(!p6.isEmpty()){
            roundrobin(p6.get(0),p6);        
        }
        else if(!processes.isEmpty()){                
            System.out.print("   |");
            ++currenttime; 
        }
        else{
            displayresults();
            System.exit(0);
        }
        processfilter();         
    }
    public void roundrobin(Process process,LinkedList<Process> list){ 
        while(process.getCounter()!=quantum){
            System.out.print(process.getprocessName());
            process.setburstTime();
            process.setCounter();
            System.out.print(" | ");
            ++currenttime;
            timing.add(currenttime);
        }      

        if(processes.size()>0){
            if(currenttime>=processes.get(0).getarrivalTime()){
                processfilter();
            }    
        }
        //processname.add(process.getprocessName());
        //timing.add(currenttime);
        if(process.getburstTime()==0){
                list.remove(process);
            }
        else {
            if(process.getCounter()==quantum){                    
                Process toTheLast = list.remove(0);
                list.add(toTheLast);
                process.resetCounter();
            }
        } 
    }
    public void displayresults(){
        
        for(int x=0;x<processname.size();x++){
            if(x<4){
                System.out.print("| "+processname.get(x)+" ");
            }
            else{
                System.out.print(" | "+processname.get(x)+" ");
            }
        }
        System.out.println("");
        if(spacing == true){
            System.out.print(timing.get(0)+"  ");
            spacing = false;
        }
        for(int x=1;x<timing.size();x++){
            if(x<10){
                System.out.print(timing.get(x)+"    ");
            }
            else{
                 System.out.print(timing.get(x)+"   ");
            }
        }
    }
}




    
    

