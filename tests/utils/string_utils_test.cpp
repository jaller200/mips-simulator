#include "catch.hpp"

#include "utils/string_utils.hpp"

/**
 * Method: StringUtils::toLowerCase(..)
 * Desired Confidence Level: Basic validation
 * 
 * Inputs:
 *      str     -> Any valid string, validated
 * 
 * Outputs:
 *      A string where all ASCII characters are lower case
 * 
 * Valid Tests:
 *      str     -> a basic string with upper and lower case letters
 *                 a basic string with all upper case letters
 *                 a basic string with all lower case letters
 *                 a whitespace-only string
 *                 an empty string
 *
 * Invalid Tests:
 *      None
 */
TEST_CASE("Converting strings to lower case work properly") {

    SECTION("Converting a nominal string to lower case works") {
        std::string result = StringUtils::toLowerCase("I absolutely LOVE programming!");
        std::string expected = "i absolutely love programming!";
        REQUIRE(result == expected);
    }

    SECTION("Converting a string with all upper case to lower case works") {
        std::string result = StringUtils::toLowerCase("THIS IS AMAZING!");
        std::string expected = "this is amazing!";
        REQUIRE(result == expected);
    }

    SECTION("Converting a string with no upper case to lower case just returns the string") {
        std::string result = StringUtils::toLowerCase("this is amazing");
        std::string expected = "this is amazing";
        REQUIRE(result == expected);
    }

    SECTION("Converting a whitespace-only string to lower case does nothing") {
        std::string result = StringUtils::toLowerCase(" \t");
        std::string expected = " \t";
        REQUIRE(result == expected);
    }

    SECTION("Converting an empty string to lower case just returns an empty string") {
        std::string results = StringUtils::toLowerCase("");
        std::string expected = "";
        REQUIRE(results == expected);
    }
}

/**
 * Method: StringUtils::ltrim(..)
 * Desired Confidence Level: Basic validation
 * 
 * Inputs:
 *      str     -> Any valid string, validated
 * 
 * Outputs:
 *      A string with no whitespace (tabs, tabs, etc.) at
 *      the start.
 * 
 * Valid Tests:
 *      str     -> a basic string with whitespace at the start
 *                 a basic string with whitespace both at the start and inside
 *                 a basic string with whitespace at the start and new line at the end
 *                 a basic string with tabs at the start
 *                 a basic string with a mixture of all possible whitespace types
 *                 a basic string with no whitespace at the front
 *                 an white-space only string
 *                 an empty string
 * 
 * Invalid Tests:
 *      None
 */
