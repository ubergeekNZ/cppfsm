#include "gtest/gtest.h"
#include "gmock/gmock.h"

int main(int argc, char *argv[])
{
    testing::InitGoogleTest(&argc, argv);
    testing::FLAGS_gmock_verbose = "error";
    return RUN_ALL_TESTS();
}