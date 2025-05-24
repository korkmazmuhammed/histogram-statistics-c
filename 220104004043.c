#include <stdio.h>
int how_many(int array[], int size, int number)
{
    int counter = 0;
    int i;
    for (i = 0; i <= size - 2; i++)
    {
        if (array[i] == number)
        {
            counter++;
        }
    }
    return counter;
}

void display_screen(int A, int B, int max, int size, int array[])
{
    int count = 0;
    int i = 0;
    while (max != 0)
    {
        for (i = A; i <= B; i++)
        {
            count = how_many(array, size, i);
            if (count < max)
                printf(" ");
            else if (max <= count)
                printf("*");
        }
        printf("\n");
        max--;
    }
}

void print_mode(int array[], int size, int max, int A, int B)
{
    int i;
    int j;
    int counter = 0;
    int catcher[100] = {0};
    int k = 0;
    int flag = 1;
    int t = 0;

    for (i = 0; i <= size - 2; i++)
    {
        for (j = 0; j <= size - 2; j++)
        {
            if (array[i] == array[j])
            {
                counter++;
                if (max == counter)
                {
                    t = 0;
                    while (catcher[t])
                    {
                        if (array[i] == catcher[t])
                            flag = 0;
                        t++;
                    }
                    if (flag == 1)
                    {
                        catcher[k] = array[i];
                        k++;
                    }
                }
            }
            flag = 1;
        }
        counter = 0;
    }
    t = 0;
    printf("Mode: ");

    while (catcher[t])
    {
        if (catcher[t] >= A && catcher[t] <= B)
            printf("%d ", catcher[t]);
        t++;
    }
}

int count_max(int array[], int size, int A, int B)
{
    int i;
    int j;
    int counter = 0;
    int max = 0;
    for (i = 0; i <= size - 2; i++)
    {
        if (array[i] >= A && array[i] <= B)
        {
            for (j = 0; j <= size - 2; j++)
            {
                if (array[i] == array[j])
                {
                    counter++;
                }
            }
            if (max < counter)
                max = counter;
            counter = 0;
        }
    }
    return max;
}

int find_size_of_array(int A[])
{
    int i = 0;

    while (A[i] != -1)
    {
        i++;
    }
    i++;
    return i;
}

double calc_avg(int A, int B, int array[], int size)
{
    double sum = 0;
    int i = 0;
    int out_of_interval = 0;
    while (array[i] != -1)
    {
        if (array[i] >= A && array[i] <= B)
            sum += array[i];
        else
            out_of_interval++;
        i++;
    }
    sum = (sum) / (size - 1 - out_of_interval);
    return sum;
}

int get_min(int A[], int current, int last)
{
    int i, j;
    int min_value = A[current];
    int min_index = 0;
    for (i = current; i <= last - 1; i++)
    {
        if (A[i] <= min_value)
        {
            min_index = i;
            min_value = A[i];
        }
    }
    return min_index;
}

void sort_min_to_max(int array[], int size, int A, int B)
{
    int new_arr[500];
    int j = 1;
    int fill, temp, index_of_min;
    for (fill = 0; fill < size - 1; fill++)
    {
        index_of_min = get_min(array, fill, size - 1);
        if (index_of_min != fill)
        {
            temp = array[index_of_min];
            array[index_of_min] = array[fill];
            array[fill] = temp;
        }
        if (array[fill] >= A && array[fill] <= B)
        {
            new_arr[j] = array[fill];
            j++;
        }
    }
    j--;
    if ((j) % 2 == 1)
        printf("Median: %.2lf\n", (float)new_arr[((j + 1) / 2)]);
    else
        printf("Median: %.2lf\n", (float)(new_arr[(j / 2)] + new_arr[(j / 2) + 1]) / 2);
}
int main()
{
    printf("A value must be at least 50, and the B value must not exceed 200\n");
    int A, B;
    scanf("%d %d", &A, &B);
    if ((A < 50 || A > 200) || (B < 50 || B > 200))
    {
        printf("A and B must be >= 50 and =<200 and B should be greater than A ");
        scanf("%d %d", &A, &B);
    }

    int size;
    int choice;
    int number_array[300] = {45, 46, 47, 48, 49, 50, 133, 52, 53, 54, 55, 111, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 55, 55, 69, 70, 55, 45, 73, 55, 75, 76, 77, 78, 79, 80, 81, 82, 55, 55, 85, 86, 87, 88, 89, 90, 91, 92, 93, 193, 95, 133, 76, 191, 55, 100, 101, 102, 76, 104, 105, 106, 107, 108, 120, 110, 111, 112, 113, 114, 115, 116, 117, 118, 163, 120, 121, 122, 193, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139, 140, 141, 193, 133, 144, 145, 146, 147, 148, 149, 150, 151, 193, 153, 154, 155, 156, 157, 158, 111, 160, 120, 162, 163, 128, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 111, 179, 180, 181, 111, 120, 184, 133, 186, 187, 188, 125, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199, 125, 201, 202, 203, 173, 205, 61, 128, 173, 76, 111, 133, 45, -1};
    size = find_size_of_array(number_array);
    int max = count_max(number_array, size, A, B);
    display_screen(A, B, max, size, number_array);

    printf("Do you want to add number Yes(1) No(0)\n");
    scanf("%d", &choice);
    float avg = 0;

    switch (choice)
    {
    case 1:
        printf("Enter up to five additional numbers\n");
        int j = 0;

        int flag = 1;
        int counter = 0;
        int controller;
        int catcher;

        while (flag == 1 && counter != 5)
        {
            controller = scanf(" %d", &catcher);
            if (catcher != -1 && controller > 0)
            {
                number_array[size - 1] = catcher;
                size++;
            }
            else
                flag = 0;
            counter++;
        }
        number_array[size - 1] = -1;

        printf("\n");
        size = find_size_of_array(number_array);
        max = count_max(number_array, size, A, B);
        display_screen(A, B, max, size, number_array);
        avg = calc_avg(A, B, number_array, size);
        printf("\nAverage:%.2lf\n", avg);
        sort_min_to_max(number_array, size, A, B);
        print_mode(number_array, size, max, A, B);
        break;

    case 0:
        avg = calc_avg(A, B, number_array, size);
        printf("\nAverage:%.2lf\n", avg);
        sort_min_to_max(number_array, size, A, B);
        max = count_max(number_array, size, A, B);
        print_mode(number_array, size, max, A, B);
        break;
    default:
        printf("\nWRONG ENTERED!\n");
        break;
    }
}
