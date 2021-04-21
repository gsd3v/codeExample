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

  //! Выбор фильтра из доступных
  //! Вернет FilterInformation с нулевыми полями, если нет подходящего
  FilterInformation select(float currentFreq);

private:
  //! Получение списка подходящих фильтров из списка доступных
  std::vector<FilterInformation> getSuitableFiltersList(float currentFreq);

  //! Выбор лучшего фильтра
  //! Лучший фильтр - фильтр, у которого верхняя граница лежит ближе всего к текущей частоте
  FilterInformation selectBest(float currentFreq, const std::vector<FilterInformation> *list);

  //! Доступные фильтры (первоночальный набор фильтров, из которых будет происходить отбор)
  const std::vector<FilterInformation>* accessibleFilters;
};
//----------------------------------------------------------------------------

#endif // FilterSelectorH
