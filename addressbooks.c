#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include<assert.h>

#define MAX 100//通讯录最大人数

//菜单
void menu();
//添加联系人
void addPerson(struct Addressbooks* abs);
//显示联系人
void showPerson(struct Addressbooks* abs);
//查找联系人
void findPerson(struct Addressbooks* abs);
//删除联系人
void deletePerson(struct Addressbooks* abs);
//修改联系人
void modifyPerson(struct Addressbooks* abs);
//统计联系人
void totalPerson(struct Addressbooks* abs);
//排序
void sortPerson(struct Addressbooks* abs);
//插入联系人
void inSertPerson(struct Addressbooks* abs);
//清空联系人
void cleanPerson(struct Addressbooks* abs);

//联系人结构体
struct Person
{
	//姓名
	char m_name[20];
	//性别
	int m_sex;//1、男  2、女
	//年龄
	int m_age;
	//电话
	char m_phone[20];
	//住址
	char m_addr[50];
	//工作单位
	char m_job[30];	
};

//设计通讯录结构体
struct Addressbooks
{
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];

	//通讯录中当前记录联系人个数
	int m_Size;
};

//菜单 
void menu()
{

	system("cls");

	printf("\n\n\n");

	printf("\t\t\t\t\t**************************************\n");

	printf("\t\t\t\t\t************通讯录管理系统************\n");

	printf("\t\t\t\t\t======================================\n");

	printf("\t\t\t\t\t*          1.录入联系人信息          *\n");

	printf("\t\t\t\t\t*          2.显示所有联系人          *\n");

	printf("\t\t\t\t\t*          3.查找联系人信息          *\n");

	printf("\t\t\t\t\t*          4.删除联系人信息          *\n");

	printf("\t\t\t\t\t*          5.修改联系人信息          *\n");

	printf("\t\t\t\t\t*          6.插入联系人信息          *\n");

	printf("\t\t\t\t\t*          7.排序                    *\n");

	printf("\t\t\t\t\t*          8.统计联系人总数          *\n");

	printf("\t\t\t\t\t*          9.清空所有联系人          *\n");

	printf("\t\t\t\t\t*          0.退出系统                *\n");

	printf("\t\t\t\t\t======================================\n");

	printf("\t\t\t\t\t**************************************\n");

	printf("\t\t\t\t\t          请选择(0-9):");
}

//添加联系人
void addPerson(struct Addressbooks* abs)
{
	//判断通讯录是否已满，如果满了就不在添加
	if (abs->m_Size == MAX)
	{
		printf("通讯录已满，无法添加！\n");

		return;
	}
	else
	{
		//添加具体的联系人

		//姓名
		char name[20];
		printf("请输入姓名：");
		scanf("%s", name);
		strcpy(abs->personArray[abs->m_Size].m_name, name);
		//abs->personArray[abs->m_Size].m_name = name;
		printf("\n");

		//性别
		printf("请输入性别：\n");
		printf("1---男\n");
		printf("2---女\n");

		int sex = 0;
		while (1)
		{
			//如果输入的是1或是2可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			scanf("%d", &sex);

			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			printf("输入有误，请重新输入\n");
		}
		printf("\n");

		//年龄
		printf("请输入年龄：");
		int age = 0;
		while (1)
		{
			scanf("%d", &age);

			if (age < 120 && age>3)
			{
				abs->personArray[abs->m_Size].m_age = age;
				break;
			}
			printf("输入有误，请重新输入\n");
		}
		printf("\n");

		//电话
		printf("请输入联系电话：");
		char phone[20];
		scanf("%s", phone);
		strcpy(abs->personArray[abs->m_Size].m_phone, phone);
		//abs->personArray[abs->m_Size].m_phone = phone;
		printf("\n");

		//住址
		printf("请输入住址：");
		char address[50];
		scanf("%s", address);
		strcpy(abs->personArray[abs->m_Size].m_addr, address);
		//abs->personArray[abs->m_Size].m_addr = address;
		printf("\n");

		//工作单位
		printf("请输入工作单位：");
		char job[30];
		scanf("%s", job);
		strcpy(abs->personArray[abs->m_Size].m_job, job);
		//abs->personArray[abs->m_Size].m_job = job;
		printf("\n");

		//更新通讯录人数
		abs->m_Size++;

		printf("添加成功\n");

		system("pause");
		system("cls");//清屏
	}
	
}

