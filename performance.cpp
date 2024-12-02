#include <iostream>
#include <fstream>
#include <ctime>  // For time measurement using clock()
#include <cstdlib> // For rand()
#include <ctime>   // For time-based randomness
#include "HashMap.cpp"

// Function to simulate performance analysis with deletions and searches
void performance_analysis_with_deletions() {
    const std::size_t num_buckets = 100;  // Fixed number of buckets
    HashMap<int, int> hashMap(num_buckets);

    std::ofstream output("performance_with_deletions.csv");
    output << "NumElements,LoadFactor,ElementsPerSlot,Runtime(ms),DeletionsTime(ms)\n";

    const int max_elements = 1000000;  // Max number of elements to insert
    int num_elements = 100;           // Start with 100 elements

    // Set up random number generator for deleting elements with probability 0.5
    srand(static_cast<unsigned int>(time(0)));

    while (num_elements <= max_elements) {
        // Start measuring time
        clock_t start_time = clock();

        // Insert elements into the hash map
        for (int i = 0; i < num_elements; ++i) {
            hashMap.insert(i, i);
        }

        // Track deletions: n/10 deletions
        int numDeletions = num_elements / 10;
        clock_t deletion_start_time = clock();
        for (int i = 0; i < numDeletions; ++i) {
            if (rand() < RAND_MAX / 2) {  // With probability 0.5
                int keyToDelete = rand() % num_elements;  // Generate random key to delete
                try {
                    hashMap.remove(keyToDelete);  // Try to remove the element
                } catch (const std::runtime_error& e) {
                    // Handle the error (e.g., element not found)
                    std::cout << "Error: " << e.what() << " for key " << keyToDelete << std::endl;
                }
            }
        }
        clock_t deletion_end_time = clock();
        double deletion_time = static_cast<double>(deletion_end_time - deletion_start_time) / CLOCKS_PER_SEC * 1000.0;

        // End measuring time
        clock_t end_time = clock();
        double elapsed_time = static_cast<double>(end_time - start_time) / CLOCKS_PER_SEC * 1000.0;  // Convert to milliseconds

        // Calculate load factor
        double load_factor = static_cast<double>(num_elements) / num_buckets;

        // Calculate average elements per slot
        int total_elements = 0;
        for (std::size_t i = 0; i < num_buckets; ++i) {
            Node<int, int>* current = hashMap.search(i);
            while (current != nullptr) {
                ++total_elements;
                current = current->next;
            }
        }
        double avg_elements_per_slot = static_cast<double>(total_elements) / num_buckets;

        // Write data to file
        output << num_elements << "," << load_factor << "," << avg_elements_per_slot << "," << elapsed_time << "," << deletion_time << "\n";
        std::cout << "Inserted " << num_elements << " elements. Runtime: " << elapsed_time << " ms, Deletions Time: " << deletion_time << " ms\n";

        // Increase num_elements by a factor of 10
        num_elements *= 10;
    }

    output.close();
    std::cout << "Performance data with deletions written to 'performance_with_deletions.csv'.\n";
}

int main() {
    performance_analysis_with_deletions();
    return 0;
}
