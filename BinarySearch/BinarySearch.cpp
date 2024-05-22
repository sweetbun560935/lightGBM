// BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <cassert>

using namespace std;

class BinarySearch
{
    // NOTE: For a BST, we could find the floor and ceiling values using predecessor and ancestor algorithms respectively!
public:
    bool findIterative(vector<int> data, int value)
    {
        int iLow = 0;
        int iHi = data.size() - 1;
        int iMid = -1;
        while (iLow <= iHi)
        {
            iMid = iLow + ((iHi - iLow) / 2);
            if (data[iMid] == value)
            {
                return true;
            }
            if (data[iMid] < value)
            {
                iLow = iMid + 1;
            }
            else // (data[iMid] > value)
            {
                iHi = iMid - 1;
            }
        }
        return false;
    }
    bool findRecursive(vector<int> data, int value)
    {
        int iLow = 0;
        int iHi = data.size() - 1;
        return _findRecursive(data, value, iLow, iHi);
    }
    bool findFloorIterative(vector<int> data, int value, int* retValue)
    {
        // if the value we're searching for is greater than the largest value in the data, do we return .back() or return Not 
        // Found. Seems subjective so for now we'll just return last element in data

        int iLow = 0;
        int iHi = data.size() - 1;
        int iMid = -1;
        int iFloor = -1;
        while (iLow <= iHi)
        {
            iMid = iLow + ((iHi - iLow) / 2);
            if (data[iMid] == value)
            {
                *retValue = data[iMid];
                return true;
            }
            if (data[iMid] < value)
            {
                iFloor = iMid;
                iLow = iMid + 1;
            }
            else // (data[iMid] > value)
            {
                iHi = iMid - 1;
            }
        }

        if (iFloor != -1)
        {
            *retValue = data[iFloor];
            return true;
        }

        return false;
    }
    bool findCeilingIterative(vector<int> data, int value, int* retValue)
    {
        // if the value we're searching for is less than the smallest value in the data, do we return .front() or return Not 
        // Found. Seems subjective so for now we'll just return first element in data
        int iLow = 0;
        int iHi = data.size() - 1;
        int iMid = -1;
        int iCeiling = -1;
        while (iLow <= iHi)
        {
            iMid = iLow + ((iHi - iLow) / 2);
            if (data[iMid] == value)
            {
                *retValue = data[iMid];
                return true;
            }
            if (data[iMid] < value)
            {
                iLow = iMid + 1;
            }
            else // (data[iMid] > value)
            {
                iCeiling = iMid;
                iHi = iMid - 1;
            }
        }

        if (iCeiling != -1)
        {
            *retValue = data[iCeiling];
            return true;
        }

        return false;
    }

private:
    bool _findRecursive(vector<int> data, int value, int iLow, int iHi)
    {
        if (iLow > iHi)
        {
            return false;
        }
        int iMid = iLow + ((iHi - iLow) / 2);

        if (data[iMid] == value)
        {
            return true;
        }

        if (data[iMid] < value)
        {
            return _findRecursive(data, value, iMid+1, iHi);
        }
        else // (data[iMid] > value)
        {
            return _findRecursive(data, value, iLow, iMid-1);
        }
    }
};

void testBinarySearchIterative()
{
    bool ret = false;
    int value = -1;
    vector<int> dataEmpty;
    vector<int> dataOne{ 3 };
    vector<int> dataN{ 2, 7, 8, 11, 20 };
    vector<int> data;

    BinarySearch s;

    data = dataEmpty;
    ret = s.findIterative(data, 3);
    assert(ret == false);

    data = dataOne;
    value = data.front() - 1;
    ret = s.findIterative(data, value);
    assert(ret == false);
    value = data.front();
    ret = s.findIterative(data, value);
    assert(ret == true);
    value = data.front() + 1;
    ret = s.findIterative(data, value);
    assert(ret == false);

    data = dataN;
    value = data.front() - 1;
    ret = s.findIterative(data, value);
    assert(ret == false);
    value = data.front();
    ret = s.findIterative(data, value);
    assert(ret == true);
    value = data.front() + 1;
    ret = s.findIterative(data, value);
    assert(ret == false);

    data = dataN;
    value = data.back() - 1;
    ret = s.findIterative(data, value);
    assert(ret == false);
    value = data.back();
    ret = s.findIterative(data, value);
    assert(ret == true);
    value = data.back() + 1;
    ret = s.findIterative(data, value);
    assert(ret == false);

    data = dataN;
    for (int i = 0; i < data.size(); ++i)
    {
        ret = s.findIterative(data, data[i]);
        assert(ret == true);
    }
}

