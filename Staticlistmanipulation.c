#include <stdio.h>
#include <stdlib.h>
void delete(int *arr, int *n)
{
    int key, flag = 0;
    printf("enter the element you want to delete ");
    scanf("%d", &key);
    if (*n == 0)
    {
        printf("Array is empty, cannot delete element.\n");
        return;
    }
    for (int i = 0; i < *n;)
    {
        if (arr[i] == key)
        {
            for (int j = i; j < *n - 1; j++)
            {
                arr[j] = arr[j + 1];
            }
            (*n)--;
            flag = 1;
        }
        else
            i++;
    }
    if (!flag)
    {
        printf("Element not found in the array.\n");
        return;
    }
    printf("Array after deleting the element is:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void insert(int **arr, int *n)
{
    int key, index;
    printf("enter the element you want to insert ");
    scanf("%d", &key);
    printf("enter the index at which you want to insert the element ");
    scanf("%d", &index);
    if (index > *n || index < 0)
    {
        printf("Invalid Position !!!!!\n");
        return;
    }
    int *temp = realloc(*arr, (*n + 1) * sizeof(int));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    *arr = temp;
    for (int i = *n - 1; i >= index; i--)
    {
        (*arr)[i + 1] = (*arr)[i];
    }
    (*arr)[index] = key;
    (*n)++;
    printf("Array after inserting the element is:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", (*arr)[i]);
    }
    printf("\n");
}
void update(int *arr, int *n)
{
    int val, index;
    printf("enter the element you want to update :  ");
    scanf("%d", &val);
    printf("Enter the Index of the element you want to update: ");
    scanf("%d", &index);
    if (index >= *n || index < 0)
    {
        printf("Invalid Position !!!\n");
        return;
    }
    arr[index] = val;
    printf("Array after updating the element is:\n");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
void search(int *arr, int *n)
{
    int val, flag = 0;
    printf("enter the element you want to search ");
    scanf("%d", &val);
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] == val)
        {
            printf("Element found at index %d\n", i);
            flag = 1;
            break;
        }
    }
    if (!flag)
    {
        printf("Element not found in the array.\n");
    }
}
void traverse(int *arr, int *n)
{
    if (*n == 0)
    {
        printf("Array is empty\n");
        return;
    }
    printf("Elements of array are :");
    for (int i = 0; i < *n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int choice, n, capacity;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Invalid array size!\n");
        return 1;
    }
    capacity = n + 10;
    int *arr = (int *)malloc(capacity * sizeof(int));
    if (!arr)
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    while (1)
    {
        printf("\nEnter the operation you want to perform:\n");
        printf("1. Delete an element\n2. Insert an element\n");
        printf("3. Update an element\n4. Search an element\n5. Traverse elements\n6. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            delete (arr, &n);
            break;
        case 2:
            insert(&arr, &n);
            break;
        case 3:
            update(arr, &n);
            break;
        case 4:
            search(arr, &n);
            break;
        case 5:
            traverse(arr, &n);
            break;
        case 6:
            free(arr);
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
