#include<iostream>
using namespace std;
#include<vector>
#include<ctime>
#include<algorithm>
#include<string>

enum States{UP, DOWN};
enum Floor{FIRST=1, SECOND, THIRD, FOURTH};

class Building
{
    public:
    virtual string getlocation() const;
    Building();
    ~Building();
    private:
    string buildingname;
};

string Building::getlocation() const
{
    return buildingname;
}

Building::Building()
{
    cout<<"Please enter the name of the building: ";
    getline(cin, buildingname);
}

Building::~Building()
{
    cout<<"Thanks for visiting "<<getlocation()<<". Please come again soon!"<<endl;
}

class Person
{
    public:
    bool authorisationstatus();
    Person();
    private:
    string name;
    char authorisation;
};

Person::Person()
{
    cout<<"Please enter the name of the person entering the building: ";
    getline(cin, name);
}

bool Person::authorisationstatus()
{
    cout<<"Does the person have authorisation? If yes, enter y. Else, enter anything else: ";
    cin>>authorisation;
    if(authorisation=='y'||authorisation=='Y')
    {
        cout<<"Authorisation confirmed for "<<name<<". Please enter!"<<endl;
        return 1;
    }
    else
    {
        cout<<"Authorisation denied or not found for "<<name<<". Kindly leave the building."<<endl;
        return 0;
    }
}

class Elevator : public Building, public Person
{
    public:
    int getfloor() const;
    virtual string getlocation() const;
    Elevator();
    ~Elevator();
    void setfloor();
    void floorsetter(int);
    Floor getfloorval(int);
    private:
    vector<int> floorselections;
    States state;
    Floor floor;
    string elevatorlocation;
};

string Elevator::getlocation() const
{
    return elevatorlocation;
}

Elevator::~Elevator()
{
    cout<<endl<<endl<<"Thank you for using the elevator located at "<<elevatorlocation<<"! Please come again soon!"<<endl;
}

Elevator::Elevator() : Building(), Person()
{
    cout<<"Please enter the location of the elevator being accessed: ";
    getline(cin, elevatorlocation);
    if(authorisationstatus()==0)
    {
        exit(1);
    }
    cout<<"Please enter u if you are looking to go up, or press d if you want to go down: ";
    char decisionupdown;
    cin>>decisionupdown;
    if(decisionupdown=='u'||decisionupdown=='U')
    {
        state=UP;
    }
    else if(decisionupdown=='d'||decisionupdown=='D')
    {
        state=DOWN;
    }
    else
    {
        cout<<"Wrong input! Kindly try gain!"<<endl;
        while(decisionupdown!='u'&&decisionupdown!='U'&&decisionupdown!='d'&&decisionupdown!='D')
        {
            cout<<"Please enter u if you are looking to go up, or press d if you want to go down: ";
            cin>>decisionupdown;
            if(decisionupdown!='u'&&decisionupdown!='U'&&decisionupdown!='d'&&decisionupdown!='D')
            {
                cout<<"Wrong input! Kindly try again!"<<endl;
            }
        }
        if(decisionupdown=='u'||decisionupdown=='U')
        {
            state=UP;
        }
        else if(decisionupdown=='d'||decisionupdown=='D')
        {
            state=DOWN;
        }
        cout<<"You have selected that you want to go ";
        if(state==UP)
        {
            cout<<"UP!"<<endl;
        }
        else
        {
            cout<<"DOWN!"<<endl;
        }
    }
    cout<<"What's the starting floor? Kindly enter: ";
    int pp;
    cin>>pp;
    floor=getfloorval(pp);
    cout<<"The current floor is Floor "<<floor<<"."<<endl;
}

Floor Elevator::getfloorval(int a)
{
    if(a==1)
    return FIRST;
    else if(a==2)
    return SECOND;
    else if(a==3)
    return THIRD;
    else if(a==4)
    return FOURTH;
}

void Elevator::floorsetter(int a)
{
    if(a==1)
    {
        floor=FIRST;
    }
    else if(a==2)
    {
        floor=SECOND;
    }
    else if(a==3)
    {
        floor=THIRD;
    }
    else if(a==4)
    {
        floor=FOURTH;
    }
}

