/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 *
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Dolev Dublon
 *
 * Date: 2022-03
 */

#include "doctest.h"
#include "Direction.hpp"
#include "Notebook.hpp"
#include <string>
#include <stdexcept>
#include <iostream>
using namespace std;
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

TEST_CASE("Good input")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Horizontal, "abc");

    CHECK((note.read(0, 0, 0, Direction::Horizontal, 3)) == ("abc"));
    /* Add more test here */

    note.write(0, 1, 0, Direction::Horizontal, "abc");
    /*18*/ CHECK((note.read(0, 1, 0, Direction::Horizontal, 3)) == ("abc"));
}

TEST_CASE("2")
{
    Notebook note;
    note.write(100, 0, 0, Direction::Horizontal, "abc");
    CHECK((note.read(100, 0, 0, Direction::Horizontal, 3) == "abc"));
}
TEST_CASE("3")
{
    Notebook note;
    note.write(200, 0, 0, Direction::Horizontal, "abc");
    CHECK((note.read(200, 0, 0, Direction::Horizontal, 3) == "abc"));
}
TEST_CASE("4")
{
    Notebook note;
    note.write(200, 0, 0, Direction::Horizontal, "abc");
    CHECK((note.read(0, 0, 0, Direction::Horizontal, 3) == "___"));
}
TEST_CASE("5")
{
    Notebook note;
    note.write(50, 1, 99, Direction::Horizontal, "a");
    CHECK((note.read(50, 1, 99, Direction::Horizontal, 1) == "a"));
}

TEST_CASE("6")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    CHECK((note.read(0, 1, 0, Direction::Horizontal, 1) == "b"));
}

TEST_CASE("7")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    CHECK((note.read(0, 2, 0, Direction::Horizontal, 1) == "c"));
}

TEST_CASE("8")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    CHECK((note.read(0, 2, 0, Direction::Horizontal, 1) == "c"));
}

TEST_CASE("9")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    CHECK((note.read(0, 3, 0, Direction::Horizontal, 1) == "d"));
}

TEST_CASE("10")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    note.erase(0, 0, 0, Direction::Horizontal, 1);
    CHECK((note.read(0, 0, 0, Direction::Horizontal, 4) == "~bcd"));
}

// TEST_CASE("Bad input")
// {
//     CHECK_THROWS(mat(10, 5, '$', '%'));
//     /* Add more test here */
// }

// TEST_CASE("21")
// {
//     /*1*/ CHECK_THROWS((mat(4, 4, '@', '-'))); // cant have EVEN mat
// }
// TEST_CASE("22")
// {
//     /*2*/ CHECK_THROWS((mat(2, 5, '@', '-'))); // cant have EVEN mat
// }
// TEST_CASE("23")
// {
//     /*3*/ CHECK_THROWS((mat(2, 40, '@', '-'))); // cant have EVEN mat
// }
// TEST_CASE("24")
// {
//     /*4*/ CHECK_THROWS((mat(0, 1, '@', '-'))); // 0 not valid input
// }
// TEST_CASE("25")
// {
//     /*5*/ CHECK_THROWS((mat(0, 0, '@', '-'))); // 0 not valid input
// }
// TEST_CASE("26")
// {
//     /*6*/ CHECK_THROWS((mat(-5, -7, '@', '-'))); // cant have negative numbers
// }
