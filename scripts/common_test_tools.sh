#!/bin/bash

SCRIPT_DIR=`dirname $0`
source "${SCRIPT_DIR}/common_tools.sh"

# Set and check test global variables.
set_test_global_variables()
{
    # UNZIP to use, defaults to "unzip" if not set
    UNZIP="${UNZIP:-unzip}"
    if [ ! -f "`which "${UNZIP}"`" ] ; then
        stderr_echo "Cannot find unzip! Set UNZIP environment variable."
        return 1
    fi

    # GRPC setup
    GRPC_ROOT="${GRPC_ROOT:-""}"

    # Zserio extra arguments
    ZSERIO_EXTRA_ARGS="${ZSERIO_EXTRA_ARGS:-""}"

    return 0
}

# Print help on the environment variables used for this release script.
print_test_help_env()
{
    cat << EOF
Uses the following environment variables for testing:
    UNZIP               Unzip executable to use. Default is "unzip".
    GRPC_ROOT           Root path to GRPC repository. GRPC is disabled by default.
    ZSERIO_EXTRA_ARGS   Extra arguments to zserio tool. Default is empty.
EOF
}

# Unpack zserio release zips.
unpack_release()
{
    exit_if_argc_ne $# 4
    local TEST_OUT_DIR="$1"; shift
    local ZSERIO_RELEASE_DIR="$1"; shift
    local ZSERIO_VERSION="$1"; shift
    local UNPACKED_ZSERIO_RELEASE_DIR_OUT="$1"; shift

    local UNPACKED_ZSERIO_RELEASE_DIR_LOC="${TEST_OUT_DIR}/tested_release"
    rm -rf "${UNPACKED_ZSERIO_RELEASE_DIR_LOC}" # always use fresh release
    mkdir -p "${UNPACKED_ZSERIO_RELEASE_DIR_LOC}"

    # bin
    "${UNZIP}" -q "${ZSERIO_RELEASE_DIR}/zserio-${ZSERIO_VERSION}-bin.zip" \
        -d "${UNPACKED_ZSERIO_RELEASE_DIR_LOC}"
    if [ $? -ne 0 ] ; then
        stderr_echo "Cannot unzip zserio binaries to ${UNPACKED_ZSERIO_RELEASE_DIR_LOC}!"
        return 1
    fi

    # runtime-libs
    "${UNZIP}" -q "${ZSERIO_RELEASE_DIR}/zserio-${ZSERIO_VERSION}-runtime-libs.zip" \
        -d "${UNPACKED_ZSERIO_RELEASE_DIR_LOC}"
    if [ $? -ne 0 ] ; then
        stderr_echo "Cannot unzip zserio runtime libraries to ${UNPACKED_ZSERIO_RELEASE_DIR_LOC}!"
        return 1
    fi

    eval ${UNPACKED_ZSERIO_RELEASE_DIR_OUT}="'${UNPACKED_ZSERIO_RELEASE_DIR_LOC}'"

    return 0
}

# Run zserio tool with specified sources and arguments
run_zserio_tool()
{
    exit_if_argc_ne $# 6
    local ZSERIO_RELEASE_ROOT="$1"; shift
    local BUILD_DIR="$1"; shift # for logging
    local ZSERIO_DIRECTORY="$1"; shift
    local ZSERIO_SOURCE="$1"; shift
    local WERROR="$1"; shift
    local MSYS_WORKAROUND_TEMP=("${!1}"); shift
    local ZSERIO_ARGS=("${MSYS_WORKAROUND_TEMP[@]}")

    local ZSERIO="${ZSERIO_RELEASE_ROOT}/zserio.jar"
    local ZSERIO_LOG="${BUILD_DIR}/zserio_log.txt"
    local MESSAGE="Compilation of zserio '${ZSERIO_DIRECTORY}/${ZSERIO_SOURCE}'"
    echo "STARTING - ${MESSAGE}"

    "${JAVA_BIN}" -jar "${ZSERIO}" ${ZSERIO_EXTRA_ARGS} "-src" "${ZSERIO_DIRECTORY}" "${ZSERIO_SOURCE}" \
            "${ZSERIO_ARGS[@]}" 2>&1 | tee ${ZSERIO_LOG}

    if [ ${PIPESTATUS[0]} -ne 0 ] ; then
        stderr_echo "${MESSAGE} failed!"
        return 1
    fi

    if [ ${WERROR} -ne 0 ] ; then
        grep -q "\[WARNING\]" ${ZSERIO_LOG}
        if [ $? -eq 0 ] ; then
            stderr_echo "${MESSAGE} failed because warnings are treated as errors! "
            return 1
        fi
    fi

    echo -e "FINISHED - ${MESSAGE}\n"

    return 0
}
