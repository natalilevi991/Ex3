#include <iostream>
using namespace std;

#include "Member.h"


Member avi, beni, chana;

void test1() {
	Member dana;
	chana.follow(dana);
	dana.follow(avi);
	cout << "  " << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 1
	cout << "  " << avi.numFollowers() << " " << avi.numFollowing() << endl; // 1 0
	cout << "  " << Member::count() << endl; // 4
}
void test2() {//test of follow function
	Member tal,dvir,natali,liz;
	tal.follow(avi);
	tal.follow(tal);
	beni.follow(tal);
	dvir.follow(natali);
	tal.follow(dvir);
	beni.follow(natali);
	cout << "  " << tal.numFollowing() << " " << tal.numFollowers() << endl; //2 1
	cout << "  " << beni.numFollowing() << " " << beni.numFollowers() << endl; //2 0
	cout << "  " << dvir.numFollowing() << " " << dvir.numFollowers() << endl; //1 1
	cout << "  " << liz.numFollowing() << " " << liz.numFollowers() << endl; //0 0
	cout << "  " << natali.numFollowing() << " " << dvir.numFollowers() << endl; //0 1
}
void test3() {
	Member yael, sol, zohar, yossi;
	zohar.follow(yossi);
	zohar.follow(yael);
	zohar.unfollow(zohar);
	cout << "  " << zohar.numFollowing() << " " << zohar.numFollowers() << endl; //2 0
	sol.follow(zohar);
	sol.follow(yossi);
	sol.unfollow(zohar);
	cout << "  " << zohar.numFollowing() << " " << zohar.numFollowers() << endl; //2 0
	cout << "  " << sol.numFollowing() << " " << sol.numFollowers() << endl; //1 0

}
/*int main() {
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	avi.follow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	cout << beni.numFollowers() << " " << beni.numFollowing() << endl; // 1 0
	cout << Member::count() << endl; // 3
	cout << endl;

	avi.follow(beni); // duplicate follow has no effect
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 1
	avi.unfollow(beni);
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << endl;

	cout << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	test1();
	cout << chana.numFollowers() << " " << chana.numFollowing() << endl; // 0 0
	cout << avi.numFollowers() << " " << avi.numFollowing() << endl; // 0 0
	cout << Member::count() << endl; // 3
	test2();
	test3();
}*/