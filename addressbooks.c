#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h> 
#include<assert.h>

#define MAX 100//ͨѶ¼�������

//�˵�
void menu();
//�����ϵ��
void addPerson(struct Addressbooks* abs);
//��ʾ��ϵ��
void showPerson(struct Addressbooks* abs);
//������ϵ��
void findPerson(struct Addressbooks* abs);
//ɾ����ϵ��
void deletePerson(struct Addressbooks* abs);
//�޸���ϵ��
void modifyPerson(struct Addressbooks* abs);
//ͳ����ϵ��
void totalPerson(struct Addressbooks* abs);
//����
void sortPerson(struct Addressbooks* abs);
//������ϵ��
void inSertPerson(struct Addressbooks* abs);
//�����ϵ��
void cleanPerson(struct Addressbooks* abs);

//��ϵ�˽ṹ��
struct Person
{
	//����
	char m_name[20];
	//�Ա�
	int m_sex;//1����  2��Ů
	//����
	int m_age;
	//�绰
	char m_phone[20];
	//סַ
	char m_addr[50];
	//������λ
	char m_job[30];	
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_Size;
};

//�˵� 
void menu()
{

	system("cls");

	printf("\n\n\n");

	printf("\t\t\t\t\t**************************************\n");

	printf("\t\t\t\t\t************ͨѶ¼����ϵͳ************\n");

	printf("\t\t\t\t\t======================================\n");

	printf("\t\t\t\t\t*          1.¼����ϵ����Ϣ          *\n");

	printf("\t\t\t\t\t*          2.��ʾ������ϵ��          *\n");

	printf("\t\t\t\t\t*          3.������ϵ����Ϣ          *\n");

	printf("\t\t\t\t\t*          4.ɾ����ϵ����Ϣ          *\n");

	printf("\t\t\t\t\t*          5.�޸���ϵ����Ϣ          *\n");

	printf("\t\t\t\t\t*          6.������ϵ����Ϣ          *\n");

	printf("\t\t\t\t\t*          7.����                    *\n");

	printf("\t\t\t\t\t*          8.ͳ����ϵ������          *\n");

	printf("\t\t\t\t\t*          9.���������ϵ��          *\n");

	printf("\t\t\t\t\t*          0.�˳�ϵͳ                *\n");

	printf("\t\t\t\t\t======================================\n");

	printf("\t\t\t\t\t**************************************\n");

	printf("\t\t\t\t\t          ��ѡ��(0-9):");
}

//�����ϵ��
void addPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
	if (abs->m_Size == MAX)
	{
		printf("ͨѶ¼�������޷���ӣ�\n");

		return;
	}
	else
	{
		//��Ӿ������ϵ��

		//����
		char name[20];
		printf("������������");
		scanf("%s", name);
		strcpy(abs->personArray[abs->m_Size].m_name, name);
		//abs->personArray[abs->m_Size].m_name = name;
		printf("\n");

		//�Ա�
		printf("�������Ա�\n");
		printf("1---��\n");
		printf("2---Ů\n");

		int sex = 0;
		while (1)
		{
			//����������1����2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			scanf("%d", &sex);

			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_sex = sex;
				break;
			}
			printf("������������������\n");
		}
		printf("\n");

		//����
		printf("���������䣺");
		int age = 0;
		while (1)
		{
			scanf("%d", &age);

			if (age < 120 && age>3)
			{
				abs->personArray[abs->m_Size].m_age = age;
				break;
			}
			printf("������������������\n");
		}
		printf("\n");

		//�绰
		printf("��������ϵ�绰��");
		char phone[20];
		scanf("%s", phone);
		strcpy(abs->personArray[abs->m_Size].m_phone, phone);
		//abs->personArray[abs->m_Size].m_phone = phone;
		printf("\n");

		//סַ
		printf("������סַ��");
		char address[50];
		scanf("%s", address);
		strcpy(abs->personArray[abs->m_Size].m_addr, address);
		//abs->personArray[abs->m_Size].m_addr = address;
		printf("\n");

		//������λ
		printf("�����빤����λ��");
		char job[30];
		scanf("%s", job);
		strcpy(abs->personArray[abs->m_Size].m_job, job);
		//abs->personArray[abs->m_Size].m_job = job;
		printf("\n");

		//����ͨѶ¼����
		abs->m_Size++;

		printf("��ӳɹ�\n");

		system("pause");
		system("cls");//����
	}
	
}

