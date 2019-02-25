## Arrays

**#1 Remove duplicates from an array**

En:
1. Is array sorted?
2. Should I allocate extra space for non-duplicate array or should I remove the duplicates in-place?
3. What should I return? The new length of non-duplicate array or the new non-duplicate array?
4. Is it an integer array? Could there be non-negative integers?
5. What are the restraints? What is the max value of an integer and what is the max size of the array?

Ru:
1. Массив отсортирован?
2. Могу ли я использовать дополнительную память для нового массива без дубликатов или же необходимо убрать дубликаты на месте за константную память?
3. Что необходимо вернуть? Новый размер массива или же новый массив без дубликатов?
4. Это массив целочисленных типов? Могут ли быть отрицательные числа в нем?
5. Какие ограничения? Какое самое большое число и какой максимальный размер массива может быть?

*Idea*
En:
We have a sorted array thus we can use two pointers: one pointer is a slow one, it points to first elements in the array, the second pointer is fast pointer and it points to the second element in the array. We iterate over array with the fast pointer and compare its element to the slow pointer's element. If the two elements aren't equal then we found new non-duplicate element and we can swap the fast pointer's element with the slow pointer's next element and increment the slow pointer. Now the slow pointer points to the new value and we can continue iterate over the array with fast pointer and repeat comparison and swapping until we reach the end of the array. With this method we use in-place algorithm and doesn't allocate any extra memory, so we use O(1) memory and O(n) time as we need to iterate over every element in the array. In the beginning of the function we need to check if the array's length is at least 1 because we need two elements to point to, if the array is empty then we can return the initial array, there would be no duplicates in it. If we need to return the new array's size then we can return the slow pointer pre-increment it by one.

Ru:
Так как у нас массив отсортирован, то мы можем использовать два указателя. Первый указатель медленный, второй более быстрый. Медленный указатель указывает на первый элемент массива, быстрый указатель на следующий элемент массива. Пробегаемся быстрым указателем по массиву до тех пор пока элемент, на который указывает быстрый указатель будет не равен элементу медленного указателя. В этом случае мы нашли следующий незадублированый элемент. Меняем местами элемент быстрого указателя с элементом, который стоит сразу после медленного указателя и сдвигаем медленный указатель на новый элемент. Быстрый указатель продолжает бежать дальше, теперь сравнивая последующие элементы с новым элементом медленного указателя и повторяя смену местами при несовпадении элементов. Решение за линейное время O(n), так как мы в любом случае пробегаемся быстрым указателем по всему массиву. Так как для использования двух указателей нам нужен массив длинной минимум 1, то в начале функции проверяем длину массива и если массив пуст, возвращаемся этот же массив, в нем не будет дубликатов по определению, если массив не пуст. Если нам нужно вернуть длину нового массива, можем вернуть медленный указатель предваритель увеличив его на 1.
