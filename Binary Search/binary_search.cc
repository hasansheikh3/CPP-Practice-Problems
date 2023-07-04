// Algo : Implement a Binary Search Algorithm


int BinarySearch(vector<int> &v, int key)
{
    int low = 0;  // low index
    int high = v.size() - 1;  // high index, size() returns the number of elements in the vector and since the index starts at 0, we need to subtract 1
    int mid = 0;  // mid index

    while (low <= high)  // while low index is less than or equal to high index, means low reaches high
    {
        mid = (low + high) / 2;
        cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
        if (key == v[mid])
        {
            return mid;
        }
        else if (key < v[mid])
        {
            high = mid - 1;
        }
        else if (key > v[mid])
        {
            low = mid + 1;
        }
    }
    return -1;
}


int main()
{
    vector<int> v = {4,5,6,1,2,3};
    int key = 6;
    int index = BinarySearch(v, key);
    cout << "Index of " << key << " is " << index << endl;
    return 0;
}