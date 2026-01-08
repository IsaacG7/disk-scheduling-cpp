//********************************************************************
//
// Isaac Godsey
// Operating Systems
// Programming Project #7: Disk Scheduling Algorithms
// November 7th, 2025
// Instructor: Dr. Siming Liu
//
//********************************************************************
#include "disk_algorithms.h"

int main(int argc, char *argv[])
{
    srand(time(nullptr));

    // get initial position passed in command line
    if (argv[1] == nullptr)
    {
        std::cout << "Error: Enter starting position!" << std::endl;
        return 0;
    }
    int initial_pos = atoi(argv[1]);

    std::vector<int> requests(1000, 0);
    // filling a requests array with 1000 random requests from 0-2999
    for (int x = 0; x < 1000; x++)
    {
        requests[x] = rand() % NUM_CYLINDERS;
    }
    std::cout << "FCFS: " << FCFS(initial_pos, requests) << std::endl
              << "SSTF: " << SSTF(initial_pos, requests) << std::endl
              << "SCAN: " << SCAN(initial_pos, requests) << std::endl
              << "C-SCAN: " << C_SCAN(initial_pos, requests) << std::endl
              << "LOOK: " << LOOK(initial_pos, requests) << std::endl
              << "C-LOOK: " << C_LOOK(initial_pos, requests) << std::endl;
}

int FCFS(int initial, const std::vector<int> &requests)
{
    int distance = 0;
    int current_pos = initial;
    for (int x = 0; x < requests.size(); x++)
    {
        distance += abs(requests[x] - current_pos);
        current_pos = requests[x];
    }
    return distance;
}
int SSTF(int initial, const std::vector<int> &requests)

