/**********|**********|**********|
Program: YOUR_FILENAME.cpp
Course: TCP1101 Programming Fundamentals
Year: 2017/18 Trimester 1
Name: Lim Kuang Tar
ID: 1171300077
Email: buddy.lim@live.com
Phone: 0164230329
**********|**********|**********/

#include <iostream>
#include <iomanip> //Usage of setw
#include <sstream> //Usage of stringstream
#include <cstdlib> //Usage of system()
#include <fstream> //Usage of save and load


using namespace std;

string copytext,oldcopytext,oldboxes[80]; //Oldboxes is an array that will save old elements of the notepad. copytext and oldcopytext is also the same in regards to saving the string.
int blocksize[8]; //Saves the biggest value of string length and sets the space of the notepad.

void screen(string boxes[],string& filename,string& findingwords);
void deleting(string boxes[],string& filename);
void FirstScreen(string input1,string& filename,string boxes[]);

bool is_file_exist(const char *filename)
{
    ifstream infile(filename); //Tells the user if the file exists.
    return infile.good();
}

void undo(string boxes[],string& filename)
{

    string input;
    string findingwords;

    cout<<"Would you like to undo your clipboard or notepad?\n";
    cout<<"ATTENTION: You can only undo twice in a row\n";
    cout<<"[C]lipboard, [N]otepad\n";
    cout<<"==> ";
    cin>>input;

    while(input!="C" && input!="c" && input!="N" && input!="n")
    {
        cout<<"Invalid input!\n";
        cout<<"==>";
        cin>>input;
    }

    if(input=="C" || input=="c")
    {
        copytext = oldcopytext;
    }
    else if(input=="N" || input=="n")
    {
        for(int x=0;x<80;x++)
        {
            boxes[x]=oldboxes[x];
        }
    }

    system("CLS");
    screen(boxes,filename,findingwords);
}

void resizetile(string boxes[])
{
   for(int x=0;x<8;x++)
   {
       blocksize[x]=4;
   }
   for(int x=0;x<80;x++)
   {
       if((int)boxes[x].length()>(int)blocksize[x%8])
       {
           blocksize[x%8] = boxes[x].length();
       }
   }
}

void save(string& filename,string boxes[])
{
    string findingwords;
    ofstream savefile(filename.c_str());

    if(savefile.is_open())
    {

        for(int x=0;x<79;x++)
        {
            savefile << boxes[x].c_str()<< ' ';
        }
        savefile.close();

        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"File saved successfully!\n";
        cout<<"Press Enter to continue.\n";
        cin.ignore();

    }
    else
    {
        cout <<"Unable to save file\n";
        cout<<"Press Enter to continue.\n";
        cin.ignore();
    }
    system("CLS");
    screen(boxes,filename,findingwords);
}

void load(string filename,string boxes[],bool& passedfirstscreen)
{

    cin.clear();
    cin.ignore();
    string load,input1,output,anotherbox[80];
    int elements=0;

    cout<<"Which file would you like to load?\n";
    cout<<"Filename: ";
    getline(cin,load);

    if(is_file_exist(load.c_str()))
    {
        for(int x=0;x<80;x++)
        {
            boxes[x]= anotherbox[x]; //Passes empty elements into the notepad so that the loaded text will replace and leftover texts from the previous file will be overwritten.
        }

        ifstream loadfile(load.c_str());

        loadfile.is_open();

            while (loadfile.good())
            {
                getline(loadfile,output);
                stringstream loaded(output);
                while(loaded.good() && elements<80)
                {
                    loaded>>boxes[elements];
                    ++elements;
                }
            }
        filename = load;

        loadfile.close();

    }
    else
    {
        cout<<"Such file does not exist!\n";
        cout<<"Press ENTER to continue.";
        cin.ignore();

    }
    string findingwords = "4612847564823378678316527120190914564856692346";

    if(passedfirstscreen == true)
    {
        system("CLS");
        screen(boxes,filename,findingwords);
    }
    else
    {
        system("CLS");
        FirstScreen(input1,filename,boxes);
    }
}