//��ʾ��ϵ��
void showPerson(struct Addressbooks* abs)
{
	//�ж�ͨѶ¼�е������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		printf("��ǰ��¼Ϊ��\n");
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			printf("������");
			printf("%s", abs->personArray[i].m_name);
			printf("\t�Ա�");
			printf("%s", abs->personArray[i].m_sex == 1 ? "��" : "Ů");
			printf("\t���䣺");
			printf("%d", abs->personArray[i].m_age);
			printf("\t�绰��");
			printf("%s", abs->personArray[i].m_phone);
			printf("\tסַ��");
			printf("%s", abs->personArray[i].m_addr);
			printf("\t������ַ��");
			printf("%s", abs->personArray[i].m_job);
			printf("\n");

		}
	}

	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(struct Addressbooks* abs)
{
	printf("��������Ҫ���ҵ���ϵ�ˣ�");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//��ѯ��ϵ�˵�λ��
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name,name) == 0)
		{
			ret = i;
		}
	}

	//�ж�
	if (ret != -1)
	{
		printf("������%s", abs->personArray[ret].m_name);
		printf("\t�Ա�%s", abs->personArray[ret].m_sex == 1 ? "��" : "Ů");
		printf("\t���䣺%d", abs->personArray[ret].m_age);
		printf("\t�绰��%s", abs->personArray[ret].m_phone);
		printf("\tסַ��%s", abs->personArray[ret].m_addr);
		printf("\t������ַ��%s", abs->personArray[ret].m_job);
		printf("\n");
	}
	else
	{
		printf("���޴���\n");
	}

	system("pause");
	system("cls");

}

//ɾ����ϵ��
void deletePerson(struct Addressbooks* abs)
{
	printf("������ɾ������ϵ��\n");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//��ѯ��ϵ�˵�λ��
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name, name) == 0)
		{
			ret = i;
		}
	}

	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size; i++)
		{
			//����ǰ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;//����ͨѶ¼�е���Ա��
		printf("ɾ���ɹ�\n");

		//������ϵ��
		abs->m_Size--;
	}
	else
	{
		printf("���޴���\n");
	}

	system("pause");
	system("cls");

}

//�޸���ϵ��
void modifyPerson(struct Addressbooks* abs)
{
	printf("��������Ҫ�޸ĵ���ϵ�ˣ�");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//��ѯ��ϵ�˵�λ��
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (strcmp(abs->personArray[i].m_name, name) == 0)
		{
			ret = i;
		}
	}

	if (ret != -1)
	{
		//�����޸���ϵ�˵���Ϣ

		//����
		char name[20];
		printf("������������");
		scanf("%s", name);
		strcpy(abs->personArray[ret].m_name, name);
		//abs->personArray[abs->m_Size].m_name = name;
		printf("\n");

		//�Ա�
		printf("�������Ա�\n");
		printf("1---��\n");
		printf("2---Ů\n");

		int sex = 0;
		while (1)
		{
			//����������1����2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			scanf("%d", &sex);

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			printf("������������������\n");
		}
		printf("\n");

		//����
		printf("���������䣺");
		int age = 0;
		while (1)
		{
			scanf("%d", &age);

			if (age < 120 && age>3)
			{
				abs->personArray[ret].m_age = age;
				break;
			}
			printf("������������������\n");
		}
		printf("\n");

		//�绰
		printf("��������ϵ�绰��");
		char phone[20];
		scanf("%s", phone);
		strcpy(abs->personArray[ret].m_phone, phone);
		//abs->personArray[abs->m_Size].m_phone = phone;
		printf("\n");

		//סַ
		printf("������סַ��");
		char address[50];
		scanf("%s", address);
		strcpy(abs->personArray[ret].m_addr, address);
		//abs->personArray[abs->m_Size].m_addr = address;
		printf("\n");

		//������λ
		printf("�����빤����λ��");
		char job[30];
		scanf("%s", job);
		strcpy(abs->personArray[ret].m_job, job);
		//abs->personArray[abs->m_Size].m_job = job;
		printf("\n");

		printf("�޸ĳɹ�\n");

	}
	else
	{
		printf("���޴���\n");
	}

	system("pause");
	system("cls");//����

}

//ͳ����ϵ��
void totalPerson(struct Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		printf("ͨѶ¼����ϵ��\n");
	}
	else
	{
		printf("��һ����%dλ��ϵ��\n", abs->m_Size);
		THERE:
		printf("�Ƿ��ӡ�����ˣ�(y/n)\n");
		printf("y---Yes\n");
		printf("n---No\n");
		char yn[10];
		scanf("%s", yn);
		if (strcmp(yn, "y") == 0)
		{
			showPerson(abs);   //��ӡ������ϵ��
		}
		else if (strcmp(yn, "n") == 0)
		{
			system("pause");
		}
		else
		{
			printf("�����������������\n");
			goto THERE;
		}

	}

	system("pause");
	system("cls");
}

