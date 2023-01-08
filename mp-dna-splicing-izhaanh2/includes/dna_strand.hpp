#ifndef DNA_STRAND_HPP
#define DNA_STRAND_HPP

#include "node.hpp"

class DNAstrand {
public:
  DNAstrand() = default;
  DNAstrand(const DNAstrand& rhs) = delete;
  DNAstrand& operator=(const DNAstrand& rhs) = delete;
  ~DNAstrand();

  void SpliceIn(const char* pattern, DNAstrand& to_splice_in);
  bool IsPresent(const char* pattern, unsigned int start_check);
  void PushBack(char value);
  int StartPosition(const char* pattern);
  char PrintChar(unsigned int index);
  char GetHead();
  unsigned int TotalSize();
  Node* RetHead();
  Node* RetTail();
  Node* FindEnd(const char* pattern);
  Node* FindStart(const char* pattern);
  char GetData(Node* node);

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
};

int GetSize(const char* pattern);

#endif