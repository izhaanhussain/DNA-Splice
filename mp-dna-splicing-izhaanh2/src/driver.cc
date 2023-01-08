#include <iostream>
#include <stdexcept>

#include "dna_strand.hpp"

int main() {
    char pattern[] = "c";
    DNAstrand dna;
    dna.PushBack('c');
    dna.PushBack('t');
    dna.PushBack('a');
    dna.PushBack('t');
    dna.PushBack('a');
    for (unsigned int i = 0; i < dna.TotalSize(); ++i) {
        std::cout << dna.PrintChar(i);
    }
    std::cout << '\n' << std::endl;
    DNAstrand add;
    add.PushBack('*');
    add.PushBack('*');
    // add.PushBack('*');
    for (unsigned int i = 0; i < add.TotalSize(); ++i) {
        std::cout << add.PrintChar(i);
    }
    std::cout << '\n' << std::endl;
    dna.SpliceIn(pattern, add);
    for (unsigned int i = 0; i < dna.TotalSize(); ++i) {
        std::cout << dna.PrintChar(i);
    }
    std::cout << '\n' << std::endl;
    std::cout << dna.GetData(dna.FindStart(pattern));
    // std::cout << dna.StartPosition(pattern) << std::endl;
}