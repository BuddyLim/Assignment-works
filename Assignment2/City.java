import java.util.*;
import java.io.*;

public class City 
{
    private int id;
    private String name;
    private ArrayList<Attraction> culture = new ArrayList<>(); //2
    private ArrayList<Attraction> shop = new ArrayList<>(); //1
    private ArrayList<Attraction> sport = new ArrayList<>(); //3
    private ArrayList<Attraction> allAttraction = new ArrayList<>();
    private ArrayList<City> Flight = new ArrayList<>(); //adding flights
    
    public City(String name,int id){
        this.name = name;
        this.id = id;
    } 
    public int getID(){
        return this.id;
    }
    public String getCityname(){
        return this.name;
    }    
    public Attraction addAttraction(Attraction attractions){
        //checks the typeID and adds it for processdisplayTypeAttraction() method in TouristDisplay
        if(attractions.gettypeID()==1){
            shop.add(attractions);
        }
        else if(attractions.gettypeID()==2){
            culture.add(attractions);
        }
        else if(attractions.gettypeID()==3){
            sport.add(attractions);
        }
        return attractions;
    }
    public ArrayList<Attraction> getshop(){
        return this.shop;
    }    
    public ArrayList<Attraction> getculture(){    
        return this.culture;
    }    
    public ArrayList<Attraction> getsport(){    
        return this.sport;
    }    
    public ArrayList<Attraction> getAttractions()
    {        
        allAttraction = new ArrayList<>();//full list of attractions from a city
        allAttraction.addAll(this.shop);
        allAttraction.addAll(this.culture);
        allAttraction.addAll(this.sport);
        return allAttraction;
    }
    public ArrayList<Attraction> removeAttraction(int index)
    {    
        Attraction tmpAttraction = allAttraction.get(index);
        this.shop.remove(tmpAttraction);
        this.culture.remove(tmpAttraction);
        this.sport.remove(tmpAttraction);
        allAttraction.remove(tmpAttraction);
        return allAttraction;
    }
    public void addFlight(City city)
    {
        Flight.add(city);
    }
    public void removeFlight(City city)
    {
        Flight.remove(city);
    }
    public ArrayList<City> getFlight()
    {
        return this.Flight;
    }  
}