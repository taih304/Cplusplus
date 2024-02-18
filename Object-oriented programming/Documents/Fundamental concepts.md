# What is class ?

**Class** is a group of objects having the same properties. An instance of a class is called an **object**.

If not declaring **public** or **[private](#private-variables)**, members of a class are private by default.

# Define variable and function for a class; Use class object as a pointer

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			cout << "Hello World \n";
		}
	private:
		int privateNumer = 20; //Unable to read that value outside
};

int main(){
	classTest object, *obj_ptr;
	object.hello(); //Hello World
	cout << object.publicNumber << endl; //10

	obj_ptr = &object;
	obj_ptr->hello(); //Hello World
	cout << obj_ptr->publicNumber << endl; //10
}
```

**Note 1**: If compiling with default G++ (C++98: ``g++ test.cpp``) and GCC (``gcc test.cpp -lstd++``), there will be warning: 

```
test.cpp:33:22: warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
   int publicNumber = 10;
                      ^
test.cpp:38:22: warning: non-static data member initializers only available with -std=c++11 or -std=gnu++11
   int privateNumer = 20; //Unable to read that value outside
```

So initilize variable variable inside a class is prefered to be implemented with ``C++11`` and the above ``C++`` standard.

**Note 2**: For pointer object ``obj_ptr``, like all normal pointer, it must be mapped to an object of that class. If not mapping, this pointer object will be a wild pointer and can't access the variable value of that object (cause Segmentation fault error)

```cpp
//This cause Segmentation fault error and must not be done
classTest *obj_ptr;
cout << obj_ptr->public_number << endl;//Segmentation fault
```

``new`` keyword can be used to allocate memory for ``*obj_ptr``:

```cpp
classTest *obj_ptr = new classTest();

obj_ptr->hello(); //Hello World
cout << obj_ptr->publicNumber << endl; //10
```

## Private variables

Private variables are available only inside the class function definition (check [examples](https://github.com/TranPhucVinh/Cplusplus/tree/master/Introduction/OOP/Example) for that implementation), class object is unable to access it

In the example above, class object ``object`` is unable to read private variable ``privateNumer``:

```cpp
private:
    int privateNumer = 20; //Unable to read that value outside
```

So this will give error: ``cout << object.privateNumber << endl;``

Any members defined out specified **public** or **private** are **private** by default:
```cpp
class classTest{
    int privateNumer; //This is a private member
	public:
		int publicNumber;
		void displayStringhello(){
            publicNumber = 123;
		}
};
```
# Types of class variables

* [Instance variables](#instance-variables)
* [Static variables](#static-variables)

## Instance variables

* Instance variables are **created when an object of the class is created** and **destroyed when the object is destroyed**.
* Instance variables can be accessed **only by creating objects**.

## [Static variables](static.md#static-variables)