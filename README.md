<img src="doc/Zserio.png" height="100">

***z***ero ***seri***alization ***o***verhead

[![](https://github.com/ndsev/zserio/actions/workflows/build_linux.yml/badge.svg)](https://github.com/ndsev/zserio/actions/workflows/build_linux.yml)
[![](https://github.com/ndsev/zserio/actions/workflows/build_windows.yml/badge.svg)](https://github.com/ndsev/zserio/actions/workflows/build_windows.yml)
[![](https://github.com/ndsev/zserio/actions/workflows/codeql_default.yml/badge.svg)](https://github.com/ndsev/zserio/actions/workflows/codeql_default.yml)
[![](https://github.com/ndsev/zserio/actions/workflows/codeql_autosar.yml/badge.svg)](https://github.com/ndsev/zserio/actions/workflows/codeql_autosar.yml)
[![](https://img.shields.io/endpoint?url=https://zserio.org/doc/runtime/latest/cpp/coverage/clang/coverage_github_badge.json)](https://zserio.org/doc/runtime/latest/cpp/coverage/clang)
[![](https://img.shields.io/endpoint?url=https://zserio.org/doc/runtime/latest/java/coverage/coverage_github_badge.json)](https://zserio.org/doc/runtime/latest/java/coverage)
[![](https://img.shields.io/endpoint?url=https://zserio.org/doc/runtime/latest/python/coverage/coverage_github_badge.json)](https://zserio.org/doc/runtime/latest/python/coverage)
[![](https://img.shields.io/github/release-date/ndsev/zserio)](https://github.com/ndsev/zserio/releases/latest)
[![](https://img.shields.io/github/commits-since/ndsev/zserio/latest)](https://github.com/ndsev/zserio/commits/master)
[![](https://img.shields.io/github/commit-activity/m/ndsev/zserio)](https://github.com/ndsev/zserio/commits/master)
[![](https://img.shields.io/github/watchers/ndsev/zserio.svg)](https://github.com/ndsev/zserio/watchers)
[![](https://img.shields.io/github/forks/ndsev/zserio.svg)](https://github.com/ndsev/zserio/network/members)
[![](https://img.shields.io/github/stars/ndsev/zserio.svg?color=yellow)](https://github.com/ndsev/zserio/stargazers)

--------

Zserio is a framework for serializing structured data with a compact and efficient way with low overhead.

You can define your structured data in [Zserio language](doc/ZserioLanguageOverview.md) and then you can use
special generated source code in [several languages](#language-support) to easily write and read your data to and from a binary or
text stream.

No time to read? Go to the [quick start](#quick-start) or [download latest release](https://github.com/ndsev/zserio/releases/latest).

In for the numbers? Head over to [benchmarks](benchmarks/README.md).

Questions? Check the [FAQs](doc/FAQ.md).

More documentation? Go to the [documentation](#documentation).

--------

## Language support

Zserio supports the following code generators:

- [C++ Generator](compiler/extensions/cpp/README.md) together with [runtime library](https://zserio.org/doc/runtime/latest/cpp)
  using C++11, and developed with special attention to [functional safety](compiler/extensions/cpp/README.md#functional-safety)
  and [performance](https://github.com/ndsev/zserio-protobuf-benchmarks)
- [Java Generator](compiler/extensions/java/README.md) together with [runtime library](https://zserio.org/doc/runtime/latest/java)
- [Python Generator](compiler/extensions/python/README.md) together with [runtime library](https://zserio.org/doc/runtime/latest/python)

In addition to these, Zserio provides specialized text generators for documentation and export

- [Doc Generator](compiler/extensions/doc/README.md)
- [XML Generator](compiler/extensions/xml/README.md)

## Introduction

The Zserio serialization framework allows you to serialize data in a compact and efficient way.

The key features include

- compactness (smaller than most other serializers)
- advanced schema definition options
- cross-platform
- multiple programming languages

It can be retrofitted on top of almost any other serialization language or model, since it gives the developer
powerful low-level access.

It features simple and compound data structures and provides advanced features for controlling at design time
what writers will be able to fill in.

Although it does not have a wire format, we have added some convenience keywords lately that encapsulate some
functionality. You can find more information on [Zserio Invisibles](doc/ZserioInvisibles.md).

## Quick Sample

The following shows a sample of data (schema) which describe employee using Zserio language:

```
package tutorial;

struct Employee
{
    uint8   age;
    string  name;
    uint16  salary;
    Role    role;
};

enum uint8 Role
{
    DEVELOPER = 0,
    TEAM_LEAD = 1,
    CTO       = 2,
};
```

If we use the schema above and serialize one employee with

- age = 32
- name = Joe Smith
- salary = 5000 $
- role = DEVELOPER

the resulting binary stream looks like the following:

```
Offset(d) 00 01 02 03 04 05 06 07 08 09 10 11 12 13

00000000  20 09 4A 6F 65 20 53 6D 69 74 68 13 88 00
```

Byte position | value             | value (hex)                | comment
------------- | ----------------- | -------------------------- | -----------------------
0             | 32 (age)          | 20                         | `uint8` is fixed size 8 bit value
1             | 9 (string length) | 09                         | string length is encoded in `varsize` field before actual string
2-10          | Joe Smith         | 4A 6F 65 20 53 6D 69 74 68 | UTF-8 encoded string
11-12         | 5000              | 13 88                      | `uint16` always uses 2 bytes
13            | 0                 | 00                         | enum is of size `uint8` so it uses 1 byte

and the resulting text stream (JSON) looks like the following:

```
{
    "age": 32,
    "name": "Joe Smith",
    "salary": 5000,
    "role": "DEVELOPER"
}
```

Please note that in contrast to other serialization mechanisms Zserio supports as well variable integers which
do not provide the full range of values but rather stick to the indicated size. Example: a `varuint64` will be
using max 8 bytes whilst not providing the full range of a `uint64_t` but a `varuint` will be using max
9 bytes and providing the full range of a `uint64_t`.

## Quick Start

To be able to serialize data with Zserio, you have to follow these basic steps:

1. Download the runtimes and the Zserio compiler from [Github Releases](https://github.com/ndsev/zserio/releases/latest)
2. Set up your development environment with the Zserio runtime
3. Write the schema definition
4. Compile the schema and generate code
5. Serialize/deserialize using the generated code

You can find the detailed quick start tutorial in their respective repositories:

- [C++ Tutorial](https://github.com/ndsev/zserio-tutorial-cpp#zserio-c-quick-start-tutorial)
- [Java Tutorial](https://github.com/ndsev/zserio-tutorial-java#zserio-java-quick-start-tutorial)
- [Python Tutorial](https://github.com/ndsev/zserio-tutorial-python#zserio-python-quick-start-tutorial)

Or try [Interactive Zserio Compiler](https://share.streamlit.io/zserio-streamlit/zserio-streamlit/interactive_zserio.py)
based on [Streamlit](https://streamlit.io).

## Features overview

- [Optional elements](doc/ZserioLanguageOverview.md#optional-members)
- [Constraints](doc/ZserioLanguageOverview.md#constraints)
- [Default values](doc/ZserioLanguageOverview.md#default-values)
- [Parameters](doc/ZserioLanguageOverview.md#parameterized-types)
- [Alignments](doc/ZserioLanguageOverview.md#alignment)
- [Offsets](doc/ZserioLanguageOverview.md#offsets)
- [Arrays with indexed offsets](doc/ZserioLanguageOverview.md#indexed-offsets)
- [Packed arrays](doc/ZserioLanguageOverview.md#packed-arrays)
- [Templates](doc/ZserioLanguageOverview.md#templates)
- [Generic services](#services)
- [Generic Pub/Sub](#pubsub)
- [SQLite extension](doc/ZserioLanguageOverview.md#sqlite-extension)

## Documentation

Documentation of the schema language can be found in the
[Zserio Language Overview](doc/ZserioLanguageOverview.md).

Explanation of more hidden schema language features can be found in the
[Zserio Invisibles](doc/ZserioInvisibles.md).

Schema language reference can be found in [Quick Reference](doc/ZserioQuickReference.md).

User Guide can be found in the [Zserio Compiler User Guide](doc/ZserioUserGuide.md).

Build instructions can be found in the [Zserio Compiler Build Instructions](doc/ZserioBuildInstructions.md).

C++ users can find more information in the
[C++ Tutorial](https://github.com/ndsev/zserio-tutorial-cpp#zserio-c-quick-start-tutorial).

Java users can find more information in the
[Java Tutorial](https://github.com/ndsev/zserio-tutorial-java#zserio-java-quick-start-tutorial).

Python users can find more information in the
[Python Tutorial](https://github.com/ndsev/zserio-tutorial-python#zserio-python-quick-start-tutorial).

Check out as well the [Zserio Types Mapping](doc/ZserioTypesMapping.md) for types mapping description.

### Services

[Service types](doc/ZserioLanguageOverview.md#service-types) allow to define generic service interfaces.
But note that no underlying communication library is provided by Zserio. Zserio only defines the generic
interface and users are responsible for its implementation. However, Zserio provides sample implementations
of several services backends:
   * [C++ Zserio Service gRPC backend](https://github.com/ndsev/zserio-service-grpc-cpp)
   * [Java Zserio Service RMI backend](https://github.com/ndsev/zserio-service-rmi-java)
   * [Python Zserio Service HTTP backend](https://github.com/ndsev/zserio-service-http-python)

### Pub/Sub

[Pubsub types](doc/ZserioLanguageOverview.md#pubsub-types) allow to define generic
[Pub/Sub](https://en.wikipedia.org/wiki/Publish%E2%80%93subscribe_pattern) clients.
Users are responsible for implementation of the generic Pub/Sub client interface provided
by Zserio. However, Zserio provides sample implementations of several Pub/Sub backends:
   * [C++ Zserio Pub/Sub Mosquitto backend](https://github.com/ndsev/zserio-pubsub-mosquitto-cpp)
   * [Java Zserio Pub/Sub Paho MQTT backend](https://github.com/ndsev/zserio-pubsub-paho-mqtt-java)
   * [Python Zserio Pub/Sub Paho MQTT backend](https://github.com/ndsev/zserio-pubsub-paho-mqtt-python)

Note that Zserio doesn't provide any Pub/Sub server. There are various implementations of servers
(e.g. [mosquitto](https://github.com/eclipse/mosquitto)) and it's the responsibility of the user's Pub/Sub
client implementation to communicate with the appropriate server.
