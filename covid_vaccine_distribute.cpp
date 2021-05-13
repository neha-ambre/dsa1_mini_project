#include <iostream>
#include<string>
using namespace std;

//created class node
class node
{
    //instance variables
    int age,diseases;
    int priority=0;
    string name;
    int adhar_No;
    node *next;

public:
    //parameterized constructor
    //initialized all variables of class node
    node(string s,int a,int n,int p,int ad)
    {
        name=s;
        age=a;
        diseases=n;
        adhar_No=ad;
        priority=p;
        next=NULL;
    }
    //used friend function for accessing members of class PQ
    friend class PQ;
};

//created class PQ
class PQ
{
    //instance variables
    node *front;
public:
    //default constructor
    PQ()
    {
        front=NULL;
    }

    //function for adding user into the priority list
    void add(string,int,int,int);

    //function returns priority
    int get_priority(int,int);
    bool isEmpty();
    void display();

    //function for checking if user is 1st person for getting appointment
    int search_if_front(int);

    //deleting person details after vaccinating
    node* del();

    //finding how many people are in front of any particular person
    int no_pep_bef(int);
    int search_in_queue(int);
};

//function for adding user details to queue according to priority number
void PQ::add(string nm,int age,int dis,int adharNo)
{
    int priority_number;

    //invoking function which returns priority for the user
    priority_number=get_priority(age,dis);

    //created new node for storing details of user in queue
    node *temp=new node(nm,age,dis,priority_number,adharNo);

    if(front==NULL)
        front=temp;
    else
    {
        node *ptr=front;
        node *prev;

        if(front -> priority > priority_number)
        {
            temp->next=front;        //if 1st person have lesser priority than the user
            front=temp;
        }
        else{
            //moving pointer till user has less priority than the pointer pointing the person
            while(ptr!=NULL && ptr->priority <= priority_number)
            {
                prev=ptr;
                ptr=ptr->next;
            }
            temp->next=ptr;    //
            prev->next=temp;   //
        }
    }
}

//function for returning priority on the basis of age and chronic diseases
int PQ::get_priority(int age_p,int dis_p)
{
    int s=0,d=0;
    //switch used here for returning priority on the basis of age
    switch(age_p)
    {
        // for age category from 18 to 40
        case 18 ... 40 :
            s=1;
            break;

        // for age category from 41 to 60
        case 41 ... 60 :
            s=2;
            break;

        // for age category from 61 to 120
        case 61 ... 120 :
            s=7;
            break;
    }

    //switch used here for returning priority on the basis of chronic diseases
    switch(dis_p)
    {
        //if user has 0 diseases
        case 0:
            d=0;
            break;
        //if user has 1 diseases
        case 1:
            d=1;
            break;
        //if user has 2 diseases
        case 2:
            d=2;
            break;
        //if user has 3 diseases
        case 3 ... 10:
            d=3;
            break;
    }

    //calculating total priority
    int sum_p, priority;
    sum_p = s + d;

    switch (sum_p)
    {
        //first priority
        case 6 ... 10:
            priority=1;
            break;
        //second priority
        case 5:
            priority=2;
            break;
        //third priority
        case 4:
            priority=3;
            break;
        //fourth priority
        case 3:
            priority=4;
            break;
        //fifth priority
        case 2:
            priority = 5;
            break;
        //sixth priority
        case 1:
            priority = 6;
            break;
    }
    //returning priority count
    return priority;
}

//function for checking that queue is full or not
bool PQ::isEmpty()
{
    if(front==NULL)
        return true;
    else
        return false;
}

//function for displaying list of registered people
void PQ::display()
{
    node *ptr=front;
    if(front==NULL)
    {
        cout<<"\nList is empty"<<endl;
        return;
    }
    cout<<"\n\n\t\t\t\t\t\t\tName\t\tAge\t\tNo. of diseases\t\tAdhar No.\n";
    cout<<"\t\t\t\t\t------------------------------------------------------------------------------------------";
    while(ptr!=NULL)
    {
        cout<<"\n\t\t\t\t\t\t\t"<<ptr->name<<"\t\t"<<ptr->age<<"\t\t  "<<ptr->diseases<<"\t\t\t"<<ptr->adhar_No<<endl;
        ptr=ptr->next;
    }
    cout<<"\t\t\t\t\t-----------------------------------------------------------------------------------------";

}

