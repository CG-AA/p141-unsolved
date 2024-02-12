#include<bits/stdc++.h> // Include the necessary header files

using namespace std;

int main(){
    int T; // Number of test cases
    cin >> T; // Read the number of test cases from input

    for(int Days = 0; Days < T; Days++){ // Loop through each test case
        int N, Q; // Number of groups and number of operations
        cin >> N >> Q; // Read the number of groups and number of operations from input

        unordered_map<int, int> gps; // Map to store the group of each person
        deque<pair<int, int>> line; // Queue to simulate the line

        for(int i = 0; i < N; i++){ // Loop through each group
            int cj = 0; // Number of people in the group
            cin >> cj; // Read the number of people in the group from input

            for(int j = 0; j < cj; j++){ // Loop through each person in the group
                int temp; // Temporary variable to store the person's ID
                cin >> temp; // Read the person's ID from input
                gps[temp] = i; // Map the person's ID to the group number
            }
        }

        int head = -1; // Index of the person at the front of the line

        for(int i = 0; i < Q; i++){ // Loop through each operation
            int oper; // Operation type
            cin >> oper; // Read the operation type from input

            if(oper == 1){ // If the operation is to add a person to the line
                int temp; // Temporary variable to store the person's ID
                cin >> temp; // Read the person's ID from input
                line.push_back(make_pair(temp, gps.find(temp)->second)); // Add the person to the line with their group number
            }else{ // If the operation is to remove a person from the line
                if(line.empty()){ // If the line is empty
                    cout << "-1"; // Print -1 to indicate that there is no person in the line
                }else {
                    while(line.front().first == -1){ // Remove any person with ID -1 from the front of the line
                        line.pop_front(); // Remove the person from the front of the line

                        if(head != -1){ // If there is a person at the front of the line
                            head--; // Decrement the index of the person at the front of the line
                        }
                    }

                    if(line.empty()){ // If the line is empty after removing persons with ID -1
                        cout << "-1"; // Print -1 to indicate that there is no person in the line
                        break; // Exit the loop
                    }

                    if(head == -1){ // If there is no SPECIFIC person at the front of the line
                        cout << line.front().first; // Print the ID of the person at the front of the line
                        int temp = line.front().second; // Get the group number of the person at the front of the line
                        line.pop_front(); // Remove the person from the front of the line

                        bool nosamegp = 1; // Flag to check if there is another person in the same group
                        for(int j = 0; j < line.size(); j++){ // Loop through the remaining persons in the line
                            if(temp == line[j].second){ // If there is another person in the same group
                                head = j; // Set the index of the person at the front of the line to the index of the person in the same group
                                nosamegp = 0; // Set the flag to false
                                break; // Exit the loop
                            }
                        }

                        if(nosamegp){ // If there is no person in the same group
                            head = -1; // Set the index of the person at the front of the line to -1
                        }
                    }else{ // If there is a SPECIFIC person at the front of the line
                        cout << line[head].first; // Print the ID of the SPECIFIC person at the front of the line
                        int temp = line[head].second; // Get the group number of the SPECIFIC person at the front of the line
                        line[head].first = line[head].second = -1; // Set the ID and group number of the SPECIFIC person at the front of the line to -1

                        bool nosamegp = 1; // Flag to check if there is another person in the same group
                        for(int j = 0; j < line.size(); j++){ // Loop through the remaining persons in the line
                            if(temp == line[j].second){ // If there is another person in the same group
                                head = j; // Set the index of the that person to head
                                nosamegp = 0; // Set the flag to false
                                break; // Exit the loop
                            }
                        }

                        if(nosamegp){ // If there is no person in the same group
                            head = -1; // Set the index of the person at the front of the line to -1
                        }
                    }
                }
                cout << endl; // Print a new line
            }
        }
    }

    return 0; // Exit the program
}
