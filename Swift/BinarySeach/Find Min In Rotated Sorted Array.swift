//* Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.

/* 
# Given an increasing sorted rotated array arr of distinct integers. The array is right-rotated k times. Find the value of k.
# Let's suppose we have an array arr = [2, 4, 6, 9], so if we rotate it by 2 times so that it will look like this:
# After 1st Rotation : [9, 2, 4, 6]
# After 2nd Rotation : [6, 9, 2, 4]

# Examples:

# Input: arr = [5, 1, 2, 3, 4]
# Output: 1
# Explanation: The given array is 5 1 2 3 4. The original sorted array is 1 2 3 4 5. We can see that the array was rotated 1 times to the right.

# Input: arr = [1, 2, 3, 4, 5]
# Output: 0
# Explanation: The given array is not rotated.

* Expected Time Complexity: O(log(n))
* Expected Auxiliary Space: O(1)
*/

func findKRotation(arr: [Int]) -> Int {
    var low = 0
    var high = arr.count - 1
    var ans = Int.max
    var index = -1
    
    while (low <= high) {
        let mid = low + (high - low)/2
        
        if (arr[low] <= arr[mid]) {
            if (arr[low] < ans) {
                ans = arr[low]
                index = low
            }
            low = mid + 1
        } else {
            if (arr[mid] < ans) {
                ans = arr[low]
                index = mid
            }
            high = mid - 1
        }
    }
    return index
}

let sampleOne = findKRotation(arr: [1, 2, 3, 4, 5])
let sampleTwo = findKRotation(arr: [5, 6, 1, 2, 3, 4])

print(sampleOne)
print(sampleTwo)