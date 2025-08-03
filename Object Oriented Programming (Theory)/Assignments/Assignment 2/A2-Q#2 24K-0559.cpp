//24k-0559 Bazil-Uddin-Khan  
#include <iostream>
using namespace std;

class Ghost
{
    protected:
    string PlayerName;
    int Scarelevel;
    
    public:
    Ghost()
    {
        PlayerName = " ";
        Scarelevel =0;
    }
    
    Ghost(string playername, int scarelevel) : PlayerName(playername), Scarelevel(scarelevel) 
    {}
    
    int GetScareLevel()
    {
        return Scarelevel;
    }
    
    virtual void PerformHaunting()
    {
        cout << " Player Name " << PlayerName << " Should Haunt Visitors " << endl;
        
    }
    
    string GetName()
    {
        return PlayerName;
    }
    
    
    
   friend ostream& operator << (ostream& out,Ghost &ghost);
   
   Ghost operator+(Ghost & ghost)
   {
       return Ghost(PlayerName + "&" + ghost.PlayerName , Scarelevel + ghost.Scarelevel);
       
   }
  
};

ostream& operator << (ostream& out,Ghost &ghost)
{
        out << " Ghost Player Name is  "  << ghost.PlayerName << " Ghost Scare Level Is  " << ghost.Scarelevel << endl;
        return out;
        
}


class Poltergeists : virtual public Ghost
{
    public:
    Poltergeists()
    {}
    
    Poltergeists(string playername, int scarelevel ) : Ghost(playername,scarelevel)
    {}
    
    
     void PerformHaunting()
    {
        cout << "Player = " << PlayerName << " is  Poltergeists who Moves Objects " << endl;
    }
};

class Banshees : virtual public Ghost
{
    public:
    Banshees()
    {}
    
    Banshees(string playername, int scarelevel ) : Ghost(playername,scarelevel)
    {}
    
    void PerformHaunting()
    {
        cout << " Player = " << PlayerName << " who is (Banshees) Scream's Loudly " << endl;
    }
};



class ShadowGhosts : virtual public Ghost
{
    public:
    ShadowGhosts()
    {}
    
    
   ShadowGhosts(string playername, int scarelevel ) : Ghost(playername,scarelevel)
    {}
    
    void PerformHaunting()
    {
        cout << "Player Name " << PlayerName << " is (ShadowGhosts) who is to Whispher Creeply  " << endl;
    }
};

class HybridGhost : public ShadowGhosts, public Poltergeists
{
    public:
    HybridGhost()
    {}
    
    HybridGhost(string playername, int scarelevel ) : Ghost(playername,scarelevel),ShadowGhosts(playername,scarelevel), Poltergeists(playername,scarelevel)
    {}
    
    void PerformHaunting()
    {
        ShadowGhosts :: PerformHaunting();
        Poltergeists :: PerformHaunting();
    }
    
};


class HauntedHouse
{
    string HauntedHouseName;
    Ghost ** ghost;
    int count;
    
    public:
    HauntedHouse()
    {
        HauntedHouseName = " ";
        count =0;
        
    }
    HauntedHouse(string housename) : HauntedHouseName(housename),count(0)
    {
      ghost = new Ghost*[100];
    }
    
    void AddGhost(Ghost* ghosts) 
    {
        if (count < 100) 
        {
            ghost[count] = ghosts;
            count++;
        } 
        else
        {
            cout << " Sorry!. Haunted house is full!" << endl;
        }
    }
    

    void StartHaunting() 
    {
        cout << "Haunted House Name is =  " << HauntedHouseName << endl;
        for (int i = 0; i < count; i++)
        {
            ghost[i]->PerformHaunting();
        }

    }
    
    string GetHouseName()
    {
        return HauntedHouseName;
    }
    
    
    
};

class Visitor 
{
    private:
    
    string VisitorName;
    int BraveryLevel;
    
    public:
    Visitor()
    {
        VisitorName = " ";
        BraveryLevel = 0;
    }
    
