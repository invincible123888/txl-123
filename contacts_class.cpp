#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#define MAX 1000

// ============================================================
// 一、Person 类：一个联系人
// ============================================================
class Person
{
public:
    // 姓名
    void setName(string name) { m_Name = name; }
    string getName() const { return m_Name; }

    // 性别：1 = 男，2 = 女
    void setSex(int sex) { if (sex != 1 && sex != 2) return; m_Sex = sex; }
    int  getSex() const { return m_Sex; }

    // 年龄
    void setAge(int age) {if (age < 0 || age > 150) return; m_Age = age; }
    int  getAge() const { return m_Age; }

    // 电话
    void setPhone(string phone) { m_Phone = phone; }
    string getPhone() const { return m_Phone; }

    // 地址
    void setAddress(string address) { m_Address = address; }
    string getAddress() const { return m_Address; }

private:
    string m_Name;      // 姓名
    int    m_Sex   = 0; // 性别
    int    m_Age   = 0; // 年龄
    string m_Phone;     // 电话
    string m_Address;   // 地址
};

// ============================================================
// 二、Addressbook 类：通讯录本体（数据 + 全部操作都封装在里面）
// ============================================================
class Addressbook
{
public:
    Addressbook();          // 构造：把人数初始化为 0

    void showMenu();        // 菜单 + 主循环，整个程序从这里跑起来

    void addPerson();       // 1、添加联系人
    void showPerson() const;// 2、显示联系人
    void deletePerson();    // 3、删除联系人
    void findPerson() const;// 4、查找联系人
    void modifyPerson();    // 5、修改联系人
    void cleanPerson();     // 6、清空联系人

    int isExist(string name) const;   // 按姓名找下标，找不到返回 -1

private:
    Person personArray[MAX]; // 联系人数组，最大 1000 人
    int    m_Size = 0;       // 当前记录人数
};

// ============================================================
// 三、类外实现地址簿的成员函数
// ============================================================

// 构造函数：初始化人数为 0
Addressbook::Addressbook()
{
    m_Size = 0;
}

// 菜单界面
void Addressbook::showMenu()
{
    int choice = 0;

    while (true)
    {
        cout << "*******************************" << endl;
        cout << "*****   通 讯 录 系 统   *****" << endl;
        cout << "*****   1、添加联系人    *****" << endl;
        cout << "*****   2、显示联系人    *****" << endl;
        cout << "*****   3、删除联系人    *****" << endl;
        cout << "*****   4、查找联系人    *****" << endl;
        cout << "*****   5、修改联系人    *****" << endl;
        cout << "*****   6、清空联系人    *****" << endl;
        cout << "*****   0、退出通讯录    *****" << endl;
        cout << "*******************************" << endl;

        cout << "请输入您的选择：";
        cin >> choice;

        switch (choice)
        {
        case 1:                 // 1、添加联系人
            addPerson();
            break;
        case 2:                 // 2、显示联系人
            showPerson();
            break;
        case 3:                 // 3、删除联系人
            deletePerson();
            break;
        case 4:                 // 4、查找联系人
            findPerson();
            break;
        case 5:                 // 5、修改联系人
            modifyPerson();
            break;
        case 6:                 // 6、清空联系人
            cleanPerson();
            break;
        case 0:                 // 0、退出通讯录
            cout << "欢迎下次使用" << endl;
            return;
        default:
            cout << "输入有误，请重新输入" << endl;
            break;
        }
    }
}

