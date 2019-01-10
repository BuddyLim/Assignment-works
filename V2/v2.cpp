#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iterator>

using namespace std;

string copytext;

void screen(string boxes[80],string& filename);
void deleting(string boxes[],string& filename);

void copycopycopy(string boxes[],string& filename)
{
    int tilenumber,tilenumber2;
    string test;

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
        test = boxes[x];
        copytext.append(test);

        if(x<tilenumber2)
            copytext.append(" ");

    }

    //cout << "Copied text is : '" << copytext << "'\n";

    system("CLS");
    screen(boxes,filename);
}

void clipboard(string& filename,string boxes[])
{
    system("CLS");
    cout<<"Clipboard: "<<copytext<<"\n";

    screen(boxes,filename);
}

void pasteaway(string boxes[],string& filename)
{
    int tilenumber,gamma,alpha=0;
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
    gamma = tilenumber;


    stringstream paste(copytext),transfer(copytext);
    while(paste.good() && alpha<80)
    {
        paste>>test[alpha];
        alpha++;
    }

    for(int x=79;x>=tilenumber;x--)
    {
        boxes[x+alpha] = boxes[x];
    }
    for(int x=gamma;x<79;x++)
    {
        transfer>>boxes[gamma];
        gamma++;
    }

    //Recode this part, don't loop through all the boxes tiles, loop through the test array instead
    //then set the value on boxes[gamma+x] =

    /*
    for(int x=tilenumber;x<79;x++)
    {
        boxes[x+alpha] = boxes[x];
    }
    while(transfer.good() && tilenumber<79)
    {
        transfer>>boxes[gamma];
        gamma++;
    }*/

    system("CLS");
    screen(boxes,filename);

}


//void cut()

void drawblock(int space) //prints "-" or " " based on userinput or prints out its default value.
{
    cout<<"+";
    for(int a=0;a<space;a++)
    {
        cout<<"-";
    }
}
void spookyskeleton(string boxes[]) //The entire skeleton of the notepad itself. /*wadafak is this*/
{
    int space;
//    int bigspace[8];

    for(int x=0;x<8;x++)
    {
        for(int x=0;x<8;x++)
        {
            if(boxes[x].length()<3)
                space = 4;

            else if(boxes[x].length()>boxes[x+1].length())
                space = boxes[x].length();

            else
                space = boxes[x].length();
        }
        drawblock(space);
    }

    /*for(int x=8;x>0;x--)
    {
        if(boxes[x].length()<3)
        {
            bigspace[x] = 4;
            space = bigspace[x];
        }
        else if(boxes[x].length()>boxes[x+1].length())
        {
            bigspace[x] = boxes[x].length();
            space = bigspace[x];
        }
    }

    drawblock(space);*/
    /*for(int x=0;x<80;x++)
    {
        if(boxes[x % 80].length()<bigspace[x].length())
        {
            space = bigspace[x].length();
        }
        else
        {
            space = boxes[x].length();
        }

    }
        else
        {
            space = boxes[].length();
        }
        drawblock(space);*/


    /*for(int x=0;x<8;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else if(boxes[x].length()>boxes[x+1].length())
            space = boxes[x].length();

        else
            space = boxes[x].length();

        drawblock(space);
    }*/
}

void Inserting(string boxes[],string& filename)
{
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

    if(boxes[tilenumber].length() == 0)
    {
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
            boxes[x] = boxes[x-alpha];

        while(zwool.good() && tilenumber <80)
        {
            zwool>> boxes[tilenumber];
            ++tilenumber;
        }
    }
    cin.clear();
    system("CLS");

    screen(boxes,filename);
}

void overwrite(string boxes[],string& filename)
{
    string text,nextmoves[80];
    int tilenumber,alpha=0;
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

        while(yn!='Y' && yn!='N')
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Invalid input!\n";
            cout<<"Y/N?\n";
            cout<<"==>";
            cin>>yn;
        }
        if(yn == 'Y')
        {
            cout<<"Text: ";
            cin.ignore();
            getline(cin,text);
            if(boxes[tilenumber].length() == 0)
            {
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
                for(int x=79;x==tilenumber;x--)
                    boxes[x] = boxes[x-alpha];

                while(zwool.good() && tilenumber <80)
                {
                    zwool>> boxes[tilenumber];
                    ++tilenumber;
                }
            }
            system("CLS");
            screen(boxes,filename);
        }
        else if(yn == 'N')
        {
            system("CLS");
            screen(boxes,filename);
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
        screen(boxes,filename);
    }
}

