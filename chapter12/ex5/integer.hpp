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
    friend int compare(const Integer& a, const Integer& b);
    Integer& multiply(const Integer& integer);
    // You can see that the copy ctor is called if you use this one
    // int compare(Integer integer) const;

  private:
    int m_dummy;
};
// could have been a static function or a regular global function really, getting the values can be
// done via the getter
inline int compare(const Integer& a, const Integer& b) {
    if (a.m_dummy < b.m_dummy) {
        return -1;
    }
    if (a.m_dummy == b.m_dummy) {
        return 0;
    }
    return 1;
}
} // namespace hm
