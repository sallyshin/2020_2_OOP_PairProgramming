#include <iostream>
#include <string>

using namespace std;

enum BeverageSize {
    TALL,
    GRANDE,
    VENTI
};

class Beverage
{
private:
    BeverageSize size;

public:
    string description;

    Beverage() {}

    Beverage(BeverageSize s) {
        setSize(s);
        description = "Unknown description";
    }

    BeverageSize getSize() const {
        return size;
    }
    void setSize(BeverageSize s) {
        size = s;
    }

    virtual string getDescription() {
        return description;
    }
    virtual double cost() = 0;
};

class HouseBlend : public Beverage
{
public:
    HouseBlend(BeverageSize s) {
        setSize(s);
        description = "House Blend Coffee";
    }
    double cost() {
        if (this->getSize() == TALL)
            return 0.89;
        else if (this->getSize() == GRANDE)
            return 0.99;
        else if (this->getSize() == VENTI)
            return 1.09;
    }
};

class DarkRoast : public Beverage
{
public:
    DarkRoast(BeverageSize s) {
        setSize(s);
        description = "Dark Roast coffee";
    }
    double cost() {
        if (this->getSize() == TALL)
            return 0.99;
        else if (this->getSize() == GRANDE)
            return 1.09;
        else if (this->getSize() == VENTI)
            return 1.19;
    }
};

class Expresso : public Beverage
{
public:
    Expresso(BeverageSize s) {
        setSize(s);
        description = "Expresso";
    }
    double cost() {
        if (this->getSize() == TALL)
            return 1.99;
        else if (this->getSize() == GRANDE)
            return 2.09;
        else if (this->getSize() == VENTI)
            return 2.19;
    }
};

class Decaf : public Beverage
{
public:
    Decaf(BeverageSize s) {
        setSize(s);
        description = "Decaf Coffee";
    }
    double cost() {
        if (this->getSize() == TALL)
            return 1.05;
        else if (this->getSize() == GRANDE)
            return 1.15;
        else if (this->getSize() == VENTI)
            return 1.25;
    }
};

class Decorator : public Beverage
{
public:
    virtual string getDescription() = 0;
};

class Milk : public Decorator
{
public:
    Beverage* beverage;

    Milk(Beverage* bev) {
        beverage = bev;
    }

    string getDescription() {
        return (beverage->getDescription() + ",Milk");
    }

    double cost() {
        if (beverage->getSize() == TALL)
            return beverage->cost() + 0.20;
        else if (beverage->getSize() == GRANDE)
            return beverage->cost() + 0.25;
        else if (beverage->getSize() == VENTI)
            return beverage->cost() + 0.30;
    }
};

class Mocha : public Decorator
{
public:
    Beverage* beverage;

    Mocha(Beverage* bev) {
        beverage = bev;
    }
    string getDescription() {
        return (beverage->getDescription() + ",Mocha");
    }
    double cost() {
        if (beverage->getSize() == TALL)
            return beverage->cost() + 0.10;
        else if (beverage->getSize() == GRANDE)
            return beverage->cost() + 0.15;
        else if (beverage->getSize() == VENTI)
            return beverage->cost() + 0.20;
    }
};

class Soy : public Decorator
{
public:
    Beverage* beverage;

    Soy(Beverage* bev) {
        beverage = bev;
    }

    string getDescription() {
        return (beverage->getDescription() + ",Soy");
    }

    double cost() {
        if (beverage->getSize() == TALL)
            return beverage->cost() + 0.30;
        else if (beverage->getSize() == GRANDE)
            return beverage->cost() + 0.35;
        else if (beverage->getSize() == VENTI)
            return beverage->cost() + 0.40;
    }
};

class Whip : public Decorator
{
public:
    Beverage* beverage;

    Whip(Beverage* bev) {
        beverage = bev;
    }

    string getDescription() {
        return (beverage->getDescription() + ",Whip");
    }

    double cost() {
        if (beverage->getSize() == TALL)
            return beverage->cost() + 0.60;
        else if (beverage->getSize() == GRANDE)
            return beverage->cost() + 0.65;
        else if (beverage->getSize() == VENTI)
            return beverage->cost() + 0.80;
    }
};

int main() {

    Beverage* beverage1 = new DarkRoast(TALL);
    beverage1 = new Milk(beverage1);
    beverage1 = new Mocha(beverage1);
    beverage1 = new Milk(beverage1);
    cout << beverage1->getDescription() << " $" << beverage1->cost() << endl;

    Beverage* beverage2 = new Expresso(GRANDE);
    beverage2 = new Milk(beverage2);
    beverage2 = new Mocha(beverage2);
    beverage2 = new Whip(beverage2);
    cout << beverage2->getDescription() << " $" << beverage2->cost() << endl;

    Beverage* beverage3 = new HouseBlend(VENTI);
    beverage3 = new Whip(beverage3);
    beverage3 = new Milk(beverage3);
    beverage3 = new Soy(beverage3);
    beverage3 = new Mocha(beverage3);
    cout << beverage3->getDescription() << " $" << beverage3->cost() << endl;

    return 0;
}