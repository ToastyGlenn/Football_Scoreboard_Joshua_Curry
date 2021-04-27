#ifndef CLASS_H
#define CLASS_H

using namespace std;

class Team
{
  private:
    int score; 
    bool homeStatus; 
    string teamName;
    string cityName;
    int shotsOnGoal; 
    string coachName; 
  public:
      Team() //default constructor 
      {
        score = 0; 
        homeStatus = false; //visitor = false, home = true
        teamName = "[Update Team]";
        shotsOnGoal = 0;
        coachName = "[Update Coach]";
        cityName = "[Update City]";
      }
      void setScore(int s) { score = s; }
      void setHomeStatus(bool hs) { homeStatus = hs; }
      void setTeamName(string tn) { teamName = tn; }
      void setCityName(string cn) { cityName = cn; }
      void setShotsOnGoal(int sog) { shotsOnGoal = sog; }
      void setCoachName(string sCN) { coachName = sCN; }
      int getScore() const { return score; }
      bool getHomeStatus() const { return homeStatus; }
      string getTeamName() const { return teamName; }
      string getCityName() const { return cityName; }
      int getShotsOnGoal() const { return shotsOnGoal; }
      string getCoachName() const { return coachName; }
};

class Scoreboard
{
  private:
    int half; 
    Team home; // object that is a member of another object
    Team visitor; 
  public: 
    Scoreboard()
    {
      half = 0; 
    }  
    void setHalf(int h) { half = h; }
    void setHome(Team hSet) { home = hSet; }
    void setVisitor(Team vSet) { visitor = vSet; }
    int getHalf() const { return half; }
    Team getHome() const { return home; }
    Team getVisitor() const { return visitor; }
    void showScoreboard()
    {
      string color = "";
      color = "\x1b[32;4m"; //green
      string reset = "\x1b[0m";
      string hScore = "\x1b[36;1m"; // home color
      string vScore = "\x1b[35;1m"; // visitor color

      for(int i = 0; i < 41; i++) { cout << "*"; } cout << endl;
 
      cout << "*" << color << "\t\t\tFootball Scoreboard\n" << reset;
      cout << "*\n";
      cout << "*\t" << hScore << home.getCityName() << reset << setw(14)
           << vScore << visitor.getCityName() << reset << endl;
      cout << "*\t---------------------------------" << endl;
      cout << "*\t" << hScore << home.getTeamName() << reset << setw(14)
           << vScore << visitor.getTeamName() << reset << endl; 
      cout << "*\t\t\t\t" << hScore << home.getScore() << reset << setw(14)
           << vScore << visitor.getScore() << reset << endl; 
      cout << "*\t" << hScore << home.getCoachName() << reset << "\t\t"
           << vScore << visitor.getCoachName() << reset << endl; 

      for(int i = 0; i < 41; i++) { cout << "*"; } cout << endl;
       
       //proces to show the home team status
       cout << endl; 
       if(home.getHomeStatus() == true)
       {
         cout << "Home Team is " << hScore << home.getTeamName() << reset << endl;
         cout << "Visitor Team is " << vScore << visitor.getTeamName() << reset << endl;
       }
       else if(visitor.getHomeStatus() == true)
       {
         cout << "Home Team is " << vScore << visitor.getTeamName() << reset << endl;
         cout << "Visitor Team is " << hScore << home.getTeamName() << reset << endl;
       }
       else
       {
         cout << "Error: "; 
       }

       cout << endl; 
    }
};

#endif
