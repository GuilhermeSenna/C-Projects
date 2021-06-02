#include <stdio.h>
#include <stdlib.h>

void mergesort(int *a, int n);
void sort(int *a, int *c, int i, int f);
void merge(int *a, int *c, int i, int m, int f);

int main (void) {
  int i;
  int a[8] = {7,4,3,6,5,2,9,0};

  mergesort(a, 8);

  for (i = 0; i < 8; i++)
    printf("%d ", a[i]);

  putchar('\n');

  return 0;
}

void mergesort(int *a, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(a, c, 0, n - 1);
  free(c);
}

void sort(int *a, int *c, int i, int f) {
  if (i >= f)
    return;

  int m = (i + f) / 2;

  sort(a, c, i, m);
  sort(a, c, m + 1, f);

  if (a[m] <= a[m + 1])
    return;

  merge(a, c, i, m, f);
}

void merge(int *a, int *c, int i, int m, int f) {

  int z,iv = i, ic = m + 1;

  for (z = i; z <= f; z++)
        c[z] = a[z];

  z = i;

  while (iv <= m && ic <= f) {

    if(c[iv] < c[ic])
        a[z++] = c[iv++];
    else
        a[z++] = c[ic++];
  }

  while (iv <= m)
    a[z++] = c[iv++];

  while (ic <= f)
    a[z++] = c[ic++];
}
