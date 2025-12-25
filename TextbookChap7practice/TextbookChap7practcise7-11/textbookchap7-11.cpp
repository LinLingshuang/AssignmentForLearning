/*7-11组合与继承有什么共同点和差异？通过组合生成的类与被组合的类之间的逻辑关系是什么，继承呢*/
//组合和继承都是面向对象编程中的两种重要的代码复用机制。它们有一些共同点和差异：
//共同点：
//1. 代码复用：两者都允许一个类重用另一个类的功能，从而减少代码重复。
//2. 关系建立：两者都建立了类之间的关系，使得一个类可以利用另一个类的属性和方法。
//差异：
//1. 关系类型：组合表示“有一个”关系（has-a relationship），即一个类包含另一个类的实例作为其成员变量。
// 而继承表示“是一个”关系（is-a relationship），即一个类是另一个类的子类，继承了其属性和方法。
//2. 灵活性：组合通常比继承更灵活，因为组合允许在运行时动态地改变成员对象，而继承在编译时就确定了类的结构。
//3. 复杂性：继承可能导致类层次结构变得复杂，尤其是在多重继承的情况下，而组合通常更简单，因为它只涉及对象的包含关系。
//逻辑关系：
//通过组合生成的类与被组合的类之间的逻辑关系是“有一个”关系。例如，一个汽车类可能包含一个引擎类作为其成员变量，表示汽车“有一个”引擎。
//通过继承生成的类与被继承的类之间的逻辑关系是“是一个”关系。例如，一个狗类可能继承自动物类，表示狗“是一个”动物。
#include <iostream>
using namespace std;
class Engine {
	public:
	Engine() {
		cout << "Constructing Engine..." << endl;
	}
	~Engine() {
		cout << "Destructing Engine..." << endl;
	}
};
class Car {
	private:
		Engine engine; // 组合关系
	public:
	Car() {
		cout << "Constructing Car..." << endl;
	}
	~Car() {
		cout << "Destructing Car..." << endl;
	}
};
class Vehicle {
	public:
	Vehicle() {
		cout << "Constructing Vehicle..." << endl;
	}
	~Vehicle() {
		cout << "Destructing Vehicle..." << endl;
	}
};
class Truck : public Vehicle { // 继承关系
	public:
	Truck() {
		cout << "Constructing Truck..." << endl;
	}
	~Truck() {
		cout << "Destructing Truck..." << endl;
	}
};
int main() {
	Car myCar;   // 组合示例
	Truck myTruck; // 继承示例
	return 0;
}
