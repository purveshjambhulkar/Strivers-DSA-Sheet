# 📌 C++ DSA Cheat Sheet - Arrays

## 📋 Array Functions in C++ STL  

| **Function**                      | **Description**            | **Example**                          |
|-----------------------------------|----------------------------|--------------------------------------|
| `sort(arr, arr+n)`               | Sorts array.               | `sort(arr, arr+5);`                 |
| `reverse(arr, arr+n)`            | Reverses array.            | `reverse(arr, arr+5);`              |
| `max_element(arr, arr+n)`        | Finds max element.         | `*max_element(arr, arr+5);`         |
| `min_element(arr, arr+n)`        | Finds min element.         | `*min_element(arr, arr+5);`         |
| `accumulate(arr, arr+n, 0)`      | Sums array elements.       | `accumulate(arr, arr+5, 0);`        |
| `find(arr, arr+n, x)`            | Finds `x` in array.        | `find(arr, arr+5, 10);`             |
| `count(arr, arr+n, x)`           | Counts occurrences of `x`. | `count(arr, arr+5, 10);`            |
| `binary_search(arr, arr+n, x)`   | Checks if `x` exists.      | `binary_search(arr, arr+5, 10);`    |
| `lower_bound(arr, arr+n, x)`     | First `≥ x` element.       | `lower_bound(arr, arr+5, 10);`      |
| `upper_bound(arr, arr+n, x)`     | First `> x` element.       | `upper_bound(arr, arr+5, 10);`      |
| `fill(arr, arr+n, x)`            | Fills array with `x`.      | `fill(arr, arr+5, 0);`              |
| `copy(arr1, arr1+n, arr2)`       | Copies `arr1` to `arr2`.   | `copy(arr1, arr1+5, arr2);`         |
| `equal(arr1, arr1+n, arr2)`      | Compares arrays.           | `equal(arr1, arr1+5, arr2);`        |
| `swap_ranges(arr1, arr1+n, arr2)`| Swaps two arrays.          | `swap_ranges(arr1, arr1+5, arr2);`  |
| `rotate(arr, arr+k, arr+n)`      | Rotates array left.        | `rotate(arr, arr+2, arr+5);`        |
| `next_permutation(arr, arr+n)`   | Next permutation.          | `next_permutation(arr, arr+5);`     |
| `prev_permutation(arr, arr+n)`   | Previous permutation.      | `prev_permutation(arr, arr+5);`     |
| `unique(arr, arr+n)`             | Removes duplicates.        | `unique(arr, arr+5) - arr;`         |

---

Let me know if you need **more topics like Strings, Vectors, Maps**! 🚀
