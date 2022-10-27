#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;




class Bag
{
public:
    Bag()
    {
    }

    bool addItem(int item)
    {
        Contents.push_back(item);
        return true;
    }
    
    virtual int removeItem()
    {
        int ret = Contents.back();
        Contents.pop_back();
        return ret;
    }
   

    bool deleteItem(const int& item)
    {
        int temp;
        bool deleted = false;
        for (int i = 0; i < Contents.size(); i++)
        {
            if (Contents[i] == item)
            {
                temp = Contents[i];
                Contents[i] = Contents[Contents.size() - 1];
                Contents[Contents.size() - 1] = temp;
                Contents.pop_back();
                deleted = true;
                break;
            }
        }
        return deleted;
    }

    bool deleteAll(const int& item)
    {
        int temp;
        bool deleted = false;
        for (int i = 0; i < Contents.size(); i++)
        {
            if (Contents[i] == item)
            {
                temp = Contents[i];
                Contents[i] = Contents[Contents.size() - 1];
                Contents[Contents.size() - 1] = temp;
                Contents.pop_back();
                deleted = true;
            }
        }
        return deleted;
    }
    int size()
    {
        return Contents.size();
    }
    void clear()
    {
        Contents.clear();
    }
protected:
    vector<int> Contents;
};

class OrderedBag : public Bag
{
 
    virtual int removeItem()
    {
        int min = INT_MAX;
        int minpos = -1;
        for (int i = 0; i < Contents.size(); i++)
        {
            if (min > Contents[i])
            {
                minpos = i;
                min = Contents[i];
            }
        }
        if (minpos != -1)
        {
            int temp = Contents[minpos];
            Contents[minpos] = Contents[Contents.size() - 1];
            Contents[Contents.size() - 1] = temp;
            return Bag::removeItem();
        }
        return -1;
    }
};
