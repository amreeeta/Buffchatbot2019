#include <stdio.h>
#include <iostream>
#include <fstream>
#include <cctype>
#include <string.h>
#include <time.h>
#define SIZE 256


char choice[SIZE];
int flag=0;
void login();
void createacc();
void cscr();
void mainmenu(char *);
void addevent(char username[]);
void displayevents(char username[]);
void deleteevent(char username[]);
void modify(char username[]);
char * uppercase(char*);
using namespace std;


struct chat
{
    char in[SIZE];
    char out[SIZE];
}c,ch;


struct event
{
    char name[SIZE];
    int time;
    long date;
    char details[SIZE];
}e;


struct userfile
{
    char username[SIZE];
    char password[SIZE];
}u,a;




int main()
{
    cout<<"                      ▀█████████▄   ███     ███      ▄████████    ▄████████       ▄██████    ▄█    █▄     ▄████████     ▀█████████▄  ▀█████████▄    ▄██████▄    ▀█████████▄  "<<endl;
    cout<<"                       ███    ███   ███     ███   ███    ███   ███    ███      ███    ███   ███    ███     ███    ███       ███       ███    ███   ███     ███      ███       "<<endl;
    cout<<"                       ███    ███   ███     ███   ███    █▀    ███    █▀       ███          ███    ███     ███    ███       ███       ███    ███   ███     ███      ███       "<<endl;
    cout<<"                       ▄███▄▄▄██▀   ███     ███  ▄███▄▄▄      ▄███▄▄▄          ███         ▄███▄▄▄▄███▄▄   ███    ███       ███       ▄███▄▄▄██▀   ███     ███      ███       "<<endl;
    cout<<"                      ▀▀███▀▀▀██▄   ███     ███ ▀▀███▀▀▀     ▀▀███▀▀▀          ███        ▀▀███▀▀▀▀███▀    ▀█████████       ███       ▀███▀▀▀██▄   ███     ███      ███       "<<endl;
    cout<<"                        ███    ██▄  ███     ███   ███          ███             ███          ███    ███     ███    ███       ███        ███    ██▄  ███     ███      ███       "<<endl;
    cout<<"                        ███    ███  ███     ███   ███          ███             ███    ███   ███    ███     ███    ███       ███        ███    ███  ███     ███      ███        "<<endl;
    cout<<"                      ▄█████████▀    █████████   ███          ███               ████████▀   ███    ███     ███    ███      ▄███       ▄█████████▀    ▀██████▀       ███       "<<endl;
    cout<<"\n\n                                                                          A. Log In        B. Create Account\n\n";
start:
    char ch;
    cin>>ch;
    if(ch=='A'||ch=='a')
    {
        login();
    }
    else if(ch=='B'||ch=='b')
    {
        createacc();
    }
    else
    {
        cout<<endl<<"Wrong Choice."<<endl;
        goto start;
    }
    return 0;
    
}
char * uppercase(char word[])
{
    char inp[SIZE];
    for(int i=0; word[i]!='\0'; i++)
    {
        inp[i]=toupper(word[i]);
    }
    return inp;
    
}




void createacc()
{
    cscr();
createac:
    cout<<"\n\nEnter new username:\n";
    cin>>a.username;
    
    cout<<"\nEnter password:\n";
    cin>>a.password;
    fstream  file;
    
    file.open("work.dat", ios::out|ios::in|ios::binary);
    file.read((char*)&u, sizeof(u));
    while(!file.eof())
    {
        if(strcmp(u.username,a.username)==0)
        {
            cout<<endl<<"Username is already in use."<<endl;
            goto createac;
                
        }
        file.read((char*)&u, sizeof(u));
    }
    file.close();
    
    
        file.open("work.dat", ios::out|ios::binary|ios::app);
        file.write((char*)&a,sizeof(a));
        file.close();
        
        fstream filecreate;
        filecreate.open(a.username,ios::out);
        
        filecreate.close();
        login();
    
    file.close();
    
    
    
    
    
}


void login()
{
    cscr();
    cout<<"\nWelcome to login\n";
again:
    cin.ignore(1000,'\n');
    cout<<"\nEnter username:\n";
    cin.getline(a.username,SIZE);
    
    fstream  file;
    file.open("work.dat", ios::out|ios::in|ios::binary|ios::beg);
    
    file.read((char*)&u, sizeof(u));
    int flag=0;
    while(!file.eof())
    {
       
        
        if(strcmp(u.username,a.username)==0)
        {
            flag=1;
            cin.ignore(1000,'\n');
            cout<<"\nEnter password:\n";
            cin.getline(a.password,SIZE);
            if(strlen(a.password)==strlen(u.password))
            {
                
                for(int i=0; i<strlen(a.password); i++)
                {
                    
                    if(a.password[i]!=u.password[i])


                    {
                        cout<<endl<<"Wrong password."<<endl;
                        goto again;
                    }
                }
            
            }
            else
            {
                cout<<endl<<"Wrong password."<<endl;
                goto again;
            }
            
        }
        file.read((char*)&u, sizeof(u));
    }
    if(flag==0)
    {
        cout<<endl<<"Username does not exist."<<endl;
        goto again;
    }
            
        


    file.close();
    mainmenu(a.username);
}






