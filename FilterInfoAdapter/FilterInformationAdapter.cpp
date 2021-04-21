//----------------------------------------------------------------------------

#include "FilterInformationAdapter.h"

#include "FilterInformation.h"  // FilterInformation
#include "GridContainer.h"  // TGridRecord, TGridContainer
#include "StringUtils.h"  // from_string<>()

//----------------------------------------------------------------------------

FilterInformation getFilterInfoFromRecord(TGridRecord *record)
{
  FilterInformation filter_info;
  std::string filter_id = record->GetField(FilterInfoIndex::FilterId);
  std::string max_freq = record->GetField(FilterInfoIndex::MaxFreq);
  std::string min_freq = record->GetField(FilterInfoIndex::MinFreq);

  if (!filter_id.empty() && !max_freq.empty() && !min_freq.empty())
  {
    unsigned int converted_filter_id;
    long temp = from_string<long>(filter_id);
    converted_filter_id = static_cast<unsigned int>(std::labs(temp));
    float converted_max_freq = from_string<float>(max_freq);
    float converted_min_freq = from_string<float>(min_freq);

    filter_info = FilterInformation(converted_filter_id, converted_max_freq, converted_min_freq);
  }
  return filter_info;
}
//----------------------------------------------------------------------------

std::vector<FilterInformation> getFilterInfoListFromContainer(TGridContainer *container)
{
  std::vector <FilterInformation> filters_list;
  for (int i = 0; i < container->RecordsCount(); ++i)
  {
    TGridRecord record = container->GetRecord(i);
    FilterInformation filter = getFilterInfoFromRecord(&record);
    filters_list.push_back(filter);
  }
  return filters_list;
}
//----------------------------------------------------------------------------
