#if !defined(AFX_SECURITYINT_H__21765369_AE5A_4801_9422_A18537972861__INCLUDED_)
#define AFX_SECURITYINT_H__21765369_AE5A_4801_9422_A18537972861__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif

#include <windows.h>
#include <Winbase.h>
#include <iostream>

class CInt
{
public:
    CInt()
        : m_pValue(new int(0)), m_iKeyValue(0), old(0)
    {
    }

    ~CInt()
    {
        delete m_pValue;
    }

    int Get()
    {
        return *m_pValue;
    }

    void Set(const int& iValue)
    {
        *m_pValue = iValue;
    }

    CInt& operator=(const int& iValue)
    {
        *m_pValue = iValue;
        return *this;
    }

    operator int()
    {
        return *m_pValue;
    }

protected:
    int* m_pValue;
    int m_iKeyValue;
    unsigned long old;
};

#endif
