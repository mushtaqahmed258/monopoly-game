#include<iostream>
#include<cstdlib>
#include<ctime>

void dieRoll(int& d1, int& d2) {
	int count = 0, d_1 = 0, d_2 = 0;
	do {
		d_1 += std::rand() % 6 + 1;
		d_2 += std::rand() % 6 + 1;
		std::cout << "Die rolls are : " << d_1 << " and : " << d_2 << "\n";
		count++;
		if (count == 3) {
			std::cout << "Rolled three times!";
			d1 = 0;d2 = 0;
			return;
		}
	} while (d_1 == d_2);
	d1 = d_1; d2 = d_2;
}
int main() {
	int d1 = 0, d2 = 0, position = 0;
	std::srand(std::time(0));
	dieRoll(d1, d2);
	position = (position + d1 + d2)%40;
	std::cout << "This will be a monopoly game.\n";
	std::cout << "Position = " << position;

}