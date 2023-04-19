# A function to create clang-tidy target.
#
# Usage clang_tidy_add_custom_target
#   TARGET            Existing target for which to add the clang-tidy custom target.
#   SOURCES           List of source directories for clang-tidy.
#   SOURCES_GLOBS     List of sources globbing expressions which will be searched using GLOG_RECURSE.
#   BUILD_PATH        Build path which contains the compilation database.
#                     Use -DCMAKE_EXPORT_COMPILE_COMMANDS=ON!
#   CONFIG_FILE       Path to .clang-tidy config file.
#   HEADER_FILTER     Optional header filter which will be passed as a --header-filter clang-tidy
#                     argument. Default is '_NEVER_MATCH'.
#   LINE_FILTER_FILE  Optional line filter file which content will be passed as a --line-filter clang-tidy
#                     argument. Default is '[]'.
#   OUTPUT_FILE       Optional file name where the clang-tidy output will be stored.
#                     Default is 'clang-tidy.log'.
function (clang_tidy_add_custom_target)
    include(CMakeParseArguments)
    cmake_parse_arguments(CLANG_TIDY
        "" "TARGET;BUILD_PATH;CONFIG_FILE;HEADER_FILTER;LINE_FILTER_FILE;OUTPUT_FILE" "SOURCES;SOURCES_GLOBS"
        ${ARGN}
    )

    # check required arguments
    foreach (ARG TARGET BUILD_PATH CONFIG_FILE)
        if (NOT DEFINED CLANG_TIDY_${ARG})
            message(FATAL_ERROR "No value defined for required argument ${ARG}!")
        endif ()
    endforeach ()

    if (NOT DEFINED CLANG_TIDY_SOURCES AND NOT DEFINED CLANG_TIDY_SOURCES_GLOBS)
        message(FATAL_ERROR "No value defined neither for SOURCES nor SOURCES_GLOBS!")
    endif ()

    # process optional arguments
    if (DEFINED CLANG_TIDY_HEADER_FILTER)
        set(HEADER_FILTER "${CLANG_TIDY_HEADER_FILTER}")
    else ()
        set(HEADER_FILTER "_NEVER_MATCH")
    endif ()
    if (EXISTS "${CLANG_TIDY_LINE_FILTER_FILE}")
        file(READ ${CLANG_TIDY_LINE_FILTER_FILE} LINE_FILTER)
        string(REGEX REPLACE "[ \r\n\t]" "" LINE_FILTER "${LINE_FILTER}")
    else ()
        set(LINE_FILTER "[]")
    endif ()

    if (DEFINED CLANG_TIDY_OUTPUT_FILE)
        set(OUTPUT_FILE "${CLANG_TIDY_OUTPUT_FILE}")
    else ()
        set(OUTPUT_FILE "clang-tidy.log")
    endif ()

    # process sources
    list(APPEND CLANG_TIDY_SOURCES_LIST ${CLANG_TIDY_SOURCES})
    foreach (SOURCE_EXPRESSION ${CLANG_TIDY_SOURCES_GLOBS})
        file(GLOB_RECURSE MATCHING_SOURCES "${SOURCE_EXPRESSION}")
        list(APPEND CLANG_TIDY_SOURCES_LIST ${MATCHING_SOURCES})
    endforeach ()
    list(REMOVE_DUPLICATES CLANG_TIDY_SOURCES_LIST)

    if (CLANG_TIDY_BIN)
        add_custom_target(${CLANG_TIDY_TARGET}-clang-tidy-clean ALL DEPENDS ${CLANG_TIDY_TARGET}
            COMMAND "${CMAKE_COMMAND}" -E remove -f "${OUTPUT_FILE}"
        )

        set(INDEX 0)
        foreach (SOURCE_FILE ${CLANG_TIDY_SOURCES_LIST})
            add_custom_target(${CLANG_TIDY_TARGET}-clang-tidy-${INDEX} ALL
                DEPENDS ${CLANG_TIDY_TARGET}-clang-tidy-clean)
            add_custom_command(TARGET ${CLANG_TIDY_TARGET}-clang-tidy-${INDEX} POST_BUILD
                COMMAND "${CMAKE_COMMAND}"
                    -DCLANG_TIDY_BIN="${CLANG_TIDY_BIN}"
                    -DSOURCES="${SOURCE_FILE}"
                    -DBUILD_PATH="${CLANG_TIDY_BUILD_PATH}"
                    -DCONFIG_FILE="${CLANG_TIDY_CONFIG_FILE}"
                    -DLINE_FILTER="${LINE_FILTER}"
                    -DHEADER_FILTER="${HEADER_FILTER}"
                    -DOUTPUT_FILE="${OUTPUT_FILE}"
                    -P ${CMAKE_MODULE_PATH}/clang_tidy_tool.cmake
                COMMENT "Running clang-tidy on ${SOURCE_FILE}"
            )
            math(EXPR INDEX "${INDEX} + 1")
        endforeach ()
    endif ()
endfunction()
