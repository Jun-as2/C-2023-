#include <iostream>

using namespace std;


class CCircle {
	char shape;
	int radius;
public:
	CCircle(int _radius) {
		shape = '*';
		radius = _radius;
	}
	double square(double num) { return num * num; }
	void draw() {
		double centor = radius - 0.5;

		for (int i = 0; i < radius * 2; i++) {
			for (int j = 0; j < radius * 2; j++) {
				if (radius + 0.5 > sqrt(square(centor - i) + square(centor - j))) {
					cout << shape;
				}
				else {
					cout << ' ';
				}
			}
			cout << endl;
		}
	}
	void setRadius(int _radius) { radius = _radius; }
	void setFill(char _shape) { shape = _shape; }
};


int main() {
	CCircle a(3); // 반지름 3의 원을 생성
	a.draw(); // ‘*’로 원을 그린다
	a.setRadius(4); // 원의 반지름을 변경
	a.setFill('^'); // 채우는 문자를 ‘^’ 로 변경
	a.draw();
	return 0;
}