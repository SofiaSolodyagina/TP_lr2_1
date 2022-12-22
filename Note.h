#pragma once

#include <string>
#include <sstream>
#include "utils.cpp"

using namespace std;

class Note
{
public: 
	Note() {
		setName();
		setSign();
		setBithday();
	}

	Note(string *lines) {
		name = lines[0];
		sign = lines[1];
		birthday[0] = stoi(lines[2]);
		birthday[1] = stoi(lines[3]);
		birthday[2] = stoi(lines[4]);
	}

	void setName() {
		cout << "ФИО: ";
		getline(cin, name);

	}

	string getName() {
		return name;
	}

	void setSign() {
		cout << "Знак зодиака: ";
		getline(cin, sign);

	}
	string getSign() {
		return sign;
	}

	void setBithday() {
		cout << "Введите день рождения: ";
		cin >> birthday[0];

		cout << "Введите месяц рождения: ";
		cin >> birthday[1];

		cout << "Введите год рождения: ";
		cin >> birthday[2];

		cin.get();
	}

	int* getBithday() {
		return birthday;
	}

	void edit(){

		while (true)
		{
			string commands[] = {
				"ФИО",
				"Знак зодиака",
				"День рождения",
			};

			int line = menu("Выберите поле: (< - сохранить)", commands, 3);
			if (line < 0) return;

			switch (line)
			{
			case 0:
				setName();
			case 1:
				setSign();
			case 2:
				setBithday();
			}
		}
	}

	string toString() {
		stringstream str;
		str  << setw(36) << name << setw(30) << sign << setw(16) << string(to_string(birthday[0]) + "." + to_string(birthday[1]) + "." + to_string(birthday[2])) << endl;

		return str.str();
	}

	friend std::ofstream& operator<< (std::ofstream& file, const Note& note){
		file << note.name << "\n";
		file << note.sign << "\n";
		file << note.birthday[0] << "\n";
		file << note.birthday[1] << "\n";
		file << note.birthday[2] << "\n";
		file << "\n";

		return file;
	}

private:
	string name;
	string sign;
	int birthday[3];
};