void FirstScreen(string input1,string& filename,string boxes[])
{
    char yn;

    cout<<"* ============================================\n";
    cout<<"File name :NULL\n";
    cout<<"[N]ew, [L]oad, [S]save, [Q]uit\n";
    cout<<"==>";
    cin>>input1;

    while(input1!="Q" && input1!= "N" && input1!="L" && input1!="S")
    {
        cout<<"Invalid input!\n";
        cout<<"==>";
        cin>>input1;
    }
    if(input1 == "Q")
    {
            while(yn!='N' && yn!='Y')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Are you sure you want to exit?\n";
                    cout<<"Y/N?\n";
                    cout<<"==>";
                    cin>>yn;
                }
                if(yn == 'Y')
                {
                    system("CLS");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    exit(EXIT_SUCCESS);
                }
                else if(yn == 'N')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    FirstScreen(input1,filename,boxes);
                }
    }
    else if(input1=="N")
    {
        cout<<"Please name your new file: ";
        cin.ignore(); //Creates a buffer so that it system(CLS) is not prematurely used.
        getline(cin, filename);
        system ("CLS"); //Clears the screen for the next cout statement.
        do
        {
            system("CLS");
            screen(boxes,filename);
        }
        while(true);
    }
}

void screen(string boxes[80],string& filename)
{
    int space;
    char yn,yesno;
    string input1,input2;

    cout<<"* ============================================\n";
    cout<<"File name : "<<filename<<".txt"<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"|    |";

    for(int x=0;x<8;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

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
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }

    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 08 |";

    for(int x=8;x<=15;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 16 |";

    for(int x=16;x<=23;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }

    cout<<"\n";

    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 24 |";

    for(int x=24;x<=31;x++)
    {
        if(boxes[x].length()<3)
            space = 4;


        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }

    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 32 |";

    for(int x=32;x<=39;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 40 |";

    for(int x=40;x<=47;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 48 |";

    for(int x=48;x<=55;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 56 |";

    for(int x=56;x<=63;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 64 |";

    for(int x=64;x<=71;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"| 72 |";

    for(int x=72;x<80;x++)
    {
        if(boxes[x].length()<3)
            space = 4;

        else
            space = boxes[x].length();

        cout<<setw(space);
        cout<<boxes[x];
        cout<<"|";
    }
    cout<<"\n";
    cout<<"|----";

    spookyskeleton(boxes);

    cout<<"|\n";
    cout<<"[N]ew, [I]nsert, [D]elete, [O]verwrite, [L]oad, [S]save, [C]opy, show-clip[B]oard, [X]cut, [P]aste, [F]ind, [U]ndo\n";
    cout<<"==> ";
    cin>>input2;

    do
    {
        if(input2=="N")
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Are you sure you want to continue?\n";
                cout<<"Y/N?\n";
                cout<<"==>";
                cin>>yn;

                while(yn!='N' && yn!='Y')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Invalid input!\n";
                    cout<<"Y/N?\n";
                    cout<<"==>";
                    cin>>yn;
                }
                if(yn == 'Y')
                {
                    system("CLS");
                    cin.clear();
                    cin.ignore(1000, '\n');
                    FirstScreen(input1, filename,boxes);
                }
                else if(yn == 'N')
                {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    system("CLS");
                    screen(boxes,filename);
                }
            }
        else if(input2 =="I")
            Inserting(boxes,filename);

        else if(input2 =="D")
            deleting(boxes,filename);

        else if(input2 =="O")
            overwrite(boxes,filename);

        else if(input2 =="C")
            copycopycopy(boxes,filename);

        else if(input2 =="B")
            clipboard(filename,boxes);

        else if(input2 =="P")
            pasteaway(boxes,filename);

        else if(input2 =="Q")
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Are you sure you want to continue?\n";
            cout<<"Y/N?\n";
            cout<<"==>";
            cin>>yesno;

            while(yesno!='N' && yesno!='Y')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                cout<<"Invalid input!\n";
                cout<<"Y/N?\n";
                cout<<"==>";
                cin>>yn;
            }
            if(yesno == 'Y')
            {
                exit(EXIT_SUCCESS);
            }
            else if(yesno == 'N')
            {
                cin.clear();
                cin.ignore(1000, '\n');
                screen(boxes,filename);
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

void deleting(string boxes[],string& filename)
{
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

    if(boxes[tilenumber].length()==0)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout<<"There's nothing to delete!\n";
        cout<<"Press ENTER to continue.\n";
        cin.ignore();
        system("CLS");
        screen(boxes,filename);
    }
    else if(boxes[tilenumber].length()>0)
    {
        cout<<"Are you sure?\n";
        cout<<"Y/N\n";
        cout<<"==>";
        cin>>yn;

        while(yn!='Y' && yn!='N')
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout<<"Invalid input!\n";
            cout<<"Y/N?\n";
            cout<<"==>";
            cin>>yn;
        }
        if(yn == 'Y')
        {
            for(int x=tilenumber;x<tilenumber2;x++)
                boxes[x] = "";

            for(int x=tilenumber;x<78;x++)
            {
                y = tilenumber2-tilenumber;
                boxes[x] = boxes[x+y];
            }
            system("CLS");
            screen(boxes,filename);
        }
        else if(yn == 'N')
        {
            system("CLS");
            screen(boxes,filename);
        }
    }
}

int main()
{
    string input1,filename,boxes[80];

    FirstScreen(input1,filename,boxes);
}