//function for checking if user is first person for getting appointment for vaccination
int PQ::search_if_front(int adNo)
{
    int r,flag=0;
    node *ptr=front;
    if(front==NULL)
        return 0;
    else
    {
        if(front->adhar_No==adNo)
        return 1;
    }
}

//function for deleting user details after vaccination
node* PQ::del()
{
        node *ptr=front;
        front=front->next;
        return ptr;
}

//function for finding how many people name are in front of any particular person
int PQ::no_pep_bef(int adNo)
{
       node *p=front;
       int w=0;
       while(p->adhar_No!=adNo)
       {
           w++;
           p=p->next;
       }
       return w;
}

//function for finding user is present in queue or not
int PQ::search_in_queue(int adNo)
{
    node *ptr=front;
    int flag=0;
    while( ptr->next!=NULL && ptr->adhar_No!=adNo )
    {
        ptr=ptr->next;
        if(ptr->adhar_No==adNo)
        {
            flag=1;
        }
    }
    if(flag==1 || ptr->adhar_No==adNo)
        return 1;
    else if(ptr->next==NULL)
        return 0;
}

//node class for suppliers class
class node_for_supp
{
    //instance variables
    string company_Name;
    string contact_No;
    //string vaccineType;
    int total_Avlbl_Vacc;
    node_for_supp *link;
public:
    //default constructor
    node_for_supp()
    {

    }
    //parameterized constructor
    node_for_supp(string cname,string cno,int tavacc)
    {
        company_Name=cname;
        contact_No=cno;
        total_Avlbl_Vacc=tavacc;
        link=NULL;
    }
    //used friend function for accessing members of class suppliers
    friend class suppilers;
};

//created class suppliers
class suppilers
{
    //instance variables
    node_for_supp *head;
public:
    //functions declaration
    int supp_accept(string,string);
    //void sdisplay();
    //default constructor
    suppilers()
    {
        head=NULL;
    }
};

//function for accepting suppliers details and adding to list
int suppilers::supp_accept(string company_Name, string contact_No)
{
    //variable declaration
    int no;
    int total_Avlbl_Vacc=0;
    string ch;

    //created new node for storing suppliers details
    node_for_supp *newnode=new node_for_supp(company_Name,contact_No,total_Avlbl_Vacc);
    node_for_supp *temp;

    //total vaccines input
    cout<<"\n\t\t\t\t\t\t\t Enter total no of vaccines you can provide to us : ";
    cin>>total_Avlbl_Vacc;

    //adding to linked list
    newnode->link=NULL;
    if(head==NULL)
        head=newnode;
    else{
        temp=head;
        while(temp->link!=NULL)
            {
                temp=temp->link;
            }
        temp->link=newnode;
    }
    return total_Avlbl_Vacc;    //returning total number of available vaccines
}

//created class Center
class Center
{
    //instance variables
    string center_Name;
    int center_No;
public:
      int no_Of_Vacc;  //no of vaccines
    //object of PQ class
    PQ p;
    //default constructor
    Center()
    {
        no_Of_Vacc=0;
    }
    //parameterized constructor
    Center(string n,int cn)
    {
        //intialized all variables of class Center
        center_Name=n;
        center_No=cn;
        no_Of_Vacc=0;

        //added some objects of hard-coded values to priority queue PQ
        p.add("anjali",21,1,123);
        p.add("rahul",34,2,234);
        p.add("raj",60,3,345);
        p.add("simaran",45,4,456);
        p.add("esha",50,1,567);
        p.add("naina",65,2,678);
        p.add("gayatri",31,3,789);
        p.add("hina",80,4,321);
        p.add("isha",25,1,423);
        p.add("janvhi",18,2,756);
        p.add("kiran",41,3,543);
        p.add("lina",45,4,645);

    }

