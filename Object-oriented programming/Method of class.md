# Types of methods in class

**Private methods** can't be access outside the class internal definition and can only be called from outisde the class by public functions. Check ``call_private_function()`` function in [header.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/OOP/Example/header.cpp)

**Non-static member methods** can access all data members (static and non-static variables) of the class. Example: Check ``add_number()`` function in [header.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/OOP/Example/header.cpp)

**Static member methods** can only operate on the static variables, static functions and variables and functions outside the class. It can't call non-static variables and non-static functions. Example: Check ``read_static_var()`` function in [header.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/OOP/Example/header.cpp). Also note that defining function ``read_static_var()`` inside the CPP source file must not have ``static`` storage class.

Static member functions works with variables and functions outside the class like this example:

``head.h``

```cpp
#include <iostream>
#ifndef header_h
#define header_h

using namespace std;

class exampleClass
{
  	public:
		static int 	return_int_num();
		static void print_argument(int argument);
};
#endif
```
``head.cpp``
```cpp
int exampleClass::return_int_num(){
    return 123;
}
void exampleClass::print_argument(int argument){
    cout << argument << endl;
}
```

``main.cpp``

```cpp
#include "header.h"

int a = 789;
main(){
	exampleClass object;
	object.print_argument(a);//789

	int b = object.return_int_num();
	object.print_argument(b);//123
}
```

**Methods take object as parameter**: Check ``call_object_method()`` for the method to take object as parameter in [header.cpp](https://github.com/TranPhucVinh/Cplusplus/blob/master/Introduction/OOP/Example/header.cpp)

# Calling multiple method at one time

## Simple call

```cpp
#include <iostream>

using namespace std;
class classTest{
	public:
		classTest display_string(){
            classTest new_object;
			cout << "Hello, World !\n";
            return new_object;
		}
        void display_number(){
			cout << 123;
		}
};

int main(){
	classTest object;
    object
        .display_string()
        .display_number()
    ;
}
```
  
``display_number()`` can be called after ``display_string()`` as ``display_string()`` return object ``new_object`` as having type ``classTest``. ``new_object`` will then be used for calling ``display_number()``.

**Result**

```
Hello, World !
123
```

Can also call by this way:

```cpp
classTest object;
object.display_string().display_number();
```

## Using this pointer

To keep the same object when calling multiple methods, it's better to use ``this`` pointer.

```cpp
classTest display_string(){
    cout << "*this Hello, World !\n";
    return *this;
}

//Other operations keep as above

int main(){
	classTest object;
    object.display_string().display_number();
}
```
## Using rvalue class object
```cpp
#include <iostream>
#include <typeinfo>

using namespace std;
template <typename class_type>
void call_object_method(class_type&& object){
    object
        .display_string()
        .display_number()
    ;
}

class classTest{
	public:
		classTest& display_string(){
			cout << "Hello World \n";
            return *this;
		}
        void display_number(){
			cout << 123;
		}
};

int main(){
	classTest&& rval_object = classTest();
    call_object_method<classTest&&>(move(rval_object));
}
```