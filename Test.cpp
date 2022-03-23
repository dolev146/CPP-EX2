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

TEST_CASE("1")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Horizontal, "abc");

    CHECK((note.read(0, 0, 0, Direction::Horizontal, 3)) == ("abc"));
    /* Add more test here */
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

TEST_CASE("11")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    note.erase(0, 0, 0, Direction::Horizontal, 1);
    note.erase(0, 0, 0, Direction::Horizontal, 1);
    CHECK((note.read(0, 0, 0, Direction::Horizontal, 4) == "~bcd"));
}

TEST_CASE("12")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "abcd");
    /*1*/ CHECK_THROWS(note.write(0, 0, 0, Direction::Vertical, "abcd"));
}

TEST_CASE("13")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Vertical, "a");
    note.write(1, 0, 0, Direction::Vertical, "b");
    note.write(2, 0, 0, Direction::Vertical, "c");
    note.write(3, 0, 0, Direction::Vertical, "d");
    CHECK((note.read(0, 0, 0, Direction::Horizontal, 4) == "abcd"));
}
TEST_CASE("14")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Horizontal, "abcd");
    CHECK_THROWS(note.write(0, 0, 0, Direction::Vertical, "abcd"));
}
TEST_CASE("15")
{
    Notebook note;
    note.write(0, 0, 0, Direction::Horizontal, "abcd");
    CHECK_THROWS(note.write(0, 0, 0, Direction::Vertical, "abcd"));
}
TEST_CASE("16")
{
    // you cannot write where you delete
    Notebook note;
    note.write(100, 100, 50, Direction::Horizontal, "dolev");
    note.erase(100, 100, 50, Direction::Horizontal, 4);
    CHECK_THROWS(note.write(100, 100, 50, Direction::Horizontal, "dolev"));
}

TEST_CASE("17")
{
    Notebook note;
    CHECK_THROWS(note.write(-1, 0, 0, Direction::Vertical, "Dolev"));
}
TEST_CASE("18")
{
    Notebook note;
    CHECK_THROWS(note.write(0, -1, 0, Direction::Vertical, "Dolev"));
}
TEST_CASE("19")
{
    Notebook note;
    CHECK_THROWS(note.write(0, 0, -1, Direction::Vertical, "Dolev"));
}

TEST_CASE("20")
{
    Notebook note;
    CHECK_THROWS(note.read(5, 5, 5, Direction::Vertical, -4));
}