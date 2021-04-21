//----------------------------------------------------------------------------

#ifndef EnumDecoratorH
#define EnumDecoratorH

//----------------------------------------------------------------------------

//! ����� ������� ����� ��� ������������, ����� ��� ������������� � ���� 
//! ����������� ���� ENUM::INDEX (� C++ Builder 6 � ���� ��������)
//! ������ �������������:
//!   class NewEnum : public EnumDecorator {
//!     public:
//!       enum EnumIndex__ {
//!         NEW_VALUE_1 = 0,
//!         NEW_VALUE_2,
//!         ...
//!       }
//!   }
//! � ����:
//!   NewEnum::NEW_VALUE_1

class EnumDecorator
{
public:
  enum EnumIndex__ {
    Count = 0
  };

  EnumDecorator(EnumIndex__ idx) : index_(idx)
  { }
  operator EnumIndex__() const {
    return index_;
  }

private:
  EnumIndex__ index_;
};
//----------------------------------------------------------------------------

#endif // EnumDecoratorH
