#include <iostream>
#include <fstream>
#include <string>
#include <chrono>

int* fill_array(const std::string& filename, int& num_entries);
void insertion_sort(int arr[], int n);
void exchange_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void smartPrint(int arr[], int n);

int main(int argc, char** argv)
{
    int choice, num_entries;
    std::string file_name = "";
    std::cout << "Welcome to the great sorter!" << std::endl;
    std::cout << "Enter the name of the text file you wish to search\n";
    std::getline(std::cin, file_name);
    int* array = fill_array(file_name, num_entries);
    std::cout << "Array before sorting: \n";
    smartPrint(array, num_entries);

    std::cout << "\n";

    std::cout << "Serveral sorting algorithms are available to use.\nPlease select 1,2,3 for Insertion,exchange and selectiontion\n";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        insertion_sort(array, num_entries);
        break;
    case 2:
        exchange_sort(array, num_entries);
        break;
    case 3:
        selection_sort(array, num_entries);
        break;

    default:
        std::cout << "Invalid choice\n";
        break;
    }

    std::cout << "Array after sorting:\n";
    smartPrint(array, num_entries);

}//end of main

int* fill_array(const std::string& filename, int& num_entries)
{
    std::ifstream infile(filename);

    if (!infile)
    {
        std::cerr << "Error opening file!\n";
        exit(1);
    }

    infile >> num_entries;

    int* array = new int[num_entries];

    for (int i = 0; i < num_entries; i++)
    {
        infile >> array[i];
    }

    infile.close();
    return array;
}

void insertion_sort(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now();//start the clock

    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    auto stop = std::chrono::high_resolution_clock::now();//stop the clock
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);//Calculate the time taken in MS

    std::cout << "Insertion sort time: " << duration.count() << " MS\n";
}

void exchange_sort(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now(); // start the clock

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    auto stop = std::chrono::high_resolution_clock::now();                               // stop the clock
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); // Calculate the time taken in MS

    std::cout << "Insertion sort time: " << duration.count() << " MS\n";
}

void selection_sort(int arr[], int n)
{
    auto start = std::chrono::high_resolution_clock::now(); // start the clock

    for (int i = 0; i < n - 1; i++)
    {
        // Find the minimum element in the unsorted part of the array
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first element in the unsorted part
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }

    auto stop = std::chrono::high_resolution_clock::now();                               // stop the clock
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); // Calculate the time taken in MS

    std::cout << "Insertion sort time: " << duration.count() << " MS\n";
}

void smartPrint(int arr[], int n)
{
    if (n <= 1000)
    {
        // Print all the elements
        for (int i = 0; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    else
    {
        // Print the first 200 elements
        for (int i = 0; i < 200; i++)
        {
            std::cout << arr[i] << " ";
        }

        std::cout << " ... "; // Indicate that some elements were skipped

        // Print the last 200 elements
        for (int i = n - 200; i < n; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << std::endl; // Add a newline after printing the array
}
