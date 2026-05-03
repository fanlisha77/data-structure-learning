# 📚 单链表（Linked List）完整学习笔记（C++）

---

## 一、什么是单链表？

单链表是一种**线性数据结构**，由一系列节点组成，每个节点包含：

* 数据域（data）
* 指针域（next）

```text
head → [data | next] → [data | next] → ... → NULL
```

---

## 二、节点定义（C++）

```cpp
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
```

---

## 三、头指针 vs 头节点

| 名称        | 含义        |
| --------- | --------- |
| 头指针（head） | 指向链表第一个节点 |
| 头节点       | 实际的第一个节点  |

通常我们使用：

```cpp
Node* head = nullptr;
```

---

## 四、尾插法（Append）

### 原理

```text
找到最后一个节点 → 接上新节点
```

### 代码

```cpp
void append(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}
```

---

## 五、头插法（Head Insert）

### 原理

```text
新节点 → 指向原 head
head → 指向新节点
```

### 代码

```cpp
void headInsert(Node*& head, int val) {
    Node* newNode = new Node(val);

    newNode->next = head;
    head = newNode;
}
```

---

## 六、遍历链表

```cpp
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}
```

---

## 七、查找（按值）

```cpp
int find(Node* head, int val) {
    Node* temp = head;
    int index = 0;

    while (temp != nullptr) {
        if (temp->data == val) {
            return index;
        }
        temp = temp->next;
        index++;
    }

    return -1;
}
```

---

## 八、删除（按值）

```cpp
void deleteByValue(Node*& head, int val) {
    if (head == nullptr) return;

    // 删除头节点
    if (head->data == val) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* cur = head;
    while (cur->next != nullptr && cur->next->data != val) {
        cur = cur->next;
    }

    if (cur->next != nullptr) {
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
}
```

---

## 九、删除（按位置）

```cpp
void deleteAt(Node*& head, int k) {
    if (head == nullptr || k < 0) return;

    if (k == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* cur = head;
    for (int i = 0; i < k - 1 && cur != nullptr; i++) {
        cur = cur->next;
    }

    if (cur != nullptr && cur->next != nullptr) {
        Node* temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
}
```

---

## 十、释放链表（防止内存泄漏）

```cpp
void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}
```

---

## 十一、完整 main 示例

```cpp
int main() {
    Node* head1 = nullptr;

    // 尾插法
    append(head1, 1);
    append(head1, 2);
    append(head1, 3);
    append(head1, 4);

    cout << "尾插法链表:" << endl;
    printList(head1);

    // 头插法（新链表）
    Node* head2 = nullptr;
    headInsert(head2, 1);
    headInsert(head2, 2);
    headInsert(head2, 3);
    headInsert(head2, 4);

    cout << "头插法链表:" << endl;
    printList(head2);

    // 查找
    cout << "查找 3 的位置: " << find(head1, 3) << endl;

    // 删除
    deleteByValue(head1, 2);
    cout << "删除2后: ";
    printList(head1);

    // 释放
    freeList(head1);
    freeList(head2);

    return 0;
}
```

---

## 十二、常见错误总结

### ❌ 1. 忘记初始化 head

```cpp
Node* head; // ❌
```

✅ 正确：

```cpp
Node* head = nullptr;
```

---

### ❌ 2. 函数调用写成声明

```cpp
append(Node*& head, 1); // ❌
```

✅ 正确：

```cpp
append(head, 1);
```

---

### ❌ 3. void 函数返回值

```cpp
void find(...) {
    return 1; // ❌
}
```

---

### ❌ 4. 忘记 delete

```text
会导致内存泄漏
```

---

## 🎯 总结

```text
单链表核心 = 指针连接（next）
```

你必须掌握：

* 插入（头插 / 尾插）
* 删除（按值 / 按位置）
* 遍历
* 查找
* 内存释放

---

## 🚀 下一步建议

* 反转链表（最重要）
* 快慢指针（找中点）
* 合并链表

---

> 💡 学会链表的关键：多画图 + 多调试 + 理解指针方向