void copycopycopy(string boxes[],string& filename) //done
{

    oldcopytext = copytext;
    int tilenumber,tilenumber2;
    string test,findingwords;

    cout<<"Please select a tile-number which you would like to copy\n";
    cout<<"==> ";
    cin>>tilenumber;

    while(tilenumber<=0 || tilenumber>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"From tile-number\n ";
        cout<<"==> ";
        cin>>tilenumber;
    }

    cout<<"To tile-number\n";
    cout<<"==> ";
    cin>>tilenumber2;

    while(tilenumber2<=0 || tilenumber2>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"To tile number: ";
        cout<<"==> ";
        cin>>tilenumber2;
    }
    while(tilenumber>tilenumber2)
    {
        cin.ignore(1000,'\n');
        cin.clear();
        cout<<"Unable to copy when first tile number is bigger than the second tile-number!\n";
        cout<<"To tile number: ";
        cin>>tilenumber2;
    }

    tilenumber = tilenumber-1;
    tilenumber2 = tilenumber2-1;

    copytext="";
    for(int x=tilenumber;x<=tilenumber2;x++)
    {
        if(boxes[x].length()>0)
        {
            test = boxes[x];
            copytext.append(test);
            if(x<tilenumber2)
            copytext.append(" ");
        }
    }


    system("CLS");
    screen(boxes,filename,findingwords);
}

void clipboard(string& filename,string boxes[]) //done
{
    string findingwords;
    system("CLS");
    cout<<"Clipboard: "<<copytext<<"\n";

    screen(boxes,filename,findingwords);
}

void pasteaway(string boxes[],string& filename,int& counter) //done
{
    string findingwords;
    for(int x=0;x<80;x++)
    {
        oldboxes[x] = boxes[x];
    }

    int tilenumber,alpha=0;
    string test[80];

    cout<<"Which tile-number would you like to paste into?\n";
    cout<<"==> ";
    cin>>tilenumber;

    while(tilenumber<=0 || tilenumber>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"Please insert a tile-number that's between 1~80\n";
        cout<<"==> ";
        cin>>tilenumber;
    }
    tilenumber = tilenumber-1;

    if(boxes[tilenumber].length() == 0)
    {
        tilenumber = counter;

        stringstream ssin(copytext);
        while (ssin.good() &&  tilenumber < 80)
        {
            ssin >> boxes[tilenumber];
            ++tilenumber;
        }
    }
    else
    {
        stringstream swool(copytext),zwool(copytext);
        while(swool.good() && alpha <80)
        {
            swool>>test[alpha];
            ++alpha;
        }
        for(int x=79;x>tilenumber;x--)
        {
            boxes[x] = boxes[x-alpha];
        }
        while(zwool.good() && tilenumber <80)
        {
            zwool>> boxes[tilenumber];
            ++tilenumber;
        }
    }
    system("CLS");
    screen(boxes,filename,findingwords);

}

void cut(string boxes[],string& filename)
{
    string findingwords;
    for(int x=0;x<80;x++)
    {
        oldboxes[x] = boxes[x];
    }
    oldcopytext = copytext;
    int tilenumber,tilenumber2,y;
    string test;

    cout<<"Please select a tile-number which you would like to cut\n";
    cout<<"==> ";
    cin>>tilenumber;

    while(tilenumber<=0 || tilenumber>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"From tile-number\n ";
        cout<<"==> ";
        cin>>tilenumber;
    }

    cout<<"To tile-number\n";
    cout<<"==> ";
    cin>>tilenumber2;

    while(tilenumber2<=0 || tilenumber2>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"To tile number: ";
        cout<<"==> ";
        cin>>tilenumber2;
    }
    while(tilenumber>tilenumber2)
    {
        cin.ignore(1000,'\n');
        cin.clear();
        cout<<"Unable to cut when first tile number is bigger than the second tile-number!\n";
        cout<<"To tile number: ";
        cin>>tilenumber2;
    }

    tilenumber = tilenumber-1;
    tilenumber2 = tilenumber2-1;
    y = tilenumber2-tilenumber;

    copytext="";
    for(int x=tilenumber;x<=tilenumber2;x++)
    {
        test = boxes[x];
        copytext.append(test);

        if(x<tilenumber2)
            copytext.append(" ");
    }
    for(int x=tilenumber;x<=tilenumber2;x++)
    {
        boxes[x] = "";
    }
    for(int z=tilenumber;z<=79-y;z++)
    {
        boxes[z]=boxes[z+y];
    }
    for(int z=tilenumber;z<=79-y;z++)
    {
        boxes[z]=boxes[z+1];
    }

    system("CLS");
    screen(boxes,filename,findingwords);
}