//显示联系人
void showPerson(struct Addressbooks* abs)
{
	//判断通讯录中的人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		printf("当前记录为空\n");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			printf("姓名：");
			printf("%s", abs->personArray[i].m_name);
			printf("\t性别：");
			printf("%s", abs->personArray[i].m_sex == 1 ? "男" : "女");
			printf("\t年龄：");
			printf("%d", abs->personArray[i].m_age);
			printf("\t电话：");
			printf("%s", abs->personArray[i].m_phone);
			printf("\t住址：");
			printf("%s", abs->personArray[i].m_addr);
			printf("\t工作地址：");
			printf("%s", abs->personArray[i].m_job);
			printf("\n");

		}
	}

	system("pause");
	system("cls");
}

//查找联系人
void findPerson(struct Addressbooks* abs)
{
	printf("请输入您要查找的联系人：");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//查询联系人的位置
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name,name) == 0)
		{
			ret = i;
		}
	}

	//判断
	if (ret != -1)
	{
		printf("姓名：%s", abs->personArray[ret].m_name);
		printf("\t性别：%s", abs->personArray[ret].m_sex == 1 ? "男" : "女");
		printf("\t年龄：%d", abs->personArray[ret].m_age);
		printf("\t电话：%s", abs->personArray[ret].m_phone);
		printf("\t住址：%s", abs->personArray[ret].m_addr);
		printf("\t工作地址：%s", abs->personArray[ret].m_job);
		printf("\n");
	}
	else
	{
		printf("查无此人\n");
	}

	system("pause");
	system("cls");

}

//删除联系人
void deletePerson(struct Addressbooks* abs)
{
	printf("请输入删除的联系人\n");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//查询联系人的位置
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name, name) == 0)
		{
			ret = i;
		}
	}

	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_Size; i++)
		{
			//数据前移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//更新通讯录中的人员数
		printf("删除成功\n");

		//更新联系人
		abs->m_Size--;
	}
	else
	{
		printf("查无此人\n");
	}

	system("pause");
	system("cls");

}

//修改联系人
void modifyPerson(struct Addressbooks* abs)
{
	printf("请输入您要修改的联系人：");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//查询联系人的位置
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name, name) == 0)
		{
			ret = i;
		}
	}

	if (ret != -1)
	{
		//输入修改联系人的信息

		//姓名
		char name[20];
		printf("请输入姓名：");
		scanf("%s", name);
		strcpy(abs->personArray[ret].m_name, name);
		//abs->personArray[abs->m_Size].m_name = name;
		printf("\n");

		//性别
		printf("请输入性别：\n");
		printf("1---男\n");
		printf("2---女\n");

		int sex = 0;
		while (1)
		{
			//如果输入的是1或是2可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			scanf("%d", &sex);

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			printf("输入有误，请重新输入\n");
		}
		printf("\n");

		//年龄
		printf("请输入年龄：");
		int age = 0;
		while (1)
		{
			scanf("%d", &age);

			if (age < 120 && age>3)
			{
				abs->personArray[ret].m_age = age;
				break;
			}
			printf("输入有误，请重新输入\n");
		}
		printf("\n");

		//电话
		printf("请输入联系电话：");
		char phone[20];
		scanf("%s", phone);
		strcpy(abs->personArray[ret].m_phone, phone);
		//abs->personArray[abs->m_Size].m_phone = phone;
		printf("\n");

		//住址
		printf("请输入住址：");
		char address[50];
		scanf("%s", address);
		strcpy(abs->personArray[ret].m_addr, address);
		//abs->personArray[abs->m_Size].m_addr = address;
		printf("\n");

		//工作单位
		printf("请输入工作单位：");
		char job[30];
		scanf("%s", job);
		strcpy(abs->personArray[ret].m_job, job);
		//abs->personArray[abs->m_Size].m_job = job;
		printf("\n");

		printf("修改成功\n");

	}
	else
	{
		printf("查无此人\n");
	}

	system("pause");
	system("cls");//清屏

}

//统计联系人
void totalPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		printf("通讯录无联系人\n");
	}
	else
	{
		printf("您一个有%d位联系人\n", abs->m_Size);
		THERE:
		printf("是否打印所有人：(y/n)\n");
		printf("y---Yes\n");
		printf("n---No\n");
		char yn[10];
		scanf("%s", yn);
		if (strcmp(yn, "y") == 0)
		{
			showPerson(abs);   //打印所有联系人
		}
		else if (strcmp(yn, "n") == 0)
		{
			system("pause");
		}
		else
		{
			printf("输入错误，请重新输入\n");
			goto THERE;
		}

	}

	system("pause");
	system("cls");
}