// 1、添加联系人
void Addressbook::addPerson()
{
    // 判断通讯录是否已满
    if (m_Size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        system("pause");
        system("cls");
        return;
    }

    // ① 姓名
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    personArray[m_Size].setName(name);

    // ② 性别（只允许 1 或 2）
    int sex = 0;
    cout << "请输入性别：" << endl;
    cout << "1 --- 男" << endl;
    cout << "2 --- 女" << endl;
    while (true)
    {
        cin >> sex;
        if (sex == 1 || sex == 2)
        {
            personArray[m_Size].setSex(sex);
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    // ③ 年龄（0 ~ 150 之间）
    int age = 0;
    cout << "请输入年龄：" << endl;
    while (true)
    {
        cin >> age;
        if (age >= 0 && age <= 150)
        {
            personArray[m_Size].setAge(age);
            break;
        }
        cout << "输入有误，请重新输入" << endl;
    }

    // ④ 电话
    string phone;
    cout << "请输入联系电话：" << endl;
    cin >> phone;
    personArray[m_Size].setPhone(phone);

    // ⑤ 地址
    string address;
    cout << "请输入家庭地址：" << endl;
    cin >> address;
    personArray[m_Size].setAddress(address);

    // 更新通讯录人数
    m_Size++;

    cout << "添加成功" << endl;
    system("pause");
    system("cls");
}

// 2、显示联系人
void Addressbook::showPerson() const
{
    if (m_Size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else
    {
        for (int i = 0; i < m_Size; i++)
        {
            cout << "姓名：" << personArray[i].getName() << "\t"
                 << "性别：" << (personArray[i].getSex() == 1 ? "男" : "女") << "\t"
                 << "年龄：" << personArray[i].getAge() << "\t"
                 << "电话：" << personArray[i].getPhone() << "\t"
                 << "地址：" << personArray[i].getAddress() << endl;
        }
    }

    system("pause");
    system("cls");
}

// 判断联系人是否存在：存在返回下标，不存在返回 -1
int Addressbook::isExist(string name) const
{
    for (int i = 0; i < m_Size; i++)
    {
        if (personArray[i].getName() == name)
        {
            return i;
        }
    }
    return -1;
}

// 3、删除联系人（后面的数据整体前移一位）
void Addressbook::deletePerson()
{
    cout << "请输入您要删除的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(name);
    if (ret != -1)
    {
        // 从被删除位置开始，后面的人往前挪一格
        for (int i = ret; i < m_Size - 1; i++)
        {
            personArray[i] = personArray[i + 1];
        }
        m_Size--;   // 更新通讯录人数
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

// 4、查找联系人
void Addressbook::findPerson() const
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(name);
    if (ret != -1)
    {
        cout << "姓名：" << personArray[ret].getName() << "\t"
             << "性别：" << (personArray[ret].getSex() == 1 ? "男" : "女") << "\t"
             << "年龄：" << personArray[ret].getAge() << "\t"
             << "电话：" << personArray[ret].getPhone() << "\t"
             << "地址：" << personArray[ret].getAddress() << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

// 5、修改联系人（找到后把 5 个字段重新录入一遍）
void Addressbook::modifyPerson()
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(name);
    if (ret != -1)
    {
        // 姓名
        cout << "请输入姓名：" << endl;
        cin >> name;
        personArray[ret].setName(name);

        // 性别
        int sex = 0;
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                personArray[ret].setSex(sex);
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // 年龄
        int age = 0;
        cout << "请输入年龄：" << endl;
        while (true)
        {
            cin >> age;
            if (age >= 0 && age <= 150)
            {
                personArray[ret].setAge(age);
                break;
            }
            cout << "输入有误，请重新输入" << endl;
        }

        // 电话
        string phone;
        cout << "请输入联系电话：" << endl;
        cin >> phone;
        personArray[ret].setPhone(phone);

        // 地址
        string address;
        cout << "请输入家庭地址：" << endl;
        cin >> address;
        personArray[ret].setAddress(address);

        cout << "修改成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    system("pause");
    system("cls");
}

// 6、清空联系人（把人数清零即可，旧数据会被后续添加覆盖）
void Addressbook::cleanPerson()
{
    m_Size = 0;
    cout << "通讯录已清空" << endl;

    system("pause");
    system("cls");
}

// ============================================================
// 四、主函数：对象一建，全部逻辑都在类里
// ============================================================
int main()
{
    Addressbook abs;    // 创建通讯录对象（人数自动初始化为 0）
    abs.showMenu();     // 菜单 + 主循环

    return 0;
}
