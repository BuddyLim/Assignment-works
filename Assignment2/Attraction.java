import java.util.*;

public abstract class Attraction
{
    private int id;
    private String name;
    private int typeID;
  
    abstract void display();
    public Attraction(int id,String name,int typeID){
        this.id=id; //city id
        this.name=name; //city name
        this.typeID=typeID; //city typeID
    }    
    public int gettypeID(){
        return this.typeID;
    }
    public String getName(){
        return this.name;
    }
    public int getID(){
        return this.id;
    }  
}
class Culture extends Attraction
{
    private double entranceFee;
    
    public Culture(int id,String name,int typeID){
        super(id,name,typeID);
    }
    public void display(){
        System.out.println("");
        System.out.println(this.getName() + " Infomation: ");
        System.out.println("Entrance fee is: RM " + entranceFee);
    }
    public void setEntranceFee(double entranceFee){
        this.entranceFee = entranceFee;        
    }
}
class Sport extends Attraction
{
    private int ageLimit;
    
    public Sport(int id,String name,int typeID){
        super(id,name,typeID);
    }
    public void display(){
        System.out.println("");
        System.out.println(this.getName() + " Infomation: ");
        System.out.println("Age limit is: " + this.ageLimit);
    }
    public void setAgeLimit(int ageLimit){
        this.ageLimit = ageLimit;
    }
}
class Shopping extends Attraction
{
    private ArrayList<String> Shops = new ArrayList<>();
       
    public Shopping(int id,String name,int typeID){
        super(id,name,typeID);    
    }
    public void setShop(ArrayList<String> Shops){
        this.Shops = Shops;
    }
    public void display(){
        System.out.println("");
        System.out.println(this.getName() + " Infomation: ");        
        System.out.println("Shops available: ");
        for(int l=0; l<Shops.size();l++)
        {
            System.out.println((l+1)+") "+Shops.get(l));
        }
    }
}