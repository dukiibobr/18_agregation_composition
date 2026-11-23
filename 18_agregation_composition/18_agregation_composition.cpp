#include <iostream>
using namespace std;

//enum Type{None,Stanard,XL,XXL};
//
//class Cartridge {
//	float volume;
//	string color;
//	Type type;
//public:
//	Cartridge():volume(0),color("-"),type(None){}
//	Cartridge(float v,string c,Type t):volume(v),color(c),type(t){}
//	
//	void show()const {
//		cout << "volume " << volume << endl;
//		cout << "color " << color << endl;
//		cout << "type ";
//		switch (type)
//		{
//		case None:cout << "none" << endl;
//		case Stanard:cout<<"standard"<<endl;
//		case XL:cout<<"xl"<<endl;
//		case XXL:cout<<"xxl "<<endl;
//		}
//
//		cout << endl;
//	}
//};
//
//class Scaner {
//	float scanRes;
//	float height;
//	float width;
//public:
//	Scaner():scanRes(0),height(0),width(0){}
//	Scaner(float s,float h,float w):scanRes(s),height(h),width(w){}
//
//	void show()const {
//		cout << "scan resolution: " << scanRes << endl;
//		cout << " height: " << height << endl;
//		cout << " width: " << width << endl;
//	}
//};
//
//class Document {
//	string name;
//	string format;
//	int pages;
//public:
//	Document() :name("-"), format("-"), pages(0) {}
//	Document(string n, string f, int p) :name(n), format(f), pages(p) {}
//
//	void show()const {
//		cout << "=============document: " << name << "=============" << endl;
//		cout << "format: " << format << endl;
//		cout << "pages: " << pages << endl;
//		cout << endl;
//	}
//};
//
//class Printer {
//	string model;
//	Cartridge* cartridges;
//	int countCr;
//	Scaner scanner;
//	Document* doc;
//public:
//	Printer() :model("-"), cartridges(nullptr), countCr(0),doc(nullptr){}
//	Printer(string m, float s, float h, float w):model(m),scanner(s,h,w),doc(nullptr)
//	{
//		countCr = 4;
//		cartridges = new Cartridge[countCr];
//		cartridges[0] = Cartridge(300, "red", Type::Stanard);
//		cartridges[1] = Cartridge(300, "green", Type::Stanard);
//		cartridges[2] = Cartridge(300, "blue", Type::Stanard);
//		cartridges[3] = Cartridge(300, "black", Type::Stanard);
//	}
//	
//	void Scan() {
//		cout << "scanning..." << endl;
//	}
//
//	void printDocument() {
//		if (doc != nullptr) {
//			cout << "print document..." << endl;
//			doc->show();
//		}
//		else
//			cout << "no document" << endl;
//	}
//
//	void prinrSettings() {
//		for (int i = 0; i < countCr; i++)
//		{
//			cartridges[i].show();
//		}
//		scanner.show();
//	}
//
//	void addDoc(Document* doc) {
//		this->doc = doc;
//	}
//
//	~Printer()
//	{
//		if (cartridges!=nullptr)
//			delete[]cartridges;
//	}
//};



//1


enum Type{None,Sedan,HedgeBack,Universal};
class Body {
	Type carType;
public:
	Body():carType(None){}
	Body(Type t):carType(t){}

	void show()const {
				
				cout << "type ";

				switch (carType)
				{
				case None:cout << "none" << endl;break;
				case Sedan:cout<<"sedan"<<endl;break;
				case HedgeBack:cout<<"hedgeback"<<endl;break;
				case Universal:cout<<"universal "<<endl;break;
				}
			}
};

class Wheel {
	string wheelType;
	string quality;
	public:
		Wheel():wheelType("-"),quality("-"){}
		Wheel(string w,string q):wheelType(w),quality(q){}
		
		void show()const {
			cout << "wheelType: " << wheelType << endl;
			cout<<"quality: "<<quality<<endl;
		}
};

class Engine {
	int hp;
	float volume;
public:
	Engine():hp(0),volume(0){}
	Engine(int h,float v):hp(h),volume(v){}
	
	void show()const {
		cout << "hp: " << hp << endl;
		cout << "volume: " << volume << endl;
	}
};

class Door {
	string color;
	string openingSide;
	public:
		Door():color("-"),openingSide("-"){}
		Door(string c,string o):color(c),openingSide(o){}
		
		void show()const {
			cout << "color: " << color << endl;
			cout << "openingSide: " << openingSide << endl;
		}
};

class Headlight {
	string color;
	int power;
	public:
		Headlight():color("-"),power(0){}
		Headlight(string c,int p):color(c),power(p){}
		
		void show()const {
			cout << "color: " << color << endl;
			cout << "power: " << power << endl;
		}
};

class Driver {//agregation 
	string name;
	string surname;
	int age;
	int experience;
	public:
		Driver():name("-"),surname("-"),age(0),experience(0){}
		Driver(string n,string s,int a,int e):name(n),surname(s),age(a),experience(e){}
		
		void show()const {
			cout << "name: " << name << endl;
			cout << "surname: " << surname << endl;
			cout << "age: " << age << endl;
			cout << "experience: " << experience << endl;
		}

};



class Car {//---------------------------car
	Body body;
	Wheel wheel[4];
	Engine engine;
	Door door[4];
	Headlight light[2];
	Driver* driver;
public:
	Car(const Body& b, const Wheel(& w)[4], const Engine& e,
		const Door(&d)[4], const Headlight(&h)[2], Driver* dr)
		: body(b), engine(e),
		 driver(dr)
	{
		for (int  i = 0; i < 4; i++)
		{
			wheel[i] = w[i];
			door[i] = d[i];
		}
		for (int  i = 0; i < 2; i++)
		{
			light[i] = h[i];
		}
	
	}

	void printAll()const {
		body.show();
		for (int i = 0; i < 4; i++)
		{
			wheel[i].show();
			door[i].show();
		}

		for (int i = 0; i < 2; i++)
		{
			light[i].show();
		}

		engine.show();
		if (driver != nullptr)
			driver->show();

		else
			cout << "no driver" << endl;

		cout << endl;
	}

	void removeDriver() {
		driver = nullptr;
		cout << "driver removed" << endl << endl;
	}

	void addDriver(Driver* d) {
		this->driver = d;
		cout << "driver added" << endl << endl;
	}
};
int main()
{
	Body b(Sedan);
	Wheel w[4] = {
			Wheel("sports", "worn out"),
	Wheel("sports", "worn out"),
	Wheel("sports", "worn out"),
	Wheel("sports", "worn out")
	};

	Engine e(200, 100);

	Door d[4] = {
		 Door("black", "right"),
	Door("black", "right"),
	Door("black", "right"),
	Door("black", "right")
	};

	Headlight h[2] = {
			Headlight("yellow", 20),
	Headlight("yellow", 40)
	};

	Driver dr("max", "stirner", 40, 20);

	Car c(b, w, e, d, h, &dr);
	c.printAll();
	c.removeDriver();
	c.printAll();
	c.addDriver(&dr);
	c.printAll();





	/*Printer p("panda",300,30,50);
	p.printDocument();
	p.Scan();
	p.prinrSettings();
	

	Document d("passport", "a5", 16);
	Document d1("c++ for kattles", "a4", 1600);

	p.addDoc(&d);
	p.printDocument();
	p.addDoc(&d1);
	p.printDocument();*/
}