void drawblock(int space) //prints "-" or " " based on userinput or prints out its default value.
{
    cout<<"+";
    for(int a=0;a<space;a++)
    {
        cout<<"-";
    }
}

void finding(string boxes[],string& filename,string& findingwords)
{

    cout<<"Please type out the word you'd like to find\n";
    cout<<"==> ";
    cin>>findingwords;

    system("CLS");
    screen(boxes,filename,findingwords);
}

void spookyskeleton(string boxes[]) //The entire skeleton of the notepad itself.
{
    for(int x=0;x<8;x++)
    {
        drawblock(blocksize[x]);
    }
}

void Inserting(string boxes[],string& filename,int& counter) //done
{
    string findingwords;
    for(int x=0;x<80;x++)
    {
        oldboxes[x] = boxes[x];
    }
    cin.clear();
    cin.ignore(1000, '\n');
    int alpha=0,tilenumber=0;
    string text,nextmoves[80];

    cout<<"Please insert a tile-number that's between 1~80\n";
    cout<<"==> ";
    cin>>tilenumber;

    while(tilenumber<=0 || tilenumber>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"Please insert a tile-number that's between 1~80\n";
        cout<<"==> ";
        cin>>tilenumber;
    }

    tilenumber = tilenumber - 1;

    cout<<"Please insert your text\n";
    cout<<"Text: ";
    cin.ignore();
    getline(cin,text);

    while(text.length()==0)
    {
        cin.clear();
        cout<<"Please at least type in a letter!\n";
        cout<<"Text: ";
        getline(cin,text);
    }

    if(boxes[tilenumber].length() == 0)
    {
        if(boxes[0].length()==0)
        {
            tilenumber = 0;
        }
        tilenumber = counter;
        stringstream ssin(text);
        while (ssin.good() &&  tilenumber < 80)
        {
            ssin >> boxes[tilenumber];
            ++tilenumber;
        }
    }

    else
    {
        stringstream swool(text),zwool(text);
        while(swool.good() && alpha <80)
        {
            swool>>nextmoves[alpha];
            ++alpha;
        }
        for(int x=79;x>tilenumber;x--)
        {
            boxes[x] = boxes[x-alpha];
        }
        while(zwool.good() && tilenumber <80)
        {
            zwool>> boxes[tilenumber];
            ++tilenumber;
        }
    }
    cin.clear();
    system("CLS");

    screen(boxes,filename,findingwords);
}

void overwrite(string boxes[],string& filename) //done
{
    string findingwords;
    for(int x=0;x<80;x++)
    {
        oldboxes[x] = boxes[x];
    }

    string text,nextmoves[80];
    int tilenumber;
    char yn; //Yes or No

    cout<<"Please select a tile number to overwrite from.\n";
    cout<<"==> ";
    cin>>tilenumber;

    while(cin.fail())
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid input!\n";
        cout<<"Please select a tile number to overwrite from.\n";
        cout<<"==>";
        cin>>tilenumber;
    }
    while(tilenumber<0 || tilenumber>80)
    {
        cout<<"Invalid tile number!\n";
        cout<<"==>";
        cin>>tilenumber;
    }
    tilenumber=tilenumber-1;

    if(boxes[tilenumber].length()>0)
    {
        cout<<"Are you sure?\n";
        cout<<"Y/N\n";
        cout<<"==>";
        cin>>yn;

        while(yn!='Y' && yn!='N' && yn!='y'&& yn!='n')
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Invalid input!\n";
            cout<<"Y/N?\n";
            cout<<"==>";
            cin>>yn;
        }
        if(yn == 'Y' || yn == 'y')
        {
            cout<<"Text: ";
            cin.ignore();
            getline(cin,text);

            stringstream zwool(text);

            while(zwool.good() && tilenumber <80)
            {
                zwool>> boxes[tilenumber];
                ++tilenumber;

            }
            system("CLS");
            screen(boxes,filename,findingwords);
        }

        else if(yn == 'N' || yn == 'n')
        {
            system("CLS");
            screen(boxes,filename,findingwords);
        }
    }

    else if(boxes[tilenumber].length() == 0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"There's nothing to overwrite!\n";
        cout<<"Press Enter to continue.\n";
        cin.ignore(); //creates a buffer so New function isn't prematurely used.

        system("CLS");
        screen(boxes,filename,findingwords);
    }
}

