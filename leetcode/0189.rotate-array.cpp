// 1) rotate on one shift k % n times
// 2) start rotation until n elements rotated, else dive into next element
// 3) copy array and insert elements
// 4) reverse whole array and then reverse first k elements and last (n - k) elements
// 5) 
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if (k%n == 0) return;
        int first = 0, middle = n-k%n, last = n;
        int next = middle;
        while(first != next) {
            swap (nums[first++], nums[next++]);
            cout << endl;
            if (next == last) {
              next = middle;
            }
            else if (first == middle) {
               middle = next;
            }
        }
    }
};

