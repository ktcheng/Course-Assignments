#ifndef SSNSET_H
#define SSNSET_H

#include "Set.h"
/// #include "newSet.h" // Testing Purposes!!

class SSNSet
{
public:
    // Create an empty SSN set.
    SSNSet();

    // Add an SSN to the SSNSet.  Return true if and only if the SSN
    // was actually added.
    bool add(unsigned long ssn);

    // Return the number of SSNs in the SSNSet.
    int size() const;

    // Write to cout every SSN in the SSNSet exactly once, one per
    // line.  Write no other text.
    void print() const;

private:
    Set m_set;
};

#endif


