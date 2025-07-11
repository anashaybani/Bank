#pragma once
#include <iostream>
using namespace std;
#include "User.h"



class Admin : public User
{public:
	Admin();
	~Admin();

	void findCostumer();
	void findAdmin();

};

