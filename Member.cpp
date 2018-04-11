#include "Member.h"
using namespace std;

int Member::numOfMembers = 0;
Member::Member()
{
	++numOfMembers;
}

Member::~Member()
{
	for (Member* m : followers) 
	{
		m->unfollow(*this);
	}
	for (Member* m : following)
	{
		this->unfollow(*m);
	}
	--numOfMembers;
}

void Member::follow(Member& m)
{
	Member *u = &m;
	if (this == u) return;
	for(Member *m : following) // Checks if it's already following
	{
		if (m == u) {
			return;
		}
	}
	following.push_back(u); //add to following
	u->followers.push_back(this);//add to followers of m
}


void Member::unfollow(Member& m)
{
	Member *member = &m;
	for (int i = 0; i < following.size(); i++) 
	{ //Runs on a following and searches for m then erases it
		if (following[i] == member)
		{
			following.erase(following.begin() + i);
		}
	}

	for (int i = 0; i < m.followers.size(); i++) 
	{//Runs on M's followers and searches for m and then deletes it
		if (m.followers[i] == this) 
		{
		//	member->followers.erase(followers.begin() + i);
			m.followers.erase(m.followers.begin() + i);
			return;
		}
	}

}

int Member::numFollowers()
{
	return followers.size();
}

int Member::numFollowing()
{
	return following.size();
}

int Member::count()
{
	return numOfMembers;
}
