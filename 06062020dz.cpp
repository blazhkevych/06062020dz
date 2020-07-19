/*
Разработать класс String, который в дальнейшем будет использоваться для работы со строками.
Класс должен содержать:
- Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
- Конструктор, позволяющий создавать строку произвольного размера;
- Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
Необходимо создать деструктор, а также использовать механизмы делегирования конструкторов, если это возможно.
Класс должен содержать методы для ввода строк с клавиатуры и вывода строк на экран.
Также нужно реализовать статическую функцию-член, которая будет возвращать количество созданных объектов строк.
*/
#include <iostream>
using namespace std;
class String
{
private:
	char* str;
	int len;
	static int numbOfObj;
public:
	String(); //- Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
	String(int l); //- Конструктор, позволяющий создавать строку произвольного размера;
	String(const char* s); //- Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
	~String(); // Деструктор
	friend istream& operator >> (istream& stream, String& orig); //метод для ввода строк
	friend ostream& operator << (ostream& stream, const String& orig); //метод для вывода строк на экран
	static void showObjectsNumbr();
};
int String::numbOfObj = 0;

String::String() //- Конструктор по умолчанию, позволяющий создать строку длиной 80 символов;
{
	len = 80;
	str = new char[len + 1];
	*str = '\0';
	++numbOfObj;
}

String::~String() // Деструктор
{
	delete[] str;
	--numbOfObj;
}

void String::showObjectsNumbr()
{
	cout << numbOfObj;
}

String::String(int l) //- Конструктор, позволяющий создавать строку произвольного размера;
{
	len = l;
	str = new char[len + 1];
	*str = '\0';
	++numbOfObj;
}

String::String(const char* s) //- Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
{
	len = strlen(s);
	str = new char[len + 1];
	if (!str)
		strcpy_s(str, len, s);
	++numbOfObj;
}

istream& operator >> (istream& stream, String& orig) //метод для ввода строк
{
	stream >> orig.str;
	return stream;
}

ostream& operator << (ostream& stream, const String& orig) //метод для вывода строк на экран
{
	stream << orig.str;
	return stream;
}
int main()
{
	String;
	String a(80);
	String b;
	cout << "Here is empty String a: ";
	cout << a << endl;
	cout << "Enter String b : ";
	cin >> b;
	cout << "Here is String b: ";
	cout << b << endl;
	cout << "Number of Objects : ";
	String::showObjectsNumbr();
}