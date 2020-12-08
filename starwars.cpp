#include <iostream>

class ForceBeing {
  private: int
  power_level;
  std::string name;
  bool evil;

  protected:
   ForceBeing(int level) {
      power_level = level;
  }

  void setName(std::string characterName) {
    name = characterName;
  }

  void setPowerLevel(int level) {
    power_level = level;
  }

  public:
  virtual int getPowerLevel() {
    return power_level;
  }
  
  virtual std::string getName() {
    return name;
  }

   void setEvil() {
    evil = true;
  }

   void setGood() {
    evil = false;
  }

};

class Jedi : public ForceBeing {
  
  public:
  Jedi(std::string jediName, int level): ForceBeing(level) {
      setName(jediName);
      setGood();
  }

   int getPowerLevel() {
    return ForceBeing::getPowerLevel() + 1;
  }
};

class Sith : public ForceBeing {
  public:
   Sith(std::string sithName, int level): ForceBeing(level) {
      setName(sithName);
      setEvil();
  }

  int getPowerLevel() {
    return ForceBeing::getPowerLevel() -1;
  }

  std::string getName() {
    return "Sith Lord: " + ForceBeing::getName();
  }
};



    std::string getWinner(ForceBeing &player1, ForceBeing &player2) {
        return player1.getPowerLevel() > player2.getPowerLevel() ? player1.getName() : player2.getName();
    }

     static void printWinner(std::string winner) {
        std::cout << "The winner is: " << winner;
    }

     int main() {
        Sith darthVader("Darth Vader",100);
        Jedi lukeSkyWalker("Luke Skywalker",99);
        printWinner(getWinner(darthVader, lukeSkyWalker));
        return 0;
    }
