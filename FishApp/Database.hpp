#pragma once

#include "Fish.hpp"
#include <map>
#include <vector>

class Database {

public:
	void add(Fish *fish);
	Fish* find(int id);
	void remove(int id);
	void update(int id, Fish* fish);
	std::vector<Fish*> getAll();

	std::map<int, Fish*> db_source;

private:
	int db_counter = 0;
	std::vector<Fish*> result;
};