#include "catch.hpp"

#include "str_util.h"

TEST_CASE( "helloworld", "[split]" ) {
    REQUIRE( split("a b c")[0] == "a" );
    REQUIRE( split("a b c")[1] == "b" );
    REQUIRE( split("a b c")[2] == "c" );
}
