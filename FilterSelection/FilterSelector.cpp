//----------------------------------------------------------------------------

#include "FilterSelector.h"

#include <math.h>  // fabs()
#include "FilterInformation.h"  // FilterInformation

//----------------------------------------------------------------------------

const float START_VALUE_MIN_DIFF = 1e7f;
const float HIGH_LIMIT_RESERVE_COEFFICIENT = 0.04f;

//----------------------------------------------------------------------------

//! Выбор фильтра из доступных
FilterInformation FilterSelector::select(float currentFreq)
{
  // По грубому критерию отбросим совсем неподходяшие
  std::vector<FilterInformation> filters_list = getSuitableFiltersList(currentFreq);
  // Из оставшихся выберем лучший
  FilterInformation best = selectBest(currentFreq, &filters_list);
  return best;
}
//----------------------------------------------------------------------------

//! Получение списка подходящих фильтров из списка доступных
std::vector<FilterInformation> FilterSelector::getSuitableFiltersList(float currentFreq)
{
  std::vector<FilterInformation> good_filters;

  std::vector<FilterInformation>::const_iterator it = accessibleFilters->begin();
  for (; it != accessibleFilters->end(); ++it)
  {
    FilterInformation filter = *it;
    float half_interval = fabs(filter.maxFreq - filter.minFreq) / 2;
    float high_limit_reserve = filter.maxFreq * HIGH_LIMIT_RESERVE_COEFFICIENT;
    if (currentFreq > filter.minFreq + half_interval &&
        currentFreq < filter.maxFreq + high_limit_reserve)
      good_filters.push_back(*it);
  }
  return good_filters;
}
//----------------------------------------------------------------------------

//! Выбор лучшего фильтра
//! Лучший фильтр - фильтр, у которого верхняя граница лежит ближе всего к текущей частоте
FilterInformation FilterSelector::selectBest(float currentFreq,
                                                   const std::vector<FilterInformation> *list)
{
  float min_diff = START_VALUE_MIN_DIFF;
  FilterInformation found_filter;
  std::vector<FilterInformation>::const_iterator it = list->begin();
  for (; it != list->end(); ++it)
  {
    FilterInformation filter = *it;
    float new_diff = fabs(filter.maxFreq - currentFreq);
    if (new_diff < min_diff)
    {
      min_diff = new_diff;
      found_filter = filter;
    }
  }

  return found_filter;
}
//----------------------------------------------------------------------------

