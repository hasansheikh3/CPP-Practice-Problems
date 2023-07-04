// Algorithm : Check if an array is circular sorted

bool IsCircularSorted(vector<int> &v)
{
    int low = 0;
    int high = v.size() - 1;
    int mid = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        cout << "low: " << low << " high: " << high << " mid: " << mid << endl;
        if (v[low] <= v[mid] && v[mid] <= v[high]) // if the array is sorted, then the first element will be less than the middle element and the middle element will be less than the last element
        {
            return true;
        }
        else if (v[low] <= v[mid] && v[mid] >= v[high])  // if the array is not sorted, then the first element will be less than the middle element and the middle element will be greater than the last element
        {
            low = mid + 1;
        }
        else if (v[low] >= v[mid] && v[mid] <= v[high])  // if the array is not sorted, then the first element will be greater than the middle element and the middle element will be less than the last element
        {
            high = mid - 1;
        }
    }
    return false;
}


int main()
{
    vector<int> v = {4,5,6,1,2,3};
    bool is_circular_sorted = IsCircularSorted(v);
    cout << "Is the array circular sorted? " << is_circular_sorted << endl;
    return 0;
}