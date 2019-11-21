#include "gtest/gtest.h"

#include "zserio/BitStreamWriter.h"
#include "zserio/BitStreamReader.h"

#include "topic_types/topic_ok/TestTopic.h"

#include <functional>
#include <type_traits>

namespace topic_types
{
namespace topic_ok
{

TEST(TopicTest, TopicOk)
{
    TestTopic test;

    /* Check topic name */
    ASSERT_EQ(test.topic(), "this/is/a/topic/#");

    /* Check num of wildcards */
    ASSERT_EQ(test.numWildcards(), 1u);

    /* Check topic value-type by comparing it's payload callback type */
    auto valueTypeOk =
        std::is_same<std::function<void(const std::string&, const TestData&)>,
                     TestTopic::OnPayloadAvailable>::value;
    ASSERT_TRUE(valueTypeOk);
}

}
}
