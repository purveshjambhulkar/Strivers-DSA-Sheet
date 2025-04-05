bool subsetUtil(int n, vector<int>& a, int k, int index, int currentSum) {
    // Base Case: If sum matches target
    if (currentSum == k) return true;

    // If we reach the end without finding the sum
    if (index == n) return false;

    // Include current element
    if (subsetUtil(n, a, k, index + 1, currentSum + a[index])) return true;

    // Exclude current element
    if (subsetUtil(n, a, k, index + 1, currentSum)) return true;

    return false;
}

bool isSubsetPresent(int n, int k, vector<int>& a) {
    return subsetUtil(n, a, k, 0, 0);
}
