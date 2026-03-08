#pragma once
namespace hm {
class Integer {
  public:
    // could use default constructor as the other option
    Integer(int dummy = 0);
    Integer(const Integer& integer);

    int get_dummy() const;
    void set_dummy(int dummy);
    void print_value() const;
    // cannot exist at the same time with pass by value as they are ambigous
    int compare(const Integer& integer) const;
    Integer& multiply(const Integer& integer);
    // You can see that the copy ctor is called if you use this one
    // int compare(Integer integer) const;

  private:
    int m_dummy;
};
} // namespace hm