void testBinarySearchRecursive()
{
    bool ret = false;
    int value = -1;
    vector<int> dataEmpty;
    vector<int> dataOne{ 3 };
    vector<int> dataN{ 2, 7, 8, 11, 20 };
    vector<int> data;

    BinarySearch s;

    data = dataEmpty;
    ret = s.findRecursive(data, 3);
    assert(ret == false);

    data = dataOne;
    value = data.front() - 1;
    ret = s.findRecursive(data, value);
    assert(ret == false);
    value = data.front();
    ret = s.findRecursive(data, value);
    assert(ret == true);
    value = data.front() + 1;
    ret = s.findRecursive(data, value);
    assert(ret == false);

    data = dataN;
    value = data.front() - 1;
    ret = s.findRecursive(data, value);
    assert(ret == false);
    value = data.front();
    ret = s.findRecursive(data, value);
    assert(ret == true);
    value = data.front() + 1;
    ret = s.findRecursive(data, value);
    assert(ret == false);

    data = dataN;
    value = data.back() - 1;
    ret = s.findRecursive(data, value);
    assert(ret == false);
    value = data.back();
    ret = s.findRecursive(data, value);
    assert(ret == true);
    value = data.back() + 1;
    ret = s.findRecursive(data, value);
    assert(ret == false);

    data = dataN;
    for (int i = 0; i < data.size(); ++i)
    {
        ret = s.findRecursive(data, data[i]);
        assert(ret == true);
    }
}

void testBinarySearchFloorIterative()
{
    bool ret = false;
    int value = -1;
    int retValue = -1;
    vector<int> dataEmpty;
    vector<int> dataOne{ 3 };
    vector<int> dataN{ 2, 7, 8, 11, 20 };
    vector<int> data;

    BinarySearch s;

    data = dataEmpty;
    value = 3;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == false);

    data = dataOne;
    value = data.front() - 1;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == false);
    value = data.front();
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == value);
    value = data.front() + 1;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true); // a little subjective. See comment in implementation!
    assert(retValue == data.front());

    data = dataN;
    value = data.front() - 1;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == false);
    value = data.front();
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == value);
    value = data.front() + 1;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == data.front());

    data = dataN;
    value = data.back() - 1;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == data[data.size() - 2]);
    value = data.back();
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == value);
    value = data.back() + 1;
    ret = s.findFloorIterative(data, value, &retValue);
    assert(ret == true); // a little subjective. See comment in implementation!
    assert(retValue == data.back());

    data = dataN;
    for (int i = 0; i < data.size(); ++i)
    {
        ret = s.findFloorIterative(data, data[i], &retValue);
        assert(ret == true);
        assert(retValue == data[i]);
    }
}

void testBinarySearchCeilingIterative()
{
    bool ret = false;
    int value = -1;
    int retValue = -1;
    vector<int> dataEmpty;
    vector<int> dataOne{ 3 };
    vector<int> dataN{ 2, 7, 8, 11, 20 };
    vector<int> data;

    BinarySearch s;

    data = dataEmpty;
    value = 3;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == false);

    data = dataOne;
    value = data.front() - 1;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true); // a little subjective. See comment in implementation!
    assert(retValue == data.front());
    value = data.front();
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == value);
    value = data.front() + 1;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == false);

    data = dataN;
    value = data.front() - 1;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true); // a little subjective. See comment in implementation!
    assert(retValue == data.front());
    value = data.front();
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == value);
    value = data.front() + 1;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == data[1]);

    data = dataN;
    value = data.back() - 1;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == data[data.size() - 1]);
    value = data.back();
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == true);
    assert(retValue == value);
    value = data.back() + 1;
    ret = s.findCeilingIterative(data, value, &retValue);
    assert(ret == false); // a little subjective. See comment in implementation!

    data = dataN;
    for (int i = 0; i < data.size(); ++i)
    {
        ret = s.findCeilingIterative(data, data[i], &retValue);
        assert(ret == true);
        assert(retValue == data[i]);
    }
}

int main()
{
    testBinarySearchIterative();
    testBinarySearchRecursive();
    testBinarySearchFloorIterative();
    testBinarySearchCeilingIterative();

    return 0;
}

