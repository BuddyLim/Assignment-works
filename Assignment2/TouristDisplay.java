import java.util.*;
import java.io.*;

//to do: removing flights detail after removing cities
public class TouristDisplay implements Serializable
{
    private static ArrayList<City> cities = new ArrayList<>();
    public static void main(String[] a) 
    {   
        addCities(); //adding data into cities arraylist and attractions arraylist
        for(int i=0;i<cities.size();i++){
            cities.get(i).getAttractions();
        }
        boolean SystemAdminLoop = true;         
        while(SystemAdminLoop){
           printSystemAdmin();
           SystemAdminLoop = processSystemAdmin();
        }
    }
    private static void printline(){
        System.out.println("");
    }
    private static void dashLine(){
        System.out.println("-----------------------------------------------------------------------");
    }
    private static void addCities()
    {
        ArrayList<String> Shops = new ArrayList<>();
        
        City GeorgeTown = new City("GeorgeTown",1);        
        Shopping Komtar = new Shopping(1,"Komtar",1);
        Shops = new ArrayList<>();
        Shops.addAll(Arrays.asList("Popular","KFC","Science Park")); 
        Komtar.setShop(Shops);
        Shopping Gurney = new Shopping(1,"Gurney Paragon",1);
        Shops = new ArrayList<>();
        Shops.addAll(Arrays.asList("MorganField","H&M","Baskin Robins"));        
        Sport EscapePark = new Sport(1,"Escape Park",3);
        EscapePark.setAgeLimit(5);        
        Culture SnakeTemple = new Culture(1,"Snake Temple",2);
        SnakeTemple.setEntranceFee(0.00);
        GeorgeTown.addAttraction(EscapePark);
        GeorgeTown.addAttraction(Komtar);
        GeorgeTown.addAttraction(SnakeTemple);
        cities.add(GeorgeTown);        
        
        City Berlin = new City("Berlin",2);
        Shopping MOB = new Shopping(2,"Mall of Berlin",1);
        Shops =  new ArrayList<>();
        Shops.addAll(Arrays.asList("Airfield","For All Mankind","Adidas"));
        MOB.setShop(Shops);
        Culture ReichStag = new Culture(2,"ReichStag",2);
        ReichStag.setEntranceFee(5.00);
        Culture Oktoberfest = new Culture(2,"Oktoberfest",2);
        Oktoberfest.setEntranceFee(10.00);
        Berlin.addAttraction(ReichStag);
        Berlin.addAttraction(Oktoberfest);
        Berlin.addAttraction(MOB);
 
        cities.add(Berlin);
        
        
        City NewYork = new City("New York",3);
        Shopping TS = new Shopping(3,"Times Square",1);
        Shops = new ArrayList<>();       
        Shops.addAll(Arrays.asList("Starbucks","Walmart","Costco"));
        TS.setShop(Shops);
        Sport SFNJ = new Sport(3,"Six Flags New Jersey",3);
        Culture SLiberty = new Culture(3,"Statue of Liberty",2);        
        SFNJ.setAgeLimit(10);
        NewYork.addAttraction(TS);
        NewYork.addAttraction(SFNJ);
        NewYork.addAttraction(SLiberty);
        cities.add(NewYork);
        
        City KualaLumpur = new City("Kuala Lumpur",4);
        Shopping SunwayPyramid = new Shopping(4,"Sunway Pyramid",1);
        Shops = new ArrayList<>();
        Shops.addAll(Arrays.asList("Burger King","1901 Hotdog","Chatime"));
        SunwayPyramid.setShop(Shops);
        Culture SunwayLagoon = new Culture(4,"Sunway Lagoon",2);
        Sport BukitJalil = new Sport(4,"Bukit Jalil Stadium",3);
        BukitJalil.setAgeLimit(0);
        SunwayLagoon.setEntranceFee(50.00);
        KualaLumpur.addAttraction(SunwayLagoon);
        KualaLumpur.addAttraction(SunwayPyramid);
        KualaLumpur.addAttraction(BukitJalil);
        cities.add(KualaLumpur);
        
        Berlin.addFlight(KualaLumpur);
        Berlin.addFlight(NewYork);
        
        NewYork.addFlight(Berlin);
        
        KualaLumpur.addFlight(GeorgeTown);
        KualaLumpur.addFlight(Berlin);
        
        GeorgeTown.addFlight(KualaLumpur);
        
    }    
    private static void printCities(ArrayList<City> cities)
    {
        Collections.sort(cities,Comparator.comparing(City::getCityname)); //Alphabetical arragement
        System.out.println("There are: "+(cities.size())+" cities logged\n");
        System.out.println("[0] [Back to previous list]");
        for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname());            
        }
         System.out.println("\n\nWhich cities would you like to know more about the attractions or flights?");
    }
    private static void printAttractionorFlight()
    {
        System.out.println("Would you like to view the attractions or flight?");
        System.out.println("[0] [Back to previous list]\n[1] Attractions\n[2] Flights");
    }
    private static boolean processAttractionorFlight(int cityindex) throws InputMismatchException
    {
        System.out.print("Number: ");
        Scanner input = new Scanner(System.in);
        try{
            int answer = input.nextInt();      
            if(answer==0){
                return false;
            }
            else if(answer==1){
                boolean printTypeorFull = true;
                while(printTypeorFull){
                    displayTypeorFull(cities.get(cityindex));
                    printTypeorFull = processdisplayTypeorFull(cities.get(cityindex));
                    printline();              
                }
                return true;
                }
            else if(answer==2){
                processflightcities(cityindex,cities);
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }    
        }
        catch(InputMismatchException err){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static void processflightcities(int cityindex,ArrayList<City> cities)
    {
        ArrayList<City> cityname = new ArrayList<>();
        cityname.addAll(cities.get(cityindex).getFlight());
        System.out.println("");
        System.out.println("City " + cities.get(cityindex).getCityname() +" is connected to: ");
        for(int i=0;i<cityname.size();i++){              
           System.out.println("["+(i+1)+"] "+ cityname.get(i).getCityname());                   
        }
        System.out.println("");       
    }
    private static boolean processInputprintCities() throws InputMismatchException
    {
        System.out.print("Number: ");
        Scanner input = new Scanner(System.in);
        boolean Systemloop = true;
        try{
            int answer = input.nextInt();  
            if(answer==0){ 
                return false;   //return to main function             
            }
            answer -=1;
            dashLine();
            if(answer<cities.size()){
                while(Systemloop){
                    printAttractionorFlight();
                    Systemloop = processAttractionorFlight(answer);
                }
                return true;                  
            }                       
                
            else{
                System.out.println("Cities does not exist at chosen number!"); 
                printline(); 
                return true;            
            }
        }
        catch(InputMismatchException err){
            System.out.println("Input should be a number!");
            printline(); 
            return true;
        }        
    }
    private static void displayTypeorFull(City cities)
    {
        System.out.println("Would you like to view the full list of attractions or the full type of attractions?");
        System.out.println("[0] [Back to previous list]\n[1] Type\n[2] Full");
    } 
    private static boolean processdisplayTypeorFull(City cities) throws InputMismatchException
    {
        System.out.print("Number: ");
        Scanner input= new Scanner(System.in);
        try{
            int answer = input.nextInt();           
            boolean attractionLoop = true;
            
            if(answer==0)
            {
                printline();
                return false; //returns to processInputprintCities() list
            }
            else if(answer==1)
            {
                while(attractionLoop){
                    displayTypeAttraction(cities);
                    attractionLoop = processdisplayTypeAttraction(cities); 
                    dashLine();
                }
                return true;
            }
            else if(answer==2)
            {
                ArrayList<Attraction> attractions = cities.getAttractions();
                while(attractionLoop){
                    displayAttraction(cities,attractions);
                    attractionLoop = processdisplayAttraction(cities,attractions); 
                    dashLine();
                }
                return true;
            }  
            else
            {
                System.out.println("Invalid input!\n");
                dashLine();
                return true;
            }
        }
        catch(InputMismatchException err){
            System.out.println("Input should be a number!");
            printline();
            return true;
        }
    }
    private static void displayTypeAttraction(City cities)
    {
        System.out.println("Type of Attractions");
        System.out.println("[0] [Back to previous list]\n[1] Shopping\n[2] Culture\n[3] Sports");
    }
    private static boolean processdisplayTypeAttraction(City cities) throws InputMismatchException
    {   
        //displays type of attraction
        System.out.print("Number: ");
        Scanner answer = new Scanner(System.in);
        try{
            int input = answer.nextInt();
            boolean attractionTypeLoop = true; 
            if(input==0){
                dashLine();
                return false;  //returns to processdisplayTypeorFull list
            }
            else if(input>=1 && input<=3)
            {
                ArrayList<Attraction> attractions = new ArrayList<>();
                if(input==1){           
                    attractions = cities.getshop(); //attractions with type ID 1 will be inserted into attractions array
                }
                else if(input==2){           
                    attractions = cities.getculture(); //attractions with type ID 2
                }
                else if(input==3){           
                    attractions = cities.getsport(); //attractions with type ID 3
                }                
                while(attractionTypeLoop){            
                    displayAttraction(cities, attractions);
                    attractionTypeLoop = processdisplayAttraction(cities,attractions);
                } 
                return true;
            }
            else{
                System.out.println("Invalid input!\n");
                return true;
            }  
        }
        catch(InputMismatchException error)
        {
            System.out.println("Input should be a number!");
            printline();
            return true;
        }
    }
    private static void displayAttraction(City cities,ArrayList<Attraction> attractions)
    {
        printline();
        System.out.println("[0] [Back to previous list]");
        for(int i =0;i<attractions.size();i++){
            System.out.println("["+(i+1)+"] "+attractions.get(i).getName());
        }
    }
    private static boolean processdisplayAttraction(City cities, ArrayList<Attraction> attractions) throws InputMismatchException
    {
        //displays the full list of attraction
        Scanner answer = new Scanner(System.in);
        System.out.print("Number: ");
        try{
            int number = answer.nextInt();   
            if(number==0){
                   return false; //goes back to processdisplayTypeorFull 
            }
            else{                
                number-=1; 
                if(number<attractions.size()){
                    attractions.get(number).display();                    
                    printline();
                    return true;
                }
                else{        
                    System.out.println("Attraction does not exist at chosen number!");
                    return true;
                }                
            }
        }
        catch(InputMismatchException error){
            System.out.println("Input should be a number!");
            printline();
            return true;
        }
    }
    private static void printSystemAdmin()
    {
        System.out.println("[0] Exit Program\n[1] Admin\n[2] User");
    }
    private static boolean processSystemAdmin() throws InputMismatchException
    {
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);
 
        try{
            int answer = input.nextInt();
            System.out.println("");
            if(answer==0){
                System.exit(0);
                return false;
            }
            else if(answer==1){
                boolean pICoA = true;
                while(pICoA){
                    printInsertCitiesorAttraction();
                    pICoA = processInsertCitiesorAttraction(cities);
                }
                return true;
            }
            else if(answer==2){
                boolean Systemlooping = true; //looping the system        
                while(Systemlooping){
                    printCities(cities);
                    Systemlooping = processInputprintCities();
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static void printInsertCitiesorAttraction()
    {
        System.out.println("What do you wish to modify?");
        System.out.println("[0] [Back to previous list]\n[1] Cities\n[2] Attractions\n[3] Flights");
    }
    private static boolean processInsertCitiesorAttraction(ArrayList<City> cities) throws InputMismatchException
    {
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);
                     
        try{
            int answer = input.nextInt();
            if(answer==0){
                return false;
            }
            else if(answer==1){
                boolean printaddcityorremove = true;
                while(printaddcityorremove){    
                    printaddcitiesorremove();
                    printaddcityorremove = processprintaddcityorremove(cities);
                }
                return true;           
            }
            else if(answer==2){
                boolean attractionmodify = true;
                while(attractionmodify){
                    printattractionmodify();
                    attractionmodify = processattractionmodify(cities);
                }
                return true;
            }  
            else if(answer==3){
                boolean modifyflight = true;
                while(modifyflight){
                   printmodifyflight();
                   modifyflight = processmodifyflight();
                }
                return true;
            }
            else{ 
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static void printmodifyflight()
    {
        System.out.println("");
        System.out.println("Do you want to insert to remove flight connections?");
        System.out.println("[0] [Back to previous list]\n[1] Add flight connections\n[2] Remove flight connections"); 
    }
    private static boolean processmodifyflight() throws InputMismatchException
    {
        Scanner input = new Scanner(System.in);
        System.out.print("Input: ");

        try{     
            int answer = input.nextInt();
            System.out.println("");
            if(answer==0){
                return false;
            }
            else if(answer==1){
                boolean addingflights = true;
                while(addingflights){
                    addingflights = addingflightsconnection(cities);
                }            
                return true;
            }
            else if(answer==2){
                boolean removingflights = true;
                while(removingflights){
                    removingflights = removingflightsconnection(cities);
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static boolean removingflightsconnection(ArrayList<City> cities) throws InputMismatchException
    {
        dashLine();
        printline();
        
        ArrayList<City> flighttemp = new ArrayList<>();
        Collections.sort(cities,Comparator.comparing(City::getCityname));
        
        System.out.println("[0] [Back to previous list]");
        for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname());            
        }
        System.out.println("Which city flight connection would you like to remove?");
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);

        try{     
            int answer = input.nextInt();
            printline();
            if(answer==0){
                return false;
            }
            else if(answer<=cities.size()){
                answer-=1;
                flighttemp.addAll(cities.get(answer).getFlight());
                
                if(flighttemp.size()==0){
                    System.out.println("There's no flight connection to remove!");
                    printline();
                    return true;
                }
                System.out.println("City "+ cities.get(answer).getCityname() + " is connected to: ");
                for(int i=0;i<flighttemp.size();i++){
                    System.out.println("["+(i+1)+"] "+ flighttemp.get(i).getCityname());
                }
                System.out.println("Which city would you like to remove the connection to?");
                int diffanswer = input.nextInt();
                if(diffanswer<=flighttemp.size()){
                    diffanswer-=1;
                    cities.get(answer).removeFlight(flighttemp.get(diffanswer));
                    flighttemp.get(diffanswer).removeFlight(cities.get(answer));
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                printline();
                return true;
            }
        }
        catch(InputMismatchException err){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static boolean addingflightsconnection(ArrayList<City> cities) throws InputMismatchException
    {
        dashLine();
        printline();
        ArrayList<City> flighttemp = new ArrayList<>(); //maybe add clone
        ArrayList<City> citiestemp = new ArrayList<>();          

        Collections.sort(cities,Comparator.comparing(City::getCityname));
        
        System.out.println("[0] [Back to previous list]");
        for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname());            
        }
        System.out.println("Which city would you like to add connection to?");
        Scanner input = new Scanner(System.in);
        System.out.print("Input: ");

        try{    
            int answer = input.nextInt();
            System.out.println("");
            if(answer==0){
                return false;
            }        
            else if(answer<=cities.size()){
                answer-=1;            
                flighttemp.addAll(cities.get(answer).getFlight());
                citiestemp.addAll(cities);
                
                System.out.println("City " + cities.get(answer).getCityname() + " is connected to");
                for(int i=0;i<flighttemp.size();i++){
                    System.out.println("["+(i+1)+"] "+ flighttemp.get(i).getCityname());
                }
                System.out.println("");
                System.out.println("City " +cities.get(answer).getCityname() + " not connected to: ");
             
                citiestemp.removeAll(flighttemp);
                citiestemp.remove(cities.get(answer));
                
                for(int i=0;i<citiestemp.size();i++){
                   System.out.println("["+(i+1)+"] "+citiestemp.get(i).getCityname());
                }            
                System.out.println("");
                System.out.println("Which city would you like to add connection to?");
                System.out.print("Input: ");
                int diffanswer = input.nextInt();
                if(diffanswer<=citiestemp.size()){
                    diffanswer-=1;
                    cities.get(answer).addFlight(citiestemp.get(diffanswer));
                    citiestemp.get(diffanswer).addFlight(cities.get(answer));
                }
                else{
                    System.out.println("Invalid input!");
                    printline();
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static void printaddcitiesorremove()
    {
        System.out.println("[0] [Back to previous list]\n[1] Add cities\n[2] Remove cities");            
    }
    private static boolean processprintaddcityorremove(ArrayList<City> cities) throws InputMismatchException
    {
        boolean modifyCity = true;
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);

        try{  
            int answer = input.nextInt();
            printline();
            if(answer==0){
                return false;
            }
            else if(answer==1){            
                while(modifyCity){
                    printaddCitiesorRead();
                    modifyCity = processaddCitiesorRead(cities);
                }
                return true;
            }
            else if(answer==2){
                while(modifyCity){
                    modifyCity = removeCity(cities);
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            System.out.println("");
            return true;
        }
    }
    private static void printaddCitiesorRead() 
    { 
        System.out.println("[0] [Back to previous list]\n[1] Add Cities manually\n[2] Read from file\n");
    }
    private static boolean processaddCitiesorRead(ArrayList<City> cities) throws InputMismatchException
    {
        boolean systemloop = true;
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);

        try{    
            int answer = input.nextInt();
            printline();
            if(answer==0){
                return false;
            }
            else if(answer==1){
                while(systemloop){
                    systemloop = addingCities(cities);
                }
                return true;
            }
            else if(answer==2){
                while(systemloop){
                    //systemloop = readfile();
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }   
    private static boolean removeCity(ArrayList<City> cities) throws InputMismatchException
    {
        System.out.println("Which city would you like to remove?\n");
        System.out.println("[0] [Back to previous list]");
        for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname()+ " ID: " +cities.get(i).getID());            
        } 
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);

        try{    
            int answer = input.nextInt();
            printline();
            if(answer==0){
                return false;
            }
            else if(answer<=cities.size()){
                ArrayList<City> flighttemp = new ArrayList<>();
                flighttemp.addAll(cities.get(answer-1).getFlight());
                for(int i=0;i<flighttemp.size();i++){
                    flighttemp.get(i).removeFlight(cities.get(answer-1));
                }
                cities.remove(answer-1);
                return true;
            }
            else{
                System.out.println("Cities does not exist at current index!");
                System.out.println("");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static boolean addingCities(ArrayList<City> cities) throws InputMismatchException
    {
        for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname()+ " ID: " +cities.get(i).getID());            
        } 
        try{
            System.out.print("City name: ");
            Scanner input = new Scanner(System.in);
            String name = input.nextLine();
            System.out.print("City ID: ");
            int cityid = input.nextInt();
            printline();
            for(int i=0;i<cities.size();i++){
                while(cityid==cities.get(i).getID()){
                    System.out.println("City ID has already been taken by a pre exisiting city!");
                    System.out.print("City ID: ");
                    cityid = input.nextInt();  
                }
            }
        
            City cityname = new City(name,cityid); 
        
            cities.add(cityname);
            System.out.println("");
       
            return false; 
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return false;
        }        
    }   
    private static void printattractionmodify() 
    {
        System.out.println("\n[0] [Back to previous list]\n[1] Add attractions\n[2] Remove attractions");
    }
    private static boolean processattractionmodify(ArrayList<City> cities) throws InputMismatchException 
    {
        boolean systemloop = true;
        System.out.print("Input: ");
        Scanner input = new Scanner(System.in);

        try{   
            int answer = input.nextInt();
            printline();
            if(answer==0){
                return false;
            }
            else if(answer==1){
                while(systemloop){
                    systemloop = addingAttractions(cities);
                }
                return true;
            }
            else if(answer==2){
                while(systemloop){
                   printremoveAttractions(cities);
                   systemloop = processremoveAttractions(cities);
                }
                return true;
            }
            else{
                System.out.println("Invalid input!");
                return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            return true;
        }
    }        
    private static boolean addingAttractions(ArrayList<City> cities) throws InputMismatchException
    {
       System.out.println("");
       Collections.sort(cities,Comparator.comparing(City::getCityname));
       System.out.println("[0] [Back to previous list]");
       for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname()+ " ID: " +cities.get(i).getID());            
       } 
       Scanner input = new Scanner(System.in);      
       System.out.print("At which city index will the new attraction be?: ");
       try{
           int cityindex = input.nextInt();
           if(cityindex==0){
               return false;
            }
           System.out.println("\nPlease add your attraction of type: ");
           System.out.println("[1] Shop\n[2] Culture\n[3] Sport");
           System.out.print("Type: ");
           int attractiontype = input.nextInt();
           printline();
           while(attractiontype>3){
               System.out.println("Current attraction ID does not exist!");
               System.out.print("Type: ");
               attractiontype = input.nextInt();
           }
             
           System.out.print("Attraction name: ");
           input.nextLine(); //Consumes the blank line so that it doesn't skip the next input
           String givenattractioname = input.nextLine();
           if(attractiontype==0){
               return false;
           }
           else if(attractiontype==1){    //set the array of shops   
               Shopping attractionname = new Shopping(cities.get(cityindex-1).getID(),givenattractioname,attractiontype);
               cities.get(cityindex-1).addAttraction(attractionname);
               System.out.println("What shops are to be added to the attraction? (Enter 'E' to exit shop addition)");
               ArrayList<String> Shops = new ArrayList<>();
               System.out.print("Shop: ");
               String shop = input.nextLine();
               while(!shop.equals("E")){               
                   Shops.add(shop);
                   System.out.print("Shop: ");
                   shop = input.nextLine();               
                }
                attractionname.setShop(Shops);
               System.out.println("");
           }
           else if(attractiontype==2){   //set entrance fee       
               Culture attractionname = new Culture(cities.get(cityindex-1).getID(),givenattractioname,attractiontype);
               cities.get(cityindex-1).addAttraction(attractionname);
               System.out.println("What would the entrance fee be?");
               double entrancefee = input.nextInt();           
               attractionname.setEntranceFee(entrancefee);
               System.out.println("");
           }
           if(attractiontype==3){       //set age limit
               Sport attractionname = new Sport(cities.get(cityindex-1).getID(),givenattractioname,attractiontype);
               cities.get(cityindex-1).addAttraction(attractionname);
               System.out.println("What would the age limit be?");
               int ageLimit = input.nextInt();           
               attractionname.setAgeLimit(ageLimit);           
               System.out.println("");
           }
           return true; 
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static void printremoveAttractions(ArrayList<City> cities)
    {
       System.out.println("");
       Collections.sort(cities,Comparator.comparing(City::getCityname));
       System.out.println("[0] [Back to previous list]");
       for(int i=0;i<cities.size();i++){
            System.out.println("["+(i+1)+"] "+cities.get(i).getCityname()+ " ID: " +cities.get(i).getID());            
       }
       System.out.println("");
       System.out.print("At which city index will you remove the attraction?: ");
    }
    private static boolean processremoveAttractions(ArrayList<City> cities) throws InputMismatchException
    {
       boolean Systemloop = true;
       Scanner input = new Scanner(System.in); 
       try{
           int cityindex = input.nextInt();  
           if(cityindex==0){
               return false;
           }
           else if(cityindex<=cities.size()){ 
               ArrayList<Attraction> attraction = new ArrayList<>(); 
               //attraction = cities.get(cityindex-1).getAttractions();
               while(Systemloop){
                   Systemloop = removeAttractions(cities,attraction,cityindex);           
               }   
               return true;
           }
           else{
               System.out.println("Invalid input!");
               System.out.println("");
               return true;
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
    }
    private static boolean removeAttractions(ArrayList<City> cities,ArrayList<Attraction> attraction,int cityindex) throws InputMismatchException
    {
        //attraction = cities.get(cityindex-1).returnAttractions(); //maybe add a counter to initialize once
        attraction = cities.get(cityindex-1).getAttractions();
        System.out.println("[0] [Back to previous list]");
        for(int i=0;i<attraction.size();i++){
            System.out.println("["+(i+1)+"] "+attraction.get(i).getName());
        } 
        System.out.println("");
        System.out.println("Which attraction?");
        System.out.print("Input: ");
        
        Scanner input = new Scanner(System.in);
        try{
            int answer = input.nextInt();     
            if(answer==0){
                return false;
            }
            else if(answer<=attraction.size()){
                cities.get(cityindex-1).removeAttraction(answer-1);
                return true;
            }
            else{
                System.out.println("Invalid input!");
                System.out.println("");
                return true;  
            }
        }
        catch(InputMismatchException error){
            System.out.println("Invalid input!");
            printline();
            return true;
        }
        
    }
}

