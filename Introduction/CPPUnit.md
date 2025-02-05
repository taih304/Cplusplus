# Fundamental concept 

CPPUnit is a test framework used for CPP unit testing.

## Install and setup

```sh
sudo apt-get install libcppunit-dev
```
After successfully install **libcppunit** package, CPPUnit now is available as an external library.

## Implementation

A fixture, from ``TestFixture``, is a known set of objects that serves as a base for a set of test cases.

**Example**

```cpp
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>

class TestClass : public CppUnit::TestFixture
{
	void equal_check()
	{
		CPPUNIT_ASSERT_EQUAL(1 + 1, 2);
	}

	CPPUNIT_TEST_SUITE(TestClass);
	CPPUNIT_TEST(equal_check);
	CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestClass);

int main()
{
	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();//Get the top level suite from the registry
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);//Add test suite
	runner.run();//Run test suite
	return 0;
}
```

Compile: ``g++ test.cpp -lcppunit``

Result

```
OK (1 tests)
```

# Bazel build setup for CPPUnit

```
├── main.cpp
├── WORKSPACE
└── BUILD
```
**BUILD**
```sh
cc_binary(
    name = "main",
    srcs = ["main.cpp"],
    linkopts = ["-lcppunit"],
)
```
**Build**:  ``bazel build main``

**Run**: ``bazel run main``
# Test script and main source code in separated files
**test_script.cpp**
```cpp
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <unistd.h>

class TestClass : public CppUnit::TestFixture
{
	void display_string()
	{
		while(1){
            std::cout << "Hello, World !\n";
            sleep(1);
        }
	}

	CPPUNIT_TEST_SUITE(TestClass);
	CPPUNIT_TEST(display_string);
	CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestClass);
```
**main.cpp**
```cpp
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/ui/text/TestRunner.h>
#include <unistd.h>

int main()
{
	CPPUNIT_NS::Test *suite = CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest();//Get the top level suite from the registry
	CppUnit::TextUi::TestRunner runner;
	runner.addTest(suite);//Add test suite
	runner.run();//Run test suite
	return 0;
}
```
**BUILD**
```sh
cc_binary(
    name = "test_script",
    srcs = ["test_script.cpp"],
    deps = [
        ":library_name",        
    ],
)

cc_library(
    name = "library_name",
    srcs = ["main.cpp"],
    linkopts = ["-lcppunit"],
)
```
# API

## TestFixture.h

TestFixture.h definiton on [its official webpage](https://cppunit.sourceforge.net/doc/1.8.0/_test_fixture_8h-source.html):

```cpp
#ifndef CPPUNIT_TESTFIXTURE_H    // -*- C++ -*-
#define CPPUNIT_TESTFIXTURE_H

#include <cppunit/Portability.h>

namespace CppUnit {
    class CPPUNIT_API TestFixture
    {
        public:
            virtual ~TestFixture() {};

            virtual void setUp() {};

            virtual void tearDown() {};
    };

}

#endif
```
## CPPUNIT_ASSERT_EQUAL()

```cpp
CPPUNIT_ASSERT_EQUAL(1 + 1, 2);
```
## CPPUNIT_ASSERT_MESSAGE()

```cpp
CPPUNIT_ASSERT_MESSAGE(message, exp);
```

``CPPUNIT_ASSERT_MESSAGE`` will print out the ``message`` if ``exp`` is ``false`` and print out nothing (i.e skip ``CPPUNIT_ASSERT_MESSAGE``) if exp is ``true``

```cpp
bool bool_val = false;
CPPUNIT_ASSERT_MESSAGE("Not true", true);// This is not printed out as the param is true
CPPUNIT_ASSERT_MESSAGE("bool_val is true", bool_val);
```

**Result**

```
!!!FAILURES!!!
Test Results:
Run:  1   Failures: 1   Errors: 0

1) test: TestClass::equal_check (F) line: 10 test_script.cpp
assertion failed
- Expression: bool_val
- bool_val is true
```
## CPPUNIT_ASSERT_EQUAL_MESSAGE()

```cpp
CPPUNIT_ASSERT_EQUAL_MESSAGE(message, expected, actual)
```
Return:
* Print out ``message`` if ``expect != equal``
* Return ``OK`` if ``expect == equal``

Example


Result

```cpp
CPPUNIT_ASSERT_EQUAL_MESSAGE("Not qual", 1 + 3, 2);
```

```
!!!FAILURES!!!
Test Results:
Run:  1   Failures: 1   Errors: 0

1) test: TestClass::equal_check (F) line: 8 test_script.cpp
equality assertion failed
- Expected: 4
- Actual  : 2
- Not qual
```