void mainmenu(char username[])
{
buff:
    cscr();
    char inp[SIZE];
    cin.ignore(1000,'\n');
    cout<<"Hi "<<username<<"! What would you like me to do for you today? \nEnter Help if you want to know what I can do.  \n\n\n";
    cin.getline(c.in,SIZE);
    for(int i=0; c.in[i]!='\0'; i++)
    {
        inp[i]=toupper(c.in[i]);
        inp[i+1]='\0';
    }
    if(strcmp(inp,"HELP")==0)
    {
        cout<<"\n\nI can do the following and more!:\n1.Add event \n2.View events \n3.Delete events \n4.Modify event \n5.Tell me the date and time \n6.Exit \n";
        cout<<endl<<endl<<"Some of my chat commands are:"<<endl<<endl;
        fstream file;
        file.open("chatttt.dat",ios::out|ios::in|ios::binary);
        
        file.seekg(0);
        if(!file)
        {
            cout<<endl<<"ERROR 404"<<endl;
            exit(0);
        }
        file.read((char*)&ch, sizeof(ch));
        
        
        
        for(int i=0; i<5; i++)
        {
            cout<<ch.in<<endl;
            file.read((char*)&ch, sizeof(ch));
        }
        file.close();
    }
    else if(strcmp(inp,"ADD EVENT")==0)
    {
        addevent(username);
    }
    else if(strcmp(inp,"VIEW EVENTS")==0)
    {
        displayevents(username);
    }
    else if(strcmp(inp,"DELETE EVENT")==0)
    {
        deleteevent(username);
    }
    else if(strcmp(inp,"MODIFY EVENT")==0)
    {
        modify(username);
    }
    else if(strcmp(inp,"TELL ME THE DATE AND TIME")==0)
    {
    // declaring argument of time()
    time_t my_time = time(NULL);
    
    // ctime() used to give the present time
    printf("%s", ctime(&my_time));
    }
    else if(strcmp(inp,"EXIT")==0)
    {
        cout<<endl<<"Goodbye!"<<endl;
        exit(0);
    }
    else
    {
        fstream file;
        file.open("chatttt.dat",ios::out|ios::in|ios::binary);
        
        file.seekg(0);
        if(!file)
        {
            cout<<endl<<"ERROR 404"<<endl;
            exit(0);
        }
        file.read((char*)&ch, sizeof(ch));
        
        while(!file.eof())
        {
            if(strcmp(inp,ch.in)==0)
            {
                cout<<endl<<ch.out<<endl;
                flag=1;
                break;
            }
            file.read((char*)&ch, sizeof(ch));
        }
        if(flag==0)
        {
            
        redo:
            cin.ignore(1000,'\n');
            cout<<endl<<"I do not know how to answer that, would you like to teach me? (Yes or No) \n";
            cin.getline(choice,256);
            
            if(strcmp(uppercase(choice),"YES")==0)
            {
                file.close();
                file.open("chatttt.dat",ios::out|ios::in|ios::binary|ios::app);
                cout<<endl<<"Enter the appropriate response: \n";
                cin.getline(ch.out,256);
                strcpy(ch.in,inp);
                file.write((char*)&ch,sizeof(ch));
            }
            else if (strcmp(uppercase(choice),"NO")==0)
            {
                file.close();
    
                goto cont;
            }
            else
            {
                cout<<endl<<"Please enter only Yes or No \n";
                goto redo;
            }
        }


        file.close();
            
    }
cont:
    cin.ignore(1000,'\n');
    char ans[SIZE], cha[SIZE];
    cout<<endl<<"Would you like to continue?"<<endl;
    cin.getline(cha,SIZE);
    strcpy(ans,uppercase(cha));
    if(strcmp(ans,"YES")==0)
    {


        goto buff;
    }
    else if (strcmp(ans,"NO")==0)
    {
        cout<<endl<<"Goodbye!"<<endl;
        exit(0);
    }
    else
    {
        cout<<endl<<"Please enter only Yes or No"<<endl;
        goto cont;
    }


}


