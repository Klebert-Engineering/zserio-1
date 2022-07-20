#include <algorithm>
#include <array>

#include "gtest/gtest.h"

#include "zserio/CppRuntimeException.h"

namespace zserio
{

TEST(CppRuntimeExceptionTest, emptyConstructor)
{
    CppRuntimeException exception;
    ASSERT_EQ(std::string(), exception.what());
}

TEST(CppRuntimeExceptionTest, cStringConstructor)
{
    CppRuntimeException noDescriptionException;
    ASSERT_EQ(std::string(), noDescriptionException.what());

    CppRuntimeException emptyDescriptionException("");
    ASSERT_EQ(std::string(), emptyDescriptionException.what());

    const std::string testMessage = "this is the test message";
    CppRuntimeException exception(testMessage.c_str());
    ASSERT_EQ(testMessage, exception.what());
}

TEST(CppRuntimeExceptionTest, appendCString)
{
    std::string testMessage = "1234567890123456";
    const std::string appendix = "1234567890123456";
    CppRuntimeException exception = CppRuntimeException(testMessage.c_str()) << appendix.c_str();
    testMessage += appendix;
    ASSERT_EQ(testMessage, exception.what());

    const size_t exceptionBufferSize = 512;
    const size_t maxLen = exceptionBufferSize - 1;
    for (int i = 0; i < 100; ++i)
    {
        exception = exception << appendix.c_str();
        testMessage += appendix;
        const size_t len = std::min(testMessage.size(), maxLen);
        ASSERT_EQ(testMessage.substr(0, len), exception.what());
    }
}

TEST(CppRuntimeExceptionTest, appendBool)
{
    std::string testMessage = "test true: ";
    CppRuntimeException exception = CppRuntimeException(testMessage.c_str()) << true;
    testMessage += "true";
    ASSERT_EQ(testMessage, exception.what());

    exception << ", and false: " << false;
    testMessage += ", and false: false";
    ASSERT_EQ(testMessage, exception.what());
}

TEST(CppRuntimeExceptionTest, appendFloat)
{
    const float value = 123.456f;
    CppRuntimeException exception = CppRuntimeException() << value;
    ASSERT_EQ(std::string("123.456"), exception.what());
}

TEST(CppRuntimeExceptionTest, appendDouble)
{
    const double value = 123.456;
    CppRuntimeException exception = CppRuntimeException() << value;
    ASSERT_EQ(std::string("123.456"), exception.what());
}

TEST(CppRuntimeExceptionTest, appendInt)
{
    const int value = 42;
    CppRuntimeException exception = CppRuntimeException() << value;
    ASSERT_EQ(std::to_string(value), exception.what());
}

enum class Enumeration : uint8_t
{
    BLACK,
    RED,
    WHITE
};

template <>
struct EnumTraits<Enumeration>
{
    static constexpr ::std::array<const char*, 3> names =
    {{
        "BLACK",
        "RED",
        "WHITE"
    }};
};

constexpr ::std::array<const char*, 3> EnumTraits<Enumeration>::names;

template <>
size_t enumToOrdinal(Enumeration value)
{
    switch (value)
    {
    case Enumeration::BLACK:
        return 0;
    case Enumeration::RED:
        return 1;
    case Enumeration::WHITE:
        return 2;
    default:
        throw CppRuntimeException("Unknown value for enumeration Enumeration: ") <<
                static_cast<typename ::std::underlying_type<Enumeration>::type>(value) << "!";
    }
}

TEST(CppRuntimeExceptionTest, appendEnum)
{
    CppRuntimeException exception = CppRuntimeException() << Enumeration::BLACK <<
            Enumeration::RED << Enumeration::WHITE;
    ASSERT_EQ(std::string(EnumTraits<Enumeration>::names[0]) + EnumTraits<Enumeration>::names[1] +
            EnumTraits<Enumeration>::names[2], exception.what());
}

class Bitmask
{
public:
    typedef uint8_t underlying_type;

    enum class Values : underlying_type
    {
        READ = UINT8_C(1),
        WRITE = UINT8_C(2)
    };

    constexpr explicit Bitmask(Values value) noexcept :
        m_value(static_cast<underlying_type>(value))
    {}

    constexpr underlying_type getValue() const
    {
        return m_value;
    }

private:
    underlying_type m_value;
};

TEST(CppRuntimeExceptionTest, appendBitmask)
{
    const Bitmask value(Bitmask::Values::WRITE);
    CppRuntimeException exception = CppRuntimeException() << value;
    ASSERT_STREQ("2", exception.what());
}

TEST(CppRuntimeExceptionTest, appendString)
{
    CppRuntimeException exception = CppRuntimeException() << std::string("test");
    ASSERT_STREQ("test", exception.what());
}

TEST(CppRuntimeExceptionTest, appendVector)
{
    CppRuntimeException exception = CppRuntimeException() << std::vector<int>{{1, 2, 3}};
    ASSERT_STREQ("vector([...], 3)", exception.what());
}

} // namespace zserio