TEST_CASE("Left trimming a string works properly") {

    SECTION("Left trimming a nominal string with whitespace at the start removes the starting whitespace") {
        std::string result = StringUtils::ltrim("   test");
        std::string expected = "test";
        REQUIRE(result == expected);
    }

    SECTION("Left trimming a string with whitespace at the start and inside only removes the starting whitespace") {
        std::string result = StringUtils::ltrim("   this is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Left trimmin a string with whitespace at the start and a new line at the end only removes the starting whitespace") {
        std::string result = StringUtils::ltrim("   this is a test\n");
        std::string expected = "this is a test\n";
        REQUIRE(result == expected);
    }

    SECTION("Left trimming a string with tabs at the start removes the tabs") {
        std::string result = StringUtils::ltrim("\t\t\tthis is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Left trimming a string with all possible whitespace before removes the whitespace") {
        std::string result = StringUtils::ltrim(" \f\n\r\t\vthis is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Left trimming a string with no whitespace at the start just returns the string") {
        std::string result = StringUtils::ltrim("this is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Left trimming a string with only whitespace returns an empty string") {
        std::string result = StringUtils::ltrim(" \t\t\r");
        std::string expected = "";
        REQUIRE(result == expected);
    }

    SECTION("Left trimming and empty string returns an empty string") {
        std::string result = StringUtils::ltrim("");
        std::string expected = "";
        REQUIRE(result == expected);
    }
}

/**
 * Method: StringUtils::rtrim(..)
 * Desired Confidence Level: Basic validation
 * 
 * Inputs:
 *      str     -> Any valid string, validated
 * 
 * Outputs:
 *      A string with no whitespace (tabs, tabs, etc.) at
 *      the end.
 * 
 * Valid Tests:
 *      str     -> a basic string with whitespace at the end
 *                 a basic string with whitespace both at the end and inside
 *                 a basic string with whitepace at the start and the end
 *                 a basic string with tabs at the end
 *                 a basic string with a mixture of all possible whitespace types at the end
 *                 a basic string with no whitespace at the end
 *                 a whitespace-only string
 *                 an empty string
 * 
 * Invalid Tests:
 *      None
 */
TEST_CASE("Right trimming a string works properly") {

    SECTION("Right trimming a nominal string with whitespace at the end removes the ending whitespace") {
        std::string result = StringUtils::rtrim("test   ");
        std::string expected = "test";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming a string with whitespace at the end and inside removes only the ending whitespace") {
        std::string result = StringUtils::rtrim("this is a test   ");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming a string with whitespace at the start and end only removes the ending whitespace") {
        std::string result = StringUtils::rtrim("  this is a test  ");
        std::string expected = "  this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming a string with tabs at the end removes the tabs") {
        std::string result = StringUtils::rtrim("this is a test\t\t");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming a string with all possible whitespace at the end removes it") {
        std::string result = StringUtils::rtrim("this is a test \f\n\r\t\v");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming a string with no whitespace at the end just returns the string") {
        std::string result = StringUtils::rtrim("this is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming a string with only whitespace returns an empty string") {
        std::string result = StringUtils::rtrim(" \t\t\r");
        std::string expected = "";
        REQUIRE(result == expected);
    }

    SECTION("Right trimming and empty string returns an empty string") {
        std::string result = StringUtils::rtrim("");
        std::string expected = "";
        REQUIRE(result == expected);
    }
}

/**
 * Method: StringUtils::trim(..)
 * Desired Confidence Level: Basic validation
 * 
 * Inputs:
 *      str     -> Any valid string, validated
 * 
 * Outputs:
 *      A string with no whitespace (tabs, tabs, etc.) at
 *      the start or end.
 * 
 * Valid Tests:
 *      str     -> a basic string with whitespace at the start
 *                 a basic string with whitespace at the end
 *                 a basic string with whitespace both at the start and inside
 *                 a basic string with whitespace both at the end and inside
 *                 a basic string with whitepace at the start and the end
 *                 a basic string with a mixture of all possible whitespace types at the start and end
 *                 a basic string with no whitespace at the start or end
 *                 a whitespace-only string
 *                 an empty string
 * 
 * Invalid Tests:
 *      None
 */
TEST_CASE("Trimming a string works properly") {

    SECTION("Trimming a nominal string with whitespace at the start removes the starting whitespace") {
        std::string result = StringUtils::trim("  test");
        std::string expected = "test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a nominal string with whitespace at the end removes the ending whitespace") {
        std::string result = StringUtils::trim("test  ");
        std::string expected = "test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a string with whitespace at the start and inside removes the starting whitespace") {
        std::string result = StringUtils::trim("  this is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a string with whitespace at the end and inside removes the ending whitespace") {
        std::string result = StringUtils::trim("this is a test  ");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a string with whitespace at both the start and end removes the starting and ending whitespace") {
        std::string result = StringUtils::trim("  this is a test  ");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a string with all possible whitespace at the start and end removes the whitespace") {
        std::string result = StringUtils::trim(" \f\n\r\t\vthis is a test \f\n\r\t\v");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a string with no whitespace at the start or end just returns the string") {
        std::string result = StringUtils::trim("this is a test");
        std::string expected = "this is a test";
        REQUIRE(result == expected);
    }

    SECTION("Trimming a string with only whitespace returns an empty string") {
        std::string result = StringUtils::trim(" \t\t\r");
        std::string expected = "";
        REQUIRE(result == expected);
    }

    SECTION("Trimming and empty string returns an empty string") {
        std::string result = StringUtils::trim("");
        std::string expected = "";
        REQUIRE(result == expected);
    }
}