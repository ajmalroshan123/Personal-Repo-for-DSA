#include <iostream>
using namespace std;

void sebsequence(int arr[], int index, int n, vector<vector<int>> &a, vector<int> temp)
{
    if (index==n) {
        ans.push_back(temp);
        return;
    }

    sebsequence(arr, index+1, n, ans, temp);
    temp.push_back(arr[index]);
    sebsequence(arr, index+1, n, ans, temp);
}


int main(){

    int arr[] = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    sebsequence(arr,0,3,ans,temp);
}


////////////////////////////
// py


// def subsequence(arr, index, n, ans, temp):
//     if index == n:
//         ans.append(temp[:])  # Append a copy of temp
//         return
    
//     # Exclude current element
//     subsequence(arr, index + 1, n, ans, temp)
    
//     # Include current element
//     temp.append(arr[index])
//     subsequence(arr, index + 1, n, ans, temp)
    
//     # Backtrack
//     temp.pop()


// arr = [1, 2, 3]
// ans = []
// temp = []
// subsequence(arr, 0, len(arr), ans, temp)

// print(ans)
