# Create new file

Open a file (created if not existed) and write data to that file

```cpp
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ofstream fileStreamOut;
	fileStreamOut.open("text.txt");

	fileStreamOut << "Hello, World !"; //Write data to file
	fileStreamOut.close();
}
```

Or: ``ofstream fileStreamOut("text.txt");``

# Read file into std::string

## << causes reading to be separated by spaces

``text.txt``
```
1 user_1 10
2 user_2 20
3 user_3 30
```

Using ``fstream()``

```cpp
string readString;

fstream fileStream("text.txt");
fileStream >> readString;
cout << readString;
fileStream.close();
```
**Output**: ``1``

The same issue happens with ``ifstream()``. That’s because the ``>>`` operator reads a string only until it encounters a white space character (such as a space or line break). 

**Problem solved**

```cpp
string data;
ifstream fileStreamIn("main.cpp");

while (!fileStreamIn.eof()){
    string _data;
    getline(fileStreamIn, _data);
    data += _data + "\n";
}
cout << data;
```

## Read a number of characters of a file into a buffer

Use **read()** function to read a number of characters of a file into a buffer on stack memory:

```cpp
#include <iostream>
#include <fstream>

using namespace std;
char buf[100];
int main()
{
    ifstream if_stream("main.cpp");
    if(!if_stream) {
      cout << "Cannot open file!" << endl;
      return 1;
    } else cout << "Open file successfully\n";
    if_stream.read(buf, sizeof(buf));
    cout << buf << endl;
}
```
Implement heap memory initialized with unique pointer:
```cpp
#include <iostream>
#include <fstream>
#include <memory>

using namespace std;

#define BUFF_SIZE   100 

int main()
{
    ifstream ifs("main.cpp");
    if(!ifs.good()) {
      cout << "Cannot open file!" << endl;
      return 1;
    } else cout << "Open file successfully\n";

    std::unique_ptr<char[]> file_buffer(new char[BUFF_SIZE]);

    ifs.read(file_buffer.get(), BUFF_SIZE);
    cout << file_buffer.get() << endl;
}
```
## Read the whole file without knowing its size
```cpp
const char *filename = "main.cpp";

std::ifstream ifs(filename, std::ios::ate);
size_t file_sz = ifs.tellg(); 
cout << file_sz << endl;

ifs.seekg(0);// Revert ifs back to index 0

std::unique_ptr<char[]> file_buffer(new char[file_sz]);

ifs.read(file_buffer.get(), file_sz);
cout << file_buffer.get() << endl;
```
# Write data to file

Write with ``fstream()``

```cpp
#include <iostream>
#include <fstream>
using namespace std;

#define FILE_NAME   "text.txt"
int main()
{
	fstream fileStream(FILE_NAME);
    if (fileStream.fail()) {//Use .fail() to check if FILE_NAME existed
        cout << "File " << FILE_NAME << " not existed\n";
        return 0;
    }
    fileStream << "Hello, World !";
    fileStream.close();
    return 0;
}
```

``fileStream.fail()`` return ``1`` if file not existed and ``0`` if file existed.

Or: 

```c
fstream fileStream("text.txt", ios::in | ios::out);
```

Write with ``ofstream()``

```c
#include <iostream>
#include <fstream>

using namespace std;

int number = 10;
string displayedString = "Hello, World !";

main() {
	ofstream fileStreamOut("file.txt");
	fileStreamOut << number << " " << displayedString << endl;
	fileStreamOut.close();
}
```
