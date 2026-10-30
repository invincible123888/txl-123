#include <iostream>
#include <string>

using namespace std;

#define MAX 1000        

// 联系人结构体
struct Person
{
    string m_Name;      // 姓名
    int    m_Sex;       // 性别：1 男，2 女
    int    m_Age;       // 年龄
    string m_Phone;     // 联系电话
    string m_Address;   // 家庭住址
};

// 通讯录结构体
struct Addressbooks
{
    struct Person personArray[MAX];   // 联系人数组
    int           m_Size;             // 当前记录人数
};

void showMenu();                               // 菜单
void addPerson(Addressbooks * abs);            // 1.添加联系人
void showPerson(Addressbooks * abs);           // 2.显示联系人
int  isExist(Addressbooks * abs, string name); // 检测联系人是否存在
void deletePerson(Addressbooks * abs);         // 3.删除联系人
void findPerson(Addressbooks * abs);           // 4.查找联系人
void modifyPerson(Addressbooks * abs);         // 5.修改联系人
void cleanPerson(Addressbooks * abs);          // 6.清空联系人

int main()
{
    // 创建通讯录对象，并初始化人数为 0
    Addressbooks abs;
    abs.m_Size = 0;

    int select = 0;         // 用户选择

    while (true)
    {
        showMenu();         // 显示菜单
        cout << "请输入您的选择：";
        cin >> select;

        switch (select)
        {
        case 1:             // 添加
            addPerson(&abs);        
            break;
        case 2:             // 显示
            showPerson(&abs);
            break;
        case 3:             // 删除
            deletePerson(&abs);
            break;
        case 4:             // 查找
            findPerson(&abs);
            break;
        case 5:             // 修改
            modifyPerson(&abs);
            break;
        case 6:             // 清空
            cleanPerson(&abs);
            break;
        case 0:             // 退出
            cout << "欢迎下次使用" << endl;
            system("pause");
            return 0;
        default:            // 输入有误
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }

    system("pause");
    return 0;
}

/* =============== 菜单界面 =============== */

void showMenu()
{
    cout << "***************************" << endl;
    cout << "*****  通 讯 录 系 统  *****" << endl;
    cout << "*****  1、添加联系人  *****" << endl;
    cout << "*****  2、显示联系人  *****" << endl;
    cout << "*****  3、删除联系人  *****" << endl;
    cout << "*****  4、查找联系人  *****" << endl;
    cout << "*****  5、修改联系人  *****" << endl;
    cout << "*****  6、清空联系人  *****" << endl;
    cout << "*****  0、退出通讯录  *****" << endl;
    cout << "***************************" << endl;
}

/* =============== 1. 添加联系人 =============== */

void addPerson(Addressbooks * abs)
{
    // 判断通讯录是否已满
    if (abs->m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        // ① 姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_Size].m_Name = name;

        // ② 性别（循环校验，只能输入 1 或 2）
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_Size].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // ③ 年龄（笔记建议：可借鉴性别处的 while 循环防止输入错误）
        cout << "请输入年龄：" << endl;
        int age = 0;
        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                abs->personArray[abs->m_Size].m_Age = age;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // ④ 联系电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_Size].m_Phone = phone;

        // ⑤ 家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[abs->m_Size].m_Address = address;

        // 更新通讯录中的人数
        abs->m_Size++;
        cout << "添加成功" << endl;

        system("pause");    // 请按任意键继续...
        system("cls");      // 清屏，回到菜单
    }
}

/* =============== 2. 显示联系人 =============== */

void showPerson(Addressbooks * abs)
{
    if (abs->m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < abs->m_Size; i++)
        {
            // 用 "\t" 水平制表符让输出更整齐；性别用三目运算符转成"男/女"
            cout << "姓名：" << abs->personArray[i].m_Name << "\t";
            cout << "性别：" << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
            cout << "年龄：" << abs->personArray[i].m_Age << "\t";
            cout << "电话：" << abs->personArray[i].m_Phone << "\t";
            cout << "住址：" << abs->personArray[i].m_Address << endl;
        }
    }

    system("pause");
    system("cls");
}

/* =============== 3. 删除联系人 =============== */

// ① 检测联系人是否存在：存在返回下标，不存在返回 -1
int isExist(Addressbooks * abs, string name)
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if (abs->personArray[i].m_Name == name)
        {
            return i;
        }
    }
    return -1;      // 遍历结束仍未找到
}

// ② 删除联系人：后面的人依次前移，总人数 -1
void deletePerson(Addressbooks * abs)
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);   // 先查找

    if (ret != -1)                  // 找到了
    {
        // 数据前移：从被删位置开始，把后面的人逐个向前覆盖
        for (int i = ret; i < abs->m_Size - 1; i++)
        {
            abs->personArray[i] = abs->personArray[i + 1];
        }

        abs->m_Size--;              // 更新通讯录中的人数
        cout << "删除成功" << endl;
    }
    else                            // 没找到
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

/* =============== 4. 查找联系人 =============== */

void findPerson(Addressbooks * abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
        cout << "性别：" << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
        cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
        cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_Address << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

/* =============== 5. 修改联系人 =============== */

void modifyPerson(Addressbooks * abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);

    if (ret != -1)
    {
        // 与添加联系人的输入过程相同，
        // 只是把 [abs->m_Size] 换成 [ret]

        // ① 姓名
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_Name = name;

        // ② 性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[ret].m_Sex = sex;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // ③ 年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                abs->personArray[ret].m_Age = age;
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // ④ 联系电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_Phone = phone;

        // ⑤ 家庭住址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_Address = address;

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

/* =============== 6. 清空联系人 =============== */

void cleanPerson(Addressbooks * abs)
{
    abs->m_Size = 0;        // 逻辑清空：人数置 0，即视为空
    cout << "通讯录已清空" << endl;

    system("pause");
    system("cls");
}
