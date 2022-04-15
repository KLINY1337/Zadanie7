#include "functions.h"
#include <cmath>

int solve_prefix(string prefix) {
	Stack operandStack("",prefix.size()+1);
	for (int i = prefix.size() - 1; i >= 0; i--) {
		if (isdigit(prefix[i])) operandStack.AddEl(prefix[i] - '0');
		else {
			int operand1;
			operandStack.TakeEl(operand1);
			
			int operand2;
			operandStack.TakeEl(operand2);
			if (prefix[i] == '+') operandStack.AddEl(operand1 + operand2);
			else
				if (prefix[i] == '-') operandStack.AddEl(operand1 - operand2);
				else
					if (prefix[i] == '*') operandStack.AddEl(operand1 * operand2);
					else
						if (prefix[i] == '/') operandStack.AddEl(operand1 / operand2);
						else
							if (prefix[i] == '^') operandStack.AddEl(pow(operand1, operand2));
		}
	}
	int result;
	operandStack.TakeEl(result);
	return result;
}

Stack::Stack(string _name, int _size) {
	name = _name; // ���������� ����� �����
	size = _size; // ���������� ������� �����
	a = new int[size]; // ��������� ������ ��� �������
	curlen = -1; // ������������� ������� ����� -1
}

int Stack::StackSize() { // ������� ������� �����
	return size;
}

int Stack::CurrentLength() { // ������� ������� ����� �����
	return curlen + 1;
}

string Stack::StackName() { // ������� ����� �����
	return name;
}

bool Stack::AddEl(int _el) {
	curlen++; // ����������������� ������� �����
	if (curlen <= size - 1) { a[curlen] = _el; return true; } // ������������� �������� �����
	else
		return false;
}

bool Stack::TakeEl(int& m) {
	if (CurrentLength() > 0) { // ���������� �������� �����
		m = a[CurrentLength() - 1];
		curlen--; // ����������������� ������� ����� �����
		return true;
	}
	else return false;

}