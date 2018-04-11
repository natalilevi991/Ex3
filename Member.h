#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



class Member
{

private:
	vector <Member*> followers;//Who's following me
	vector <Member*> following;//All the members I follow
	static int numOfMembers; 

public:
	Member(); // constructor
	~Member(); // distructor
	void follow(Member& m);//The function does follow
	void unfollow(Member& m);// The function does unfollow
	int numFollowers();//return number of followers of me
	int numFollowing();//return number of my following
	static int count();//count of members
};

