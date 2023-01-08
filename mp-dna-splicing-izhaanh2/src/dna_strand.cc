#include "dna_strand.hpp"

#include <stdexcept>

// DNAstrand::DNAstrand() {
//     head_ = nullptr;
//     tail_ = nullptr;
// }

DNAstrand::~DNAstrand() {
    Node* next = nullptr;
    while (head_ != nullptr) {
        next = head_ -> next;
        delete head_;
        head_ = next;
    }
}

void DNAstrand::SpliceIn(const char* pattern, DNAstrand& to_splice_in) {
    if (pattern == nullptr) {
        return;
    }
    if (&to_splice_in == this) {
        return;
    }
    if (!IsPresent(pattern, 0)) {
        throw std::invalid_argument("");
    }
    int start_pos = StartPosition(pattern);
    Node* start_node = FindStart(pattern);
    Node* end_node = FindEnd(pattern);
    Node* start = start_node -> next;
    Node* end = end_node;
    Node* next = nullptr;
    while (start != nullptr && start != end) {
        next = start -> next;
        delete start;
        start = next;
    }
    to_splice_in.tail_ -> next = end_node;
    if (start_pos == 0) {
        head_ = to_splice_in.head_;
    } else {
        start_node -> next = to_splice_in.head_;
    }
    to_splice_in.head_ = nullptr;
    to_splice_in.tail_ = nullptr;
}

bool DNAstrand::IsPresent(const char* pattern, unsigned int start_check) {
    Node* current = head_;
    int pattern_size = GetSize(pattern);
    int num = 0;
    for (unsigned int i = 0; i < start_check; ++i) {
        current = current -> next;
    }
    for (int i = 0; i < pattern_size; ++i) {
        if (current != nullptr) {
            if (current -> data == pattern[i]) {
                num++;
                if (num == pattern_size) {
                    return true;
                }
            } else {
                i = -1;
                num = 0;
            }
            current = current -> next;
        } else {
            return false;
        }
    }
    return false;
}

int GetSize(const char* pattern) {
    int ret = 0;
    for (unsigned int i = 0; pattern[i] != '\0'; ++i) {
        ret++;
    }
    return ret;
}

void DNAstrand::PushBack(char value) {
    if (head_ == nullptr) {
        head_ = tail_ = new Node(value);
    } else {
        Node* tmp = new Node(value);
        tail_ -> next = tmp;
        tail_ = tmp;
    }
}

int DNAstrand::StartPosition(const char* pattern) {
    int ret = 0;
    int counter = 0;
    bool present = false;
    Node* current = head_;
    while (current != nullptr) {
        if (current -> data == pattern[0]) {
            present = true;
            Node* tmp = current;
            for (int j = 0; j < GetSize(pattern); ++j) {
                if (tmp == nullptr || tmp -> data != pattern[j]) {
                    present = false;
                    break;
                }
                tmp = tmp -> next;
            }
            if (present) {
                ret = counter;
            }
        }
        current = current -> next;
        counter++;
    }
    return ret;
}

char DNAstrand::PrintChar(unsigned int index) {
    Node* current = head_;
    unsigned int num = 0;
    while (head_ != nullptr) {
        if (num == index) {
            return current -> data;
        } else {
            num++;
            current = current -> next;
        }
    }
    return 'z';
}

char DNAstrand::GetHead() {
    return head_ -> data;
}

unsigned int DNAstrand::TotalSize() {
    unsigned int ret = 0;
    Node* current = head_;
    while (current != nullptr) {
        ret++;
        current = current -> next;
    }
    return ret;
}

Node* DNAstrand::RetHead() {
    return head_;
}

Node* DNAstrand::RetTail() {
    return tail_;
}

Node* DNAstrand::FindEnd(const char* pattern) {
    Node* end_node = head_;
    for (int i = 0; i < GetSize(pattern) + StartPosition(pattern); ++i) {
        end_node = end_node -> next;
    }
    return end_node;
}

char DNAstrand::GetData(Node* node) {
    return node -> data;
}

Node* DNAstrand::FindStart(const char* pattern) {
    Node* start_node = head_;
    int prev_start = StartPosition(pattern) - 1;
    if (prev_start >= 0) {
        for (int i = 0; i < prev_start; ++i) {
            start_node = start_node -> next;
        }
    }
    return start_node;
}