//������ϵ��
void inSertPerson(struct Addressbooks* abs)
{
	printf("������������ӵ���ϵ������һ��ϵ��ǰ������֣�");
	char name[20];
	scanf("%s", name);

	int ret = -1;
	//��ѯ��ϵ�˵�λ��
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
			//Ԫ�غ���
			abs->personArray[j + 1] = abs->personArray[j];
		}

		//������Ҫ������ϵ�˵���Ϣ

		//����
		char name[20];
		printf("������������");
		scanf("%s", name);
		strcpy(abs->personArray[ret].m_name, name);
		//abs->personArray[abs->m_Size].m_name = name;
		printf("\n");

		//�Ա�
		printf("�������Ա�\n");
		printf("1---��\n");
		printf("2---Ů\n");

		int sex = 0;
		while (1)
		{
			//����������1����2�����˳�ѭ������Ϊ���������ȷֵ
			//�������������������
			scanf("%d", &sex);

			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_sex = sex;
				break;
			}
			printf("������������������\n");
		}
		printf("\n");

		//����
		printf("���������䣺");
		int age = 0;
		while (1)
		{
			scanf("%d", &age);
			//�ж������Ƿ�Ϸ�
			if (age < 120 && age>3)
			{
				abs->personArray[ret].m_age = age;
				break;
			}
			printf("������������������\n");
		}
		printf("\n");

		//�绰
		printf("��������ϵ�绰��");
		char phone[20];
		scanf("%s", phone);
		strcpy(abs->personArray[ret].m_phone, phone);
		//abs->personArray[abs->m_Size].m_phone = phone;
		printf("\n");

		//סַ
		printf("������סַ��");
		char address[50];
		scanf("%s", address);
		strcpy(abs->personArray[ret].m_addr, address);
		//abs->personArray[abs->m_Size].m_addr = address;
		printf("\n");

		//������λ
		printf("�����빤����λ��");
		char job[30];
		scanf("%s", job);
		strcpy(abs->personArray[ret].m_job, job);
		//abs->personArray[abs->m_Size].m_job = job;
		printf("\n");

		abs->m_Size++;

		printf("����ɹ�\n");
	}
	else
	{
		printf("���޴��ˣ�\n");
	}

	system("pause");
	system("cls");
}

//����
void sortPerson(struct Addressbooks* abs)
{
	THER:
	printf("��ѡ���������\n");
	printf("1---�Ա�\n");
	printf("2---����\n");
	int ret = 0;
	scanf("%d", &ret);

	if (ret = 1)
	{
		//ð������
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
		//������ɺ���ʾ������ϵ��
		showPerson(abs);
	}
	else if (ret == 2)
	{
		//ð������
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
		//������ɺ���ʾ������ϵ��
		showPerson(abs);
	}
	else
	{
		printf("����������������룡\n");
		goto THER;
	}

	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(struct Addressbooks* abs)
{
	int a = 0;
	printf("�Ƿ����ͨѶ¼\n");
	printf("1--ȷ��\n");
	printf("2--ȡ��\n");
	while (1)
	{
		scanf("%d", &a);
		if (a == 1)
		{
			//�߼�����
			abs->m_Size = 0;
			printf("ͨѶ¼�����\n");
			break;
		}
		else if (a == 2)
		{
			break;
		}
		else
		{
			printf("ѡ�����������ѡ��\n");
		}

	}

	system("pause");
	system("cls");
}

int main()
{
	//����ͨѶ¼�ṹ�����
	struct Addressbooks abs;
	//��ʼ��ͨѶ¼�е�ǰ��Ա����
	abs.m_Size = 0;

	//ѡ��
	int select = 0;

	while (1)
	{

		//�˵�����
		menu();

		scanf_s("%d", &select);
		switch (select)
		{
		case 1:
			addPerson(&abs);    //�����ϵ��
			break;
		case 2:
			showPerson(&abs);   //��ʾ��ϵ��
			break;
		case 3:
			findPerson(&abs);   //������ϵ��
			break;
		case 4:
			deletePerson(&abs);   //ɾ����ϵ��
			break;
		case 5:
			modifyPerson(&abs);   //�޸���ϵ��
			break;
		case 6:
			inSertPerson(&abs);   //������ϵ��
			break;
		case 7:
			sortPerson(&abs);    //����
			break;
		case 8:
			totalPerson(&abs);    //ͳ����ϵ��
			break;
		case 9:
			cleanPerson(&abs);   //�����ϵ��
			break;
		case 0:       //�������0���˳�ϵͳ 
			printf("��ӭ�´�ʹ�ã�\n");
			system("pause");
			return 0;
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
	}

	system("pause");
	return 0;
}