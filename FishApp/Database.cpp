#include "Database.hpp"
#include <algorithm>

void Database::add(Fish *fish) {
	fish->id = db_counter;
	db_source.insert(std::make_pair(db_counter, fish));
	db_counter++;
}
//mapa -id -obiekt id
Fish* Database::find(int id) {
	return db_source.at(id);
}

void Database::remove(int id) {
	db_source.erase(id);
}

void Database::update(int id, Fish*product) {
	db_source[id] = product;
}

//konwersja mapy na liste - dynamiczna
std::vector<Fish*> Database::getAll() {
	result.clear();

	for (auto i : db_source)
	{
		result.push_back(i.second);
	}

	return result;
}