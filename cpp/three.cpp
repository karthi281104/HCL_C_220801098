#include <iostream>
#include <cstdlib>

using namespace std;

class duplicate_elements
{
public:
    duplicate_elements(int arr[], int n)
    {
        cout << "the duplicate elements in the array are\n";
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    cout << arr[i] << "\n";
                    break;
                }
            }
        }
    }
};

int main()
{
    int n;
    cout << "enter the number of elements in the array\n";
    cin >> n;

    int *arr = (int*)malloc(n * sizeof(int));
    if (!arr) return 0;

    cout << "enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    duplicate_elements d1(arr, n);

    free(arr);
    return 0;
}