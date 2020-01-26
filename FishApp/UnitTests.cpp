#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Fish.hpp"
#include "Database.hpp"


TEST_CASE("For Fish creation") {
	Fish* fish = new Fish("Test fish", 2, 30);

	REQUIRE(fish->name == "Test fish");
	REQUIRE(fish->quantity == 2);
	REQUIRE(fish->price == 30);
}

TEST_CASE("For Fish added to db creates  id number for new fish - counter check") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 30);
	Fish* fish2 = new Fish("Second fish", 5, 30);

	db.add(fish);
	db.add(fish2);

	REQUIRE(db.db_source[0]->name == "Test fish");
	REQUIRE(db.db_source[1]->name == "Second fish");
}

//find ma argument int - szukam po id ryby
TEST_CASE("For Find Fish") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 30);
	Fish* fish2 = new Fish("Second fish", 5, 30);

	db.add(fish);
	db.add(fish2);

	REQUIRE(db.find(0)->name == "Test fish");
	REQUIRE(db.find(1)->name == "Second fish");
}

TEST_CASE("For removing fish") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 31);
	Fish* fish2 = new Fish("Second test fish", 5, 31);

	db.add(fish);
	db.add(fish2);

	db.remove(1);

	CHECK_THROWS(db.find(1));
}

TEST_CASE("Updating fish") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 31);
	Fish* fish2 = new Fish("Second test fish", 5, 31);
	//prewencja wyieku pamieci - 
	// https://docs.microsoft.com/pl-pl/cpp/cpp/smart-pointers-modern-cpp?view=vs-2019
	//
	db.add(fish);
	db.add(fish2);

	Fish* newfish = new Fish("Updated second test fish", 5, 31);
	
	db.update(1, newfish);

	REQUIRE(db.find(1)->name == "Updated second test fish");
}

TEST_CASE("For - getAll functionallity") {
	Database db = Database();

	//Expects that no exception is thrown during evaluation of the expression.
	REQUIRE_NOTHROW(db.getAll());
}

TEST_CASE("When there are no fish in db - getAll should return empty vector-list") {
	Database db = Database();

	std::vector<Fish*> result = db.getAll();
	//zero pusty vektor
	REQUIRE(result.size() == 0);
}

TEST_CASE("For - getAll returns vector with correct size") {
	Database db = Database();

	Fish* fish = new Fish("Test fish", 1, 34);
	Fish* fish2 = new Fish("Second test fish", 2, 35);
	Fish* fish3 = new Fish("Third test fish", 4, 36);

	db.add(fish);
	db.add(fish2);
	db.add(fish3);
		
	std::vector<Fish*> result = db.getAll();

	REQUIRE(result.size() == 3 );
}


