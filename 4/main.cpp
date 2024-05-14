#include <iostream>

using namespace std;

class MyString {
	char* m_data;
	int m_size;
public:
	MyString() {
		m_data = NULL;
		m_size = 0;
	}
	MyString(const char* str) {
		int i;
		for (i = 0; str[i] != '\0'; i++) {}
		m_size = i + 1;
		m_data = new char[m_size];
		for (i = 0; i < m_size; i++) {
			m_data[i] = str[i];
		}
	}

	MyString(MyString& in) {
		if (m_data != NULL) {
			releaseMemory();
		}
		m_size = in.m_size;
		m_data = new char[m_size];

		for (int i = 0; i < m_size; i++) {
			m_data[i] = in.m_data[i];
		}
	}

	char& operator[](int i) {
		return m_data[i];
	}
	
	void operator=(MyString& in) {
		if (m_data != NULL) {
			releaseMemory();
		}
		m_size = in.m_size;
		m_data = new char[m_size];

		for (int i = 0; i < m_size; i++) {
			m_data[i] = in.m_data[i];
		}
	}

	void releaseMemory() {
		delete[] m_data;
	}

	void add(MyString& in) {
		char* temp = new char[m_size];
		int temp_size = m_size;
		for (int i = 0; i < m_size; i++) {
			temp[i] = m_data[m_size];
		}
		m_size += in.m_size;
		m_data = new char[m_size];
		for (int i = 0; i < m_size; i++) {
			if (i < temp_size)
				m_data[i] = temp[i];
			else
				m_data[i] = in.m_data[i];
			
		}
		releaseMemory();
	}
	~MyString() {
		releaseMemory();
	}
	friend ostream& operator<<(ostream& o, MyString& in);
};


MyString& operator+(MyString in1, MyString in2) {
	MyString out;
	return out;
}


ostream& operator<<(ostream& o, MyString& in) {
	o << in.m_data;
	return o;
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