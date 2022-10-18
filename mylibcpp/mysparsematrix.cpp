
#include "mysparsematrix.h"
#include <iostream>


#pragma region SPARSE MATRIX FUNCTIONS
/// <summary>
/// Given two sparse matrices,  perform operations such as add,
/// multiply or transpose of the matrices in their sparse form itself. 
/// The result should consist of three sparse matrices, one obtained by adding the two input matrices, 
/// one by multiplying the two matrices and one obtained by transpose of the first matrix. 
/// </summary>
/// <param name="row"></param>
/// <param name="column"></param>
/// <returns></returns>
MySparseMatrix* initSparseMatrix(int row, int column) {
	MySparseMatrix* matrix = new MySparseMatrix;
	matrix->row = row;
	matrix->col = column;
	matrix->data = 0;
	matrix->next = NULL;
	return matrix;
}
/// <summary>
/// We use getSparseMatrix to get sparse matrix.
/// </summary>
/// <param name="matrix"></param>
/// <param name="row"></param>
/// <param name="column"></param>
/// <returns></returns>
Data* getSparseMatrix(MySparseMatrix* matrix, int row, int column) {
	MySparseMatrix* temp = matrix;
	while (temp != NULL) {
		if (temp->row == row && temp->col == column) {
			Data* data = new Data();
			data->key = temp->data;
			return data;
		}
		temp = temp->next;
	}
	return 0;
}
/// <summary>
/// We use it to add the item to the sparse matrix.
/// </summary>
/// <param name="matrix"></param>
/// <param name="row"></param>
/// <param name="column"></param>
/// <param name="data"></param>
/// <returns></returns>
int insertSparseMatrix(MySparseMatrix* matrix, int row, int column, Data* data) {
	MySparseMatrix* temp = matrix;
	MySparseMatrix* r;

	if (temp == NULL) {
		temp = new MySparseMatrix();
		temp->row = row;
		temp->col = column;
		temp->data = data->key;
		temp->next = NULL;
	}
	else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		r = new MySparseMatrix();
		r->row = row;
		r->col = column;
		r->data = data->key;
		r->next = NULL;
		temp->next = r;
	}
	return 0;
}
/// <summary>
/// We use it to delete the item in the sparse matrix.
/// </summary>
/// <param name="matrix"></param>
/// <param name="row"></param>
/// <param name="column"></param>
/// <returns></returns>
int deleteSparseMatrix(MySparseMatrix* matrix, int row, int column) {
	MySparseMatrix* temp = matrix;
	MySparseMatrix* r;
	if (temp == NULL) {
		return 0;
	}
	if (temp->row == row && temp->col == column) {
		matrix = temp->next;
		delete(temp);
		return 0;
	}
	/// <summary>
	/// We use loop to delete item in sparse matrix.
	/// </summary>
	/// <param name="matrix"></param>
	/// <param name="row"></param>
	/// <param name="column"></param>
	/// <returns></returns>
	while (temp->next != NULL) {
		if (temp->next->row == row && temp->next->col == column) {
			r = temp->next;
			temp->next = r->next;
			delete(r);
			return 0;
		}
		temp = temp->next;
	}
	return 0;
}
/// <summary>
/// To copy the sparse matrix, we do the following.
/// </summary>
/// <param name="source"></param>
/// <param name="destination"></param>
/// <returns></returns>
int copySparseMatrix(MySparseMatrix* source, MySparseMatrix* destination) {
	MySparseMatrix* temp = source;
	MySparseMatrix* r;
	if (temp == NULL) {
		return 0;
	}
	/// <summary>
	/// To copy the sparse matrix, we do the following.
	/// </summary>
	/// <param name="source"></param>
	/// <param name="destination"></param>
	/// <returns></returns>
	while (temp != NULL) {
		r = new MySparseMatrix();
		r->row = temp->row;
		r->col = temp->col;
		r->data = temp->data;
		r->next = NULL;

		if (destination == NULL) {
			destination = r;
		}
		else {
			MySparseMatrix* temp2 = destination;
			while (temp2->next != NULL) {
				temp2 = temp2->next;
			}
			temp2->next = r;
		}
	}
	return 0;
}
/// <summary>
/// to delete sparseMatrix
/// </summary>
/// <param name="matrix"></param>
/// <returns></returns>
int deleteSparseMatrix(MySparseMatrix* matrix) {
	MySparseMatrix* temp = matrix;
	MySparseMatrix* r;
	if (temp == NULL) {
		return 0;
	}
	while (temp != NULL) {
		r = temp;
		temp = temp->next;
		delete(r);
	}
	return 0;
}
/// <summary>
/// We come to print to console.
/// </summary>
/// <param name="matrix"></param>
void printMatrixToConsole(MySparseMatrix* matrix) {
	MySparseMatrix* temp = matrix;
	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
	std::cout << "column_position:";

	temp = matrix;
	while (temp != NULL) {
		std::cout << temp->col << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
	std::cout << "row_position:";
	temp = matrix;

	while (temp != NULL) {
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}
/// <summary>
/// We use lenght to show how many items are in the sparse matrix.
/// </summary>
/// <param name="matrix"></param>
/// <returns></returns>
int lengthMatrix(MySparseMatrix* matrix) {
	MySparseMatrix* temp = matrix;
	int length = 0;
	while (temp != NULL) {
		length++;
		temp = temp->next;
	}
	return length;
}

#pragma endregion