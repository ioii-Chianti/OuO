# set, multiset

> [C++ Reference](https://www.cplusplus.com/reference/set/)
> T 為傳入的資料型態

**Set.insert(T data)**
- Parameter: data
- Return: 

**Set.begin()**
- Return: *<iterator>* 指向第一個元素的 iterator

**Set.end()**
- Return: *<iterator>* 指向最後一個元素後面 (NULL) 的 iterator

**Set.size()**
- Return: *<int>* 集合內有幾個元素

**Set.lower_bound(T data)**
- Parameter: 某個 T type 的東西
- Return: *<iterator>* 找到 data <= value，回傳 value 的 iterator

**Set.lower_bound(T data)**
- Parameter: 某個 T type 的東西
- Return: *<iterator>* 找到 data <= value，回傳 value 的 iterator

**Set.lower_bound(const T &data)**

**Set.lower_bound(const_iterator it)**

**Set.lower_bound(const_iterator first, const_iterator last)**
1. 輸入值
    刪除值為 data 的元素
2. 輸入 it
    刪除被 it 指著的元素
3. 輸入 it ~ it
    刪除 set [first,last) 區間的元素
- Parameter: three cases above OxO
- Return: (C++11) 最後一個被刪除的元素的下一個 iterator
          (Others) 沒有回傳值