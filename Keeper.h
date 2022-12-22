#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iomanip>

#include "Note.h"

using namespace std;

class Keeper {
public:

	Keeper() {
	}

	void addNote(Note *transport) {
		Note **newList = new Note*[listSize + 1];
		
		for (int i = 0; i < listSize; i++) {
			newList[i] = list[i];
		}

		newList[listSize++] = transport;

		delete []list;
		list = newList;
	}

	void removeNote(int number) {
		Note **newList = new Note*[listSize - 1];

		int index = 0;
		for (int i = 0; i < listSize; i++) {
			if (i == number) continue;

			newList[index] = list[index];
			index++;
		}

		delete[] list;
		list = newList;
		listSize--;
	}

	void sort() {
		Note* temp;

		for (size_t i = 0; i < listSize - 1; i++)
		{
			for (size_t j = i + 1; j < listSize; j++)
			{
				if (getList()[i]->getBithday()[0] > getList()[j]->getBithday()[0]) {
					temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}
			}
		}
	}

	void save() {
		ofstream out;

		out.open("data.txt");

		if (out.is_open())
		{
			for (size_t i = 0; i < listSize; i++) {
				out << *list[i];
			}
			cout << "���������!";
		} else {
			cout << "�� ������� ������� ����!";

		}
		
		out.close();

		cout << endl << "\033[35m������� ����� ������� ����� ��������� � ����\033[0m" << endl;
		cin.get();
	}
	
	void load() {

		string line;

		ifstream in("data.txt");

		try
		{
			const int strNums = 6;

			if (!in.is_open()) throw std::runtime_error("�� ������� ������� ����.");

			int numberOfLines = count(std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>(), '\n'); // ������� ���������� ����� � �����
			if (numberOfLines <= 0 || numberOfLines % strNums != 0) throw std::runtime_error("���� ��������!");

			in.seekg(0);

			int lineNum = 0;
			Note **newList = new Note*[(int) numberOfLines / strNums];
			string lines[strNums];

			while (getline(in, line))
			{
				string str = line;

				lines[(lineNum++) % strNums] = str;
				
				int pos = lineNum / strNums - 1;

				if (lineNum % strNums == 0) {
					newList[pos] = new Note(lines);
				}
			}

			delete[]list;

			list = newList;
			listSize = (int)numberOfLines / strNums;

			cout << "���������!";
		} 
		catch (std::runtime_error err)
		{
			cout << err.what() << endl;
		}
		catch (...)
		{
			cout << "����������� ������!";
		}

		in.close(); 

		cout << endl << "\033[35m������� ����� ������� ����� ��������� � ����\033[0m" << endl;
		cin.get();

	}

	void printHead() {
		cout << "\033[44;30m" << setw(36) << "���" << setw(30) << "���� �������" << setw(16) << "���� ��������" << "\033[0m" << endl;
	}

	Note** getList() {
		return list;
	}

	size_t getSize() {
		return listSize;
	}

	friend const bool operator! (Keeper& keeper)
	{
		return (bool) keeper.getSize();
	}

private:
	Note** list = {};
	size_t listSize = 0;
};


