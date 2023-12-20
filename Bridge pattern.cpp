#include <iostream>

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Square" << std::endl;
    }
};

class DrawingAPI {
public:
    virtual void drawShape() = 0;
    virtual ~DrawingAPI() {}
};

class DrawingAPI1 : public DrawingAPI {
public:
    void drawShape() override {
        std::cout << "Using Drawing API 1" << std::endl;
    }
};

class DrawingAPI2 : public DrawingAPI {
public:
    void drawShape() override {
        std::cout << "Using Drawing API 2" << std::endl;
    }
};

class ShapeBridge {
protected:
    DrawingAPI *drawingAPI;
    
public:
    ShapeBridge(DrawingAPI *api) : drawingAPI(api) {}
    virtual void draw() = 0;
    virtual ~ShapeBridge() {}
};

class CircleShape : public ShapeBridge {
public:
    CircleShape(DrawingAPI *api) : ShapeBridge(api) {}
    void draw() override {
        std::cout << "CircleShape ";
        drawingAPI->drawShape();
    }
};

class SquareShape : public ShapeBridge {
public:
    SquareShape(DrawingAPI *api) : ShapeBridge(api) {}
    void draw() override {
        std::cout << "SquareShape ";
        drawingAPI->drawShape();
    }
};

int main() {
    DrawingAPI1 api1;
    DrawingAPI2 api2;

    CircleShape circle1(&api1);
    SquareShape square1(&api2);

    circle1.draw();
    square1.draw();

    return 0;
}
