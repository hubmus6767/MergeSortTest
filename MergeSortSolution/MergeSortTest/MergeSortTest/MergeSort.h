
#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>
#include <cstddef>

/**
 * @brief Szablonowa klasa realizująca algorytm sortowania przez scalanie.
 *
 * Klasa umożliwia sortowanie tablic (std::vector) różnych typów danych,
 * np. int, long int, float oraz double.
 *
 * Typ T musi obsługiwać operator porównania <.
 *
 * @tparam T Typ elementów przechowywanych w tablicy.
 */
template <typename T>
class MergeSort
{
public:

    /**
     * @brief Sortuje tablicę rosnąco za pomocą algorytmu MergeSort.
     *
     * Sortowanie odbywa się bezpośrednio w przekazanej tablicy.
     * Pusta tablica oraz tablica zawierająca jeden element
     * nie wymagają żadnych operacji.
     *
     * @param array Tablica (std::vector) przeznaczona do posortowania.
     */
    static void sort(std::vector<T>& array)
    {
        // Nie ma potrzeby sortowania tablicy z mniej niż dwoma elementami.
        if (array.size() < 2)
        {
            return;
        }

        // Tablica pomocnicza wykorzystywana podczas scalania.
        std::vector<T> temp(array.size());

        // Rozpoczęcie sortowania całego zakresu tablicy.
        mergeSort(array, temp, 0, array.size());
    }

private:

    /**
     * @brief Rekurencyjnie dzieli tablicę na mniejsze fragmenty.
     *
     * Funkcja dzieli aktualny zakres na dwie części, sortuje
     * każdą z nich, a następnie scala posortowane fragmenty.
     *
     * @param array Sortowana tablica.
     * @param temp Tablica pomocnicza.
     * @param left Początkowy indeks zakresu.
     * @param right Końcowy indeks zakresu (nie jest wliczany).
     */
    static void mergeSort(
        std::vector<T>& array,
        std::vector<T>& temp,
        std::size_t left,
        std::size_t right)
    {
        // Jeżeli zakres zawiera maksymalnie jeden element,
        // jest już posortowany.
        if (right - left <= 1)
        {
            return;
        }

        // Wyznaczenie środka aktualnego zakresu.
        const std::size_t middle = left + (right - left) / 2;

        // Rekurencyjne sortowanie lewej połowy.
        mergeSort(array, temp, left, middle);

        // Rekurencyjne sortowanie prawej połowy.
        mergeSort(array, temp, middle, right);

        // Po posortowaniu obu połówek łączymy je w jedną.
        merge(array, temp, left, middle, right);
    }

    /**
     * @brief Scala dwa sąsiadujące, posortowane fragmenty tablicy.
     *
     * Elementy z obu fragmentów są porównywane i umieszczane
     * w odpowiedniej kolejności w tablicy pomocniczej.
     * Następnie wynik jest kopiowany do oryginalnej tablicy.
     *
     * @param array Sortowana tablica.
     * @param temp Tablica pomocnicza.
     * @param left Początek lewego fragmentu.
     * @param middle Koniec lewego i początek prawego fragmentu.
     * @param right Koniec prawego fragmentu (nie jest wliczany).
     */
    static void merge(
        std::vector<T>& array,
        std::vector<T>& temp,
        std::size_t left,
        std::size_t middle,
        std::size_t right)
    {
        // Indeks aktualnie sprawdzanego elementu lewej części.
        std::size_t i = left;

        // Indeks aktualnie sprawdzanego elementu prawej części.
        std::size_t j = middle;

        // Indeks miejsca, w którym zapisujemy kolejny element.
        std::size_t k = left;

        // Porównywanie elementów z obu posortowanych fragmentów.
        while (i < middle && j < right)
        {
            // Wybieramy mniejszy element.
            // Przy równych elementach najpierw wybieramy lewy,
            // dzięki czemu algorytm zachowuje stabilność sortowania.
            if (!(array[j] < array[i]))
            {
                temp[k] = array[i];
                ++i;
            }
            else
            {
                temp[k] = array[j];
                ++j;
            }

            ++k;
        }

        // Przeniesienie pozostałych elementów lewej części.
        while (i < middle)
        {
            temp[k] = array[i];
            ++i;
            ++k;
        }

        // Przeniesienie pozostałych elementów prawej części.
        while (j < right)
        {
            temp[k] = array[j];
            ++j;
            ++k;
        }

        // Przepisanie posortowanego fragmentu do oryginalnej tablicy.
        for (std::size_t x = left; x < right; ++x)
        {
            array[x] = temp[x];
        }
    }
};

#endif // MERGESORT_H
