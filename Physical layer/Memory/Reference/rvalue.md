rvalue reference is unofficially called as double address operator. rvalue reference can be defined with ``int &&`` and ``int &&a``.

``&&`` is new in C++11. ``int&& a`` means "a" is an r-value reference.

Compile: ``g++ main.c -std=c++11``

# Define rvalue

```c
#include <stdio.h>

int main()
{
    int&& a = 1;//Define with int&&   
    int &&b = 2;//Define with int &&
    printf("a: %d, &a: %d\n", a, &a);//a: 1, &a: 6487560
    printf("b: %d, &b: %d\n", b, &b);//b: 2, &b: 6487564
}
```

Calling ``&&a`` will result in error:

```cpp
printf("&&a: %d", &&a);//This will result in error
printf("&&b: %d", &&b);//This will result in error
```
**Error**

```
main.c:13:25: error: label 'a' used but not defined
main.c:14:25: error: label 'b' used but not defined
```
## Change rvalue
```cpp
int&& a = 1;
printf("a: %d, &a: %d\n", a, &a);//a: 1, &a: 6487560
a = 123;
printf("a: %d, &a: %d\n", a, &a);//a: 123, &a: 6487560
```
## Arithmetic

```cpp
int a = 1;
int b = 2;
int &&c = a + b;
printf("c: %d\n", c);//c: 3
```

# rvalue as class object

```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		int publicNumber = 10;
		void hello(){
			cout << "Hello, World !\n";
		}
};

int main(){
    classTest &&rval_object = classTest();
    rval_object.hello();//Hello, World !
    cout << rval_object.publicNumber << endl; //10
}
```
## Set rvalue for a class object from an existed one
To set rvalue for a class object from an existed one, use [std::move()](README.md#stdmove):
```cpp
classTest object;
classTest &&rval_object = std::move(object);
```
## rvalue as function argument with constructor setup
```cpp
#include <iostream>

using namespace std;

class classTest{
	public:
		classTest(int a, string str){
			_a = a;
			_str = str;

		}
		int _a;
		string _str;
		void display_string(){
			cout << _str << endl;
			cout << _a << endl;
		}
};

void display(classTest &&rval_object);

int main(){
	display({123, "Hello, World !"});
}

void display(classTest &&rval_object){
	rval_object.display_string();
}
```
```
Hello, World !
123
```
# rvalue as function argument

For rvalue as function argument, the value passing to it must be rvalue

```c
#include <stdio.h>

int func(int&& a)
{
    return a+1;
}

int main()
{   
    int a = 4;
    printf("%d\n", func(3));//4
    printf("%d\n", func(a-0));//5
    printf("%d\n", func(a+1));//6
}
```
Use [std::move()](README.md#stdmove) to be more efficient, instead of using ``func(a-0)``:

```cpp
printf("%d\n", func(std::move(a)));
```

# rvalue as pass reference

For rvalue as pass reference to change value of a variable, use [std::move()](README.md#stdmove)

```c
void func(int&& a)
{
    a += 1;
    return;
}

int main()
{   
    int a = 4;
    printf("%d\n", a);//4
    func(std::move(a));
    printf("%d\n", a);//5
}
```
