#pragma once
#include <iostream>
using namespace std;
#include "Account.h"
#include "User.h"
#include "Costumer.h"
#include "Admin.h"
#include "CardToCard.h"
#include "LinkedList.h"

extern LinkedList<Account*> ACCOUNTS;
extern LinkedList<User*> USERS;
extern LinkedList<Costumer*> COSTUMERS;
extern LinkedList<Admin*> ADMINS;
extern LinkedList<CardToCard*> CardToCardS;
