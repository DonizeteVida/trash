#include <iostream>
#include <vector>
#include <map>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::map<int, int> mapped;
    for (int index = 0; index < nums.size(); index++) {
        mapped[nums[index]] = index;
    }
    std::vector<int> result;
    for (int index = 0; index < nums.size(); index++)
    {   
        int diff = target - nums[index];
        auto find = mapped.find(diff);
        if (find != mapped.end() && index != find->second) {
            result.push_back(index);
            result.push_back(find->second);
            break;
        }
    }
    return result;
}

int main()
{
    std::vector<int> data = {3, 2, 4};
    auto res = twoSum(data, 6);
    for (int i : res) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}