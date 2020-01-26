#include "catch.hpp"
#include "Database.hpp"
#include "Fish.hpp"

SCENARIO("Removing  fish from the db") {

	GIVEN("Database with fish") {
		Database db = Database();
		Fish* fish = new Fish("Test fish", 2, 22);

		db.add(fish);

		//Expects that no exception is thrown during evaluation of the expression.
		CHECK_NOTHROW(db.find(0));

		WHEN("Fish is removed from the db") {
			db.remove(0);

			THEN("Fish no longer exists in the db") {
			  //Expects that an exception(of any type) is be thrown during evaluation of the expression.
				CHECK_THROWS(db.find(0));
			}
		}
	}
}