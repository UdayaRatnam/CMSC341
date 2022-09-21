#include <iostream>
#include <string>
using namespace std;
class Person {
public:
  Person(std::string name = "", int age = 0)
    : m_name(name), m_age(age ) {
  }
  string getName() {
    return m_name;
  }
  int getAge() {
    return m_age;
  }
private:
  std::string m_name;
  int m_age;
};
// Soccer Player publicly inheriting Person
class SoccerPlayer : public Person {
public:
  SoccerPlayer(string name = "", int age = 0,
	       int goals = 0, int assists = 0)
    : Person(name, age), // call Person(string, int) to initialize these fields
      m_goals(goals), m_assists(assists)
  {
  }
  int getGoals() { return m_goals; }
  int getAssists() { return m_assists; }
private:
  int m_goals;
  int m_assists;
};

int main () {
  SoccerPlayer myPlayer("Maradonna", 33,10,15);
  cout << myPlayer.getName() << " " << myPlayer.getAge()
       << " " << myPlayer.getGoals() << " " << myPlayer.getAssists() << endl;
  return 0;
}
