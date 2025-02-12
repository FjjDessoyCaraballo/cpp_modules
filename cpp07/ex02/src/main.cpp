/* ****************************************************************************/
/*  ROFL:ROFL:ROFL:ROFL 													  */
/*          _^___      														  */
/* L     __/   [] \    														  */
/* LOL===__        \   			MY ROFLCOPTER GOES BRRRRRR					  */
/* L      \________]  					by fdessoy-							  */
/*         I   I     			(fdessoy-@student.hive.fi)					  */
/*        --------/   														  */
/* ****************************************************************************/

#include "../inc/Array.hpp"

// #define MAX_VAL 750 // DO NOT SET THIS FOR MORE THAN 10 000 FOR THE LOVE OF GOD

// int main(int , char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;
//     return 0;
// }

#include <cassert>

void test_default_constructor() 
{
    Array<int> arr;
    assert(arr.size() == 1);
    std::cout << "✅ Default Constructor Test Passed\n";
}

void test_zero_size() 
{
    Array<int> arr(0);
    assert(arr.size() == 0);
    std::cout << "✅ Zero-Size Array Test Passed\n";
}

void test_large_size() 
{
    Array<int> arr(1000000);
    assert(arr.size() == 1000000);
    std::cout << "✅ Large Size Array Test Passed\n";
}

void test_copy_constructor() 
{
    Array<int> arr(10);
    for (uint32_t i = 0; i < arr.size(); ++i)
        arr[i] = i * 2;

    Array<int> copy(arr);
    for (uint32_t i = 0; i < arr.size(); ++i)
        assert(copy[i] == arr[i]);

    std::cout << "✅ Copy Constructor Test Passed\n";
}

void test_assignment_operator() 
{
    Array<int> arr1(5);
    Array<int> arr2(5);

    for (uint32_t i = 0; i < arr1.size(); ++i)
        arr1[i] = i + 10;

    arr2 = arr1;

    for (uint32_t i = 0; i < arr2.size(); ++i)
        assert(arr2[i] == arr1[i]);

    std::cout << "✅ Assignment Operator Test Passed\n";
}

void test_out_of_bounds() 
{
    Array<int> arr(5);
    bool caught = false;

    try {
        arr[5] = 100;
    } catch (const std::exception &e) {
        caught = true;
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    assert(caught);

    caught = false;
    try {
        arr[-1] = 100;
    } catch (const std::exception &e) {
        caught = true;
        std::cout << "Caught exception: " << e.what() << '\n';
    }
    assert(caught);

    std::cout << "✅ Out-of-Bounds Test Passed\n";
}

void test_modify_elements() 
{
    Array<int> arr(5);
    for (size_t i = 0; i < arr.size(); ++i)
        arr[i] = static_cast<int>(i * 3);

    for (size_t i = 0; i < arr.size(); ++i)
        assert(arr[i] == static_cast<int>(i * 3));

    std::cout << "✅ Modify Elements Test Passed\n";
}

int main(int, char**) {
    test_default_constructor();
    test_zero_size();
    test_large_size();
    test_copy_constructor();
    test_assignment_operator();
    test_out_of_bounds();
    test_modify_elements();
    std::cout << "\n🎉 ALL TESTS PASSED SUCCESSFULLY! 🎉\n";
    return 0;
}