    Visitor(string name, int level) : VisitorName(name),BraveryLevel(level)
    {}
    
    friend void Visit(Visitor visitors[],HauntedHouse & haunted,Ghost  * ghost1);
    
    string GetName()
    {
        return VisitorName;
    }
    
    int GetLevel()
    {
        return BraveryLevel;
    }
    
    
};

void Visit(Visitor visitors[], HauntedHouse &haunted, Ghost *ghosts[])
{
    cout << " Visitors Entering Our Haunted House : " << haunted.GetHouseName() << endl;

    for (int i = 0; i < 3; i++)  
    {
        cout << visitors[i].GetName() << "  is entering the haunted house " << endl;

        
        string braveryRange;
        if (visitors[i].GetLevel() >= 1 && visitors[i].GetLevel() <= 4)
        {
            braveryRange = "Cowardly";
        }
            
        else if (visitors[i].GetLevel() >= 5 && visitors[i].GetLevel() <= 7)
        {
            braveryRange = "Average";
        }
        
        else if (visitors[i].GetLevel() >= 8 && visitors[i].GetLevel() <= 10)
        {
            braveryRange = "Fearless";
        }

        cout << visitors[i].GetName() << " is " << braveryRange << endl;

        for (int j = 0; j < 4; j++)
        {
            int scareLevel = ghosts[j]->GetScareLevel();
            cout << ghosts[j]->GetName() << " is trying to scare them with a scare level of " << scareLevel  << endl;

            if (scareLevel < 5) 
            {
                cout << visitors[i].GetName() << " Ha Ha he says .is that all you got ?." << endl;
            }
            else if (scareLevel >= 5 && scareLevel <= 7) 
            {
                cout << visitors[i].GetName() << " Speaking with  shaky voice I am shivering. " << endl;
            }
            else 
            {
                cout << "Ah help " << visitors[i].GetName() << " is running away in fear " << endl;
            }
        }

        cout << endl;
    }
}

int main() 
{
    
    
    HauntedHouse house1("Borley Rectory");

    Ghost * ghost [4]
    =
    {
    new Poltergeists("Qasim", rand() % 10 + 1),
    new Banshees("Wasim", rand() % 10 + 1),
    new ShadowGhosts("Ali", rand() % 10 + 1),
    new HybridGhost("Farteen", rand() % 10 + 1) };
    
    cout << " Ghost Info " << endl;
    for (int i = 0; i < 4; i++) 
    {
    cout << *ghost[i];  
    }
    
    Ghost *upgradedGhost = new Ghost(*ghost[0] + *ghost[1]);

    cout << " New Upgraded Ghost Is  ";
    cout << *upgradedGhost; 
    

    house1.AddGhost(ghost[0]);
    house1.AddGhost(ghost[1]);
    house1.AddGhost(ghost[2]);
    house1.AddGhost(ghost[3]);
    
    cout << endl;
    cout << " _House 1  Visitors_ " << endl;
    cout << endl;


    Visitor visitors1[3] = {{"Saffora",6},{"Quba",2},{"Was",9}};
    
    Visit(visitors1, house1, ghost);

    
    
    HauntedHouse house2("Amit valley");
    
    cout << endl;
    cout << " _House 2 Visitors_ " << endl;
    
    house2.AddGhost(ghost[0]);
    house2.AddGhost(ghost[1]);
    house2.AddGhost(ghost[2]);
    house2.AddGhost(ghost[3]);
    
    Visitor visitors2[3] = {{"Saff",1},{"Qua",9},{"Ws",5}};
    
    Visit(visitors2, house2, ghost);
    
    
    HauntedHouse house3("Mystery");
    cout << endl;
    cout << " _House 3 Visitors_ " << endl;
    house3.AddGhost(ghost[0]);
    house3.AddGhost(ghost[1]);
    house3.AddGhost(ghost[2]);
    house3.AddGhost(ghost[3]);
    
    Visitor visitors3[3] = {{"Myste",6},{"Qua",2},{"Ws",9}};
    
    Visit(visitors3, house3, ghost);

    return 0;
}