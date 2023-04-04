#include <iostream>
#include <string>

//��� ���������
struct dateData {
	unsigned int day = 1;
	unsigned int month = 1;
	unsigned int year = 1970;
};
struct personData {
	std::string name = "noname";
	dateData birthday; //������ ��������� � �������� ���� ��� ������ ���������
	std::string job = "empty";
	int salary = 0;
};

void show_person(const personData& PD) {
	std::cout << "Name:       " << PD.name << std::endl;
	std::cout << "Birthday:   " << PD.birthday.day << '.' << PD.birthday.month << '.' << PD.birthday.year << std::endl;
	std::cout << "Job:        " << PD.job << std::endl;
	std::cout << "Salary:     " << PD.salary << std::endl;
}

personData input_person() {
	personData tmp;
	std::cout << "Enter name -> ";
	std::cin.ignore();
	std::getline(std::cin, tmp.name);
	std::cout << "Enter birthday day -> ";
	std::cin >> tmp.birthday.day;
	std::cout << "Enter birthday month -> ";
	std::cin >> tmp.birthday.month;
	std::cout << "Enter birthday year -> ";
	std::cin >> tmp.birthday.year;
	std::cin.ignore();
	std::cout << "Enter job -> ";
	std::getline(std::cin, tmp.job);
	std::cout << "Enter salary -> ";
	std::cin >> tmp.salary;
	return tmp;
}

struct coinKeeper {
	std::string name = "empty";
	int age = 0;
	int coins_number = 0;
	int* coins = nullptr;
};

void showCoinKeeper(const coinKeeper& CK) {
	std::cout << "���:     " << CK.name << std::endl;
	std::cout << "�������: " << CK.age << std::endl;
	std::cout << "������:  ";
	for (int i = 0; i < CK.coins_number; i++)
		std::cout << CK.coins[i] << ", ";
	std::cout << "\b\b \n";
}

inline int yearOfBirth(const coinKeeper& CK, int year) {
	return (year - CK.age);
}

int cash(const coinKeeper& CK) {
	int sum = 0;
	for (int i = 0; i < CK.coins_number; i++)
		sum += CK.coins[i];
	return sum;
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;

	struct map {
		int width;
		int height;
		char** field;
		int start_x;
		int start_y;
	};

	//��������� person
	/*struct person { //���������, ���������� ��������� ��������
		std::string name; //���� ���������, ���������� ��������� ����������
		int age;          //���� ���������, ���������� ������������� ����������
		std::string gender;
		std::string job;
		int salary;
	} p1, p2{ "Elisa Thompson", 22, "female", "actress", 50000}; //�������� �������� ���������, ���� �� ������� ��������� ���������������

	//��������� � ����� ������� ���������
	p1.name = "Tom Smith";
	p1.age = 26;
	p1.gender = "male";
	p1.job = "programmer";
	p1.salary = 80000;

	std::cout << "Name:   " << p1.name << std::endl;
	std::cout << "Age:    " << p1.age << std::endl;
	std::cout << "Gender: " << p1.gender << std::endl;
	std::cout << "Job:    " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl;

	std::cout << "----------------" << std::endl;

	std::cout << "Name:   " << p2.name << std::endl;
	std::cout << "Age:    " << p2.age << std::endl;
	std::cout << "Gender: " << p2.gender << std::endl;
	std::cout << "Job:    " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl;

	//�������������� ������� �������� �������
	person p3 {
		"Alex Romanov",
		46,
		"male",
		"director",
		120000
	};
	
	
	person p4 = p3; //������ ������������ ����� ������� p4 �������� ������� p3

	std::cout << "----------------" << std::endl;

	std::cout << "Name:   " << p4.name << std::endl;
	std::cout << "Age:    " << p4.age << std::endl;
	std::cout << "Gender: " << p4.gender << std::endl;
	std::cout << "Job:    " << p4.job << std::endl;
	std::cout << "Salary: " << p4.salary << std::endl;*/

	//��������� date
	/*struct date {
		unsigned int day = 1;
		unsigned int month = 1;
		unsigned int year = 1970;
		std::string note = "empty"; //�������� �� ���������
	};
	date bd{ 1, 5, 2010, "Bob's birthday" };
	std::cout << bd.day << '.' << bd.month << '.' << bd.year << " - " << bd.note << std::endl;*/


	/*personData pd{
		"Mike Ledger",
		{ 29, 7, 1998 },
		"teacher",
		80000
	};

	show_person(pd);

	personData* pointer = &pd;
	std::cout << "\n" << pointer->name << std::endl;
	std::cout << pointer->birthday.day << '.';
	std::cout << pointer->birthday.month << '.';
	std::cout << pointer->birthday.year << std::endl;
	std::cout << pointer->job << std::endl;
	std::cout << pointer->salary << std::endl;

	personData pd2 = input_person();
	show_person(pd2);*/

	//������ 1. ������ � ��������
	std::cout << "������ 1. \n������:\n";
	coinKeeper keeper{
		"Peter",
		10,
		7,
		new int [7] { 1, 10, 5, 2, 1, 1, 10 }
	};
	showCoinKeeper(keeper);
	std::cout << "��� ��������: ����� " << yearOfBirth(keeper, 2023) << std::endl;
	std::cout << "����� ����������: " << cash(keeper) << std::endl;

	delete[] keeper.coins;

	return 0;
}