    //functions declaration
    int add_Vacc(int);
    void appointment(int);
};

//function for adding vaccines to total count which are not used yet
int Center::add_Vacc(int half_Of_Vacc)
{
        no_Of_Vacc = no_Of_Vacc + half_Of_Vacc;
        return no_Of_Vacc;
}
void Center::appointment(int ad)  //arguments are queue of people, queue of dates, no of vaccines,
{
    int x,s=0;
    node *ptr;
    int is_name_in_queue;
    if(no_Of_Vacc==0)
    {
        cout<<"\n\t\t\t\t\t-------------------------------------------------------------------------------------------------------\n";
        cout<<"\n\t\t\t\t\t\t\t\t   Sorry! No vaccines available at this centre :(\n\t\t\t\t\t\t\t\t   Please check availability at the other centre!"<<endl;
        return;
    }
    while(no_Of_Vacc!=0)   //till no of vaccines not becomes 0
    {
        s=p.search_if_front(ad);  //finding if the user is first in the queue
        if(s==1)
        {
            no_Of_Vacc--;
            p.display();
            p.del(); //deleting the user from the queue
            cout<<"\n\n\n\t\t\t\t\t\t      Your appointment is done.If you're in the first half of the list,\n\t\t\t\t\t\t       then your appointment is scheduled on 19th May 2021, Wednesday!"<<endl;
            cout<<"\n\t\t\t\t\t  If your name is in the remaing half, then your appointment is scheduled on 20th May 2021, Thursday!\n\n\t\t\t\t\t\t\t  Vaccine slots will be given on first come, first serve basis."<<endl;
            cout<<"\n\t\t\t\t\t\t\t\t\tSTAY HOME, STAY SAFE!\n"<<endl;
            break;
        }
        ptr=p.del();   //if user is not the 1st then moving to next person after considering giving vaccine
        no_Of_Vacc--;      //decresing vaccine no by 1
        if(p.isEmpty())   //if queue is empty then getting out of the loop
            break;

    }
    is_name_in_queue=p.search_in_queue(ad);
    if(s!=1)
    {//if user is not first
        x=p.no_pep_bef(ad);   //finding no of people before user
    if(x==0 && is_name_in_queue==1)    //if there is no one infront of user
        cout<<"Your appointment will be booked as soon as vaccines are available\nYou will be notified when they become available"<<endl;  //giving appointment to user
    else if(x>0 && is_name_in_queue==1)
        {
            cout<<"\n\t\t\t\t\t   ---------------------------------------------------------------------------------------";
            cout<<"\n\n\t\t\t\t\t\t\t\t   Sorry! Not enough vaccines available..\n\t\t\t\t\t\t\t\t    Hence you've been placed in queue.\n\t\t\t\t\t\t\t\t     There are "<<x<<" people before you"<<endl;   //if there are people infront of user and no of vaccines are 0
            cout<<"\n\t\t\t\t\t-----------------------------------------------------------------------------------------------";
            p.display();
            cout<<"\n\n\t\t\t\t\t\t  Do not register at this centre for the next few days, as we're out of vaccines.\n\t\t\t\t\t\t\t You will be notified, according to your number in the queue,\n\t\t\t\t\t\t\t    as soon as the new stock arrives.. Till then, STAY SAFE!"<<endl;
        }
    }
}
int main()
{
    //created objectArray  of class Center
    Center c[5];
    //created object of class suppliers
    suppilers s;
    //Adding objects to array
    c[0]=Center("Swarget",1);
    c[1]=Center("Katraj",2);

    //variables declaration
    int ch,choice, center_choice;
    int no_vacc, total_count_of_dis;
    string user_name;
    int user_age, half_vacc, adharNo;
    int max_register=4;
    string company_Name, contact_No;

    cout<<"\n\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *";
        cout<<"\n\n\t\t\t   * * * * * * * * * * * * * "<<
        " Welcome to the BRAND NEW Covid-19 Vaccine distribution portal !! * * * * * * * * * * * * * * "<<
        "\n\t\t\t\n\t\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n";

    do
    {
        cout<<"\n\n\n\t\t\t\t\t\t  Press '1' if you're a supplier, & '2' if you want to register for vaccine."<<endl;
        //menu
        cout<<"\n\n\t\t\t\t\t\t\t\t\t1. Supplier\n\t\t\t\t\t\t\t\t\t2. Register for vaccination ( only 18+ )\n";
        cout<<"\n\t\t\t\t\t\t\t\t\tEnter your choice : ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"\n\n\t\t\t\t\t\t---------------------------+ SUPPLIER DETAILS +--------------------------\n";
                //accepting supplier details
                //company name
                cout<<"\n\t\t\t\t\t\t\t\t\tEnter company name : ";
                cin>>company_Name;
                //contact no
                cout<<"\t\t\t\t\t\t\t\t\tContact no. : ";
                cin>>contact_No;

                //invoking supp_accept function for adding supplier details to list
                no_vacc=s.supp_accept(company_Name,contact_No);

                //finding half of total count of vaccines
                half_vacc=no_vacc/2;

                //adding half of total vaccines to each centers
                c[0].add_Vacc(half_vacc);              //adding to center Swarget
                c[1].add_Vacc(no_vacc - half_vacc);     //adding to center Katraj

                break;

            case 2:
                cout<<"\n\n\t\t\t\t\t\t\t\t\t   * SUCCESS !! *\n\t\t\t\t\t\t\t      You have successfully logged into your account !\n";

                cout<<"\n\t\t\t\t\t\t  +------------------------------------------------------------------------+";
                cout<<"\n\t\t\t\t\t\t  |         You can only register 4 people, through 1 account.\t\t   |";
                cout<<"\n\t\t\t\t\t\t  |  You can proceed to register a person till you reach the maximum limit.|";
                cout<<"\n\t\t\t\t\t\t  +------------------------------------------------------------------------+";

                //accepting user details
                cout<<"\n\n\n\t\t\t\t\t\t\t\t\tEnter name : ";   //user name
                getline(cin,user_name);
                getline(cin,user_name);
                //age
                cout<<"\t\t\t\t\t\t\t\t\tEnter age : ";
                cin>>user_age;
                //adhar number
                cout<<"\t\t\t\t\t\t\t\t\tEnter Adhar Number : ";
                cin>>adharNo;

                //checking eligibility of users under 18 age for vaccination
                if( user_age < 18 )
                {
                    cout<<"\n\n\t\t\t\t\t\t\t\t    >>>>> Vaccination for under 18 not allowed .. <<<<<"<<endl;
                    break;
                }

                //accepting count of diseases a user has.
                cout<<"\n\t\t\t\t\t\t\t\t     Enter Number of chronic Diseases you have\n\t\t\t\t\t\t\t( eg. High BP, Diabetes, Arthritis, Heart disease, Asthma, etc ) : ";
                cin>>total_count_of_dis;

                //displaying vaccination centers list for user
                cout<<"\n\t\t\t\t\t\t\t\t    -: Choose the center nearest to you :- \n\t\t\t\t\t\t\t\t\t\t";
                cout<<"1. Swargate(Vaccines avialable:"<<c[0].no_Of_Vacc<<")\n\t\t\t\t\t\t\t\t\t\t2. Katraj(Vaccines avialable:"<<c[1].no_Of_Vacc<<")\n\t\t\t\t\t\t\t\t\t    Your choice : ";
                cin>>center_choice;

                switch(center_choice)
                {
                    case 1:
                        //for center Swargate
                        //adding user details to queue
                        c[0].p.add(user_name,user_age,total_count_of_dis,adharNo);

                        //adding adhar number to queue for getting appointment
                        c[0].appointment(adharNo);

                        break;

                    case 2:
                        //for center Katraj
                        //adding user details
                        c[1].p.add(user_name,user_age,total_count_of_dis,adharNo);

                        //adding adhar number to queue for getting appointment
                        c[1].appointment(adharNo);

                        break;

                    default:
                        cout<<"\n\n\t\t\t\t\t\t\t\t       >>>>>>> Invalid input.. <<<<<<<\n";
                }
                max_register--;
                if(max_register==0)
                {
                    cout<<"\n\t\t\t\t\t\t\t\t  >>>>>>>> Sorry, you have reached your limit.\nYou can only register for 4 people from 1 account <<<<<<<<\n";
                }
                break;

            default:
                cout<<"\n\n\t\t\t\t\t\t\t\t       >>>>>>> Invalid input.. <<<<<<<\n";
        }
        cout<<"\n\t\t\t--------------------------------------------------------------------------------------------------------------------------------\n";
        cout<<"\n\t\t\t\t\t\t\t    Do you want to continue ?  Enter 1 to continue. ";
        cin>>choice;
        cout<<"\n\t\t\t-----------------------------------------------------------------------------------------------------------------------------\n";

    }while(choice==1);

    return 0;
}
/*Priority queue before taking input:
Name    Age     No of diseases  Adhar no        Priority
naina   65      2               678             1
hina    80      4               321             1
raj     60      3               345             2
simaran 45      4               456             2
kiran   41      3               543             2
lina    45      4               645             2
gayatri 31      3               789             3
rahul   34      2               234             4
esha    50      1               567             4
janvhi  18      2               756             4
anjali  21      1               123             5
isha    25      1               423             5
*/
/*Sample output:

                        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *

                           * * * * * * * * * * * * *  Welcome to the BRAND NEW Covid-19 Vaccine distribution portal !! * * * * * * * * * * * * * *

                        * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *



                                                  Press '1' if you're a supplier, & '2' if you want to register for vaccine.


                                                                        1. Supplier
                                                                        2. Register for vaccination ( only 18+ )

                                                                        Enter your choice : 1


                                                ---------------------------+ SUPPLIER DETAILS +--------------------------

                                                                        Enter company name : company_a
                                                                        Contact no. : 543634

                                                         Enter total no of vaccines you can provide to us : 13

                        --------------------------------------------------------------------------------------------------------------------------------

                                                            Do you want to continue ?  Enter 1 to continue. 1

                        -----------------------------------------------------------------------------------------------------------------------------



                                                  Press '1' if you're a supplier, & '2' if you want to register for vaccine.


                                                                        1. Supplier
                                                                        2. Register for vaccination ( only 18+ )

                                                                        Enter your choice : 2


                                                                           * SUCCESS !! *
                                                              You have successfully logged into your account !

                                                  +------------------------------------------------------------------------+
                                                  |         You can only register 4 people, through 1 account.             |
                                                  |  You can proceed to register a person till you reach the maximum limit.|
                                                  +------------------------------------------------------------------------+


                                                                        Enter name : priya
                                                                        Enter age : 20
                                                                        Enter Adhar Number : 412

                                                                     Enter Number of chronic Diseases you have
                                                        ( eg. High BP, Diabetes, Arthritis, Heart disease, Asthma, etc ) : 0

                                                                    -: Choose the center nearest to you :-
                                                                                1. Swargate(Vaccines avialable:6)
                                                                                2. Katraj(Vaccines avialable:7)
                                                                            Your choice : 1

                                           ---------------------------------------------------------------------------------------

                                                                   Sorry! Not enough vaccines available..
                                                                    Hence you've been placed in queue.
                                                                     There are 6 people before you

                                        -----------------------------------------------------------------------------------------------

                                                        Name            Age             No. of diseases         Adhar No.
                                        ------------------------------------------------------------------------------------------
                                                        gayatri         31                3                     789

                                                        rahul           34                2                     234

                                                        esha            50                1                     567

                                                        janvhi          18                2                     756

                                                        anjali          21                1                     123

                                                        isha            25                1                     423

                                                        priya           20                0                     412
                                        -----------------------------------------------------------------------------------------

                                                  Do not register at this centre for the next few days, as we're out of vaccines.
                                                         You will be notified, according to your number in the queue,
                                                            as soon as the new stock arrives.. Till then, STAY SAFE!

                        --------------------------------------------------------------------------------------------------------------------------------

                                                            Do you want to continue ?  Enter 1 to continue. 1

                        -----------------------------------------------------------------------------------------------------------------------------



                                                  Press '1' if you're a supplier, & '2' if you want to register for vaccine.


                                                                        1. Supplier
                                                                        2. Register for vaccination ( only 18+ )

                                                                        Enter your choice : 2


                                                                           * SUCCESS !! *
                                                              You have successfully logged into your account !

                                                  +------------------------------------------------------------------------+
                                                  |         You can only register 4 people, through 1 account.             |
                                                  |  You can proceed to register a person till you reach the maximum limit.|
                                                  +------------------------------------------------------------------------+


                                                                        Enter name : tina
                                                                        Enter age : 67
                                                                        Enter Adhar Number : 512

                                                                     Enter Number of chronic Diseases you have
                                                        ( eg. High BP, Diabetes, Arthritis, Heart disease, Asthma, etc ) : 3

                                                                    -: Choose the center nearest to you :-
                                                                                1. Swargate(Vaccines avialable:0)
                                                                                2. Katraj(Vaccines avialable:7)
                                                                            Your choice : 2


                                                        Name            Age             No. of diseases         Adhar No.
                                        ------------------------------------------------------------------------------------------
                                                        tina            67                3                     512

                                                        raj             60                3                     345

                                                        simaran         45                4                     456

                                                        kiran           41                3                     543

                                                        lina            45                4                     645

                                                        gayatri         31                3                     789

                                                        rahul           34                2                     234

                                                        esha            50                1                     567

                                                        janvhi          18                2                     756

                                                        anjali          21                1                     123

                                                        isha            25                1                     423
                                        -----------------------------------------------------------------------------------------


                                                      Your appointment is done.If you're in the first half of the list,
                                                       then your appointment is scheduled on 19th May 2021, Wednesday!

                                          If your name is in the remaing half, then your appointment is scheduled on 20th May 2021, Thursday!

                                                          Vaccine slots will be given on first come, first serve basis.

                                                                        STAY HOME, STAY SAFE!


                        --------------------------------------------------------------------------------------------------------------------------------

                                                            Do you want to continue ?  Enter 1 to continue. 1

                        -----------------------------------------------------------------------------------------------------------------------------



                                                  Press '1' if you're a supplier, & '2' if you want to register for vaccine.


                                                                        1. Supplier
                                                                        2. Register for vaccination ( only 18+ )

                                                                        Enter your choice : 2


                                                                           * SUCCESS !! *
                                                              You have successfully logged into your account !

                                                  +------------------------------------------------------------------------+
                                                  |         You can only register 4 people, through 1 account.             |
                                                  |  You can proceed to register a person till you reach the maximum limit.|
                                                  +------------------------------------------------------------------------+


                                                                        Enter name : mina
                                                                        Enter age : 47
                                                                        Enter Adhar Number : 623

                                                                     Enter Number of chronic Diseases you have
                                                        ( eg. High BP, Diabetes, Arthritis, Heart disease, Asthma, etc ) : 4

                                                                    -: Choose the center nearest to you :-
                                                                                1. Swargate(Vaccines avialable:0)
                                                                                2. Katraj(Vaccines avialable:4)
                                                                            Your choice : 2
Your appointment will be booked as soon as vaccines are available
You will be notified when they become available

                        --------------------------------------------------------------------------------------------------------------------------------

                                                            Do you want to continue ?  Enter 1 to continue. 2

                        -----------------------------------------------------------------------------------------------------------------------------
*/

