# 📚 Data Structure Learning (C++)

> A personal repository for learning data structures with C++, including code implementations and notes.

---

## 🧠 项目简介

这是一个用于记录我学习**数据结构（Data Structures）**过程的仓库，主要包括：

* 📖 知识点笔记（Markdown）
* 💻 C++代码实现
* 🔁 学习过程记录

适合：

* 数据结构初学者
* 复习基础算法的人
* 想看简单实现代码的人

---

## 🛠️ 技术栈

* 语言：C++
* 工具：Git + GitHub
* 编辑器：任意（如 Dev-C++ / VS Code）

---

## 📂 项目结构

```text
data-structure-learning
│
├── array/                 # 数组基础
│   ├── notes.md
│   └── array.cpp
│
├── SeqList/              # 顺序表（基于数组实现）
│   ├── SeqList.h
│   ├── SeqList.cpp
│   └── README.md
│
└── README.md             # 项目说明（本文件）
```

---

## 📌 当前已实现内容

### ✅ 数组（Array）

* 基本概念
* 特点分析（O(1)访问 / O(n)插入删除）
* 简单代码示例

### ✅ 顺序表（SeqList）

* 初始化（Init）
* 插入（Insert）
* 删除（Remove）
* 查找（Find）
* 输出（Print）

---

## 🚀 示例代码

```cpp
SeqList L;
Init(L);

Insert(L, 0, 10);
Insert(L, 1, 20);
Insert(L, 2, 30);

Print(L);

int pos = Find(L, 20);
cout << "位置：" << pos << endl;
```

---

## 📖 学习进度

* [x] 数组（Array）
* [x] 顺序表（SeqList）
* [ ] 单链表（Linked List）
* [ ] 栈（Stack）
* [ ] 队列（Queue）
* [ ] 树（Tree）
* [ ] 图（Graph）

---

## 🎯 学习目标

* 掌握基础数据结构原理
* 熟练用 C++ 实现常见结构
* 理解时间复杂度（Big-O）
* 为算法学习打基础

---

## 💡 说明

* 本仓库代码以**学习为主**，可能不是最优实现
* 欢迎参考，但建议自己动手实现一遍

---

## 📬 联系方式

如果你也在学习数据结构，欢迎一起交流！

---

⭐ 如果这个仓库对你有帮助，可以点个 Star~
