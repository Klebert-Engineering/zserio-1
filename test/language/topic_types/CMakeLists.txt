set(ZSERIO_GEN_DIR ${CMAKE_CURRENT_BINARY_DIR}/gen)
set(ZSERIO_GENERATED_SOURCES
    ${ZSERIO_GEN_DIR}/topic_types/topic_ok/TestTopic.cpp
    ${ZSERIO_GEN_DIR}/topic_types/topic_ok/TestTopic.h
    ${ZSERIO_GEN_DIR}/topic_types/topic_ok/TestData.cpp
    ${ZSERIO_GEN_DIR}/topic_types/topic_ok/TestData.h
)

zserio_add_library(TARGET topic_types_zs
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/zs
    MAIN_SOURCE topic_types.zs
    OUT_DIR ${ZSERIO_GEN_DIR}
    OUT_FILES ${ZSERIO_GENERATED_SOURCES}
    ZSERIO_CORE_DIR ${ZSERIO_JAR_DIR}
    ZSERIO_OPTIONS -withoutSourcesAmalgamation -cppStandard ${ZSERIO_CPP_STANDARD}
)

add_test_sources(
    ${ZSERIO_CPP_DIR}/TopicOk.cpp
)

add_test_dependencies(topic_types_zs)
