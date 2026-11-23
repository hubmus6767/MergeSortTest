
#include "MergeSort.h"
#include <gtest/gtest.h>

#include <algorithm>
#include <random>
#include <vector>

// ============================================================
// TEST 1
// Sprawdzenie, czy posortowana rosnąco tablica pozostaje bez zmian.
// ============================================================

TEST(MergeSortTest, AlreadySortedArray)
{
    std::vector<int> array = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    const std::vector<int> original = array;

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, original);
}

// ============================================================
// TEST 2
// Sortowanie tablicy posortowanej w odwrotnej kolejności.
// ============================================================

TEST(MergeSortTest, ReverseSortedArray)
{
    std::vector<int> array = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    const std::vector<int> expected = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 3
// Sortowanie losowej tablicy liczb.
// ============================================================

TEST(MergeSortTest, RandomArray)
{
    std::vector<int> array;

    // Generator z ustalonym ziarnem zapewnia powtarzalność testu.
    std::mt19937 generator(12345);

    std::uniform_int_distribution<int> distribution(-1000, 1000);

    for (int i = 0; i < 100; ++i)
    {
        array.push_back(distribution(generator));
    }

    // Przygotowanie oczekiwanego wyniku.
    std::vector<int> expected = array;

    std::sort(expected.begin(), expected.end());

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 4
// Sortowanie tablicy zawierającej wyłącznie liczby ujemne.
// ============================================================

TEST(MergeSortTest, OnlyNegativeNumbers)
{
    std::vector<int> array = { -10, -50, -2, -100, -25, -1 };

    const std::vector<int> expected = {
        -100, -50, -25, -10, -2, -1
    };

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 5
// Sortowanie tablicy zawierającej liczby ujemne i dodatnie.
// ============================================================

TEST(MergeSortTest, NegativeAndPositiveNumbers)
{
    std::vector<int> array = { 10, -5, 20, -15, 0, 8, -1 };

    const std::vector<int> expected = {
        -15, -5, -1, 0, 8, 10, 20
    };

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 6
// Sprawdzenie obsługi pustej tablicy.
// ============================================================

TEST(MergeSortTest, EmptyArray)
{
    std::vector<int> array;

    EXPECT_NO_THROW(MergeSort<int>::sort(array));

    EXPECT_TRUE(array.empty());
}

// ============================================================
// TEST 7
// Sprawdzenie tablicy zawierającej tylko jeden element.
// ============================================================

TEST(MergeSortTest, SingleElementArray)
{
    std::vector<int> array = { 42 };

    const std::vector<int> original = array;

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, original);
}

// ============================================================
// TEST 8
// Sortowanie tablicy zawierającej duplikaty.
// ============================================================

TEST(MergeSortTest, ArrayWithDuplicates)
{
    std::vector<int> array = { 5, 2, 8, 2, 1, 5, 9, 1 };

    const std::vector<int> expected = {
        1, 1, 2, 2, 5, 5, 8, 9
    };

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 9
// Sortowanie tablicy z liczbami ujemnymi i duplikatami.
// ============================================================

TEST(MergeSortTest, NegativeNumbersWithDuplicates)
{
    std::vector<int> array = {
        -5, -2, -10, -5, -2, -10, -1
    };

    const std::vector<int> expected = {
        -10, -10, -5, -5, -2, -2, -1
    };

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 10
// Sortowanie liczb ujemnych, dodatnich oraz duplikatów.
// ============================================================

TEST(MergeSortTest, MixedNumbersWithDuplicates)
{
    std::vector<int> array = {
        5, -3, 5, 0, -3, 8, -10, 8, 1, -10
    };

    const std::vector<int> expected = {
        -10, -10, -3, -3, 0, 1, 5, 5, 8, 8
    };

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 11
// Tablica zawierająca dokładnie dwa elementy w kolejności rosnącej.
// ============================================================

TEST(MergeSortTest, TwoElementsAscending)
{
    std::vector<int> array = { 1, 2 };

    const std::vector<int> original = array;

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, original);
}

// ============================================================
// TEST 12
// Sortowanie dużej tablicy zawierającej ponad 100 elementów.
// ============================================================

TEST(MergeSortTest, LargeArrayOver100Elements)
{
    std::vector<int> array;

    // Utworzenie tablicy 500 elementów w odwrotnej kolejności.
    for (int i = 500; i >= 1; --i)
    {
        array.push_back(i);
    }

    std::vector<int> expected = array;

    std::sort(expected.begin(), expected.end());

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST 13
// Duża tablica z liczbami ujemnymi, dodatnimi i duplikatami.
// ============================================================

TEST(MergeSortTest, LargeMixedArrayWithDuplicates)
{
    std::vector<int> array;

    // Utworzenie dużej tablicy z liczbami od -50 do 50.
    // Wartości będą się powtarzać.
    for (int i = 0; i < 1000; ++i)
    {
        array.push_back((i % 101) - 50);
    }

    // Dodatkowo odwracamy kolejność elementów.
    std::reverse(array.begin(), array.end());

    std::vector<int> expected = array;

    std::sort(expected.begin(), expected.end());

    MergeSort<int>::sort(array);

    EXPECT_EQ(array, expected);
}

// ============================================================
// TEST DODATKOWY 14
// Sprawdzenie działania szablonu dla typu double.
// ============================================================

TEST(MergeSortTest, DoubleArray)
{
    std::vector<double> array = {
        5.5, -2.3, 10.1, 0.5, -8.7, 3.2
    };

    const std::vector<double> expected = {
        -8.7, -2.3, 0.5, 3.2, 5.5, 10.1
    };

    MergeSort<double>::sort(array);

    EXPECT_EQ(array, expected);
}
