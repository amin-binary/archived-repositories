#include"http.h"
#include<catch.hpp>


using namespace std;

TEST_CASE("asio wks!", "[rp]") {
    io_context_example();

    REQUIRE(true);
}
