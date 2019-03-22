include(compiler_utils)

# A function to add CURL library target
function(curl_add_library ZSERIO_PROJECT_ROOT)
    # remove strict warning
    compiler_reset_warnings()
    compiler_reset_warnings_as_errors()

    add_subdirectory("${ZSERIO_PROJECT_ROOT}/3rdparty/cpp/curl")

    # configuration
    # target_compile_definitions(SQLite3 PRIVATE SQLITE_ENABLE_FTS4 SQLITE_ENABLE_FTS5)

    # set(SQLITE_LIBRARY SQLite3 PARENT_SCOPE)
    # set(SQLITE_INCDIR ${SQLITE_ROOT} PARENT_SCOPE)
endfunction()
