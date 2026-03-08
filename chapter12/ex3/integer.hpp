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
    int compare(const Integer& integer) const;

    Integer& add(const Integer& integer);
    Integer& subtract(const Integer& integer);
    Integer& multiply(const Integer& integer);

  private:
    int m_dummy;
};
} // namespace hm
