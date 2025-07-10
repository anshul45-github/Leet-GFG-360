# DSA Quick Reference Cheat Sheet

## 🚀 STL Containers
| Container           | Declaration                  | Common Methods                     | Time Complexity |
|---------------------|------------------------------|------------------------------------|-----------------|
| Vector             | `vector<int> v;`            | `.push_back()`, `.pop_back()`      | O(1) amortized  |
| Priority Queue     | `priority_queue<int> pq;`   | `.push()`, `.top()`, `.pop()`      | O(log n)        |
| Set                | `set<int> s;`               | `.insert()`, `.find()`, `.erase()` | O(log n)        |
| Unordered Map      | `unordered_map<K,V> mp;`    | `[]`, `.count()`, `.erase()`       | O(1) avg        |

## 🔥 Common Algorithms

### Sorting
```cpp
// Custom comparator
sort(v.begin(), v.end(), [](auto &a, auto &b) {
    return a[0] < b[0];  // Sort by first element
});
````

### Binary Search

```cpp
bool found = binary_search(v.begin(), v.end(), target);
```

## 🔎 Set Lookups

### Check if number > x exists in set

```cpp
auto it = s.upper_bound(x);
if(it != s.end()) {
    // Number > x exists: *it
}
```

### Check if number ≥ x exists in set

```cpp
auto it = s.lower_bound(x);
if(it != s.end()) {
    // Number >= x exists: *it
}
```

* Both `upper_bound` and `lower_bound` work in `O(log n)` time.

## ⚡ Bit Manipulation

| Operation  | Code              | Effect              |
| ---------- | ----------------- | ------------------- |
| Clear bit  | `x &= ~(1 << n);` | Clears nth bit      |
| Toggle bit | `x ^= (1 << n);`  | Flips nth bit       |
| Check bit  | `(x >> n) & 1`    | Returns nth bit     |
| LSB        | `x & (-x)`        | Gets lowest set bit |

## 🧮 Math Formulas

* **Prime Check**: Trial division up to √n

## 🛠 Useful Snippets

### Fast I/O (for competitive programming)

```cpp
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
```

## 📝 Problem Solving Template

1. Understand constraints (input size → time complexity)
2. Brute force → Optimize
3. Edge cases:

   * Empty input
   * Single eleme
   * Duplicates
   * Overflow cases