# throw int value

``try catch`` will try execute the block of code inside ``try``. ``catch`` will be executed if there is [throw](throw.md) inside ``try`` and the line of code of ``throw`` is reached.

```c
#include <iostream>

using namespace std;

int main(){
    try {
        int value = 1;
        if (value >= 10) {
            cout << "Valid number";
        } else {
            throw value;//Throw value as the exeception number
        }

        //Those block of code can't be reached as throw is reached above
        if (value == 2) cout << "value = 2";
        else cout << "value != 2";
    }
    catch (int number_var) {
        cout << "Invalid number: " << number_var << "\n";
    }
        printf("Program keeps running as throw error is caught\n");
}
```

```c
Invalid number: 1
Program keeps running as throw error is caught
```

As the throw error (``throw value``) is caught (by ``catch``), the program won't stop so the line of code after ``catch(int number_var)`` keeps executing (``printf("Program keeps running as throw error is caught\n")``);

# throw string value

```c
try {
    int value = 1;
    if (value >= 10) {
        cout << "Valid number";
    } else throw "throw a string value";//Throw value as the exeception number
}
catch (const char *str) {//As handling with const char*
    cout << "Thow string: " << str << "\n";
}
printf("Program keeps running as throw error is caught\n");
```
    
# throw std::runtime_error

``throw std::runtime_error`` must be caught with ``std::runtime_error &e``

```cpp
try {
    int value = 1;
    if (value >= 10) {
        std::cout << "Valid number";
    } else throw std::runtime_error("Invalid number throw runtime_error");
}
catch (std::runtime_error &e) {
    std::cout << "Invalid number: " << e.what() << "\n";
}
printf("Program keeps running as throw error is caught\n");
```
**Result**
```
Invalid number: Invalid number throw runtime_error
Program keeps running as throw error is caught
```
# catch (...) will accept all thrown data types
```c
int main()
{
    try {
        int value = 1;
        if (value >= 10) {
            cout << "Valid number";
        } else {
            throw value;//Throw value as the exeception number
        }
    }
    catch (...) {
        cout << "Exception is thrown\n";
    }
}
```
E.g: Handle invalid [stoi()]() convert:

```cpp
try {
    return std::stoi("abc12");
}
catch (...) {
    cout << "Invalid convert with stoi()\n";
}
```
