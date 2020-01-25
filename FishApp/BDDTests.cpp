#include "catch.hpp"
#include "Database.hpp"
#include "Fish.hpp"

SCENARIO("Removing single product from the database") {

	GIVEN("Database with fish") {
		Database db = Database();
		Fish* fish = new Fish("Test fish", 1, 25);

		db.add(fish);	

		CHECK_NOTHROW(db.find(0));

		WHEN("Fish is removed from the database") {
			db.remove(0);
				
			THEN("Fish no longer exists in the database") {
				CHECK_THROWS(db.find(0));
			}
		}
	}
}