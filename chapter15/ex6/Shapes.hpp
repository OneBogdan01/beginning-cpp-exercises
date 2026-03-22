#pragma once
// Generic base class for shapes

#include <numbers>
class Point final

{
  public:
    Point(double x, double y) : m_x{x}, m_y{y} {}

    double getX() const {
        return m_x;
    }

    double getY() const {
        return m_y;
    }

    void setX(double x) {
        m_x = x;
    }

    void setY(double y) {
        m_y = y;
    }

  private:
    double m_x;

    double m_y;
};

class Shape

{
  public:
    Shape(const Point& position) : m_position{position} {}

    virtual ~Shape() = default; // Remember: always use virtual destructors for base classes!

    virtual double area() const = 0; // Pure virtual function to compute a shape's area

    virtual void scale(double factor) = 0; // Pure virtual function to scale a shape
    virtual double perimeter() const = 0;
    // Regular virtual function to move a shape

    virtual void move(const Point& position) {
        m_position = position;
    };

  private:
    Point m_position; // Position of a shape
};
class Rectangle : public Shape {
  public:
    Rectangle(const Point& p, double width, double m_height)
        : Shape(p), m_width(width), m_height(m_height) {}
    double perimeter() const override {
        return 2 * (m_height + m_width);
    }

    double area() const override {
        return m_height * m_width;
    }

    void scale(double factor) override {
        m_width *= factor;
        m_height *= factor;
    }

  private:
    double m_width;
    double m_height;
};
class Circle : public Shape

{
  public:
    Circle(const Point& center, double radius) : Shape{center}, m_radius{radius} {}

    double area() const override {
        return m_radius * m_radius * std::numbers::pi;
    }
    double perimeter() const override {
        return 2 * std::numbers::pi * m_radius;
    }

    void scale(double factor) override {
        m_radius *= factor;
    }

  private:
    double m_radius; // Radius of a circle
};