//插入联系人
void inSertPerson(struct Addressbooks* abs)
{
	printf("请输入您想添加的联系人在另一联系人前面的名字：");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//查询联系人的位置
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name, name) == 0)
		{
			ret = i;
		}
	}

	if (ret != -1)
	{
		for (int j = abs->m_Size - 1; j >= ret; j--)
		{
			//元素后移
			abs->personArray[j + 1] = abs->personArray[j];
		}

		//输入所要插入联系人的信息

		//姓名
		char name[20];
		printf("请输入姓名：");
		scanf("%s", name);
		strcpy(abs->personArray[ret].m_name, name);
		//abs->personArray[abs->m_Size].m_name = name;
		printf("\n");

		//性别
		printf("请输入性别：\n");
		printf("1---男\n");
		printf("2---女\n");

		int sex = 0;
		while (1)
		{
			//如果输入的是1或是2可以退出循环，因为输入的是正确值
			//如果输入有误，重新输入
			scanf("%d", &sex);

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			printf("输入有误，请重新输入\n");
		}
		printf("\n");

		//年龄
		printf("请输入年龄：");
		int age = 0;
		while (1)
		{
			scanf("%d", &age);
			//判断年龄是否合法
			if (age < 120 && age>3)
			{
				abs->personArray[ret].m_age = age;
				break;
			}
			printf("输入有误，请重新输入\n");
		}
		printf("\n");

		//电话
		printf("请输入联系电话：");
		char phone[20];
		scanf("%s", phone);
		strcpy(abs->personArray[ret].m_phone, phone);
		//abs->personArray[abs->m_Size].m_phone = phone;
		printf("\n");

		//住址
		printf("请输入住址：");
		char address[50];
		scanf("%s", address);
		strcpy(abs->personArray[ret].m_addr, address);
		//abs->personArray[abs->m_Size].m_addr = address;
		printf("\n");

		//工作单位
		printf("请输入工作单位：");
		char job[30];
		scanf("%s", job);
		strcpy(abs->personArray[ret].m_job, job);
		//abs->personArray[abs->m_Size].m_job = job;
		printf("\n");

		abs->m_Size++;

		printf("插入成功\n");
	}
	else
	{
		printf("查无此人！\n");
	}

	system("pause");
	system("cls");
}

//排序
void sortPerson(struct Addressbooks* abs)
{
	THER:
	printf("请选择如何排序：\n");
	printf("1---性别\n");
	printf("2---年龄\n");
	int ret = 0;
	scanf("%d", &ret);

	if (ret = 1)
	{
		//冒泡排序
		for (int i = 0; i < abs->m_Size - 1; i++)
		{
			for (int j = 0; j < abs->m_Size - i - 1; j++)
			{
				if (abs->personArray[j].m_sex > abs->personArray[j + 1].m_sex)
				{
					struct Person temp = abs->personArray[j];
					abs->personArray[j] = abs->personArray[j + 1];
					abs->personArray[j + 1] = temp;
				}
			}
		}
		//排序完成后显示所有联系人
		showPerson(abs);
	}
	else if (ret == 2)
	{
		//冒泡排序
		for (int i = 0; i < abs->m_Size - 1; i++)
		{
			for (int j = 0; j < abs->m_Size - i - 1; j++)
			{
				if (abs->personArray[j].m_age > abs->personArray[j + 1].m_age)
				{
					struct Person temp = abs->personArray[j];
					abs->personArray[j] = abs->personArray[j + 1];
					abs->personArray[j + 1] = temp;
				}
			}
		}
		//排序完成后显示所有联系人
		showPerson(abs);
	}
	else
	{
		printf("输入错误，请重新输入！\n");
		goto THER;
	}

	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(struct Addressbooks* abs)
{
	int a = 0;
	printf("是否清空通讯录\n");
	printf("1--确认\n");
	printf("2--取消\n");
	while (1)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			//逻辑清零
			abs->m_Size = 0;
			printf("通讯录已清空\n");
			break;
		}
		else if (a == 2)
		{
			break;
		}
		else
		{
			printf("选择错误，请重新选择\n");
		}

	}

	system("pause");
	system("cls");
}

int main()
{
	//创建通讯录结构体变量
	struct Addressbooks abs;
	//初始化通讯录中当前人员个数
	abs.m_Size = 0;

	//选择
	int select = 0;

	while (1)
	{

		//菜单调用
		menu();

		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			addPerson(&abs);    //添加联系人
			break;
		case 2:
			showPerson(&abs);   //显示联系人
			break;
		case 3:
			findPerson(&abs);   //查找联系人
			break;
		case 4:
			deletePerson(&abs);   //删除联系人
			break;
		case 5:
			modifyPerson(&abs);   //修改联系人
			break;
		case 6:
			inSertPerson(&abs);   //插入联系人
			break;
		case 7:
			sortPerson(&abs);    //排序
			break;
		case 8:
			totalPerson(&abs);    //统计联系人
			break;
		case 9:
			cleanPerson(&abs);   //清空联系人
			break;
		case 0:       //输入的是0，退出系统 
			printf("欢迎下次使用！\n");
			system("pause");
			return 0;
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	}

	system("pause");
	return 0;
}