// Busca ternária para encontrar valor específico key
int ternarySearch(int arr[], int l, int r, int key)
{
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Check if the key is present at mid1
        if (arr[mid1] == key) {
            return mid1;
        }

        // Check if the key is present at mid2
        if (arr[mid2] == key) {
            return mid2;
        }

        // Determine which segment to search next
        if (key < arr[mid1]) {
            r = mid1 - 1;
        }
        else if (key > arr[mid2]) {
            l = mid2 + 1;
        }
        else {
            l = mid1 + 1;
            r = mid2 - 1;
        }
    }

    // If the element is not found
    return -1;
}

// Busca ternária para encontrar máximo
int ternarySearch(int arr[], int l, int r, int key)
{
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Determine which segment to search next
        if (f(mid1) < f(mid2) {
          l = mid1+1;
        }

        else {
          r = mid2-1;
        }
    }

    // If the element is not found
    return -1;
}

// Busca ternária para encontrar mínimo
int ternarySearch(int arr[], int l, int r, int key)
{
    while (r >= l) {
        int mid1 = l + (r - l) / 3;
        int mid2 = r - (r - l) / 3;

        // Determine which segment to search next
        if (f(mid1) < f(mid2) {
            r = mid2-1;
        }

        else {
            l = mid1+1;
        }
    }

    // If the element is not found
    return -1;
}


int main()
{
    int index = ternarySearch(arr, 0, n - 1, key);

    if (index != -1) {
        cout << "Element found at index " << index << endl;
    }
    else {
        cout << "Element not found in the array" << endl;
    }
}
