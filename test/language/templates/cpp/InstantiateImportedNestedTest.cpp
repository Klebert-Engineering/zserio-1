#include "gtest/gtest.h"

#include "templates/instantiate_imported_nested/pkg/U32.h"

namespace templates
{
namespace instantiate_imported_nested
{

TEST(InstantiateImportedNestedTest, readWrite)
{
    pkg::U32 u32{13u};

    zserio::BitStreamWriter writer;
    u32.write(writer);
    size_t bufferSize = 0u;
    const auto buffer = writer.getWriteBuffer(bufferSize);

    zserio::BitStreamReader reader(buffer, bufferSize);
    pkg::U32 readU32(reader);

    ASSERT_EQ(u32, readU32);
}

} // namespace instantiate_imported_nested
} // namespace templates