void FirstScreen(string input1,string& filename,string boxes[])
{
    bool passedfirstscreen = false;
    char yn;
    string anotherbox[80],findingwords;

    for(int x=0;x<79;x++)
    {
        boxes[x] = anotherbox[x];
    }

    cout<<"* ============================================\n";
    cout<<"File name :NULL\n";
    cout<<"[N]ew, [L]oad, [Q]uit\n";
    cout<<"==>";
    cin>>input1;


    while(input1!="q" && input1!="Q" && input1!= "N" && input1!="n" && input1!="L" && input1!="l")
    {
        cout<<"Invalid input!\n";
        cout<<"==>";
        cin>>input1;
    }
    if(input1 == "Q"|| input1=="q")
    {
            while(yn!='N' && yn!='Y' && yn!='n' && yn!='y')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Are you sure you want to exit?\n";
                    cout<<"Y/N?\n";
                    cout<<"==>";
                    cin>>yn;
                }
                if(yn == 'Y' || yn == 'y')
                {
                    system("CLS");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    exit(EXIT_SUCCESS);
                }
                else if(yn == 'N' || yn == 'n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    FirstScreen(input1,filename,boxes);
                }
    }
    else if(input1=="N" || input1=="n")
    {
        cout<<"\nIMPORTANT! Please include .txt at the end of your filename to allow saving and loading functionality!\n\n";
        cout<<"Please name your new file: ";
        cin.ignore(); //Creates a buffer so that it system(CLS) is not prematurely used.
        getline(cin, filename);
        system ("CLS"); //Clears the screen for the next cout statement.
        do
        {
            system("CLS");
            screen(boxes,filename,findingwords);
        }
        while(true);

    }
    else if(input1=="L" || input1=="l")
    {
        load(filename,boxes,passedfirstscreen);
    }
}

