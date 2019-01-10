
/**
 * Write a description of class test here.
 *
 * @author (your name)
 * @version (a version number or a date)
 */
public class test{
    
    static boolean PalinChecker(int start,int stop,String word){
        if(word.toLowerCase().charAt(start)!=word.toLowerCase().charAt(stop)){
            return false;
        }
        else if(word.toLowerCase().charAt(start)==word.toLowerCase().charAt(stop)){
            if(start<stop+1){
                return PalinChecker(start+1,stop-1,word);
            }
        }
        return true;
    }
    public static void main(String[] args){
        
        //Question 1
        for(int x=1;x<=100;x++){      
            if(x%3==0 || x%5==0){
                System.out.print(x+" ");  
            }
        }
        System.out.println("\n");
///////////////////////////////////////////////////////////////////////////////////     
  
      //Question 2        
        int temp;  
        int[] arr1 = {100,2,5,13,29,68,87,4,17,45,54}; 
        System.out.print("Before sort: "); 
        for(int x=0;x<arr1.length;x++){
            System.out.print(arr1[x]+" ");
        }
        System.out.println();
        for(int x=0;x<arr1.length;x++){
            for(int y=1;y<arr1.length-x;y++){
                if(arr1[y-1]>arr1[y]){
                   temp = arr1[y-1];      //Based on the bubblesort algorithm
                   arr1[y-1] = arr1[y];
                   arr1[y] = temp;
                }
            }
        }
        System.out.print("After sort: ");
        for(int x=0;x<arr1.length;x++){
            System.out.print(arr1[x]+" ");
        } 
        System.out.println("\n");
        
        
///////////////////////////////////////////////////////////////////////////////////
        //Question 3
        String word = "Hannah";
        if(PalinChecker(0,word.length()-1,word)==true){
            System.out.print("Yes, " + word + " is a palindrome");
        }
        else{
            System.out.print("No, " + word + " isn't  a palindrome");
        }
        
    }
}
