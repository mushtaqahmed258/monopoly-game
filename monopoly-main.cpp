#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
#include<ctime>
#include<iomanip>
int n = 0;
int dieRoll();
int updtPosition(int& position);
class Player { //class name with capital 'P'
public:
	int id;
	Player (int newid):id(newid){}
	int pos = 0;//position
	int cash = 1500; //cash

	void turn(Player) {
		pos = updtPosition(pos);
	}
};
int main() {
	std::srand(static_cast<unsigned int>(time(nullptr)));//seeding srand
	std::cout << "======== <<< Monopoly Game >>> ========.\n";
	std::cout << "Start the game!!\n";
	std::cout << "How many players : ";
	std::cin >> n;
	std::vector<Player> players; //vector name with small 'p'
	for (int i = 0;i < n;i++) {
		players.push_back(Player(i+1));
	}
	int pTurn = 0; //which players turn is it
	while (true) //main-loop
	{
		pTurn = 1;
		std::cout << "Turn of player : " << pTurn + 1 << "\n";
		players[pTurn].turn(players[pTurn]);
		std::cout << "Position = " << players[pTurn].pos;
		break;
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