#include "QS.h"


using namespace std; 
	void QS :: sortAll(){
        cout << "Calling sortAll()" << endl; 
		RecursiveSort(0, numElements-1);

		
    }
	void QS::RecursiveSort(int first, int last){
		// base case , 1 element is already sorted, if the first and last are in the middle it is already sorted 
		if(numElements <= 1){
			return; // already sorted
		}
		if(last - first < 1){
			return; 
		}
		int pivot = medianOfThree(first, last);
		 pivot = partition(first, last, pivot);
		 RecursiveSort(first, pivot-1);
		 RecursiveSort(pivot + 1, last);
		 return; 
		
	}


	/*
	* medianOfThree()
	*
	* The median of three pivot selection has two parts:
	*
	* 1) Calculates the middle index by averaging the given left and right indices:
	*
	* middle = (left + right)/2
	*
	* 2) Then bubble-sorts the values at the left, middle, and right indices.
	*
	* After this method is called, data[left] <= data[middle] <= data[right].
	* The middle index will be returned.
	*
	* Returns -1 if the array is empty, if either of the given integers
	* is out of bounds, or if the left index is not less than the right
	* index.
	*
	* @param left
	* 		the left boundary for the subarray from which to find a pivot
	* @param right
	* 		the right boundary for the subarray from which to find a pivot
	* @return
	*		the index of the pivot (middle index); -1 if provided with invalid input
	*/
	int QS :: medianOfThree(int left, int right){
        cout << "calling median of 3" << endl;

		if(QS_array == NULL || (left >= right) || (left < 0) || (left >= numElements) 
		|| (right < 0) || (right >= numElements)
		){
			return -1; 
		}
		int middle = (left + right) / 2; 
		if(QS_array[left] > QS_array[middle]){ // if the left element is bigger than the middle, swap them 
			swap(QS_array[left], QS_array[middle]);
		}
		if(QS_array[middle] > QS_array[right]){ // if the middle element is bigger than the right, swap them
			swap(QS_array[middle], QS_array[right]);

			if(QS_array[left] > QS_array[middle]){ // go back and check the first two elements to see if they are in the right order 
				swap(QS_array[left], QS_array[middle]);
			}
		}

        return middle; 
    }
		/*
	* Partitions a subarray around a pivot value selected according to
	* median-of-three pivot selection.  Because there are multiple ways to partition a list,
	* we will follow the algorithm on page 611 of the course text when testing this function.
	*
	* The values which are smaller than the pivot should be placed to the left
	* of the pivot; the values which are larger than the pivot should be placed
	* to the right of the pivot.
	*
	* Returns -1 if the array is null, if either of the given integers is out of
	* bounds, or if the first integer is not less than the second integer, or if the
	* pivot is not within the sub-array designated by left and right.
	*
	* @param left
	* 		the left boundary for the subarray to partition
	* @param right
	* 		the right boundary for the subarray to partition
	* @param pivotIndex
	* 		the index of the pivot in the subarray
	* @return
	*		the pivot's ending index after the partition completes; -1 if
	* 		provided with bad input
	*/
	int QS :: partition(int left, int right, int pivotIndex){
        cout << "calling partition()" << endl;
		if((QS_array == NULL) || (pivotIndex >= numElements) || (left < 0) 
		|| (left >= numElements) || (right < 0) || (right >= numElements) 
		|| (pivotIndex < 0) || (left >= right) || (left > pivotIndex) || (pivotIndex > right) ){ // check to see if pvoti s too big, right is too small/ big.. etc 
			return -1; 
		}
		swap(QS_array[left], QS_array[pivotIndex]);
		int up = left + 1;
		int down = right; 
		do{
			cout << "entering do loop"  << endl;
			while((QS_array[up] <= QS_array[left]) && (up < right)){ // left 
				up++;
				cout << "entering 1st up loop" << endl;
			}
			while((QS_array[down] > QS_array[left]) && (down > left)){ // left, since they switched
				down--; 
				cout << "entering 2nd down loop" << endl;
			}
			if(up < down){
				swap(QS_array[up], QS_array[down]);
			}
			cout << "exiting do loop" << endl;
		}while(up < down);

		swap(QS_array[left], QS_array[down]);
		return down; 
    }

	/*
	* Produces a comma delimited string representation of the array. For example: if my array
	* looked like {5,7,2,9,0}, then the string to be returned would look like "5,7,2,9,0"
	* with no trailing comma.  The number of cells included equals the number of values added.
	* Do not include the entire array if the array has yet to be filled.
	*
	* Returns an empty string, if the array is NULL or empty.
	*
	* @return
	*		the string representation of the current array
	*/
	string QS :: getArray(){
        cout << "calling getArray()" << endl;
		stringstream ss; 
		string myString; 
		if(QS_array != NULL){
			for(int i = 0; i < numElements; i++){
				ss << QS_array[i]; 
				if(i < numElements- 1){
					ss << ",";
				}
			}
		return ss.str(); 
		}
		else{
			return ""; 
		} 
    }

	/*
	* Returns the number of elements which have been added to the array.
	*/
	int QS :: getSize() const{
        cout << "calling getSize()" << endl;

        return numElements;
    }

	/*
	* Adds the given value to the end of the array starting at index 0.
	* For example, the first time addToArray is called,
	* the give value should be found at index 0.
	* 2nd time, value should be found at index 1.
	* 3rd, index 2, etc up to its max capacity.
	*
	* If the array is filled, do nothing.
	* returns true if a value was added, false otherwise.
	*/
	bool QS::addToArray(int value){
        cout << "calling addToArray()" << endl; 
	
		 if(capacity == numElements){
			return false; // already full
		 }
		 else {
			 QS_array[numElements] = value; 
		 	numElements = numElements + 1;
			elementList.push_back(value);
			return true; 
		 }

	}
// if you is empty function helps

	/*
	* Dynamically allocates an array with the given capacity.
	* If a previous array had been allocated, delete the previous array.
	* Returns false if the given capacity is non-positive, true otherwise.
	*
	* @param
	*		size of array
	* @return
	*		true if the array was created, false otherwise
	*/
	bool QS::createArray(int capacity){
        cout << "calling createArray()" << endl;
		// if(QS_array != NULL){
		// 	delete [] QS_array; 
		// 	numElements = 0;  
		// }
		if(capacity < 0){
			return false; // invalid capacity
		}
		else{
			QS_array = new int[capacity];
			numElements = 0; 
			this->capacity = capacity; 
			elementList.clear(); 
			return true; 
		}
    }

	/*
	* Resets the array to an empty or NULL state.
	*/
	void QS:: clear(){
        cout << "clearing " << endl;
		if((QS_array == NULL) &&(numElements == 0)){
			return; 
		}
		else{
			numElements = 0; 
			delete [] QS_array;
			return; 
		}
        
    }