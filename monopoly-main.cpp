#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
using namespace std;

int n = 0;
int pTurn = 0; //which players turn is it
int dieRoll();
int updtPosition(int& position);
extern std::string place[40];


class Player { //class name with capital 'P'
public:
	int id;
	Player (int newid=1):id(newid){}
	std::string name;
	int pos = 0;//position
	int cash = 1500; //cash

	void turn(Player) {
		pos = updtPosition(pos);
	}
};

class Place {
public:
	int id;
	Place (int newid = 0):id(newid){}
	std::string title;
	Player owner;
};

int main() {
	std::srand(static_cast<unsigned int>(time(nullptr)));//seeding srand
	std::cout << "======== <<< Monopoly Game >>> ========.\n";
	std::cout << "Start the game!!\n";
	/*std::cout << "How many players : ";
	std::cin >> n;
	std::vector<Player> players; //vector name with small 'p'*/
	constexpr int n = 5;
	Player players[n];
	players[0] = Player(0);
	players[0].name= "Bank";
	players[0].cash= 6000;//bank cash
	Place place[40];
	for (int i = 1;i < (n);i++) {//making objects for each player
		players[i] = Player(i);
		//players.push_back(Player(i+1));
	}

	for (int i = 0;i < 40;i++) {
		place[i] = Place(i);
		std::cout << "\nPlace id's : " << place[i].id+1;
	}

	while (true) //main-loop
	{
		pTurn = pTurn%4;
		std::cout << "\n\nTurn of player : " << ++pTurn << "\n";
		players[pTurn].turn(players[pTurn]);
		std::cout << "Position = " << players[pTurn].pos << "\n\n";
		if (pTurn>=4) {
			break;
		}
	}
}
int dieRoll() {//simply returns the final sum, after checking three times same case.
	int count = 0, d1 = 0, d2 = 0;
	do {
		d1 += std::rand() % 6 + 1;
		d2 += std::rand() % 6 + 1;
		std::cout << "Die rolls are : " << d1 << " and : " << d2 << "\n";
		count++;
		if (count == 3) {
			std::cout << "Rolled three times!";
			d1 = 0;d2 = 0;
			return 0;
		}
	} while (d1 == d2);
	return (d1+d2);
}
int updtPosition(int& position) {	
	return ((position + dieRoll()) % 40);
}

std::string place[40] = { "hello",
"propert1","jail" };


class Property
{
public:
	int id;
	string name;
	string color;

	int price;
	int ownerId;

	int houses;
	bool hotel;
	bool mortgage;

	int rent[6];

	Property()
	{
		ownerId = -1;
		houses = 0;
		mortgage = false;
		hotel = false;
	}

};
Property properties[28];

int main()
{

}