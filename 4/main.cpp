#include <iostream>

using namespace std;

class MyString
{
private:
	char* m_data;
	int m_size;

public:
	MyString();
	MyString(const char* in);		// MyString a("abc")
	MyString(const MyString& in);		//copy constructor;
	~MyString();

	void assignMemory();
	void releaseMemory();

	int getLength() const { return m_size; }
	static int getLength(const char* in, int max_length = 255);
	char& operator[](int i) {
		return m_data[i];
	}
	//cout << a << endl;
	friend std::ostream& operator<<(std::ostream& o, const MyString& in);
	//b = a= c
	const MyString& operator=(const MyString& in);
	// c = a + b + c;

	void append(const MyString& in);

	friend const MyString operator+(const MyString& in, const MyString& in2);
};

MyString::MyString()
{
	m_data = nullptr;
	m_size = 0;
}

MyString::MyString(const char* in)
{
	m_data = nullptr;
	m_size = getLength(in);
	if (m_size == 0) return;

	assignMemory();
	for (int i = 0; i < m_size; i++)
		m_data[i] = in[i];
	m_data[m_size] = '\0';
}

MyString::MyString(const MyString& in) // 복사생성자
{
	m_data = nullptr;
	m_size = in.getLength();
	if (m_size == 0) return;

	assignMemory();

	for (int i = 0; i < m_size; i++)
		m_data[i] = in.m_data[i];
	m_data[m_size] = '\0';
}


const MyString& MyString::operator=(const MyString& in) //할당연산자
{
	if (this == &in) return *this;			// 나랑 같은 주소인 경우

	releaseMemory();						// 값 삭제
	m_size = in.getLength();
	if (m_size == 0) return *this;

	assignMemory();

	for (int i = 0; i < m_size; i++)
		m_data[i] = in.m_data[i];
	m_data[m_size] = '\0';
	return *this;
}

MyString::~MyString()
{
	releaseMemory();
}

void MyString::assignMemory()
{
	if (m_size == 0) return;
	m_data = new char[m_size + 1];
}

void MyString::releaseMemory()
{
	if (m_data != nullptr) delete[] m_data;
	m_data = nullptr;
	m_size = 0;
}

int MyString::getLength(const char* in, int max_length)
{
	if (in == nullptr) return 0;
	int leng = 0;
	while (true)
	{
		if (in[leng] == '\0') return leng;
		if (leng >= max_length) return leng;
		leng++;
	}
}

std::ostream& operator<<(std::ostream& o, const MyString& in)		//상수는 입력받을 때 상수가 있고 함수 상수가 있음.
{
	if (in.getLength() == 0) return o;
	o << in.m_data;

	return o;
}



void MyString::append(const MyString& in)
{

	if (in.getLength() == 0) return;

	MyString temp = *this;
	releaseMemory();
	m_size = temp.getLength() + in.getLength();

	if (m_size == 0) return;
	assignMemory();
	for (int i = 0; i < temp.m_size; i++)
		m_data[i] = temp.m_data[i];
	for (int i = 0; i < in.m_size; i++)
		m_data[i + temp.m_size] = in.m_data[i];

	m_data[m_size] = '\0';
}

const MyString operator+(const MyString& in, const MyString& in2)
{
	MyString out;
	out.append(in);
	out.append(in2);

	return out;
}



int main() {
	MyString a("Sejong");
	MyString b = a;
	b[0] = 'C';
	MyString c;
	c = a + b;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}