void screen(string boxes[80],string& filename,string& findingwords)
{
    if(findingwords == "")
    {
        findingwords = "46128475648233786783165271201909"; //As a measure so that the notepad isn't highlighted when no elements are in it.
    }
    bool passedfirstscreen = true;
    int counter = 0;
    for(int x=0;x<80;x++)
    {
       if(boxes[x].length()>0)
       {
           counter++; //Runs a counter for inserting so that all elements are pushed to the nearest element or inserted properly
       }
    }

    resizetile(boxes);

    int space;
    char yn,yesno;
    string input1,input2;

    cout<<"* ============================================\n";
    cout<<"File name : "<<filename<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"|    |";

    for(int x=0;x<8;x++)
    {
        space = blocksize[x];
        cout<<setw(space);
        cout<<(x+1);
        cout<<"|";
    }


    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 00 |";

    for(int x=0;x<=7;x++)
    {
        space = blocksize[x];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }

    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 08 |";

    for(int x=8;x<=15;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 16 |";

    for(int x=16;x<=23;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }

    cout<<"\n";

    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 24 |";

    for(int x=24;x<=31;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }

    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 32 |";

    for(int x=32;x<=39;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 40 |";

    for(int x=40;x<=47;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 48 |";

    for(int x=48;x<=55;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 56 |";

    for(int x=56;x<=63;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 64 |";

    for(int x=64;x<=71;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 72 |";

    for(int x=72;x<80;x++)
    {
        space = blocksize[x%8];
        cout<<setw(space);
        cout<<boxes[x];
        if(findingwords==boxes[x])
        {
            cout<<"=";
        }
        else
        {

            cout<<"|";
        }
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"[N]ew, [I]nsert, [D]elete, [O]verwrite, [L]oad, [S]ave, [C]opy, show-clip[B]oard, [X]cut, [P]aste, [F]ind, [U]ndo\n";
    cout<<"==> ";
    cin>>input2;

    do
    {
        if(input2=="N" || input2=="n")
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Are you sure you want to continue?\n";
                cout<<"Y/N?\n";
                cout<<"==>";
                cin>>yn;

                while(yn!='N' && yn!='Y' && yn!='n' && yn!='y')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Invalid input!\n";
                    cout<<"Y/N?\n";
                    cout<<"==>";
                    cin>>yn;
                }
                if(yn == 'Y' || yn == 'y')
                {
                    system("CLS");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    FirstScreen(input1, filename,boxes);
                }
                else if(yn == 'N' || yn == 'n')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    system("CLS");
                    screen(boxes,filename,findingwords);
                }
            }
        else if(input2 =="I" || input2 =="i")
            Inserting(boxes,filename,counter);

        else if(input2 =="D"|| input2 =="d")
            deleting(boxes,filename);

        else if(input2 =="O"|| input2 =="o")
            overwrite(boxes,filename);

        else if(input2 =="C"|| input2 =="c")
            copycopycopy(boxes,filename);

        else if(input2 =="B"|| input2 =="b")
            clipboard(filename,boxes);

        else if(input2 =="P"|| input2 =="p")
            pasteaway(boxes,filename,counter);

        else if(input2=="X"|| input2 =="x")
            cut(boxes,filename);

        else if(input2=="S"|| input2 =="s")
            save(filename,boxes);

        else if(input2=="L"|| input2 =="l")
            load(filename,boxes,passedfirstscreen);

        else if(input2=="F"|| input2 =="f")
            finding(boxes,filename,findingwords);

        else if(input2=="U"|| input2 =="u")
            undo(boxes,filename);

        else if(input2 =="Q"|| input2 =="q")
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Are you sure you want to continue?\n";
            cout<<"Y/N?\n";
            cout<<"==>";
            cin>>yesno;

            while(yesno!='N' && yesno!='Y' && yesno!='y' && yesno!='n')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Invalid input!\n";
                cout<<"Y/N?\n";
                cout<<"==>";
                cin>>yn;
            }
            if(yesno == 'Y' || yesno == 'y')
            {
                exit(EXIT_SUCCESS);
            }
            else if(yesno == 'N' || yesno == 'n')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                screen(boxes,filename,findingwords);
            }
        }
        else
        {
            cout<<"Invalid input!\n";
            cout<<"==>";
            cin>>input2;
        }
    }
    while(true);
}

void deleting(string boxes[],string& filename) //done
{
    string findingwords;
    for(int x=0;x<80;x++)
    {
        oldboxes[x] = boxes[x];
    }

    int tilenumber,tilenumber2,y=0;
    char yn;

    cin.clear();
    cin.ignore(1000, '\n');
    cout<<"From which tile number would you like to delete?\n";
    cout<<"==>";
    cin>>tilenumber;

    while(tilenumber<=0 || tilenumber>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"Please insert a tile-number that's between 1~80\n\n";
        cout<<"From which tile number would you like to delete?\n";
        cout<<"==>";
        cin>>tilenumber;
    }
    cout<<"To tile number: ";
    cin>>tilenumber2;

    while(tilenumber2<=0 || tilenumber2>80)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"Invalid tile-number input!\n";
        cout<<"To tile number: ";
        cout<<"==> ";
        cin>>tilenumber2;
    }

    while(tilenumber>tilenumber2)
    {
        cin.ignore(1000,'\n');
        cin.clear();
        cout<<"Deletion is not possible when the first tile number is bigger than the second tilenumber!\n";
        cout<<"To tile number: ";
        cin>>tilenumber2;
    }

    tilenumber = tilenumber-1;
    tilenumber2 = tilenumber2-1;
    y = tilenumber2-tilenumber+1;

    if(boxes[tilenumber].length()==0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"There's nothing to delete!\n";
        cout<<"Press ENTER to continue.\n";
        cin.ignore();
        system("CLS");
        screen(boxes,filename,findingwords);
    }
    else if(boxes[tilenumber].length()>0)
    {
        cout<<"Are you sure?\n";
        cout<<"Y/N\n";
        cout<<"==>";
        cin>>yn;

        while(yn!='N' && yn!='Y' && yn!='n' && yn!='y')
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Invalid input!\n";
            cout<<"Y/N?\n";
            cout<<"==>";
            cin>>yn;
        }
        if(yn == 'Y' || yn == 'y')
        {
            for(int x=tilenumber;x<=tilenumber2;x++)
            {
                boxes[x] = "";
            }
            for(int z=tilenumber;z<=79-y;z++)
            {
                boxes[z]=boxes[z+y];
            }
            system("CLS");
            screen(boxes,filename,findingwords);
        }
        else if(yn == 'N' || yn == 'n')
        {
            system("CLS");
            screen(boxes,filename,findingwords);
        }
    }
}

int main()
{
    string input1 ,filename,boxes[80];

    FirstScreen(input1,filename,boxes);
}