{
    std::map<int, bool> map;
    int current_pos = initial;
    int next_pos = -1;
    int tot_distance = 0;

    // initialize map with request values to false
    for (int i = 0; i < requests.size(); i++)
    {
        map[requests[i]] = false;
    }

    while (1)
    {
        int counter = 0;
        int smallest_distance = INT_MAX;
        for (int x = 0; x < requests.size(); x++)
        {
            if (map[requests[x]] == true)
            {
                continue;
            }
            // if the distance to the next request is smaller than
            // the smallest we have found so far
            if (abs(current_pos - requests[x]) < smallest_distance)
            {
                // set a new smallest distance and position
                smallest_distance = abs(current_pos - requests[x]);
                next_pos = requests[x];
            }
        }
        // move to next request
        tot_distance += smallest_distance;
        current_pos = next_pos;
        map[current_pos] = true;

        // loop through map to see if all requests have been visited
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second == true)
            {
                counter++;
            }
        }
        if (counter == map.size())
        {
            break;
        }
    }
    return tot_distance;
}
int SCAN(int initial, const std::vector<int> &requests)
{
    std::map<int, bool> map;
    int current_pos = initial;
    bool going_down = false;
    int next_pos = -1;
    int tot_distance = 0;
    auto it_max = std::max_element(requests.begin(), requests.end());
    auto it_min = std::min_element(requests.begin(), requests.end());

    // initialize map with request values to false
    for (int i = 0; i < requests.size(); i++)
    {
        map[requests[i]] = false;
    }

    while (1)
    {
        int counter = 0;
        int smallest_distance = INT_MAX;
        for (int x = 0; x < requests.size(); x++)
        {
            if (map[requests[x]] == true)
            {
                continue;
            }
            // look at requests only larger than the position were at
            //  because we assume we are heading in the upward direction of cylinders
            if ((requests[x] < current_pos && !going_down) || (requests[x] > current_pos && going_down))
            {
                continue;
            }
            // if the distance to the next request is smaller than
            // the smallest we have found so far
            if (abs(current_pos - requests[x]) < smallest_distance)
            {
                // set a new smallest distance and position
                smallest_distance = abs(current_pos - requests[x]);
                next_pos = requests[x];
            }
        }
        // move to next request
        tot_distance += smallest_distance;
        current_pos = next_pos;
        map[current_pos] = true;

        // if the current position is the max value of the vector
        // we have to start heading in the other direction
        if (current_pos == *it_max)
        {
            going_down = true;
            tot_distance += (NUM_CYLINDERS - 1) - current_pos;
        }
        else if (current_pos == *it_min)
        {
            tot_distance += current_pos;
            going_down = false;
        }

        // loop through map to see if all requests have been visited
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second == true)
            {
                counter++;
            }
        }
        if (counter == map.size())
        {
            break;
        }
    }
    return tot_distance;
}
int C_SCAN(int initial, const std::vector<int> &requests)
{
    std::map<int, bool> map;
    int current_pos = initial;
    int next_pos = -1;
    int tot_distance = 0;
    auto it_max = std::max_element(requests.begin(), requests.end());
    // initialize map with request values to false
    for (int i = 0; i < requests.size(); i++)
    {
        map[requests[i]] = false;
    }

    while (1)
    {
        int counter = 0;
        int smallest_distance = INT_MAX;
        for (int x = 0; x < requests.size(); x++)
        {
            if (map[requests[x]] == true)
            {
                continue;
            }
            // look at requests only larger than the position were at
            //  because we assume we are heading in the upward direction of cylinders
            if (requests[x] < current_pos)
            {
                continue;
            }
            // if the distance to the next request is smaller than
            // the smallest we have found so far
            if (abs(current_pos - requests[x]) < smallest_distance)
            {
                // set a new smallest distance and position
                smallest_distance = abs(current_pos - requests[x]);
                next_pos = requests[x];
            }
        }
        // move to next request
        tot_distance += smallest_distance;
        current_pos = next_pos;
        map[current_pos] = true;

        // if the current position is the max value of the vector
        // we have to start heading in the other direction
        if (current_pos == *it_max)
        {
            tot_distance += (NUM_CYLINDERS - 1 - current_pos) + (NUM_CYLINDERS - 1);
            current_pos = 0;
        }

        // loop through map to see if all requests have been visited
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second == true)
            {
                counter++;
            }
        }
        if (counter == map.size())
        {
            break;
        }
    }
    return tot_distance;
}
int LOOK(int initial, const std::vector<int> &requests)
{
    std::map<int, bool> map;
    int current_pos = initial;
    bool going_down = false;
    int next_pos = -1;
    int tot_distance = 0;
    auto it_max = std::max_element(requests.begin(), requests.end());
    auto it_min = std::min_element(requests.begin(), requests.end());

    // initialize map with request values to false
    for (int i = 0; i < requests.size(); i++)
    {
        map[requests[i]] = false;
    }

    while (1)
    {
        int counter = 0;
        int smallest_distance = INT_MAX;
        for (int x = 0; x < requests.size(); x++)
        {
            if (map[requests[x]] == true)
            {
                continue;
            }
            // look at requests only larger than the position were at
            //  because we assume we are heading in the upward direction of cylinders
            if ((requests[x] < current_pos && !going_down) || (requests[x] > current_pos && going_down))
            {
                continue;
            }
            // if the distance to the next request is smaller than
            // the smallest we have found so far
            if (abs(current_pos - requests[x]) < smallest_distance)
            {
                // set a new smallest distance and position
                smallest_distance = abs(current_pos - requests[x]);
                next_pos = requests[x];
            }
        }
        // move to next request
        tot_distance += smallest_distance;
        current_pos = next_pos;
        map[current_pos] = true;

        // if the current position is the max value of the vector
        // we have to start heading in the other direction
        if (current_pos == *it_max)
        {
            going_down = true;
        }
        else if (current_pos == *it_min)
        {
            going_down = false;
        }

        // loop through map to see if all requests have been visited
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second == true)
            {
                counter++;
            }
        }
        if (counter == map.size())
        {
            break;
        }
    }
    return tot_distance;
}
int C_LOOK(int initial, const std::vector<int> &requests)
{
    std::map<int, bool> map;
    int current_pos = initial;
    int next_pos = -1;
    int tot_distance = 0;
    auto it_max = std::max_element(requests.begin(), requests.end());
    auto it_min = std::min_element(requests.begin(), requests.end());

    // initialize map with request values to false
    for (int i = 0; i < requests.size(); i++)
    {
        map[requests[i]] = false;
    }
    while (1)
    {
        int counter = 0;
        int smallest_distance = INT_MAX;
        for (int x = 0; x < requests.size(); x++)
        {
            if (map[requests[x]] == true)
            {
                continue;
            }
            // look at requests only larger than the position were at
            //  because we assume we are heading in the upward direction of cylinders
            if (requests[x] < current_pos)
            {
                continue;
            }
            // if the distance to the next request is smaller than
            // the smallest we have found so far
            if (abs(current_pos - requests[x]) < smallest_distance)
            {
                // set a new smallest distance and position
                smallest_distance = abs(current_pos - requests[x]);
                next_pos = requests[x];
            }
        }
        // move to next request
        tot_distance += smallest_distance;
        current_pos = next_pos;
        map[current_pos] = true;

        // if the current position is the max value of the vector
        // we have to start heading in the other direction
        if (current_pos == *it_max)
        {
            tot_distance += abs(current_pos - *it_min);
            current_pos = *it_min;
        }

        // loop through map to see if all requests have been visited
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            if (it->second == true)
            {
                counter++;
            }
        }
        if (counter == map.size())
        {
            break;
        }
    }
    return tot_distance;
}