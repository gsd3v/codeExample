//----------------------------------------------------------------------------

#ifndef FilterInformationAdapterH
#define FilterInformationAdapterH

//----------------------------------------------------------------------------

#include <vector>
#include "EnumDecorator.h"

//----------------------------------------------------------------------------

class FilterInformation;
class TGridContainer;
class TGridRecord;

//----------------------------------------------------------------------------

class FilterInfoIndex : public EnumDecorator
{
public:
  enum EnumIndex__
  {
    First = 0,
    FilterId = First,
    MaxFreq,
    MinFreq,
    Last = MinFreq,

    Count
  };
};
//----------------------------------------------------------------------------

FilterInformation getFilterInfoFromRecord(TGridRecord *record);
std::vector <FilterInformation> getFilterInfoListFromContainer(TGridContainer *container);

//----------------------------------------------------------------------------

#endif // FilterInformationAdapterH
