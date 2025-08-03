// 24k-0559 BAZIL-UDDIN-KHAN

#include <iostream>
using namespace std;

class Ball
{
    private:
    int X;
    int Y;
    
    public:
    Ball()
    {
        X =0;
        Y =0;
    }
    void MethodMove(int Dx,int Dy)
    {
        this->X =  Dx;
        this->Y =  Dy;
    }
    void SetCoordinates()
    {
        X = 0;
        Y =0;
    }
    
    void GetPosition()
    {
        cout << " Current Position is (X,Y) " << X << " , " << Y << endl;
    }
    int GetX()
    {
        return X;
    }
    int GetY()
    {
        return Y;
    }
};

class Robot
{
    private:
    string Name;
    int TotalHits;
    int RobotX;
    int RobotY;
    int Y ;
    int X ; 
    Ball ball;
    
    public:
    Robot()
    {
        Name = " ";
        TotalHits =0;
        RobotX=0;
        RobotY=0;
        Y =0;
        X =0;
    }
    int CallX()
    {
        
        return (ball.GetX());
    }
    
    int Cally()
    {
       
        return (ball.GetY());
    }
    
    string GetName()
    {
        return Name;
    }
    
    void SetCoordinates()
    {
        X = 0;
        Y =0;
    }
    
    void SetName(string Name)
    {
        this->Name = Name;
    }
    
    int GetHits()
    {
        return TotalHits;
    }
    
    string UpDirection()
    {
        return "Up";
    }
    string DownDirection()
    {
        return "Down";
    }
    string LeftDirection()
    {
        return "Left";
    }
    string RightDirection()
    {
        return "Right";
    }
    
    void SetHits(int TotalHits)
    {
        this->TotalHits = TotalHits;
    }
    
    void HitBall(int &Ballx,int &Bally,const string &Direction,Ball &ball)
    {

        if(Direction == "Up")
        {
            this->Y = Y + Bally;
            this->X = X + Ballx;
            ball.MethodMove(X,Y);
            this->RobotX = X;
            this->RobotY = Y;
        }
        
        else if(Direction == "Down")
        {
            this->Y = Y - Bally;
            this->X = X - Ballx;
            ball.MethodMove(X,Y);
            this->RobotX = X;
            RobotY = Y;
        }
        
        else if(Direction == "Right")
        {
            this->X = X + Ballx;
            ball.MethodMove(X,Y);
            this->RobotX = X;
        }
        
       else if(Direction == "Left")
        {
            this->X = X - Ballx;
            ball.MethodMove(X,Y);
            this->RobotX = X;
        }
        else
        {
            cout << " Wrong Try " << endl;
        }
        TotalHits++;
    }

};

class Goal
{
    private:
    int X;
    int Y;
    
    public:
    Goal()
    {
        X =0;
        Y =0;
    }
    Goal(int X, int Y)
    {
        this->X = X;
        this->Y = Y;
    }
    void SetCoordinates()
    {
        this->X =0;
        this->Y =0;
    
    }
    int GetTargetX()
    {
        return X;
    }
    int GetTargetY()
    {
        return Y;
    }
    
    int  isGoalReached(int ballX, int ballY)
    {
        if(ballX == X && ballY == Y)
        {
            return 1;
        }
        
        else
        {
            cout << " Still Not Reached " << endl;
            return 0;
        }
        
    }
    
};

class Team
{
    private:
    string Name;
    Robot * robot ;
    int TeamNum; 
    int Teamhits;
    
    
    
    public:
    Team()
    {
        TeamNum =0;
        robot = new Robot[2];
        
    }
    
    void SetTeam(string Name)
    {
        this->Name = Name;
    }
    
   void SetTeamHits(int Teamhits)
    {
        this->Teamhits= Teamhits;
    }
    
    void CallRobot(Team * team)
    {
        Goal goal(3,3);
        Ball ball;
        
        for(int i =0; i < 2; i++)
        {
            string Name;
            cout << " Enter Robot Name . (like this Qasim11 etc withno gaps) " << endl;
            cin >> Name;
            robot[i].SetName(Name);
            int Teamhits =0;
            
           while(1)
            {
             if(goal.isGoalReached(ball.GetX(),ball.GetY()) == 1)
            {
                cout << " Your Goal Has Reached " << endl;
                ball.SetCoordinates();
                cout << " Robot : " << robot[i].GetName() << " Reached Goal in " << robot[i].GetHits() << " Times " << endl;
               robot[i].SetHits(Teamhits);
               team[i].SetTeamHits(Teamhits);
                TeamNum++;
                
                
                break;
            }
            else
            {
                int EnterHitx;
                cout << " Enter Hit x " << endl;
                cin >> EnterHitx;
                int EnterHity;
                cout << " Enter Hit Y " << endl;
                cin >> EnterHity;
                string Direction;
                cout << " Enter Direction(Up/Down/Left/Right) " << endl;
                cin >> Direction;
                robot[i].HitBall(EnterHitx,EnterHity,Direction,ball);
                 ball.GetPosition();
                 Teamhits++;
            }
          } 
        }
       
    }
    void SetTeam(int Teamhits)
    {
       this->Teamhits = Teamhits;
    }

    int GetTeam()
    {
        return Teamhits;
    }
    
    int TeamTotalHits(int i )
    {
        return (robot[i].GetHits());

    }
    ~Team() 
    {
        delete[] robot;
    }
    
};

class Game
{
    private:
    Team Teamone;
    Team Teamtwo;
    Goal Goalobject;
    Ball Ballobject;
    
    public:
    
    void startGame()
    {
        cout << " Start The Game " << endl;
    }
    
    void play(Team *team)
    {
        team->CallRobot(team);
    }
    
    void DeclareWinner(Team * team)
    {
         int TeamHitsone = team[0].GetTeam();
         int TeamHitstwo = team[1].GetTeam();
         Teamone.SetTeamHits(TeamHitsone);
         Teamtwo.SetTeamHits(TeamHitstwo);
         cout << " Teamone one hits  " << TeamHitsone << endl;
          cout << " Teamone Two hits  " <<  TeamHitstwo << endl;


        if(Teamone.GetTeam() < Teamtwo.GetTeam())
        {
            cout << " Congratulations Team 1 has Won with Total : " <<  Teamone.GetTeam() << " Hits " << endl;
        }
        else if(Teamtwo.GetTeam() < Teamone.GetTeam())
        {
            cout << " Congratulations Team 2 has Won with Total : " <<  Teamtwo.GetTeam() << " Hits " << endl;
        }
        else
        {
            cout << " Oh it's a tie " ;
        }
    }
    
    
};
int main() 
{
   
    Game GAME;
    GAME.startGame();
    Team *team = new Team[2];
    for(int i =0; i < 2; i++)
    {
        string Name;
        cout << " Enter Team Name. (like this Qasim11 etc withno gaps)" << endl;
        cin >> Name;
        team[i].SetTeam(Name);
    }
    int Index =0;
    for(int i =0; i < 1; i++)
    {
        GAME.play(team);
        
    }
    GAME.DeclareWinner(team);
    
    delete [] team;
    

    return 0;
}