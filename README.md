# 通讯录管理系统（C++）

大一第一个 C++ 小项目，用来把结构体、指针、数组、函数串起来练一遍。约 345 行，单文件，无第三方依赖。

## 功能

- 添加联系人（姓名 / 性别 / 年龄 / 电话 / 住址）
- 显示全部、按姓名查找
- 修改、删除、清空
- 按姓名排序
- 文件存档：退出自动保存，启动自动读取

## 编译运行

Windows + MinGW（g++ 13）或 Visual Studio 2022：

    g++ -std=c++17 contacts.cpp -o contacts
    ./contacts

## 代码结构

- `struct Person`：一条联系人记录
- `struct AddressBook`：挂 `Person` 数组 + 当前人数 `size`
- 九个功能函数：添加 / 显示 / 查找 / 修改 / 删除 / 清空 / 排序 / 存档 / 读档
- `main`：菜单循环

## 我踩过的坑

1. （换成你真实遇到的，写 1–2 句就行）
2. （比如：删除后忘了 size--，导致显示出现空行）
3. （比如：fstream 忘了判断 is_open()，文件不存在时静默读到空数据）

## 下一步

- [ ] 改写成 class 版本（配合第 10 周「类和对象」）
- [ ] 用 std::vector 替掉定长数组，去掉人数上限
- [ ] 尝试二进制读写
<img width="1270" height="752" alt="屏幕截图 2026-10-30 220609" src="https://github.com/user-attachments/assets/b6979fee-9eb7-48e4-bbcc-f94c719102b9" />
