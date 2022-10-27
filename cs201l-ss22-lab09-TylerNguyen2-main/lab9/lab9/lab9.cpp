#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
#include "Header.h"
using namespace std;
const string inputfile("input.txt");
const string outputfile("output.txt");
const string orderedoutputfile("output1.txt"); 

void TestBag(Bag* b, FILE* input, FILE* output)
{
    char operation;
    int value;
    int cnt = 0;
    while (!feof(input))
    {
        fscanf(input, "%c", &operation);
        switch (operation)
        {
        case 'A':
        {
            fscanf(input, "%d", &value);
            fprintf(output, "Adding %d.", value);
            if (b->addItem(value))
            {
                fprintf(output, " Add Successful.\n");
            }
            else
            {
                fprintf(output, " Add Not Successful.\n");
            }
        }
        break;
        case 'R':
        {
            if (b->size() > 0)
            {
                fprintf(output, "Removing item, ");
                int item = b->removeItem();
                fprintf(output, " got %d\n", item);
            }
            else
            {
                cout << "Bag is empty.." << endl;
            }
        }
        break;
        case 'D':
        {
            fscanf(input, "%d", &value);
            fprintf(output, "Deleting %d.", value);
            if (b->deleteItem(value))
            {
                fprintf(output, " Deleting Successful.\n");
            }
            else
            {
                fprintf(output, " Deleting Not Successful.\n");
            }
        }
        break;

        case 'Z':
        {
            fscanf(input, "%d", &value);
            fprintf(output, "Deleting all instances of %d.", value);
            if (b->deleteAll(value))
            {
                fprintf(output, " Deleting Successful.\n");
            }
            else
            {
                fprintf(output, " Deleting Not Successful.\n");
            }
        }
        break;
        default:
            break;
        }
        fscanf(input, "\n");
        if (cnt == 25)
        {
            int r = 0;
        }
        cnt++;
    }
}

int main()
{
    FILE* input = fopen(inputfile.c_str(), "r");
    FILE* output = fopen(outputfile.c_str(), "w");
    Bag b;
    OrderedBag ob;
    fprintf(output, "Beginning processing with regular Bag.\n");
    TestBag(&b, input, output);
    fprintf(output, "At end of processing, the bag still has %d items\n", ob.size());
    fclose(input);
    fclose(output);
    input = fopen(inputfile.c_str(), "r");
    FILE* outputordered = fopen(orderedoutputfile.c_str(), "w");
    fprintf(outputordered, "Repeating the process, with an Ordered Bag.\n");
    TestBag(&ob, input, outputordered);
    fprintf(outputordered, "At end of processing, the ordered bag still has %d items\n",
        ob.size());

    fclose(outputordered);
}
