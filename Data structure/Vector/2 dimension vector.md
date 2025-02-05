Create a 2x3 vector:
```cpp
vector<vector<int>> two_d_vec = {{1, 2, 3}, {4, 5, 6}};
```
# Setup value for a 2D vector
Define a 2D vector:
```cpp
int row = 3;
int column = 2;

std::vector<std::vector<int>> two_d_vec(row, std::vector<int>(column));

for (int _row = 0; _row < row; _row++) {
    for (int _col = 0; _col < column; _col++) {
        two_d_vec[_row][_col] = _row * column + _col;
    }
}

for (int _row = 0; _row < row; _row++) {
    for (int _col = 0; _col < column; _col++) {
        std::cout << two_d_vec[_row][_col] << " ";
    }
    std::cout << std::endl;
}
```
**Result**:
```
0 1
2 3
4 5
```
**Enter value for each member of the 2D vector**:
```cpp
void setup_2d_vector(){
    int n;
    cin >> n;
    
    vector<vector<int>> two_d_vec(n);
    
    for (int i = 0; i < n; i++){
        int one_d_vec_sz;
        cin >> one_d_vec_sz;
        vector<int> one_d_vec(one_d_vec_sz);
        
        for (int j = 0; j < one_d_vec_sz; j++){
            cin >> one_d_vec[j];
        }

        // Must not use push_back(): two_d_vec.push_back(one_d_vec);
        two_d_vec[i] = one_d_vec;
    }
}
```
# Size of a 2D vector
``.size()`` of a 2D vector returns the total rows of that vector:
```cpp
vector<vector<int>> two_d_vec = {{1, 2, 3}, {4, 5, 6}, {4, 5, 6}};
cout << two_d_vec.size() << endl; // 3
```
# Count pairs of similar strings

Two strings are similar if they consist of the same characters.

* "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
* However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.

* Input: words = ["aba","aabb","abcd","bac","aabc"]
* Output: 2. Pair ("aba","aabb") and ("bac","aabc")

* Input: words = ["aabb","ab","ba"]
* Output: 3. Pair: ("aabb","ab"), ("aabb", "ba"), ("ab","ba")

```cpp
int similarPairs(vector<string>& words) {
    vector<vector<char>> words_vector;

    for (int i = 0; i < words.size(); i++){
        vector<char> char_vector;
        for (int j = 0; j < words[i].size(); j++){
            vector<char>::iterator iter = find(char_vector.begin(), char_vector.end(), words[i][j]);
            if (iter == char_vector.end()) {
                char_vector.push_back(words[i][j]);
            }
        }
        if (char_vector.size() > 0) {
            sort(char_vector.begin(), char_vector.end());
            words_vector.push_back(char_vector);
        }
    }

    if (!words_vector.size()) return 0;

    int count = 0;

    for (int i = 0; i < words_vector.size(); i++){
        for (int j = i + 1; j < words_vector.size(); j++){
            if (words_vector[i] == words_vector[j]) count += 1;
        }
    }

    return count;
}
```
