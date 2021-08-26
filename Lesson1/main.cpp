#include<iostream>

const int SIZE{ 10 };
//
class Power
{
	float var1{3};
	float var2{3};

public:
	void set(float _var1, float _var2)
	{
		var1 = _var1;
		var2 = _var2;
	}

	void calculate()
	{
		float res{var1};
		for (int i{}; i < var2-1; i++)
			res *= var1;
		std::cout <<"Результат возведения "<<var1<<" в степень "<<var2<<" равен: " << res<<'\n';
	}
};

class RGBA
{
	short unsigned int m_red{};
	short unsigned int m_green{};
	short unsigned int m_blue{};
	short unsigned int m_alpha{255};

public:
	RGBA(uint8_t _m_red, uint8_t _m_green, uint8_t _m_blue, uint8_t _m_alpha) : m_red(_m_red), m_green(_m_green), m_blue(_m_blue), m_alpha(_m_alpha) {}

	void print()
	{
		std::cout << "m_red: " << m_red << ", m_green: " << m_green << ", m_blue: " << m_blue << ", m_alpha: " << m_alpha << '\n';
	}
};

class Stack
{
	int arr[SIZE];
	int cursor;

public:
	void reset()
	{
		for (int i{}; i < SIZE; i++)
			arr[i] = 0;
		cursor = -1;
	}

	bool push( int data)
	{
		if (cursor < SIZE - 1)
		{
			arr[++cursor] = data;
			return true;
		}
		else
			return false;
	}

	int pop()
	{
		if (cursor != -1)
			return arr[cursor--];
		else
		{
			std::cout << "Stack is empty\n";
			return -1;
		}
	}

	void print()
	{
		std::cout << "( ";
		for (int i{}; i <= cursor; i++)
			std::cout<< arr[i] << ' ';
		std::cout << ")\n";
	}

};

int main()
{
	setlocale(0, "ru.RU_utf8");
	//Задание 1
	{
		std::cout << "Задание 1\n";
		Power power;
		power.set(12.0f, 3.0f);
		power.calculate();
	}
	//Задание 2
	{
		std::cout << "\n\nЗадание 2\n";
		RGBA rgba(20,30,40,50);
		rgba.print();
	}
	//Задание 3
	{
		std::cout << "\n\nЗадание 3\n";
		Stack stack;
		stack.reset();
		stack.print();

		stack.push(3);
		stack.push(7);
		stack.push(5);
		stack.print();

		stack.pop();
		stack.print();

		stack.pop();
		stack.pop();
		stack.print();

		return 0;
	}
}