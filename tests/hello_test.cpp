#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE("adding students and assignments") {
    Gradebook g;
    g.add_student("Bob", "Bobberson", "ABC123");
    g.add_assignment("Quiz 1");
    g.enter_grade("Bob Bobberson", "Quiz 1", 85);

    string expected = "Last_Name,First_Name,Student_ID,Quiz 1\nBobberson,Bob,ABC123,85\n";
    REQUIRE(g.report() == expected);
}

TEST_CASE("G=grades not entered show none") {
    Gradebook g;
    g.add_student("Jess", "Jesserson", "HIJ789");
    g.add_assignment("Lab 1");

    string expected = "Last_Name,First_Name,Student_ID,Lab 1\nJesserson,Jess,HIJ789,none\n";
    REQUIRE(g.report() == expected);
}

TEST_CASE("multiple students and assignments") {
    Gradebook g;
    g.add_student("Bob", "Bobberson", "ABC123");
    g.add_student("Sam", "Sammerson", "DEF456");
    g.add_assignment("Quiz 1");
    g.add_assignment("Lab 1");

    g.enter_grade("Sam Sammerson", "Quiz 1", 95);
    g.enter_grade("Bob Bobberson", "Lab 1", 0);

    string expected = "Last_Name,First_Name,Student_ID,Quiz 1,Lab 1\nBobberson,Bob,ABC123,none,0\nSammerson,Sam,DEF456,95,none\n";
    REQUIRE(g.report() == expected);
}