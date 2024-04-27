#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> seen; // Lưu trữ các số đã gặp và chỉ số của chúng

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i]; // Tìm số bổ sung cần thiết

        if (seen.count(complement)) { // Nếu số bổ sung đã xuất hiện trước đó
            return {seen[complement], i}; // Trả về chỉ số của số bổ sung và chỉ số hiện tại
        }

        seen[nums[i]] = i; // Lưu trữ số hiện tại và chỉ số của nó
    }

    return {}; // Trường hợp không tìm thấy cặp số phù hợp (không nên xảy ra theo đề bài)
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

    cout << "Indices: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}