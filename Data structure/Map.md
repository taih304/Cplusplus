Map is a data structure that supports creating an object includes a key and its value

```cpp
std::map<key, value> Map;
```

# Create a map and read all of its objects

```cpp
#include <iostream>
#include <map>

int main()
{
    std::map<int, std::string> Map;
    Map[1] = "Map, key 1";
    Map[123] = "Map, key 123";
    Map[456] = "Map, key 456";

    std::cout << Map[123] << std::endl;// Map, key 123

    for (auto &el: Map){
        std::cout << "First element: " << el.first << std::endl;
        std::cout << "Second element: " << el.second << std::endl;
    }
    return 0;
}
```
```
Map, key 123
First element: 1
Second element: Map, key 1
First element: 123
Second element: Map, key 123
First element: 456
Second element: Map, key 456
```
# Insert a new member to the map

```cpp
std::map<int, std::string> Map;
Map[1] = "Map, key 1";
Map[123] = "Map, key 123";
Map[456] = "Map, key 456";

std::cout << "Map before inserting\n";
for (auto &el: Map){
    std::cout << el.first << " " << el.second << std::endl;
}

Map.insert(std::make_pair(789, "Newly insert value"));

std::cout << "Map after inserting\n";
for (auto &el: Map){
    std::cout << el.first << " " << el.second << std::endl;
}
```