//----------------------------------------------------------------------------

#ifndef FilterInformationH
#define FilterInformationH

//----------------------------------------------------------------------------

class FilterInformation
{
public:
  FilterInformation() : index(0), maxFreq(0.0f), minFreq(0.0f)
  { }
  FilterInformation(unsigned int idx, float max_freq, float min_freq) :
    index(idx), maxFreq(max_freq), minFreq(min_freq)
  {}

  bool IsFullEqual(const FilterInformation& filter)
  {
    bool equal = false;
    if (this->index == filter.index)
      if (this->maxFreq == filter.maxFreq && this->minFreq == filter.minFreq) // в данном случае достаточно сравнения float'ов "в лоб"
        equal = true;

    return equal;
  }

  unsigned int index;
  float maxFreq;
  float minFreq;
};
//----------------------------------------------------------------------------

#endif // FilterInformationH
