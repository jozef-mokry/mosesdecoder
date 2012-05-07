#pragma once

#include <vector>
#include <string>

class Alignment;
class PhrasePair;
class SuffixArray;
class TargetCorpus;
class Mismatch;

class PhrasePairCollection
{
public:
  typedef unsigned int INDEX;

private:
  SuffixArray *m_suffixArray;
  TargetCorpus *m_targetCorpus;
  Alignment *m_alignment;
  std::vector<std::vector<PhrasePair*> > m_collection;
  std::vector< Mismatch* > m_mismatch, m_unaligned;
  int m_size;
  int m_max_lookup;
  int m_max_pp_target;
  int m_max_pp;

public:
  PhrasePairCollection ( SuffixArray *, TargetCorpus *, Alignment * );
  ~PhrasePairCollection ();

  bool GetCollection( const std::vector<std::string > sourceString );
  void Print();
  void PrintHTML();
};

// sorting helper
struct CompareBySize {
  bool operator()(const std::vector<PhrasePair*> a, const std::vector<PhrasePair*> b ) const {
    return a.size() > b.size();
  }
};
