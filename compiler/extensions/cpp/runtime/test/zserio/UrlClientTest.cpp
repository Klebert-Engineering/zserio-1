#include "zserio/UrlClient.h"

#include "gtest/gtest.h"
#include <iostream>

namespace zserio
{

TEST(UrlClientTest, fetch)
{
    UrlClient underTest;

    underTest.fetchResource("i_am_a_bad_url");
    ASSERT_EQ(UrlClient::Error, underTest.status());
    ASSERT_EQ("Couldn't resolve host name", underTest.statusDescription());

    auto result = underTest.fetchResource("https://www.w3.org/History.html");
    ASSERT_EQ(UrlClient::Healthy, underTest.status());
    ASSERT_EQ(result.size(), 18205);
}

}