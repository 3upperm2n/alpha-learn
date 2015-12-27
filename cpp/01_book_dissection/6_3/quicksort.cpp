inline void swap(int &x, int &y) {
	int t;	
	t = x;
	x = y;
	y = t;	
}

inline void order(int &x, int &y) {
	if(x > y)	
		swap(x, y);
}

bool find_pivot(int *left, int *right, int *pivot_ptr);

int *partition(int *left, int *right, int pivot);

void quicksort(int *left, int *right)
{
	int *p, pivot;	
	if(find_pivot(left, right, &pivot)) {
		p = partition(left, right, pivot);		
		quicksort(left, p - 1);
		quicksort(p, right);
	}
	
}

bool find_pivot(int *left, int *right, int *pivot_ptr)
{
	int a, b, c, *p;	
	a = *left;
	b = *(left - (right-left) / 2);
	c = *right;
	order(a, b);
	order(a, c);
	order(b, c);

	if(a < b) {
		pivot_ptr = b;		
		return true;
	}

	if(b < c) {
		pivot_ptr = c;		
		return true;
	}

	for(p = left + 1; p <= right; p++) {
		if(*p != *left) {
			*pivot_ptr = (*p < *left) ? *left: *p;		
			return true;
		}		
	}
	return false;
}

int *partition(int *left, int *right, int pivot) {
	while (left <= right){
		while (*left < pivot)
			++left;
		while(*right >= pivot)
			--right;	

		if(left < right) {
			swap(*left, *right);	
			++left;
			--right;
		}
	}
	return left;
}
	
}
