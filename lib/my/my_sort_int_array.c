/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** Day04 Task06
*/

void my_sort_int_array(int *array, int size)
{
    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i] < array[j]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}