int Elevator::getfloor() const
{
    if(floor==FIRST)
    {
        return 1;
    }
    else if(floor==SECOND)
    {
        return 2;
    }
    else if(floor==THIRD)
    {
        return 3;
    }
    else if(floor==FOURTH)
    {
        return 4;
    }
}

void Elevator::setfloor()
{
    if(floorselections.size()==4)
    {
        cout<<"Can't enter anymore floors since all are selected!"<<endl;
    }
    else
    {
        int selection;
        int remaining=4-floorselections.size();
        int pop=0;
        time_t startTime=time(nullptr);
        while(remaining>0)
        {
            time_t currentTime=time(nullptr);
            if(currentTime-startTime<5)
            {
                int check=0;
                cout<<"Enter a floor number please:";
                cin>>selection;
                if(selection==floor)
                {
                    continue;
                }
                for(int i=0;i<floorselections.size();i++)
                {
                    if(floorselections[i]==selection)
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0)
                {
                    if(floorselections.size()==4)
                    {
                        cout<<"Floor already selected!"<<endl;
                    }
                    else
                    {
                        floorselections.push_back(selection);
                        remaining--;
                    }
                }
            }
            else
            {
                cout<<"Doors are closing!"<<endl;
                pop=1;
                break;
            }
        }
        if(pop==0)
        {
            cout<<"All buttons have been pressed!"<<endl;
        }
    }
    int present=0;
    if(floor==FOURTH)
    {
        state=DOWN;
    }
    else if(floor==FIRST)
    {
        state=UP;
    }
    else if(floor==SECOND||floor==THIRD)
    {
        int countup=0;
        if(state==UP)
        {
            for(int i=0;i<floorselections.size();i++)
            {
                if(floorselections[i]>floor)
                {
                    countup++;
                    break;
                }
            }
            if(countup==0)
            {
                state=DOWN;
            }
        }
        if(state==DOWN)
        {
            int countdown=0;
            for(int i=0;i<floorselections.size();i++)
            {
                if(floorselections[i]<floor)
                {
                    countdown++;
                    break;
                }
                if(countdown==0)
                {
                    state=UP;
                }
            }
        }
    }
    int f=0;
    if(state==UP)
    {
        for(int i=1;i<=4;i++)
        {
            if(getfloorval(i)<=floor)
            {
                continue;
            }
            for(int j=0;j<floorselections.size();j++)
            {
                if(getfloorval(i)==floorselections[j])
                {
                    present=1;
                    f=i;
                    break;
                }
            }
            if(present==1)
            {
                this->floorsetter(f);
                floorselections.erase(remove(floorselections.begin(), floorselections.end(), f), floorselections.end());
                break;
            }
        }
    }
    if(state==DOWN)
    {
        for(int i=4;i>=1;i--)
        {
            if(getfloorval(i)>=floor)
            {
                continue;
            }
            for(int j=0;j<floorselections.size();j++)
            {
                if(getfloorval(i)==floorselections[j])
                {
                    present=1;
                    f=i;
                    break;
                }
            }
            if(present==1)
            {
                this->floorsetter(f);
                floorselections.erase(remove(floorselections.begin(), floorselections.end(), f), floorselections.end());
                break;
            }
        }
        
    }
}

int main()
{
    Elevator *ee;
    ee=new Elevator;
    ee->setfloor();
    cout<<"Elevator is moving...please wait..."<<endl;
    cout<<"Arrived at Floor "<<ee->getfloor()<<"."<<endl;
    cout<<"If you want to continue, please enter y, or press enter any other character to exit: ";
    char check;
    cin.clear();
    cin>>check;
    if(check!='y' && check!='Y')
    {
        delete ee;
        exit(1);
    }
    else
    {
        while(1)
        {
            ee->setfloor();
            cout<<"Elevator is moving...please wait..."<<endl;
            cout<<"Arrived at Floor "<<ee->getfloor()<<"."<<endl;
            cout<<"If you want to continue, please enter y, or press enter any other character to exit: ";
            char check;
            cin.clear();
            cin>>check;
            if(check!='y' && check!='Y')
            {
                delete ee;
                exit(1);
            }
        }
    }
}