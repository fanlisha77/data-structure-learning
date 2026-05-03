# 数组（Array）

## 📌 概念
数组是一种连续存储的数据结构，可以通过索引快速访问元素。

## ✅ 特点
- 支持随机访问（O(1)）
- 插入和删除较慢（O(n)）
- 内存连续

- ## 📊 时间复杂度

- 查找：O(1)
- 插入：O(n)
- 删除：O(n)
  
## 💻 示例代码（C++）

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3] = {1, 2, 3};
    cout << arr[0] << endl;
    return 0;
}