void addevent(char username[])
{
    event e;
    fstream file;
    file.open(username, ios::app|ios::in|ios::out|ios::binary);
    cin.ignore(1000,'\n');
    cout<<endl<<"\nEnter name of event:"<<endl;
    cin.getline(e.name,SIZE);
    cout<<endl<<"\nEnter time of event(24 hr format):"<<endl;
    cin>>e.time;
    cout<<endl<<"\nEnter date of event(dd mm yy):"<<endl;
    cin>>e.date;
    cout<<endl<<"\nEnter details for event:"<<endl;
    cin.ignore(1000,'\n');
    cin.getline(e.details,SIZE);
    file.write((char*)&e, sizeof(e));
    file.close();
}
void displayevents(char username[])
{
    event e;
    fstream file;
    file.open(username, ios::in|ios::out|ios::binary);
    file.seekg(0);
    file.read((char*)&e, sizeof(e));
    if(file.eof())
    {
        cout<<"Empty file.";
    }
    while(!file.eof())
    {
        
        cout<<endl<<"\nName of event:"<<endl;
        cout<<e.name<<endl;
        cout<<endl<<"\nTime of event:"<<endl;
        cout<<e.time<<endl;
        cout<<endl<<"\nDate of event:"<<endl;
        cout<<e.date<<endl;
        cout<<endl<<"\nDetails for event:"<<endl;
        cout<<e.details<<endl;
        file.read((char*)&e, sizeof(e));
    }
    
    file.close();
    
}
void deleteevent(char username[])
{
    event e,temp;
    char inp[SIZE];
    fstream file;
    file.open(username, ios::in | ios::out | ios::binary);
    fstream filetemp;
    filetemp.open("tempp.dat", ios::out|ios::binary);
    
    if(!file)
    {
        cout<<endl<<"File not found."<<endl;
        exit(0);
    }
    if(!filetemp)
    {
        cout<<endl<<"File not found."<<endl;
        exit(0);
    }
    cin.ignore(1000,'\n');
    cout<<endl<<"Enter name of event to be deleted:"<<endl;
    cin.getline(inp,SIZE);
    file.read((char*)&e,sizeof(e));
    if(file.eof())
    {
        cout<<endl<<"Empty file."<<endl;
    }
    else
    {
        while(!file.eof())
        {
        
            if(strcmp(inp,e.name)!=0)
            {
            
                filetemp.write((char*)&e, sizeof(e));
            }
            else
            {
                
                temp=e;
            }
            file.read((char*)&e, sizeof(e));
        }
        cout<<endl<<temp.name<<" is deleted"<<endl;
        file.close();
        filetemp.close();
        remove(username);
        rename("tempp.dat",username);
    }
}
void modify(char username[])                #modifying the events stored in the list 
{
    event e,g;
    char inp[SIZE];
    fstream file;
    file.open(username,ios::beg| ios::in | ios::out | ios::binary);
    
    if(!file)
    {
        cout<<"File not found."<<endl;
        exit(0);
    }
    int num=0;
    cin.ignore(1000,'\n');
    cout<<endl<<endl<<"Enter name of event to be modified:"<<endl;
    cin.getline(inp,SIZE);
    cout<<endl<<endl<<"Enter new record"<<endl;
    cin.ignore(1000,'\n');
    cout<<endl<<endl<<"\nEnter name of event:"<<endl;
    cin.getline(e.name,SIZE);
    cout<<endl<<endl<<"\nEnter time of event(24 hr format):"<<endl;
    cin>>e.time;
    cout<<endl<<endl<<"\nEnter date of event(dd mm yy):"<<endl;
    cin>>e.date;
    cin.ignore(1000,'\n');
    cout<<endl<<endl<<"\nEnter details for event:"<<endl;
    cin.getline(e.details,SIZE);
    file.read((char*)&g, sizeof(g));
    while(!file.eof())
    {
        
        if(strcmp(inp,g.name)==0)
        {
            
            goto place;
            
        }
        num++;
        file.read((char*)&e, sizeof(e));
        
    }
place:
    
    file.seekp(num*sizeof(e), ios::beg);
    file.write((char*)&e, sizeof(e));
    
    
    
    file.close();
}


void cscr()
{
    for(int i=0; i<100; i++)
    {
        cout<<endl;
    }
    cout<<"                      ▀█████████▄   ███     ███      ▄████████    ▄████████       ▄██████    ▄█    █▄     ▄████████     ▀█████████▄  ▀█████████▄    ▄██████▄    ▀█████████▄  "<<endl;
    cout<<"                       ███    ███   ███     ███   ███    ███   ███    ███      ███    ███   ███    ███     ███    ███       ███       ███    ███   ███     ███      ███       "<<endl;
    cout<<"                       ███    ███   ███     ███   ███    █▀    ███    █▀       ███          ███    ███     ███    ███       ███       ███    ███   ███     ███      ███       "<<endl;
    cout<<"                       ▄███▄▄▄██▀   ███     ███  ▄███▄▄▄      ▄███▄▄▄          ███         ▄███▄▄▄▄███▄▄   ███    ███       ███       ▄███▄▄▄██▀   ███     ███      ███       "<<endl;
    cout<<"                      ▀▀███▀▀▀██▄   ███     ███ ▀▀███▀▀▀     ▀▀███▀▀▀          ███        ▀▀███▀▀▀▀███▀    ▀█████████       ███       ▀███▀▀▀██▄   ███     ███      ███       "<<endl;
    cout<<"                        ███    ██▄  ███     ███   ███          ███             ███          ███    ███     ███    ███       ███        ███    ██▄  ███     ███      ███       "<<endl;
    cout<<"                        ███    ███  ███     ███   ███          ███             ███    ███   ███    ███     ███    ███       ███        ███    ███  ███     ███      ███        "<<endl;
    cout<<"                      ▄█████████▀    █████████   ███          ███               ████████▀   ███    ███     ███    ███      ▄███       ▄█████████▀    ▀██████▀       ███       "<<endl;
    
    for(int i=0; i<30; i++)
    {
        cout<<endl;
    }
}
