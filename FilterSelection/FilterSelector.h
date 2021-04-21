//----------------------------------------------------------------------------

#ifndef FilterSelectorH
#define FilterSelectorH

//----------------------------------------------------------------------------

#include <vector>

//----------------------------------------------------------------------------

class FilterInformation;

//----------------------------------------------------------------------------

class FilterSelector
{
public:
  FilterSelector(const std::vector<FilterInformation>* accessible_filters) :
    accessibleFilters(accessible_filters)
  { }

  //! ����� ������� �� ���������
  //! ������ FilterInformation � �������� ������, ���� ��� �����������
  FilterInformation select(float currentFreq);

private:
  //! ��������� ������ ���������� �������� �� ������ ���������
  std::vector<FilterInformation> getSuitableFiltersList(float currentFreq);

  //! ����� ������� �������
  //! ������ ������ - ������, � �������� ������� ������� ����� ����� ����� � ������� �������
  FilterInformation selectBest(float currentFreq, const std::vector<FilterInformation> *list);

  //! ��������� ������� (�������������� ����� ��������, �� ������� ����� ����������� �����)
  const std::vector<FilterInformation>* accessibleFilters;
};
//----------------------------------------------------------------------------

#endif // FilterSelectorH
