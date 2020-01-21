#include "Fish.hpp"

Fish::Fish(std::string name, int quantity, int price)
{
	this->name = name;
	this->quantity = quantity;
	this->price = price;
}

Fish::~Fish()
{
}
