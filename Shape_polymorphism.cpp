#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

// Base class
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() = default;
};

// Derived class - Circle
class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

// Derived class - Square
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing Square" << std::endl;
    }
};

// Factory Pattern
class ShapeFactory {
public:
    static std::unique_ptr<Shape> createShape(const std::string& type) {
        if (type == "circle")
            return std::make_unique<Circle>();
        else if (type == "square")
            return std::make_unique<Square>();
        else
            return nullptr;
    }
};

// Draw function (polymorphic call)
void drawShapes(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        shape->draw();
    }
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;

    shapes.emplace_back(ShapeFactory::createShape("circle")); // using factory
    shapes.emplace_back(ShapeFactory::createShape("square"));
    shapes.emplace_back(ShapeFactory::createShape("circle"));
    shapes.emplace_back(std::make_unique<Circle>()); // normal way

    // run time polymorphism
    for (const auto& shape : shapes) {
        shape->draw();
    }
    
    // not using shapefactory
    std::unique_ptr<Shape> shape1 = std::make_unique<Circle>();
    shape1->draw();

    

    // // 多執行緒畫圖
    // std::thread t1(drawShapes, std::cref(shapes));
    // t1.join();

    return 0;
}
