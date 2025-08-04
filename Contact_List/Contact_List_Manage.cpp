#include <iostream>
#include <string>
using namespace std;

//联系人结构体
struct Person {
	string m_Name; //姓名
	int m_Sex;		//性别 1；男，2：女
	int m_Age;		//年龄
	string m_Phone;	//电话
	string m_Addr;	//地址
};
//通讯录结构体
#define MAX  10
struct AddresBooks {
	struct Person PersonArray[MAX];
	int m_Size;
};




void showMenu() {
	cout << "1、添加联系人" << endl;
	cout << "2、显示联系人" << endl;
	cout << "3、删除联系人" << endl;
	cout << "4、查找联系人" << endl;
	cout << "5、修改联系人" << endl;
	cout << "6、清空联系人" << endl;
	cout << "0、退出" << endl;
	cout << "*************" << endl;
}
//添加联系人
void addPerson(AddresBooks* abs) {
	if (abs->m_Size >= MAX) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//添加具体联系人
		string name;
		cout << "请输入姓名：" ;
		cin >> name;
		abs->PersonArray[abs->m_Size].m_Name = name;

		int sex;
		cout << "请输入性别（1；男，2：女）：";	
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->PersonArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误！！" << endl;
			}
		}

		int age;
		cout << "请输入年龄：";
		cin >> age;
		abs->PersonArray[abs->m_Size].m_Age = age;

		string phone;
		cout << "请输入电话：";
		cin >> phone;
		abs->PersonArray[abs->m_Size].m_Phone = phone;

		string address;
		cout << "请输入地址：";
		cin >> address;
		abs->PersonArray[abs->m_Size].m_Addr = address;

		//更新通讯录计数
		abs->m_Size++;
		cout << "添加成功。" << endl;

		//system("pause")  //按任意键继续
		//system("cls")		//清屏
	}
}

//显示联系人
void showPerson(AddresBooks* abs) {
	//判断通讯录记录是否空
	if (abs->m_Size == 0) {
		cout << "记录为空。" << endl;
	}
	else {
		for (int i = 0; i < abs->m_Size; i++) {
			cout << "姓名：" << abs->PersonArray[i].m_Name << " \t"
				<< "性别：" << (abs->PersonArray[i].m_Sex == 1 ? "男" : "女") << " \t"
				<< "年龄：" << abs->PersonArray[i].m_Age << " \t"
				<< "电话：" << abs->PersonArray[i].m_Phone << " \t"
				<< "地址：" << abs->PersonArray[i].m_Addr << endl;
		}
	}
}

//删除联系人
void deletePerson(AddresBooks* abs) {
	string name;
	cout << "请输入要删除的联系人：" ;
	cin >> name;
	//检测是否存在
	int record = -1;
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->PersonArray[i].m_Name == name) {
			record = i;
		}
	}

	if (record == -1) {
		cout << "查无此人！！" << endl;
	}
	else {
		for (int i = record; i < (abs->m_Size -1); i++) {
			abs->PersonArray[i] = abs->PersonArray[i + 1];
		}
		abs->m_Size--;
		cout << "删除成功。" << endl;
	}
}

//查找联系人
void findPerson(AddresBooks* abs) {
	string name;
	cout << "请输入要查找的联系人：";
	cin >> name;

	int record = -1;
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->PersonArray[i].m_Name == name) {
			record = i;
		}
	}

	if (record == -1) {
		cout << "查无此人！！" << endl;
	}
	else {
		cout << "姓名：" << abs->PersonArray[record].m_Name << " \t"
			<< "性别：" << (abs->PersonArray[record].m_Sex == 1 ? "男" : "女") << " \t"
			<< "年龄：" << abs->PersonArray[record].m_Age << " \t"
			<< "电话：" << abs->PersonArray[record].m_Phone << " \t"
			<< "地址：" << abs->PersonArray[record].m_Addr << endl;
	}
}

void modifyPerson(AddresBooks* abs) {
	string name;
	cout << "请输入要修改的联系人：";
	cin >> name;

	int record = -1;
	for (int i = 0; i < abs->m_Size; i++) {
		if (abs->PersonArray[i].m_Name == name) {
			record = i;
		}
	}

	if (record == -1) {
		cout << "查无此人！！" << endl;
	}
	else {
		int sex;
		cout << "请输入性别（1；男，2：女）：";
		while (1) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->PersonArray[record].m_Sex = sex;
				break;
			}
			else {
				cout << "输入有误！！" << endl;
			}
		}

		int age;
		cout << "请输入年龄：";
		cin >> age;
		abs->PersonArray[record].m_Age = age;

		string phone;
		cout << "请输入电话：";
		cin >> phone;
		abs->PersonArray[record].m_Phone = phone;

		string address;
		cout << "请输入地址：";
		cin >> address;
		abs->PersonArray[record].m_Addr = address;

		cout << "修改成功。" << endl;
	}
}

void cleanPerson(AddresBooks* abs) {
	abs->m_Size = 0;
	cout << "清空成功。" << endl;
}
int selectMenu() {
	int select = -1;

	//创建通讯录结构体成员变量
	AddresBooks abs;
	abs.m_Size = 0;

	while (1) {
		cout << "输入选择：" ;
		// 检查输入是否成功
		if (!(cin >> select)) {
			// 清除错误状态
			cin.clear();
			// 丢弃无效输入（清空缓冲区）
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "错误：请输入有效的整数！" << endl;
			
		}else {
			switch (select) {
			case 1: //1、添加联系人
				addPerson(&abs);
				break;
			case 2:	//2、显示联系人
				showPerson(&abs);
				break;
			case 3:	//3、删除联系人
				deletePerson(&abs);
				break;
			case 4:	//4、查找联系
				findPerson(&abs);
				break;
			case 5:	//5、修改联系人
				modifyPerson(&abs);
				break;
			case 6:	//6、清空联系人
				cleanPerson(&abs);
				break;
			case 0:	//0、退出
				cout << "欢迎下次使用" << endl;
				return 0;
				break;
			default:
				cout << "输入错误！！" << endl;
				break;
			}
		}
	}
	return 0;
}
int main() {
	//调用菜单
	showMenu();
	//菜单选择
	selectMenu();
	
	return 0;
}