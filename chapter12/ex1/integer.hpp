#pragma once
namespace hm {
class Integer {
  public:
    Integer();
    int get_dummy() const;
    void set_dummy(int dummy);
    void print_value() const;

  private:
    int m_dummy;
};
} // namespace hm
