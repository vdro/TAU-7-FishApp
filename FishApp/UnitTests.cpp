#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Fish.hpp"
#include "Database.hpp"

TEST_CASE("getAll is impelemented") {
	Database db = Database();

	REQUIRE_NOTHROW(db.getAll());
}

TEST_CASE("Creating Fish - hope it works") {
	Fish*fish = new Fish("Test fish", 1, 25);

	REQUIRE(fish->name == "Test fish");
	REQUIRE(fish->quantity == 1);
	REQUIRE(fish->price == 25);
}

TEST_CASE("Adding Fish to database creates proper id number for new fish - counter check") {
	Database db = Database();

	Fish*fish = new Fish("Test fish", 1, 25);
	Fish* fish2 = new Fish("Second test fish", 5, 35);

	db.add(fish);
	db.add(fish2);

	REQUIRE(db.db_source[0]->name == "Test fish");
	REQUIRE(db.db_source[1]->name == "Second test fish");
}
//sprawdze meode find
TEST_CASE("Find Fish works") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 25);
	Fish* fish2 = new Fish("Second test fish", 5, 35);

	db.add(fish);
	db.add(fish2);

	REQUIRE(db.find(0)->name == "Test fish");
	REQUIRE(db.find(1)->name == "Second test fish");
}

TEST_CASE("Remove Fish works") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 25);
	Fish* fish2 = new Fish("Second test fish", 5, 35);

	db.add(fish);
	db.add(fish2);

	db.remove(1);

	CHECK_THROWS(db.find(1));
}

TEST_CASE("Update Fish works") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 25);
	Fish* fish2 = new Fish("Second test fish", 5, 35);

	db.add(fish);
	db.add(fish2);

	Fish* newfish = new Fish("Updated second test fish", 5, 35);

	db.update(1, newfish);

	REQUIRE(db.find(1)->name == "Updated second test fish");
}



TEST_CASE("When there are no fishes in db getAll should return empty vector(liste)") {
	Database db = Database();

	std::vector<Fish*> result = db.getAll();
	//zero pusty vektor
	REQUIRE(result.size() == 0);
}

TEST_CASE("getAll returns vector with correct size") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 25);
	Fish* fish2 = new Fish("Second test fish", 5, 35);
	Fish* fish3 = new Fish("Third test fish", 3, 12);

	db.add(fish);
	db.add(fish2);
	db.add(fish3);

	std::vector<Fish*> result = db.getAll();
	//3 obiety 
	REQUIRE(result.size() == 3);
}